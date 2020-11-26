// pin definitions for the SDR sequencer

#ifndef _PINDEFS_H_
#define _PINDEFS_H_
#include <stdint.h>

//SDR1000 control pins
//for legacy reference
#define CONTROL1 53
#define CONTROL2 51
#define CONTROL3 49
#define CONTROL4 47
#define CONTROL5 45
#define CONTROL6 43
#define PTT_ACTIVE 41

//RF relay control pins
//1-4 are 28MHz
//5-8 are 144MHz
//1B/2B are 144LO and 432LO internal transverters
#define RF1A	23
#define RF2A	25
#define RF3A	27
#define RF4A	29
#define RF5A	31
#define RF6A	33
#define RF7A	35
#define RF8A	37
#define RF1B    66
#define RF2B    65

//microphone PTT pin
#define PTT_MIC 69  //A15 is 69
#define SDR_PTT_OUT  53


//right-hand side PTT relays
#define XV_EN   39
#define PTT_MAIN  41
#define F144MHZ   43
#define F222MHZ  45
#define F432MHZ  47
#define F902MHZ  49
#define F1296MHZ  51
#define F2304MHZ  67
#define F3456MHZ  55


//12V relay control pins
#define DC12RY1	39
#define DC12RY2	41
#define DC12RY3	43
#define DC12RY4	45
#define DC12RY5	47
#define DC12RY6	49
#define DC12RY7	51
#define DC12RY8	53
#define DC5RY1 68  
#define DC5RY2 67 


//PCA9555 pins
#define IO0_0	36
#define IO0_1	34
#define IO0_2	32
#define IO0_3	30
#define IO0_4	28
#define IO0_5	26	
#define IO0_6	24
#define IO0_7	22

#define IO1_0	52
#define IO1_1	50
#define IO1_2	48
#define IO1_3	46
#define IO1_4	44
#define IO1_5	42
#define IO1_6	40
#define IO1_7	38

uint8_t PCA9555_pins = 8;
uint8_t PCA9555_pins_0[] = {IO0_0, IO0_1, IO0_2, IO0_3, IO0_4, IO0_5, IO0_6, IO0_7};
uint8_t PCA9555_pins_1[] = {IO1_0, IO1_1, IO1_2, IO1_3, IO1_4, IO1_5, IO1_6, IO1_7};

#endif
