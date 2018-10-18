/*
Author: Haley Fogelson
Date: Jan 25, 2018
Class: Robotics


*/

#define FLEX_PIN A0
#define VCC 4.98
#define R_DIV 47500
#define STRAIGHT_RESISTANCE  37300.0 
#define BEND_RESISTANCE  90000.0

void setup() {
  Serial.begin(115200);
  pinMode(FLEX_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Read the ADC, and calculate voltage and resistance from it
  Serial.println(analogRead(FLEX_PIN));
 /* int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);
  Serial.println("Resistance: " + String(flexR) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();
*/
  delay(500);

}
