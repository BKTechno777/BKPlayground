#include <Servo.h>
Servo my_servo;

void setup() {
  my_servo.attach(10);

}

void loop() {
  
  // These loops shall rorate the servo motor between 0-180 degrees and 180-0 degrees.
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
}
