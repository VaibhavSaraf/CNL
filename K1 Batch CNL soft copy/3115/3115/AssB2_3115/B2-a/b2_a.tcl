#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red
$ns color 3 Yellow

#Open the NAM trace file
set nf [open b2.nam w]
$ns namtrace-all $nf

set nf1 [open b2.tr w]
$ns trace-all $nf1

#Define a 'finish' procedure
proc finish {} {
        global ns nf
        $ns flush-trace
        #Close the NAM trace file
        close $nf
        #Execute NAM on the trace file
        exec nam b2.nam &
        exit 0
}

#Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n3 2Mb 10ms DropTail

#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient up
$ns duplex-link-op $n0 $n2 orient left-down
$ns duplex-link-op $n0 $n3 orient right-down

#Setup a TCP connection
set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$ns attach-agent $n0 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n1 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 1

set tcp2 [new Agent/TCP]
$tcp2 set class_ 2
$ns attach-agent $n0 $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $n3 $sink2
$ns connect $tcp2 $sink2
$tcp2 set fid_ 2


#Setup a FTP over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ftp2 set type_ FTP


#Schedule events for the CBR and FTP agents
$ns at 0.2 "$ftp1 start"
$ns at 0.2 "$ftp2 start"
$ns at 2.0 "$ftp1 stop"
$ns at 2.1 "$ftp2 stop"

#Detach tcp and sink agents (not really necessary)
$ns at 2.5 "$ns detach-agent $n0 $tcp1 ; $ns detach-agent $n1 $sink1"
$ns at 2.5 "$ns detach-agent $n0 $tcp2 ; $ns detach-agent $n3 $sink2"

#Call the finish procedure after 5 seconds of simulation time
$ns at 3.0 "finish"

#Run the simulation
$ns run
