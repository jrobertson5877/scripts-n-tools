# create a lookup Hashtable for all OU's in your organisation
# You can limit this using parameters like '-SearchScope' and '-SearchBase' depending on the structure in your AD environment
$allOUs = @{}
Get-ADOrganizationalUnit -Filter 'Name -like "*"' | ForEach-Object {
    $allOUs[$_.Name] = $_.DistinguishedName 
}

# next, get all computers in the default Computers OU
$result = Get-ADComputer -Filter * -SearchBase "CN=Computers,DC=Contoso,DC=com" | ForEach-Object {
    $computerName = $_.Name
    $found = $false
    if ($computerName.Length -ge 6) {
        $targetOU = $computerName.Substring(0,6)
        $found    = $allOUs.ContainsKey($targetOU)
    }
    if (!$found -and $computerName.Length -ge 5) {
        $targetOU = $computerName.Substring(0,5)
        $found    = $allOUs.ContainsKey($targetOU)
    }
    if ($found) {
        try {
            $_ | Move-ADObject -TargetPath $allOUs[$targetOU] -ErrorAction Stop -WhatIf
            # add success to the $result
            [PsCustomObject]@{
                'Computer' = $computerName
                'TargetOU' = $targetOU
                'Result'   = 'Moved'
            }
        }
        catch {
            # add exception to the $result
            [PsCustomObject]@{
                'Computer' = $computerName
                'TargetOU' = $targetOU
                'Result'   = 'Not moved. {0}' -f $_.Exception.Message
            }
        }
    }
    else {
        # add failure to the $result
        [PsCustomObject]@{
            'Computer' = $computerName
            'TargetOU' = ''
            'Result'   = 'Not moved. Computername does not begin with a valid OU name'
        }
    }
}

# output on screen
$result

# output to file
$result | Export-Csv -Path 'ComputersMoved.CSV' -NoTypeInformation