// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);  // Sytytä ledi
  delay(300); // Odota 300 millisekuntia
  digitalWrite(2, LOW);  // Sammuta ledi
  digitalWrite(3, HIGH);
  delay(300); // Odota 300 millisekuntia
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(300); // Odota 300 millisekuntia
  digitalWrite(4, LOW);
}