/*
   This sketch uses structures to run and change variables.
 */
#include <ASerial.h>

#define numOfIntElements 1   //number of int elements (changable variables)
#define numOfPlusValueElements 1   //number of increase 1 elements (changable variables)

ASerial ASerial;      //Construct
int counter = 1;   //Starting counter value
byte test = 20;     //Starting test value
#define changeValue 5 //change members of plusValuePointers by 5. If no value is provided, than it changes values by 1

String intVarNames[numOfIntElements] = {"counter"};
int *intVarPointers[numOfIntElements] = {&counter};
String plusValueVarNames[numOfPlusValueElements] = {"test"};
byte *plusValuePointers[numOfPlusValueElements] = {&test};

void setup(){
        ASerial.begin(115200);
}

void loop() {
        if(Serial.available() > 0) {
                String serialName = Serial.readStringUntil('=');
                float serialValue = Serial.parseFloat();
                ASerial.printLine();
                ASerial.print(" Your input:", serialName);
                ASerial.println("=  ",serialValue);
                if(ASerial.readSerial(intVarNames, intVarPointers, numOfIntElements, serialName, serialValue) == 0) {
                        if(ASerial.readSerialIncreaseValue(plusValueVarNames, plusValuePointers, numOfPlusValueElements, serialName, changeValue) == 0) {
                                ASerial.println(" Variable does not exist, or it is not changable.");
                        }else{
                                //ASerial.println(" Variable changed it's value by 1");
                        }
                }else{
                        //ASerial.println(" Variable changed it's value.");
                }
                ASerial.printLine();
        }
        ASerial.print("Counter: ", counter);
        ASerial.println("- Test: ", test);
        counter += 3;      //Increase counter by 3
        delay(1000);
}
