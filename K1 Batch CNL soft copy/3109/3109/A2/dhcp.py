import os
import getpass

direct = os.getcwd()
f = open(direct + "/etc/dhcp/dhcpd.conf","w")
#f = open(direct + "/Documents/dummy.conf","w")
f.truncate()

subnet = '192.168.8.0'
lowerIP = '192.168.8.10'
upperIP = '192.168.8.20'
clientIP = ''
username = getpass.getuser()
userPassword = ''
rootPassword = ''

content1 = 'subnet ' + subnet + ' netmask 255.255.255.0 {\nrange '+lowerIP+' '+ upperIP+';\n'
content2 = 'option domain-name-servers ns1.internal.example.org;\noption domain-name "internal.example.org";\n'
content3 = 'option routers 192.168.8.254;\noption broadcast-address 192.168.8.255;'
content4 = 'default-lease-time 600;\nmax-lease-time 7200;\n}'

content = content1 + content2 + content3 + content4
f.write(content)

os.system("systemctl restart dhcpd")
os.system("systemctl status dhcpd")
sshCommand = "ssh "+username+"@"+clientIP

os.system(sshCommand)
os.system(userPassword)
os.system("su")
os.system(rootPassword)
os.system("yum install dhcp")
