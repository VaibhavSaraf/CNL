#include<iostream>
using namespace std;

int main()
{
	int n1,n3;
	cout<<"========RECEIVER SIDE========";
	cout<<"Enter the size of key value in bits:";
	cin>>n1;
	cout<<"Enter the size of data value in bits:";
	cin>>n3;
	bool key[n1];
	bool data[n3];
	int n2=n3-n1+1;
	bool data2[n2];
	cout<<"Enter the key:";
	for(int i=0;i<n1;i++)
	{
		cin>>key[i];
	}
	cout<<"Enter the data:";
	for(int i=0;i<n3;i++)
	{
		cin>>data[i];
		if(i<n2)
		data2[i]=data[i];
	}
	
	int i=0;
	while(i<n2)
	{
		if(data[i]==1)
		{
			for(int j=i;j<(i+n1);j++)
			{
				data[j]=data[j]^key[j-i];
			}
		}
		for(int j=0;j<(n2+n1-1);j++)
			cout<<data[j];
		cout<<"\n";
		i++;
	}
	int flag=0;
	while(i<n3)
	{
		if(data[i]==1)
		{
			flag=1;
			break;
		}
		else 
		i++;
	}
	if(flag==1)
	{
		cout<<"Discard data";
	}
	else
	{
		cout<<"No error detected\n";
		cout<<"The received frame is:";
		for(int j=0;j<n2;j++)
			cout<<data[j];
	}
}
