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

// structs
struct FingerServo {
  int pos;
  Servo servo;
} thumb1, thumb2, thumb3,
  index1, index2, index3, 
  middle1, middle2, middle3, 
  ring1, ring2, ring3, 
  pinky1, pinky2, pinky3;

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
      thumb1.pos = values[0]; thumb2.pos = values[0]; thumb3.pos = values[0];
      index1.pos = values[1]; index2.pos = values[1]; index3.pos = values[1];
      middle1.pos = values[2]; middle2.pos = values[2]; middle3.pos = values[2];
      ring1.pos = values[3]; ring2.pos = values[3]; ring3.pos = values[3];
      pinky1.pos = values[4]; pinky2.pos = values[4]; pinky3.pos = values[4];
      break;
      case 'S':
      // SET SERVO PINS
      thumb1.servo.attach(values[0]); thumb2.servo.attach(values[1]); thumb3.servo.attach(values[2]);
      index1.servo.attach(values[3]); index2.servo.attach(values[4]); index3.servo.attach(values[5]);
      middle1.servo.attach(values[6]); middle2.servo.attach(values[7]); middle3.servo.attach(values[8]);
      ring1.servo.attach(values[9]); ring2.servo.attach(values[10]); ring3.servo.attach(values[11]);
      pinky1.servo.attach(values[12]); pinky2.servo.attach(values[13]); pinky3.servo.attach(values[14]);            
      break;
    }    
  }
  
  
  Serial.print(thumb1.pos); Serial.print(":"); Serial.print(thumb2.pos); Serial.print(":"); Serial.print(thumb3.pos); Serial.print(" ");
  Serial.print(index1.pos); Serial.print(":"); Serial.print(index2.pos); Serial.print(":"); Serial.print(index3.pos); Serial.print(" ");
  Serial.print(middle1.pos); Serial.print(":"); Serial.print(middle2.pos); Serial.print(":"); Serial.print(middle3.pos); Serial.print(" ");
  Serial.print(ring1.pos); Serial.print(":"); Serial.print(ring2.pos); Serial.print(":"); Serial.print(ring3.pos); Serial.print(" ");
  Serial.print(pinky1.pos); Serial.print(":"); Serial.print(pinky2.pos); Serial.print(":"); Serial.print(pinky3.pos); Serial.print(" ");
    
}
