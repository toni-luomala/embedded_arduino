// C++ code
//


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
float mitattu_ADC = A0; // ADC lukema tmp sensorista mitattuna
float viimeisin_ADC = 0; // apumuuttuja
float avgADC = 0; // keskiarvo
float LT = 0; // lämpötila
bool painike_painettu = false; // painike painettu alkuarvona false

void setup() {
 pinMode(2, INPUT_PULLUP);
 lcd.begin(16, 7);
 pinMode(switchPin,INPUT);
 
 lcd.print("Ask the");
 lcd.setCursor(0, 1);
 lcd.print("Crystal Ball!");
 attachInterrupt(digitalPinToInterrupt(2), painikeInt, RISING);
}

void loop() {
 switchState = digitalRead(switchPin);
 if (switchState != prevSwitchState) {
 if (switchState == LOW) {
 reply = random(8);

 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("The ball says:");
 lcd.setCursor(0, 1);
 switch(reply){
 case 0:
 lcd.print("Yes");
 break;
 case 1:
 lcd.print("Most likely");
 break;
 case 2:
 lcd.print("Certainly");
 break;
 case 3:
 lcd.print("Outlook good");
 break;
 case 4:
 lcd.print("Unsure");
 break;
 case 5:
 lcd.print("Ask again");
 break;
 case 6:
 lcd.print("Doubtful");
 break;
 case 7:
 lcd.print("No");
 break;
 }
 }
 }
 prevSwitchState = switchState;
}

void painikeInt() {
painike_painettu = true;
laskeLampotila(); // kutsutaan funktiota kun painiketta on painettu
}
void laskeLampotila(){
  // for looppi pyörähtää 50 kertaa
  for (int i = 0; i < 50; i++ ) {
  viimeisin_ADC += analogRead(mitattu_ADC); // lisätään lukemaa joka kierroksella
  delay(20); // odota 20 millisekuntia
  }
  avgADC = viimeisin_ADC / 50; // lasketaan keskiarvo
  LT = ((5 * avgADC / 1024.0)- 0.5) * 100; // kaava lämpötilan laskemiseen
  viimeisin_ADC = 0; // nollataan mitattu arvo, jotta se ei kertaannu nappia painettaessa
  lcd.clear();
  lcd.print("Temp is now:");
  lcd.setCursor(0,1); // rivinvaihto
  lcd.print(LT); // lämpötilan printtaus
  painike_painettu == false;
  delay(500); 
}