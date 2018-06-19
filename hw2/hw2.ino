int second = A0; //0b0 key
int third = A1; //0b1 key
int fourth = A2; //enter key
int fifth = A3; //space key
int delayVal = 175; //delay value

//setting up four pins, for each finger 
void setup() {
  pinMode(second, INPUT);
  pinMode(third, INPUT);
  pinMode(fourth, INPUT);
  pinMode(fifth, INPUT);
}

//main
void loop() {
  int key = 0;
  int count = 0;
  bool convertFlag = true;
  bool capFlag = false;
  
  while (digitalRead(fourth) != LOW) {
    if (digitalRead(second) == LOW) {
      count++;
      convertFlag = errorHandleOverflow(count);
      if (!convertFlag) {
        break;
      }
      key = key << 1;
      delay(delayVal);
    }
    if (digitalRead(third) == LOW) {
      count++;
      convertFlag = errorHandleOverflow(count);
      if (!convertFlag) {
        break;
      }
      key = (key << 1) + 1;
      delay(delayVal);
    }
    
    if (digitalRead(fifth) == LOW) {
      Serial.print(" ");
      key = -1;
      convertFlag = false;
      delay(delayVal);
      break;
    }
  }
  
  if (key == 0) {
    capFlag = !capFlag;  
    //add LED control code here later?
  } else {
    if (convertFlag) {
      Serial.print(bitConvert(key, capFlag));
    }
  }
  delay(delayVal);  
}

//error handler for more than 5 bit input
void errorHandleOverflow(int count) {
  if (count > 5) {
    Serial.print("More than 5 bits entered. Error, input reset.");
    delay(delayVal);
    //add LED control code here later?
    return false;
  } else {
    return true;
  }
}

//error handler for unrecognized input
void errorHandleNoMatch() {
  Serial.print("5 bit code entered does not match to a character. Error, input reset.");
  delay(delayVal);
  //add LED control code here later?
}

//binary to char converter
char bitConvert(int key, bool capFlag) {
  char converted;
  if (capFlag) {
    switch(key) {
      case 1: converted = 'A'; break;
      case 2: converted = 'B'; break;
      case 3: converted = 'C'; break;
      case 4: converted = 'D'; break;
      case 5: converted = 'E'; break;
      case 6: converted = 'F'; break;
      case 7: converted = 'G'; break;
      case 8: converted = 'H'; break;
      case 9: converted = 'I'; break;
      case 10: converted = 'J'; break;
      case 11: converted = 'K'; break;
      case 12: converted = 'L'; break;
      case 13: converted = 'M'; break;
      case 14: converted = 'N'; break;
      case 15: converted = 'O'; break;
      case 16: converted = 'P'; break;
      case 17: converted = 'Q'; break;
      case 18: converted = 'R'; break;
      case 19: converted = 'S'; break;
      case 20: converted = 'T'; break;
      case 21: converted = 'U'; break;
      case 22: converted = 'V'; break;
      case 23: converted = 'W'; break;
      case 24: converted = 'X'; break;
      case 25: converted = 'Y'; break;
      case 26: converted = 'Z'; break;
      default:
        converted = NULL;
        errorHandleNoMatch();
    }
  } else {
    switch(key) {
      case 1: converted = 'a'; break;
      case 2: converted = 'b'; break;
      case 3: converted = 'c'; break;
      case 4: converted = 'd'; break;
      case 5: converted = 'e'; break;
      case 6: converted = 'f'; break;
      case 7: converted = 'g'; break;
      case 8: converted = 'h'; break;
      case 9: converted = 'i'; break;
      case 10: converted = 'j'; break;
      case 11: converted = 'k'; break;
      case 12: converted = 'l'; break;
      case 13: converted = 'm'; break;
      case 14: converted = 'n'; break;
      case 15: converted = 'o'; break;
      case 16: converted = 'p'; break;
      case 17: converted = 'q'; break;
      case 18: converted = 'r'; break;
      case 19: converted = 's'; break;
      case 20: converted = 't'; break;
      case 21: converted = 'u'; break;
      case 22: converted = 'v'; break;
      case 23: converted = 'w'; break;
      case 24: converted = 'x'; break;
      case 25: converted = 'y'; break;
      case 26: converted = 'z'; break;
      default:
        converted = NULL;
        errorHandleNoMatch();
    }
  }
  return converted;
}



