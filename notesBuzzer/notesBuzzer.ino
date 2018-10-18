/*
Author: Haley Fogelson
Date: October 17, 2018
Class: CornerStone to Engineering


*/

#include <LiquidCrystal.h>

#define button1 2
#define button2 3
#define button3 4
#define buzzer 6
#define bellPin 6


//Notes


#define BREAK 0
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988



const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  int namesT[] = { 261, 294, 329, 349, 392, 440, 493, 523 };
  int tonesT[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 // char Iamurs[]= {'d','d','B','B','B','B','B','B','B','C','d','d'};
  //int tempoIamurs[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};



int thisNote = 0;
int tempo =76;
int i = 0;
int note= 0;
int tempoJi = 300;

int melodyJ[] = {
 //Dash  -   ing         through   the   snow 
    NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A4,
  
  // in         a       one     hor- se   o -   pen       sleigh
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4,

  //  over   the        fields     we       go
    NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_CS5, 

  // laugh- ing         all    the      way
  NOTE_A5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_FS5, 0,
  
  // Bells    on        bob      tail    ring
    NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A4,
    
  // mak     ing       spir     its     bright
    NOTE_A4, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4,

  // What       fun     it          is      to      ride    and     sing        a       sleigh  ing     song      to       night!
    NOTE_B4, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, 0,
 

  // Jin-       gle       Bells,      Jin-      gle     Bells,    jin-      gle     all       the     way
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_A5, NOTE_D4, NOTE_E5, NOTE_FS5, 

  //    Oh,   what       fun      it      is      to        ride-       in      a
    NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,

  // one       hor- se   o-      pen       sle-    igh!-
   NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A5,

  // Jin-       gle       Bells,      Jin-      gle     Bells,    jin-      gle     all       the     way
    NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_A5, NOTE_D4, NOTE_E5, NOTE_FS5, 

  //    Oh,   what       fun      it      is      to        ride-       in      a
    NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_FS5,

 // one       hor- se   o-      pen       sle-  
   NOTE_A5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5
};

int tempoJ[] = {     4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 2,
  4, 4, 4, 4, 2, 2,
  4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2,
   
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 1, 
  4, 4, 2, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 2, 2,
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 1, 
  4, 4, 2, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 2
};



//eye of the tiger
int melodyE[]={988,988,880,988,988,880,988,988,880,784,880};
int tempoE[]={250,250,250,250,250,250,250,250,250,1000,1000};
int breaks[]={1000,400,400,1000,400,400,1000,400,400,1000,1000};

  

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Music assignment");

}

void loop() {
  lcd.setCursor(0,1);
  //lcd.print(millis()/1000);
  // put your main code here, to run repeatedly:

  
 if(digitalRead(button1)==LOW){
  lcd.print("Music stopped   ");
  }

 
   else if(digitalRead(button2)==LOW){
      lcd.print("Eye of the Tiger");
        tone(buzzer,melodyE[thisNote],tempoE[thisNote]);
        delay(breaks[thisNote]);
        thisNote++;
        if(thisNote>=11)
            thisNote= 0;
    
  }
    else if(digitalRead(button3)==LOW){
        if(note>=100)
            note=0;
     if(melodyJ[i]==0){
        delay(tempoJ[note]*tempoJi);
     }
     else{
     tone(buzzer, melodyJ[note],1000/tempoJ[note] );
     }
      delay(tempoJi/2);  
      noTone(buzzer);
     note++;
    lcd.print("Jingle Bells    ");
        
  }

}
