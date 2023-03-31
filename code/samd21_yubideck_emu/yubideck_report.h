struct inputdata {
  unsigned char IRValue;         //红外传感器信号，低6bits对应6个传感器
  unsigned char Buttons;         //控制器3个功能按键，低3bits对应3个按键
  unsigned char TouchValue[32];  //32个触摸数值
  unsigned char CardStatue;      //读卡器卡片状态，0：无卡，1：aime，2：Felica
  unsigned char CardID[10];      //卡片ID，aime：10字节数据，Felica：8字节数据 + 2字节留空
};

struct rgb {
  unsigned char R;
  unsigned char G;
  unsigned char B;
};

struct usb_output_data_1 {
  unsigned char Index;       //该字节要求，为0 (即, 接收到的数据如果第1byte为0, 那么就按照usb_output_data_1的结构来解析)
  struct rgb TouchArea[20];  //对应触摸区域前20个灯
};

struct usb_output_data_2 {
  unsigned char Index;       //该字节要求，为1 (即, 接收到的数据如果第1byte为1, 那么就按照usb_output_data_2的结构来解析)
  struct rgb TouchArea[11];  //对应触摸区域后11个灯
  struct rgb LeftAir;        //左侧板灯光
  struct rgb Rightair;       //右侧板灯光
  struct rgb CardReader;     //读卡器灯光
  unsigned char Empyt[18];   //填0以填充UBS规定长度
};