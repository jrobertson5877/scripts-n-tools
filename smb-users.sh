#!/bin/bash

while IFS=':' read user pass; do
	(echo $pass; echo $pass) | smbpasswd -s -a $user
done <$1
