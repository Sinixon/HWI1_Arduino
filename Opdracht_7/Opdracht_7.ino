// opdracht 7
#include<Servo.h>
const int triggerPin = 13; //triggerPin van sensor op poort 13 zetten
const int echoPin = 3; //echoPin van sensor op poort 3 zetten
Servo servoMotor; //servoMotor aanmaken
int pos = 0; //positieteller aanmaken
float timePassed; //tijd die nodig is
float distance; //afstand van voorwerp

int convertToDistance = 58;
int maxDistance = 10;
int minDistance = 4;

//functie setup aanspreken
void setup() {
  servoMotor.attach(9); //servo op poort 9 instancieren
  pinMode(triggerPin, OUTPUT); //we verwachten output van triggerPin
  pinMode(echoPin, INPUT); //we verwachten input van echoPin
}

//functie loop aanspreken
void loop() {
  digitalWrite(triggerPin, LOW); //triggerPin op LOW zetten
  delay(50); //kleine delay
  digitalWrite(triggerPin, HIGH); //triggerPin op HIGH zetten (aan)
  delay(50); //kleine delay
  digitalWrite(triggerPin , LOW); //triggerPin op LOW zetten
  timePassed = pulseIn(echoPin, HIGH); // variabele timePassed vullen met input van de echoPin
  distance = timePassed / convertToDistance;  //tijd die passed is door de convertToDistance variabele delen voor afstand in cm
  delay(50); //kleine delay
  if (distance <= maxDistance && distance >= minDistance) { // alleen bij een afstand tussen 10 en 4 willen we iets doen
    int positionObject = map(Afstand, 4, 10, 180, 0); //afstand tussen 10 en 4 een bepaalde stand voor de servoMotor geven en opslaan in variabele
    servoMotor.write(positionObject); //die stand doorsturen naar servomotor
    delay(50); //kleine delay
  }
}
