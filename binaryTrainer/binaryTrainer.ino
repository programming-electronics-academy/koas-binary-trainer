const byte RIGHT_BTN = 5; // Right Button -> press for 1 | YES  - Normally LOW, HIGH when Pressed
const byte LEFT_BTN = 2; // Left Button -> press for 0 | NO   - Normally HIGH, LOW when Pressed
const byte LEDPins[8] = { 13, 12, 11, 10, 9, 8, 7, 6 }; // Pins for LEDs positioned from Left (MSB) to Right (LSB)
const byte analogPinForRandomSeed = A2;

char msgBuffer[100]; // Buffer for displaying messages

//Timing of selection blink
boolean LEDState = HIGH;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;           // interval at which to blink (milliseconds)

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

/**
   Returns true if right button pressed
   Returns false otherwise
*/
boolean rightBTNPressed()
{
  boolean result = false;

  if (digitalRead(RIGHT_BTN))
  {
    result = true;
  }

  return result;
}

/**
   Returns true if left button pressed
   Returns false otherwise
*/
boolean leftBTNPressed()
{
  return digitalRead(LEFT_BTN) ? false : true;
}

void loop() {

  //Create and save random Number
  byte practiceByte = random(0, 256);

  sprintf(msgBuffer, "Enter --> %d <-- in binary", practiceByte);
  Serial.println(msgBuffer);

  /* I don't like this...I am using it as a test to see when input is complete */
  char input[8] = { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'} ; // Array to hold user input

  while (input[7] == 'x') {

    static byte count = 0; // Where we are in count
    
    //Blink LED that LED
    unsigned long currentMillis = millis();
    
    if(currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;

      LEDState ? LEDState = LOW : LEDState = HIGH;
      digitalWrite(LEDPins[count], LEDState); 
    }
    
    if (rightBTNPressed())
    {
      input[count] = '1';
      Serial.print(input[count]);
      digitalWrite(LEDPins[count], HIGH);
      count++;
      delay(500);
    }

    if (leftBTNPressed())
    {
      input[count] = '0';
      Serial.print(input[count]);
      count++;
      delay(500);
    }

    //Reset count
    if(count >= 8)
    {
      count = 0;
    }
  }

}
