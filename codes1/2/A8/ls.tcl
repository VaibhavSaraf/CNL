set ns [new Simulator]

$ns color 1 Red
$ns color 2 Green

set nr [open thro.tr w]
$ns trace-all $nr
set nf [open thro.nam w]

$ns namtrace-all $nf
        proc finish { } {
        global ns nr nf
        $ns flush-trace
        close $nf
        close $nr
        exec nam thro.nam &
	exit 0
        }

for { set i 0 } { $i < 6} { incr i 1 } {
	set n($i) [$ns node]}

for {set i 0} {$i < 5} {incr i} {
	$ns duplex-link $n($i) $n([expr $i+1]) 1Mb 10ms DropTail  }
$ns duplex-link $n(0) $n(5) 1Mb 10ms DropTail
$ns duplex-link $n(1) $n(3) 1Mb 10ms DropTail
$ns duplex-link $n(2) $n(4) 1Mb 10ms DropTail

set udp [new Agent/UDP]
$ns attach-agent $n(0) $udp
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
set null [new Agent/Null]
$ns attach-agent $n(2) $null
$ns connect $udp $null
$udp set fid_ 1

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n(1) $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n(4) $sink
$ns connect $tcp $sink
$tcp set fid_ 2

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns rtproto LS

$ns rtmodel-at 0.5 down $n(2) $n(4)
$ns rtmodel-at 1.0 down $n(1) $n(3)
$ns rtmodel-at 1.5 up $n(2) $n(4)
$ns rtmodel-at 2.0 up $n(1) $n(3)

$ns at 0.2 "$cbr start"
$ns at 0.8 "$ftp start"

$ns at 2.5 "finish"

$ns run
