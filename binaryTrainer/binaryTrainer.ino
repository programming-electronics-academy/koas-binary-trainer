const byte RIGHT_BTN = 5; // Right Button -> press for 1 | YES
const byte LEFT_BTN = 2; // Left Button -> press for 0 | NO

const byte LEDPins[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };

const byte analogPinForRandomSeed = A2;

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
  Serial.println(practiceByte);
  
}
