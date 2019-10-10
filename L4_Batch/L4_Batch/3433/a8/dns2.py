
#A8
import socket
str=raw_input("Enter URL:")
type(str)

add=socket.gethostbyname(str)
print('Hostname:'+str)
print ('IP:'+add)


ip=raw_input("Enter IP Address:")
type(ip)

ipaddr=socket.gethostbyaddr(ip)
print ('IP:'+ip)
print('Hostname:'+ipaddr[0])
