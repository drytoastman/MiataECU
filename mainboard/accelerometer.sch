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
Sheet 10 10
Title ""
Date "29 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3350 2400 0    60   Input ~ 0
5V
Text HLabel 3400 5000 0    60   Input ~ 0
GND
Connection ~ 4550 5000
Wire Wire Line
	3400 5000 5500 5000
Connection ~ 5500 3100
Connection ~ 5050 5000
Wire Wire Line
	5500 5000 5500 3100
Wire Wire Line
	5050 5000 5050 4850
Wire Wire Line
	4550 5000 4550 4850
Connection ~ 4800 4100
Wire Wire Line
	4800 4350 4800 4100
Wire Wire Line
	6050 3800 5300 3800
Wire Wire Line
	5300 4250 5300 3800
Wire Wire Line
	4250 4250 5300 4250
Wire Wire Line
	6050 3300 5100 3300
Wire Wire Line
	5100 3950 5100 3300
Wire Wire Line
	4250 3950 5100 3950
Wire Wire Line
	3400 4100 3750 4100
Wire Wire Line
	4350 3700 4700 3700
Wire Wire Line
	6050 3600 4700 3600
Wire Wire Line
	4700 3600 4700 3700
Wire Wire Line
	6050 3100 4650 3100
Wire Wire Line
	4650 3100 4650 2950
Wire Wire Line
	4100 2400 3350 2400
Wire Wire Line
	5250 2400 5250 3200
Wire Wire Line
	3950 3700 3400 3700
Wire Wire Line
	6050 3200 4150 3200
Wire Wire Line
	4150 3200 4150 3400
Connection ~ 5250 3200
Connection ~ 4550 3200
Connection ~ 4550 3700
Wire Wire Line
	3750 3950 3400 3950
Wire Wire Line
	3750 4250 3400 4250
Wire Wire Line
	4250 4100 5200 4100
Wire Wire Line
	5200 4100 5200 3700
Wire Wire Line
	5200 3700 6050 3700
Wire Wire Line
	5050 4250 5050 4350
Connection ~ 5050 4250
Wire Wire Line
	4550 4350 4550 3950
Connection ~ 4550 3950
Wire Wire Line
	4800 4850 4800 5000
Connection ~ 4800 5000
Connection ~ 3750 2400
Text HLabel 3400 4250 0    60   Input ~ 0
SCL
Text HLabel 3400 4100 0    60   Input ~ 0
SDI
Text HLabel 3400 3950 0    60   Input ~ 0
CS
Text HLabel 3400 3700 0    60   Input ~ 0
SDO
$Comp
L R R33
U 1 1 4EABCC8E
P 5050 4600
F 0 "R33" V 5130 4600 50  0000 C CNN
F 1 "10K" V 5050 4600 50  0000 C CNN
F 2 "R4" H 5050 4600 60  0001 C CNN
	1    5050 4600
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 4EABCC8A
P 4800 4600
F 0 "R32" V 4880 4600 50  0000 C CNN
F 1 "10K" V 4800 4600 50  0000 C CNN
F 2 "R4" H 4800 4600 60  0001 C CNN
	1    4800 4600
	1    0    0    -1  
$EndComp
$Comp
L R R31
U 1 1 4EABCC86
P 4550 4600
F 0 "R31" V 4630 4600 50  0000 C CNN
F 1 "10K" V 4550 4600 50  0000 C CNN
F 2 "R4" H 4550 4600 60  0001 C CNN
	1    4550 4600
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 4EABCC5E
P 4000 4250
F 0 "R29" V 4080 4250 50  0000 C CNN
F 1 "10K" V 4000 4250 50  0000 C CNN
F 2 "R4" H 4000 4250 60  0001 C CNN
	1    4000 4250
	0    1    1    0   
$EndComp
$Comp
L R R27
U 1 1 4EABCC58
P 4000 3950
F 0 "R27" V 4080 3950 50  0000 C CNN
F 1 "10K" V 4000 3950 50  0000 C CNN
F 2 "R4" H 4000 3950 60  0001 C CNN
	1    4000 3950
	0    1    1    0   
$EndComp
$Comp
L R R30
U 1 1 4EABCBD3
P 4550 3450
F 0 "R30" V 4630 3450 50  0000 C CNN
F 1 "10K" V 4550 3450 50  0000 C CNN
F 2 "R4" H 4550 3450 60  0001 C CNN
	1    4550 3450
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q6
U 1 1 4EABCB82
P 4150 3600
F 0 "Q6" H 4160 3770 60  0000 R CNN
F 1 "BSS138" H 4160 3450 60  0000 R CNN
	1    4150 3600
	0    -1   1    0   
$EndComp
$Comp
L R R28
U 1 1 4EABCA77
P 4000 4100
F 0 "R28" V 4080 4100 50  0000 C CNN
F 1 "10K" V 4000 4100 50  0000 C CNN
F 2 "R4" H 4000 4100 60  0001 C CNN
	1    4000 4100
	0    1    1    0   
$EndComp
$Comp
L 3.3V_REGULATOR U14
U 1 1 4EABCA04
P 4650 2500
F 0 "U14" H 4450 2300 60  0000 C CNN
F 1 "3.3V_REGULATOR" H 4700 2750 60  0000 C CNN
F 2 "SOT23-5" H 4350 2650 60  0001 C CNN
	1    4650 2500
	1    0    0    -1  
$EndComp
$Comp
L ADXL345BOARD U15
U 1 1 4EABC9F0
P 6350 3300
F 0 "U15" H 6400 2650 60  0000 C CNN
F 1 "ADXL345BOARD" H 6600 3650 60  0000 C CNN
F 2 "ADXL345Breakout" H 6600 2550 60  0001 C CNN
	1    6350 3300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
