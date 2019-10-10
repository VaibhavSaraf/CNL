import java.io.*;
import java.net.*;
 
public class udp_client
{
    public static void main(String args[])
    {
        DatagramSocket sock = null;
        int port = 7777;
        String s;
         
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
         
        try
        {
            sock = new DatagramSocket();
             
            InetAddress host = InetAddress.getByName("localhost");
            
            int flag = 0;
             
            while(true && flag == 0)
            {
                System.out.println("Enter message to send : ");
                s = cin.readLine();
                byte[] b = s.getBytes();
                 
                DatagramPacket  dp = new DatagramPacket(b , b.length , host , port);
                sock.send(dp);
                 
                byte[] buffer = new byte[65536];
                DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
                sock.receive(reply);
                 
                byte[] data = reply.getData();
                String s1 = new String(data, 0, reply.getLength());
                
                System.out.println(reply.getAddress().getHostAddress() + " : " + reply.getPort() + " - " + s1);
                
                if(s.equals("Over"))
                {
                	flag = 1;
                }
            }
        }
         
        catch(IOException e)
        {
            System.err.println("IOException " + e);
        }
    }
}
