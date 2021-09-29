const byte RIGHT_BTN = 5; // Right Button -> press for 1 | YES
const byte LEFT_BTN = 2; // Left Button -> press for 0 | NO

const byte LEDPins[8] = { 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {

  Serial.begin(9600);

  //Set pinModes
  pinMode(RIGHT_BTN, INPUT);
  pinMode(LEFT_BTN, INPUT);

  for (int i = 0; i < sizeof(LEDPins); i++)
  {
    pinMode(LEDPins[i], OUTPUT);
  }

}

void loop() {

}
