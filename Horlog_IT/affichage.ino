
// inclusion de la librairie Liquid Crystal pour le controle LCD
#include <LiquidCrystal.h>

// declaration des Broches de l'ecran LCD 
LiquidCrystal LCD(11,10,5,4,3,2);
const int AlimSupLCD = 22;


//////////////////////////////////////////////////////
//  Initialisation de l'ecran LCD

void IniLCD()
{
   //Initialisation de l'ecran LCD
  pinMode(AlimSupLCD, OUTPUT); // initalisation, de la broche d'alim sup
  digitalWrite(AlimSupLCD, HIGH); //on allume l'ecran
  LCD.begin(16,2); // initialisation de la taille de l'ecran, en bloc de 8 trame de 5bits
  LCD.home();  //on met le curseur en haut à gauche
  LCD.print("Initialisation");  // on affiche a l'ecran "initialisation en cours" sur 2 line
  LCD.setCursor(0,1);
  LCD.print("En Cours");
  
}
///////////////////////////////////////
//  fonction Clear de l'ecran

void affClear()
{
    // on enleve se qui etait afficher
   LCD.clear();
}

////////////////////////////////////////
// affichage reglage

void affReglage()
{

  LCD.home();
  LCD.print("Reglage");
  LCD.setCursor(0,1);
}
//////////////////////////////////////
// Affichage de l'horloge

void affTemps()
{
  char message[16] = "";
   LCD.home();
   sprintf(message,"%2d:%2d:%2d", heures,minutes,secondes);
   LCD.write(message);
}

///////////////////////////////////////////////////
//    Creation du Logo Phenix it 

void IniLogo()      
{
  byte IA[8] = {
    B00000,
    B00001,
    B00011,
    B00110,
    B01100,
    B11100,
    B11000,
    B11100,  };
    
  byte IB[8] = {
    B01010,
    B10001,
    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B11111,  };
    
    byte IC[8] = {
      B00000,
      B10000,
      B11000,
      B01100,
      B00110,
      B00111,
      B00011,
      B00111,  };
      
    byte IIA[8] = {
      B11110,
      B11111,
      B01111,
      B00111,
      B00011,
      B00001,
      B00000,
      B00000,  };
    
    byte IIB[8] = {
      B11111,
      B01110,
      B00000,
      B11011,
      B11111,
      B11111,
      B11111,
      B01110,  };
    
  byte IIC[8] = {
      B01111,
      B11111,
      B11110,
      B11100,
      B11000,
      B10000,
      B00000,
      B00000,  };
 
// creation de charactere sur l'ecran LCD
  LCD.createChar(0, IA);
  LCD.createChar(1, IB);  
  LCD.createChar(2, IC);  
  LCD.createChar(3, IIA);  
  LCD.createChar(4, IIB);
  LCD.createChar(5, IIC);

  
}

// Affichage du logo

void LogoPH()
{
 LCD.setCursor(13,0);
 LCD.write((uint8_t) 0);
 
 LCD.setCursor(14,0);
 LCD.write((uint8_t) 1);
 
 LCD.setCursor(15,0);
 LCD.write((uint8_t) 2);
 
 LCD.setCursor(13,1);
 LCD.write((uint8_t) 3);
 
 LCD.setCursor(14,1);
 LCD.write((uint8_t) 4);
 
 LCD.setCursor(15,1);
 LCD.write((uint8_t) 5);
}

void affRegleHeur()
{
  char message[16] = "";
  heures = Select;
  LCD.setCursor(0,1);
  sprintf(message,"%2d Heures",heures);
  LCD.write(message);
}  

void affRegleMin()
{
  char message[16] = "";
  minutes = Select;
  LCD.setCursor(0,1);
  sprintf(message,"%2d Minutes",minutes);
  LCD.write(message);
}

void affTemp()
{
  unsigned char memoireTemp = analogRead(temp);
  char message[16] = "";
  LCD.setCursor(0,1);
  sprintf(message,"Temp: %2d Cel",memoireTemp);
   if(( millis() - tpsAffTemp)  > 1500)
  {
   LCD.write(message);
   tpsAffTemp=millis();
  }
}

