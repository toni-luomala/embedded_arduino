// C++ code
//
#include <EEPROM.h>

int nappi3 = 4;
int eeprom_muisti;
int painikkeen_tila = 0; // alustetaan painikkeen tila
int laskuri = 0;// alustetaan laskuri
int i = 1;// kirjoitettava arvo 

void setup()
{
  pinMode(nappi3, INPUT);
  Serial.begin(9600); // avataan sarjaportti
}
 
void loop()
{
  painikkeen_tila = digitalRead(nappi3);
  if (painikkeen_tila == LOW) {
    EEPROM.write(laskuri, i); // kirjoittaa muistipaikkaan laskuri arvon i
    laskuri++; // muistipaikan lukua lisätään jokaisella kierroksella
    i++;// muistipaikan arvoa lisätään jokaisella kierroksella
    delay(500); // viive napin painalluksen jälkeen
  }
}
