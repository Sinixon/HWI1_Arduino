// Naam geven / led connecton 
int led = 11;
int pushButton = 5;

// de setup beginnen met de knop
void setup() {

  Serial.begin(9600);
  pinMode(pushButton, INPUT);
    pinMode(led, OUTPUT);

}

// de loop runt over en over
void loop() {
  
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  if (buttonState == 1) {
      digitalWrite(led, HIGH);   // led aan zetten
  } else {
    digitalWrite(led, LOW);    // led uit zetten
  }
  delay(1);        // delay in between reads for stability
  
  

  
}
