#include "Adafruit_TinyUSB.h"
#include "report.h"

// USB HID object. For ESP32 these values cannot be changed after this declaration
// desc report, desc len, protocol, interval, use out endpoint
Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_NONE, 2, true);

// the setup function runs once when you press reset or power the board
void setup()
{
#if defined(ARDUINO_ARCH_MBED) && defined(ARDUINO_ARCH_RP2040)
  // Manual begin() is required on core without built-in support for TinyUSB such as mbed rp2040
  TinyUSB_Device_Init(0);
#endif
  TinyUSBDevice.setSerialDescriptor("OK"); //设定USB设备序列号
  TinyUSBDevice.setID(0x1973,0x2001); //设定USB设备vid，pid
  TinyUSBDevice.setProductDescriptor("ZhouSensor YubiDeck"); //设定USB设备产品名
  TinyUSBDevice.setManufacturerDescriptor("ZHOUSENSOR I/O SYSTEM"); //设定USB设备制造商名
  usb_hid.setPollInterval(1); //设定hid报文间隔为1ms，即最大1000hz回报率
  usb_hid.setReportCallback(get_report_callback, set_report_callback); //当电脑向手台发送数据时会调用set_report_callback进行处理
  usb_hid.begin();
  while (!TinyUSBDevice.mounted()) delay(1);  //如果没插入则等待 wait till plugged
  while (!usb_hid.ready()) delay(1);
}

struct inputdata data_tx;
struct usb_output_data_1 data_rx_1;
struct usb_output_data_2 data_rx_2;

void loop()
{
  data_tx.IRValue = 0x3f; //低6bits为红外传感器数据
  data_tx.Buttons = 0x04; //低3bits为三个功能键
  for (int i = 0; i < 32; i ++)
  {
    data_tx.TouchValue[i] = 3; //32个分区的触摸数值
  }
  data_tx.CardStatue = 0; //读卡器卡片状态，0：无卡，1：aime，2：Felica
  for (int i = 0; i < 10; i ++)
  {
    data_tx.CardID[i] = 0; //卡片ID，aime：10字节数据，Felica：8字节数据 + 2字节留空
  }

  usb_hid.sendReport(0, &data_tx, sizeof(data_tx));

  //LED.setpixelcolor(data_rx_1.TouchArea, sizeof(TouchArea)); 对data_rx_1和data_rx_2的数据进行处理等

}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t get_report_callback (uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
  // not used in this example
  (void) report_id;
  (void) report_type;
  (void) buffer;
  (void) reqlen;
  return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
// 当接受到数据时会触发中断, 自动运行这个函数
void set_report_callback(uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
  // This example doesn't use multiple report and report ID
  (void) report_id;
  (void) report_type;

  //buffer即为从电脑收到的数据，首先判断第1byte的数值，来选择解析为data_rx_1还是data_rx_2 (see definition in report.h)
  if (buffer[0] == 0)
  {
    memcpy(&data_rx_1, buffer, bufsize);
  }
  else
  {
    memcpy(&data_rx_2, buffer, bufsize);
  }
}