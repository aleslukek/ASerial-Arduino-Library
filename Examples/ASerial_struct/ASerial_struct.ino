/*
   This sketch uses structures to run and change variables.
 */
#include <ASerial.h>

#define numOfUniversalElements 2   //number of constructors (changable variables)
#define numOfActionElements 1   //number of constructors (action variables)

ASerial ASerial;      //Construct
#define counter 1   //Starting counter value
#define test 20     //Starting test value
ChangableUniversal list[numOfUniversalElements];     //Starting universal changable stucture
RunAction actionList[numOfActionElements];

#define ledPin 5 //led on pin 3 will turn on or off if led=1 or led=0 will be written to Serial console.

void setup(){
        ASerial.begin(115200);
        constrSetup();
        pinMode(ledPin, OUTPUT);
}

void constrSetup(){
        list[0].name = "test";      //name - MUST ALL BE LOWER CASE
        list[0].valueType = 3;      //1 bool, 2 char, 3 byte, 4 int, 5 double, 6 float, 7 long, 8 unsigned int, 9 unsigned long
        list[0].byteValue = test;     //must be byteValue, because this is byte type
        list[0].description = "Test variable that is here only for test purpuses.";
        list[0].change = 2;     //Will ALWAYS increase value by 2, does not matter what value you put into serial.

        list[1].name = "counter";     //name - MUST ALL BE LOWER CASE
        list[1].valueType = 4;      //1 bool, 2 char, 3 byte, 4 int, 5 double, 6 float, 7 long, 8 unsigned int, 9 unsigned long
        list[1].intValue = counter;     //must be intValue, because this is int type
        list[1].description = "Main counter.";
        list[1].change = 0;     //Will get the value you put into serial.

        actionList[0].name = "led";
        actionList[0].runEvent = 1;
        actionList[0].description = "Turn led on and off.";
}

void loop() {
        if(Serial.available() > 0) {
                String serialName = Serial.readStringUntil('=');
                float serialValue = Serial.parseFloat();
                ASerial.printLine();
                ASerial.print("Your input:", serialName);
                ASerial.println("=  ",serialValue);
                if(ASerial.readSerial(list, numOfUniversalElements, serialName, serialValue) == 0) {
                        int action = ASerial.findAction(actionList, numOfActionElements, serialName);
                        if(action == 0) {//No variable was found
                                ASerial.println(" Variable does not exist, or it is not changable.");
                        }else if(action == -1) {//Variable was found, but description was printed, no action

                        }else if(action == actionList[0].runEvent) {//event on "led" input; action == 1
                                if(serialValue > 0) {
                                        digitalWrite(ledPin, HIGH);
                                        ASerial.println("Turn led on.");
                                }else{
                                        digitalWrite(ledPin, LOW);
                                        ASerial.println("Turn led off.");
                                }
                        }else{
                                ASerial.println("No action written for this command.");
                        }

                }else{
                        //ASerial.println(" Variable changed it's value.");
                }
                ASerial.printLine();
        }
        ASerial.print("Counter: ", list[1].intValue);
        ASerial.println("- Test: ", list[0].intValue);
        list[1].intValue += 3;      //Increase counter by 3
        delay(1000);
}
