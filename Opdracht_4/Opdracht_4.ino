//opdracht 4
const int tempPin = A5; //instancieren van de LM35 op de analoge ingang A5
float temperatureCount = 0; //startwaarde van de temperatuur counter op 0 zetten

//functie setup aanspreken
void setup() {
  Serial.begin(9600); //serial laten starten met begin functie
}

void loop() {
  temperatureCount = analogRead(tempPin); //temperatuurwaarde aflezen van de temperatuurPin
  temperatureCount = temperatureCount * 0.48828125; //graden celcius berekenen
  Serial.print("Temperatuur in graden Celcius = "); //temperatuur laten zien op de seriele monitor
  Serial.println(temperatureCount); //temperatuur laten zien op de seriele monitor
  delay(1000); //1 seconden wachten met opnieuw printen
}
