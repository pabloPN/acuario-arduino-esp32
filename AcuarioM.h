/*
                      Control de acuario marino
                        USB
                      BOOT EN    PINES QUE NO ESTAN
                      3,3v vin    6,7,8,9,10,11,20,24,28,29,30,31,37,38
                      gnd  gnd
     azul  high touch 15   13 touch          calentador
   blanco    cs touch 2    12 touch          enfriador
temperat?       touch 4    14 touch high     subida
                 rxd2 16   27 touch          luz
                 rtx2 17   26                magnesio
            high      5    25                calcio
                  sck 18   33                kh
                 miso 19   32                temperat
                  sda 21   35 solo in, NO pwm no out
            high rxd0 3    34 solo in, NO pwm no out
            high txd0 1    39 solo in, NO pwm no out sensVN- conectar 0 a 3,3v y lo lee 
                  scl 22   36 solo in, NO pwm no out sensVP+ conectar 0 a 3,3v y lo lee 
                 mosi 23   en
*/
#include <WiFi.h>
#include <WebServer.h>
#include "time.h"
#include "EEPROM.h"
#include <OneWire.h> //temp
#include <DallasTemperature.h>
#include <esp_task_wdt.h>//perro

////// BLUETOOTH //////
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define PIN_AZUL 15
#define PIN_BLANCO 2
#define CANAL_AZUL 0
#define CANAL_BLANCO 1
#define PIN_R_CALENTADOR 13
#define PIN_R_ENFRIADOR 12
#define PIN_R_SUBIDA 14
#define PIN_R_LUZ 27
#define PIN_MAGNESIO 26
#define PIN_CALCIO 25
#define PIN_KH 33
#define PIN_SENSOR_TEMP 32

#define EEPROM_SIZE 32


//////  INSTANCIAS //////
WebServer server(80);// instancia de WebServer
BluetoothSerial bt;
OneWire oneWire(PIN_SENSOR_TEMP);
DallasTemperature sensorTemp(&oneWire);
////// VARIABLES
boolean bloqueoC=false,bloqueoL=false,bloqueoE=false,bloqueoS=false,bloqueoSERI=false,bloqueoBLUE=false,bloqueoSERV=false,bloqueoPERI=true,bloqueoRELO=false;
int tiempoDimmeo,retrasoBl,retardo, segundo, minuto, hora, diaSemana, dia, mes, ano;
byte dimmerA,dimmerB,dimmerAzMax,dimmerBlMax;
long lucesOn,lucesOff;
float tempMax,tempMin,tempMinE;
unsigned long delayMagnesio,delayCalcio,delayKh, cadaMinuto,cadaHora;
int horaArrayMagnesio;// tiempo de peristaltica 1 en 0
int horaArrayCalcio;
int horaArrayKh;
time_t onOffTemp = 0; // variable estática para almacenar la última llamada

