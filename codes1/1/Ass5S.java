import java.io.*;
import java.net.*;
 
public class udp_server
{
    public static void main(String args[])
    {
        DatagramSocket sock = null;
         
        try
        {
            sock = new DatagramSocket(7777);
             
            byte[] buffer = new byte[65536];
            DatagramPacket incoming = new DatagramPacket(buffer, buffer.length);
             
            System.out.println("Server socket created. Waiting for incoming data...");
            
            int flag = 0;
                         
            while(true && flag == 0)
            {
                sock.receive(incoming);
                byte[] data = incoming.getData();
                String s = new String(data, 0, incoming.getLength());
                 
                System.out.println(incoming.getAddress().getHostAddress() + " : " + incoming.getPort() + " - " + s);
                                
                if(s.equals("Over"))
                {
                	String over1 = "Connection terminated!";
                	byte[] over12 = over1.getBytes();
                	
                	DatagramPacket dp1 = new DatagramPacket(over12, over12.length, incoming.getAddress() , incoming.getPort());
                	sock.send(dp1);
               	}
                
                if(!s.equals("Over"))
                {
                	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
                	String ser = input.readLine();
                	byte[] se = ser.getBytes();
                
                	DatagramPacket dp = new DatagramPacket(se , se.length , incoming.getAddress() , incoming.getPort());
                	sock.send(dp);
                }
            }
        }
         
        catch(IOException e)
        {
            System.err.println("IOException " + e);
        }
    }
}
