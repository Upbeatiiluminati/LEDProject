
void setup() {                
  pinMode(13, OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

char ledSpec;
int PWMVal;
void loop() 
{
  if(Serial.available())
  {
    ledSpec = Serial.read();
    PWMVal = (int) Serial.parseFloat();
    if(ledSpec=='r') analogWrite(11,PWMVal);
      else 
        if(ledSpec=='g') analogWrite(9,PWMVal);
          else 
            if(ledSpec=='b') analogWrite(6,PWMVal);
              
  }
       
}

