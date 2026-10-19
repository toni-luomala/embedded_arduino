// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // for loop kiertää kolme kertaa, jonka
  // jälkeen tullaan pois loopista ja lamput
  // syttyvät yhtäaikaa
  for (int i = 0; i < 3; i++) {
  digitalWrite(2, HIGH);
  delay(300); // Odota 300 millisekuntia
  digitalWrite(2, LOW);
  delay(300); // Odota 300 millisekuntia
  }
  
  digitalWrite(2, HIGH); // Kaikki ledit päälle
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(300); // Odota 300 millisekuntia
  digitalWrite(2, LOW); // Kaikki ledit pois päältä
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(300); // Odota 300 millisekuntia
}