Get-ADOrganizationalUnit -Filter 'Name -like "*"' | Format-Table Name, DistinguishedName -A

New-ADOrganizationalUnit -Name "Domain Users" -Path "DC=MYTHOS,DC=ORG"
New-ADOrganizationalUnit -Name "Domain Systems" -Path "DC=MYTHOS,DC=ORG"

#Rename-ADObject -Identity "OU=DomainUsers,DC=MYTHOS,DC=ORG" -NewName "Domain Users"

New-ADUser -Name "Oxygen Decae" -GivenName "Oxygen" -Surname "Decae" -SamAccountName "admin-decae" -UserPrincipalName "admin-decae@mythos.org" -Path "OU=Domain Users,DC=mythos,DC=org" -AccountPassword(Read-Host -AsSecureString "Input Password") -Enabled $true
New-ADUser -Name "Oxycodone Decae" -GivenName "Oxycodone" -Surname "Decae" -SamAccountName "decae" -UserPrincipalName "decae@mythos.org" -Path "OU=Domain Users,DC=mythos,DC=org" -AccountPassword(Read-Host -AsSecureString "Input Password") -Enabled $true

Add-ADGroupMember -Identity "Domain Admins" -Members admin-decae

Get-ADGroupMember -Identity "Domain Admins" -Recursive | %{Get-ADUser -Identity $_.distinguishedName} | Select Name, Enabled
#
Disable-ADAccount -Identity Administrator
