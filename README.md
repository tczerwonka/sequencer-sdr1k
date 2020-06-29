This is a sequencer for microwave transverters using an Arduino Mega 2560.  
Originally targeted for the SDR-1000, but now starting support for the 
FlexWire interface found on the Flex-3000 and probably the 5000 and maybe
even the 6300.

Goal is to emulate an i2c target at 0x4C for the xvtr band selection.

Oh yeah, a LCD display because I have a spare one.

Sun Jun 28 21:28:39 CDT 2020

As of this moment the Flex-3000 doesn't change bands when the arduino
Mega is connected.  Need to check my wiring I guess.
