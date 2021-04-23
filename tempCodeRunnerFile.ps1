Import-Module ActiveDirectory -ErrorAction Stop

$civ = 
$dept = 
$destOU = "DomainSystems"

New-ADOrganizationalUnit -Name $destOU -Path "DC=$dept,DC=$civ"



$computers = Get-ADComputer -Filter * -SearchBase "CN=Computers,DC=Contoso,DC=com" | ForEach-Object {
    $computerName = $_.Name
    Move-ADObject -TargetPath "OU" -ErrorAction Stop -WhatIf
