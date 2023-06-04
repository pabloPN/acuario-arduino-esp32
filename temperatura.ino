float TempAcuario()
{
  sensorTemp.requestTemperatures();       //Prepara el sensor para la lectura 
  //tempAcuario=sensorTemp.getTempCByIndex(0);
  return sensorTemp.getTempCByIndex(0); //Se lee 
}
void TempOnOff(){
  
    if (!bloqueoC){
          if (TempAcuario()>tempMax){
              //apaga
              if (digitalRead(PIN_R_CALENTADOR)){// para q solo se apage cuando esta encendido esto lo usamos para ver cuando se apaga o se enciende
                SiEnciendeOApagaCalentador(0);
                Serial.println("APAGAMOS");
                digitalWrite(PIN_R_CALENTADOR,LOW);
              }
          }else if(TempAcuario()<tempMin){
              //enciende
              if (!digitalRead(PIN_R_CALENTADOR)){// lo mismo que arriba Si esta apagado lo encendemos esto lo usamos para ver cuando se apaga o se enciende 
                SiEnciendeOApagaCalentador(1);
                Serial.println("ENCENDEMOS");
                digitalWrite(PIN_R_CALENTADOR,HIGH);
              }
          }
    }//bloqueoc
     //// enfriador ////
      if (!bloqueoE){
           if (TempAcuario()>tempMinE){
                //enciende
                digitalWrite(PIN_R_ENFRIADOR,HIGH);
           }else if(TempAcuario()<tempMax){
                //apaga
                digitalWrite(PIN_R_ENFRIADOR,LOW);
           }
      }
}
void SiEnciendeOApagaCalentador(byte a) {
    if (a){
        // encendiendo guarda que ha estado apagado
        Cliente("mi.betulaludica.com","/acua2020/enviaOnOffBD.php?onOff=0&onOffTime="+String(time(NULL) - onOffTemp)); 
    }else{
        //apagando  guarda que ha estado encendido
         Cliente("mi.betulaludica.com","/acua2020/enviaOnOffBD.php?onOff=1&onOffTime="+String(time(NULL) - onOffTemp)); 
    }
    onOffTemp = time(NULL); // actualizar el valor de la última llamada
}
