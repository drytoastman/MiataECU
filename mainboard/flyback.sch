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
Sheet 3 11
Title ""
Date "2 nov 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TIP42C Q1
U 1 1 4EA88072
P 5300 2850
F 0 "Q1" H 5300 2700 60  0000 R CNN
F 1 "TIP42C" H 5300 3000 60  0000 R CNN
F 2 "TO220-123" H 5200 2600 60  0001 C CNN
F 4 "PH" H 5300 2850 60  0001 C CNN "Digikey"
	1    5300 2850
	1    0    0    1   
$EndComp
Text HLabel 5150 3250 3    60   Input ~ 0
Gnd
Text HLabel 5150 2300 1    60   Input ~ 0
Flyback
$Comp
L R R4
U 1 1 4EA87EBB
P 4850 2600
F 0 "R4" H 4930 2600 50  0000 C CNN
F 1 "270" V 4850 2600 50  0000 C CNN
F 2 "R4" H 4850 2600 60  0001 C CNN
F 4 "PH" H 4850 2600 60  0001 C CNN "Digikey"
	1    4850 2600
	1    0    0    -1  
$EndComp
$Comp
L ZENER D2
U 1 1 4EA87EBA
P 4850 3050
F 0 "D2" H 4850 3150 50  0000 C CNN
F 1 "36V" H 4850 2950 40  0000 C CNN
F 2 "D4" H 4850 3050 60  0001 C CNN
F 4 "PH" H 4850 3050 60  0001 C CNN "Digikey"
	1    4850 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 3050 5400 3250
Wire Wire Line
	5400 3250 4850 3250
Wire Wire Line
	5400 2650 5400 2300
Wire Wire Line
	4850 2850 5100 2850
Wire Wire Line
	4850 2350 4850 2300
Wire Wire Line
	4850 2300 5400 2300
$EndSCHEMATC
