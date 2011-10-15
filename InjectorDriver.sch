EESchema Schematic File Version 2  date 10/15/2011 5:06:23 AM
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
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 6 8
Title "noname.sch"
Date "15 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2900 2900 2900 2400
Connection ~ 2900 4150
Wire Wire Line
	2900 4150 3150 4150
Wire Wire Line
	3150 4150 3150 3400
Wire Wire Line
	3150 3400 4950 3400
Wire Wire Line
	4450 4700 4450 4500
Connection ~ 3950 3100
Wire Wire Line
	3950 3100 3950 3200
Wire Wire Line
	3950 3200 4150 3200
Wire Wire Line
	2350 2700 2100 2700
Wire Wire Line
	2900 4350 2900 4050
Connection ~ 4450 3600
Connection ~ 4200 3000
Wire Wire Line
	4200 3000 4950 3000
Wire Wire Line
	4950 3600 3950 3600
Wire Wire Line
	4950 3700 4700 3700
Wire Wire Line
	4700 3700 4700 4100
Wire Wire Line
	4700 4100 4450 4100
Wire Wire Line
	3200 3100 4950 3100
Wire Wire Line
	2900 3550 2900 3300
Wire Wire Line
	2900 2700 2750 2700
Connection ~ 2900 2700
Wire Wire Line
	4950 3200 4550 3200
Wire Wire Line
	4750 2500 6050 2500
Wire Wire Line
	6050 2500 6050 4500
Wire Wire Line
	4950 3300 4450 3300
Wire Wire Line
	4450 3300 4450 3350
Wire Wire Line
	4450 3350 2900 3350
Connection ~ 2900 3350
Wire Wire Line
	4950 3500 3550 3500
Wire Wire Line
	3550 3500 3550 4500
Wire Wire Line
	3550 4500 6050 4500
Connection ~ 4450 4500
$Comp
L TIP121 Q7
U 1 1 4E99601F
P 3000 3100
AR Path="/4E98EC9F/4E99601F" Ref="Q7"  Part="1" 
AR Path="/4E98ECA0/4E99601F" Ref="Q6"  Part="1" 
AR Path="/4E98EC15/4E99601F" Ref="Q8"  Part="1" 
AR Path="/4E98DA01/4E99601F" Ref="Q9"  Part="1" 
F 0 "Q9" H 3000 2950 50  0000 R CNN
F 1 "TIP121" H 3000 3250 50  0000 R CNN
	1    3000 3100
	-1   0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 4E98D54E
P 4350 3200
AR Path="/4E98ECA0/4E98D54E" Ref="C9"  Part="1" 
AR Path="/4E98EC9F/4E98D54E" Ref="C11"  Part="1" 
AR Path="/4E98EC15/4E98D54E" Ref="C13"  Part="1" 
AR Path="/4E98DA01/4E98D54E" Ref="C15"  Part="1" 
F 0 "C15" H 4400 3300 50  0000 L CNN
F 1 "0.1uF" H 4400 3100 50  0000 L CNN
	1    4350 3200
	0    -1   -1   0   
$EndComp
Text HLabel 2900 4350 3    60   Input ~ 0
INJGND
Text HLabel 2900 2400 1    60   Input ~ 0
INJ
Text HLabel 2100 2700 0    60   Input ~ 0
FB
$Comp
L DIODE D6
U 1 1 4E98D486
P 2550 2700
AR Path="/4E98ECA0/4E98D486" Ref="D6"  Part="1" 
AR Path="/4E98EC9F/4E98D486" Ref="D7"  Part="1" 
AR Path="/4E98EC15/4E98D486" Ref="D8"  Part="1" 
AR Path="/4E98DA01/4E98D486" Ref="D9"  Part="1" 
F 0 "D9" H 2550 2800 40  0000 C CNN
F 1 "FR302" H 2550 2600 40  0000 C CNN
	1    2550 2700
	-1   0    0    1   
$EndComp
$Comp
L R R14
U 1 1 4E98D43F
P 2900 3800
AR Path="/4E98ECA0/4E98D43F" Ref="R14"  Part="1" 
AR Path="/4E98EC9F/4E98D43F" Ref="R17"  Part="1" 
AR Path="/4E98EC15/4E98D43F" Ref="R20"  Part="1" 
AR Path="/4E98DA01/4E98D43F" Ref="R23"  Part="1" 
F 0 "R23" V 2980 3800 50  0000 C CNN
F 1 "0.1" V 2900 3800 50  0000 C CNN
	1    2900 3800
	1    0    0    -1  
$EndComp
Text HLabel 4450 4700 3    60   Input ~ 0
GND
$Comp
L C C10
U 1 1 4E98D2E0
P 4450 4300
AR Path="/4E98ECA0/4E98D2E0" Ref="C10"  Part="1" 
AR Path="/4E98EC9F/4E98D2E0" Ref="C12"  Part="1" 
AR Path="/4E98EC15/4E98D2E0" Ref="C14"  Part="1" 
AR Path="/4E98DA01/4E98D2E0" Ref="C16"  Part="1" 
F 0 "C16" H 4500 4400 50  0000 L CNN
F 1 "0.1uF" H 4500 4200 50  0000 L CNN
	1    4450 4300
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 4E98D2AF
P 4450 3850
AR Path="/4E98ECA0/4E98D2AF" Ref="R15"  Part="1" 
AR Path="/4E98EC9F/4E98D2AF" Ref="R18"  Part="1" 
AR Path="/4E98EC15/4E98D2AF" Ref="R21"  Part="1" 
AR Path="/4E98DA01/4E98D2AF" Ref="R24"  Part="1" 
F 0 "R24" V 4530 3850 50  0000 C CNN
F 1 "39K" V 4450 3850 50  0000 C CNN
	1    4450 3850
	1    0    0    -1  
$EndComp
Text HLabel 3950 3600 0    60   Input ~ 0
VCC
Text HLabel 4200 3000 0    60   Input ~ 0
IN
$Comp
L R R16
U 1 1 4E98CF40
P 4750 2750
AR Path="/4E98ECA0/4E98CF40" Ref="R16"  Part="1" 
AR Path="/4E98EC9F/4E98CF40" Ref="R19"  Part="1" 
AR Path="/4E98EC15/4E98CF40" Ref="R22"  Part="1" 
AR Path="/4E98DA01/4E98CF40" Ref="R25"  Part="1" 
F 0 "R25" V 4830 2750 50  0000 C CNN
F 1 "100K" V 4750 2750 50  0000 C CNN
	1    4750 2750
	1    0    0    -1  
$EndComp
$Comp
L LM1949 U6
U 1 1 4E98CC2B
P 5550 3400
AR Path="/4E98ECA0/4E98CC2B" Ref="U6"  Part="1" 
AR Path="/4E98EC9F/4E98CC2B" Ref="U7"  Part="1" 
AR Path="/4E98EC15/4E98CC2B" Ref="U8"  Part="1" 
AR Path="/4E98DA01/4E98CC2B" Ref="U9"  Part="1" 
F 0 "U9" H 5350 3900 60  0000 C CNN
F 1 "LM1949" H 5450 3000 60  0000 C CNN
F 2 "PDIP8" H 5700 3900 60  0000 C CNN
	1    5550 3400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
