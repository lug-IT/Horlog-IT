
//declaration de variable d'etat et de memoire des boutons
boolean memBts1 = LOW;
boolean memBts2 = LOW;
boolean etatBts1;
boolean etatBts2;

//declaration des memoire capteur
int memoireTemp;
float memoireLum;


void IniCaptBts()
{
   
  //Initialisation etatBouton
  etatBts1 = 1;
  etatBts2 = 1;
  
  //initialisation des entrers
  pinMode(bts1, INPUT);
  pinMode(bts2, INPUT);
  pinMode(temp, INPUT);
  pinMode(lum, INPUT);
  
   //Test la reception des valeurs des capteur
  memoireTemp = analogRead(temp);
  memoireLum = analogRead(lum);
  
  Serial.print(memoireTemp);
  Serial.print(" / ");
  Serial.println(memoireLum);
  delay(1000);
}

int detectBts()
{
 
  // initialisation des etats des boutons
  etatBts1 = digitalRead(bts1);
  etatBts2 = digitalRead(bts2);
  
    if((etatBts1 == memBts1) && (etatBts2 == memBts2) && ((millis() - tps) > 500))
    {
      affClear(); 
      memSelect = 1;
      delay(500);
      Menu++;
      
    }
    
  etatBts1 = digitalRead(bts1);
  etatBts2 = digitalRead(bts2);
  return(memSelect);
  return(Menu);
   
} 

int Bts()
{
  etatBts1 = digitalRead(bts1);
  
  if(etatBts1 == memBts1)
    {
      
      Select++;
      Serial.print(" / Bts1");
      delay(300);

    }
    
  etatBts1 = digitalRead(bts1);
  
  etatBts2 = digitalRead(bts2);
  
  if(etatBts2 == memBts2)
  {
    Select--;
    if(Select <= 0)
    { Select = 0; }
    Serial.print(" / bts2");
    delay(300);
    
  }
  
  etatBts2 = digitalRead(bts2);

  return(Select);
 
}

