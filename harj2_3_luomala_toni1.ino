// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Avataan portti
}

void loop()
{
  digitalWrite(2, HIGH); // Kaikki ledit päälle
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  Serial.println("LED ON"); // Tulostetaan porttiin
  delay(2000); // Odota 2000 millisekuntia
  digitalWrite(2, LOW); // Kaikki ledit pois päältä
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  Serial.println("LED OFF"); // Tulostetaan porttiin
  delay(2000); // Odota 2000 millisekuntia
 }
