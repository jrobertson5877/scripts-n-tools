#!/bin/sh
#Make sure you have the correct sshguard distro and the other files that go with this in the same directory in the same

if [[ $EUID -ne 0 ]]; then
echo you must run this script as root
exit 1
fi

dist=1
if [ -f /etc/redhat-release ]; then
	test=$( cat /etc/redhat-release )
echo "$test"
	let dist=1
fi
echo $dist
case $dist in
	1) #CentOS
		tar -xzvf sshguard-2.1.0.tar.gz
		cd sshguard-2.1.0
		./configure --prefix=/opt/sshguard
		make
		make install
		cd ..
		mkdir /opt/sshguard/etc
		cp TMPSSHG.conf /opt/sshguard/etc/sshguard.conf
		#if [ $test == *"6.2 (Final)"*] || [ "$test" == *"6.5 (Final)"* ] || [ "$test" == *"6.8 (Final)"* ]; then #if we cannot use systemctl

			#cp NoSysctl.sh /etc/init.d/sshguard
			#chmod +x /etc/init.d/sshguard
			#ln -s /etc/init.d/sshguard /etc/rc5.d/S99sshguard
			#ln -s /etc/init.d/sshguard /etc/rc3.d/S99sshguard
			#ln -s /etc/init.d/sshguard /etc/rc6.d/K01sshguard
			#ln -s /etc/init.d/sshguard /etc/rc0.d/K01sshguard
			#cd /etc/init.d
			#service sshguard start
			
		#else
			cp sshguard.ser /usr/lib/systemd/system
			systemctl daemon-reload
			systemctl start sshguard
			systemctl enable sshguard
			systemctl status sshguard
		#fi
	;;
	*)
		echo unkown Distribuition
	;;
esac 
