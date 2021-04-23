#!/usr/bin/python
import csv
import urllib
import urllib2
import requests
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
url = "https://disc2.classex.tu/webpass/index.php"
tail = "?submit"
s = requests.Session()
password = raw_input("password: ")


team = 5    # Change me
data =    {
    "password" : password,
    "team" : team
    }
try:
    r = s.get(url, verify=False)
except Exception as err:
    print("something went wrong")
print(r.text)
r = s.post(url, verify=False, 
        data = {
            'password' : password,
            'team' : team})
print(r.text)
reader =csv.reader(
        open("user-pass.txt"), delimiter=":"
        )
for row in reader:
    user = row[0] 
    password = row[1]
    try:
        r = s.post(url+"?submit", verify=False, timeout=3,
                data = {'user' : user,
                    'password1' : password,
                    'password2' : password,
                    'submit' : 'Submit'})

    except Exception as err:
        print("you fucked up")
    print(r.text)
