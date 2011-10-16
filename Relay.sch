EESchema Schematic File Version 2  date 10/16/2011 12:53:16 AM
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
LIBS:PNP
LIBS:MiataPNP-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 2 8
Title "noname.sch"
Date "16 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3700 1950 3250 1950
Wire Wire Line
	3250 2500 3250 2800
Wire Wire Line
	2800 2300 2950 2300
Wire Wire Line
	2100 2300 2300 2300
Wire Wire Line
	3250 1550 3250 1250
Wire Wire Line
	3250 1950 3250 2100
$Comp
L 2N2222A Q5
U 1 1 4E9A52AA
P 3150 2300
AR Path="/4E98F68A/4E9A52AA" Ref="Q5"  Part="1" 
AR Path="/4E98F7A4/4E9A52AA" Ref="Q3"  Part="1" 
AR Path="/4E98F795/4E9A52AA" Ref="Q4"  Part="1" 
F 0 "Q5" H 3150 2150 50  0000 R CNN
F 1 "2N2222A" H 3150 2450 50  0000 R CNN
F 2 "TO-92" H 3050 2050 60  0001 C CNN
F 4 "P2N2222AGOS-ND" H 3250 2250 60  0001 C CNN "Digikey"
	1    3150 2300
	1    0    0    -1  
$EndComp
Text HLabel 2100 2300 0    60   Input ~ 0
IN
Text HLabel 3250 1250 1    60   BiDi ~ 0
12V
Text HLabel 3250 2800 3    60   BiDi ~ 0
GND
Text HLabel 3700 1950 2    60   Output ~ 0
OUT
$Comp
L DIODE D3
U 1 1 4E98F412
P 3250 1750
AR Path="/4E98F7A4/4E98F412" Ref="D3"  Part="1" 
AR Path="/4E98F795/4E98F412" Ref="D4"  Part="1" 
AR Path="/4E98F68A/4E98F412" Ref="D5"  Part="1" 
F 0 "D5" H 3250 1850 40  0000 C CNN
F 1 "1N4002" H 3250 1650 40  0000 C CNN
F 2 "D4" H 3250 1750 60  0001 C CNN
F 4 "1N4002FSCT-ND" H 3250 1750 60  0001 C CNN "Digikey"
	1    3250 1750
	0    -1   -1   0   
$EndComp
$Comp
L R R11
U 1 1 4E98F3FA
P 2550 2300
AR Path="/4E98F7A4/4E98F3FA" Ref="R11"  Part="1" 
AR Path="/4E98F795/4E98F3FA" Ref="R12"  Part="1" 
AR Path="/4E98F68A/4E98F3FA" Ref="R13"  Part="1" 
F 0 "R13" V 2630 2300 50  0000 C CNN
F 1 "1K" V 2550 2300 50  0000 C CNN
F 2 "R4" H 2550 2300 60  0001 C CNN
	1    2550 2300
	0    1    1    0   
$EndComp
$EndSCHEMATC
