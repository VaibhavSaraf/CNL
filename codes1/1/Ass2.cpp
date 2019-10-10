#include<iostream>
 
using namespace std;
 
int main() 
{
    int data[10];
    int hcode[10],c,c1,c2,c3,i;
    cout<<"\nEnter 4 bits of data one by one";
    cin>>data[0];
    cin>>data[1];
    cin>>data[2];
    cin>>data[4];
 
    //Calculation of even parity
    data[6]=data[0]^data[2]^data[4];
    data[5]=data[0]^data[1]^data[4];
    data[3]=data[0]^data[1]^data[2];
 
    cout<<"\nEncoded data is";
    for(i=0;i<7;i++)
        cout<<data[i];
    cout<<"\nEnter received data bits one by one";
    for(i=0;i<7;i++)
        cin>>hcode[i];
    c1=hcode[6]^hcode[4]^hcode[2]^hcode[0];
    c2=hcode[5]^hcode[4]^hcode[1]^hcode[0];
    c3=hcode[3]^hcode[2]^hcode[1]^hcode[0];
    c=c3*4+c2*2+c1 ;
    if(c==0) 
    {
        cout<<"\nNo error while transmission of data\n";
    }
    else 
    {
        cout<<"\nError on position "<<c;
        
        cout<<"\nData sent : ";
        for(i=0;i<7;i++)
            cout<<data[i];
        
        cout<<"\nData received : ";
        for(i=0;i<7;i++)
            cout<<hcode[i];
        
        cout<<"\nCorrect message is\n";
        
        //if errorneous bit is 0 we complement it else vice versa
        if(hcode[7-c]==0)
            hcode[7-c]=1;
        else
             hcode[7-c]=0;
        for (i=0;i<7;i++) 
	{
            cout<<hcode[i];
        }
    }
    return 0;
}
