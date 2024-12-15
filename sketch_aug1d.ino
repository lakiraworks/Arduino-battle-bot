int in1 = 2;
int in2 = 3;
int enable1 = 5;  

int channel_2 = 6;  

void setup() 
{
  pinMode(channel_2, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int pwm = 0;
  int value = pulseIn(channel_2, HIGH, 250000);
  
  if(value==0)
  {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
  }
  
  else if(value > 1530)
  {
      pwm = map(value, 1530, 2000, 0, 350); 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enable1, pwm);
  }
  
  else if(value < 1460)
  {
      pwm = map(value, 1560, 1000, 0, 300); 
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enable1, pwm);
  }
  
  else
  {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
  }
  
  delay(10);
}
