
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


#include <Ultrasonic.h>
#include <pitches.h>

Ultrasonic ultrasonic(4,2); // (Trig PIN,Echo PIN)
String inputString = "";
boolean stringComplete = false;
//sensor de obstaculos
int sensor1_Valor = 0;
int sensor2_Valor = 0;
int sensor1_pin = 0;
int sensor2_pin = 1;

void setup() {
  ///Mario coin
    tone(13,NOTE_E6,125);
  delay(130);
  tone(13,NOTE_G6,125);
  delay(130);
  tone(13,NOTE_E7,125);
  delay(130);
  tone(13,NOTE_C7,125);
  delay(130);
  tone(13,NOTE_D7,125);
  delay(130);
  tone(13,NOTE_G7,125);
  delay(125);
  noTone(13);
  //
  
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

           
        }

          else if (inputString.startsWith("%")){
             String value = inputString.substring(1);

                 //CONTROL DE MOTORES
               if (value.startsWith("FORWARD")){
              Serial.print(value);
               adelante();
              inputString="";
              stringComplete = false;
              }
    
              if (value.startsWith("STOP")){
              Serial.print(value);
               detenido();
              inputString="";
              stringComplete = false;
              }
                if (value.startsWith("BACKWARD")){  // no puede ser B por que interfiere con el caracter del color azul "BLUE"
              Serial.print(value);
               atras();
              inputString="";
              stringComplete = false;
              }
  
              if (value.startsWith("RIGHT")){   // no puede ser R por que interfiere con el valor del caracter "RED"
              Serial.print(value);
               derecha();
              inputString="";
              stringComplete = false;
              }
              
                if (value.startsWith("LEFT")){
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
