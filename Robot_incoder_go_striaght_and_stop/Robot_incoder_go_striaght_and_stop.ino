#include <PinChangeInt.h>
#define RPWR 5
#define RDIR 4
#define LPWR 6
#define LDIR 7
#define r 2
#define l 0
#define lEncoder 3
#define rEncoder 8
#define maxPower 250
#define minPower 150
#define powerCenter ((maxPower + minPower)/2)
#define dp 6
int readValue;
int countRight = 0;
int countLeft = 0;
int leftPower;
int rightPower;
int rightdistance = 0;
int leftdistance = 0;

void addRCount() {
  countRight++;
  rightdistance += 2.07;
}
void addLCount() {
  countLeft++;
  leftdistance += 2.07;
}


void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  pinMode(rEncoder, INPUT);
  pinMode(lEncoder, INPUT);
  pinMode(RPWR, OUTPUT);
  pinMode(LPWR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(LDIR, OUTPUT);
  Serial.begin(115200);
  while (Serial.available() == 0);
    readValue = Serial.parseInt();
  PCintPort::attachInterrupt(rEncoder, addRCount, RISING);
  PCintPort::attachInterrupt(lEncoder, addLCount, RISING);
  leftPower = powerCenter - 15;
  rightPower = powerCenter;
  delay(5000);

  //rightPower= 205;
 // leftPower  = 165;
 

}

void loop() {
  // put your main code here, to run repeatedly:

  if (countLeft > 5 && abs(countLeft - countRight) > 2) {
    int propLeft;
    int propRight;
    
    if ( countLeft > countRight) {
      propLeft = max ( minPower, leftPower - dp );
      propRight = min(maxPower, rightPower + dp);

    }
    else {
      propLeft = min (maxPower, leftPower + dp);
      propRight = max (maxPower, rightPower - dp);
    }
    if (abs(propLeft - powerCenter) < abs(propRight - powerCenter) && leftPower - dp > minPower && rightPower + dp < maxPower)
      leftPower = propLeft;
    else
      rightPower = propRight;

  }
  if (rightdistance < readValue - 2 ) {
    digitalWrite(RDIR, HIGH);
    analogWrite(RPWR, rightPower);
  }
  else
    analogWrite(RPWR, 0);
  if (leftdistance < readValue - 2 ) {
    digitalWrite(LDIR, HIGH);
    analogWrite(LPWR, leftPower);
  }
  else
    analogWrite(LPWR, 0);

  Serial.print("right");
  Serial.print( countRight);
  Serial.print("left");
  Serial.println(countLeft);

}
