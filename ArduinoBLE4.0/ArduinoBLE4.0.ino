/*
 * @author Mehmet Top
 * 2017
 * 
 * Bluetooth LE 4.0 Server Application
 */

 /*
  * Arduino's PIN 10 (MOSI) ---> BLE TX
  * Arduino's PIN 11 (MISO) ---> BLE RX
  * 
  * Arduino Baudrate  : 115200
  * BLE Baudrate**    : 57600 
  * 
  * Default BLE NAME  : HMSoft  
  * Default Password  : 000000
  * Default Baudrate  : 9600
  * 
  *    Baud rate No. 
  *    
  *    >> AT+BAUD<param>
  * 
  *    0---------9600
  *    1---------19200
  *    2---------38400
  *    3---------57600
  *    4---------115200
  *    5---------4800
  *    6---------2400
  *    7---------1200
  *    8---------230400
  *    Default: 0(9600)
  *    
  *    **Baudrate was changed to listen serial port from computer
  * 
  */

 
#include <SoftwareSerial.h>

#define ARDUINO_PIN_MOSI          10
#define ARDUINO_PIN_MISO          11
#define ARDUINO_SERIAL_BAUDRATE   115200
#define BLUETOOTH_SERIAL_BAUDRATE 57600
//--
SoftwareSerial ChannelBLE4(ARDUINO_PIN_MOSI, ARDUINO_PIN_MISO);

void setup() {
  
  // Initialize Serial Communication Channels.
  Serial.begin(ARDUINO_SERIAL_BAUDRATE);
  ChannelBLE4.begin(BLUETOOTH_SERIAL_BAUDRATE);
  Serial.println("Ble client was started !");

}

void loop() {
  while(ChannelBLE4.available()>0){
    Serial.print(ChannelBLE4.read(), HEX);
    Serial.print(" ");
    delay(100);
  }
}
