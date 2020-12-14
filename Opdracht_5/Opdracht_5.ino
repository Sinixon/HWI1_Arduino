//Opdracht 5
#define BLUE 4 //BLUE variabele op poort 4 aanmaken
#define GREEN 3 //GREEN variabele op poort 3 aanmaken
#define RED 2 //RED variabele op poort 2 aanmaken

int redC; //teller variabele aanmaken voor rood
int greenC; //teller variabele aanmaken voor groen
int blueC; //teller variabele aanmaken voor blauw

//functie setup aanspreken
void setup() {
  pinMode(BLUE, OUTPUT); //zorgen dat de blauwe poort op output staat
  pinMode(GREEN, OUTPUT); //zorgen dat de groene poort op output staat
  pinMode(RED, OUTPUT); //zorgen dat de rode poort op output staat

  digitalWrite(BLUE, LOW);  //blauwe lamp uitzetten bij aanvang
  digitalWrite(GREEN, LOW); //groene lamp uitzetten bij aanvang
  digitalWrite(RED, LOW);  //rode lamp uitzetten bij aanvang
}


//functie loop aanspreken
void loop() {
  for (int y = 0; y < 255; y++) { //for loopje om van waarde 255 naar 0 te gaan van groene lampje
    greenC -= 1;
    blueC += 1;
    analogWrite(GREEN, greenC); //groene waarde aanspreken middels analogWrite
    analogWrite(BLUE, blueC); //blauwe waarde aanspreken middels analogWrite
    delay(5); //5 miliseconde wachten
  }
  //alles hierboven idem voor blauwe lampje
  for (int y = 0; y < 255; y++) {
    blueC -= 1;
    redC += 1;
    analogWrite(BLUE, blueC);
    analogWrite(RED, redC);
    delay(5);
  }
  //alles hierboven idem voor rode lampje
  for (int y = 0; y < 255; y++) {
    redC -= 1;
    greenC += 1;
    analogWrite(RED, redC);
    analogWrite(GREEN, greenC);
    delay(5);
  }
}
