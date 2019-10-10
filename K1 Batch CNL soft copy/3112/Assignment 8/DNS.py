import socket

print 'Welcome to DNS to IP Address'
URL=raw_input('Enter URL')

addr1 = socket.gethostbyname(URL)
#addr2 = socket.gethostbyname('yahoo.com')
#addr3 = socket.gethostbyname('amazon.com')
#addr4 = socket.gethostbyname('gmail.com')
#addr5 = socket.gethostbyname('facebook.com')

print(addr1)
print 'WelCome IP address to DNS'
IP=raw_input('Enter IP Address')
addr6=socket.gethostbyaddr(IP)
print addr6
