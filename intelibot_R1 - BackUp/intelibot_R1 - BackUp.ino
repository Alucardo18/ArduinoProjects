String inputString = "";
boolean stringComplete = false;

void setup() {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);
inputString.reserve(200);


}

void loop() {
  
int RED_LED =11;
int GREEN_LED = 10;
int BLUE_LED =9;

  if (stringComplete){

///RGB
 if (inputString.startsWith("#")){
      String value = inputString.substring(1);
      
        if (value.startsWith("R")){
          value = value.substring(1);
          Serial.println(value.toInt());
          analogWrite(RED_LED,value.toInt());
          inputString="";
          stringComplete = false;
          } 
          
        if (value.startsWith("G")){
          value = value.substring(1);
          Serial.println(value.toInt());
          analogWrite(GREEN_LED,value.toInt());
          inputString="";
          stringComplete = false;
          }
          
        if (value.startsWith("B")){
          value = value.substring(1);
          Serial.println(value.toInt());
          analogWrite(BLUE_LED,value.toInt());
          inputString="";
          stringComplete = false;
          }

             //CONTROL DE MOTORES
             if (value.startsWith("F")){
            Serial.print(value);
             adelante();
            inputString="";
            stringComplete = false;
            }
  
            if (value.startsWith("S")){
            Serial.print(value);
             detenido();
            inputString="";
            stringComplete = false;
            }
              if (value.startsWith("D")){  // no puede ser B por que interfiere con el caracter del color azul "BLUE"
            Serial.print(value);
             atras();
            inputString="";
            stringComplete = false;
            }

            if (value.startsWith("X")){   // no puede ser R por que interfiere con el valor del caracter "RED"
            Serial.print(value);
             derecha();
            inputString="";
            stringComplete = false;
            }
            
              if (value.startsWith("L")){
            Serial.print(value);
             izquierda();
            inputString="";
            stringComplete = false;
            }
          
        }
        
      }
    }



void serialEvent(){
  while (Serial.available()){
   char inChar = (char)Serial.read();
   inputString += inChar;
   
   if (inChar == '\n'){
    
      stringComplete = true;
    }    
  } 
}


////RUTINAS DE MOVIMIENTO
void adelante (){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  }
  void atras (){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  }
  void derecha (){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  }
  void izquierda (){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  }
  void detenido (){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  }
