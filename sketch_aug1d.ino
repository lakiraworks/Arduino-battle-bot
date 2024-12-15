int in1 = 2;
int in2 = 3;

int in3 = 4;
int in4 = 7;

int enable1 = 5;  
int enable2 =9;


int channel_2 = 6;  
int channel_3 =11;


void setup() 
{
  pinMode(channel_2, INPUT);
  pinMode(channel_3, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enable1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  int pwm = 0;

  int value = pulseIn(channel_2,HIGH, 25000);
  int value1= pulseIn(channel_3,HIGH,25000);


  
  if(value==0)
  {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);

      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enable2, 0);
  }
  
  else if(value > 1530)
  {
      pwm = map(value, 1530, 2000, 0, 255); 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enable1, pwm);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enable2, pwm);
  }
  
  else if(value < 1460)
  {
      pwm = map(value, 1550, 1000, 0, 255); 
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enable1, pwm);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enable2, pwm);
  }
  
  else
  {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enable1, 0);
  }
  
  delay(10);
}
