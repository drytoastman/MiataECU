EESchema Schematic File Version 2  date 11/2/2011 2:39:47 AM
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
Sheet 10 11
Title ""
Date "2 nov 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7000 3200 5350 3200
Connection ~ 7000 3200
Connection ~ 8400 3800
Wire Wire Line
	8450 3800 8350 3800
Wire Wire Line
	4500 3700 4700 3700
Connection ~ 3000 4550
Wire Wire Line
	3000 4450 3000 4550
Wire Wire Line
	7000 4550 7000 4350
Wire Wire Line
	6400 3950 6300 3950
Connection ~ 6350 4550
Wire Wire Line
	3400 3950 3000 3950
Connection ~ 5800 3650
Wire Wire Line
	6400 3650 5800 3650
Wire Wire Line
	5800 3200 5800 3950
Wire Wire Line
	7850 3800 7650 3800
Wire Wire Line
	7650 3800 7650 3650
Wire Wire Line
	3400 3600 3000 3600
Connection ~ 5800 3200
Connection ~ 4500 4550
Wire Wire Line
	6350 4150 6350 3950
Connection ~ 6350 3950
Wire Wire Line
	7650 4550 7650 3950
Connection ~ 7000 4550
Wire Wire Line
	4500 4550 4500 3900
Wire Wire Line
	2800 4550 8400 4550
Wire Wire Line
	8400 4550 8400 4200
Connection ~ 7650 4550
$Comp
L ZENER D15
U 1 1 4EADFC0D
P 8400 4000
F 0 "D15" H 8400 4100 50  0000 C CNN
F 1 "5.1V" H 8400 3900 40  0000 C CNN
F 2 "D4" H 8400 4000 60  0001 C CNN
F 4 "parts" H 8400 4000 60  0001 C CNN "Digikey"
	1    8400 4000
	0    -1   -1   0   
$EndComp
$Comp
L R R21
U 1 1 4EADFC02
P 8100 3800
F 0 "R21" V 8180 3800 50  0000 C CNN
F 1 "1K" V 8100 3800 50  0000 C CNN
F 2 "R4" H 8100 3800 60  0001 C CNN
	1    8100 3800
	0    1    1    0   
$EndComp
$Comp
L FOD817 U12
U 1 1 4EAC4F9C
P 3950 3800
F 0 "U12" H 3900 4150 70  0000 C CNN
F 1 "FOD817" H 3900 3450 70  0000 C CNN
F 2 "DIP-4__300" H 3950 3750 60  0001 C CNN
F 4 "FOD817A-ND" H 3950 3800 60  0001 C CNN "Digikey"
	1    3950 3800
	1    0    0    -1  
$EndComp
Text HLabel 2800 4550 0    60   Input ~ 0
GND
Text HLabel 8450 3800 2    60   Input ~ 0
12VMeasure
Text HLabel 4700 3700 2    60   Input ~ 0
PhasePin
Text HLabel 3000 3600 0    60   Input ~ 0
Phase12V
$Comp
L AD8276 U13
U 1 1 4EABDBCA
P 7000 3800
F 0 "U13" H 6750 4150 60  0000 C CNN
F 1 "AD8276" H 7200 3500 60  0000 C CNN
F 2 "SO8E" H 7000 3800 60  0001 C CNN
F 4 "AD8276ARZ-ND" H 7000 3800 60  0001 C CNN "Digikey"
F 5 "BRZ version avail" H 7000 3800 60  0001 C CNN "Note"
	1    7000 3800
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 4EABDBC9
P 6050 3950
F 0 "R26" V 6130 3950 50  0000 C CNN
F 1 "10K" V 6050 3950 50  0000 C CNN
F 2 "R4" H 6050 3950 60  0001 C CNN
	1    6050 3950
	0    1    1    0   
$EndComp
$Comp
L ZENER D12
U 1 1 4EABDBC8
P 6350 4350
F 0 "D12" H 6350 4450 50  0000 C CNN
F 1 "LM4040,10V" H 6350 4250 40  0000 C CNN
F 2 "SOT23-3" H 6350 4350 60  0001 C CNN
F 4 "LM4040DIM3X-10CT-ND" H 6350 4350 60  0001 C CNN "Digikey"
	1    6350 4350
	0    -1   -1   0   
$EndComp
Text HLabel 5350 3200 0    60   Input ~ 0
12V
$Comp
L R R25
U 1 1 4EABDBC6
P 3000 4200
F 0 "R25" V 3080 4200 50  0000 C CNN
F 1 "10K" V 3000 4200 50  0000 C CNN
F 2 "R4" H 3000 4200 60  0001 C CNN
	1    3000 4200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
