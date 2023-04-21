# yubideck-io-firmware
rp2040 and samd21 firmware for using yubideck io

## How to use:
### for rp2040
1.Install Arduino IDE<br>
2.Install Arduino-Pico core follow instructions in https://arduino-pico.readthedocs.io/en/latest/install.html (Important: install v2.6.4)<br>
3.Download boards.txt from yubideck-io-firmware/code/pico_yubideck_emu/ and put it in C:\Users\Administrator\AppData\Local\Arduino15\packages\rp2040\hardware\rp2040\2.6.4<br>
4.Open Arduino IDE and select board:Raspberry Pi Pico in Tools -> Board<br>
5.Select Adafruit_TinyUSB in Tools -> USBStack<br>
6.Push and hold the BOOTSEL button on the Pico, then connect to your computer using a micro USB cable. Release BOOTSEL once the drive RPI-RP2 appears on your computer.<br>
7.Select UF2 Board in Tools -> Port<br>
8.Upload the code<br>

### for other MCUs
should be similar on other MCUs that support TinyUSB<br>

## What's inside the boards.txt:

1.Changing the VID and PID of the Raspberry Pi Pico to 0x1973 and 0x2001 to make it the same as Yubideck controller.(So that the IO would recognize the pico as a Yubideck)<br>
2.Changing the Manufacture name to "ZHOUSENSOR I/O SYSTEM" and changing the product name to "ZhouSensor YubiDeck" (maybe not important)<br>
