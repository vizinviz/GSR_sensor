const int GSR=A0;
int sensorValue=0;
int gsr_average=0;

//Human Resistance in ohm = ((1024+2*Serial_Port_Reading)*10000)/(512-Serial_Port_Reading)

void setup(){
  Serial.begin(9600);
}

void loop(){
  long sum=0;
  for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
      {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      delay(5);
      }
   gsr_average = sum/10;
   Serial.println(gsr_average);

   
}
