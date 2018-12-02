


#include <Ultrasonic.h>
#include "pitches.h"

Ultrasonic ultrasonic(4,2); // (Trig PIN,Echo PIN)
String inputString = "";
boolean stringComplete = false;
//sensor de obstaculos
int sensor1_Valor = 0;
int sensor2_Valor = 0;
int sensor1_pin = 0;
int sensor2_pin = 1;
boolean autonomous = false; // AUTONOMOUES FLAG

String readString;



void setup() {
marioCoinTone ();

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

/*URRENT MAPPINGS

PWM RGB LED ->

9 -> BLUE
10 -> GREEN
11 -> RED
NEW MAPPINGS FOR NEW RGB LED
9 -> GREEN
10 -> RED
11 -> BLUE
*/

  if (stringComplete){

///RGB
 if (inputString.startsWith("#")){    // CONTROL DE LED RGB
      String value = inputString.substring(1);
      char ind1; // , locations
      char ind2;
      char ind3;
      char ind4;
      String redValue;
      String greenValue;
      String blueValue;

        ind1 = value.indexOf(',');
        redValue = value.substring(3,ind1);
        ind2 = value.indexOf(',', ind1+1 );
        greenValue = value.substring(ind1+1, ind2+1);
        ind3 = value.indexOf(',', ind2+1 );
        blueValue = value.substring(ind2+1, ind3+1);

     // Serial.print("redValue = ");   //
     // Serial.println(redValue.toInt());
     // Serial.print("greenValue = ");
     // Serial.println(greenValue.toInt());
     // Serial.print("blueValue = ");
     // Serial.println(blueValue.toInt());

      analogWrite(RED_LED,redValue.toInt());
      analogWrite(GREEN_LED,greenValue.toInt());
      analogWrite(BLUE_LED,blueValue.toInt());
      cleanInput();

        }

          else if (inputString.startsWith("%")){  //CONTROL DE MMOTORES + FUNCIONALIDADES ESPECIALES
             String value = inputString.substring(1);

             if (value.startsWith("STOP")){
             Serial.print(value);
              detenido();
             }

                 //CONTROL DE MOTORES
               if (value.startsWith("FORWARD")){
              Serial.print(value);
               adelante();
              }

                if (value.startsWith("BACKWARD")){  // no puede ser B por que interfiere con el caracter del color azul "BLUE"
              Serial.print(value);
               atras();
              }

              if (value.startsWith("RIGHT")){   // no puede ser R por que interfiere con el valor del caracter "RED"
              Serial.print(value);
               derecha();
              }

                if (value.startsWith("LEFT")){
              Serial.print(value);
               izquierda();
              }

              //
               if (value.startsWith("HONK")){
              Serial.print(value);
              mentada ();
              }

//////////////////////////////
                  ///MODOS AUTONOMOS
               if (value.startsWith("BATTLE")){
              Serial.print(value);
              stormsTone();
              autonomous = true;
                while (autonomous){
                 battleMode();
                        if (Serial.available() > 0){ // DETIENE EL LOOP
                            detenido ();
                          autonomous = false;
                          break;
                        }
                  }
              }
              //RANGER
               if (value.startsWith("RANGER")){
              Serial.print(value);
              r2d2Tone ();
              autonomous = true;
                while (autonomous){
                 rangerMode();
                        if (Serial.available() > 0){ // DETIENE EL LOOP
                            detenido ();
                          autonomous = false;
                          break;

                        }
                }

              }

              cleanInput();
          }

      }

    }

void cleanInput(){
  inputString="";
  stringComplete = false;
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

  //MODOS AUTONOMOS



  void rangerMode (){
sensor1_Valor = analogRead(sensor1_pin);
sensor2_Valor = analogRead(sensor2_pin);
      adelante();
      if (ultrasonic.Ranging(CM) <= 10){

      atras();
      delay(200);
      }
      if (sensor1_Valor >= 550){
      izquierda ();
      delay(500);
      }
        if (sensor2_Valor >= 800){
      derecha ();
      delay(500);
      }
  }

  void battleMode (){
sensor1_Valor = analogRead(sensor1_pin);
sensor2_Valor = analogRead(sensor2_pin);


     if (ultrasonic.Ranging(CM) <= 20){
       adelante();
     }
     if (sensor1_Valor >= 400){
     derecha ();
     //delay(500);
     }
     if (sensor2_Valor >= 700){
     izquierda ();
     //delay(500);
     }
     else if (ultrasonic.Ranging(CM) > 20){
     detenido();
     }

  }
