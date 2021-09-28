/**
 * 
 * An Arduino Board Game using the koas to practice your binary skills!
 * 
 * TODO:
 *  
 *  Lorenzo decides to practice reading binary numbers - what can I say - he's a dork like that.
 *  He heard about a fun binary trainer he can build with his Arduino UNO and his Kit-on-s-Shield
 *  He goes to https://programmingelectronics.com/binaryTrainer, downloads the code for the project, 
 *  and uploads it to his Arduino UNO
 *  
 *  The instructions on the webpage instruct Lorenzo to open up the serial 
 *  monitor window once the program is loaded and follow the instructions.
 *  
 *  A welcome message on the Serial Monitor window tells the user to select either "practice" or "timed test" 
 *  Lorenzo selects "practice"
 *  
 *  The Serial Monitor window displays a message exmplaing that it will show a number
 *  in decimal format, for example 79.  Lorezo then must input the decimal version of that  
 *  number using the Kit-on-a-Shield buttons from least signicant bit (LSB) to most significant bit (MSB).  
 *  A left button press will be a 0 and right button press will be a 1.  
 *  
 *  The 8 LEDs on the Kit-on-a-Shield will act as a visual representation of the byte, with an on LED representing a 1,
 *  and an off LED representing a 0.
 *  
 *  As instructed, Lorenzo presses either button to begin the practice round.
 *  
 *  The number 175 is displayed on the Serial Monitor window.
 *  
 *  Lorezo knows that 175 in binary format is 10101111 NOTE: MSB->10101111<-LSB
 *  Starting at the LSB, Lorenzi begins to input the number.  He starts by pressing the right button, since the LSB is a 1.
 *  
 *  The LED in the LSB position illuminates and stays on. 
 *  
 *  He then presses the right button again for the next digit.
 *  
 *  The next LED lights and stays on.
 *  
 *  He repeats this 2 more times until he gets to the 5th digit, where he now presses the left button since the digit is a 0. 
 *  
 *  The 5th LED lights up momentarily, and then goes dark.
 *  
 *  He continues pressing the appropriate buttons for each digit.
 *  
 *  When he gets to the last digit, he see's notices two things on the Serial Monitop window.
 *  
 *  1) The binary number he entered on the Kit-on-a-Shield has been displayed on a single line
 *  2) He is asked to press the right button to submit the answer, and the left button if he would like to reenter it.
 *  
 *  Lorenzo is pretty sure he entered the number correct, so he presses the right button.
 *  
 *  A message on the serial monitor congratulates him, and the LEDs on the Kit-on-a-Shield light up back and forth in a victory lap.
 *  
 *  Another message is displayed asking if he would like another practice number, to press the right button for YES and the left button for No.
 *  
 *  He presses the right button, and a new number, 42, is displayed on the screen.  Lorenzo is not sure how to represent the number 42 in binary,
 *  but he enters his best guess and enters 101011  NOTE: Correct-> 101010  
 *  
 *  When asked to press the left button to submit his answer, he decides to try rentering the value, 
 *  because he thinks he flipped one of the bits wrong.  
 *  
 *  He presses the left button to 
 *  
 *  
 *  
 *  
 *  
 *  
 *  
 *  
 *  
 *  

 *  
 *  
 * 
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
