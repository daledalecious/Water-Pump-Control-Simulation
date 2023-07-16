#include <Servo.h>
Servo myServo; 

int servoPin = 9;
int servoPos = 0;

int water_lvl_sensor = A0;
int sensor_val = 0;

unsigned long previousTime = 0;
unsigned long interval = 1000; // Delay interval in milliseconds

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

myServo.attach(servoPin);

pinMode(water_lvl_sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long currentTime = millis();
sensor_val = analogRead(water_lvl_sensor);
Serial.println(sensor_val);

if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    
    
    servoPos += 90;
    if (servoPos>=180) {
      servoPos = 0;
    }

    // Set the angle of the servo
    myServo.write(servoPos);
  }

if(sensor_val>=365){
myServo.write(0);
}
}
