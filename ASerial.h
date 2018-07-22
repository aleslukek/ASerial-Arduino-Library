/*
   Ales Lukek
 */

#include "Arduino.h"

struct ChangableBool
{
        String name;
        bool value;
        String description;
};

struct ChangableChar
{
        String name;
        char value;
        char change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableByte
{
        String name;
        byte value;
        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableInt
{
        String name;
        int value;
        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableDouble
{
        String name;
        double value;
        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableFloat
{
        String name;
        float value;
        float change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableLong
{
        String name;
        long value;
        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableUInt
{
        String name;
        unsigned int value;
        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct ChangableUniversal
{
        String name;
        union {
                bool boolValue; // valueType = 1
                char charValue; // valueType = 2
                byte byteValue; // valueType = 3
                int intValue; // valueType = 4
                double doubleValue; // valueType = 5
                float floatValue; // valueType = 6
                long longValue; // valueType = 7
                unsigned int uintValue; // valueType = 8
                unsigned long ulongValue; // valueType = 9
        };
        byte valueType = 0; //1 bool, 2 char, 3 byte, 4 int, 5 double, 6 float, 7 long, 8 unsigned int, 9 unsigned long

        int change = 0; //if 0 change via serial read, else change to value from change value
        String description;
};

struct RunAction
{
        String name;  //name of variable
        byte runEvent; //function will return this number. DO NOT USE 0, since 0 returns as error. So write: if ASerial.runEvent(---) == 1 -> run this function... etc. You get it. If returns 0, variable was NOT found!
        String description;
};




class ASerial {
public:

//Constructor
ASerial(bool debug = false);

//Begin Serial. Not needed, but can be used instead of Serial.begin(baud);
void begin(int baud = 115200);

//Structs
ChangableUniversal variablesUniversal[];
ChangableBool variablesBool[];
ChangableChar variablesChar[];
ChangableByte variablesByte[];
ChangableInt variablesInt[];
ChangableDouble variablesDouble[];
ChangableFloat variablesFloat[];
ChangableLong variablesLong[];
ChangableUInt variablesUInt[];
RunAction variablesAction[];

//print string, variable, string in same function
void print(String text, float variable, String text2 = "");
void print(String text, int variable, String text2 = "");
void print(String text, double variable, String text2 = "");
void print(String text, String text2 = "", String text3 = "");
void print(float variable, String text = "");
void print(int variable, String text = "");
void print(double variable, String text = "");
void println(String text, float variable, String text2 = "");
void println(String text, int variable, String text2 = "");
void println(String text, double variable, String text2 = "");
void println(String text, String text2 = "", String text3 = "");
void println(float variable, String text = "");
void println(int variable, String text = "");
void println(double variable, String text = "");
void println();
void printlnln(String text, float variable, String text2 = "");
void printlnln(String text, int variable, String text2 = "");
void printlnln(String text, double variable, String text2 = "");
void printlnln(String text, String text2 = "", String text3 = "");
void printlnln(float variable, String text = "");
void printlnln(int variable, String text = "");
void printlnln(double variable, String text = "");
void printlnln();

//prints line
void printLine();
void printLineln();

//Print variable change - old one, new one
void printChange(String text, float oldValue, float newValue);
void printChangeln(String text, float oldValue, float newValue);


//Change variable via serial using structs
bool readSerial(ChangableUniversal variablesUniversal[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableBool variablesBool[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableChar variablesChar[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableByte variablesByte[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableInt variablesInt[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableDouble variablesDouble[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableFloat variablesFloat[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableLong variablesLong[], int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(ChangableUInt variablesUInt[], int arrayLength, String serialInputString, float serialInputValue);

//Change variable via serial using pointer arrays
bool readSerial(String changableVarNamesArray[], bool **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], double **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], float **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], long **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], unsigned int **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);
bool readSerial(String changableVarNamesArray[], unsigned long **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue);

//Increase variable by 1 via serial using pointer arrays
bool readSerialIncreaseValue(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);
bool readSerialIncreaseValue(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);
bool readSerialIncreaseValue(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);

//Decrease variable by 1 via serial using pointer arrays
bool readSerialDecreaseValue(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);
bool readSerialDecreaseValue(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);
bool readSerialDecreaseValue(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, int changeValue = 1);

//Print variable description via serial using stucts
bool varDescription(ChangableUniversal variablesUniversal[], int arrayLength, String serialInputString);
bool varDescription(ChangableBool variablesBool[], int arrayLength, String serialInputString);
bool varDescription(ChangableChar variablesChar[], int arrayLength, String serialInputString);
bool varDescription(ChangableByte variablesByte[], int arrayLength, String serialInputString);
bool varDescription(ChangableInt variablesInt[], int arrayLength, String serialInputString);
bool varDescription(ChangableDouble variablesDouble[], int arrayLength, String serialInputString);
bool varDescription(ChangableFloat variablesFloat[], int arrayLength, String serialInputString);
bool varDescription(ChangableLong variablesLong[], int arrayLength, String serialInputString);
bool varDescription(ChangableUInt variablesUInt[], int arrayLength, String serialInputString);
bool varDescription(RunAction variablesAction[], int arrayLength, String serialInputString);

int findAction(RunAction variablesAction[], int arrayLength, String serialInputString);

private:


};
