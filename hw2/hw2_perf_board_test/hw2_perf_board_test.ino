int second = A0; //0b0 key
int third = A2; //0b1 key
int fourth = A4; //enter key
int fifth = 12; //space key
int LED1 = 23; //capsLock LED
int LED2 = 0; //error LED
int LED3 = 1; //okay LED

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, LOW);
  delay(100);
}

void loop() {
  if (digitalRead(second) == LOW) {
    Serial.print("second");
  }

  if (digitalRead(third) == LOW) {
    Serial.print("third");
  }

  if (digitalRead(fourth) == LOW) {
    Serial.print("fourth");
  }

  if (digitalRead(fifth) == LOW) {
    Serial.print("fifth");
  }
  
}
