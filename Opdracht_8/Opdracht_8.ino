// opdracht 8
#include<IRremote.h>
decode_results decodeResults; //decode results van de remote
unsigned long timePassed = 0; //tijd die verstreken is
int memoryA = 0; //memory om later te gebruiken
int memoryB = 0;//memory om later te gebruiken
int x = 0; //counter voor later

int IRsensor = 10; //IRsensor op poort 10 instancieren
int pinArrayList[]={6, 7, 8, 9};// aanmaken van de constante variabelen zodat elke ledPin een nummer heeft op volgorde van de poorten <ik heb poort 6-9 gebruikt> 
IRrecv irReveicer(IRsensor); // IR sensor aan IR recveiver koppelen

//de remote die ik heb gebruikt is samsung (!)
long int Button1 = 3772784863; //knop 1 op remote
long int Button2 = 3772817503; //knop 2 op remote
long int Button3 = 3772801183; //knop 3 op remote
long int Button4 = 3772780783; //knop 4 op remote
long int Button5 = 3772813423; //knop 5 op remote

//setup functie aanspreken
void setup() {
  Serial.begin(9600); //printen van serial in seriele monitor
  irReveicer.enableIRIn(); //functie om input te geven aan IR remote

  for (int y = 0; y <= 4; y++) { //for loop om de LED's die in de array zitten op pinMode OUTPUT te zetten
    pinMode(pinArrayList[y],OUTPUT);
  }
}

//functie loop aanspreken
void loop() {
  int LED1 = digitalRead(pinArrayList[0]); //status uitlezen en opslaan in variabele van eerste LED
  int LED2 = digitalRead(pinArrayList[1]); //status uitlezen en opslaan in variabele van tweede LED
  int LED3 = digitalRead(pinArrayList[2]); //status uitlezen en opslaan in variabele van derde LED
  int LED4 = digitalRead(pinArrayList[3]); //status uitlezen en opslaan in variabele van vierde LED

  if (irReveicer.decode(&decodeResults)) { 
    Serial.println(decodeResults.value); //resultaat van ingedrukte knop op remote printen
    irReveicer.resume(); //verdergaan
    if (x < 2) { //wanneer de count X kleiner is dan 2 dan moet het volgende gebeuren
      if (decodeResults.value == Button1 && LED1 == LOW) { //ingetoetste signaal toetsen aan knop1, 2, 3, 4 waarde en setMemory aanspreken bij juiste knop met waarde.
        setMemory(pinArrayList[0]); //memory op LED1 zetten
      } else if (decodeResults.value == Button2 && LED2 == LOW) {
        setMemory(pinArrayList[1]); //memory op LED2 zetten
      } else if (decodeResults.value == Button3 && LED3 == LOW) {
        setMemory(pinArrayList[2]); //memory op LED3 zetten
      } else if (decodeResults.value == Button4 && LED4 == LOW) {
        setMemory(pinArrayList[3]); //memory op LED3 zetten
      } else if (decodeResults.value == Button5) { //deze knop dient als reset knop
        digitalWrite(memoryA, LOW); //LED uit
        digitalWrite(memoryB, LOW); //LED uit
        int memoryA = 0; //reset
        int memoryB = 0; //reset
        int x = 0; //reset
        
      }
    }
  }
  if (x == 2) { //wanneer de count X gelijk is aan 2 dan moet het volgende gebeuren (knipper snelheid aanpassen)
    if (decodeResults.value == Button1) { //ingetoetste signaal toetsen aan knop1, 2, 3, 4 waarde en flashSpeed aanspreken bij juiste knop met parameter flashSpeed
      flashSpeed(100);
    } else if (decodeResults.value == Button2) {
      flashSpeed(200);
    } else if (decodeResults.value == Button3) {
      flashSpeed(300);
    } else if (decodeResults.value == Button4) {
      flashSpeed(400);
    }
  }
}

//functie flashSpeed
void flashSpeed(int flashSpeed) {
  //eerst moeten we de memories uitlezen en opslaan in een variabele
  int memoryAsave = digitalRead(memoryA);
  int memoryBsave = digitalRead(memoryB);
  unsigned long timeNow = millis(); //huidige tijd opslaan in een variabele om een if statement te maken
  if (timeNow - timePassed >= flashSpeed) { // als de huidige tijd min de verstreken tijd groter of gelijk is aan de flashSpeed
    timePassed = timeNow; //verstreken tijd op huidige tijd zetten
    if (memoryAsave == LOW && memoryBsave == LOW) { //als deze variabelen LOW teruggeven doe dan het volgende
      digitalWrite(memoryA, HIGH); //output op HIGH zetten
      digitalWrite(memoryB, HIGH); //output op HIGH zetten
    } else { // anders
      digitalWrite(memoryA, LOW); //output op LOW zetten
      digitalWrite(memoryB, LOW); //output op LOW zetten
    }
  }
}


//functie setMemory die de ingedrukte knoppen gaat opslaan
void setMemory(int intLED) {
  digitalWrite(intLED, HIGH); //output van ingedrukte knop op HIGH zetten
  if (memoryA == 0) { // Bij memory op 0 doe dan
    memoryA = intLED; //memoryA op meegegeven parameter zetten
    x++; // counter met 1 verhogen
  } else { //anders
    memoryB = intLED; //memoryB op meegegeven parameter zetten
    x++; // counter met 1 verhogen
  }
}
