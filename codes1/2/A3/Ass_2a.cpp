/*Write a program in C/C++  for error detection and correction for 7/8 bits ASCII codes using Hamming
 Codes or CRC. Demonstrate the packets captured traces using Wireshark Packet Analyzer
 Tool for peer to peer mode.
( 50% students will perform Hamming Code and others will
 perform CRC)
	CODE:  CRC
*/

#include<iostream>
using namespace std;

int main()
{
	int n1,n2;
	cout<<"========SENDER SIDE========";
	cout<<"Enter the size of key value in bits:";
	cin>>n1;
	cout<<"Enter the size of data value in bits:";
	cin>>n2;
	bool key[n1];
	bool data[n2];
	bool data2[n2+n1-1];
	bool div[n2];
	cout<<"Enter the key:";
	for(int i=0;i<n1;i++)
	{
		cin>>key[i];
	}
	cout<<"Enter the data:";
	for(int i=0;i<n2;i++)
	{
		cin>>data[i];
		data2[i]=data[i];
	}
	for(int i=n2;i<(n2+n1-1);i++)
	{
		data2[i]=0;
	}
	int i=0;
	while(i<n2)
	{
		if(data2[i]==1)
		{
			for(int j=i;j<(i+n1);j++)
			{
				data2[j]=data2[j]^key[j-i];
			}
		}
		for(int j=0;j<(n2+n1-1);j++)
			cout<<data2[j];
		cout<<"\n";
		i++;
	}
	cout<<"The Data to be sent is:";
	for(i=0;i<(n2);i++)
	{
		cout<<data[i];
	}
	cout<<" ";
	for(int j=n2;j<(n2+n1-1);j++)
		cout<<data2[j];
	
}
