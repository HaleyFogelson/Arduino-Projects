/*
Author: Haley Fogelson
Date: December 24, 2017
Class: Robotics

*/

#include <Servo.h>
#include <Ping.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

#define sclk 13
#define rst  12
#define mosi 11
#define cs   10
#define dc    8

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
// 0.. r,b ..31, 0.. g ..63
#define color(r,g,b)    ((r << 11) | (g << 5) | b)

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

#define SERVO 9
Servo sweep;

#define LDIR  7
#define LPWR  6
#define RPWR  5
#define RDIR  4

#define PING  3
Ping ping(PING);

#define MAXCM 50.0
#define PIXELSPERCMX (display.width()/(MAXCM*2))
#define PIXELSPERCMY (display.height()/MAXCM)

float lastDist[180];
void drawLine (float distance, int angle, boolean erase) {


  // draw a line from bottom middle at angle for distance
  //
  // distance is in CM... need to convert to pixels.
  // height in pixels represents 61 cm.

  if (erase)
    drawLine (lastDist[angle], angle, false);

  float x = (int)(cos(radians(angle)) * distance * PIXELSPERCMX) + display.width() / 2;
  float y = display.height() - (int)(sin(radians(angle)) * distance * PIXELSPERCMY);

  int dispColor = (distance < MAXCM ? (distance < MAXCM / 1.5 ? RED : YELLOW) : GREEN);
  display.drawLine(display.width() / 2, display.height() - 1, x, y, !erase ? BLACK : dispColor);

  if (erase) {
    lastDist[angle] = distance;
  }
}

void setup(void) {
  Serial.begin (115200);
  display.begin();
  display.fillScreen(BLACK);

  sweep.attach (SERVO);
  
}

void loop() {
  goStraight();
  static int angle = 0;
  static int dA = 4;
  sweep.write (angle);
  
  delay(30);
  ping.echo();
  drawLine (min (ping.getDistanceCm(), MAXCM), map(angle, 0, 180, 180, 0), true);

  angle += dA;
  if (angle < 0 || angle > 179) {
    angle -= dA;
    dA = -dA;
    angle += dA;
  }
  if(lastDist[90] < 10 || lastDist[92] < 10 || lastDist[88] < 10|| lastDist[91] < 10 || lastDist[89] < 10){
    boolean notFound = true;
    int i = 90;
    while(notFound){
      if(lastDist[i++]> 10){
        notFound = false;
        turnRight(i-90);
      }
    }
  }

  /*if ((lastDist[90] < 10 || lastDist[85] < 10 || lastDist[95] < 10)) {
    sweep.write (90);
    delay(90);
    ping.echo();
    while (ping.getDistanceCm() < 10) {
      if (lastDist[120] > 10)
          turnLeft();
      else {
        turnRight();
        }
      delay(10);
      ping.echo();
    }


  }
  */


}



void goStraight() {
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, LOW);
  analogWrite(RPWR, 105);
  analogWrite( LPWR, 105);
}
void turnLeft(int deg) {
  digitalWrite(LDIR, LOW);
  analogWrite(RPWR, 0);
  analogWrite( LPWR, 105);
  delay(17 * deg);
  analogWrite( LPWR, 0);

}
void turnRight(int deg) {
  digitalWrite(RDIR, LOW);
  analogWrite(RPWR, 105);
  analogWrite( LPWR, 0);
  delay(17 * deg);
  analogWrite( RPWR, 0);

}


