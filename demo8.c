int SensorLED = 13;
int SensorINPUT = 3;
unsigned char state = 0;

void setup()
{
    pinMode(SensorLED, OUTPUT);
    pinMode(SensorINPUT, INPUT);

    attachInterrupt(1, blink, RISING);
}

void loop()
{
    if (state == 1)
    {
        state = 0;
        digitalWrite(SensorLED, HIGH);
        delay(50);
    }
    else
    {
        digitalWrite(SensorLED, LOW);
    }
}

void blink()
{
    state = 1;
}
