
int sensePin = A1;  //This is the Arduino Pin that will control Relay #1
int sensorValue = 0;    //The variable we will use to store the sensor input
//int sensePin = A0;  //This is the Arduino Pin that will control Relay #1
int sensorInput;    //The variable we will use to store the sensor input
double temp; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Start the Serial Port at 9600 baud (default)

}
void loop() {
  // put your main code here, to run repeatedly: 
  sensorValue = analogRead(A1);    //read the analog sensor and store it
            
  sensorInput = analogRead(A0);    //read the analog sensor and store it
  temp = (double)sensorInput / 1024;       //find percentage of input reading
  temp = temp * 5;                 //multiply by 5V to get voltage
  temp = temp - 0.5;               //Subtract the offset 
  temp = temp * 100;               //Convert to degrees 


  if (temp > 28 ) {
   Serial.print("Current Temp is hot i.e.: ");
   Serial.println(temp);
  }
  
  else if (temp < 28) {
    Serial.print("Current Temp is cold i.e.: ");
    Serial.println(temp);
  }
   else{
    Serial.print("Current Temp: ");
    Serial.println(temp);
    }

if (sensorValue > 70 ) {
   Serial.print("Current Light is high i.e.: ");
   Serial.println(sensorValue);
  }
  
  else if (sensorValue < 60) {
    Serial.print("Current Light is low i.e.: ");
    Serial.println(sensorValue);
  }
   else{
    Serial.print("Light seems good: ");
    Serial.println(sensorValue);
    }

  
  //Serial.print("Current Temp: ");
  
  //Serial.println(temp);

  //Serial.print("Current Light: ");
  //Serial.println(sensorValue);
  
  //Serial.end();
  delay(10000);
}








