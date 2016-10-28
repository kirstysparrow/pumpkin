/* Singing, Glowing, Haloween Pumpkin
 * Written by Kirsty Sparrow and Adrian McEwen
 *
 * Uses a PIR sensor to detect movement, and whenever it is triggered
 * it flashes four LEDs and plays a tune on a piezo buzzer to scare the intruder.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note   frequency   period  timeHigh
 * c          261 Hz          3830  1915  
 * d          294 Hz          3400  1700  
 * e          329 Hz          3038  1519  
 * f          349 Hz          2864  1432  
 * g          392 Hz          2550  1275  
 * a          440 Hz          2272  1136  
 * b          493 Hz          2028  1014  
 * C          523 Hz          1912  956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

/*
  Button - the motion sensor
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */
  
int speakerPin = 9;

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  12;      // the number of the LED pin
const int ledPin2 =  13;      // the number of the LED pin
const int ledPin3 =  A4;      // the number of the LED pin
const int ledPin4 =  A3;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


int length = 12; // the number of notes
//Close Encounters of the Third Kind
char notes[] = "GAFfc GAFfc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1 };

//Scale
//char notes[] = "fgabcdeFGABCD "; // a space represents a rest
//int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

//ghoul
//char notes[] = "bBCCaf bCbg efec"; // a space represents a rest
//int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

//batman
//char notes[] = "CCbbaabbCCbbaabbee "; // a space represents a rest
//int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2 };

//alarm 1
//char notes[] = "abcdabcdabcd "; // a space represents a rest
//int beats[] = { 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2 };

//alarm 2
//char notes[] = "cacacacacacaca "; // a space represents a rest
//int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4 };

//twinkle twinkle
//char notes[] = "ccggaagffeeddc "; // a space represents a rest
//int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };

int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}


// Use this for Ghoul - The frequencies don't correspond to actual notes

//void playNote(char note, int duration) {
//  char names[] = { 'b', 'c', 'd', 'e', 'f', 'g', 'a', 'B', 'C', 'D' };
//  int tones[] = { 1822, 1643, 1479, 1213, 901, 793, 600, 448, 237, 130 };

//Use this for the other tunes - The frequencies do play the actual notes

//void playNote(char note, int duration) {
//  char names[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'A', 'B', 'C' };
//  int tones[] = {  1929, 1822, 1715, 1608, 1519, 1432, 1175, 1100, 1014, 856 };

void playNote(char note, int duration) {
  char names[] = { 'f', 'g', 'a', 'b', 'c', 'd', 'e', 'F', 'G', 'A', 'B', 'C', 'D', 'E' };
  int tones[] = { 1318, 1175, 1046, 998, 880, 784, 698, 659, 587, 523, 494, 440, 349, 392 };
  // play the tone corresponding to the note name
  for (int i = 0; i < 14; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
 // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);  
  pinMode(ledPin4, OUTPUT);
 // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on: 
       
    bool leftOn = true;
    bool rightOn = false;    
    for (int i = 0; i < length; i++) {
      digitalWrite(ledPin1, leftOn);
      digitalWrite(ledPin3, leftOn);
      leftOn = !leftOn;
      if (rightOn) {
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin4, HIGH);
        rightOn = false;
      } else {
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin4, LOW);
        rightOn = true;
      }
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
      //digitalWrite(ledPin1, HIGH);
    } else {
      playNote(notes[i], beats[i] * tempo);
      //digitalWrite(ledPin2, HIGH);  
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
    
   
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW); 
    digitalWrite(speakerPin, LOW);
  }
}
  
