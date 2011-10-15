EESchema Schematic File Version 2  date 10/14/2011 9:55:46 PM
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
Sheet 5 8
Title "noname.sch"
Date "15 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 4450 4500
Wire Wire Line
	3550 4500 6050 4500
Wire Wire Line
	3550 4500 3550 3500
Wire Wire Line
	3550 3500 4950 3500
Connection ~ 2750 3350
Wire Wire Line
	2750 3350 4450 3350
Wire Wire Line
	4450 3350 4450 3300
Wire Wire Line
	4450 3300 4950 3300
Wire Wire Line
	6050 4500 6050 2500
Wire Wire Line
	6050 2500 4750 2500
Wire Wire Line
	4950 3200 4550 3200
Connection ~ 2850 2700
Wire Wire Line
	2750 2700 2850 2700
Wire Wire Line
	2750 3300 2750 3550
Wire Wire Line
	4950 3100 3250 3100
Wire Wire Line
	4450 4100 4700 4100
Wire Wire Line
	4700 4100 4700 3700
Wire Wire Line
	4700 3700 4950 3700
Wire Wire Line
	3950 3600 4950 3600
Wire Wire Line
	4200 3000 4950 3000
Connection ~ 4200 3000
Connection ~ 4450 3600
Wire Wire Line
	2850 2400 2850 2900
Wire Wire Line
	2750 4050 2750 4350
Wire Wire Line
	2350 2700 2100 2700
Wire Wire Line
	4150 3200 3950 3200
Wire Wire Line
	3950 3200 3950 3100
Connection ~ 3950 3100
Wire Wire Line
	4450 4500 4450 4700
Wire Wire Line
	4950 3400 2900 3400
Wire Wire Line
	2900 3400 2900 4150
Wire Wire Line
	2900 4150 2750 4150
Connection ~ 2750 4150
$Comp
L C C?
U 1 1 4E98D54E
P 4350 3200
AR Path="/4E98ECA0/4E98D54E" Ref="C?"  Part="1" 
AR Path="/4E98EC9F/4E98D54E" Ref="C?"  Part="1" 
AR Path="/4E98EC15/4E98D54E" Ref="C?"  Part="1" 
AR Path="/4E98DA01/4E98D54E" Ref="C?"  Part="1" 
F 0 "C?" H 4400 3300 50  0000 L CNN
F 1 "0.1uF" H 4400 3100 50  0000 L CNN
	1    4350 3200
	0    -1   -1   0   
$EndComp
Text HLabel 2750 4350 3    60   Input ~ 0
INJGND
Text HLabel 2850 2400 1    60   Input ~ 0
INJ
Text HLabel 2100 2700 0    60   Input ~ 0
FB
$Comp
L DIODE D?
U 1 1 4E98D486
P 2550 2700
AR Path="/4E98ECA0/4E98D486" Ref="D?"  Part="1" 
AR Path="/4E98EC9F/4E98D486" Ref="D?"  Part="1" 
AR Path="/4E98EC15/4E98D486" Ref="D?"  Part="1" 
AR Path="/4E98DA01/4E98D486" Ref="D?"  Part="1" 
F 0 "D?" H 2550 2800 40  0000 C CNN
F 1 "FR302" H 2550 2600 40  0000 C CNN
	1    2550 2700
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 4E98D43F
P 2750 3800
AR Path="/4E98ECA0/4E98D43F" Ref="R?"  Part="1" 
AR Path="/4E98EC9F/4E98D43F" Ref="R?"  Part="1" 
AR Path="/4E98EC15/4E98D43F" Ref="R?"  Part="1" 
AR Path="/4E98DA01/4E98D43F" Ref="R?"  Part="1" 
F 0 "R?" V 2830 3800 50  0000 C CNN
F 1 "0.1" V 2750 3800 50  0000 C CNN
	1    2750 3800
	1    0    0    -1  
$EndComp
$Comp
L DARL_N Q?
U 1 1 4E98D3EC
P 3000 3150
AR Path="/4E98ECA0/4E98D3EC" Ref="Q?"  Part="1" 
AR Path="/4E98EC9F/4E98D3EC" Ref="Q?"  Part="1" 
AR Path="/4E98EC15/4E98D3EC" Ref="Q?"  Part="1" 
AR Path="/4E98DA01/4E98D3EC" Ref="Q?"  Part="1" 
F 0 "Q?" H 3000 3400 50  0000 C CNN
F 1 "TIP121" H 2800 3050 50  0000 C CNN
	1    3000 3150
	-1   0    0    -1  
$EndComp
Text HLabel 4450 4700 3    60   Input ~ 0
GND
$Comp
L C C?
U 1 1 4E98D2E0
P 4450 4300
AR Path="/4E98ECA0/4E98D2E0" Ref="C?"  Part="1" 
AR Path="/4E98EC9F/4E98D2E0" Ref="C?"  Part="1" 
AR Path="/4E98EC15/4E98D2E0" Ref="C?"  Part="1" 
AR Path="/4E98DA01/4E98D2E0" Ref="C?"  Part="1" 
F 0 "C?" H 4500 4400 50  0000 L CNN
F 1 "0.1uF" H 4500 4200 50  0000 L CNN
	1    4450 4300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4E98D2AF
P 4450 3850
AR Path="/4E98ECA0/4E98D2AF" Ref="R?"  Part="1" 
AR Path="/4E98EC9F/4E98D2AF" Ref="R?"  Part="1" 
AR Path="/4E98EC15/4E98D2AF" Ref="R?"  Part="1" 
AR Path="/4E98DA01/4E98D2AF" Ref="R?"  Part="1" 
F 0 "R?" V 4530 3850 50  0000 C CNN
F 1 "39K" V 4450 3850 50  0000 C CNN
	1    4450 3850
	1    0    0    -1  
$EndComp
Text HLabel 3950 3600 0    60   Input ~ 0
VCC
Text HLabel 4200 3000 0    60   Input ~ 0
IN
$Comp
L R R?
U 1 1 4E98CF40
P 4750 2750
AR Path="/4E98ECA0/4E98CF40" Ref="R?"  Part="1" 
AR Path="/4E98EC9F/4E98CF40" Ref="R?"  Part="1" 
AR Path="/4E98EC15/4E98CF40" Ref="R?"  Part="1" 
AR Path="/4E98DA01/4E98CF40" Ref="R?"  Part="1" 
F 0 "R?" V 4830 2750 50  0000 C CNN
F 1 "100K" V 4750 2750 50  0000 C CNN
	1    4750 2750
	1    0    0    -1  
$EndComp
$Comp
L LM1949 U?
U 1 1 4E98CC2B
P 5550 3400
AR Path="/4E98ECA0/4E98CC2B" Ref="U?"  Part="1" 
AR Path="/4E98EC9F/4E98CC2B" Ref="U?"  Part="1" 
AR Path="/4E98EC15/4E98CC2B" Ref="U?"  Part="1" 
AR Path="/4E98DA01/4E98CC2B" Ref="U?"  Part="1" 
F 0 "U?" H 5350 3900 60  0000 C CNN
F 1 "LM1949" H 5450 3000 60  0000 C CNN
F 2 "PDIP8" H 5700 3900 60  0000 C CNN
	1    5550 3400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
