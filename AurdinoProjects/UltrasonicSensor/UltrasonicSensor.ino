
#include <Servo.h>
Servo my_servo;

#define TRIG_PIN 13
#define ECHO_PIN 12

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  my_servo.attach(10);
}

void loop() {
  static int i = 0;
  int direction = 1;
  if(i<=0)
  {
    direction = 1;
  }

  if(i>=145)
  {
    direction = -1;
  }

  my_servo.write(i+direction);
  i=i+direction;
  //These loops shall rorate the servo motor between 0-180 degrees and 180-0 degrees.
  for(int i = 0; i<= 180;i++)
  {
    my_servo.write(i);
    delay(15);
  }

  for(int j=180;j>=0;j--)
  {
    my_servo.write(j);
    delay(15);
  }
  
  Serial.print("ULTRASONIC=");

  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN,HIGH);

  distance = duration * (0.34)/2;

  Serial.print("Distance: ");
  Serial.println(distance);



}
