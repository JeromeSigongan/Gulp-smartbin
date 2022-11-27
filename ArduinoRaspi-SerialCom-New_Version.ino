 /* Example sketch to control a stepper motor with TB6600 stepper motor driver, AccelStepper library and Arduino: acceleration and deceleration. More info: https://www.makerguides.com */

// Include the AccelStepper library:
#include <AccelStepper.h>
//Include the LedControl Library:
#include <LedControl.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
String command;
#define dirPin 9
#define stepPin 12
#define motorInterfaceType 1

// Define MAX7219 dot matrix connections:
int din=11;
int cs =10;
int clk=13;
int led=4;

LedControl Ic=LedControl(din,clk,cs,led);

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
// Create a new instance of ledControl class:

void setup() {
  //Serial Communication with Raspberry Pi
  Serial.begin(9600);
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(1500);
  stepper.setAcceleration(1000);
  
  // Set your MAX7219
  Ic.shutdown(0,false); //The MAX72XX is in power-saving mode on startup
  Ic.shutdown(1,false);
  Ic.shutdown(2,false);
  Ic.shutdown(3,false);
  
  Ic.setIntensity(0,15); // Set the brightness to maximum value
  Ic.setIntensity(1,15);
  Ic.setIntensity(2,15);
  Ic.setIntensity(3,15);
  
  Ic.clearDisplay(0);
  Ic.clearDisplay(1);
  Ic.clearDisplay(2);
  Ic.clearDisplay(3);

// and clear the display

}

