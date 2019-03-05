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
#include "ovo.h"

#define PIN            4
#define NUMPIXELS      2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

slowWrite m;

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
    m.set(LED_BUILTIN, 2000);
    m.run();

    setTimeout([]{setInterval([]{m.high();}, 6000);},3000);
    setInterval([]{m.low();}, 6000);


}
