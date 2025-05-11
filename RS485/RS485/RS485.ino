//GND is black
//Vcc is brown
//blue is data-A4 pin
//yellow goes to ground
//0-3v output
//every 1 V change corresponds to 120 deg rotation
//val is the bit number where 1024 bits=5v
//make sure that the serial monitor baud rate is 115200
int analogPin = A4;
int val = 0;
float volt = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //uncomment the line below for Arduino Giga R1, keep commented for UNO
  //analogReadResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);

  //The line below creates a voltage value when using an UNO
  volt = val* .00489;

  //The line below creates a voltage value when using a Giga R1
  //volt = val * (3.3 / 4095.0);
  //one of the above lines should be commented, while the other is not

  //Serial.println(volt);
  if (.09375 <= volt && volt < .28125){
    Serial.println("SSW");
  } 
  else if (.28125 <= volt && volt < .46875) {
    Serial.println("SW");
  } 
  else if (.46875 <= volt && volt < .65625) {
    Serial.println("WSW");
  }
  else if (.65625 <= volt && volt < .84375) {
    Serial.println("W");
  }
  else if (.84375 <= volt && volt < 1.03125) {
    Serial.println("WNW");
  }
  else if (1.03125 <= volt && volt < 1.21875) {
    Serial.println("NW");
  }
  else if (1.21875 <= volt && volt < 1.40625) {
    Serial.println("NNW");
  }
  else if (1.40625 < volt && volt < 1.59375){
    Serial.println("N");
  }
  else if (1.59375 < volt && volt <= 1.78125) {
    Serial.println("NNE");
  }
  else if (1.78125 <= volt && volt <= 1.96875) {
    Serial.println("NE");
  }
  else if (1.96875 <= volt && volt < 2.15625) {
    Serial.println("ENE");
  }
  else if (2.15625 <= volt && volt < 2.34375) {
    Serial.println("E");
  }
  else if (2.34375 <= volt && volt < 2.53125) {
    Serial.println("ESE");
  }
  else if (2.53125 <= volt && volt < 2.71875) {
    Serial.println("SE");
  }
  else if (2.71875 <= volt && volt < 2.90625) {
    Serial.println("SSE");
  }
  else {
    Serial.println("S");
  }
  //Serial.println(volt);
  delay(1000);
}


