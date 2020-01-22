#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>

SoftwareSerial IM920Serial(8, 9); //受信 RX をピン 8、送信 TX をピン 9 に割り当てます

void setup()
{
    IM920Serial.begin(19200); //ソフトウェアシリアル開始。IM920 とは 19200 ボーを指定
    
    Serial.begin(19200);    
    Wire.begin();
}

void loop()
{
    String str = "";
    str += "TXDA ";
    str += encodeAscii("12345");
    
    Serial.println(str);
    IM920Serial.println(str);
      
    delay(500);
    IM920Serial.println("ENRX");
}

String encodeAscii(String str){
  String ascii = "";
  int j=0;
  bool _dot_flag = false;
  for(int i=0; i<str.length(); i++){
    if(str.charAt(i) == '.' || _dot_flag){
      j++;
      _dot_flag = true;
    }
    ascii += asciiElement(str.charAt(i));
    if(j > 1) break;
  }
  return ascii;  
}

String asciiElement(char c){
  String s;
  if(c == ',')  s = "2c";
  if(c == '.')  s = "2e";
  if(c == '0')  s = "30";
  if(c == '1')  s = "31";
  if(c == '2')  s = "32";
  if(c == '3')  s = "33";
  if(c == '4')  s = "34";
  if(c == '5')  s = "35";
  if(c == '6')  s = "36";
  if(c == '7')  s = "37";
  if(c == '8')  s = "38";
  if(c == '9')  s = "39";

  return s;
}


