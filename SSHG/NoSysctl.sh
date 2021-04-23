# sshguard.service -- sample systemd unit file
#!/bin/sh
case $1 in 
start)
	/opt/sshguard/sbin/sshguard -l /var/log/secure -l /var/log/messages &
	;;
stop)
	killall sshguard
	;;
*)
	echo "Use start or stop!"
	exit 1
;;
esac
