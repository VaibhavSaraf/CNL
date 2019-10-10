#include<iostream>
using namespace std;

int main()
{
int a[12];
int c1,c2,c3,c4;
cout<<"enter the 7 bit code"<<endl;

for(int i=0;i<11;i++)
	{
		if(i==0 || i==1 || i==3 || i==7)
			{
				continue;
			}
		else
			{
				cin>>a[i];
			}
	}
	
	
	
for(int i=0;i<11;i++)


	{
		if(i==2 || i==4 || i==6 || i==8 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c1++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
   
   if(c1%2==0)
   	{
   	 	a[0]=0;
   	}
   	
   	else
     {
       a[0]=1;
     }
     
     
     
     
    for(int i=0;i<11;i++)


	{
		if(i==2 || i==5 || i==6 || i==9 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c2++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
   
   if(c2%2==0)
   	{
   	 	a[1]=0;
   	}
   	
   	else
     {
       a[1]=1;
     }
     
     
     
      for(int i=0;i<11;i++)


	{
		if(i==4 || i==5 || i==6)
		   {
		       if(a[i]==1)
		       	{
		       		c3++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
   
   if(c3%2==0)
   	{
   	 	a[3]=0;
   	}
   	
   	else
     {
       a[3]=1;
     }
     
     
       for(int i=0;i<11;i++)


	{
		if(i==8 || i==9 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c4++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
   
   if(c4%2==0)
   	{
   	 	a[7]=0;
   	}
   	
   	else
     {
       a[7]=1;
     }
     
     cout<<"the code is"<<endl;
     
     for(int i=0;i<11;i++)
     	{
     	   cout<<a[i];
     	   cout<<" ";
     	 }


}     	 
     	   
     
     
     
     
   		
   	 
     
     
   	
	



