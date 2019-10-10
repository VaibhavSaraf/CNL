import os
import random
print("Enter the CIDR :")
cidrs=raw_input()
[address,sub]=cidrs.split('/')





[ad1,ad2,ad3,ad4]=address.split('.')



nbit=int(sub)%8                        
ran=8-nbit


for i in range(2**nbit):
	print(ad1+"."+ad2+"."+ad3+"."+ad4)
	ad4=int(ad4)
	ad4=ad4+2**ran
	ad4=str(ad4)

nm=0;

for i in range(nbit):
	nm=nm+2**(7-i);
print(nm)


netmask="255.255.255."+str(nm)

print(netmask)


print("Enter the subnet number for client 1:")

n1=raw_input();
ad4=int(ad4)
n1=int(n1)
ad4=random.randrange((n1-1)*(2**ran) + 1,n1*(2**ran));
address = ad1+'.'+ad2+'.'+ad3+'.'+str(ad4);
print(address)
 
 

os.system("ifconfig enp3s0 "+address)
os.system("ifconfig enp3s0 netmask "+netmask)
os.system("ifconfig")


print("Enter the subnet number for client 2:")
n2=raw_input();
n2=int(n2)
ad4=int(ad4)
ad4=random.randrange((n2-1)*(2**ran) + 1,n2*(2**ran));
address = ad1+'.'+ad2+'.'+ad3+'.'+str(ad4);

print(address)
os.system("ping "+address)







