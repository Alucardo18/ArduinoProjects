


void setup() {
  String string;
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
int RED_LED =11;
int GREEN_LED = 10;
int BLUE_LED =9;
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps


}

void loop() {
 

        // send data only when you receive data:
        if (Serial.available() > 0) {
          byte incomingByte  ;   // for incoming serial data
                // read the incoming byte:
                incomingByte = Serial.read();
                    // Serial.print("I received: ");
               // Serial.println(incomingByte); 
              //String inputString = String (incomingByte);
                   // say what you got:
                 Serial.print("I received: ");
                Serial.print(incomingByte);
      

                     if (incomingByte == 'A'){
                        Serial.print("I received: ");
                Serial.println(incomingByte);
                    adelante ();
                    
                    }
                     if (incomingByte == 'B'){
                       Serial.print("I received: ");
                Serial.println(incomingByte);                   
                    atras ();
                    }
                     if (incomingByte == 'R'){
                          Serial.print("I received: ");
                Serial.println(incomingByte); 
                    derecha ();
                    }
                     if (incomingByte == 'L'){
                          Serial.print("I received: ");
                Serial.println(incomingByte); 
                    izquierda ();
                    }
                     if (incomingByte == 'S'){
                          Serial.print("I received: ");
                Serial.println(incomingByte); 
                    detenido ();
                    }
                    
        }
}


///////METODOS DE MOVILIDAD MOTRIZ
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
