// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jra.so )
// more info at www.ardublog.com

#include <Ultrasonic.h>

Ultrasonic ultrasonic(4,2); // (Trig PIN,Echo PIN)
int sensor1_Valor = 0;
int sensor2_Valor = 0;
int sensor1_pin = 0;
int sensor2_pin = 1;

void setup() {
  Serial.begin(9600); 


}

void loop()
{
  sensor1_Valor = analogRead(sensor1_pin);
  sensor2_Valor = analogRead(sensor2_pin);
  Serial.print("Distancia sensor ultrasonico: ");
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  Serial.print("Sensor lateral_UNO: ");
  Serial.println(sensor1_Valor);
  Serial.print("Sensor lateral_DOS: ");
  Serial.println(sensor2_Valor);
  Serial.println(" ");
  delay(200);
 
}
