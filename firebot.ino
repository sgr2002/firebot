#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int m1p=22;
const int m1n=23;
const int m2p=24;
const int m2n=25;
const int m3p=26;
const int m3n=27;
const int m4p=28;
const int m4n=29;
const int nm1=36;
const int nm2=37;
const int nm3=38;
const int nm4=39;
const int nm5=40;
const int nm6=41;
const int nm7=42;
const int pingPin1 = 2;
const int echoPin1 = 3;
const int pingPin2 = 6;
const int echoPin2 = 7;
long dur1,dur2;
int dis1,dis2;
void forward()
{
digitalWrite(m1n,HIGH);
digitalWrite(m1p,LOW);
digitalWrite(m2n,HIGH);
digitalWrite(m2p,LOW);
digitalWrite(m3n,HIGH);
digitalWrite(m3p,LOW);
digitalWrite(m4n,HIGH);
digitalWrite(m4p,LOW);
}
void reverse()
{
  digitalWrite(m1p,HIGH);
digitalWrite(m1n,LOW);
digitalWrite(m2p,HIGH);
digitalWrite(m2n,LOW);
digitalWrite(m3p,HIGH);
digitalWrite(m3n,LOW);
digitalWrite(m4p,HIGH);
digitalWrite(m4n,LOW);
}
void left()
{
digitalWrite(m1n,HIGH);
digitalWrite(m1p,LOW);
digitalWrite(m2n,LOW);
digitalWrite(m2p,HIGH);
digitalWrite(m3n,LOW);
digitalWrite(m3p,HIGH);
digitalWrite(m4n,HIGH);
digitalWrite(m4p,LOW);
}
void right()
{
digitalWrite(m1n,LOW);
digitalWrite(m1p,HIGH);
digitalWrite(m2n,HIGH);
digitalWrite(m2p,LOW);
digitalWrite(m3n,HIGH);
digitalWrite(m3p,LOW);
digitalWrite(m4n,LOW);
digitalWrite(m4p,HIGH);
}
void halt()
{
digitalWrite(m1p,LOW);
digitalWrite(m1n,LOW);
digitalWrite(m2p,LOW);
digitalWrite(m2n,LOW);
digitalWrite(m3p,LOW);
digitalWrite(m3n,LOW);
digitalWrite(m4p,LOW);
digitalWrite(m4n,LOW);
}
int dist1()
{
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin1, LOW);
  dur1 = pulseIn(echoPin1, HIGH);
  dis1 = dur1 * 0.017 ;
  return dis1;
}
int dist2()
{
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin2, LOW);
  dur2 = pulseIn(echoPin2, HIGH);
  dis2 = dur2 * 0.017;
  Serial.print(dis2);
  return dis2;
}

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Fire Bot");  
  pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(A6,INPUT);
pinMode(A7,INPUT);
  pinMode(pingPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(pingPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(m1p,OUTPUT);
pinMode(m1n,OUTPUT);
pinMode(m2p,OUTPUT);
pinMode(m2n,OUTPUT);
pinMode(m3p,OUTPUT);
pinMode(m3n,OUTPUT);
pinMode(m4p,OUTPUT);
pinMode(m4n,OUTPUT);
pinMode(46,OUTPUT); 
pinMode(nm1,INPUT);
pinMode(nm2,INPUT);
pinMode(nm3,INPUT);
pinMode(nm4,INPUT);
pinMode(nm5,INPUT);
pinMode(nm6,INPUT);
pinMode(nm7,INPUT); 
pinMode(50,INPUT); 
pinMode(51,INPUT); 
digitalWrite(46,HIGH);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
Serial.println(analogRead(A1));
Serial.println(analogRead(A2));
Serial.println(analogRead(A3));
Serial.println(analogRead(A4));
Serial.println(analogRead(A5));
Serial.println(analogRead(A6));
Serial.println(analogRead(A7));
Serial.println(digitalRead(50));
Serial.println(digitalRead(51));

  if(digitalRead(nm1)==LOW)
  {
    lcd.setCursor(1,0);
  lcd.print("FireBot Auto   ");
    Serial.println("Auto");
    if(digitalRead(50)==0 || digitalRead(51)==0 || (analogRead(A2)<30 && analogRead(A3)<30 && analogRead(A4)<30 && analogRead(A5)<30))
    {
      digitalWrite(46,LOW);
    }
    else
    {
      digitalWrite(46,HIGH);
    }
  }
  else
  {
    lcd.setCursor(1,0);
  lcd.print("FireBot Manual");
  Serial.println("Manual");
    if(digitalRead(nm6)==HIGH)
    {
      digitalWrite(46,LOW);
    }
    else
    {
      digitalWrite(46,HIGH);
    }
    
  }
  if(digitalRead(nm2))
    {
      if(dist2()<1)
{
  halt();
}
else
{
      forward();
}
      lcd.setCursor(3,1);
  lcd.print("Forward  ");
    }
    else if(digitalRead(nm3))
    {
      right();
      lcd.setCursor(3,1);
  lcd.print("Right    ");
    }
    else if(digitalRead(nm4))
    {
      reverse();
      lcd.setCursor(3,1);
  lcd.print("Reverse  ");
    }
    else if(digitalRead(nm5))
    {
       left();
       lcd.setCursor(3,1);
  lcd.print("Left    ");
    }
    else
    {
        halt();
    }
}
