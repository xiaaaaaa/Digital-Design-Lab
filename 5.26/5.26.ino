#include "pitches.h"
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 A5
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0

#define BUTTON 2

int melody1[] = {
  NOTE_A3, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4 , NOTE_E4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4
};
int noteDurations1[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 2
};
int melody2[]={
  NOTE_A3, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4 , NOTE_B3
};
int noteDurations2[] = {
  4, 4, 1, 4, 2, 2, 1
};
const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};
  
byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};


byte sus[8][8] = {
  {1,1,1,0,0,0,1,1},
  {1,1,0,1,1,1,0,1},
  {0,0,0,1,0,0,0,0},
  {0,1,0,1,0,0,0,0},
  {0,1,0,1,1,1,0,1},
  {0,0,0,1,0,1,0,1},
  {1,1,0,1,0,1,0,1},
  {1,1,0,0,1,0,0,1}};


byte meow[8][8] = {
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,1,1,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0}};

int melodyNumber=0;
byte previousState=1, presentState=1; //patternNumber=0;
unsigned long tb=0, tn=0;


void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]);  
    }
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], HIGH);
      digitalWrite(col[j], LOW);  
    }
  }
}

void setup()
{
  Serial.begin(9600);
  for (byte i = 0; i <= sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i <= sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }  
  pinMode(2,INPUT_PULLUP);
  
}

void loop()
{ 
  //myTime = millis();

  if(melodyNumber==0){
    for(int thisNote = 0; thisNote < 11; thisNote++){
          int noteDuration = 1000 / noteDurations1[thisNote];
          tone(9, melody1[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          while(tn-tb<pauseBetweenNotes){
            tn=millis();
            showPattern(sus);
          }
          tb=tn;
          noTone(9);
          presentState=digitalRead(2);
          if(presentState==0 && previousState==1){
            melodyNumber++;
            thisNote=11;
          }
          previousState=presentState;
    }
  }

  if(melodyNumber == 1){
     for(int thisNote = 0; thisNote < 7; thisNote++){
            int noteDuration = 1000 / noteDurations2[thisNote];
            tone(9, melody2[thisNote], noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            while(tn-tb<pauseBetweenNotes){
              tn=millis();
              showPattern(meow);
            }
            tb=tn;
            noTone(9);
            presentState=digitalRead(2);
            if(presentState==0 && previousState==1){
              melodyNumber--;
              thisNote=7;
            }
            previousState=presentState;
      }
   }
}
