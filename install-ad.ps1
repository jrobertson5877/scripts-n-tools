Install-WindowsFeature –Name AD-Domain-Services –IncludeManagementTools

Install-ADDSForest `
 -DomainName "mythos.org" `
 -CreateDnsDelegation:$false `
 -DatabasePath "C:\Windows\NTDS" `
 -DomainMode "7" `
 -DomainNetbiosName "mythos" `
 -ForestMode "7" `
 -InstallDns:$true `
 -LogPath "C:\Windows\NTDS" `
 -NoRebootOnCompletion:$true `
 -SysvolPath "C:\Windows\SYSVOL" `
 -Force:$true

 Restart-Computer

