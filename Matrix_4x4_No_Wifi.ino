const byte NUMBER_OF_ROWS = 4;
const byte NUMBER_OF_COLUMNS = 4;

const byte persistanceTimer = 5; // Controls how quickly the rows trun on.
const byte timmerCount = 35; // Controls how many times the funtion loops through the array. More loops mean longer time on each pattern.

byte column[NUMBER_OF_COLUMNS] = {5,4,0,2}; // Column Pins
byte row[NUMBER_OF_ROWS] = {16,14,12,13}; // Row pins

void setup() {

  //set all pins as output
  for (byte i=0; i<NUMBER_OF_ROWS; i++){
    pinMode(row[i], OUTPUT);
  }
  for (byte i=0; i<NUMBER_OF_COLUMNS; i++){
    pinMode(column[i], OUTPUT);
  }
}

void loop() {

  allOff();
  /* Create some arrays to send to displayLight(). 
   *  The first 4 bits show the first line of LEDs. The second 4 bits show the second row and so on.
   *  There are 16 bits total.
   *  
   *  bits of the Byte:
   *  {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
   *  
   *  Coresponding Leds in the Matrix:
   *  0,1,2,3,
   *  4,5,6,7,
   *  8,9,10,11,
   *  12,13,14,15
   *  
   *  Thus led1[4][4] = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}} will turn on the top left and bottom right leds.
   */

  byte led1[4][4] = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
  byte led2[4][4] = {{0,1,0,0},{0,0,0,0},{0,0,0,0},{0,0,1,0}};
  byte led3[4][4] = {{0,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,0}};
  byte led4[4][4] = {{0,0,0,0},{0,0,1,0},{0,1,0,0},{0,0,0,0}};
  byte led5[4][4] = {{0,0,1,0},{0,0,0,0},{0,0,0,0},{0,1,0,0}};
  byte led6[4][4] = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
  byte led7[4][4] = {{0,0,0,0},{0,0,0,1},{1,0,0,0},{0,0,0,0}};
  byte led8[4][4] = {{0,0,0,0},{0,0,1,0},{0,1,0,0},{0,0,0,0}};

  
  byte led9[4][4] = {{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,0,0,1}}; //X
  byte led10[4][4] = {{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}}; //O
  byte led11[4][4] = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}; //*
  byte led12[4][4] = {{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
  byte led13[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
  byte led14[4][4] = {{1,1,0,0},{0,0,1,1},{1,1,0,0},{0,0,1,1}};
  byte led15[4][4] = {{0,0,1,1},{1,1,0,0},{0,0,1,1},{1,1,0,0}};
  // If you create a new array (pattern) you will need to send it to the displayLight() function. displayLight("nameOfYourArray");
  
  
  
  
  displayLight(led1);
  displayLight(led2);
  displayLight(led3);
  displayLight(led4);
  displayLight(led5);
  displayLight(led6);
  displayLight(led7);
  displayLight(led8);
  displayLight(led9);
  displayLight(led10);
  displayLight(led9);  
  displayLight(led10);
  displayLight(led12);
  displayLight(led12);
  displayLight(led13);
  displayLight(led13);
  displayLight(led14);
  displayLight(led15);
  displayLight(led14);
  displayLight(led15);
  
}

void allOff(){
  for(byte i=0; i<NUMBER_OF_ROWS; i++){
    digitalWrite(row[i], HIGH);
  }
  for(byte i=0; i<NUMBER_OF_COLUMNS; i++){
    digitalWrite(column[i], LOW);
  }
}

// simple funtion to injest the information from the array and send it to the LEDs.

void displayLight(byte leds[4][4]){
  for(byte n=0; n<timmerCount; n++){
    for(byte i=0; i<4; i++){
      digitalWrite(row[i], LOW); // turn on the row
      for(byte n=0; n<4; n++){ // for loop to turn on the leds in a given row
        leds[i][n] ? digitalWrite(column[n], HIGH) : digitalWrite(column[n], LOW);
      }
      delay(persistanceTimer);
      digitalWrite(row[i], HIGH); // turn off the row
    }
  }
}
