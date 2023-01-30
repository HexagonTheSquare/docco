// Master board, handles input and output, delegates control of overflow fingers to slave board.

/*

BOARD INFO || INTERFACE INFORMATION

SERIAL PORT: COM?

*/

// includes
#include<Servo.h>
#include<Wire.h>
#include "HCPCA9685.h"


// defines
#define INPUT_SIZE 30
#define DEFAULT_BAUD 9600
#define SERVO_FREQ 50
#define  I2CAdd 0x40

HCPCA9685 HCPCA9685(I2CAdd);

// structs
struct FingerServo {
  int pos;
  int servo;
} thumb1, thumb2, thumb3,
  index1, index2, index3, 
  middle1, middle2, middle3, 
  ring1, ring2, ring3, 
  pinky1, pinky2, pinky3;

struct SlaveCommand {
  String action;
  int address;

};

void updateServos() {
  if(thumb1.servo !="" && thumb2.servo !="" && thumb3.servo !="")
  {
    HCPCA9685.Servo(thumb1.servo, thumb1.pos); HCPCA9685.Servo(thumb2.servo, thumb2.pos); HCPCA9685.Servo(thumb3.servo, thumb3.pos);
  }
  if(index1.servo !="" && index2.servo !="" && index3.servo !="") {
    HCPCA9685.Servo(index1.servo, index1.pos); HCPCA9685.Servo(index2.servo, index2.pos); HCPCA9685.Servo(index3.servo, index3.pos);  
  }
  if(middle1.servo !="" && middle2.servo !="" && middle3.servo !="") {
    HCPCA9685.Servo(middle1.servo, middle1.pos); HCPCA9685.Servo(middle2.servo, middle2.pos); HCPCA9685.Servo(middle3.servo, middle3.pos);  
  }
  if(ring1.servo !="" && ring2.servo !="" && ring3.servo !="") {
    HCPCA9685.Servo(ring1.servo, ring1.pos); HCPCA9685.Servo(ring2.servo, ring2.pos); HCPCA9685.Servo(ring3.servo, ring3.pos);  
  }
  if(pinky1.servo !="" && pinky2.servo !="" && pinky3.servo !="") {
    HCPCA9685.Servo(pinky1.servo, pinky1.pos); HCPCA9685.Servo(pinky2.servo, pinky2.pos); HCPCA9685.Servo(pinky3.servo, pinky3.pos);
  }
}

void setup() {
  Serial.begin(DEFAULT_BAUD);
  HCPCA9685.Init(SERVO_MODE);
  HCPCA9685.Sleep(false);
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

    Serial.print(dataType);
    //Serial.print(values[0]);
    //Serial.print(values);
    
    switch(dataType) {
      case 'P':
      // SET FINGER POSITION
      thumb1.pos = values[0]; thumb2.pos = values[0]; thumb3.pos = values[0];
      index1.pos = values[1]; index2.pos = values[1]; index3.pos = values[1];
      middle1.pos = values[2]; middle2.pos = values[2]; middle3.pos = values[2];
      ring1.pos = values[3]; ring2.pos = values[3]; ring3.pos = values[3];
      pinky1.pos = values[4]; pinky2.pos = values[4]; pinky3.pos = values[4];

      updateServos();      
      break;
      case 'S':
      // SET SERVO PINS
      thumb1.servo=values[0]; thumb2.servo=values[1]; thumb3.servo=values[2];
      index1.servo=values[3]; index2.servo=values[4]; index3.servo=values[5];
      middle1.servo=values[6]; middle2.servo=values[7]; middle3.servo=values[8];
      ring1.servo=values[9]; ring2.servo=values[10]; ring3.servo=values[11];
      pinky1.servo=values[12]; pinky2.servo=values[13]; pinky3.servo=values[14];            
      break;
    }    
  }
  
  
  /*Serial.print(thumb1.pos); Serial.print(":"); Serial.print(thumb2.pos); Serial.print(":"); Serial.print(thumb3.pos); Serial.print(" ");
  Serial.print(index1.pos); Serial.print(":"); Serial.print(index2.pos); Serial.print(":"); Serial.print(index3.pos); Serial.print(" ");
  Serial.print(middle1.pos); Serial.print(":"); Serial.print(middle2.pos); Serial.print(":"); Serial.print(middle3.pos); Serial.print(" ");
  Serial.print(ring1.pos); Serial.print(":"); Serial.print(ring2.pos); Serial.print(":"); Serial.print(ring3.pos); Serial.print(" ");
  Serial.print(pinky1.pos); Serial.print(":"); Serial.print(pinky2.pos); Serial.print(":"); Serial.print(pinky3.pos); Serial.print(" \n");*/
}
