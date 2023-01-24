// Master board, handles input and output, delegates control of overflow fingers to slave board.

/*

BOARD INFO || INTERFACE INFORMATION

SERIAL PORT: COM?

*/

#include<Servo.h>
#include<Wire.h>

//Constant variables init
const String fingers[5] = {
  "thumb",
  "index",
  "middle",
  "ring",
  "pinky"      
};
const int slaveAdress = 9;
const int guiBaud = 9600;

//Variable init

//Struct init
struct FingerServo {
  int potpin;
  int pos;

};

struct SlaveCommand {
  String action;
  int address;

};


void setup() {
  
  Serial.begin(guiBaud);

  

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
