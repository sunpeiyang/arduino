float sinVal;
int toneVal;

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

}

void loop()
{
    for (int x= 0; x < 180; x++)
    {
        sinVal = (sin(x * (3.141 / 180)));
        toneVal = 2000 + (int(sinVal * 1000));
        tone(8, toneVal);
        analogWrite(9, x);
        delay(2);

    }
}
