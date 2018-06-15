int second = A0; //0b0
int third = A1; //0b1
int fourth = A2; //enter
int fifth = A3; //space
int delayVal = 175; //delay value
  
void setup() {
  //setting up four pins, for each finger 
  pinMode(second, INPUT);
  pinMode(third, INPUT);
  pinMode(fourth, INPUT);
  pinMode(fifth, INPUT);
}

void loop() {
  int key = 0;
  int count = 0;
  bool convert = true;
  while (digitalRead(fourth) != LOW) {
    if (digitalRead(second) == LOW) {
      count++;
      if (count > 5) {
        convert = false;
        errorHandleOverflow();
        break;
      }
      key = key << 1;
      delay(delayVal);
    }
    if (digitalRead(third) == LOW) {
      count++;
      if (count > 5) {
        convert = false;
        errorHandleOverflow();
        break;
      }
      key = (key << 1) + 1;
      delay(delayVal);
    }
    
    if (digitalRead(fifth) == LOW) {
      Serial.print(" ");
      convert = false;
      delay(delayVal);
      break;
    }
  }
  if (convert) {
    Serial.print(bitConvert(key));
  }
  delay(delayVal);  
}

void errorHandleOverflow() {
  Serial.print("More than 5 bits entered. Error, input reset.");
  delay(delayVal);
  //add LED control code here later?
}

void errorHandleNoMatch() {
  Serial.print("5 bit code entered does not match to a character. Error, input reset.");
  delay(delayVal);
  //add LED control code here later?
}

char bitConvert(int key) {
  char converted;
  switch(key - 1) {
    case 0:
      converted = 'a';
    break;
    case 1:
      converted = 'b';
    break;
    case 2:
      converted = 'c';
    break;
    case 3:
      converted = 'd';
    break;
    case 4:
      converted = 'e';
    break;
    case 5:
      converted = 'f';
    break;
    case 6:
      converted = 'g';
    break;
    case 7:
      converted = 'h';
    break;
    case 8:
      converted = 'i';
    break;
    case 9:
      converted = 'j';
    break;
    case 10:
      converted = 'k';
    break;
    case 11:
      converted = 'l';
    break;
    case 12:
      converted = 'm';
    break;
    case 13:
      converted = 'n';
    break;
    case 14:
      converted = 'o';
    break;
    case 15:
      converted = 'p';
    break;
    case 16:
      converted = 'q';
    break;
    case 17:
      converted = 'r';
    break;
    case 18:
      converted = 's';
    break;
    case 19:
      converted = 't';
    break;
    case 20:
      converted = 'u';
    break;
    case 21:
      converted = 'v';
    break;
    case 22:
      converted = 'w';
    break;
    case 23:
      converted = 'x';
    break;
    case 24:
      converted = 'y';
    break;
    case 25:
      converted = 'z';
    break;
    case -1:
      converted = NULL;
    default:
      converted = NULL;
      errorHandleNoMatch();
  }
  return converted;
}



