int LED = 13;
int val = 0;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    val = analogRead(0);
    Serial.println(val);
    if (val < 1000)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }

    delay(10);
}
