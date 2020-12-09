// Zachary Wagner
// Mini Telegraph Code
#include <Servo.h>
#include <avr/pgmspace.h>

// Array of bytes for characters, each either 0 or 1
const PROGMEM byte letters[] =   {0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // a 0 - 44
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // b 45 - 89
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0, // c 90 - 134
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 1, 1, 1, 1, 1, 1, 1, 0, 0, // d 135 - 179
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 0, 1, 0, 0, // e 180 - 224
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0,
                                 1, 0, 1, 0, 0, 0, 0, 0, 0, // f 225 - 269
                                 0, 0, 1, 1, 1, 1, 1, 0, 1,
                                 0, 0, 1, 0, 0, 0, 1, 0, 1,
                                 0, 0, 1, 0, 0, 0, 1, 0, 1,
                                 0, 0, 1, 0, 0, 0, 1, 0, 1,
                                 0, 0, 1, 1, 1, 1, 1, 1, 1, // g 270 - 314
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // h 315 - 359
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 1, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, // i 360 - 404
                                 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 0, 0, 1, 0, 1, 1, 1, 1, 1,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, // j 405 - 449
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 0, 1, 0, 1, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, // k 450 - 494
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, // l 495 - 539
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // m 540 - 584
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // n 585 - 629
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // o 630 - 674
                                 0, 0, 1, 1, 1, 1, 1, 1, 1,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // p 675 - 719
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 1, 1, // q 720 - 764
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0, // r 765 - 809
                                 0, 0, 1, 1, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 0, 1, 1, 1, 0, 0, // s 810 - 854
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 1, 1, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 0, 0, 0, // t 855 - 899
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // u 900 - 944
                                 0, 0, 1, 1, 1, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                 0, 0, 1, 1, 1, 0, 0, 0, 0, // v 945 - 989
                                 0, 0, 1, 1, 1, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 0, 1, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 1, 1, 1, 1, 0, 0, // w 990 - 1034
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 1, 0, 1, 0, 0, 0,
                                 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 0, 0, 0, 1, 0, 1, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0, // x 1035 - 1079
                                 0, 0, 1, 1, 1, 1, 1, 0, 1,
                                 0, 0, 0, 0, 0, 0, 1, 0, 1,
                                 0, 0, 0, 0, 0, 0, 1, 0, 1,
                                 0, 0, 0, 0, 0, 0, 1, 0, 1,
                                 0, 0, 1, 1, 1, 1, 1, 1, 1, // y 1080 - 1124
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 1, 1, 0, 0,
                                 0, 0, 1, 0, 1, 0, 1, 0, 0,
                                 0, 0, 1, 1, 0, 0, 1, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0}; // z 1125 - 1169


// writtenChar class
// two variables, character and array_position
class writtenChar {
  public:
    char character;
    int array_position;
    
    writtenChar() {
      character = ' ';
      array_position = 0;
    }
    
    writtenChar(char c, int p){
      character = c;
      array_position = p;
    }
    
};

// size of array = number of characters
const int array_size = 26;
writtenChar char_Array[array_size];



// constants
Servo arm;
const int motorPin = 9;
const int solenoidPin = 10;
const int servoPin = 3;
const int delayTime = 1500;

// prototypes for user defined functions
void singleMotorTurn();
void spaceMotorTurn();

// global variables
bool foundChar;
int startingPos = 40;
int movePos = 6;
int endPos = 94;
int nextPos = startingPos + movePos;
char phrase[] = "m";
int strLength = sizeof(phrase);

void setup()
{
 // sets up pin modes for motor and solenoid
  pinMode(motorPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  
  // sets up servo
  arm.attach(servoPin);
  arm.write(startingPos);

// adds each character and position to char_Array
char_Array[0] = writtenChar('a', 0);
char_Array[1] = writtenChar('b', 45);
char_Array[2] = writtenChar('c', 90);
char_Array[3] = writtenChar('d', 135);
char_Array[4] = writtenChar('e', 180);
char_Array[5] = writtenChar('f', 225);
char_Array[6] = writtenChar('g', 270);
char_Array[7] = writtenChar('h', 315);
char_Array[8] = writtenChar('i', 360);
char_Array[9] = writtenChar('j', 405);
char_Array[10] = writtenChar('k', 450);
char_Array[11] = writtenChar('l', 495);
char_Array[12] = writtenChar('m', 540);
char_Array[13] = writtenChar('n', 585);
char_Array[14] = writtenChar('o', 630);
char_Array[15] = writtenChar('p', 675);
char_Array[16] = writtenChar('q', 720);
char_Array[17] = writtenChar('r', 765);
char_Array[18] = writtenChar('s', 810);
char_Array[19] = writtenChar('t', 855);
char_Array[20] = writtenChar('u', 900);
char_Array[21] = writtenChar('v', 945);
char_Array[22] = writtenChar('w', 990);
char_Array[23] = writtenChar('x', 1035);
char_Array[24] = writtenChar('y', 1080);
char_Array[25] = writtenChar('z', 1125);
                                 
}                                                                                                               

void loop()
{

 // loops through entire string
  for(int i = 0; i < strLength; i++) {
    foundChar = false;

    // if character in this phrase address is space or end
    // performs space motor turn
    if(phrase[i] == ' ' || phrase[i] == 0) {
      spaceMotorTurn();
      delay(delayTime);
    }

    
    else {
      // go through array of characters
    for(int j = 0; j < array_size; j++) {
      // if the character in that array section is the same as the phrase character
      if(char_Array[j].character == phrase[i]) {
        // go through all 45 bytes for that letter
        for(int k = char_Array[j].array_position; k < char_Array[j].array_position + 45; k++) {
          // if current byte is 0, solenoid pin is pulled down
          // arm moves one position
            if(pgm_read_byte(letters + k) == 0) {
              digitalWrite(solenoidPin, HIGH);
              delay(delayTime);
              arm.write(nextPos);
              delay(delayTime);
              nextPos += movePos;
            }

            // else the solenoid pin will be pushed up
            // arm moves one position
            else {
              digitalWrite(solenoidPin, LOW);
              delay(delayTime);
              arm.write(nextPos);
              delay(delayTime);
              nextPos += movePos;
            }

          // if arm has reached the end of the paper,
          // return arm to startPos, move motor once
          if(nextPos > endPos){
          digitalWrite(solenoidPin, HIGH);
          delay(delayTime);
          arm.write(startingPos);
          nextPos = startingPos + movePos;
          delay(delayTime);
          singleMotorTurn();
          delay(delayTime);
          }
          }
        // after character completed, will break
        foundChar = true;
        break;
        }
        
      }
    }
    // if character in string did not match any in array
    // will put space instead
    if(foundChar == false) {
      spaceMotorTurn();
      delay(delayTime);
    }
  }
}


// turns motor single turn
void singleMotorTurn()
{
  const int onTime = 100; 
 

  digitalWrite(motorPin, HIGH); 
  delay(onTime); 
  digitalWrite(motorPin, LOW); 
  
}

// turns motor for longer time for space
void spaceMotorTurn()
{
  const int onTime = 500; 
 

  digitalWrite(motorPin, HIGH); 
  delay(onTime); 
  digitalWrite(motorPin, LOW); 
  
}
