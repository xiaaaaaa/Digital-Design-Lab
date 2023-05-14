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

void setup() {
  // iterate over the notes of the melody:
  pinMode(9,INPUT_PULLUP);
}

void loop() {
  // no need to repeat the melody.

  if(melodyNumber==0){
      for (int thisNote = 0; thisNote < 11; thisNote++){
            // to calculate the note duration, take one second divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / noteDurations1[thisNote];
          tone(8, melody1[thisNote], noteDuration);
    
            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(8);
          
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
      tone(8, melody2[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      presentState=digitalRead(9);
      if(presentState==0&&previousState==1){
        melodyNumber--;
        thisNote=7;
      }
      previousState=presentState;
    }
  }
}
