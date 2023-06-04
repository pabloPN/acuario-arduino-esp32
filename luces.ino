void Luces(){
    long segActual=SegActu(); // leemos el segundo acutual de dia
    // encender o apagar rele de luces
    if (!bloqueoL){
        ////// Enciende el Rele //////
       if (segActual>(lucesOn-60)&&segActual<(lucesOff+40)){digitalWrite(PIN_R_LUZ,HIGH);}else{digitalWrite(PIN_R_LUZ,LOW);}
        // AZUL //
       if (segActual>=lucesOn && segActual<=lucesOn+tiempoDimmeo){
            //dimmer ++ mayor de enciende y menor de tiempo de dimeado 
            dimmerA=map(segActual,lucesOn,lucesOn+tiempoDimmeo,0,dimmerAzMax);// calculamos el dimmer exacto segun el segundo que estamos
       }else if(segActual>lucesOn+tiempoDimmeo && segActual<lucesOff-tiempoDimmeo){
            // maximo mayor de enciende+tiempodedimmeado y menos de apaga-Tdimmeado
            dimmerA=dimmerAzMax;
       }else if(segActual>=lucesOff-tiempoDimmeo && segActual<=lucesOff){
            //dimmer -- mayor de apaga-tdimm y menor apaga
            dimmerA=map(segActual,lucesOff-tiempoDimmeo,lucesOff,dimmerAzMax,0);
       }else{
            // minnimo todo lo demas
            dimmerA=0;
       }
           // BLANCO //
       if (segActual>=lucesOn+retrasoBl && segActual<=lucesOn+retrasoBl+tiempoDimmeo){
            //dimmer ++ mayor de enciende y menor de tiempo de dimeado 
            dimmerB=map(segActual,lucesOn+retrasoBl,lucesOn+retrasoBl+tiempoDimmeo,0,dimmerAzMax);// calculamos el dimmer exacto segun el segundo que estamos
       }else if(segActual>lucesOn+retrasoBl+tiempoDimmeo && segActual<lucesOff-retrasoBl-tiempoDimmeo){
            // maximo mayor de enciende+tiempodedimmeado y menos de apaga-Tdimmeado
            dimmerB=dimmerAzMax;
       }else if(segActual>=lucesOff-retrasoBl-tiempoDimmeo && segActual<=lucesOff-retrasoBl){
            //dimmer -- mayor de apaga-tdimm y menor apaga
            dimmerB=map(segActual,lucesOff-retrasoBl-tiempoDimmeo,lucesOff-retrasoBl,dimmerAzMax,0);
       }else{
            // minnimo
            dimmerB=0;
       }
   }
   ledcWrite(CANAL_AZUL, dimmerA);
   ledcWrite(CANAL_BLANCO, dimmerB);
}
