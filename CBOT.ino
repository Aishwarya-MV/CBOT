#include <Servo.h>

Servo servob;
Servo servol;
Servo servor;

int pos = 0;
const int buttonPin = 3;
const int ledPin =  13; 
int buttonState = 0;
const int ledg = 8;
const int ledy = 9;


void setup() {
  // put your setup code here, to run once:
servob.attach(4);
servol.attach(5);
servor.attach(6);
 pinMode(buttonPin, INPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(ledg, OUTPUT);
 pinMode(ledy, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
if(buttonState == LOW)
{
servob.write(0);
servol.write(180);
servor.write(0);
digitalWrite(ledy, HIGH);
digitalWrite(ledg, LOW);

}
else
if(buttonState == HIGH)
{
digitalWrite(ledg, HIGH);
digitalWrite(ledy, LOW);

servor.write(90);
servol.write(90);

delay(5000);

for(pos =0; pos<=100;pos++)
{
servob.write(pos);
delay(5);
}

for(pos = 90; pos>=0;pos--)
{
servor.write(pos);
servol.write(180 - pos);
delay(5);
}
delay(3000);

for(pos = 100; pos>=0;pos--)
{
servob.write(pos);
delay(10);
}

}

}
