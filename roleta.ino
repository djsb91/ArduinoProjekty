#include<Servo.h>
int pos = 0;

//Sterownik rolety na przyciski + dwa mechanizmy krańcowe

Servo servo;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  servo.attach(6);
}
void loop() {
 
  // Żaden z przycisków nie jest naciśnięty / są wciśnięte obydwa 
  // Servo stoi 
  while (digitalRead(2) == HIGH && digitalRead(3) == HIGH) {
    pos=89;
    servo.write(pos);
    delay(15);
  }
  while (digitalRead(2) == LOW && digitalRead(3) == LOW) {
    pos=89;
    servo.write(pos);
    delay(15);
  }
    // Skręt w prawo
  while (digitalRead(2) == HIGH && digitalRead(3) == LOW && digitalRead(5) == LOW) {
    pos=180;
    servo.write(pos);
    delay(15);
  }
  while (digitalRead(2) == HIGH && digitalRead(3) == LOW && digitalRead(5) == HIGH) {
    pos=89;
    servo.write(pos);
    delay(15);
  }
  
  // Skręt w lewo
  while (digitalRead(2) == LOW && digitalRead(3) == HIGH && digitalRead(4) == LOW) {
    pos=-180;
    servo.write(pos);
    delay(15);
  }
  while (digitalRead(2) == LOW && digitalRead(3) == HIGH && digitalRead(4) == HIGH) {
    pos=89;
    servo.write(pos);
    delay(15);
  
  
  }
}