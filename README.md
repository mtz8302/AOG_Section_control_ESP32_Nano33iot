# AOG_Section_control

Section Control running on ESP32 or Arduino 33 iot for AgOpenGPS PC Software.

Supports: <br>- Section control, 16 sections
          <br>- hardware input switches (Main ON/OFF, OFF/Auto/ON for each section, +/- pressure (only motor driven, no rate control in V4 so far))
          <br>- documentation only (e.g. for machinery with hydraulic gates)
   <br>and most combinations of it

Settings can be changed via webinterface. The IP adress is x.x.x.71 in your WiFi network. If the log to your networks fails, you wait until an accesspoint is created. Connenct your computer to it and use your browser to get to webinterface at 192.168.1.1

The settings done directly in the code are the default values, that can be reloaded. The pin assigment must be done in the code, most other things can be changed in webinterface.

Make sure, that the SSID and password fits to your tractor's WIFI.

Works with the circuit (by WEder) based on Arduino nano, see PDF.

!!!The ESP32 and the Nano33 iot use 3.3V for any in-/outputs !!!

A suggestion for ESP32 pinout is in the PDF. Don't use pins GPIO 0, 6-12. The pins 33-39 are input only, and don't have pullup resistors.

Further remarks on the ESP32 pinout:
The circuit could be mostly the same as in WEder's schematic.

All switches use internal pullup, so switch to GND.

GPIO 39 has no internal pullup, so external resistor 10k to 3.3V and switch to GND.

Pressure(Flowrate) and Main Switch are (ON)-OFF-(ON) switches or push buttons: 3.3V - 1.15V - GND to get 1.15V use 10k to 3.3 and 10k to GND. So only 1 input for 2 functions is needed.

For the outputs use a driver like UDN2981(relais have common GND and UDN does +) or ULN2803 (relais have common + and ULN does GND) 


NO rate control in AOG V4 at the moment (not supported by AOG)
