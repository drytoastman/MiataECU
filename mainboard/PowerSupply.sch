EESchema Schematic File Version 2  date 10/29/2011 4:15:13 AM
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:PNPComponents
LIBS:MiataPNP-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 2 10
Title ""
Date "29 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4200 1700 0    60   Input ~ 0
12V
Connection ~ 4600 1700
Wire Wire Line
	4200 1700 4950 1700
Wire Wire Line
	4600 1700 4600 2100
Connection ~ 3600 2900
Wire Wire Line
	6700 2900 6700 2500
Wire Wire Line
	6100 2100 5750 2100
Connection ~ 5150 2900
Wire Wire Line
	5750 2500 5750 2900
Connection ~ 4350 2900
Wire Wire Line
	4350 2900 4350 2500
Wire Wire Line
	3600 2600 3600 2900
Connection ~ 3600 2100
Wire Wire Line
	3900 2100 3050 2100
Connection ~ 3850 2100
Wire Wire Line
	4600 2100 4300 2100
Connection ~ 4350 2100
Wire Wire Line
	5150 2900 5150 2650
Connection ~ 3850 2900
Wire Wire Line
	4600 2900 4600 2500
Connection ~ 4600 2900
Connection ~ 5750 2900
Wire Wire Line
	6600 2100 7000 2100
Connection ~ 6700 2100
Wire Wire Line
	3600 2900 7000 2900
Connection ~ 6700 2900
Wire Wire Line
	5350 1700 5750 1700
Wire Wire Line
	5750 1700 5750 2100
$Comp
L DIODE D13
U 1 1 4EABC49D
P 5150 1700
F 0 "D13" H 5150 1800 40  0000 C CNN
F 1 "1N4001" H 5150 1600 40  0000 C CNN
F 2 "D4" H 5150 1700 60  0001 C CNN
	1    5150 1700
	-1   0    0    1   
$EndComp
Text HLabel 7000 2900 2    60   Input ~ 0
GND
Text HLabel 7000 2100 2    60   Input ~ 0
5V
Text HLabel 3050 2100 0    60   Input ~ 0
12VRAW
$Comp
L CP1 C2
U 1 1 4EA86FAB
P 5750 2300
F 0 "C2" H 5800 2400 50  0000 L CNN
F 1 "33uF" H 5800 2200 50  0000 L CNN
F 2 "C2V8" H 5750 2300 60  0001 C CNN
F 4 "V3-C17" H 5750 2300 60  0001 C CNN "Digikey"
	1    5750 2300
	1    0    0    -1  
$EndComp
$Comp
L CP1 C1
U 1 1 4EA86FAA
P 4600 2300
F 0 "C1" H 4650 2400 50  0000 L CNN
F 1 "33uF" H 4650 2200 50  0000 L CNN
F 2 "C2V8" H 4600 2300 60  0001 C CNN
F 4 "V3-C16" H 4600 2300 60  0001 C CNN "Digikey"
	1    4600 2300
	1    0    0    -1  
$EndComp
$Comp
L ZENER D7
U 1 1 4EA86FA9
P 6700 2300
F 0 "D7" H 6700 2400 50  0000 C CNN
F 1 "5.6V 1W" H 6700 2200 40  0000 C CNN
F 2 "D4" H 6700 2300 60  0001 C CNN
F 4 "V3-D19" H 6700 2300 60  0001 C CNN "Digikey"
	1    6700 2300
	0    -1   -1   0   
$EndComp
$Comp
L R M1
U 1 1 4EA86FA8
P 3600 2350
F 0 "M1" V 3680 2350 50  0000 C CNN
F 1 "MOV" V 3600 2350 50  0000 C CNN
F 2 "R4" H 3600 2350 60  0001 C CNN
F 4 "V3-MOV1" V 3600 2350 60  0001 C CNN "Digikey"
	1    3600 2350
	1    0    0    -1  
$EndComp
$Comp
L DIODE D3
U 1 1 4EA86FA7
P 3850 2300
F 0 "D3" H 3850 2400 40  0000 C CNN
F 1 "1N4001" H 3850 2200 40  0000 C CNN
F 2 "D4" H 3850 2300 60  0001 C CNN
F 4 "V3-D11" H 3850 2300 60  0001 C CNN "Digikey"
	1    3850 2300
	0    -1   -1   0   
$EndComp
$Comp
L ZENER D4
U 1 1 4EA86FA6
P 3850 2700
F 0 "D4" H 3850 2800 50  0000 C CNN
F 1 "12V 1W" H 3850 2600 40  0000 C CNN
F 2 "D4" H 3850 2700 60  0001 C CNN
F 4 "V3-D13" H 3850 2700 60  0001 C CNN "Digikey"
	1    3850 2700
	0    1    1    0   
$EndComp
$Comp
L DIODE D5
U 1 1 4EA86FA5
P 4100 2100
F 0 "D5" H 4100 2200 40  0000 C CNN
F 1 "1N4001" H 4100 2000 40  0000 C CNN
F 2 "D4" H 4100 2100 60  0001 C CNN
F 4 "V3-D10" H 4100 2100 60  0001 C CNN "Digikey"
	1    4100 2100
	1    0    0    -1  
$EndComp
$Comp
L ZENER D6
U 1 1 4EA86FA4
P 4350 2300
F 0 "D6" H 4350 2400 50  0000 C CNN
F 1 "22V 1W" H 4350 2200 40  0000 C CNN
F 2 "D4" H 4350 2300 60  0001 C CNN
F 4 "V3-D12" H 4350 2300 60  0001 C CNN "Digikey"
	1    4350 2300
	0    -1   -1   0   
$EndComp
$Comp
L LM2937 U4
U 1 1 4EA86FA3
P 5150 2200
F 0 "U4" H 4950 2450 60  0000 C CNN
F 1 "LM2937" H 5300 2450 60  0000 C CNN
F 2 "TO220" H 4850 2350 60  0001 C CNN
F 4 "V3-U5" H 5150 2200 60  0001 C CNN "Digikey"
	1    5150 2200
	1    0    0    -1  
$EndComp
Text Notes 4250 3050 0    60   ~ 0
Copy of V3 Board 5V Supply\n(scavange parts)
$Comp
L FUSE F1
U 1 1 4EA86FA2
P 6350 2100
F 0 "F1" H 6450 2150 40  0000 C CNN
F 1 "FUSE" H 6250 2050 40  0000 C CNN
F 2 "C2" H 6350 2100 60  0001 C CNN
F 4 "V3-F1" H 6350 2100 60  0001 C CNN "Digikey"
	1    6350 2100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
