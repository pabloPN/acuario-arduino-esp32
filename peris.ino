/*
 *AL FINAL NECESITAMOS PIN Y TIEMPO ADITANDO QUE ES IGUAL A MILILITROS QUE QUEREMOS POR TIEMP OUE NECESITA CADA MILILITRO 
 * P1=X P1tA=P1totMLa*P1tiempo1ML
poder aditar mas o menos veces al dia tamaño de array    int myarray[5] = {19, 10, 8, 17, 9};    int size = sizeof(myarray) / sizeof(int);
pasos
1 definimos el pin
2 declaramos delay de cada peristaltica
3 guardamos en "delay" el tiempo con =(mltotales*(memoria*100)+memoria)
*/
void Adita(){
   if (!bloqueoPERI){
      //(h*60)+minuto
      int adita1[] = {(0*60)+30, (10*60)+1, (20*60)+1};// 00:30, 10:00,20:00 esto es el tiempo en minutos
      if ((SegActu()/60)>adita1[horaArrayMagnesio]){
         digitalWrite(PIN_MAGNESIO,HIGH);delay(delayMagnesio);digitalWrite(PIN_MAGNESIO,LOW);
         horaArrayMagnesio++;
         if (horaArrayMagnesio>=3) horaArrayMagnesio=0;
      }
      int adita2[] = {(3*60)+30,(13*60)+1,(23*60)+30};// 3:30,13:00,23:30 tiempo
      if ((SegActu()/60)>adita2[horaArrayCalcio]){
         digitalWrite(PIN_CALCIO,HIGH);delay(delayCalcio);digitalWrite(PIN_CALCIO,LOW);
         horaArrayCalcio++;
         if (horaArrayCalcio>=3) horaArrayCalcio=0;
      }
      int adita3[] = {(3*60)+25,(13*60)+5,(23*60)+25};// tiempo 3:25,13:05,23:25
      if ((SegActu()/60)>adita3[horaArrayKh]){
         digitalWrite(PIN_KH,HIGH);delay(delayKh);digitalWrite(PIN_KH,LOW);
         horaArrayKh++;
         if (horaArrayKh>=3) horaArrayKh=0;
      }
   }
}
