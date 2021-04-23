# This is a powershell script that:
#   - Create the DomainSystems OU
#   -- Add all Computers (not DCs) to DomainSystems OU
#   - Create a GPO that: Enables RDP - Allow through firewall
#   - Create a GPO that: Enables WMI - Starts the WMI Service - Allow through the firewall
#   - Link GPOs to Domain Controllers OU and DomainSystems OU

# +++ MUST BE RUN AS ADMINISTRATOR ON DC +++ #

Import-Module ActiveDirectory -ErrorAction Stop

$civ = "france"
$dept = "intel"
$domain = "$dept.$civ"

$DS = "Domain Systems"
$DC = "Domain Controllers"

$DSOUPath = "OU=$DS,DC=$dept,DC=$civ"
$DCOUPath = "OU=$DC,DC=$dept,DC=$civ"
#==========================================================================================================================================================================
### Move all Computers to Domain Systems OU ###

Try {
    Try {
        New-ADOrganizationalUnit -Name $DS -Path "DC=$dept,DC=$civ"
        Write-Output "Successfully created Domain Systems OU"
    }
    Catch {
        Write-Output "Could not create 'Domain Systems' OU"
        Write-Warning $_.Exception.Message
    }

    Get-ADComputer -Filter * -SearchBase "CN=Computers,DC=$dept,DC=$civ" | ForEach-Object {
        $dname = $_.DistinguishedName
        Move-ADObject -Identity $dname -TargetPath $DSOUPath -ErrorAction Stop #-WhatIf

        Write-Output "Successfully added $dname to 'Domain Systems' OU"
    }
}
Catch {
    Write-Warning $_.Exception.Message
    $Prompt = Read-Host -Prompt "Computers --> DomainSystems addition portion of script failed. Would you like to exit? (y/n): "
    if ( $Prompt -eq 'n') {
        Write-Host "Continuing..."
    }
    else {
        Exit
    }
}
#==========================================================================================================================================================================
### Enable Ping (Echo Reply - disabled by default on Windows Workstations)

$ICMPGPOName = "Allow inbound ICMP"
$ICMPv4FWRule = "Allow inbound ICMPv4"
$ICMPv6FWRule = "Allow inbound ICMPv6"
$ICMPPolicyStoreName = "$domain\" + $ICMPGPOName
Try{
    Try{
        New-GPO -name $ICMPGPOName -Domain $domain
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not create Ping-EchoReply GPO..."
    }
    Try{
        $ICMPGPOSession = Open-NetGPO –PolicyStore $ICMPPolicyStoreName
        New-NetFirewallRule -DisplayName $ICMPv4FWRule -Direction Inbound -GPOSession $ICMPGPOSession -PolicyStore $ICMPPolicyStoreName -Protocol ICMPv4 -IcmpType 8 -Profile Any -Action Allow
        New-NetFirewallRule -DisplayName $ICMPv6FWRule -Direction Inbound -GPOSession $ICMPGPOSession -PolicyStore $ICMPPolicyStoreName -Protocol ICMPv6 -IcmpType 8 -Profile Any -Action Allow
        Save-NetGPO -GPOSession $ICMPGPOSession
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not create ICMP Firewall rules..."
    }
    Try{
        New-GPLink -name $ICMPGPOName -Target $DSOUPath -LinkEnabled Yes    # DomainSystems
        New-GPLink -name $ICMPGPOName -Target $DCOUPath -LinkEnabled Yes    # Domain Controllers
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not link 'ICMP' GPO to OUs..."
    }
}
Catch {
    Write-Warning $_.Exception.Message
    $Prompt = Read-Host -Prompt "$ICMPGPOName portion of script failed. Would you like to exit? (y/n): "
    if ( $Prompt -eq 'n') {
        Write-Host "Continuing..."
    }
    else {
        Exit
    }
}
#==========================================================================================================================================================================
### Remote Desktop Services GPO - Enabling and Firewalling ###

$RDPGPOName = "Enable Remote Desktop"
$RDPFWRule = "Allow 3389-TCP on all profiles"
$RDPPolicyStoreName = "$domain\" + $RDPGPOName 

Try{
    Try{
        New-GPO -name $RDPGPOName -Domain $domain
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not create Enable Remote Desktop GPO..."
    }

    Try{ 
        Set-GPRegistryValue -name $RDPGPOName -key 'HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Terminal Server' -ValueName "fDenyTSConnections" -type Dword -value 00000000
        Set-GPRegistryValue -name $RDPGPOName -key 'HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services' -ValueName "fDenyTSConnections" -type Dword -value 00000000
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not set RDP registry values..."
    }

    Try{
        $RDPGPOSession = Open-NetGPO –PolicyStore $RDPPolicyStoreName
        New-NetFirewallRule -DisplayName $RDPFWRule -Direction Inbound -GPOSession $RDPGPOSession -PolicyStore $RDPPolicyStoreName -Protocol TCP -LocalPort 3389 -Action Allow -Profile Any
        Save-NetGPO -GPOSession $RDPGPOSession
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not create RDP Firewall rules..."
    }

    Try{
        New-GPLink -name $RDPGPOName -Target $DSOUPath -LinkEnabled Yes    # DomainSystems
        New-GPLink -name $RDPGPOName -Target $DCOUPath -LinkEnabled Yes    # Domain Controllers
    }
    Catch{
        Write-Warning $_.Exception.Message
        Write-Output "Could not link 'Enable Remote Desktop' GPO to OUs..."
    }

    Write-Output "Enabling RDP Successful..."
    Write-Output "Firewalling RDP Successful..."
}
Catch {
    Write-Warning $_.Exception.Message
    $Prompt = Read-Host -Prompt "$RDPGPOName portion of script failed. Would you like to exit? (y/n): "
    if ( $Prompt -eq 'n') {
        Write-Host "Continuing..."
    }
    else {
        Exit
    }
}
#==========================================================================================================================================================================
### WMI GPO - Enabling, Service Starting, and Firewalling + UAC Disabling ###

