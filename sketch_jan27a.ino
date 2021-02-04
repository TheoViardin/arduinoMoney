#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

int CAPTEUR_PIN = A0;
int CAPTEUR2_PIN = 2;

// valeur capteur distance
float DEUX_EURO = 430; // 253 - 260
float UN_EURO = 470; // 470
float CINQUANTE_CENT = 470; // 470
float VINGT_CENT = 470; // 480
float DIX_CENT = 500;// 500
float CINQ_CENT = 590;// 590
float DEUX_CENT = 605;// 605
float UN_CENT = 540;// 640

int nbDeuxEuro = 0;
int nbUnEuro = 0;
int nbCinquanteCentime = 0;
int nbVingtCentime = 0;
int nbDixCentime = 0;
int nbCinqCentime = 0;
int nbDeuxCentime = 0;
int nbUnCentime = 0;
  
float montant = 0;

void setup()
{
  pinMode(CAPTEUR_PIN, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int valeurCapteur = analogRead(CAPTEUR_PIN);

  if (valeurCapteur >= DEUX_EURO - 10 && valeurCapteur <= DEUX_EURO + 10) {
    nbDeuxEuro++;
  }/* else if (valeurCapteur >= UN_EURO - 10 && valeurCapteur <= UN_EURO + 10) {
    nbUnEuro++;    
  } else if (valeurCapteur >= CINQUANTE_CENT - 10 && valeurCapteur <= CINQUANTE_CENT + 10) {
    nbCinquanteCentime++;    
  }*/ else if (valeurCapteur >= VINGT_CENT - 10 && valeurCapteur <= VINGT_CENT + 10) {
    nbVingtCentime++;
  }/* else if (valeurCapteur >= DIX_CENT - 10 && valeurCapteur <= DIX_CENT + 10) {
    nbDixCentime++;
  } else if (valeurCapteur >= CINQ_CENT - 10 && valeurCapteur <= CINQ_CENT + 10) {
    nbCinqCentime++;
  } else if (valeurCapteur >= DEUX_CENT - 10 && valeurCapteur <= DEUX_CENT + 10) {
    nbDeuxCentime;
  }*/ else if (valeurCapteur >= UN_CENT - 10 && valeurCapteur <= UN_CENT + 10) {
    nbUnCentime++;
  }
  
  montant = 2 * nbDeuxEuro;
  montant += 1 * nbUnEuro;
  montant += 0.5 * nbCinquanteCentime;
  montant += 0.2 * nbVingtCentime;
  montant += 0.1 * nbDixCentime;
  montant += 0.05 * nbCinqCentime;
  montant += 0.02 * nbDeuxCentime;
  montant += 0.01 * nbUnCentime;
  
  Serial.println(digitalRead(CAPTEUR2_PIN));
  
  lcd.setCursor(0, 0);
  lcd.print(montant);
  lcd.setCursor(0, 1);
  lcd.print(valeurCapteur);
  delay(500);
}
