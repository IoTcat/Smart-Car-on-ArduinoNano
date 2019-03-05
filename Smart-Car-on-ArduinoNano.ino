/**
 * Smart-Car-on-ArduinoNano 
 *
 * @category SmartCar
 * @package Smart-Car-on-ArduinoNano
 * @copyright Jianzhi Fan, Xiaotian Li, Yimian Liu
 * @license GNU General Public License 2.0
 * @version 0.0.1
 */

#include "Adafruit_NeoPixel.h"  //彩色灯珠驱动
#include "comm.h"               //传感器数据读取
#include "motor.h"              //电机控制

#define PIN            4
#define NUMPIXELS      2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



void setTimeout(auto function,const int delay)
{
    static bool on = 1;
    if(on == 1){
        static unsigned long startTime = millis(); 

        if(millis() - startTime > delay){
            function();
            on == 0;
        }
    }
}

void setInterval(auto function, const int delay)
{
    static unsigned long startTime = millis(); 

    if(millis() - startTime > delay){
        function();
        startTime = millis();
    }
}

void setSwitch(auto function1, auto function2, const int delay1, const int delay2)
{
    static unsigned long startTime = millis(); 

    if(millis() - startTime < delay1){
        function1();
    }else if(millis() - startTime >= delay1 && millis() - startTime < delay1 + delay2){
        function2();
    }else if(millis() - startTime >= delay1 + delay2){
        startTime = millis();
    }
}

void slowWrite(int pin, int state, unsigned int delay)
{
    static int startTime = millis();
    if(millis() - startTime >= delay){
        
    }
    analogWrite(pin, (((millis() - startTime) % delay) / delay) * 255);
}

/*
        slowWrite(int pin, int state, unsigned int delay){
            static int startTime = millis();
            if(millis() - startTime < delay){
                analogWrite(pin, ((millis() - startTime) / delay) * 255);
                Serial.println(((millis() - startTime) / delay) * 255);
            }else{
                delete this;
            }
        }
*/



///////Test Version Only
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    shift_reg_init();   //传感器初始化
    motor_init();       //电机初始化
    pixels.begin();     //彩色灯珠初始化
    Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {

  setTimeout([]{setInterval([]{digitalWrite(LED_BUILTIN, HIGH);}, 3000);},1000);

  setInterval([]{digitalWrite(LED_BUILTIN, LOW);}, 3000);


}
