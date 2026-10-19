// C++ code
//
void setup()
{
  pinMode(3, INPUT);
  pinMode(12, OUTPUT);
  
 
}
 int switchState = 0; // painikkeen tila alustettu muuttujaan
void loop()
{
  switchState = digitalRead(3); // painikkeen tila luettuna portista
  if (switchState == LOW) // LOW = Painike alhaalla
  {
  digitalWrite(12, HIGH); // HIGH = Painike ylhäällä
  }
  else {
  digitalWrite(12, LOW);
  };
  // HIGH ja LOW tilat on nyt vähän epäloogisesti suhteessa lediin,
  // koska jos painike on HIGH silloin led on LOW
}