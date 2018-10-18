// This code makes a robot go straight by adjusting the power of the left and right motor based of the values the incoders counting wheel rotations get

#include <CalibratedDrive.h>

#define RPWR 5
#define RDIR 4
#define LPWR 6
#define LDIR 7
#define r 2
#define l 0
#define lIncoder 3
#define rIncoder 8
int loopTime = 0;
int countLeft;
int countRight;
int countRight2;
int countLeft2;
int lastR;
int lastL;
int rightPower = 255;
int leftPower = 255;
void setup() {
  // put your setup code here, to run once:
  lastR = 0;
  lastL = 0;
  pinMode(RPWR, OUTPUT);
  pinMode(LPWR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(115200);

}

void loop() {
  loopTime++;
  int currentR = digitalRead(rIncoder);
  int currentL = digitalRead(lIncoder);
  if (lastL == 0 && currentL == 1) {
    countLeft ++;
    countLeft2;
  }
  lastL = currentL;


  if (lastR == 0 && currentR == 1) {
    countRight ++;
    countRight2 ++;
  }
  lastR = currentR;

if(countRight2> countLeft2){
  digitalWrite(2,HIGH);
  digitalWrite(12,LOW);
}
if(countLeft2 > countRight2){
  digitalWrite(2,LOW);
  digitalWrite(12,HIGH);
}

leftPower += (countLeft - countRight)*50;
rightPower+=(countRight-countLeft)* 50;
if(countRight%10==0)
 
 

  //if (countRight % 10 == 0) {
   
  // while(countRight-countLeft < 0)
      //countLeft%countRight/10
   
  }
//  
//    if (countRight - 1  > countLeft) {
//      rightPower -= 2;
//      countRight = 0;
//      countLeft = 0;
//
//    }
//    if (countLeft - 1 > countRight) {
//      leftPower -= 2;
//      countRight = 0;
//      countLeft = 0;
//    }
//
  

  Serial.print("left");
  Serial.print( leftPower);
  Serial.print("right");
  Serial.println(rightPower);
  digitalWrite(LDIR, HIGH);
  analogWrite(LPWR, leftPower);
  digitalWrite(RDIR, HIGH);
  analogWrite(RPWR, rightPower);

  delay(20);

}
