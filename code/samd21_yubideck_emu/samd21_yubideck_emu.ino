#include "HID-Project.h"
#include "yubideck_report.h"
#include "YubiHID.h"

// Buffer to hold RawHID data.
// If host tries to send more data than this,
// it will respond with an error.
// If the data is not read until the host sends the next data
// it will also respond with an error and the data will be lost.
uint8_t rawhidData[255];

void setup() {
  // Set the RawHID OUT report array.
  // Feature reports are also (parallel) possible, see the other example for this.
  YubiHID.begin(rawhidData, sizeof(rawhidData));
}

struct inputdata data_tx;
struct usb_output_data_1 data_rx_1;
struct usb_output_data_2 data_rx_2;
uint8_t rawInBuffer[61];

void loop() {
  // Send data to the host
  data_tx.IRValue = 0x3f;  //低6bits为红外传感器数据
  data_tx.Buttons = 0x04;  //低3bits为三个功能键
  for (int i = 0; i < 32; i++) {
    data_tx.TouchValue[i] = 3;  //32个分区的触摸数值
  }
  data_tx.CardStatue = 0;  //读卡器卡片状态，0：无卡，1：aime，2：Felica
  for (int i = 0; i < 10; i++) {
    data_tx.CardID[i] = 0;  //卡片ID，aime：10字节数据，Felica：8字节数据 + 2字节留空
  }
  uint8_t megabuff[45];
  memcpy(&megabuff, &data_tx, sizeof(data_tx));
  YubiHID.write(megabuff, sizeof(megabuff));


  // Check if there is new data from the RawHID device
  auto bytesAvailable = YubiHID.available();
  if (bytesAvailable) {
    YubiHID.readBytes(rawInBuffer, 61);
    if (rawInBuffer[0] == 0)
    {
      memcpy(&data_rx_1, &rawInBuffer, sizeof(rawInBuffer));
    }
    else
    {
      memcpy(&data_rx_2, &rawInBuffer, sizeof(rawInBuffer));
    }
  }

}
