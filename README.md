# ASerial.h for Arduino

ASerial library is an Arduino tool for easier debugging and serial console.

##### TLDR;

1.  one line serial print text and variables,
2.  print variable changes (old value, new value),
3.  **easily change any variable value via serial console,**
4.  **start / run function from serial console,**
5.  print variable description.

* * *

#### To initialize class:

`ASerial ASerial;`

* * *

#### Print

You can use ASerial class .print and .println to print text and variables in one line:

    ASerial.print("Variable value is ", variable, ", and not much more.");
    ASerial.println("After this variable there will be a new line", variable);

* * *

You can use ASerial class `.printChange` and `.printChangeln` to input text (variable name), old variable value and new variable value and will output:


`ASerial.printChange("Variable", oldValue, newValue);` -> "Variable - old: oldValue; new: newValue "

`ASerial.printChangeln` adds new line to the end.

`.printlnln(somethingsomethingsomethin);` -> Adds single empty line after the one.

`.printLine();` -> prints line.

`.printLineln();` -> prints line and an empty line after.

------

#### One big use of ASerial library is ability to change variable values via serial console.

You can do that in two ways, depending on the way you structured your variables.

**You can either use array of pointers (and leave existing variable structure), best for retro fitting your code.**
To use arrays you have to include three things into your code: You have int variable1, int variable2 and byte variable3 in your code.
1. const variable or `#define numOfTypeElements` -> number of variables of same type that you want to be able to change.
###### Example:

        #define numOfIntElements 2
        #define numOfByteElements 1

2.  Array of variable names of same type. Example:


        arrayOfIntNames[numOfIntElements] = {"variable1", "variable2"};
        arrayOfByteNames[numOfByteElements] = {"variable3"};

3.  Array of variable pointers of same type. Example:

        *arrayOfIntPointers[numOfIntElements] = {&variable1, &variable2};
        *arrayOfBytePointers[numOfByteElements] = {&variable3};

4.  In loop function put:

        if(Serial.available() > 0) {
            String serialName = Serial.readStringUntil('=');
            float serialValue = Serial.parseInt();
            if(ASerial.readSerial(arrayOfIntNames, arrayOfIntPointers, numOfIntElements, serialName, serialValue)) == 0){
                ASerial.readSerial(arrayOfByteNames, arrayOfBytePointers, numOfByteElements, serialName, serialValue));
            };
        }

What it will happen is:
If you input something into Serial it will try to parse: `"variable=value"`. String `serialName` is variable, `serialValue` is value from serial input.
Next it will pass arrays and serial input to first function, that will go through int variables. If it does not find one in int array it will go through byte array.

`ASerial.readSerial` functions are bool. If returns true (1), variable was changed to new value (serialValue). If returns false (0) variable was not found.

You can use other functions that are similar to readSerial:

   `ASerial.readSerialIncreaseValue(arrayOfNames, arrayOfPointers, numOfIntElements, serialName, changeValue);` - this will increase variable by +changeValue. Does not matter what value you put into serial ("variable=whatever"), it will always change variable by +changeValue. If changeValue is not provided it will default to +1.
    `ASerial.readSerialDecreaseValue(arrayOfNames, arrayOfPointers, numOfIntElements, serialName, changeValue);`- this will increase variable by -changeValue. Does not matter what value you put into serial ("variable=whatever"), it will always change variable by -changeValue. If changeValue is not provided it will default to -1.


* * *

##### Other way (more powerful) is use of Array of Structs.

There are multiple structures you can use. All have one thing in common: every variable is structure by itself. So best practice (one that will work with ASerial) is to make one Array of sturctures.
Structures available:

            `ChangableUniversal variablesUniversal[];` - you can use any type you'd want in this structure. It takes same amount of bytes as float type. Easiest, but takes more space than others.
            `ChangableBool variablesBool[];` - for bool types only
            `ChangableChar variablesChar[];` - for char types only
            `ChangableByte variablesByte[];` - for byte types only
            `ChangableInt variablesInt[];` - for int types only
            `ChangableDouble variablesDouble[];` - for double types only
            `ChangableFloat variablesFloat[];` - for float types only
            `ChangableLong variablesLong[];` - for long types only
            `ChangableUInt variablesUInt[];` - for unsigned int types

