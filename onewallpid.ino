#define IR1 19 //front sensor
#define IR_RIGHT 17
#define IR_LEFT 18
#define PWM1 10 //right
#define PWM2 11 //left
#define IN3 5 //right
#define IN4 6 //right
#define IN1 7 //left
#define IN2 8 //left

bool start = false;

//constants






void setup()
{
  //IR Sensor pin
  pinMode(IR1, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);
  //pwm pins
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);

  //motor control pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Serial.begin(9600);
}

void loop()
{
  if (start == false)
  {
    delay(3000);
    start = true;
  }

  int left_sensor = analogRead(IR_LEFT) - 11;
  int right_sensor = analogRead(IR_RIGHT);
  int front_sensor = analogRead(IR1);

  int left_error = left_sensor - 971;
  int right_error = (right_sensor - 971);

  float left_speed_l = 100 + 1 * left_error;
  float right_speed_l = 107 - 1 * left_error;

  float left_speed_r = 100 - 1 * right_error;
  float right_speed_r = 107 + 1 * right_error;



  if (left_sensor > 480)
  {
    if (front_sensor > 988)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(PWM1, 80);
  
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(PWM2, 87);
      delay(500);

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(PWM1, 57);
      
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(PWM2, 59);
      delay(900);
    }
    else 
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(PWM1, left_speed_l);
      
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(PWM2, right_speed_l);
    }
  }
  else 
  {
    if (front_sensor > 988)
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(PWM1, 80);
  
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(PWM2, 87);
      delay(500);

      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(PWM1, 57);
      
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(PWM2, 59);
      delay(900);
    }
    else
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(PWM1, left_speed_r);
      
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(PWM2, right_speed_r);
    }
  }




//  Serial.println(left_error);
//  Serial.println(right_error);
//  delay(1000);
//  Serial.println(left_speed_l);
//  Serial.println(right_speed_l);
//  delay(1000);

  

  






  

}
