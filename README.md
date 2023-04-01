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

### for samd21
1.Install Arduino IDE<br>
2.Install Arduino SAMD boards from board manager(Important: install v1.8.9 because some issues mentioned in https://github.com/NicoHood/HID/issues/411)<br>
3.Install HID-project library<br>
4.Download boards.txt from yubideck-io-firmware/code/samd21_yubideck_emu/ and put it in C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\hardware\samd\1.8.9<br>
5.Open Arduino IDE and select board:Arduino Zero (Native USB Port) in Tools -> Board<br>
6.Select upload port for your samd21<br>
7.Upload the code<br>

## What's inside the boards.txt:

1.Changing the VID and PID of the Raspberry Pi Pico to 0x1973 and 0x2001 to make it the same as Yubideck controller.(So that the IO would recognize the pico as a Yubideck)<br>
2.Changing the Manufacture name to "ZHOUSENSOR I/O SYSTEM" and changing the product name to "ZhouSensor YubiDeck" (Necessary in testtools, but maybe not important during actual playing? )<br>


## TODO:
migrate the code to SAMD21(Completed)