void loop() {

    byte arrow0[]={B11111100,B11111000,B11110000,B11100000,B11000000,B10000000,B00000000,B00000000};
    byte arrow1[]={B00111111,B00011111,B00001111,B00000111,B00000011,B00000001,B00000000,B00000000};
    byte arrow2[]={B00000000,B11000000,B11000000,B11000000,B11000000,B11000000,B11000000,B11000000};
    byte arrow3[]={B00000000,B00000011,B00000011,B00000011,B00000011,B00000011,B00000011,B00000011};

    byte normal0[]={B01000001,B10000001,B00000010,B00000010,B11100100,B00001000,B00110000,B11000000};
    byte normal1[]={B10000010,B10000001,B01000000,B01000000,B00100111,B00010000,B00001100,B00000011};
    byte normal2[]={B11000000,B00110000,B00011000,B00000100,B00110010,B00110010,B00000001,B00000001};
    byte normal3[]={B00000011,B00001100,B00011000,B00100000,B01001100,B01001100,B10000000,B10000000};

    byte smile0[]={B01000001,B10000001,B00010010,B00100010,B11000100,B00001000,B00110000,B11000000};
    byte smile1[]={B10000010,B10000001,B01001000,B01000100,B00100011,B00010000,B00001100,B00000011};
    byte smile2[]={B11000000,B00110000,B00011000,B00000100,B00110010,B01001010,B00000001,B00000001};
    byte smile3[]={B00000011,B00001100,B00011000,B00100000,B01001100,B01010010,B10000000,B10000000};

    byte frawn0[]={B01000001,B10000001,B00000010,B11000010,B00100100,B00001000,B00110000,B11000000};
    byte frawn1[]={B10000010,B10000001,B01000000,B01000011,B00100100,B00010000,B00001100,B00000011};
    byte frawn2[]={B11000000,B00110000,B00011000,B00000100,B01001010,B00110010,B00000001,B00000001};
    byte frawn3[]={B00000011,B00001100,B00011000,B00100000,B01010010,B01001100,B10000000,B10000000};

    byte heart0[]={B11111111,B11111111,B11111110,B11111110,B11111100,B11111000,B11110000,B11000000};
    byte heart1[]={B11111111,B11111111,B01111111,B01111111,B00111111,B00011111,B00001111,B00000011};
    byte heart2[]={B00000000,B00111100,B01111110,B11111110,B11111111,B11111111,B11111111,B11111111};
    byte heart3[]={B00000000,B00111100,B01111110,B01111111,B11111111,B11111111,B11111111,B11111111};

    byte five0[]={B11111110,B11111110,B00000110,B00000110,B00000110,B11111110,B11111110,B00000000};
    byte five1[]={B01111111,B01111111,B00000000,B00000000,B00000000,B01111111,B01111111,B00000000};
    byte five2[]={B00000000,B11111110,B11111110,B00000000,B00000000,B00000000,B00000000,B00000000};
    byte five3[]={B00000000,B01111111,B01111111,B01100000,B01100000,B01100000,B01100000,B01100000};

    
    byte four0[]={B11111110,B11111110,B00110000,B00110000,B00110000,B00110000,B00110000,B00000000};
    byte four1[]={B01111111,B01111111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
    byte four2[]={B00000000,B11110000,B11110000,B00110000,B00110000,B00110000,B00110000,B00110000};
    byte four3[]={B00000000,B00001111,B00011111,B00111000,B01110000,B01100000,B01100000,B01100000};

    byte three0[]={B11111110,B11111110,B00000110,B00000110,B00000110,B11111110,B11111110,B00000000};
    byte three1[]={B01111111,B01111111,B00000000,B00000000,B00000000,B01111111,B01111111,B00000000};
    byte three2[]={B00000000,B11111110,B11111110,B00000110,B00000110,B00000110,B00000110,B00000110};
    byte three3[]={B00000000,B01111111,B01111111,B00000000,B00000000,B00000000,B00000000,B00000000};

    byte two0[]={B11111110,B11111110,B00000000,B00000000,B00000000,B11111110,B11111110,B00000000};
    byte two1[]={B01111111,B01111111,B01100000,B01100000,B01100000,B01111111,B01111111,B00000000};
    byte two2[]={B00000000,B11111110,B11111110,B00000110,B00000110,B00000110,B00000110,B00000110};
    byte two3[]={B00000000,B01111111,B01111111,B00000000,B00000000,B00000000,B00000000,B00000000};

    byte one0[]={B11100000,B11100000,B11100000,B11100000,B11100000,B11111110,B11111110,B00000000};
    byte one1[]={B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,B01111111,B00000000};
    byte one2[]={B00000000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000,B11100000};
    byte one3[]={B00000000,B01111111,B01111111,B01111111,B00000000,B00000000,B00000000,B00000000};
  
   if (Serial.available() > 0)
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("CW")){
      
    printByte0(smile0);
    printByte1(smile1);
    printByte2(smile2);
    printByte3(smile3);
    
    // Set the target position:
    stepper.moveTo(6000);
    // Run to target position with set speed and acceleration/deceleration:
    stepper.runToPosition();
    }if (command.equals("default")){

    printByte0(smile0);
    printByte1(smile1);
    printByte2(smile2);
    printByte3(smile3);
    
    //Move back to zero:
    stepper.moveTo(0);
    // Run to target position with set speed and acceleration/deceleration:
    stepper.runToPosition();
    }if (command.equals("CCW")){
      
    printByte0(smile0);
    printByte1(smile1);
    printByte2(smile2);
    printByte3(smile3);
    
     // Set the target position:
    stepper.moveTo(-6000);
    // Run to target position with set speed and acceleration/deceleration:
    stepper.runToPosition();    
    }if (command.equals("arrow")){
      
    printByte0(arrow0);
    printByte1(arrow1);
    printByte2(arrow2);
    printByte3(arrow3);
         
    }if (command.equals("normal")){
      
    printByte0(normal0);
    printByte1(normal1);
    printByte2(normal2);
    printByte3(normal3);
       
    }if (command.equals("smile")){      
      
    printByte0(smile0);
    printByte1(smile1);
    printByte2(smile2);
    printByte3(smile3);
    
    }if (command.equals("frawn")){      
      
    printByte0(frawn0);
    printByte1(frawn1);
    printByte2(frawn2);
    printByte3(frawn3);
    
    }if (command.equals("heart")){      
      
    printByte0(heart0);
    printByte1(heart1);
    printByte2(heart2);
    printByte3(heart3);
    
    }if (command.equals("five")){      
      
    printByte0(five0);
    printByte1(five1);
    printByte2(five2);
    printByte3(five3);
    
    }if (command.equals("four")){      
      
    printByte0(four0);
    printByte1(four1);
    printByte2(four2);
    printByte3(four3);
    
    }if (command.equals("three")){      
      
    printByte0(three0);
    printByte1(three1);
    printByte2(three2);
    printByte3(three3);
    
    }if (command.equals("two")){      
      
    printByte0(two0);
    printByte1(two1);
    printByte2(two2);
    printByte3(two3);
    
    }if (command.equals("one")){      
      
    printByte0(one0);
    printByte1(one1);
    printByte2(one2);
    printByte3(one3);
    
    }
}
void printByte0(byte character []){
int i = 0;
for(i=0;i<8;i++){
  Ic.setRow(0,i,character[i]);
}
}

void printByte1 (byte character []) {
int i = 0;
for(i=0;i<8;i++){ 
  Ic.setRow(1,i,character[i]);
}
}

void printByte2(byte character []){
int i = 0;
for(i=0;i<8;i++)
{
  Ic.setRow(2,i,character[i]);
}
}
void printByte3(byte character []){
int i = 0;
for(i=0;i<8;i++) {
Ic.setRow(3,i,character[i]);
}
}
