#include <Wire.h>

const int MPU_addr = 0x68;  // I2C address of the MPU-6050

// Arduino pin numbers
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int buzzer = 2;// pin for buzzer

int incomingByte = 0; //incoming byte from python file

int16_t GyX, GyY;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); //initialize buzzer pin as an output
  digitalWrite(buzzer, LOW);   //Start with buzzer off
}

void loop() {
  Serial.println(analogRead(X_pin));
  Serial.println(analogRead(Y_pin));
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers
  GyX = Wire.read() << 8 | Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  Serial.println(GyX);
  Serial.println(GyY);

  incomingByte = Serial.read(); //recieve and store serial information

  if(incomingByte == 'E') {
      digitalWrite(buzzer, HIGH); // Turn on buzzer
      delay(500);
    }
    incomingByte = 0; //reset incoming byte
  digitalWrite(buzzer, LOW); //turn off buzzer

  delay(333);
}