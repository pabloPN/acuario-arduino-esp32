void MemoriaRead (){
        ////// Lectura de Memoria
    // azules
    long temporal=EEPROM.read(10)*60;//hora
    Serial.println(temporal);
    temporal=temporal+EEPROM.read(11);//min
    Serial.println(temporal);
    lucesOn=temporal*60;//segundos
    Serial.println(lucesOn);
    temporal=EEPROM.read(12)*60;//hora
    temporal=temporal+EEPROM.read(13);//min
    lucesOff=temporal*60;//segundos
    Serial.println(lucesOff);
    tiempoDimmeo=EEPROM.read(14)*60;
    retrasoBl=EEPROM.read(15)*60;
    dimmerAzMax=EEPROM.read(16);
    dimmerBlMax=EEPROM.read(17);
    tempMax=EEPROM.read(18);
    tempMax=tempMax+((float)EEPROM.read(19)/100);
    tempMin=EEPROM.read(20);
    tempMin=tempMin+((float)EEPROM.read(21)/100);
    // enfriador
    tempMinE=EEPROM.read(22);
    tempMinE=tempMinE+((float)EEPROM.read(23)/100);
    retardo=EEPROM.read(24)*1000;// retardo de mostrar pantalla

  }
void MemoriaMuestra(){
  for(byte x=0;x<EEPROM_SIZE+1;x++){
    Serial.print("mem "+String(x)+"= ");
    Serial.println(byte(EEPROM.read(x)));
 }
}  
   //MemoriaWrite (         14,            30,           23,           59,             35,                15,             255,                255,           25,           30,          24,            30,           26,             10,          5);
void MemoriaWrite (byte lucesOnH, byte lucesOnM,byte lucesOffH,byte lucesOffM,byte mtiempoDimmeo,byte mretrasoBl,byte mdimmerAzMax,byte mdimmerBlMax,byte tempMax1,byte tempMax2,byte tempMin1,byte tempMin2,byte tempMinE1,byte tempMinE2,byte mretardo)
  {
    
    EEPROM.write(10,lucesOnH);//hora on
    EEPROM.write(11,lucesOnM);//min on
    EEPROM.write(12,lucesOffH);//hora off
    EEPROM.write(13,lucesOffM);//min off
    EEPROM.write(14,mtiempoDimmeo);// tiempoDimmeo
    EEPROM.write(15,mretrasoBl);//retrasoBl
    EEPROM.write(16,mdimmerAzMax);// dimmerAzMax
    EEPROM.write(17,mdimmerBlMax);// dimmerBlMax
    EEPROM.write(18,tempMax1);//tempMax1
    EEPROM.write(19,tempMax2);//tempMax2
    EEPROM.write(20,tempMin1);//tempMin1
    EEPROM.write(21,tempMin2);//tempMin2
    EEPROM.write(22,tempMinE1);//tempMinE1
    EEPROM.write(23,tempMinE2);//tempMinE2
    EEPROM.write(24,mretardo);// retardo de mostrar pantalla
    if (EEPROM.commit())
      Serial.println("ok write");
    else
      Serial.println("write fallo");
 }
void Mw(int m,int v)
{
   EEPROM.write(m,v);// retardo de mostrar pantalla
   EEPROM.commit();
}
void MemoriaBorra()
{
  for(byte x=0;x<EEPROM_SIZE+1;x++){
    EEPROM.write(x,0);
    EEPROM.commit();
  }
}
