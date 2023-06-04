void LeerS2(){
    String a;
    String variable="";
    String valor="";
    //Serial.println("leers2");
    while(Serial2.available()) {
        a= Serial2.readString();// read the incoming data as string
        variable =a.substring( 0,a.indexOf (".") );
        valor =a.substring( a.indexOf (".")+1,a.length() );
        //Serial.print("Recivimos: ");Serial.print(a);Serial.println("*");
    }
  if(a!=""){
    //Serial.print("variable: ");Serial.println(variable);
    //Serial.print("valor: ");Serial.println(valor);

      if(variable=="subida"){
            digitalWrite(PIN_R_SUBIDA,!digitalRead(PIN_R_SUBIDA));
             boton("Bsub",digitalRead(PIN_R_SUBIDA));
      }else if(variable=="Bsubida"){
            bloqueoS=!bloqueoS;
             botonT("Bsub",bloqueoS);
      }else if(variable=="luces"){
            digitalWrite(PIN_R_LUZ,!digitalRead(PIN_R_LUZ));
             boton("Bluc",digitalRead(PIN_R_LUZ));
      }else if(variable=="Bluces"){
            bloqueoL=!bloqueoL;
             botonT("Bluc",bloqueoL);
      }else if(variable=="calentador"){
            digitalWrite(PIN_R_CALENTADOR,!digitalRead(PIN_R_CALENTADOR));
             boton("Bcal",digitalRead(PIN_R_CALENTADOR));
      }else if(variable=="Bcalentador"){
            bloqueoC=!bloqueoC;
             botonT("Bcal",bloqueoC);
      }else if(variable=="enfriador"){
            digitalWrite(PIN_R_ENFRIADOR,!digitalRead(PIN_R_ENFRIADOR));
             boton("Benf",digitalRead(PIN_R_ENFRIADOR));
      }else if(variable=="Benfriador"){
            bloqueoE=!bloqueoE;
             botonT("Benf",bloqueoE);
      }else if(variable=="maxT"){
            int temp= valor.substring(0,valor.indexOf ( "." )).toInt();
            Mw(18,temp);//escrinimos en memoria dirrecion , valor
            tempMax=temp;
            temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();
            Mw(19,temp);//escrinimos en memoria dirrecion , valor
            tempMax=tempMax+((float)temp/100); 
            String a="Tmax.txt=\""+String(tempMax)+"\"";// se puede borrar
            Serial2.print(a);
      }else if(variable=="minT"){
            int temp= valor.substring(0,valor.indexOf ( "." )).toInt();
            Mw(20,temp);//escrinimos en memoria dirrecion , valor
            tempMin=temp;
            temp=  valor.substring( valor.indexOf ( "." )+1   ,valor.length()).toInt();
            Mw(21,temp);//escrinimos en memoria dirrecion , valor
            tempMin=tempMin+((float)temp/100); 
            String a="Tmin.txt=\""+String(tempMin)+"\"";// se puede borrar
            Serial2.print(a);
      }else if(variable=="dim"){
    // dim.54   ->  h0.val=67 y nciento.val=67
            
            digitalWrite(PIN_R_LUZ,HIGH);
            //bloqueoL=true;
            dimmerA=map(valor.toInt(),0,100,0,255);
            dimmerB=map(valor.toInt(),0,100,0,255);
            Serial2.print("h0.val="+valor);ff();
            Serial2.print("nciento.txt=\""+valor+"\"");ff();
            //Serial2.print("Bluc.pco=47104");ff();//rojo bloqueo ture
            Serial2.print("Bluc.bco=62400");ff();//naranja encendido
      }else if(variable=="actualiza"){
          Pantalla();
      }else{
        //numeros
        //Serial.println(a);
      }
       
  }
  
}
void Pantalla()
{
  Serial.println("entra");
            String a="";
             a="Tmin.txt=\""+String(tempMin)+"\"";// se puede borrar
             Serial2.print(a);ff();
             a="Tmax.txt=\""+String(tempMax)+"\"";// se puede borrar
             Serial2.print(a);ff();
             a= String(TempAcuario());
             Serial2.print("tempE.txt=\""+a.substring(0,a.indexOf ( "." ))+"\"");ff();
             Serial2.print("tempD.txt=\""+a.substring(a.indexOf ( "." )+1,a.length())+"\"");ff();
             Serial2.print("hora.val="+String(hora));ff();
             Serial2.print("minuto.val="+String(minuto));ff();
             Serial2.print("dia.val="+String(dia));ff();
             String arr[]={" Enero"," Febreo"," Marzo"," Abril"," Mayo"," Junio"," Julio"," Agosto"," Septiembre"," Octubre"," Noviembre"," Diciembre"};
             Serial2.print("mes.txt=\""+arr[mes]+"\"");ff();
             Serial2.print("ano.val="+String(ano));ff();
             String arr2[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
             Serial2.print("diam.txt=\""+arr2[diaSemana])+"\"";ff();
             Serial2.print("h0.val="+String(map(dimmerA,0,255,0,100)));ff();
             Serial2.print("nciento.txt=\""+String(map(dimmerA,0,255,0,100))+"\"");ff();
             botonT("Benf",bloqueoE);
             botonT("Bsub",bloqueoS);
             botonT("Bcal",bloqueoC);
             botonT("Bluc",bloqueoL);
             boton("Benf",digitalRead(PIN_R_ENFRIADOR));
             boton("Bsub",digitalRead(PIN_R_SUBIDA));
             boton("Bcal",digitalRead(PIN_R_CALENTADOR));
             boton("Bluc",digitalRead(PIN_R_LUZ));
             
}
void ff(){Serial2.write(0xff);Serial2.write(0xff);Serial2.write(0xff);}
void botonT(String a,boolean b){
      if (b){
        //Serial.print(a+".pco=47104"); //rojo=63488 verde=13952 rojo oscuro 47104
        Serial2.print(a+".pco=47104"); //rojo=63488 verde=13952 rojo oscuro 47104
      }else{
        //Serial.print(a+".pco=65535"); //blanco
        Serial2.print(a+".pco=65535"); //blanco
      } 
      ff();
}
void boton(String a,boolean b){
      if (b){
        //Serial.print(a+".bco=62400"); //naranja
        Serial2.print(a+".bco=62400"); //naranja
      }else{
        //Serial.print(a+".bco=14791"); //gris
        Serial2.print(a+".bco=14791"); //gris
      } 
      ff();
}
