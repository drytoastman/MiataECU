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
Sheet 9 11
Title ""
Date "2 nov 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 7450 3300
Connection ~ 4900 2900
Text Notes 7250 3600 0    60   ~ 0
Input Gain = R24/R27
Wire Wire Line
	5550 4000 5600 4000
Wire Wire Line
	4800 4000 5050 4000
Wire Wire Line
	4300 4000 4400 4000
Wire Wire Line
	4900 3700 5600 3700
Connection ~ 7450 3200
Wire Wire Line
	5250 3300 5250 3200
Wire Wire Line
	5250 3300 4900 3300
Wire Wire Line
	6950 4000 7250 4000
Wire Wire Line
	6950 3800 7250 3800
Wire Wire Line
	4650 2900 5250 2900
Wire Wire Line
	6950 3100 7050 3100
Wire Wire Line
	7050 3100 7050 2800
Wire Wire Line
	5450 3300 5450 2800
Wire Wire Line
	5450 3300 5600 3300
Wire Wire Line
	5250 3200 5600 3200
Wire Wire Line
	5600 3100 5250 3100
Wire Wire Line
	5450 2800 7650 2800
Connection ~ 7050 2800
Wire Wire Line
	8050 2800 8500 2800
Wire Wire Line
	6950 3900 7250 3900
Wire Wire Line
	5250 3100 5250 2900
Wire Wire Line
	8350 3200 8500 3200
Wire Wire Line
	6950 3200 7450 3200
Wire Wire Line
	7450 3200 7450 3300
Wire Wire Line
	5600 3800 4900 3800
Wire Wire Line
	3800 4000 3600 4000
Wire Wire Line
	5600 3900 4950 3900
Wire Wire Line
	4950 3900 4950 4000
Connection ~ 4950 4000
Text Label 8150 2800 0    60   ~ 0
GND
Text HLabel 4650 2900 0    60   Input ~ 0
5V
Text HLabel 7250 4000 2    60   Input ~ 0
SDO
Text HLabel 7250 3900 2    60   Input ~ 0
SDI
Text HLabel 7250 3800 2    60   Input ~ 0
SCLK
Text HLabel 8500 2800 2    60   Input ~ 0
GND
Text HLabel 3600 4000 0    60   Input ~ 0
Clock
Text HLabel 4900 3800 0    60   Input ~ 0
CS
Text HLabel 4900 3700 0    60   Input ~ 0
Window
$Comp
L TPIC8101 U10
U 1 1 4EACEB37
P 6300 3650
F 0 "U10" H 5950 4350 60  0000 C CNN
F 1 "TPIC8101" H 6100 3150 60  0000 C CNN
F 2 "SO20L" H 6300 3650 60  0001 C CNN
F 4 "296-24864-1-ND" H 6300 3650 60  0001 C CNN "Digikey"
	1    6300 3650
	1    0    0    -1  
$EndComp
Text Label 5250 3200 0    60   ~ 0
GND
$Comp
L R R24
U 1 1 4EACEB36
P 7200 3300
F 0 "R24" V 7280 3300 50  0000 C CNN
F 1 "TBD" V 7200 3300 50  0000 C CNN
F 2 "R4" H 7200 3300 60  0001 C CNN
	1    7200 3300
	0    1    1    0   
$EndComp
$Comp
L R R27
U 1 1 4EACEB35
P 7700 3200
F 0 "R27" V 7780 3200 50  0000 C CNN
F 1 "TBD" V 7700 3200 50  0000 C CNN
F 2 "R4" H 7700 3200 60  0001 C CNN
	1    7700 3200
	0    1    1    0   
$EndComp
$Comp
L C C19
U 1 1 4EACEB34
P 8150 3200
F 0 "C19" H 8200 3300 50  0000 L CNN
F 1 "3.3nF" H 8200 3100 50  0000 L CNN
F 2 "C2" H 8150 3200 60  0001 C CNN
	1    8150 3200
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 4EACEB33
P 5300 4000
F 0 "R23" V 5380 4000 50  0000 C CNN
F 1 "1M" V 5300 4000 50  0000 C CNN
F 2 "R4" H 5300 4000 60  0001 C CNN
	1    5300 4000
	0    1    1    0   
$EndComp
$Comp
L C C16
U 1 1 4EACEB32
P 4600 4000
F 0 "C16" H 4650 4100 50  0000 L CNN
F 1 "470pF" H 4650 3900 50  0000 L CNN
F 2 "C2" H 4600 4000 60  0001 C CNN
	1    4600 4000
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 4EACEB31
P 4050 4000
F 0 "R22" V 4130 4000 50  0000 C CNN
F 1 "1k" V 4050 4000 50  0000 C CNN
F 2 "R4" H 4050 4000 60  0001 C CNN
	1    4050 4000
	0    1    1    0   
$EndComp
Text Notes 5950 4350 0    60   ~ 0
Knock Processing
$Comp
L BYPASS C18
U 1 1 4EACEB30
P 7850 2800
F 0 "C18" H 7860 2880 50  0000 L CNN
F 1 "100nF" V 7800 2670 50  0000 L CNN
F 2 "SM0805" H 7700 3100 60  0001 C CNN
F 4 "399-4329-ND" H 8000 3000 60  0001 C CNN "Digikey"
	1    7850 2800
	0    1    1    0   
$EndComp
$Comp
L C C17
U 1 1 4EACEB2F
P 4900 3100
F 0 "C17" H 4950 3200 50  0000 L CNN
F 1 "4.7uF" H 4950 3000 50  0000 L CNN
F 2 "SM0805" H 4900 3100 60  0001 C CNN
	1    4900 3100
	1    0    0    -1  
$EndComp
Text Label 5500 3900 2    60   ~ 0
KnockXin
Text HLabel 8500 3200 2    60   Input ~ 0
KnockSensor
$EndSCHEMATC
