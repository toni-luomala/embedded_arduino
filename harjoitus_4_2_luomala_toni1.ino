// C++ code
//
#include <EEPROM.h>

int nappi3 = 4;
int nappi2 = 3;
int nappi1 = 2;
int eeprom_muisti;
int eeprom_lue;
int painikkeen3_tila = 0; // alustetaan painikkeen tila
int painikkeen2_tila = 0; // alustetaan painikkeen tila
int laskuri = 0;// alustetaan laskuri
int i = 1;// kirjoitettava arvo
volatile bool tyhjenna = false;
volatile bool lue = false;

void setup()
{
  pinMode(nappi3, INPUT);
  pinMode(nappi2, INPUT);
  Serial.begin(9600); // avataan sarjaportti
  attachInterrupt(digitalPinToInterrupt(3), tyhjennaMuisti, RISING);
  attachInterrupt(digitalPinToInterrupt(nappi1), lueMuisti, RISING);
}

 
void loop()
{
  painikkeen3_tila = digitalRead(nappi3);
  if 
(painikkeen3_tila == LOW) {
    EEPROM.write(laskuri, i); // kirjoittaa muistipaikkaan laskuri arvon i
    Serial.println(laskuri);
    laskuri++; // muistipaikan lukua lisätään jokaisella kierroksella
    i++;// muistipaikan arvoa lisätään jokaisella kierroksella
    delay(500); // viive napin painalluksen jälkeen
  }

   if (tyhjenna) {
	 Serial.println("Tyhjennetään EEPROM ....");
	// käydään kaikki muistipaikat läpi
     for (int osoite = 0; osoite < EEPROM.length(); osoite++)
     {
     EEPROM.write(osoite, 0);
     Serial.println(EEPROM.read(laskuri));
     }
     Serial.println("EEPROM on tyhjä");
     delay(500);
    // nollataan laskuri
    laskuri = 0;
     i =0;
    tyhjenna = false; //estetään jatkuva looppi
  }
  
  if (lue) {
    // luetaan EEPROMIN muistin pituuden mukaan arvot
    for (int osoite = 0; osoite < EEPROM.length(); osoite++)
    {
      eeprom_lue = EEPROM.read(laskuri); // luetaan eepromin arvo
      Serial.println(eeprom_lue);
    }
  }
  lue = false;
}

  void tyhjennaMuisti() {
 	tyhjenna = true;
 	}

  void lueMuisti() {
    lue = true;
    }