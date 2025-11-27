#include <Servo.h>

int pos = 0;

Servo servo;

void setup()
{
  servo.attach(9, 500, 2500);
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(15); 
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(15); 
  }
}
