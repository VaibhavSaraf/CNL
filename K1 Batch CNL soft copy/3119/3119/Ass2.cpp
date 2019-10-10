#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l;
	int ds;
	cout<<"\nEnter the dataword size";
	cin>>ds;
	int dw[20];
	cout<<"\nEnter frame";
	for(i=0;i<ds;i++)
	{
		cin>>dw[i];
	}
	int gs;
	cout<<"\nEnter Divisor size: ";
    	cin>>gs;
    	int g[20]; 
    	cout<<"\nEnter Divisor:";
    	for(i=0;i<gs;i++)
    	{
        	cin>>g[i];
    	}
	cout<<"\nSender's side";
	cout<<"\nDataword:";
    	for(i=0;i<ds;i++)
    	{
        	cout<<dw[i];
    	}
	cout<<"\nDivisor:";
    	for(i=0;i<gs;i++)
    	{
        	cout<<g[i];
    	}
	int rs=gs-1;
    	cout<<"\nNumber of 0's to be appended:"<<rs;
    	for (i=ds;i<ds+rs;i++)
    	{
        	dw[i]=0;
    	}
	int temp[20];
    	for(i=0;i<20;i++)
    	{
        	temp[i]=dw[i];
    	}
	cout<<"\nMessage after appending 0's :";
    	for(i=0;i<ds+rs;i++)
    	{
        	cout<<temp[i];
    	}
	//Division
	for(i=0;i<ds;i++)
    	{
        	j=0;
       	 	k=i;
        //check whether it is divisible or not
        	if(temp[k]>=g[j])
        	{
            		for(j=0,k=i;j<gs;j++,k++)
            		{
                		if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                		{
                    			temp[k]=0;
                		}
                		else
                		{
                    			temp[k]=1;
                		}
            		}
        	}
    	}
	 //CRC
    	int crc[15];
    	for(i=0,j=ds;i<rs;i++,j++)
    	{
        	crc[i]=temp[j];
    	}
    	cout<<"\nCRC bits: ";
    	for(i=0;i<rs;i++)
    	{
        	cout<<crc[i];
    	}
	cout<<"\nTransmitted Frame: ";
    	int tf[15];
    	for(i=0;i<ds;i++)
    	{
        	tf[i]=dw[i];
    	}
    	for(i=ds,j=0;i<ds+rs;i++,j++)
    	{
        	tf[i]=crc[j];
    	}
    	for(i=0;i<ds+rs;i++)
   	{
        	cout<<tf[i];
    	}
	cout<<"\nReceiver side : ";
    	cout<<"\nReceived Frame: ";
    	for(i=0;i<ds+rs;i++)
    	{
        	cout<<tf[i];
    	}
    	for(i=0;i<ds+rs;i++)
    	{
        	temp[i]=tf[i];
    	}
	//Division
	for(i=0;i<ds;i++)
    	{
        	j=0;
       	 	k=i;
        //check whether it is divisible or not
        	if(temp[k]>=g[j])
        	{
            		for(j=0,k=i;j<gs;j++,k++)
            		{
                		if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                		{
                    			temp[k]=0;
                		}
                		else
                		{
                    			temp[k]=1;
                		}
            		}
        	}
    	}
	cout<<"\nRemainder: ";
    	int rrem[15];
    	for(i=ds,j=0;i<ds+rs;i++,j++)
    	{
        	rrem[j]= temp[i];
    	}
    	for(i=0;i<rs;i++)
    	{
        	cout<<rrem[i];
    	}
 	int flag=0;
    	for(i=0;i<rs;i++)
    	{
        	if(rrem[i]!=0)
        	{
            		flag=1;
        	}
    	}
    	if(flag==0)
    	{
        	cout<<"\nSince Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct";
    	}
    	else
    	{
        	cout<<"\nSince Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error";
    	}
	return 0;	
}

