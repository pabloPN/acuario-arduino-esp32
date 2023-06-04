void LeeBlue(){
  if(!bloqueoBLUE){
      String a;
      String variable="";
      String valor="";
      while(bt.available()) {
            Serial.println("entra1");
            a= bt.readString();// read the incoming data as string
            variable =a.substring( 0,a.indexOf (".") );
            valor =a.substring( a.indexOf (".")+1,a.length() );
      }
      if (variable!=""){
              Serial.print("a=");Serial.println(a);
              Serial.print("variable=");Serial.println(variable);
              Serial.print("valor= ");Serial.println(valor);
              if (variable=="datos"){
                       DatosBt();
              }else if (variable=="enciende"){
                        //Serial.println("enciende");
                       //bt.print("ini*enciende*");
                       int temp= valor.substring(0,valor.indexOf ( ":" )).toInt();//HORA
                       //bt.print(temp);bt.print("*");
                       Mw(10,temp);//escrinimos en memoria dirrecion , valor
                       lucesOn=temp*60;
                       temp=  valor.substring( valor.indexOf ( ":" )+1   ,valor.length()).toInt();//minuto
                       //bt.print(temp);bt.print("*fin");  
                       Mw(11,temp);//escrinimos en memoria dirrecion , valor
                       // Serial.println(temp);
                       lucesOn=lucesOn+temp;
                       lucesOn=lucesOn*60;
                       DatosBt();
              }else if (variable=="apaga"){
                        int temp= valor.substring(0,valor.indexOf ( ":" )).toInt();//HORA
                        //Serial.println(temp);
                        //bt.print("ini*apaga*");bt.print(temp);bt.print("*");  
                        Mw(12,temp);//escrinimos en memoria dirrecion , valor
                        lucesOff=temp*60;
                        temp=  valor.substring( valor.indexOf ( ":" )+1   ,valor.length()).toInt();//minuto
                        //bt.print(temp);bt.println("*fin");
                        Mw(13,temp);//escrinimos en memoria dirrecion , valor
                        lucesOff=lucesOff+temp;
                        lucesOff=lucesOff*60;
                        DatosBt();
                        //Serial.print("off:");Serial.println(off);Serial.print("*");
              }else if (variable=="maxima"){
                        int temp= valor.substring(0,valor.indexOf ( "." )).toInt();//HORA
                          Mw(18,temp);//escrinimos en memoria dirrecion , valor
                        tempMax=temp;
                        temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          Mw(19,temp);//escrinimos en memoria dirrecion , valor
                         tempMax=tempMax+((float)temp/100); 
                        bt.print("ini*maxima calentador*");bt.print(tempMax);bt.print("*fin");  
              }else if (variable=="minima"){
                        int temp= valor.substring(0,valor.indexOf ( "." )).toInt();//HORA
                          Mw(20,temp);//escrinimos en memoria dirrecion , valor
                        tempMin=temp;
                        temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          Mw(21,temp);//escrinimos en memoria dirrecion , valor
                        tempMin=tempMin+((float)temp/100); 
                       // Serial.print("minima=");Serial.print(tempMin);Serial.print("entero=");Serial.print(Mr(memTempMin));Serial.print(":");Serial.print(Mr(memTempMin2));  
                        bt.print("ini*minima calentador*");bt.print(tempMin);bt.print("*fin");  
              }else if (variable=="minimaE"){
                        int temp= valor.substring(0,valor.indexOf ( "." )).toInt();//HORA
                          Mw(22,temp);//escrinimos en memoria dirrecion , valor
                        tempMinE=temp; 
                        temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          Mw(23,temp);//escrinimos en memoria dirrecion , valor
                       tempMinE=tempMinE+((float)temp/100); 
                       bt.print("ini*minima enfriador*");bt.print(tempMinE);bt.print("*fin");  
              }else if (variable=="Tdimmeo"){
                        int temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          tiempoDimmeo=temp*60;
                          Mw(14,temp);//escrinimos en memoria dirrecion , valor
                          //Serial.print("Tdimeo= ");Serial.println(Tdimmeo);Serial.print("*");
                       bt.print("ini*TiempoDeDimmero*");bt.print(tiempoDimmeo/60);bt.print("*minutos*fin");  
              }else if (variable=="Tretraso"){// retraso de amanece a anochece
                        int temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          retrasoBl=temp*60;
                          //Serial.print("retraso");Serial.println(retraso);Serial.print("*");
                          Mw(15,temp);//escrinimos en memoria dirrecion , valor
                       bt.print("ini*TiempoDeRetraso*");bt.print(retrasoBl/60);bt.print("*Minutos*fin");  
              }else if (variable=="retardo"){
                        int temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();//minuto
                          retardo=temp*1000;
                          Mw(24,temp);//escrinimos en memoria dirrecion , valor
                          //Serial.print("retardo= ");Serial.println(retardo);Serial.print("*");
                       bt.print("ini*Reatrdo muestra pantalla*");bt.print(retardo/1000);bt.print("* Segundo*fin");  
              }else if (variable=="dimmer"){
                              if(bloqueoL){  
                                digitalWrite(PIN_R_LUZ,HIGH);// enciende la luz
//                                digitalWrite(Pventilador,HIGH);// enciende el ventilador
                                int temp= valor.substring(0,valor.indexOf ( ":" )).toInt();//HORA
                                //bt.print("ini*dimmer az bl*");bt.print(dimmer);
                                dimmerA=map(temp,0,100,0,255);
                                temp=  valor.substring( valor.indexOf ( ":" )+1   ,valor.length()).toInt();//minuto
                                dimmerB= map(temp,0,100,0,255);
                                bt.print("ini* Azul: *");bt.print(map(dimmerA,0,255,0,100));bt.print("* Blanco: *");bt.print(map(dimmerB,0,255,0,100));bt.print("*fin");
                              }else{bt.print("ini*error*");bt.print("Primero tienes que Bloquear las LUCES");bt.print("*fin");}
              }else if (variable=="dimmerM"){
                                int temp= valor.substring(0,valor.indexOf ( ":" )).toInt();
                                Mw(16,temp );
                                dimmerAzMax=temp;
                                temp=  valor.substring( valor.indexOf ( ":" )+1   ,valor.length()).toInt();
                                Mw(17,temp );
                                dimmerBlMax=temp;
                                bt.print("dimmer a");bt.print(dimmerAzMax);bt.print("dimmer b*");bt.print(dimmerBlMax);bt.print("*fin");
              }else if (variable=="dimmerM%"){
                                int temp= valor.substring(0,valor.indexOf ( ":" )).toInt();
                                temp= map(temp,0,100,0,255);
                                Mw(16,temp);
                                dimmerAzMax=temp;
                                temp=  valor.substring( valor.indexOf ( ":" )+1   ,valor.length()).toInt();
                                temp= map(temp,0,100,0,255);
                                Mw(17,temp);
                                dimmerBlMax=temp;
                                bt.print("ini*Azul max: *");bt.print(map(dimmerAzMax,0,255,0,100));bt.print("* Blanco max: *");bt.print(map(dimmerBlMax,0,255,0,100));bt.print("*fin");
              }else if (variable=="luces"){
                      if(bloqueoL){
                        Serial.println("lucesrr");
                        digitalWrite(PIN_R_LUZ,!digitalRead(PIN_R_LUZ));
                        //digitalWrite(Pventilador,!digitalRead(Pventilador));
                        if (digitalRead(!PIN_R_LUZ)){dimmerA=255;dimmerB=255;}else{dimmerA=0;dimmerB=0;}
                        DatosBt();//bt.print("ini*luces*");bt.print(OnOff(digitalRead(PIN_R_LUZ)));bt.print("*");bt.print(OnOff(bloqueoL));bt.print("*fin");
                      }else{bt.print("ini*error*");bt.print("Primero tienes que Bloquear las LUCES");bt.print("*fin");}
              }else if (variable=="enfriador"){
                      if(bloqueoE){
                        Serial.println("enfriadorr");
                        digitalWrite(PIN_R_ENFRIADOR,!digitalRead(PIN_R_ENFRIADOR));
                        DatosBt();//bt.print("ini*enfriador*");bt.print(OnOff(digitalRead(PIN_R_ENFRIADOR)));bt.print("*");bt.print(OnOff(bloqueoE));bt.print("*fin");
                      }else{bt.print("ini*error*");bt.print("Primero tienes que Bloquear el ENFRIADOR");bt.print("*fin");}
              }else if (variable=="calentador"){
                              if(bloqueoC){
                                Serial.println("calentadorr");
                                digitalWrite(PIN_R_CALENTADOR,!digitalRead(PIN_R_CALENTADOR));
                                DatosBt();//bt.print("ini*calentador*");bt.print(OnOff(digitalRead(PIN_R_CALENTADOR)));bt.print("*");bt.print(OnOff(bloqueoC));bt.print("*fin");
                              }else{bt.print("ini*error*");bt.print("Primero tienes que Bloquear el CALENTADOR");bt.print("*fin");}
              }else if (variable=="subida"){
                              if(bloqueoS){
                                Serial.println("subidarrr");
                                digitalWrite(PIN_R_SUBIDA,!digitalRead(PIN_R_SUBIDA));
                                DatosBt();//bt.print("ini*subida*");bt.print(OnOff(digitalRead(PIN_R_SUBIDA)));bt.print("*");bt.print(OnOff(bloqueoS));bt.print("*fin");
                              }else{bt.print("ini*error*");bt.print("Primero tienes que Bloquear la SUBIDA");bt.print("*fin");}
               }else if (variable=="bloq"){
                                //String temp= "B"+valor.substring( valor.indexOf ( ":" )+2   ,valor.length());
                                //bt.print("ini*");bt.print(temp);bt.print("*");
                                if (valor=="subida"){
                                  bloqueoS=!bloqueoS;
                                  //bt.print(OnOff( digitalRead(PIN_R_SUBIDA )));bt.print("*");bt.print(OnOff(bloqueoS));
                                  Serial.print("s");
                                }else if (valor=="enfriador"){
                                  bloqueoE=!bloqueoE;
                                  //bt.print(OnOff( digitalRead(PIN_R_ENFRIADOR )));bt.print("*");bt.print(OnOff(bloqueoE));
                                  Serial.print("e");
                                }else if (valor=="calentador"){
                                  bloqueoC=!bloqueoC;
                                  //bt.print(OnOff( digitalRead(PIN_R_CALENTADOR )));bt.print("*");bt.print(OnOff(bloqueoC));
                                  Serial.print("c");
                                }else if (valor=="luces"){
                                  bloqueoL=!bloqueoL;
                                  //bt.print(OnOff(digitalRead(PIN_R_LUZ )));bt.print("*");bt.print(OnOff(bloqueoL));
                                  Serial.print("l");
                                }
                                DatosBt();//bt.print("*fin");
              }else if (variable=="comida"){
                                digitalWrite(PIN_R_SUBIDA,!digitalRead(PIN_R_SUBIDA));
                                DatosBt();//bt.print("ini");bt.print("*subida*");bt.print(OnOff(digitalRead(PIN_R_SUBIDA)));bt.print("*bloqueoS*");bt.print(OnOff(!bloqueoS));bt.print("*fin");
              }else{
                bt.print("ini*error*");bt.print("No he podido saber que necesitas");bt.print("*fin");
              }
      }//if (variable!=""){          
  }//if bloqueoSERV
}// LeeBlue
void DatosBt()
{
                        bt.print("ini");
                        bt.print("*");    
                        bt.print(TempAcuario());//temp2
                        bt.print("*");    
                        bt.print(tempMax);//max3
                        bt.print("*");    
                        bt.print(tempMin);//min4
                        bt.print("*");   
                        bt.print(tempMinE);//minE 5
                        bt.print("*");bt.print(OnOff(digitalRead(PIN_R_LUZ)));//luces6
                        bt.print("*");bt.print(OnOff(bloqueoL));//luces loq7
                        bt.print("*");bt.print(OnOff(digitalRead(PIN_R_ENFRIADOR)));//enfira8
                        bt.print("*");bt.print(OnOff(bloqueoE));//enfira bloq9
                        bt.print("*");bt.print(OnOff(digitalRead(PIN_R_CALENTADOR)));//calentador10
                        bt.print("*");bt.print(OnOff(bloqueoC));//calentador bloq11
                        bt.print("*");bt.print(OnOff(digitalRead(PIN_R_SUBIDA)));//Subida=12
                        bt.print("*");bt.print(OnOff(bloqueoS));//Subida= bloq13
                        bt.print("*");bt.print("OK");//Nivel:14 
                        bt.print("*");bt.print(Hora(lucesOn));//enciende luces15 "13:45"
                        bt.print("*");bt.print(Hora(lucesOff));//apaga luces16
                        bt.print("*");bt.print( map(dimmerB,0,255,0,100) );//Luz blanca: %17
                        bt.print("*");bt.print( map(dimmerA,0,255,0,100) );//Luz azul: %18
                        bt.print("*");bt.print(dimmerAzMax);//Azul maxima 19
                        bt.print("*");bt.print(dimmerBlMax);// Blanca maxima 20
                        bt.print("*");bt.print(map(dimmerAzMax,0,255,0,100));//Azul maxima % 21
                        bt.print("*");bt.print(map(dimmerBlMax,0,255,0,100));// Blanca maxima % 22
                        bt.print("*");bt.print(tiempoDimmeo/60);//Tiempo de dimmero min23
                        bt.print("*");bt.print(retrasoBl/60);//Tiempo de retraso Minutos 24 
                        bt.print("*");bt.print(retardo/1000);//Retardo pantalla Segundo  25
                        bt.print("*");bt.print(5);// tiempo ence cale26
                        bt.print("*");bt.print(5);// min. Apagado: cle min"); 27 
                        bt.print("*");bt.print("ultimaHoff");//ultima apago 28
                        bt.print("*");bt.print("ultimaHon");// ultima encendio  29
                        bt.print("*");bt.print("fin");
}
////// Serial //////
void LeeSerial(void)
{ 
      String a;
      String variable="";
      String valor="";
  if (!bloqueoSERI){
    String a;
    a="";          
    while(Serial.available()) {
        a= Serial.readString();// read the incoming data as string
        variable =a.substring( 0,a.indexOf (".") );
        valor =a.substring( a.indexOf (".")+1,a.length() );
    }
    if (a!=""){
              Serial.print("a=");Serial.println(a);
              Serial.print("variable=");Serial.println(variable);
              Serial.print("valor= ");Serial.println(valor);
        if (a.startsWith("dat")){
             //Cliente("mi.betulaludica.com","/acua2020/arduino.php?q=dat&dat=ini*23,65*ON*13:30*30/11/2023_18:15:00");
        }else if (a.startsWith("temp")){
              
             Cliente("mi.betulaludica.com","/acua2020/enviaTempBD.php?temp="+String(TempAcuario())); 
        }else if (a.startsWith("dimmer")){
             Serial.print("dimmer ");Serial.println(valor);
             ledcWrite(CANAL_AZUL, valor.toInt());
              ledcWrite(CANAL_BLANCO, valor.toInt());
        }else if (a.startsWith("web")){
           Serial.println("peticion de web");
            Cliente("mi.betulaludica.com","/acua2020/arduino.php?q=arduino&dat=nada");
        }else if (a.startsWith("ip")){
            Cliente("mi.betulaludica.com","/acua2020/enviaIpBD.php");
             Serial.print("*");Serial.print(IpPublica()); Serial.print("*");
        }else if (a.startsWith("tiempo")){
            //Serial.println(TiempoPasado(1));
        }else if (a.startsWith("envia")){
            Serial.print(Datt());
        }else if (a.startsWith("luc")){
          Serial.println("luz");
                        bloqueoL=!bloqueoL;
                        //Serial.println(digitalRead(PIN_R_LUZ));
                        digitalWrite(PIN_R_LUZ,!digitalRead(PIN_R_LUZ));
                        delay(2000);
                        //Serial.println(digitalRead(PIN_R_LUZ));
                        //digitalWrite(Pventilador,!digitalRead(Pventilador));
                        //if (digitalRead(!PIN_R_LUZ)){dimmerA=255;dimmerB=255;}else{dimmerA=0;dimmerB=0;}
                        //bt.print("ini*luces*");bt.print(OnOff(digitalRead(PIN_R_LUZ)));bt.print("*");bt.print(OnOff(bloqueoL));bt.print("*fin");
                        //Serial.println(digitalRead(PIN_R_LUZ));
              }else if (a.startsWith("enf")){
                        Serial.println("enfria");
                        //bloqueoE=!bloqueoE;
                        digitalWrite(PIN_R_ENFRIADOR,!digitalRead(PIN_R_ENFRIADOR));
                       // bt.print("ini*enfriador*");bt.print(OnOff(digitalRead(PIN_R_ENFRIADOR)));bt.print("*");bt.print(OnOff(bloqueoE));bt.print("*fin");
              }else if (a.startsWith("cal")){
                Serial.println("calentadorr");
                                //bloqueoC=!bloqueoC;// lo contrario
                                digitalWrite(PIN_R_CALENTADOR,!digitalRead(PIN_R_CALENTADOR));
                           //     bt.print("ini*calentador*");bt.print(OnOff(digitalRead(PIN_R_CALENTADOR)));bt.print("*");bt.print(OnOff(bloqueoC));bt.print("*fin");
              }else if (a.startsWith("sub")){
                Serial.println("luz");
                                //bloqueoS=!bloqueoS;
                                digitalWrite(PIN_R_SUBIDA,!digitalRead(PIN_R_SUBIDA));
                          //     bt.print("ini*subida*");bt.print(OnOff(digitalRead(PIN_R_SUBIDA)));bt.print("*");bt.print(OnOff(bloqueoS));bt.print("*fin");
              }else{
          Serial.println("enviamos: ");Serial.println(a);
          bt.print(a);
        }
    }          
  } //if bloqueoSERI
}// serial
