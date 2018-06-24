#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int currentNumber = 0;
#if 1
long codes[12]= //该数组用来存放红外遥控器发出的红外码
{
    0xFD30CF,0xFD08F7, // 0 ,1
    0xFD8877,0xFD48B7, // 2 ,3
    0xFD28D7,0xFDA857, // 4 ,5
    0xFD6897,0xFD18E7, // 6 ,7
    0xFD9867,0xFD58A7, // 8 ,9
    0xFD20DF,0xFD609F, // + ,-
};

int number[10][8] =
{
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 1, 1, 0, 1},
    {0 ,0, 1, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 1}
};

void showNumber(int i)
{
#if 1
    for (int pin = 2; pin < 10; pin++)
    {
        digitalWrite(pin, number[i][pin - 2]);
    }
#endif
}

#endif
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
#if 1
    for (int pin = 2; pin < 10; pin++)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }
#endif
}

void loop()
{
#if 0 
    for (int i = 0; i < 10; i++)
    {
        showNumber(i);
        delay(500);
    }
#endif
#if 1
    if (irrecv.decode(&results))
    {
        Serial.println("==");

        Serial.println(results.value);
        for  (int i = 0; i < 12; i++)
        {
            if (results.value == codes[i] && i < 10)
            {
                showNumber(i);
                currentNumber = i;
                Serial.println(i);
                break;
            }
            else if (results.value == codes[10] && currentNumber != 0)
            {
                currentNumber--;
                showNumber(currentNumber);
                Serial.println(currentNumber);
                break;
            }
            else if (results.value == codes[11] && currentNumber != 9)
            {
                currentNumber++;
                showNumber(currentNumber);
                Serial.println(currentNumber);
                break;
            }
        }

        Serial.println(results.value, HEX);
        irrecv.resume();
    }
#endif
}
