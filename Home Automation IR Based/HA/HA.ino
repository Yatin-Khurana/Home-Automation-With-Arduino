/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int r1 = LOW;
int r0 = LOW;
int r2= LOW;
int r3= LOW;
int r4= LOW;
int r5= LOW;
int r6= LOW;
int r7= LOW;
int r8= LOW;
int r9 = LOW;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  for(int v= 1;v<10;v++){
    pinMode(v+2,OUTPUT);
  }
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  for(int v= 1;v<10;v++){
    digitalWrite(v+2,LOW);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    long unsigned int x  = (results.value);
    Serial.println(x);
    irrecv.resume(); // Receive the next value
    //////////////////paste remote Code here//////////////
    if(x == (15663359)){
      Serial.println("code matched");
      toggle(2);
    }
    /////////////////////////////////////////////////////
  }
  delay(100);
}
////////////Toggle function/////////////////////
int toggle(int pin){
  if(pin == 2)
  {
    if(r2 == LOW){
      r2 = HIGH;
      digitalWrite(13,HIGH);
    }
    else{
      r2 = LOW;
      digitalWrite(13,LOW);
    }
  }
  if(pin == 3)
  {
    if(r3 == LOW){
      r3 = HIGH;
      digitalWrite(3,HIGH);
    }
    else{
      r3 = LOW;
      digitalWrite(3,LOW);
    }
  }
  if(pin == 4)
  {
    if(r4 == LOW){
      r4 = HIGH;
      digitalWrite(4,HIGH);
    }
    else{
      r4 = LOW;
      digitalWrite(4,LOW);
    }
  }
  if(pin == 5)
  {
    if(r5 == LOW){
      r5 = HIGH;
      digitalWrite(5,HIGH);
    }
    else{
      r5 = LOW;
      digitalWrite(5,LOW);
    }
  }
if(pin == 6)
  {
    if(r6 == LOW){
      r6 = HIGH;
      digitalWrite(6,HIGH);
    }
    else{
      r6 = LOW;
      digitalWrite(6,LOW);
    }
  }if(pin == 7)
  {
    if(r7 == LOW){
      r7 = HIGH;
      digitalWrite(7,HIGH);
    }
    else{
      r7 = LOW;
      digitalWrite(7,LOW);
    }
  }if(pin == 8)
  {
    if(r8 == LOW){
      r8 = HIGH;
      digitalWrite(8,HIGH);
    }
    else{
      r8 = LOW;
      digitalWrite(8,LOW);
    }
  }if(pin == 9)
  {
    if(r9 == LOW){
      r6 = HIGH;
      digitalWrite(5,HIGH);
    }
    else{
      r9 = LOW;
      digitalWrite(9,LOW);
    }
  }
}


