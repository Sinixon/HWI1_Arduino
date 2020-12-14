//opdracht 9
char readSerial = 0;
const int greenLED = 2; //dit is het groene licht
const int orangeLED = 3; //dit is het oranje licht
const int redLED = 4; //dit is het rode licht

//functie setup aanspreken
void setup() {
  Serial.begin(9600); //seriele monitor opstarten 
  pinMode(greenLED, OUTPUT); //alle ingangen verwachten we outputs
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

//functie loop aanspreken
void loop() {
  if (Serial.available() > 0) { //output op de seriele monitor tonen
    readSerial = Serial.read();  
    Serial.println(readSerial);       
  }
  if (readSerial == 's')  {        // wanneer waarde s gevonden wordt het volgende doen
    digitalWrite(redLED, HIGH); //dit is bij de opdracht het volgende gedeelte: Als het stoplicht wordt aangezet zal deze 12 sec. op rood staan, 6 sec. op oranje en 12sec. op groen.
    delay(12000); //wacht 12 seconden met rood licht
    digitalWrite(redLED, LOW); //zet rood licht uit
    digitalWrite(orangeLED, HIGH); //zet oranje aan
    delay(60000); // 6 seconden wachten
    digitalWrite(orangeLED, LOW); //zet oranje licht uit
    digitalWrite(greenLED, HIGH); //zet groen licht aan
    delay(12000); // 12 seconden wachten
    digitalWrite(greenLED, LOW); //zet groen licht uit
  } else { //dit is bij de opdracht het volgende gedeelte: Is het stoplicht via de telefoon niet ingeschakeld zal deze oranje knipperen (1 sec. aan / 1 sec. uit).
    digitalWrite(greenLED, LOW); //alle lichten uitzetten
    digitalWrite(redLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(orangeLED, HIGH); //oranje licht aanzetten
    delay(1000); //wacht 1 seconden
    digitalWrite(orangeLED, LOW); //zet oranje licht uit
    delay(1000); //wacht 1 seconden
  }
}
