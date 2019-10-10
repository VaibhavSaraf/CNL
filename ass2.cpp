#include<iostream>
#include<math.h>

using namespace std;

int main() 
{
	int bits, a[20];
	int parity = 0;
	
	cout << "Enter the no. of data bits you want to enter :" << endl;
	cin >> bits;
	
	while(bits + parity + 1 > pow(2, parity))
	{
		parity++;
	}
	
	cout << "No. of bits to be added :" << parity << endl;
	cout << "Total no. of bits :" << bits + parity << endl;
	
	cout << "Enter the data bits one by one(1/0) :" << endl;
	for(int i = 0; i < (bits + parity); i++)
	{
		cin >> a[i];
		//cin >> " "; 
	}
	
	cout << endl;
	cout << "Data Bits Entered are :" << endl;
	for(int i = 0; i < (bits + parity); i++) 
	{
		cout << a[i];
		//cout << " ";
	} 
	cout << endl;
	
	int data[bits + parity];
	int b = 0, c = 1;
	
	for(int i = 0; i < (bits + parity); i++)
	{
		if(i == pow(2, b))
		{
			data[i] = -1;
			b++;
		}
		
		else
		{
			data[i] = a[c];
			c++;
		}
	}
	
	cout << "Data bits are encoded with parity bits :" << endl;
	for(int i = 0; i < (bits + parity); i++)
	{
		cout << data[i];
		//cout << " ";
	}
	cout << endl;
	
	//PARITY BIT CALCULATION
}
