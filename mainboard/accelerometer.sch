EESchema Schematic File Version 2  date 11/1/2011 9:13:20 PM
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
Sheet 11 11
Title ""
Date "2 nov 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 5600 2300 0    60   ~ 0
3V
Connection ~ 3850 2300
Connection ~ 4050 2300
Wire Wire Line
	4050 2300 4050 2400
Wire Wire Line
	4050 2400 4100 2400
Connection ~ 5250 2850
Wire Wire Line
	5100 4000 5700 4000
Wire Wire Line
	5700 4000 5700 2300
Wire Wire Line
	3700 4450 5250 4450
Connection ~ 5250 4450
Wire Wire Line
	5400 3600 5400 3300
Wire Wire Line
	6050 3600 5850 3600
Wire Wire Line
	5850 3600 5850 3900
Wire Wire Line
	5850 3900 5100 3900
Wire Wire Line
	6050 3700 5100 3700
Connection ~ 5250 3500
Wire Wire Line
	5250 4450 5250 2850
Connection ~ 3900 4450
Wire Wire Line
	3800 4450 3800 3500
Wire Wire Line
	3800 3500 3900 3500
Wire Wire Line
	5100 3400 5100 3200
Wire Wire Line
	5100 3200 6050 3200
Connection ~ 3650 2300
Wire Wire Line
	3650 2300 3650 3400
Wire Wire Line
	3900 4450 3900 4100
Wire Wire Line
	5100 4450 5100 4100
Wire Wire Line
	3900 3800 3650 3800
Wire Wire Line
	3900 3600 3650 3600
Wire Wire Line
	3350 2300 4100 2300
Wire Wire Line
	3900 3700 3650 3700
Wire Wire Line
	3900 3900 3650 3900
Wire Wire Line
	3650 3400 3900 3400
Wire Wire Line
	5100 3500 5250 3500
Connection ~ 5100 4450
Connection ~ 3800 4450
Wire Wire Line
	5400 3600 5100 3600
Wire Wire Line
	5400 3300 6050 3300
Wire Wire Line
	5100 3800 6050 3800
Wire Wire Line
	3750 3400 3750 4000
Wire Wire Line
	3750 4000 3900 4000
Connection ~ 3750 3400
Connection ~ 5700 3200
Wire Wire Line
	3850 2700 3850 2850
Connection ~ 4800 2850
Wire Wire Line
	3850 2850 5900 2850
Wire Wire Line
	5900 2850 5900 2700
Connection ~ 5500 2850
Wire Wire Line
	5500 2400 5500 2450
Wire Wire Line
	5500 2300 5900 2300
Connection ~ 5700 2300
$Comp
L C C24
U 1 1 4EAF1C80
P 5900 2500
F 0 "C24" H 5950 2600 50  0000 L CNN
F 1 "1uF" H 5950 2400 50  0000 L CNN
F 2 "SM0805" H 5900 2500 60  0001 C CNN
	1    5900 2500
	1    0    0    -1  
$EndComp
$Comp
L C C22
U 1 1 4EAF1C74
P 3850 2500
F 0 "C22" H 3900 2600 50  0000 L CNN
F 1 "1uF" H 3900 2400 50  0000 L CNN
F 2 "SM0805" H 3850 2500 60  0001 C CNN
	1    3850 2500
	1    0    0    -1  
$EndComp
$Comp
L C C23
U 1 1 4EAF1C6B
P 5500 2650
F 0 "C23" H 5550 2750 50  0000 L CNN
F 1 "470pF" H 5550 2550 50  0000 L CNN
F 2 "SM0805" H 5500 2650 60  0001 C CNN
	1    5500 2650
	1    0    0    -1  
$EndComp
$Comp
L SI8441 U16
U 1 1 4EABF319
P 4500 3650
F 0 "U16" H 4300 4050 60  0000 C CNN
F 1 "SI8441" H 4400 3050 60  0000 C CNN
F 2 "SO16E" H 4500 3650 60  0001 C CNN
F 4 "336-1762-5-ND" H 4500 3650 60  0001 C CNN "Digikey"
	1    4500 3650
	1    0    0    -1  
$EndComp
Text HLabel 3350 2300 0    60   Input ~ 0
5V
Text HLabel 3700 4450 0    60   Input ~ 0
GND
Text HLabel 3650 3800 0    60   Input ~ 0
SCL
Text HLabel 3650 3700 0    60   Input ~ 0
SDI
Text HLabel 3650 3600 0    60   Input ~ 0
CS
Text HLabel 3650 3900 0    60   Output ~ 0
SDO
$Comp
L 3.3V_REGULATOR U14
U 1 1 4EABCA04
P 4650 2400
F 0 "U14" H 4450 2200 60  0000 C CNN
F 1 "3.3V_REGULATOR" H 4700 2650 60  0000 C CNN
F 2 "SOT23-5" H 4350 2550 60  0001 C CNN
F 4 "TC1014-3.3VCT713CT-ND" H 4650 2400 60  0001 C CNN "Digikey"
	1    4650 2400
	1    0    0    -1  
$EndComp
$Comp
L ADXL345BOARD U15
U 1 1 4EABC9F0
P 6350 3300
F 0 "U15" H 6400 2650 60  0000 C CNN
F 1 "ADXL345BOARD" H 6600 3650 60  0000 C CNN
F 2 "ADXL345Breakout" H 6600 2550 60  0001 C CNN
F 4 "Sparkfun" H 6350 3300 60  0001 C CNN "Digikey"
	1    6350 3300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
