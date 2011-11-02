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
Sheet 7 11
Title "noname.sch"
Date "2 nov 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 4750 3000
Wire Wire Line
	3900 3000 4950 3000
Wire Wire Line
	4450 4100 4700 4100
Connection ~ 4450 4500
Wire Wire Line
	3550 4500 6050 4500
Wire Wire Line
	4550 3200 4950 3200
Wire Wire Line
	3550 4500 3550 3500
Wire Wire Line
	3550 3500 4950 3500
Connection ~ 2900 3300
Wire Wire Line
	4950 3300 2900 3300
Wire Wire Line
	6050 4500 6050 2500
Wire Wire Line
	6050 2500 4750 2500
Connection ~ 2900 2700
Wire Wire Line
	2750 2700 2900 2700
Wire Wire Line
	2900 3300 2900 3550
Wire Wire Line
	3200 3100 4950 3100
Wire Wire Line
	4700 4100 4700 3700
Wire Wire Line
	4700 3700 4950 3700
Wire Wire Line
	4950 3600 3950 3600
Connection ~ 4450 3600
Wire Wire Line
	2900 4350 2900 4050
Wire Wire Line
	2350 2700 2100 2700
Wire Wire Line
	4950 3400 3150 3400
Wire Wire Line
	3150 3400 3150 4150
Wire Wire Line
	3150 4150 2900 4150
Connection ~ 2900 4150
Wire Wire Line
	2900 2900 2900 2400
Wire Wire Line
	3950 3100 3950 3200
Connection ~ 3950 3100
Wire Wire Line
	3950 3200 4150 3200
Wire Wire Line
	4450 4500 4450 4700
$Comp
L BYPASS C4
U 1 1 4E9A5D38
P 4450 4300
AR Path="/4EA86E88/4E9A5D38" Ref="C4"  Part="1" 
AR Path="/4EA86E87/4E9A5D38" Ref="C6"  Part="1" 
AR Path="/4EA86E5C/4E9A5D38" Ref="C8"  Part="1" 
AR Path="/4EA86CCC/4E9A5D38" Ref="C10"  Part="1" 
F 0 "C8" H 4460 4380 50  0000 L CNN
F 1 "0.1uF" V 4400 4170 50  0000 L CNN
F 2 "C2" H 4300 4600 60  0001 C CNN
F 4 "PH" H 4600 4500 60  0001 C CNN "Digikey"
	1    4450 4300
	1    0    0    -1  
$EndComp
$Comp
L BYPASS C3
U 1 1 4E9A5D30
P 4350 3200
AR Path="/4EA86E88/4E9A5D30" Ref="C3"  Part="1" 
AR Path="/4EA86E87/4E9A5D30" Ref="C5"  Part="1" 
AR Path="/4EA86E5C/4E9A5D30" Ref="C7"  Part="1" 
AR Path="/4EA86CCC/4E9A5D30" Ref="C9"  Part="1" 
F 0 "C7" H 4360 3280 50  0000 L CNN
F 1 "0.1uF" V 4300 3070 50  0000 L CNN
F 2 "C2" H 4200 3500 60  0001 C CNN
F 4 "PH" H 4500 3400 60  0001 C CNN "Digikey"
	1    4350 3200
	0    1    1    0   
$EndComp
$Comp
L LM1949 U5
U 1 1 4E9A56EF
P 5550 3400
AR Path="/4EA86E88/4E9A56EF" Ref="U5"  Part="1" 
AR Path="/4EA86E87/4E9A56EF" Ref="U6"  Part="1" 
AR Path="/4EA86E5C/4E9A56EF" Ref="U7"  Part="1" 
AR Path="/4EA86CCC/4E9A56EF" Ref="U8"  Part="1" 
F 0 "U7" H 5350 3900 60  0000 C CNN
F 1 "LM1949" H 5450 3000 60  0000 C CNN
F 2 "DIP-8__300" H 5400 4100 60  0001 C CNN
F 4 "PH" H 5450 4000 60  0001 C CNN "Digikey"
	1    5550 3400
	1    0    0    -1  
