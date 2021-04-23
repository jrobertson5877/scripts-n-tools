#!/bin/bash

# Script for Case Studies 481 User creation and SSH key implant. 

# Parses TeamXEmployees.csv to seperate each user group into their respective group files.
# Remember to strip the top headings off of the CSV in order to prevent EMAIL from being used as a username.
# From there it will take each file and create users and add them to their respective groups
# This is a terrible but rather quick way of doing this, make sure to clean up after yourself 
# ie. deleting the 8606.txt file

# Bash History is wiped by the script, other logs most likely are not...

# Usage Information

for arg in "$@"
do
    if [ "$arg" == "--help" ] || [ "$arg" == "-h" ]
    then
        echo "Usage: create-users.sh [--help] <TeamXEmployees.csv> <8606.txt or passwords-file> <all|1|2|3>"
	exit 1
    fi
done


# Group assignment
if [[ $3 == "all" ]] || [[ $3 == "1" ]] ;
then
	groupadd -f it
	groupadd -f sales
	groupadd -f corp
	groupadd -f cloud
	groupadd -f ceo
	groupadd -f production
fi

# User Management
while IFS=',' read first last position email _ && IFS=':' read user pass <&3; do

	username=${email%?????????}
	
	# Create a new username:password file from Exercise Control passwords file
	if [[ $3 = "new" ]] ;
	then
		i=$(($(while :; do ran=$RANDOM; ((ran < 32760)) && echo $(((ran%2000)+1)) && break; done) + 5000))
		password=$(sed "${i}q;d" $2)
		echo "$username:$password" >> 8606.txt
	else
		password=$pass
	fi
	

	# Create users with passwords according to 8606.txt and TeamXEmployees.csv --> Groups
	if [[ $3 == "all" ]] || [[ $3 == "2" ]] ;
	then

		if [[ "$position" == "Cloud" ]] ;
		then
			#echo "$first,$last" >> cloud_users
			useradd -G cloud -m $username
			echo "$username:$password" | chpasswd

		elif [[ "$position" == "Corp" ]] ;
		then
			#echo "$first,$last" >> corp_users
			useradd -G corp -m $username
			echo "$username:$password" | chpasswd

		elif [[ "$position" == "Production" ]] ;
		then
			#echo "$first,$last" >> production_users
			useradd -G production -m $username
			echo "$username:$password" | chpasswd

		elif [[ "$position" == "Sales" ]] ;
		then
			#echo "$first,$last" >> sales_users
			useradd -G sales -m $username
			echo "$username:$password" | chpasswd

		elif [[ "$position" == "IT Staff" ]] ;
		then
			useradd -G it -m $username
			echo "$username:$password" | chpasswd
			
			# Check whether to add to sudo or wheel group
			if [[ -f /etc/centos-release ]] ;
			then
				usermod -aG wheel $username
			else
				usermod -aG sudo $username
			fi

		elif [[ "$position" == "CEO" ]] ;
		then
			#echo "$first,$last" >> ceo_users
			useradd -G ceo -m $username
			echo "$username:$password" | chpasswd
		else
			echo "Unidentified user: Skipping"
		fi
	fi
	
	# Add Exercise Control SSH-key
	if [[ $3 == "all" ]] || [[ $3 == 3 ]] ;
	then
		mkdir /home/$username/.ssh
		echo "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC+vCPrlcBeNpq5O3MojLiJZOzYSZEkEOgQJgof6OIW3MsKKAUir+txUE/NwAprRQzoisgB3305eZgRsmW5pwP9LH5Aot0sROi4XRGc7iE8O/xq3MNT/jhmjYAG2BDdaZWm2Mg0wKKSaZe/aZGmr/aW10x2W24wIdS+nTUrctqNkyBvC5y4QyfX3teh+xB7o3TBfp35tXjf0zwLPUhXXCLGn7fCFnPQa8RurQkMtylmGNL9mSytsRGnW5s9++PK51u9pr9iH69X4a413++VjcPeZ6z3TmgPNNtAeyliEhX9U7oeEdy1/r9hM84Xg6laKUkewOtSQZQ760oXfT219TqB nagios@disc.classex.tu" > /home/$username/.ssh/authorized_keys
	fi

done <$1 3<$2  		# Piping the TeamXEmployee.csv file into the first desc, and the 8606.txt file

# Clear Bash history
echo "0" > ~/.bash_history || echo "0" > ~/.history


