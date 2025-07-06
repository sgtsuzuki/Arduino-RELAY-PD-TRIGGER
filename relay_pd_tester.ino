// PDトリガーモジュールをArduinoを介したPCから制御する
// UARTでコマンドを投げると、5V,9V,12V,20Vのトリガーをかけられる
// 9600bps N81XN
// '0' = 5V
// '1' = 9V
// '2' = 12V
// '3' = 15V
// '4' = 20V
// 使用しているトリガー基板は[Youmile 2 個 USB-C PD トリガーモジュール PD/QC2.0 3.0 QC4+ デコイボード]
// https://www.amazon.co.jp/dp/B0C6KDL1D3
// ピン接続はソース参照
// FETからリレーを駆動している

const int V20_PIN = 8;
const int V15_PIN = 9;
const int V12_PIN = 10;
const int V9_PIN = 11;

void setup() {
  pinMode( V20_PIN, OUTPUT );
  pinMode( V15_PIN, OUTPUT );
  pinMode( V12_PIN, OUTPUT );
  pinMode( V9_PIN, OUTPUT );

  digitalWrite( V20_PIN, LOW );
  digitalWrite( V15_PIN, LOW );
  digitalWrite( V12_PIN, LOW );
  digitalWrite( V9_PIN, LOW );

  Serial.begin( 9600 ); 
}

// 232Cでコマンドを受け取ると
// '0' : 全てOFF ＝ 5V
// '1' : 全てOFF ＝ 9V
// '2' : 全てOFF ＝ 12V
// '3' : 全てOFF ＝ 15V
// '4' : 全てOFF ＝ 20V

void loop() {
  char key; 

  if ( Serial.available() ){
    key = Serial.read();
    // Serial.println(key); DBG
    switch(key){
      case '0':
        digitalWrite( V20_PIN, LOW );
        digitalWrite( V15_PIN, LOW );
        digitalWrite( V12_PIN, LOW );
        digitalWrite( V9_PIN, LOW );
        Serial.println("5V");
        break;
      case '1': // 9V
        digitalWrite( V20_PIN, LOW );
        digitalWrite( V15_PIN, LOW );
        digitalWrite( V12_PIN, LOW );
        digitalWrite( V9_PIN, HIGH );
        Serial.println("9V");
        break;
      case '2': // 12V
        digitalWrite( V20_PIN, LOW );
        digitalWrite( V15_PIN, LOW );
        digitalWrite( V12_PIN, HIGH );
        digitalWrite( V9_PIN, LOW );
        Serial.println("12V");
        break;
      case '3': // 15V
        digitalWrite( V20_PIN, LOW );
        digitalWrite( V15_PIN, HIGH );
        digitalWrite( V12_PIN, LOW );
        digitalWrite( V9_PIN, LOW );
        Serial.println("15V");
        break;
      case '4': // 
        digitalWrite( V20_PIN, HIGH );
        digitalWrite( V15_PIN, LOW );
        digitalWrite( V12_PIN, LOW );
        digitalWrite( V9_PIN, LOW );
        Serial.println("20V");
        break;
      }
  }
  
//  delay( 1000 );

  delay( 100 );
}