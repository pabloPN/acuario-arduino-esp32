void Siempre()
{
  ////// cada Minuto //////
  if (millis()>=(cadaMinuto+30000)|| cadaMinuto>millis()){// medio  minuto
     //esto paras a info()
    // Serial.print("dimmer A: ");Serial.println(dimmerA);
    // Serial.print("dimmer B: ");Serial.println(dimmerB);
    // Serial.print("Rele temp: ");Serial.println(digitalRead(PIN_R_CALENTADOR));
      // Serial.print("Temperatura del acuario: ");Serial.println(TempAcuario());
    // Serial.print("Temperatura max: ");Serial.println(tempMax);
    // Serial.print("Temperatura min: ");Serial.println(tempMin);
    // Serial.print("bloqueoc: ");Serial.println(bloqueoC);
    // Serial.print("Hora E: ");Serial.println(lucesOn);
    // Serial.print("hora off: ");Serial.println(lucesOff);
       //MuestraHora();
       TempOnOff(); //bloq lee temperatura y apaga o enciende calentador y enfriador
       Pantalla();
       cadaMinuto=millis();
       Serial.println("30 seg");
  }
  ////// cada Hora //////

  if (millis()>=(cadaHora+3600000) || cadaHora>millis()){//-+una Hora
      if (TempAcuario()<23.30 ||TempAcuario()>27.03 ){
          //tone(Palarma,50,500);delay(1000);tone(Palarma,50,500);
          Cliente("mi.betulaludica.com","/acua2020/enviaEerror.php?temp="+String(TempAcuario())); 
      }
     ////// enviamos Temperatura //////
       Cliente("mi.betulaludica.com", "/acua2020/enviaTempBD.php?temp="+ String(TempAcuario()) );    
       Cliente("mi.betulaludica.com","/acua2020/enviaIpBD.php");
       cadaHora=millis();
  }
  ////// Siempre //////
      LeeServidor();//bloq
      LeeSerial(); //bloq
      LeerS2();
      LeeBlue();//bloq
      Luces(); //bloq  lee segactual y dimmea
      
   //   Adita();//bloq
  
}

String OnOff(boolean a){
    if (a){
      return "ON";//"OFF";
    }else{
      return "OFF";//"ON";
    }
}
void Pwm(int pin, int dutyCycle) {
  // OJO EL LEDCHANEL SOLO ES DE 0 A 15 ASI QUE SI USAMOS EL PIN 16 O MAYOR TENEMOS QUE DEFINIR EL LEDCHANEL APARTE 
  //ledcSetup(ledChannel EL CANAL ES DE 0 A 15 , freq sule ser 5000, resolution 8bit seria un rango de 0-255);
  //ledcAttachPin(ledPin EL pin del esp2, ledChannel EL CANAL ES DE 0 A 15);
  // ledcWrite(ledChannel EL CANAL ES DE 0 A 15 , dutyCycle DE 0 A 255);
  //Serial.print("pwm");Serial.println(dutyCycle);
  ledcSetup(pin, 5000, 8);
  ledcAttachPin(pin, pin);
  ledcWrite(pin, dutyCycle);
}
String Hora(long dim){
  return String(dim / 3600)+":"+String((dim % 3600) / 60);
}
