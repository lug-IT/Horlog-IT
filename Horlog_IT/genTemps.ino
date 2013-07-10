
long temps;
int Initemps()
{
  secondes = 0;
  minutes = 0;
  heures = 0;
  
  temps = millis();
}



int genTemps ()
{
  //on commence par gérer le temps qui passe ...
 if(secondes == 60)
  {
   secondes = 0;
   minutes++;
  }
 if(minutes == 60)
  {
   minutes = 0;
   heures++;
  } 
 if(heures == 24)
  {
  heures = 0;
  } 
 
  if(( millis() - temps)  > 1000)
  {
   secondes++;
   temps=millis();
  }
  
 return(secondes);
 return(minutes);
 return(heures);
 
}
 

