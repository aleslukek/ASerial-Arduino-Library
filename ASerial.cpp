/*
   Ales Lukek
 */
#include "ASerial.h"

ASerial::ASerial(bool debug){
        if(debug == true) {
                Serial.println("ASerial now begun.");
        }
}

void ASerial::begin(int baud){
        Serial.begin(baud);
        return;
}


void ASerial::print(String text, float variable, String text2){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(variable);
        Serial.print(text2);
        return;
}
void ASerial::print(String text, int variable, String text2){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(variable);
        Serial.print(text2);
        return;
}
void ASerial::print(String text, double variable, String text2){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(variable);
        Serial.print(text2);
        return;
}
void ASerial::print(String text, String text2, String text3){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(" ");
        Serial.print(text2);
        Serial.print(" ");
        Serial.print(text3);
        return;
}
void ASerial::print(float variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        return;
}
void ASerial::print(int variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        return;
}
void ASerial::print(double variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        return;
}
void ASerial::println(String text, float variable, String text2){
        print(text, variable);
        Serial.println(text2);
        return;
}
void ASerial::println(String text, int variable, String text2){
        print(text, variable);
        Serial.println(text2);
        return;
}
void ASerial::println(String text, double variable, String text2){
        print(text, variable);
        Serial.println(text2);
        return;
}
void ASerial::println(String text, String text2, String text3){
        print(text, text2);
        Serial.println(text3);
        return;
}
void ASerial::println(float variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        Serial.println();
        return;
}
void ASerial::println(int variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        Serial.println();
        return;
}
void ASerial::println(double variable, String text){
        Serial.print(" ");
        Serial.print(variable);
        Serial.print(text);
        Serial.println();
        return;
}
void ASerial::printlnln(String text, float variable, String text2){
        println(text, variable, text2);
        Serial.println();
        return;
}
void ASerial::printlnln(String text, int variable, String text2){
        println(text, variable, text2);
        Serial.println();
        return;
}
void ASerial::printlnln(String text, double variable, String text2){
        println(text, variable, text2);
        Serial.println();
        return;
}
void ASerial::printlnln(String text, String text2, String text3){
        println(text, text2, text3);
        Serial.println();
        return;
}
void ASerial::printlnln(float variable, String text){
        println(variable, text);
        Serial.println();
        return;
}
void ASerial::printlnln(int variable, String text){
        println(variable, text);
        Serial.println();
        return;
}
void ASerial::printlnln(double variable, String text){
        println(variable, text);
        Serial.println();
        return;
}
void ASerial::printlnln(){
        Serial.println();
        Serial.println();
        return;
}
void ASerial::println(){
        Serial.println();
        return;
}


void ASerial::printLine(){
        Serial.println("   ---------------------------------------- ");
        return;
}
void ASerial::printLineln(){
        printLine();
        Serial.println();
        return;
}


void ASerial::printChange(String text, float oldValue, float newValue){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(" - old: ");
        Serial.print(oldValue);
        Serial.print("; new: ");
        Serial.print(newValue);
        Serial.print(" ");
        return;
}
void ASerial::printChangeln(String text, float oldValue, float newValue){
        Serial.print(" ");
        Serial.print(text);
        Serial.print(" - old: ");
        Serial.print(oldValue);
        Serial.print("; new: ");
        Serial.println(newValue);
        return;
}


