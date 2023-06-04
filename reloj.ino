void LeerHora()
{
  if(!bloqueoRELO){
      struct tm timeinfo;
      if(!getLocalTime(&timeinfo)){
          Serial.println("Failed to obtain time");
          return;
      }
      segundo= timeinfo.tm_sec;
      
      minuto= timeinfo.tm_min;
      hora= timeinfo.tm_hour;
      diaSemana= timeinfo.tm_wday;
      dia= timeinfo.tm_mday;
      mes= timeinfo.tm_mon;
      ano= timeinfo.tm_year+1900;
      //tm_sec: segundos (0-59)tm_min: minutos (0-59)tm_hour: horas (0-23)tm_mday: día del mes (1-31)tm_mon: mes (0-11)tm_year: año desde 1900tm_wday: día de la semana (0-6, donde 0 es domingo)
      //tm_yday: día del año (0-365)tm_isdst: horario de verano(1 activado, 0 no activado,-1 desconocido
  }
}
void ActualizaHora(){configTime(3600, 3600, "pool.ntp.org");  }
void MuestraHora()
{
  //Día de la semana, mes, día, año, hora:minutos:segundos"
  Serial.print("Hora actual: ");
  Serial.print(hora);
  Serial.print(':');
  Serial.print(minuto);
  Serial.print(':');
  Serial.print(segundo);
  Serial.println();
  
}
///// actuales segundos //////
long SegActu(){ 
    LeerHora();
    long segActual=hora*60;
    segActual=segActual+minuto;
    segActual=segActual*60;
    segActual=segActual+segundo;
    return segActual; // devolvemos el segundo que en que estamos en el dia(24h)
}
