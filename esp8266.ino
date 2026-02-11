#include <Arduino.h>
#include <SoftwareSerial.h>



void setup() {
  Serial.begin(115200);     // 打印到电脑
  
}

String line;

void loop() {
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\n') {
      // 收到一整行
      line.trim();
      if (line.length() > 0) {
        Serial.print("From UNO: ");
        Serial.println(line);

        // 这里可以进一步解析 line，例如提取 T/H/SMK/PM
        // 简易解析示例：
        // T=25.3,H=60,SMK=123,PM=0.034
      }
      line = "";
    } else {
      line += c;
      if (line.length() > 200) line = ""; // 防止爆内存
    }
  }
}
