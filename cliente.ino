void Cliente(char *web,String url ){
  if (!bloqueoSERV){
    // Establecer la conexión con el servidor
    const char* host = web;
    const int httpPort = 80;
    WiFiClient client;
    delay(500);
    if (!client.connect(web, httpPort)) {
        Serial.println("Error al conectar con el servidor.");
        return;
    }
    // Construir la petición GET con los parámetros temp1 y temp2
    // Enviar la petición GET al servidor
    //Serial.print("Enviando petición GET a ");
    //Serial.print(web);
    //Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: "+web + "\r\n" +
                 "Connection: close\r\n\r\n");
    // Leer la respuesta del servidor
    //Serial.println("Esperando respuesta del servidor...");
    String response = "";
    while (client.connected()) {
        if (client.available()) {
          String c = client.readString();
          response += c;
        }
    }
    // Imprimir la respuesta del servidor
        //Serial.print("Respuesta del servidor:");
        Serial.println(response);
    if (response.startsWith("HTTP/1.1 200 OK")){
      Serial.println("genial");      
    }else{
      Serial.println("fallo");      
    }
    client.stop();
    /// llama a funcion que analice la respuesta
  }
}
