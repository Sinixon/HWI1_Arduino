int pinArrayList[]={13,12,11,10,9,8,7,6};// aanmaken van de constante variabelen zodat elke ledPin een nummer heeft op volgorde van de poorten <ik heb poort 6-13 gebruikt> 

void setup() {
  // in de setup zorg ik ervoor dat de constante die ik hierboven heb aangemaakt via de functie pinmode een gedrag krijgt.
  // wij willen output van de pin hebben (licht) dus vandaar dat ik output als parameter meegeef.
  for (int y = 0; y <= 8; y++) { //for loop om de LED's die in de array zitten op pinMode OUTPUT te zetten
    pinMode(pinArrayList[y],OUTPUT);
  }
}

void loop() {
  // functie voorWaarts aanspreken en als parameter 6 meegeven. 
  // deze 6 staat voor de constante ledPin 8.
  voorWaarts(6); 
}


int voorWaarts(int ledPin) {
  // deze functie gaat ervoor zorgen dat de lampjes voorwaarts aangaan.
  if (ledPin < 14) { // 
    digitalWrite(ledPin, HIGH); // lampje op nummer constante ledPin gaat aan
    delay(50); // vertraag 50 milliseconde
    digitalWrite(ledPin, LOW); // lampje op nummer constante ledPin gaat uit
    delay(50); // vertraag 50 milliseconde
    ledPin++; // doe de constante ledPin met 1 verhogen
    return voorWaarts(ledPin); // voer dezelfde functie uit met de verhoogte ledPin
  } else { // als de constante boven de 13 komt -> doe dan het volgende
      achterWaarts(ledPin); // voer de functie achterWaarts uit en geef de constante ledPin mee
    }
 }

 int achterWaarts(int ledPin) {
  if (ledPin > 5) { // als de constante ledPin onder de 14 is moet het volgende uitgevoerd worden: 
      digitalWrite(ledPin, HIGH); // lampje op nummer constante ledPin gaat aan
      delay(50); // vertraag 50 milliseconde
      digitalWrite(ledPin, LOW); // lampje op nummer constante ledPin gaat uit
      delay(50); // vertraag 50 milliseconde
      ledPin--; // doe de constante ledPin met 1 verlagen
      return achterWaarts(ledPin); // voer dezelfde functie uit met de verlaagde ledPin
    } else { // als de constante lager dan 6 komt -> doe dan het volgende
        return voorWaarts(ledPin); // voer de functie voorWaarts uit en geef de constante ledPin mee
      }
  }
