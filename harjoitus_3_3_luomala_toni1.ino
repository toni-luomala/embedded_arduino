// C++ code
//
float mitattu_ADC = A0; // ADC lukema tmp sensorista mitattuna
float viimeisin_ADC = 0; // apumuuttuja
float avgADC = 0; / // keskiarvo
float LT = 0; // lämpötila
bool mitattu = false; // mitattu alkuarvona false
int switchState = 0; // painikkeen tila alustettu muuttujaan

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600); // avataan portti
  // nappia painettaessa keskeytysrutiini triggeröityy
  // laskut tehdään laskeLampotila funktiossa
  attachInterrupt(digitalPinToInterrupt(2), laskeLampotila, RISING);
}
 
void loop()
{
  switchState = digitalRead(2); // luetaan pinni 2 muuttujaan
  if (mitattu == true) { // printataan tulokset kun mitattu
  Serial.print("ADC: ");
  Serial.print(avgADC);
  Serial.print(" ");
  Serial.print("lt: ");
  Serial.println(LT);
  mitattu = false; // estetään tulostaminen useasti
  }
}
void laskeLampotila(){
  for (int i = 0; i <= 50; i++ ) {
  viimeisin_ADC += analogRead(mitattu_ADC); // lisätään lukemaa joka kierroksella
  delay(20); // odota 20 millisekuntia
  }
  avgADC = viimeisin_ADC / 50; // lasketaan keskiarvo
  LT = ((5 * avgADC / 1024.0)- 0.5) * 100; // kaava lämpötilan laskemiseen
  viimeisin_ADC = 0; // nollataan mitattu arvo, jotta se ei kertaannu nappia painettaessa
  mitattu = true;
}