Param(
    [Parameter(Mandatory=$false)]
    [string]$Root = "."  # Run this from your project's Source/<ModuleName>/ folder or pass -Root
)

Write-Host "== Slayers of the Pantheon rename: starting in $Root =="

# -------------------------------
# Mapping: file/class base names
# -------------------------------
# Bare name mapping (used for filenames, includes, and generated headers)
$BareMap = @{
    "F13Mode"               = "PantheonGameMode";
    "F13GameState"          = "PantheonGameState";
    "F13GameSession"        = "PantheonGameSession";
    "F13GameInstance"       = "PantheonGameInstance";
    "F13PlayerController"   = "PantheonPlayerController";
    "F13PlayerState"        = "PantheonPlayerState";
    "F13BotController"      = "PantheonBotController";
    "F13CharacterBase"      = "PantheonCharacterBase";
    "F13KillerCharacter"    = "PantheonKillerCharacter";
    "F13SurvivorCharacter"  = "PantheonSurvivorCharacter";
    "F13PlayerProfileSave"  = "PantheonPlayerProfileSave";
    "F13LobbyMenu"          = "PantheonLobbyGameMode"
}

# Prefixed class mapping (A*/U*)
$ClassMap = @{
    "AF13Mode"               = "APantheonGameMode";
    "AF13GameState"          = "APantheonGameState";
    "AF13GameSession"        = "APantheonGameSession";
    "UF13GameInstance"       = "UPantheonGameInstance";
    "AF13PlayerController"   = "APantheonPlayerController";
    "AF13PlayerState"        = "APantheonPlayerState";
    "AF13BotController"      = "APantheonBotController";
    "AF13CharacterBase"      = "APantheonCharacterBase";
    "AF13KillerCharacter"    = "APantheonKillerCharacter";
    "AF13SurvivorCharacter"  = "APantheonSurvivorCharacter";
    "UF13PlayerProfileSave"  = "UPantheonPlayerProfileSave";
    "AF13LobbyMenu"          = "APantheonLobbyGameMode"
}

# Optional: log category renames you want to standardize
$LogMap = @{
    "LogF13Mode" = "LogPantheonMode";
    "LogF13Bot"  = "LogPantheonBot"
}

# -------------------------------
# Helpers
# -------------------------------
function Replace-InFile {
    param (
        [Parameter(Mandatory=$true)][string]$Path,
        [Parameter(Mandatory=$true)][hashtable]$Replacements,
        [switch]$RegexWordBoundary # when set, wrap keys with \b...\b
    )
    $content = Get-Content -Raw -LiteralPath $Path

    foreach ($old in $Replacements.Keys) {
        $new = $Replacements[$old]
        if ($RegexWordBoundary) {
            $pattern = "\b{0}\b" -f [regex]::Escape($old)
            $content  = [regex]::Replace($content, $pattern, [System.Text.RegularExpressions.MatchEvaluator]{ param($m) $new })
        } else {
            $content = $content -replace [regex]::Escape($old), [System.Text.RegularExpressions.Regex]::Escape($new) -replace '\\','\'
            # The above line ensures literal string replacement; PS -replace is regex-based, so we escape both sides.
            # Then unescape backslashes in replacement.
            foreach($dummy in 1..0){} # no-op; placeholder to keep structure clean
        }
    }

    Set-Content -LiteralPath $Path -Value $content -NoNewline
}

# -------------------------------
# 1) Update contents in all .h/.cpp files
# -------------------------------
$codeFiles = Get-ChildItem -Path $Root -Recurse -File -Include *.h,*.hpp,*.cpp

foreach ($f in $codeFiles) {
    # First replace class names with word boundaries (AF13X -> APantheonX, UF13X -> UPantheonX)
    Replace-InFile -Path $f.FullName -Replacements $ClassMap -RegexWordBoundary

    # Then replace bare names (F13X -> PantheonX) which will also update includes and *.generated.h lines
    Replace-InFile -Path $f.FullName -Replacements $BareMap

    # And optional log categories
    Replace-InFile -Path $f.FullName -Replacements $LogMap -RegexWordBoundary
}

Write-Host "== Content replacements done. =="

# -------------------------------
# 2) Rename files on disk
# -------------------------------
# We rename only files that exactly match a known base + .h/.cpp
$renamed = 0
$codeFiles = Get-ChildItem -Path $Root -Recurse -File -Include *.h,*.hpp,*.cpp

foreach ($f in $codeFiles) {
    $nameNoExt = [System.IO.Path]::GetFileNameWithoutExtension($f.Name)
    if ($BareMap.ContainsKey($nameNoExt)) {
        $newBase = $BareMap[$nameNoExt]
        $newName = "$newBase$($f.Extension)"
        if ($newName -ne $f.Name) {
            $newFull = Join-Path $f.DirectoryName $newName
            if (Test-Path $newFull) {
                Write-Warning "Target already exists, skipping: $newFull"
            } else {
                Rename-Item -LiteralPath $f.FullName -NewName $newName
                $renamed++
                Write-Host ("Renamed: {0} -> {1}" -f $f.Name, $newName)
            }
        }
    }
}

Write-Host "== File renames complete. Total files renamed: $renamed =="

Write-Host ""
Write-Host "NEXT STEPS:"
Write-Host "1) Regenerate project files (optional) and recompile."
Write-Host "2) In Unreal Editor: Fix Up Redirectors, then check Project Settings -> Maps & Modes for new GameMode/GameInstance."
Write-Host "3) Reparent Blueprint assets to the new C++ classes if needed."
Write-Host "4) If you ever rename the Module (F13) later, update the API macro (F13_API) accordingly."
