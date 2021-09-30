const byte RIGHT_BTN = 5; // Right Button -> press for 1 | YES  - Normally LOW, HIGH when Pressed
const byte LEFT_BTN = 2; // Left Button -> press for 0 | NO   - Normally HIGH, LOW when Pressed
const byte numLEDs = 8;
const byte LEDPins[numLEDs] = { 13, 12, 11, 10, 9, 8, 7, 6 }; // Pins for LEDs positioned from Left (MSB) to Right (LSB)
const byte analogPinForRandomSeed = A2;


char msgBuffer[100]; // Buffer for displaying messages

//Timing of selection blink
boolean LEDState = LOW;
unsigned long previousMillis = 0; // will store last time LED was updated
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

/*
 * Converts an array representing the digits  
 * of a binary number to an integer.
 */
int convertBinaryArrayToInt(byte binArray[], byte arrayLength)
{
  int result = 0;

  for (int i = arrayLength - 1, multiplier = 1; i >= 0; i--, multiplier *= 2)
  {
    result += multiplier * binArray[i];
  }

  return result;
}

void loop() {

  //Create and save random Number
  byte practiceByte = random(0, 256);

  sprintf(msgBuffer, "\nEnter --> %d <-- in binary\n\nYour Answer--> ", practiceByte);
  Serial.print(msgBuffer);

  /* I don't like this...I am using it as a test to see when input is complete */
  byte input[numLEDs] = { 2, 2, 2, 2, 2, 2, 2, 2 } ; // Array to hold user input

  /************************************************************
        INPUT MODE
  ***********************************************************/
  while (input[numLEDs - 1] == 2) {
    static byte count = 0; // Where we are in count

    /**********************/
    /* Right Button Input */
    /**********************/
    static boolean rightButtonFlag = true;

    if (rightBTNPressed() && rightButtonFlag)
    {
      input[count] = 1;
      Serial.print(input[count]);
      digitalWrite(LEDPins[count], HIGH);
      count++;

      rightButtonFlag = false;
    }

    // Check if button has been released
    if (!rightBTNPressed())
    {
      rightButtonFlag = true;
    }

    /*********************/
    /* Left Button Input */
    /*********************/
    static boolean leftButtonFlag = true;

    if (leftBTNPressed() && leftButtonFlag)
    {
      input[count] = 0;
      Serial.print(input[count]);
      digitalWrite(LEDPins[count], LOW);
      count++;

      leftButtonFlag = false;
    }

    // Check if button has been released
    if (!leftBTNPressed())
    {
      leftButtonFlag = true;
    }

    /****************************
       Blink current input LED
     ***************************/
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;

      !LEDState ? LEDState = HIGH : LEDState = LOW;
      digitalWrite(LEDPins[count], LEDState);
    }

    //Reset count
    if (count >= 8)
    {
      count = 0;
    }
  }

  /************************************************************
       Check Result
  ***********************************************************/

  Serial.print("\nIs this your final answer?  No (left button), Yes (right button)"); 
  
  boolean submit = false;

  while(!submit)
  {
    if(leftBTNPressed() || rightBTNPressed()){
      submit = !submit;
    }
    delay(100);
  }

  
  
  int inputValue;
  





}
