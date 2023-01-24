// Master board, handles input and output, delegates control of overflow fingers to slave board.

/*

BOARD INFO || INTERFACE INFORMATION

SERIAL PORT: COM?

*/

// includes
#include<Servo.h>
#include<Wire.h>

// defines
#define INPUT_SIZE 30
#define DEFAULT_BAUD 9600
#define SLAVE_ADRESS 9

// constants
const String fingers[5] = {
  "thumb",
  "index",
  "middle",
  "ring",
  "pinky"      
};

// structs
struct FingerServo {
  int potpin;
  int pos;
  Servo servo;
};

struct SlaveCommand {
  String action;
  int address;

};


void setup() {
  Serial.begin(DEFAULT_BAUD);
}

void loop() {
  if(Serial.available()) {
    String strData = Serial.readString();
    char dataType = strData.charAt(0);
    char data[strData.length()+1];
    strcpy(data, strData.c_str());
    int values[strData.length()-1];

    int lastIndex = 2;
    for(int x = 2; x < strData.length()-2; x++) {
      if (data[x] == " ") {
        char currentVal[x - lastIndex];
        for(int y = lastIndex; y < x; y++) {
          currentVal[y - lastIndex] = data[y];
        }
        values[x-2] = atoi(currentVal);
        lastIndex = x+1;
      }
    }

        
    switch(dataType) {
      case 'P':
      // SET FINGER POSITION
      break;
      case 'S':
      // SET SERVO PINS
      break;
    }    
  }

}
