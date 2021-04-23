Get-Service adws,kdc,netlogon,dns
Get-ADDomainController
Get-ADDomain mythos.org
Get-ADForest mythos.org
Get-smbshare SYSVOL
Get-DnsServerResourceRecord -ZoneName "mythos.org"
