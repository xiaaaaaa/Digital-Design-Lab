#include "pitches.h"

// notes in the melody:
int melody1[] = {
  NOTE_A3, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4 , NOTE_E4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 2
};
int melody2[]={
  NOTE_A3, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4 , NOTE_B3
};
int noteDurations2[] = {
  4, 4, 1, 4, 2, 2, 1
};
int melodyNumber=0;
bool previousState=1,presentState=1;
int ledState;

int ledPin[]={
  2, 3, 4, 5, 6, 7, 8
};

void setup() {
  // iterate over the notes of the melody:
  pinMode(9,INPUT_PULLUP);
  for(int thisLed=0; thisLed<8; thisLed++){
    pinMode(ledPin[thisLed], OUTPUT);
  }
}


void loop() {
  // no need to repeat the melody.

  if(melodyNumber==0){
      for (int thisNote = 0; thisNote < 11; thisNote++){
            // to calculate the note duration, take one second divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / noteDurations1[thisNote];
          tone(10, melody1[thisNote], noteDuration);


          if(melody1[thisNote]==NOTE_A3){
            digitalWrite(ledPin[0], HIGH);
            ledState=ledPin[0];
          }
          else if(melody1[thisNote]==NOTE_B3){
            digitalWrite(ledPin[1], HIGH);
            ledState=ledPin[1];
          }
          else if(melody1[thisNote]==NOTE_C4){
            digitalWrite(ledPin[2], HIGH);
            ledState=ledPin[2];
          }
          else if(melody1[thisNote]==NOTE_D4){
            digitalWrite(ledPin[3], HIGH);
            ledState=ledPin[3];
          }
          else if(melody1[thisNote]==NOTE_E4){
            digitalWrite(ledPin[4], HIGH);
            ledState=ledPin[4];
          }
          else if(melody1[thisNote]==NOTE_G4){
            digitalWrite(ledPin[5], HIGH);
            ledState=ledPin[5];
          }
          else if(melody1[thisNote]==NOTE_A4){
            digitalWrite(ledPin[6], HIGH);
            ledState=ledPin[6];
          }
    
            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(10);

          digitalWrite(ledState, LOW);

          
          presentState=digitalRead(9);
          if(presentState==0&&previousState==1){
              melodyNumber++;
              thisNote=11;
          }
          previousState=presentState;
      }
  }
  if(melodyNumber==1){
    for (int thisNote = 0; thisNote < 7; thisNote++){
      // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations2[thisNote];
      tone(10, melody2[thisNote], noteDuration);

      if(melody2[thisNote]==NOTE_A3){
            digitalWrite(ledPin[0], HIGH);
            ledState=ledPin[0];
          }
          else if(melody2[thisNote]==NOTE_B3){
            digitalWrite(ledPin[1], HIGH);
            ledState=ledPin[1];
          }
          else if(melody2[thisNote]==NOTE_C4){
            digitalWrite(ledPin[2], HIGH);
            ledState=ledPin[2];
          }
          else if(melody2[thisNote]==NOTE_D4){
            digitalWrite(ledPin[3], HIGH);
            ledState=ledPin[3];
          }
          else if(melody2[thisNote]==NOTE_E4){
            digitalWrite(ledPin[4], HIGH);
            ledState=ledPin[4];
          }
          else if(melody2[thisNote]==NOTE_G4){
            digitalWrite(ledPin[5], HIGH);
            ledState=ledPin[5];
          }
          else if(melody2[thisNote]==NOTE_A4){
            digitalWrite(ledPin[6], HIGH);
            ledState=ledPin[6];
      }


      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(10);

      digitalWrite(ledState, LOW);
      
      presentState=digitalRead(9);
      if(presentState==0&&previousState==1){
        melodyNumber--;
        thisNote=7;
      }
      previousState=presentState;
    }
  }
}
