#include <Servo.h>
String text;
void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT); // in1, forward, left
    pinMode(12, OUTPUT); // in4, forward, right
    pinMode(4, OUTPUT);  // in2, backward, left
    pinMode(3, OUTPUT);  // in3, backward, right
    pinMode(9, OUTPUT);  // led white
    pinMode(8, OUTPUT);  // led red
    pinMode(7, OUTPUT);  // buzzer
    // serv_obj.attach(9);
}

void loop()
{
    while (Serial.available())
    {
        delay(100);
        char c = Serial.read();
        text += c;
    }
    if (text.length() > 0)
    {
        Serial.println(text);
        Stop();
        if (text == "F")
        {
            forward();
        }
        else if (text == "B")
        {
            backward();
        }
        else if (text == "R")
        {
            right();
        }
        else if (text == "L")
        {
            left();
        }
        else if (text == "Y")
        {
            digitalWrite(9, 1);
        }
        else if (text == "y")
        {
            digitalWrite(9, 0);
        }
        else if (text == "Z")
        {
            digitalWrite(7, 1);
            delay(1000);
            digitalWrite(7, 0);
        }

        text = "";
    }
}
void forward()
{
    digitalWrite(13, 1);
    digitalWrite(12, 1);
    digitalWrite(4, 0);
    digitalWrite(3, 0);
    digitalWrite(8, 0);
}
void backward()
{
    digitalWrite(13, 0);
    digitalWrite(12, 0);
    digitalWrite(4, 1);
    digitalWrite(3, 1);
    digitalWrite(8, 1);
}
void left()
{
    digitalWrite(13, 0);
    digitalWrite(12, 1);
    digitalWrite(4, 1);
    digitalWrite(3, 0);
    digitalWrite(8, 1);
}
void right()
{
    digitalWrite(13, 1);
    digitalWrite(12, 0);
    digitalWrite(4, 0);
    digitalWrite(3, 1);
    digitalWrite(8, 1);
}
void Stop()
{
    digitalWrite(13, 0);
    digitalWrite(12, 0);
    digitalWrite(4, 0);
    digitalWrite(3, 0);
    digitalWrite(8, 0);
}