bool ASerial::readSerial(ChangableUniversal variablesUniversal[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesUniversal, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesUniversal[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesUniversal[i].name);
                                Serial.print(" - old value: ");
                                if(variablesUniversal[i].change == 0) {
                                        if(variablesUniversal[i].valueType == 1) {
                                                Serial.print(variablesUniversal[i].boolValue);
                                                variablesUniversal[i].boolValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 2) {
                                                Serial.print(variablesUniversal[i].charValue);
                                                variablesUniversal[i].charValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 3) {
                                                Serial.print(variablesUniversal[i].byteValue);
                                                variablesUniversal[i].byteValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 4) {
                                                Serial.print(variablesUniversal[i].intValue);
                                                variablesUniversal[i].intValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 5) {
                                                Serial.print(variablesUniversal[i].doubleValue);
                                                variablesUniversal[i].doubleValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 6) {
                                                Serial.print(variablesUniversal[i].floatValue);
                                                variablesUniversal[i].floatValue = serialInputValue;
                                        }else if(variablesUniversal[i].valueType == 7) {
                                                Serial.print(variablesUniversal[i].longValue);
                                                variablesUniversal[i].longValue = serialInputValue;
                                        }
                                }else{
                                        if(variablesUniversal[i].valueType == 1) {
                                                Serial.print(variablesUniversal[i].boolValue);
                                                variablesUniversal[i].boolValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 2) {
                                                Serial.print(variablesUniversal[i].charValue);
                                                variablesUniversal[i].charValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 3) {
                                                Serial.print(variablesUniversal[i].byteValue);
                                                variablesUniversal[i].byteValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 4) {
                                                Serial.print(variablesUniversal[i].intValue);
                                                variablesUniversal[i].intValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 5) {
                                                Serial.print(variablesUniversal[i].doubleValue);
                                                variablesUniversal[i].doubleValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 6) {
                                                Serial.print(variablesUniversal[i].floatValue);
                                                variablesUniversal[i].floatValue += variablesUniversal[i].change;
                                        }else if(variablesUniversal[i].valueType == 7) {
                                                Serial.print(variablesUniversal[i].longValue);
                                                variablesUniversal[i].longValue += variablesUniversal[i].change;
                                        }
                                }
                                Serial.print(", new value: ");
                                if(variablesUniversal[i].valueType == 1) {
                                        Serial.println(variablesUniversal[i].boolValue);
                                }else if(variablesUniversal[i].valueType == 2) {
                                        Serial.println(variablesUniversal[i].charValue);
                                }else if(variablesUniversal[i].valueType == 3) {
                                        Serial.println(variablesUniversal[i].byteValue);
                                }else if(variablesUniversal[i].valueType == 4) {
                                        Serial.println(variablesUniversal[i].intValue);
                                }else if(variablesUniversal[i].valueType == 5) {
                                        Serial.println(variablesUniversal[i].doubleValue);
                                }else if(variablesUniversal[i].valueType == 6) {
                                        Serial.println(variablesUniversal[i].floatValue);
                                }else if(variablesUniversal[i].valueType == 7) {
                                        Serial.println(variablesUniversal[i].longValue);
                                }
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableBool variablesBool[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesBool, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesBool[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesBool[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesBool[i].value);
                                Serial.print(", new value: ");
                                if(serialInputValue > 0) {
                                        if(variablesBool[i].value == 0) {
                                                variablesBool[i].value = 1;
                                        }else{
                                                variablesBool[i].value = 0;
                                        }
                                }else{
                                        variablesBool[i].value = serialInputValue;
                                }
                                Serial.println(variablesBool[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableChar variablesChar[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesChar, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesChar[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesChar[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesChar[i].value);
                                Serial.print(", new value: ");
                                if(variablesChar[i].change == 0) {
                                        variablesChar[i].value = serialInputValue;
                                }else{
                                        variablesChar[i].value += variablesChar[i].change;
                                }
                                Serial.println(variablesChar[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableByte variablesByte[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesByte, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesByte[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesByte[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesByte[i].value);
                                Serial.print(", new value: ");
                                if(variablesByte[i].change == 0) {
                                        variablesByte[i].value = serialInputValue;
                                }else{
                                        variablesByte[i].value += variablesByte[i].change;
                                }
                                Serial.println(variablesByte[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableInt variablesInt[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesInt, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesInt[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesInt[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesInt[i].value);
                                Serial.print(", new value: ");
                                if(variablesInt[i].change == 0) {
                                        variablesInt[i].value = serialInputValue;
                                }else{
                                        variablesInt[i].value += variablesInt[i].change;
                                }
                                Serial.println(variablesInt[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableDouble variablesDouble[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesDouble, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesDouble[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesDouble[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesDouble[i].value);
                                Serial.print(", new value: ");
                                if(variablesDouble[i].change == 0) {
                                        variablesDouble[i].value = serialInputValue;
                                }else{
                                        variablesDouble[i].value += variablesDouble[i].change;
                                }
                                Serial.println(variablesDouble[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableFloat variablesFloat[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesFloat, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesFloat[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesFloat[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesFloat[i].value);
                                Serial.print(", new value: ");
                                if(variablesFloat[i].change == 0) {
                                        variablesFloat[i].value = serialInputValue;
                                }else{
                                        variablesFloat[i].value += variablesFloat[i].change;
                                }
                                Serial.println(variablesFloat[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableLong variablesLong[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesLong, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesLong[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesLong[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesLong[i].value);
                                Serial.print(", new value: ");
                                if(variablesLong[i].change == 0) {
                                        variablesLong[i].value = serialInputValue;
                                }else{
                                        variablesLong[i].value += variablesLong[i].change;
                                }
                                Serial.println(variablesLong[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}
bool ASerial::readSerial(ChangableUInt variablesUInt[], int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                return varDescription(variablesUInt, arrayLength, passString.remove(passString.length()-1));
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesUInt[i].name) {
                                Serial.print(" ");
                                Serial.print(variablesUInt[i].name);
                                Serial.print(" - old value: ");
                                Serial.print(variablesUInt[i].value);
                                Serial.print(", new value: ");
                                if(variablesUInt[i].change == 0) {
                                        variablesUInt[i].value = serialInputValue;
                                }else{
                                        variablesUInt[i].value += variablesUInt[i].change;
                                }
                                Serial.println(variablesUInt[i].value);
                                varFound = true;
                                return 1;//end function, because variable was fount
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 1;
                }else{
                        //Serial.println(" Variable does not exist, or it is not changable.");
                        return 0;
                }
        }
        return 0;
}



bool ASerial::readSerial(String changableVarNamesArray[], bool **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], float **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], double **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], long **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], unsigned int **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerial(String changableVarNamesArray[], unsigned long **changableVariablesArray, int arrayLength, String serialInputString, float serialInputValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] = serialInputValue;
                        Serial.print("; new: ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}


//Increase variable by 1 via serial using pointer arrays
bool ASerial::readSerialIncreaseValue(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] += changeValue;
                        Serial.print("; +");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerialIncreaseValue(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] += changeValue;
                        Serial.print("; +");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerialIncreaseValue(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] += changeValue;
                        Serial.print("; +");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}



//Decrease variable by 1 via serial using pointer arrays
bool ASerial::readSerialDecreaseValue(String changableVarNamesArray[], int **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] -= changeValue;
                        Serial.print("; -");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerialDecreaseValue(String changableVarNamesArray[], byte **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] -= changeValue;
                        Serial.print("; -");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}
bool ASerial::readSerialDecreaseValue(String changableVarNamesArray[], char **changableVariablesArray, int arrayLength, String serialInputString, int changeValue){
        serialInputString = serialInputString.toLowerCase();
        for(byte i = 0; i < arrayLength; i++) {
                if(serialInputString == changableVarNamesArray[i]) {
                        Serial.print(" ");
                        Serial.print(changableVarNamesArray[i]);
                        Serial.print(" - old: ");
                        Serial.print(*changableVariablesArray[i]);
                        *changableVariablesArray[i] -= changeValue;
                        Serial.print("; -");
                        Serial.print(changeValue);
                        Serial.print(" = ");
                        Serial.println(*changableVariablesArray[i]);
                        return 1;
                }
        }
        //Serial.println(" Variable does not exist, or it is not changable.");
        return 0;
}



//Print variable description via serial using stucts
bool ASerial::varDescription(ChangableUniversal variablesUniversal[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesUniversal[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesUniversal[i].name);
                        Serial.print(" description: ");
                        if(variablesUniversal[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesUniversal[i].description);
                                Serial.print(" Current value: ");
                                if(variablesUniversal[i].valueType == 1) {
                                        Serial.print(variablesUniversal[i].boolValue);
                                }else if(variablesUniversal[i].valueType == 2) {
                                        Serial.print(variablesUniversal[i].charValue);
                                }else if(variablesUniversal[i].valueType == 3) {
                                        Serial.print(variablesUniversal[i].byteValue);
                                }else if(variablesUniversal[i].valueType == 4) {
                                        Serial.print(variablesUniversal[i].intValue);
                                }else if(variablesUniversal[i].valueType == 5) {
                                        Serial.print(variablesUniversal[i].doubleValue);
                                }else if(variablesUniversal[i].valueType == 6) {
                                        Serial.print(variablesUniversal[i].floatValue);
                                }else if(variablesUniversal[i].valueType == 7) {
                                        Serial.print(variablesUniversal[i].longValue);
                                }
                        }
                        varFound = true;
                        return 1; //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableBool variablesBool[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesBool[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesBool[i].name);
                        Serial.print(" description: ");
                        if(variablesBool[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesBool[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesBool[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableChar variablesChar[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesChar[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesChar[i].name);
                        Serial.print(" description: ");
                        if(variablesChar[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesChar[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesChar[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableByte variablesByte[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesByte[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesByte[i].name);
                        Serial.print(" description: ");
                        if(variablesByte[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesByte[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesByte[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableInt variablesInt[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesInt[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesInt[i].name);
                        Serial.print(" description: ");
                        if(variablesInt[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesInt[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesInt[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableDouble variablesDouble[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesDouble[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesDouble[i].name);
                        Serial.print(" description: ");
                        if(variablesDouble[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesDouble[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesDouble[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableFloat variablesFloat[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesFloat[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesFloat[i].name);
                        Serial.print(" description: ");
                        if(variablesFloat[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesFloat[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesFloat[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableLong variablesLong[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesLong[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesLong[i].name);
                        Serial.print(" description: ");
                        if(variablesLong[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesLong[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesLong[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(ChangableUInt variablesUInt[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesUInt[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesUInt[i].name);
                        Serial.print(" description: ");
                        if(variablesUInt[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesUInt[i].description);
                                Serial.print(" Current value: ");
                                Serial.println(variablesUInt[i].value);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}
bool ASerial::varDescription(RunAction variablesAction[], int arrayLength, String serialInputString){
        bool varFound = false;
        serialInputString = serialInputString.toLowerCase();
        for(int i = 0; i < arrayLength; i++) {
                if(serialInputString == variablesAction[i].name) {
                        Serial.print(" ");
                        Serial.print(variablesAction[i].name);
                        Serial.print(" description: ");
                        if(variablesAction[i].description == "") {
                                Serial.println("N/A");
                        }else{
                                Serial.print(" ");
                                Serial.print(variablesAction[i].description);
                                Serial.print(" runEvent value: ");
                                Serial.println(variablesAction[i].runEvent);
                        }
                        varFound = true;
                        return 1;       //Variable found, so end the function
                }else{
                        varFound = false;
                }
        }
        if(varFound == true) {
                return 1;
        }else{
                //Serial.println(" Variable does not exist.");
                return 0;
        }
        return 0;
}

int ASerial::findAction(RunAction variablesAction[], int arrayLength, String serialInputString){
        serialInputString = serialInputString.toLowerCase();
        String passString = serialInputString;
        if(passString.indexOf("?") > 0) {
                if(varDescription(variablesAction, arrayLength, passString.remove(passString.length()-1)) == 0){
                  return 0;
                }else{
                  return -1;
                }
        }else{
                bool varFound = false;
                for(int i = 0; i < arrayLength; i++) {
                        if(serialInputString == variablesAction[i].name) {
                                varFound = true;
                                return variablesAction[i].runEvent;//end function, because variable was fount, return run.Action
                        }else{
                                varFound = false;
                        }
                }
                if(varFound == true) {
                        return 0;
                }else{
                        //Serial.println(" Variable does not exist.");
                        return 0;
                }
        }
        return 0;
}
