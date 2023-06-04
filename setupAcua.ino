bool Setup(const char* ssid, const char* password)
{
    
    Serial.begin(9600);
    Serial.println("Iniciando acuario...");
    Serial2.begin(9600);
    pinMode(PIN_AZUL, OUTPUT);
    pinMode(PIN_BLANCO, OUTPUT);
    pinMode(PIN_R_LUZ, OUTPUT);
    pinMode(PIN_R_CALENTADOR, OUTPUT);
    pinMode(PIN_R_ENFRIADOR, OUTPUT);
    pinMode(PIN_R_SUBIDA, OUTPUT);
    pinMode (PIN_MAGNESIO,OUTPUT);
    pinMode (PIN_CALCIO,OUTPUT);
    pinMode (PIN_KH,OUTPUT);

    digitalWrite (PIN_MAGNESIO,LOW);
    digitalWrite (PIN_CALCIO,LOW);
    digitalWrite (PIN_KH,LOW);
    digitalWrite(PIN_R_CALENTADOR, HIGH);
    digitalWrite(PIN_R_SUBIDA, HIGH);
    /// PWM ///
    ledcSetup(0,5000,8);
    ledcSetup(1,5000,8);
    ledcAttachPin(PIN_AZUL,CANAL_AZUL);
    ledcAttachPin(PIN_BLANCO,CANAL_BLANCO);
    
    WiFi.mode(WIFI_STA); // Configurar el modo estación de la WiFi
    // WiFi.config(local_IP, gateway, subnet); // Configurar la dirección IP estática, la puerta de enlace y la máscara de subred
    WiFi.begin(ssid, password); // Conectar a la red WiFi
    Serial.print("Conectando a la red WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(800);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conectado a la red WiFi");
    Serial.print("Dirección IP local: ");
    Serial.println(WiFi.localIP()); // Imprimir la dirección IP local del ESP32
      /////////////////  CONFIGURAMOS MANEJADORES ///////////
    //server.on("/get",HTTP_GET, RespuestaWebPost);
    server.on("/", RespuestaRaiz);
    server.on("/actualiza", RespuestaActualiza);
    server.on("/resp", RespuestaPhp);
    server.on("/rele", ServerRele);
        // Iniciar el servidor
    server.begin();
        // blue
    bt.begin("AcuarioMarino"); //Bluetooth device name
    // reloj 1 es zona horaria y 3600 
    configTime(3600, 3600, "pool.ntp.org");
    cadaMinuto=millis();//SegActu();
    cadaHora=millis();//SegActu();
    onOffTemp = time(NULL); // variable estática para almacenar la última llamada
     /////// memoria ///////
    if (EEPROM.begin(EEPROM_SIZE))
      Serial.println("memoria ok");
    else
      Serial.println("memoria fallo");
    //MemoriaWrite(14,30,23,59,35,15,255,255,25,30,24,30,26,10,5);
    MemoriaRead();
    //MemoriaMuestra();
    /// guardamos en variables el delay de cada peristaltica
   unsigned long tempPeri =(EEPROM.read(4)*100)+EEPROM.read(5);// leemos tiempo de cada milli
                 delayMagnesio =(23* tempPeri)/3; // lo multiplicamos por los mililitros totales y dividimos entre las veces al dia  que son 3
                 tempPeri =(EEPROM.read(6)*100)+EEPROM.read(7);// leemos tiempo de cada milli
                 delayCalcio=(4* tempPeri)/3;// lo multiplicamos por los mililitros totales y dividimos entre las veces al dia  que son 3
                 tempPeri =(EEPROM.read(8)*100)+EEPROM.read(9);// leemos tiempo de cada milli
                 delayKh=(8* tempPeri)/3;// lo multiplicamos por los mililitros totales y dividimos entre las veces al dia  que son 3
      horaArrayMagnesio=0;// tiempo de peristaltica 1 en 0
      horaArrayCalcio=0;
      horaArrayKh=0;
    Pantalla();
    // Habilitar el T-Watchdog con un tiempo de espera de 5 segundos
    esp_task_wdt_init(120, true);//perro 120 segundos
    esp_task_wdt_add(NULL);//si no se ejecuta cada 120seg se reinicia
    return true;
}
