/**
 * Smart-Car-on-ArduinoNano 
 *
 * @category SmartCar
 * @package Smart-Car-on-ArduinoNano
 * @copyright Jianzhi Fan, Xiaotian Li, Yimian Liu
 * @license GNU General Public License 2.0
 * @version 0.0.1
 */


void setTimeout(auto function,int delay)
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

void setInterval(auto function,int delay)
{
    static unsigned long startTime = millis(); 

    if(millis() - startTime > delay){
        function();
        startTime = millis();
    }
}

void setSwitch(auto function1, auto function2, int delay1, int delay2)
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



///////Test Version Only
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  setSwitch([]{digitalWrite(LED_BUILTIN, HIGH);},[]{digitalWrite(LED_BUILTIN, LOW);},1000, 2000);


}