Structure variables:
    `String name` - variable name - **MUST ALL BE LOWER CASE** - Example: "variable" **NOTE: two strings with same name, but different capitals WILL give you problems, since string you input into serial console, is put into lower case before comparing sturcture name to serial input string.**
    `type value` - value of the variable. Not a pointer! - Example: 4
    `type change` - how variable changes. Default 0. If 0, it will change by the value you put into serial console. Else it will change by change value. Example: if change = 5 -> value += change. If change = 0 -> value = serialValue
    `String description` - This string is used so you can print variable description. Example: "This variable changes lightspeed. So be careful!"

###### Example:

        #define numOfIntElements 2
        #define numOfByteElements 1

        variablesInt[0].name = "variable1";
        variablesInt[0].value = 56;
        variablesInt[0].description = "Number of whales in the ocean.";`

        if variablesInt[0].change is not declared it will take default value: 0

        `variablesInt[1].name = "variable2";
        variablesInt[1].value = 1;
        variablesInt[10].change = 1;
        variablesInt[1].description = "Number of Lock Ness monsters in the Lock Ness lake.";

        variablesByte[0].name = "variable3";
        variablesByte[0].value = 9;
        variablesByte[0].description = "Number of lakes.";

In your code you don't use variable1 as variable, but variablesInt[0].value. You can indeed use #define variable1 variablesInt[0].value that will "fix" this. Depends on your taste.


            if(Serial.available() > 0) {
            String serialName = Serial.readStringUntil('=');
            float serialValue = Serial.parseInt();
                if(ASerial.readSerial(variablesInt, numOfIntElements, serialName, serialValue) == 0){
                    ASerial.readSerial(variablesByte, numOfByteElements, serialName, serialValue);
                }
            }


What it will happen is:
If you input something into Serial it will try to parse: `"variable=value"`. String `serialName` is variable, serialValue is serial value input.
Next it will array of structures and serial input to first function, that will go through int structures. If it does not find one in array of int structure it will go through array of byte structures.

`ASerial.readSerial` functions are bool. If returns true (1), variable was changed to new value (serialValue). If returns false (0) variable was not found.


------

#### Run function from serial

This only works if you used structures for your variables. For this use RunAction structure
Example:

            #define numOfActionElements 1 - must be number of all variables that are in RunAction structure
            RunAction variablesAction[1];
            String name = "ledon"; - name of variable, again ALL LOWER CAPITALS only.
            byte runEvent = 1; - function will return this number. DO NOT USE 0 OR -1, since 0 returns as error - variable not found and -1 returns if printing description, do not use same .runEvent with two variables.
            String description = "This turns on LED on pin 6.";


In loop():

            void turnOnLed(){
                digitalWrite(6, HIGH);
            }

            if(Serial.available() > 0) {
            String serialName = Serial.readStringUntil('=');
            byte action = ASerial.findAction(variablesAction, numOfActionElements, serialName);
                if(action == 1){
                    turnOnLed();
                }else if(action == 0){//returned error, variable not found
                }
            }

To use this, type "ledon" into serial console. This variable name should not be the same as any other variable name, since it will mix up those two.
When it will find the keyword it will return byte value of `variablesAction[1].runEvent`. Each variable should have it's unique runEvent number.

------

#### Print variable description

This only works if you used structures for your variables. `.description` of your structure must also be filled.
Example:

            variablesInt[0].name = "variable1";
            variablesInt[0].description = "Number of whales in the ocean.";

To get the description of this variable (structure), just write `variable?` in serial console (or "?" after any other variable) and the description will be printed out.


------

#### There might be other things I will add to this library.
**To do list:**
serial read and serial write for two arduinos (and esp8266) communicating with each other.
examples

------

**Everything here is in public domain, use it, abuse it, change it, make it fly!**

------
Aleš Lukek
