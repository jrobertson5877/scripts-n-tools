New-NetIPAddress -InterfaceIndex 4 -IPAddress 192.168.100.100 -PrefixLength 24 -DefaultGateway 192.168.100.1
Set-DnsClientServerAddress -InterfaceIndex 4 -ServerAddresses ("192.168.100.100","192.168.100.102")
Rename-Computer -NewName "changeme"\\\
Set-TimeZone -Id “Eastern Standard Time”

Write-Output "Please restart the server to have changes take effect..."