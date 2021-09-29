const byte RIGHT_BTN = 5; // Right Button -> press for 1 | YES  - Normally LOW, HIGH when Pressed
const byte LEFT_BTN = 2; // Left Button -> press for 0 | NO   - Normally HIGH, LOW when Pressed
const byte LEDPins[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };
const byte analogPinForRandomSeed = A2;

char msgBuffer[100]; // Buffer for displaying messages

void setup() {

  Serial.begin(9600);

  //Set pinModes
  pinMode(RIGHT_BTN, INPUT);
  pinMode(LEFT_BTN, INPUT);

  for (int i = 0; i < sizeof(LEDPins); i++)
  {
    pinMode(LEDPins[i], OUTPUT);
  }

  //Seed random number
  randomSeed(analogRead(analogPinForRandomSeed));
}


void loop() {

  //Create and save random Number
  byte practiceByte = random(0, 256);

  sprintf(msgBuffer, "Enter --> %d <-- in binary", practiceByte);
  Serial.println(msgBuffer);

  /* I don't like this...*/
  char input[8] = {'a','b','c','d','e','f','g','h'};

  while (input[0] == 'a') {

    static byte count = 7;

    if (digitalRead(RIGHT_BTN) == HIGH)
    {
      input[4] = '1';
      sprintf(msgBuffer,"%s",input); 
      Serial.println(msgBuffer);
      count--;
      delay(100);
    }
  }

}
