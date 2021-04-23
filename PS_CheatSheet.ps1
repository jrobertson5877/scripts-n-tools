# Powershell Dictionary for Case Studies and Homelab Environment
# These lines and scripts are meant to act as a command reference and cheat-sheet
#
# Do not run this file. It is saved as a .ps1 to enable syntax highlighting for VSCode
# Enjoy...

# Set Static IPv4 Address
New-NetIPAddress -InterfaceIndex 4 -IPAddress <ip-of-system> -PrefixLength 24 -DefaultGateway 192.168.100.1
Set-DnsClientServerAddress -InterfaceIndex 4 -ServerAddresses ("dns-ip-1","dns-ip-2")
Rename-Computer -NewName "new-hostname"\\\
Set-TimeZone -Id “Eastern Standard Time”

# Install Active Directory Services promote to DC, Create Forest
Install-WindowsFeature –Name AD-Domain-Services –IncludeManagementTools
Add-Computer -DomainName mythos.org -Restart

Install-ADDSDomainController `
-DomainName "mythos.org" `
-CreateDnsDelegation:$false `
-DatabasePath "C:\Windows\NTDS" `
-InstallDns:$true `
-LogPath "C:\Windows\NTDS" `
-NoRebootOnCompletion:$true `
-SysvolPath "C:\Windows\SYSVOL" `
-Force:$true

Restart-Computer

Install-WindowsFeature –Name AD-Domain-Services –IncludeManagementTools

Install-ADDSForest `
 -DomainName "domain.dom" `
 -CreateDnsDelegation:$false ` # optional?
 -DatabasePath "C:\Windows\NTDS" `
 -DomainMode "7" `
 -DomainNetbiosName "domain" `
 -ForestMode "7" `
 -InstallDns:$true `
 -LogPath "C:\Windows\NTDS" `
 -NoRebootOnCompletion:$true `
 -SysvolPath "C:\Windows\SYSVOL" `
 -Force:$true

 Restart-Computer

<#-DomainMode - notes
 Specifies the domain functional level of the first domain in the creation of a new forest. Supported values for this parameter can be either a valid integer or a corresponding enumerated string value. For example, to set the domain mode level to Windows Server 2008 R2, you can specify either a value of 4 or Windows2008R2Domain.

The following are the currently supported values:

    Windows Server 2000: 0 or Windows2000Domain
    Windows Server 2003 Interim Domain: 1 or Windows2003InterimDomain
    Windows Server 2003: 2 or Windows2003Domain
    Windows Server 2008: 3 or Windows2008Domain
    Windows Server 2008 R2: 4 or Windows2008R2Domain
    Windows Server 2012: 5 or Windows2012Domain
    Windows Server 2012 R2: 6 or Windows2012R2Domain
    Windows Server 2016: 7 or WinThreshold #>

# Verification Commands
Get-Service adws,kdc,netlogon,dns
Get-ADDomainController
Get-ADDomain mythos.org
Get-ADForest mythos.org
Get-smbshare SYSVOL
Get-DnsServerResourceRecord -ZoneName "domain.dom"

Get-ADOrganizationalUnit -Filter 'Name -like "*"' | Format-Table Name, DistinguishedName -A

New-ADOrganizationalUnit -Name "Domain Users" -Path "DC=MYTHOS,DC=ORG"
New-ADOrganizationalUnit -Name "Domain Systems" -Path "DC=MYTHOS,DC=ORG"

#Rename-ADObject -Identity "OU=DomainUsers,DC=MYTHOS,DC=ORG" -NewName "Domain Users"

New-ADUser -Name "Oxygen Decae" -GivenName "Oxygen" -Surname "Decae" -SamAccountName "admin-decae" -UserPrincipalName "admin-decae@mythos.org" -Path "OU=Domain Users,DC=mythos,DC=org" -AccountPassword(Read-Host -AsSecureString "Input Password") -Enabled $true
New-ADUser -Name "Oxycodone Decae" -GivenName "Oxycodone" -Surname "Decae" -SamAccountName "decae" -UserPrincipalName "decae@mythos.org" -Path "OU=Domain Users,DC=mythos,DC=org" -AccountPassword(Read-Host -AsSecureString "Input Password") -Enabled $true
Add-ADGroupMember -Identity "Domain Admins" -Members admin-decae
Get-ADGroupMember -Identity "Domain Admins" -Recursive | %{Get-ADUser -Identity $_.distinguishedName} | Select Name, Enabled
Disable-ADAccount -Identity Administrator

# Enable RDP
Set-ItemProperty -Path 'HKLM:\System\CurrentControlSet\Control\Terminal Server' -name "fDenyTSConnections" -value 0
Enable-NetFirewallRule -DisplayGroup "Remote Desktop"
Restart-Computer