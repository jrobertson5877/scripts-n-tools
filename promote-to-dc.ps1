Install-WindowsFeature ad-domain-services -IncludeManagementTools
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