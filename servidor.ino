
///////////////////////////////////////////////////////////////////
/////////////////////// SERVIDOR //////////////////////////////////
///////////////////////////////////////////////////////////////////
void RespuestaRaiz() {// raiz ../?temp=34
      if (server.hasArg("luces")) {
            digitalWrite(PIN_R_LUZ,!digitalRead(PIN_R_LUZ));//lo contrario
      }else if (server.hasArg("lucesB")) {
            bloqueoL=!bloqueoL;
      }else if (server.hasArg("enfria")) {
            digitalWrite(PIN_R_ENFRIADOR,!digitalRead(PIN_R_ENFRIADOR));//lo contrario
      }else if (server.hasArg("enfriaB")) {
            bloqueoE=!bloqueoE;
      }else if (server.hasArg("calentador")) {
            digitalWrite(PIN_R_CALENTADOR,!digitalRead(PIN_R_CALENTADOR));//lo contrario
      }else if (server.hasArg("calentadorB")) {
            bloqueoC=!bloqueoC;
      }else if (server.hasArg("subida")) {
            String value = server.arg("subida");
            digitalWrite(PIN_R_SUBIDA,!digitalRead(PIN_R_SUBIDA));//lo contrario
      }else if (server.hasArg("subidaB")) {
            bloqueoS=!bloqueoS;
      }else {
            Serial.println("La variable luz no se ha recibido");
      }
            server.send(200, "text/html", Web());
}
void RespuestaActualiza()
{
          Serial.println("actualiza web");
          server.send(200, "text/html", Web());
}
void RespuestaPhp() {// ../resp?temp=34 
        String temp = server.arg("temp");// temp es el valor de temperatura recibido
        if (temp != "") {
          Serial.println("resp Temperature value received: " + temp);
          if (temp.toInt() == 34) {
            Cliente("mi.betulaludica.com","/acua2020/arduino.php?q=arduino&temp2=23");
          }
        }
        server.send(200, "text/plain", "Request "+ temp);
}
void ServerRele() {
  //      digitalWrite(PIN_AZUL,!digitalRead(PIN_AZUL));//lo contrario
    //    server.send(200, "text/plain", "Rele :"+OnOff(!digitalRead(PIN_AZUL)));
}
void LeeServidor(void)
{
  if (!bloqueoSERV) server.handleClient();
}
String IpPublica()
{
        // ya no hace falta
        WiFiClient client;
        if (!client.connect("api.ipify.org", 80)) {
          Serial.println("Error al conectarse al servidor.");
          return "";
        }
        client.println("GET / HTTP/1.1");
        client.println("Host: api.ipify.org");
        client.println("Connection: close");
        client.println();
        while (!client.available());
        String publicIP = client.readString();
        client.stop(); // Cerrar la conexión con el servidor
        int a= publicIP.lastIndexOf("\r\n");
        
        return publicIP.substring(a+2,publicIP.length());
}
String Web(){
          float temp=23.45;
          int tempInt=temp*100;
          //Los encabezados HTTP siempre comienzan con un código de respuesta (por ejemplo, HTTP / 1.1 200 OK)
          // y un tipo de contenido para que el cliente sepa lo que viene, luego una línea en blanco:
          String web="";
          web=web+
          "<html><head>"+
          "<title>Acuarium MarePrime </title> </head> <body bgcolor=\"#000000\" text=\"#ffffff\">"+
          "Enviando informacion desde el arduino ...."+
          "<form name=\"formu\" action=\"http://mi.betulaludica.com/acua2020/index.php\" method=\"get\">"+ 
          "<input type=\"hidden\" name=\"datt\" value=\""+Datt()+"\">"+

          "</form>"+       
          "<script language=\"javascript\">setTimeout(\"formu.submit()\",4000);</script>"+
          "</body></html>";  
          return web;
}
String Datt(){
  String a="";
   a= String(TempAcuario())+
         "*" +String(tempMax) +
         "*" +String(tempMin) +
         "*" +String(tempMinE)+
         "*" +String(OnOff(digitalRead(PIN_R_LUZ)))+
         "*" +String(OnOff(bloqueoL));
         a=a+"*"+String(OnOff(digitalRead(PIN_R_ENFRIADOR)));
         a=a+"*" +String(OnOff(bloqueoE));
         a=a+"*" +String(OnOff(digitalRead(PIN_R_CALENTADOR)));
         a=a+"*" +String(OnOff(bloqueoC));
         a=a+"*" +String(OnOff(digitalRead(PIN_R_SUBIDA)));
         a=a+"*" +String(OnOff(bloqueoS));
         a=a+"*" +Hora(lucesOn);
         a=a+"*" +Hora(lucesOff);
         a=a+"*" +String( map(dimmerB,0,255,0,100));
         a=a+"*" +String( map(dimmerA,0,255,0,100));
         a=a+"*" +String(dimmerAzMax);
         a=a+"*" +String(dimmerBlMax);
         a=a+"*" +String(tiempoDimmeo);
         a=a+"*" +String(retrasoBl); 
         a=a+"*" +String(retardo);    
return a;
}
