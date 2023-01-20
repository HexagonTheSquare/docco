// Master board, handles input and output, delegates control of overflow fingers to slave board.

#include<Servo.h>
#include<Wire.h>

//Constant variables init
const std::string fingers[5] = {
  "thumb",
  "index",
  "middle",
  "ring",
  "pinky"      
}
const int slaveAdress = 9;

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
  
  Serial.begin(9600);

  for(int x = 0; x < sizeof(fingers)-1); x++)
  {
    Serial.println("What is the pin number for {0}?", fingers[x])
    int answer = Serial.read();

    FingerServo finger = {
      answer,
      0
    };
    
  }

  /*SlaveCommand command = {
    "spapa",
    9
  };
  Serial.begin(9600);
  Serial.println(command.address);
  Wire.beginTransmission(command.address);
  Wire.write(command.address);
  Wire.endTransmission();*/

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
