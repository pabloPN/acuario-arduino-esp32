void Cliente(char *web,String url ){
  if (!bloqueoSERV){
    // Establecer la conexión con el servidor
    const char* host = web;
    const int httpPort = 80;
    WiFiClient client;
    delay(500);
    if (client.connect(web, httpPort)) {
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: "+web + "\r\n" +
                 "Connection: close\r\n\r\n");
        delay(50);        
        String response = "";
        while (client.available()) {
              String c = client.readString();
              response += c;
        }
        Serial.print(response);
        client.stop();
    }else {
      Serial.println("Error al conectar con el servidor.");
    }
  }
}
