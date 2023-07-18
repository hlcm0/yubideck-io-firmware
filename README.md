# yubideck-io-firmware
rp2040 firmware for using yubideck io

## How to use:
### for rp2040
1.Install Arduino IDE<br>
2.Install Arduino-Pico core follow instructions in https://arduino-pico.readthedocs.io/en/latest/install.html (Important: install v2.6.4)<br>
3.Open Arduino IDE and select board:Raspberry Pi Pico in Tools -> Board<br>
4.Select Adafruit_TinyUSB in Tools -> USBStack<br>
5.Push and hold the BOOTSEL button on the Pico, then connect to your computer using a micro USB cable. Release BOOTSEL once the drive RPI-RP2 appears on your computer.<br>
6.Select UF2 Board in Tools -> Port<br>
7.Upload the code<br>

### for other MCUs
should be similar on other MCUs that support TinyUSB<br>
