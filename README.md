# Camera LED Ring

<table><tr>
<td><img src="pics/camera.jpg" height=200 /></td>
<td><img src="pics/led_ring.jpg" height=200 /></td>
<td><img src="pics/led_ring3.jpg" height=200 /></td>
</tr></table>

This project is about a LED ring which can be mounted on camera lences in oder to get a proper light for close shots. 
The LED ring is based on WS2812 like [Adafruit NeoPixel](https://www.adafruit.com/category/168). 
For the controller I chose an [Arduino Nano](https://store.arduino.cc/arduino-nano). 
The power supply works via the usb connector which is on the arduino nano board. 
In addition I just plugged in a simple button which I can use for adjusting the brightness of the LED ring. 
For this project I just use the color white and all LEDs change their color at the same time.
The program is based on [platform.io](https://platformio.org/) and on the Adafruit library for NeoPixel. 
You find this simple program in [src/main.cpp](src/main.cpp).

By pushing the button the program increases the brightness until it has reached max, after that it decreases the brightness ... if you release the button it will stop and keep this configuration. 
If you power of it will always set the brightness to what is set as default value in the program.
