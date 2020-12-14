// opdracht 6
#include<Servo.h>
int Positie = 0; //variabele voor positie als teller aanmaken en op 0 zetten
int switchPin = 5; //instancieren van drukknop 1 op poort 5
int switchPin2 = 6; //instancieren van drukknop 2 op poort 5
int druknop1 = LOW; //drukknop1 variabele aanmaken en deze op LOW zetten
int druknop2 = LOW; //drukknop2 variabele aanmaken en deze op LOW zetten
Servo servo; //servo instancieren

//functie setup aanspreken
void setup() {
  pinMode(switchPin, INPUT); // zorgen dat drukknop 1 input verwacht
  pinMode(switchPin2, INPUT); // zorgen dat drukknop 2 input verwacht
  servo.attach(7); //servo op poort 7 zetten
}

//functie loop aanspreken
void loop() {
  int drukknop1 = digitalRead(switchPin); //waardes van drukknop1 uitlezen
  int drukknop2 = digitalRead(switchPin2); //waardes van  drukknop2 uitlezen
  servo.write(0); //zorgen dat de servo niks doet als er niks gebeurd
  
  if (drukknop1 == HIGH && drukknop2 == LOW) { //if statement voor wanneer drukknop 1 ingedrukt
    servoSpin(8,0); //functie servoSpin aanspreken met 8 en 0 als parameters. Zo gaat hij in 1 sec heen en terug
  }
  
  if (drukknop1 == LOW && drukknop2 == HIGH) { //if statement voor wanneer drukknop 1 ingedrukt
    servoSpin(4,0); //functie servoSpin aanspreken met 4 en 0 als parameters. Zo gaat hij in 0.5 sec heen en terug
  }
  
  if (drukknop1 == HIGH && drukknop2 == HIGH) { //if statement voor wanneer beide drukknoppen zijn ingedrukt
    servoSpin(8, 2000); //functie servoSpin aanspreken met 8 en 2000 als parameters. Zo gaat hij in 1 sec heen, wacht 2 seconden en gaat weer in 1 sec terug
  }
}

//functie servoSpin aanspreken
 void servoSpin(int vertraging, int wait) { //parameters vertraging en wait zijn nodig
   for (Positie = 0; Positie <= 120; Positie +=1){ //positie naar 120 laten gaan met for loop
    servo.write(Positie); //op laten lopen van de positie
    delay(vertraging); //delay op de servoMotor
  }
   delay(wait); //delay voordat het terugdraaien
   for (Positie = 120; Positie >= 0; Positie -=1){ //deze for loop werkt hetzelfde als hierboven maar is voor het terugdraaien
    servo.write(Positie);
    delay(vertraging);
   }
 }
