This is a sequencer for microwave transverters using an Arduino Mega 2560.  
Originally targeted for the SDR-1000, but now starting support for the 
FlexWire interface found on the Flex-3000 and probably the 5000 and maybe
even the 6300.

Uses a PCA9555 to speak I2C to the SDR-3000 because I was unsuccessful
in having the Wire library not hang the SDR.  The PCA9555 at address
0x26 works just fine.  The 16 output pins of the PCA9555 are connected to
16 input pins on the Mega2560.

LCD display of band output and ... other stuff I guess.

Sun Jun 28 21:28:39 CDT 2020

As of this moment the Flex-3000 doesn't change bands when the arduino
Mega is connected.  Need to check my wiring I guess.

Fri Jul  3 23:41:08 CDT 2020

Using PCA9555 for I2C decoding.  The Arduino Wire library just hangs the
SDR, I don't know why.  Now able to decode the UCB output for the bands
on the LCD display.

Next steps:

Make the LCD character handling less dumb

Figure out on paper what needs to happen when bands are switched with any
RF relays, etc.  Can I get away with crummy relays at the IF frequencies?
I have plenty of output power and the transverter output is probably 
plenty hot.

Figure out a case

Figure out PTT handling -- guessing that PTT via the transverter is safest.

