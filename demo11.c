#include <Servo.h>

Servo myservo;
int potpin = 0;
int val = 0;

void setup()
{
    myservo.attach(9);
    Serial.begin(9600);

}

void loop()
{
    val = analogRead(potpin);
    Serial.println(val);

    val = map(val, 0, 1023, 0, 179);
    Serial.println(val);

    myservo.write(val);
    delay(500);
}