$EndComp
$Comp
L TIP121 Q2
U 1 1 4E9A5680
P 3000 3100
AR Path="/4EA86E88/4E9A5680" Ref="Q2"  Part="1" 
AR Path="/4EA86E87/4E9A5680" Ref="Q3"  Part="1" 
AR Path="/4EA86E5C/4E9A5680" Ref="Q4"  Part="1" 
AR Path="/4EA86CCC/4E9A5680" Ref="Q5"  Part="1" 
F 0 "Q4" H 3000 2950 50  0000 R CNN
F 1 "TIP121" H 3000 3250 50  0000 R CNN
F 2 "TO220-123" H 2900 2850 60  0001 C CNN
F 4 "PH" H 3100 3050 60  0001 C CNN "Digikey"
	1    3000 3100
	-1   0    0    -1  
$EndComp
Text HLabel 2900 4350 3    60   Input ~ 0
INJGND
Text HLabel 2900 2400 1    60   Input ~ 0
INJ
Text HLabel 2100 2700 0    60   Input ~ 0
FB
$Comp
L DIODE D8
U 1 1 4E98D486
P 2550 2700
AR Path="/4EA86E88/4E98D486" Ref="D8"  Part="1" 
AR Path="/4EA86E87/4E98D486" Ref="D9"  Part="1" 
AR Path="/4EA86E5C/4E98D486" Ref="D10"  Part="1" 
AR Path="/4EA86CCC/4E98D486" Ref="D11"  Part="1" 
F 0 "D10" H 2550 2800 40  0000 C CNN
F 1 "FR302" H 2550 2600 40  0000 C CNN
F 2 "D4" H 2550 2700 60  0001 C CNN
F 4 "PH" H 2550 2700 60  0001 C CNN "Digikey"
	1    2550 2700
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 4E98D43F
P 2900 3800
AR Path="/4EA86E88/4E98D43F" Ref="R5"  Part="1" 
AR Path="/4EA86E87/4E98D43F" Ref="R8"  Part="1" 
AR Path="/4EA86E5C/4E98D43F" Ref="R11"  Part="1" 
AR Path="/4EA86CCC/4E98D43F" Ref="R14"  Part="1" 
F 0 "R11" V 2980 3800 50  0000 C CNN
F 1 "0.1" V 2900 3800 50  0000 C CNN
F 2 "R6" H 2900 3800 60  0001 C CNN
F 4 "PH" V 2900 3800 60  0001 C CNN "Digikey"
	1    2900 3800
	1    0    0    -1  
$EndComp
Text HLabel 4450 4700 3    60   Input ~ 0
GND
$Comp
L R R6
U 1 1 4E98D2AF
P 4450 3850
AR Path="/4EA86E88/4E98D2AF" Ref="R6"  Part="1" 
AR Path="/4EA86E87/4E98D2AF" Ref="R9"  Part="1" 
AR Path="/4EA86E5C/4E98D2AF" Ref="R12"  Part="1" 
AR Path="/4EA86CCC/4E98D2AF" Ref="R15"  Part="1" 
F 0 "R12" V 4530 3850 50  0000 C CNN
F 1 "39K" V 4450 3850 50  0000 C CNN
F 2 "R4" H 4450 3850 60  0001 C CNN
F 4 "PH" V 4450 3850 60  0001 C CNN "Digikey"
	1    4450 3850
	1    0    0    -1  
$EndComp
Text HLabel 3950 3600 0    60   Input ~ 0
VCC
Text HLabel 3900 3000 0    60   Input ~ 0
IN
$Comp
L R R7
U 1 1 4E98CF40
P 4750 2750
AR Path="/4EA86E88/4E98CF40" Ref="R7"  Part="1" 
AR Path="/4EA86E87/4E98CF40" Ref="R10"  Part="1" 
AR Path="/4EA86E5C/4E98CF40" Ref="R13"  Part="1" 
AR Path="/4EA86CCC/4E98CF40" Ref="R16"  Part="1" 
F 0 "R13" V 4830 2750 50  0000 C CNN
F 1 "100K" V 4750 2750 50  0000 C CNN
F 2 "R4" H 4750 2750 60  0001 C CNN
F 4 "PH" V 4750 2750 60  0001 C CNN "Digikey"
	1    4750 2750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
