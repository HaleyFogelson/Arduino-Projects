#include <PinChangeInt.h>
#define RPWR 5
#define lEncoder 3
#define rEncoder 8
#define RDIR 4
#define LPWR 6
#define LDIR 7
boolean canGoFL = true;
boolean canGoBR = true;
boolean canGoFR = true;
boolean canGoBL = true;
int countRight = 0;
int countLeft = 0;
int nmbTurns = 10;

void addRCount() {
  countRight++;
}
void addLCount() {
  countLeft++;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RPWR, OUTPUT);
  pinMode(rEncoder, INPUT);
  pinMode(lEncoder, INPUT);
  pinMode(LPWR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  PCintPort::attachInterrupt(rEncoder, addRCount, RISING);
  PCintPort::attachInterrupt(lEncoder, addLCount, RISING);


}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(11,HIGH);

  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  analogWrite(RPWR,0 );
  analogWrite( LPWR, 0);
  
  if (analogRead(A5) < 400){
    canGoFL = false;
    digitalWrite(11, HIGH);
  }
if(countRight >= 13 || countLeft >= 13){
  canGoBR = true;
  canGoFR = true;
  canGoFL = true;
  canGoBL = true;
  countRight = 0;
  countLeft = 0;
//  nmbTerms = random(5,20);
}

  if (analogRead(A0) < 400){
    canGoBR = false;
    digitalWrite(12,HIGH);
  }
  
  if (analogRead(A3) < 400){
    canGoBL = false;
    digitalWrite(9, HIGH);
  }
 
  if(analogRead(A2) < 400){
    canGoFR = false;
    digitalWrite(10, HIGH);
  }


     
  if ( (canGoFL && canGoBR && canGoFR && canGoBL)) {
    goStraight();
  }
  else if( canGoFL && canGoFR){
    goStraight();
  }
  else if (canGoBR && canGoBL) {
    int action = (int) micros%4;
    goBackRL(action);
  }
  else 
  pivot();

  Serial.print("right");
  Serial.print( analogRead(A5));
  Serial.print("left");
  Serial.println(analogRead(A0));
  delay(20);

}

void goStraight(){
  digitalWrite(RDIR, HIGH);
    digitalWrite(LDIR, HIGH);
    analogWrite(RPWR, 105);
    analogWrite( LPWR, 105);
}
void pivot(){
    digitalWrite(RDIR, HIGH);
    digitalWrite(LDIR, LOW);
    analogWrite(RPWR, 105);
    analogWrite( LPWR, 105);
}
void goBackwards(){
  digitalWrite(RDIR, LOW);
    digitalWrite(LDIR, LOW);
    analogWrite(RPWR, 105);
    analogWrite( LPWR, 105);
}
void goBackRL(int nmb){
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, LOW);
  if (1){
    analogWrite(RPWR, 50);
    analogWrite( LPWR, 105);
  }
  else if(2){
    analogWrite(RPWR, 105);
    analogWrite( LPWR,50);
  }
  else{
   analogWrite(RPWR, 105);
    analogWrite( LPWR,105); 
  }
  
}

