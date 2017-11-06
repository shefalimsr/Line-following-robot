//#include <DHT.h>
//#include <DHT_U.h>
//#include <Adafruit_Sensor.h>

// SoftwareSerial - Version: Latest 
#include <SoftwareSerial.h>
//#include "DHT.h"
//#define DHTPIN A0     
//#define DHTTYPE DHT11
#define M1A 5
#define M1B 6
#define M2A 10
#define M2B 11
void fw();
void bw();
void left();
void right();
void stop();
void antic();
void c();
void ledon();
void ledoff();
void on();
void off();
void booston();
void boostoff();
static int b=1;
//DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial BT(0,1);
void setup(){
    BT.begin(9600);
//    dht.begin();
    Serial.begin(9600);
    pinMode(M1A,OUTPUT);
    pinMode(M1B,OUTPUT);
    pinMode(M2A,OUTPUT);
    pinMode(M2B,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(12,OUTPUT);
    //pinMode(2,OUTPUT);
    //pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    //pinMode(7,OUTPUT);
    //pinMode(8,OUTPUT);
    pinMode(3,INPUT);
    //pinMode(DHTPIN,OUTPUT);
    //digitalWrite(2,HIGH);
    //digitalWrite(7,HIGH);
    //digitalWrite(3,LOW);
    //digitalWrite(8,LOW);
}
void loop(){
  
    if(BT.available())
    {
/*        float h = dht.readHumidity();
        float t = dht.readTemperature();
        Serial.print(t);
        Serial.print(" *C | ");
        Serial.print(h);
        Serial.print(" % | ");*/
        char input=BT.read();
        //Serial.println(b);
        //Serial.println(input);
        
        switch(input){
            case '1':
            {fw();
            break;}
            case '2':
            {bw();
            break;}
            case '3':
            {left();
            break;}
            case '4':
            {right();
            break;}
            case '0':
            {stop();
            break;}
            case '7':
            {antic();
            break;}
            case '8':
            {c();
            break;}
            case '6':
            {ledoff();
            break;}
            case '5':
            {
              ledon();
              LF();
              break;}
            case '9':
            {on();
            break;}
            case 'p':
            {off();
            break;}
            case 'q':
            {booston();
            break;}
            case 'r':
            {boostoff();
            break;}
        }
    }
}

void LF(){
  while(1){
  int x=digitalRead(3);
  int y=digitalRead(2);
  if (BT.available()){
    char input=BT.read();
    if(input=='6')
    {
      stop();
      return;
    }
  }
  if(x==1 && y==1)
  {
    analogWrite(M1A,100);
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,100);
  }

  else if(x==0 && y==1)
  {
    analogWrite(M1A,100);
    analogWrite(M1B,0);
    analogWrite(M2A,100);
    analogWrite(M2B,0);
  }

  else if(x==1 && y==0)
  {
    analogWrite(M1A,0);
    analogWrite(M1B,100);
    analogWrite(M2A,0);
    analogWrite(M2B,100);
  }

  else if(x==0 && y==0)
  {
    analogWrite(M1A,100);
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,100);
  }
  }
}

void bw(){
    analogWrite(M1A,0);
    analogWrite(M1B,200+(27.5*b));
    analogWrite(M2A,200+(27.5*b));
    analogWrite(M2B,0);
}

void fw(){
    analogWrite(M1A,200+(27.5*b));
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,200+(27.5*b));
}

void left(){
    analogWrite(M1A,200+(27.5*b));
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,0);
}

void right(){
    analogWrite(M1A,0);
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,200+(27.5*b));
}

void stop(){
    analogWrite(M1A,0);
    analogWrite(M1B,0);
    analogWrite(M2A,0);
    analogWrite(M2B,0);
}

void antic(){
    analogWrite(M1A,200+(27.5*b));
    analogWrite(M1B,0);
    analogWrite(M2A,200+(27.5*b));
    analogWrite(M2B,0);
}

void c(){
    analogWrite(M1A,0);
    analogWrite(M1B,200+(27.5*b));
    analogWrite(M2A,0);
    analogWrite(M2B,200+(27.5*b));
}

void ledon(){
    digitalWrite(9,1);
}

void ledoff(){
    digitalWrite(9,0);
}

void on(){
    digitalWrite(12,1);
}

void off(){
    digitalWrite(12,0);
}

void booston(){
    b=2;
}

void boostoff(){
    b=1;
}
