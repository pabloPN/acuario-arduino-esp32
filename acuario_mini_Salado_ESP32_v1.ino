// ultima modificacion probando instalado el whatcdog
//si reles es al contrario hay que modificar el calentador onof lo que se envia por bule y web sea contrario a lo que es 
//comprobar las luces desde la pantalla como funciona el bloqueo
//continuar con 
//ok perist,leer del ariuno en la memoria para saber los milisegundos de cada peristaltica y  comprobar que funciona el adita()???


//ok subir BD cada hora la temp
//ok subir BD cada vez que se enciende y se apaga la temp
//ok luces comprobar
//ok bluethot
//eppromOk
//temp ok 
// SetupLuces pin enciende apaga dimmero retraso ????

#include "AcuarioM.h"
#include <esp_task_wdt.h>//perro

void setup() {
    Setup("MiFibra-7D4F", "u4utsxXL");
    
    // Habilitar el T-Watchdog con un tiempo de espera de 5 segundos
    esp_task_wdt_init(120, true);//perro 120 segundos
    esp_task_wdt_add(NULL);//si no se ejecuta cada 120seg se reinicia
    
}
void loop() {
Siempre();
esp_task_wdt_reset();//si no
//Serial.print("dfsdf");
//borra();
}
void borra(){
  if (SegActu()>=(cadaHora+30) || cadaHora>SegActu()){// mas de una Hora
    ////// enviamos Temperatura //////
       Cliente("mi.betulaludica.com", "/acua2020/enviaTempBD.php?temp=23.7");
       Serial.println("String(hora+""+minuto)");    
       //Cliente("mi.betulaludica.com", "/acua2020/enviaTempBD.php?temp="+ String(TempAcuario()) );    
       //Cliente("mi.betulaludica.com","/acua2020/enviaIpBD.php");
       cadaHora=SegActu();
  }
}