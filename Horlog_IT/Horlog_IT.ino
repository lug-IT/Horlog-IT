
int secondes;
int minutes;
int heures;
//declaration des broche pour les boutons
const int bts1 = 26;
const int bts2 = 30;

//declaration des broche pour les capteur de temperature et de lumiére
const int temp = A0;
const int lum = A1;

//declaration de la broche LED
const int led = 24;

boolean memSelect;
long tps;
long tpsAffTemp;
int Select;
byte Menu;
void setup()
{
  memSelect = 0;
  tps = millis();
  tpsAffTemp = millis();
  Select = 0;
  Menu = 0;
  //on commence par crée une liaison serie pour le debug, et de future application
  Serial.begin(9600);
  
  //Initialisation du LOGO
  IniLogo();
  
  //Initialisation du Temps
  Initemps();
  
 
  // Initialisation de l'ecran LCD
  IniLCD();
 
  //Initialisation des capteur et des boutons
  IniCaptBts();
  
 
  //initialisation des sortie
  pinMode(led, OUTPUT);
  
  //test led
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  
   // on enleve se qui etait afficher
   affClear();
}

void loop()
{
  LogoPH();  //affichage du Logo Phenix IT
  genTemps(); //fonction generant le temps de l'Horloge
  detectBts();  // Dectection des bouton de reglage
   
 // selection des menu d'affichage normal/reglage
  if(memSelect == 1)
  {
    affReglage();
    digitalWrite(led, LOW);
    Bts();
      if(Menu == 1)
      { affRegleHeur();
        Select = heures;
        if(Select >=24)
            { Select =0; }
          }
          
      if(Menu == 2)
      { affRegleMin();
        Select = minutes; 
         if(Select >= 60)
            {  Select = 0;}
          }
          
      if(Menu == 3)
      { 
        memSelect =! memSelect;
        affClear();
      }
      
      
  }
  else
  {
    affTemp();
    affTemps();
    digitalWrite(led, HIGH);
  }
  
  
}


