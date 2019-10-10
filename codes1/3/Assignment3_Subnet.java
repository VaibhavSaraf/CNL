import java.util.BitSet;
import java.util.Scanner;


public class Subnet {
	BitSet A1= new BitSet(8);
	BitSet B1= new BitSet(8);BitSet C1= new BitSet(8);
	BitSet D1= new BitSet(8);
	BitSet E1= new BitSet(8);
	public static void main(String [] args)
	{
		Subnet S = new Subnet();
		String ip;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the IP address in the form A.B.C.D/E");
		ip = in.nextLine();int a;int b; int c;int d;
		int A = Integer.parseInt(ip.substring(0,  a =ip.indexOf(".", 0)));
	//	System.out.println(a);
		int B = Integer.parseInt(ip.substring( a+1, b= ip.indexOf(".", a+1)));
		//System.out.println(b);
		int C = Integer.parseInt(ip.substring( b+1, c= ip.indexOf(".", b+1)));
		int D =Integer.parseInt(ip.substring( c+1, d= ip.indexOf("/")));
		int E = Integer.parseInt(ip.substring(ip.indexOf("/")+1, ip.length()));
	//	System.out.println(A +"      "+ B+ "    "+C+"   "+D+"   "+E);
		S.E1=S.convertInttoBitSet(E);
		S.D1=S.convertInttoBitSet(D);
		S.C1=S.convertInttoBitSet(C);
		S.B1=S.convertInttoBitSet(B);
		S.A1=S.convertInttoBitSet(A);
		//System.out.println(S.E1);
	}
	
	BitSet convertInttoBitSet(int A)
	{
		BitSet temp = new BitSet(8);
		for(int i=0;i<8;i++)
		{
			if(A%2==1)
			{
				temp.set(i);
				
			}
			A=A/2;
		}
		return temp;
	}
	                 
	int getIPClass( BitSet A1)
	{
		if(A1.get(7)==false)
			return 1 ;//class A
		if(A1.get(7)==true && A1.get(6)==false)
			return 2; // class B
		if(A1.get(7)==true && A1.get(6)==true && A1.get(5)==false)
			return 3; // class C
		return 0;
	}
	BitSet AndB1(BitSet B1,int Ipclass,int Add1s )
	{
		BitSet temp = new BitSet(8); 
		for(int i=7;i<(7-Add1s);i--)
		{
			temp.set(i);
		}
		 B1.and(temp);
		 return B1;
	}
	BitSet AndC1(BitSet C1,int Ipclass,int Add1s )
	{
		BitSet temp = new BitSet(8); 
		for(int i=7;i<(7-Add1s);i--)
		{
			temp.set(i);
		}
		 C1.and(temp);
		 return C1;
	}
	BitSet AndD1(BitSet D1,int Ipclass,int Add1s )
	{
		BitSet temp = new BitSet(8); 
		for(int i=7;i<(7-Add1s);i--)
		{
			temp.set(i);
		}
		 D1.and(temp);
		 return D1;
	}
}
