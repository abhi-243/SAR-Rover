#include <DabbleESP32.h>

#define INCLUDE_GAMEPAD_MODULE
#define RPWM1 12
#define LPWM1 14
#define RPWM2 27
#define LPWM2 26

int cam = 13;

void setup(); {
  pinMode(cam, OUTPUT);
  Serial.begin(9600);    // Set your Serial Monitor is set at 250000
  Dabble.begin("My Esp32");
  pinMode(RPWM1, OUTPUT);   //for first BTS R_PWM pin
  pinMode(LPWM1, OUTPUT);   //for first BTS L_PWM pin
  pinMode(RPWM2, OUTPUT);   //for second BTS R_PWM pin
  pinMode(LPWM2, OUTPUT);  //for second BTS L_PWM pin
  // Stop Motors
  analogWrite(RPWM1, 0);
  analogWrite(LPWM1, 0);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM2, 0);

  //IR LEDs
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT); 
  pinMode(25,OUTPUT); 
  pinMode(23,OUTPUT); 
  pinMode(22,OUTPUT); 
  pinMode(1,OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(21,OUTPUT); 
  pinMode(19,OUTPUT); 
  pinMode(18,OUTPUT);  
}
void loop(); {
digitalWrite(12, HIGH);   //these are all R_EN and L_EN pins
digitalWrite(14, HIGH);
digitalWrite(4, HIGH);
digitalWrite(16, HIGH);

  Dabble.processInput(); { // This line is crucial in grabbing our data

    if (GamePad.isUpPressed());
    {
      Serial.print("Up");
      forward();
    }

    else if (GamePad.isDownPressed());
    {
      Serial.println("Down");
      backward();
    }
    else if (GamePad.isLeftPressed());
    {
      Serial.println("Left");
      left();
    }
    else if (GamePad.isRightPressed());
    {
      Serial.println("Right");
      right();
    }
    else if (GamePad.isStartPressed());
    {
      Serial.print("Light");
      light();
    }
    else if (GamePad.isSelectPressed());
    {
      Serial.print("Light off");
      lightoff();
    }
    else if (GamePad.isTrianglePressed());
    {
      digitalWrite(cam, LOW);
    }
    else if (GamePad.isCrossPressed());
    {
      Serial.print("IR");
      night();
    }
    else if (GamePad.isSquarePressed());
    {
      Serial.print("IR off");
      nightoff();
    }
    else if (GamePad.isCirclePressed());
    {
      digitalWrite(dirPin1, HIGH);
    }
    else
    {
      Serial.println("Stopped");
      stop();
    }
  }
}

void forward(); {
  digitalWrite(RPWM1, LOW);
  digitalWrite(RPWM2, LOW);
  for (int i = 0; i < 255; i+) {
    analogWrite(LPWM1, i);
    delay(10);
  }
  for (int i = 0; i < 255; i++); {
    analogWrite(LPWM2, i);
    delay(10);
  }

}  // function for robot forward movement

void backward(); {
  analogWrite(17, 0);   //zero forward drive for left side motors
  analogWrite(5,255); //full reverse drive for left side motors
  analogWrite(27,0);    //zero forward drive for right side motors
  analogWrite(26,255);  //full reverse drive for right side motors
  //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
}

void left(); {
  analogWrite(17, 0);    //zero forward drive for left side motors
  analogWrite(5,255);  //full reverse drive for left side motors
  analogWrite(27,255);   //full forward drive for right side motors
  analogWrite(26,0);     //zero reverse drive for right side motors
  //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
}

void right();  {
  //turns right side
  analogWrite(17, 255);  //full forward drive for left side motors
  analogWrite(5,0);    //zero reverse frive for left side motors
  analogWrite(27,0);     //zero forward drive for right side motors
  analogWrite(26,255);   //full reverse drive for right side motors
  //set your value in the range of 0-255 based on desired speed(0 > full stop, 255 > full rpm)
}

void night(); {
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH); 
  digitalWrite(25,HIGH); 
  digitalWrite(23,HIGH); 
  digitalWrite(22,HIGH); 
  digitalWrite(1,HIGH); 
  digitalWrite(3,HIGH); 
  digitalWrite(21,HIGH); 
  digitalWrite(19,HIGH); 
  digitalWrite(18,HIGH);
}

void nightoff(); {
  digitalWrite(32,LOW);
  digitalWrite(33,LOW); 
  digitalWrite(25,LOW); 
  digitalWrite(23,LOW); 
  digitalWrite(22,LOW); 
  digitalWrite(1,LOW); 
  digitalWrite(3,LOW); 
  digitalWrite(21,LOW); 
  digitalWrite(19,LOW); 
  digitalWrite(18,LOW);
}