#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);

float value = 0;
float rev = 0;
int rpm, count = 0;
int oldtime = 0;
int time;

void isr() // interrupt service routine
{
    rev++;
    count++;
}

void setup()
{

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();
    attachInterrupt(0, isr, RISING); // attaching the interrupt
}

void loop()
{

    delay(1000);
    detachInterrupt(0);         // detaches the interrupt
    time = millis() - oldtime;  // finds the time
    rpm = (rev / time) * 60000; // calculates rpm
    oldtime = millis();         // saves the current time
    rev = 0;

    attachInterrupt(0, isr, RISING);

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("COUNT");
    display.setCursor(70, 0);
    display.println(count);
    display.setTextSize(1.5);
    display.setTextColor(WHITE);
    display.setCursor(34, 20);
    display.println("RPM:");
    display.setTextSize(2);
    display.setCursor(40, 48);
    display.println(rpm);
    display.display();
}