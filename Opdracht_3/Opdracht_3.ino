//opdracht 3
const int potmeterPin = A5; //instancieren van de potmeterPin op de analoge ingang A5
int pinArrayList[] = {2, 3, 4, 5, 6, 7, 8}; //array maken van de poorten waarop de LED's zijn aangesloten
int potmeterWaarde = 0; //potmeterWaarde instancieren en op 0 zetten om mee te beginnen
int x = 0; //variable x aanmaken, deze is later nodig als teller


//functie setup aanspreken
void setup() {
  for (int y = 0; y <= 8; y++) { //for loop om de LED's die in de array zitten op pinMode OUTPUT te zetten
    pinMode(pinArrayList[y],OUTPUT);
  }
}


//functie loop aanspreken
void loop() {
  potmeterWaarde = map(analogRead(potmeterPin), 0, 1023, -1, 7); //potmeterWaarde map functie aanspreken om de verdeling van de potmeter goed te zetten.
                                                                 //De -1 is zodat alle lampjes uit zijn wanneer de potmeter helemaal uit staat. 7 zodat alle LED's aanstaan bij potmeter helemaal aan
  if (x < potmeterWaarde) { //if statement om de LED's 1 voor 1 aan de laten gaan met output HIGH
    digitalWrite(pinArrayList[x], HIGH);
    x++;
  }
  if (x > potmeterWaarde) { //if statement om de LED's 1 voor 1 uit te laten met output LOW
    digitalWrite(pinArrayList[x], LOW);
    x--;
  }
}
