int buttonPin = 2;
int relayPin = 3;
int relayState = HIGH;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int lastReading = 0;
void setup()
{
    pinMode(buttonPin, INPUT);
    pinMode(relayPin, OUTPUT);

    digitalWrite(relayPin, relayState);
    Serial.begin(9600);
}


#if 1
void loop()
{
    int reading = digitalRead(buttonPin);
    Serial.println(reading);
    if (reading == 0 && lastReading == 1)
    {
        relayState = !relayState;
    }

    lastReading = reading;

    digitalWrite(relayPin, relayState);
}
#endif

#if 0 //ok
void loop()
{
    int reading = digitalRead(buttonPin);
    Serial.println(reading);
    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading != buttonState)
        {
            buttonState = reading;
            if (buttonState == HIGH)
            {
                relayState = !relayState;
            }
        }
    }

    digitalWrite(relayPin, relayState);

    lastButtonState = reading;
}
#endif

