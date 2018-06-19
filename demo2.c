void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(LED_BUILTIN,HIGH);
        delay(150);
        digitalWrite(LED_BUILTIN,LOW);
        delay(100);// wait for a second
    }
    delay(100); 
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(LED_BUILTIN,HIGH);
        delay(400);
        digitalWrite(LED_BUILTIN,LOW);
        delay(100);// wait for a second
    }

    delay(100); 
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(LED_BUILTIN,HIGH);
        delay(150);
        digitalWrite(LED_BUILTIN,LOW);
        delay(100);// wait for a second
    }

    delay(5000); 
}
