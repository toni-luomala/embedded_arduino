// C++ code
//
int laskuri = 0;  // alustetaan laskurille muuttuja
int edellinen_laskuri = 0; // laskurin apumuuttuja
int painike = 0; // painikkeen tila alustettu muuttujaan

void setup()
{
  pinMode(3, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); // avataan portti
  attachInterrupt(digitalPinToInterrupt(3), incrementNumber, RISING);
}
 
void loop()
{
  painike = digitalRead(3); // luetaan pinni 3 muuttujaan
  if (laskuri != edellinen_laskuri) { // numero tulostetaan vain jos se on eri kuin viimeinen 
    Serial.print("Laskuri: ");
 	Serial.println(laskuri);
    edellinen_laskuri = laskuri;  // edellinen numero apumuuttujaan
  }
  
  if (laskuri%2 != 0) { // jakojäännöksen avulla selvitetään parillisuus
    digitalWrite(12, HIGH); // jos luku on pariton led syttyy
  }
  else {
    digitalWrite(12, LOW); // jos luku on parillinen led sammuu
  }
}

void incrementNumber(){
  laskuri++; // laskurin arvoa kasvatetaan yhdellä
}