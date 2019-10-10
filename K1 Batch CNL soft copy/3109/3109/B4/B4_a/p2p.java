import java.io.*;
import java.net.*;
import java.io.File;
import java.io.FileReader;
import java.io.LineNumberReader;
 
public class p2p
{
    public static void main(String args[])
    {
    		DatagramSocket sock0, sock1, sock2, sock3 = null;
    		
		try
		{
			String fileName = "file.txt";
	
			File file = new File(fileName);
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			String line, temp = "";
			while((line = br.readLine()) != null)
			{
			    System.out.println(line);
			    temp = line;
			}
			
			String[] temp1 = temp.split(",");
			int[] port = new int[4];
			
			int i = 0;
			int flag = 0;
			
			flag = Integer.parseInt(args[0]);
			
			for(i=0;i<4;i++)
			{
				port[i] = Integer.parseInt(temp1[i]);
				System.out.println(port[i]);
			} 
			
			BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
                	String s0 = "";
                	String dummy = "";
                	
                	InetAddress host = InetAddress.getByName("localhost");
			
			if(flag == 0)
			{
				sock0 = new DatagramSocket(port[0]);
				System.out.println("Socket 0 created");
					
				System.out.println("Enter your message");
								
				s0 = input.readLine();
				byte[] s1 = s0.getBytes();
				
				DatagramPacket dp1 = new DatagramPacket(s1 , s1.length , host , port[1]);
				sock0.send(dp1);
				DatagramPacket dp2 = new DatagramPacket(s1 , s1.length , host , port[2]);
				sock0.send(dp2);
				DatagramPacket dp3 = new DatagramPacket(s1 , s1.length , host , port[3]);
				sock0.send(dp3);
			}
			else if(flag == 1)
			{
				sock1 = new DatagramSocket(port[1]);
				System.out.println("Socket 1 created");
				
				byte[] buffer = new byte[65536];
				DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
				sock1.receive(reply);
					 
				byte[] data = reply.getData();
				String s1 = new String(data, 0, reply.getLength());
				
				System.out.println(reply.getAddress().getHostAddress() + " : " + reply.getPort() + " - " + s1);
			}
			else if(flag == 2)
			{
				sock2 = new DatagramSocket(port[2]);
				System.out.println("Socket 2 created");
				
				byte[] buffer = new byte[65536];
				DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
				sock2.receive(reply);
					 
				byte[] data = reply.getData();
				String s1 = new String(data, 0, reply.getLength());
				
				System.out.println(reply.getAddress().getHostAddress() + " : " + reply.getPort() + " - " + s1);
			}
			else if(flag == 3)
			{
				sock3 = new DatagramSocket(port[3]);
				System.out.println("Socket 3 created");
				
				byte[] buffer = new byte[65536];
				DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
				sock3.receive(reply);
					 
				byte[] data = reply.getData();
				String s1 = new String(data, 0, reply.getLength());
				
				System.out.println(reply.getAddress().getHostAddress() + " : " + reply.getPort() + " - " + s1);
			}	
			else
			{
				System.out.println("Error");
			}	
		}
		catch(Exception e)
		{
			System.out.println(e);
		}		
	}
}
