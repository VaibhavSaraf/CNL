#include<iostream>
using namespace std;

int main()
{
int a[12];
int c1,c2;
int c3=0;
int c4=0;

int p1,p2,p3,p4,p5=0;
cout<<"the 11 bit code is "<<endl;

for(int i=0;i<11;i++)
	{
		
           
		 cin>>a[i];
			
	}
	
cout<<"code is"<<endl;

for(int i=0;i<11;i++)
	{
		
           
		 cout<<a[i];
			
	}
cout<<endl;	
	
for(int i=0;i<11;i++)


	{
		if(i==0 || i==2 || i==4 || i==6 || i==8 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c1++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   cout<<c1<<endl;
   
   
   
 if(c1%2==0)
 	{
 		p1=0;
 	}
 else 
   p1=1;
     
   cout<<p1<<endl;
   
   
     
     
    for(int i=0;i<11;i++)


	{
		if(i==1 || i==2 || i==5 || i==6 || i==9 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c2++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
     cout<<c2<<endl;
   
   
    if(c2%2==0)
 	{
 		p2=0;
 	}
 else 
   p2=1;
     
   cout<<p2<<endl;
     
        
      for(int i=0;i<11;i++)


	{
	
		if(i==3 || i==4 || i==5 || i==6)
		   {
		       if(a[i]==1)
		       	{
		       		c3++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
     cout<<c3<<endl;
   
    if(c3%2==0)
 	{
 		p3=0;
 	}
 else 
   p3=1;
     
     cout<<p3<<endl;

     
     
       for(int i=0;i<11;i++)


	{
		if(i==7 || i==8 || i==9 || i==10)
		   {
		       if(a[i]==1)
		       	{
		       		c4++;
		       	}
		       	
		  }
		  
		  else 
		  	continue;
   }
   
     cout<<c4<<endl;
   
   
    if(c4%2==0)
 	{
 		p4=0;
 	}
 else 
   p4=1;
   cout<<p4<<endl;
     
   
 if(p1==0 &&p2== 0 && p3==0 && p4==0)
 	{
 		cout<<"the code is eror free"<<endl;
 
    }
    
  else
  {
  	cout<<"error is present at"<<endl;
  	p4=p4*1;
  	p3=p3*2;
  	p2=p2*4;
  	p1=p1*8;
  	p5=p4 + p3 + p2 + p1;
  	
  	cout<<p5;
  	
  	
  }
  
  
  }
     
     
     
     	   
     
     
     
     
   		
   	 
     
     
   	
	



