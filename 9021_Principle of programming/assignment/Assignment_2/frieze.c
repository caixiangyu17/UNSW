/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Description: The input is expected to consist of height + 1 lines of        *
*              length + 1 numbers in {0, ..., 15}, where length is at least   *
*              equal to MIN_LENGTH and at most equal to MAX_LENGHT and height *
*              is at least equal to MIN_HEIGHT and at most equal to           *
*              MAX_HEIGHT, with possibly lines consisting of spaces only      *
*              that will be ignored and with possibly spaces anywhere on the  *
*              lines with digits. The xth digit n of the yth line, with       *
*              0 <= x <= length and 0 <= y <= height, is to be associated     *
*              with a point situated x * 0.2 cm to the right and y * 0.2 cm   *
*              below an origin, is to be connected to the point 0.2 cm above  *
*              if the rightmost digit of n is 1, is to be connected to the    *
*              point 0.2 cm above and 0.2 cm to the right if the second       *
*              rightmost digit of n is 1, is to be connected to the point     *
*              0.2 cm to the right if the third rightmost digit of n  is 1,   *
*              and is to be connected to the point 0.2 cm to the right and    *
*              0.2 cm below if the fourth rightmost digit of n is 1.          *
*              The input is further constrained to represent a frieze,        *
*              that is, a picture that fits in a rectangle of length          *
*              length * 0.2 cm and of height heigth * 0.2 cm, with horizontal *
*              lines of length length at the top and at the bottom, identical *
*              vertical borders at both ends, no crossing segments connecting *
*              pairs of neighbours inside the rectangle, and a pattern of     *
*              integral period at least equal to 2  that is fully repeated    *
*              at least twice in the horizontal dimension.                    *
*                                                                             *
*              Practically, the input will be stored in a file and its        *
*              contents redirected to standard input. The program will be run *
*              with either no command-line argument or with "print" as unique *
*              command line argument; otherwise it will exit.                 *
*                                                                             *
*              When provided with no command-line argument, the program       *
*              displays one of two error messages if the input is incorrect   *
*              or if it fails to represent a frieze, and otherwise outputs    *
*              the period of the pattern and the set of symmetries that       *
*              keep it invariant under an isometry; a result on frieze        *
*              classification lists 7 alternatives based on 5 symmetries:     *
*              horizontal translation by period (which of course can be       *
*              applied to any frieze), horizontal reflection about the line   *
*              that goes through the middle of the frieze, horizontal         *
*              reflection about the line that goes through the middle of      *
*              the frieze and horizontal translation of the lower part of the *
*              frieze by half the period, vertical reflection about some      *
*              vertical line, and rotation around some point situated on the  *
*              horizontal line that goes through the middle of the frieze.    *
*                                                                             *
*              When provided with "print" as unique command-line argument,    *
*              the program outputs some .tex code to depict the frieze        *
*              as a tiz picture. Segments are drawn in purple with a single   *
*              draw command for each longest segment, starting with the       *
*              vertical segments, from the topmost leftmost one to the        *
*              bottommost rightmost one with the leftmost ones first,         *
*              followed by the segments that go from north west to            *
*              south east, from the topmost leftmost one to the bottommost    *
*              rightmost one with the ones topmost first, followed by the     *
*              segments that go from west to east, from the topmost leftmost  *
*              one to the bottommost rightmost one with the topmost ones      *
*              first, followed by the segments that go from the south west    *
*              to the north east, from the topmost leftmost one to the        *
*              bottommost rightmost one with the topmost ones first.          *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int sizeOfInputX = 0;
int sizeOfInputY = 0;
int input[4096];
bool isIncorrect = false;


#define TOTAL 400
int i_north_2_south[TOTAL][2][2] = { 0 };
int i_southWest_2_northEast[TOTAL][2][2] = { 0 };
int i_west_2_east[TOTAL][2][2] = { 0 };
int i_northWest_2_southEast[TOTAL][2][2] = { 0 };


int* integer_2_binary(int num, int length){
    float TERNARY_VALUE = 2;
    int *result = (int *)malloc(sizeof(int)*length);
    for (int i = 0; i <= length - 1; i++){
        if (num >> i & 1){
            result[i] = 1;
        }
        else {
            result[i] = 0;
        }
    }
    return result;
}

void printOut(){
    printf("\\documentclass[10pt]{article}\n");
    printf("\\usepackage{tikz}\n");
    printf("\\usepackage[margin=0cm]{geometry}\n");
    printf("\\pagestyle{empty}\n");
    printf("\n");
    printf("\\begin{document}\n");
    printf("\n");
    printf("\\vspace*{\\fill}\n");
    printf("\\begin{center}\n");
    printf("\\begin{tikzpicture}[x=0.2cm, y=-0.2cm, thick, purple]\n");
    printf("%% North to South lines\n");
    for (int i = 0; i < TOTAL; i++){
        if (i_north_2_south[i][0][0] == 0 && i_north_2_south[i][0][1] == 0 && i_north_2_south[i][1][0] == 0 && i_north_2_south[i][1][1] == 0){
            continue;
        }
        else{
            printf("    \\draw (%d,%d) -- (%d,%d);\n", i_north_2_south[i][0][0], i_north_2_south[i][0][1], i_north_2_south[i][1][0], i_north_2_south[i][1][1]);
        }
    }

    printf("%% North-West to South-East lines\n");
    for (int i = 0; i < TOTAL; i++){
        if (i_northWest_2_southEast[i][0][0] == 0 && i_northWest_2_southEast[i][0][1] == 0 && i_northWest_2_southEast[i][1][0] == 0 && i_northWest_2_southEast[i][1][1] == 0){
            continue;
        }
        else{
            printf("    \\draw (%d,%d) -- (%d,%d);\n", i_northWest_2_southEast[i][0][0], i_northWest_2_southEast[i][0][1], i_northWest_2_southEast[i][1][0], i_northWest_2_southEast[i][1][1]);
        }
    }

    printf("%% West to East lines\n");
    for (int i = 0; i < TOTAL; i++){
        if (i_west_2_east[i][0][0] == 0 && i_west_2_east[i][0][1] == 0 && i_west_2_east[i][1][0] == 0 && i_west_2_east[i][1][1] == 0){
            continue;
        }
        else{
            printf("    \\draw (%d,%d) -- (%d,%d);\n", i_west_2_east[i][0][0], i_west_2_east[i][0][1], i_west_2_east[i][1][0], i_west_2_east[i][1][1]);
        }
    }

    printf("%% South-West to North-East lines\n");
    for (int i = 0; i < TOTAL; i++){
        if (i_southWest_2_northEast[i][0][0] == 0 && i_southWest_2_northEast[i][0][1] == 0 && i_southWest_2_northEast[i][1][0] == 0 && i_southWest_2_northEast[i][1][1] == 0){
            continue;
        }
        else{
            printf("    \\draw (%d,%d) -- (%d,%d);\n", i_southWest_2_northEast[i][0][0], i_southWest_2_northEast[i][0][1], i_southWest_2_northEast[i][1][0], i_southWest_2_northEast[i][1][1]);
        }

    }
    printf("\\end{tikzpicture}\n");
    printf("\\end{center}\n");
    printf("\\vspace*{\\fill}\n");
    printf("\n");
    printf("\\end{document}\n");
}

void produceNum(int num, int x, int y){

    int length = 4;
    int *numDigits = integer_2_binary(num, length);
    if (numDigits[0]){
        for (int i = 0; i < TOTAL; i++){
            if (i_north_2_south[i][0][0] == 0 && i_north_2_south[i][0][1] == 0 && i_north_2_south[i][1][0] == 0 && i_north_2_south[i][1][1] == 0){
                i_north_2_south[i][0][0] = x;
                i_north_2_south[i][0][1] = y - 1;
                i_north_2_south[i][1][0] = x;
                i_north_2_south[i][1][1] = y;
                break;
            }
            else {
                if (i_north_2_south[i][1][0] == x && i_north_2_south[i][1][1] == (y - 1)){
                    i_north_2_south[i][1][1] = y;
                    break;
                }
            }
        }
    }
    if (numDigits[1]){
        for (int i = 0; i < TOTAL; i++){
            if (i_southWest_2_northEast[i][0][0] == 0 && i_southWest_2_northEast[i][0][1] == 0 && i_southWest_2_northEast[i][1][0] == 0 && i_southWest_2_northEast[i][1][1] == 0){
                i_southWest_2_northEast[i][0][0] = x;
                i_southWest_2_northEast[i][0][1] = y;
                i_southWest_2_northEast[i][1][0] = x + 1;
                i_southWest_2_northEast[i][1][1] = y - 1;
                break;
            }
            else {
                if (i_southWest_2_northEast[i][0][0] == (x + 1) && i_southWest_2_northEast[i][0][1] == (y - 1)){
                    i_southWest_2_northEast[i][0][0] = x;
                    i_southWest_2_northEast[i][0][1] = y;
                    break;
                }
            }
        }
    }
    if (numDigits[2]){
        for (int i = 0; i < TOTAL; i++){
            if (i_west_2_east[i][0][0] == 0 && i_west_2_east[i][0][1] == 0 && i_west_2_east[i][1][0] == 0 && i_west_2_east[i][1][1] == 0){
                i_west_2_east[i][0][0] = x;
                i_west_2_east[i][0][1] = y;
                i_west_2_east[i][1][0] = x + 1;
                i_west_2_east[i][1][1] = y;
                break;
            }
            else {
                if (i_west_2_east[i][1][0] == x && i_west_2_east[i][1][1] == y){
                    i_west_2_east[i][1][0] = x + 1;
                    i_west_2_east[i][1][1] = y;
                    break;
                }
            }
        }
    }
    if (numDigits[3]){
        for (int i = 0; i < TOTAL; i++){
            if (i_northWest_2_southEast[i][0][0] == 0 && i_northWest_2_southEast[i][0][1] == 0 && i_northWest_2_southEast[i][1][0] == 0 && i_northWest_2_southEast[i][1][1] == 0){
                i_northWest_2_southEast[i][0][0] = x;
                i_northWest_2_southEast[i][0][1] = y;
                i_northWest_2_southEast[i][1][0] = x + 1;
                i_northWest_2_southEast[i][1][1] = y + 1;
                break;
            }
            else {
                if (i_northWest_2_southEast[i][1][0] == x && i_northWest_2_southEast[i][1][1] == y){
                    i_northWest_2_southEast[i][1][0] = x + 1;
                    i_northWest_2_southEast[i][1][1] = y + 1;
                    break;
                }
            }
        }    
    }
}


bool thisIsForUselessStyleSheet(int numOfElements, int currentNumOfElements){
    if(numOfElements != currentNumOfElements){
        return true;
    }else{
        return false;
    }
}
void produceInput(){
    #define STATE_INIT 0
    #define STATE_CALCULATING_NUM 1
    #define STATE_ISSPACE 2
    char c;
    int numOfLines = 0;
    int numOfElements = 0;
    int currentNumOfElements = 0;
    int valueOfNum = 0;
    int state = STATE_INIT;
    int count = 0;
    for (int i = 0; i < 2048; i++){
        input[i] = -2;
    }

    bool error_startFromZero = false;
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            if (error_startFromZero){
                isIncorrect = true;
                break;
            }
            if (c == '0'){
                error_startFromZero = true;
            }
            valueOfNum = valueOfNum * 10;
            valueOfNum += c - '0';
            state = STATE_CALCULATING_NUM;
        }
        else if (c == ' ' || c == '\t'){
            error_startFromZero = false;
            if (state == STATE_CALCULATING_NUM){
                if (valueOfNum >= 16 || valueOfNum < 0){
                    isIncorrect = true;
                    break;
                }
                input[count] = valueOfNum;
                count++;
                valueOfNum = 0;
                currentNumOfElements++;
                state = STATE_ISSPACE;
            }
        }
        else if (c == '\n'){
            error_startFromZero = false;
            if (state == STATE_CALCULATING_NUM){
                if (valueOfNum >= 16 || valueOfNum < 0){
                    isIncorrect = true;
                    break;
                }
                input[count] = valueOfNum;
                count++;
                valueOfNum = 0;
                currentNumOfElements++;
                state = STATE_ISSPACE;
            }
            if (currentNumOfElements != 0){
                if (numOfElements == 0){
                    numOfElements = currentNumOfElements;
                }
                else{
                    isIncorrect = thisIsForUselessStyleSheet(numOfElements, currentNumOfElements);
                }
                if(isIncorrect){
                    break;
                }
                currentNumOfElements = 0;
                numOfLines++;
                state = STATE_ISSPACE;
                input[count] = -1;
                count++;
            }
        }
        else {
            error_startFromZero = false;
            isIncorrect = true;
            break;
        }
    }
    if (state == STATE_CALCULATING_NUM){
        if (valueOfNum >= 16 || valueOfNum < 0){
            isIncorrect = true;
        }
        input[count] = valueOfNum;
        count++;
        valueOfNum = 0;
        currentNumOfElements++;
        state = STATE_ISSPACE;
    }
    if (currentNumOfElements == numOfElements){
        numOfLines++;
        currentNumOfElements = 0;
    }
    sizeOfInputX = numOfElements;
    sizeOfInputY = numOfLines;
    if (sizeOfInputX < 5 || sizeOfInputX > 51){
        isIncorrect = true;
    }
    if (sizeOfInputY < 3 || sizeOfInputY > 17){
        isIncorrect = true;
    }
}

void bubble_sort(){
    int i, j, temp0, temp1, temp2, temp3;
    for (j = 0; j < TOTAL - 1; j++){
        for (i = 0; i < TOTAL - 1 - j; i++){
            if (i_north_2_south[i][0][1] > i_north_2_south[i + 1][0][1]){
                temp0 = i_north_2_south[i][0][0];
                temp1 = i_north_2_south[i][0][1];
                temp2 = i_north_2_south[i][1][0];
                temp3 = i_north_2_south[i][1][1];
                i_north_2_south[i][0][0] = i_north_2_south[i + 1][0][0];
                i_north_2_south[i][0][1] = i_north_2_south[i + 1][0][1];
                i_north_2_south[i][1][0] = i_north_2_south[i + 1][1][0];
                i_north_2_south[i][1][1] = i_north_2_south[i + 1][1][1];
                i_north_2_south[i + 1][0][0] = temp0;
                i_north_2_south[i + 1][0][1] = temp1;
                i_north_2_south[i + 1][1][0] = temp2;
                i_north_2_south[i + 1][1][1] = temp3;
            }
        }
    }
    for (j = 0; j < TOTAL - 1; j++){
        for (i = 0; i < TOTAL - 1 - j; i++){
            if (i_north_2_south[i][0][0] > i_north_2_south[i + 1][0][0]){
                temp0 = i_north_2_south[i][0][0];
                temp1 = i_north_2_south[i][0][1];
                temp2 = i_north_2_south[i][1][0];
                temp3 = i_north_2_south[i][1][1];
                i_north_2_south[i][0][0] = i_north_2_south[i + 1][0][0];
                i_north_2_south[i][0][1] = i_north_2_south[i + 1][0][1];
                i_north_2_south[i][1][0] = i_north_2_south[i + 1][1][0];
                i_north_2_south[i][1][1] = i_north_2_south[i + 1][1][1];
                i_north_2_south[i + 1][0][0] = temp0;
                i_north_2_south[i + 1][0][1] = temp1;
                i_north_2_south[i + 1][1][0] = temp2;
                i_north_2_south[i + 1][1][1] = temp3;
            }
        }
    }
    for (j = 0; j < TOTAL - 1; j++){
        for (i = 0; i < TOTAL - 1 - j; i++){
            if (i_southWest_2_northEast[i][0][0] > i_southWest_2_northEast[i + 1][0][0]){
                temp0 = i_southWest_2_northEast[i][0][0];
                temp1 = i_southWest_2_northEast[i][0][1];
                temp2 = i_southWest_2_northEast[i][1][0];
                temp3 = i_southWest_2_northEast[i][1][1];
                i_southWest_2_northEast[i][0][0] = i_southWest_2_northEast[i + 1][0][0];
                i_southWest_2_northEast[i][0][1] = i_southWest_2_northEast[i + 1][0][1];
                i_southWest_2_northEast[i][1][0] = i_southWest_2_northEast[i + 1][1][0];
                i_southWest_2_northEast[i][1][1] = i_southWest_2_northEast[i + 1][1][1];
                i_southWest_2_northEast[i + 1][0][0] = temp0;
                i_southWest_2_northEast[i + 1][0][1] = temp1;
                i_southWest_2_northEast[i + 1][1][0] = temp2;
                i_southWest_2_northEast[i + 1][1][1] = temp3;
            }
        }
    }
    for (j = 0; j < TOTAL - 1; j++){
        for (i = 0; i < TOTAL - 1 - j; i++){
            if (i_southWest_2_northEast[i][0][1] > i_southWest_2_northEast[i + 1][0][1]){
                temp0 = i_southWest_2_northEast[i][0][0];
                temp1 = i_southWest_2_northEast[i][0][1];
                temp2 = i_southWest_2_northEast[i][1][0];
                temp3 = i_southWest_2_northEast[i][1][1];
                i_southWest_2_northEast[i][0][0] = i_southWest_2_northEast[i + 1][0][0];
                i_southWest_2_northEast[i][0][1] = i_southWest_2_northEast[i + 1][0][1];
                i_southWest_2_northEast[i][1][0] = i_southWest_2_northEast[i + 1][1][0];
                i_southWest_2_northEast[i][1][1] = i_southWest_2_northEast[i + 1][1][1];
                i_southWest_2_northEast[i + 1][0][0] = temp0;
                i_southWest_2_northEast[i + 1][0][1] = temp1;
                i_southWest_2_northEast[i + 1][1][0] = temp2;
                i_southWest_2_northEast[i + 1][1][1] = temp3;
            }
        }
    }
}

bool compareTwoRows(int inputArray[sizeOfInputY][sizeOfInputX], int i, int j){
    bool isSame = true;
    if (j > sizeOfInputX - 1 || i > sizeOfInputX - 1){
        return true;
    }
    for (int h = 0; h < sizeOfInputY; h++){

        if (j == sizeOfInputX - 1){
            if (inputArray[h][i] % 2 != inputArray[h][j]){
                isSame = false;
                break;
            }
        }
        else{
            if (inputArray[h][i] != inputArray[h][j]){
                isSame = false;
                break;
            }
        }


    }
    return isSame;
}

int getPeriod(int inputArray[sizeOfInputY][sizeOfInputX]){

    for (int i = 0; i < sizeOfInputX; i++){
        if (inputArray[0][i] >> 0 & 1 == 1 || inputArray[0][i] >> 1 & 1 == 1){
            return -1;
        }
        if (inputArray[sizeOfInputY - 1][i] >> 3 & 1 == 1){
            return -1;
        }
    }

    bool isChecked[sizeOfInputX];
    int countDivide = 0;
    int dividers[51];
    for (int i = 0; i < 51; i++){
        dividers[i] = -1;
    }
    for (int i = 0; i < sizeOfInputX; i++){
        isChecked[i] = false;
    }
    for (int i = 0; i < sizeOfInputX; i++){
        bool isDevider = false;
        for (int j = i + 1; j < sizeOfInputX; j++){
            if (isChecked[j]){
                continue;
            }
            if (compareTwoRows(inputArray, i, j)){
                isChecked[i] = true;
                isChecked[j] = true;
                isDevider = true;
                countDivide++;
                dividers[0] = i;
                dividers[countDivide] = j;
            }
        }
        if (isDevider){
            break;
        }
    }
    countDivide++;

    bool isPeriod = true;

    //check the top line contain the horizontal line
    for (int i = 0; i < sizeOfInputX - 1; ++i){
        if (!(inputArray[0][i] >> 2 & 1) || (inputArray[0][i] >> 1 & 1)){
            isPeriod = false;
            break;
        }
    }
    //check the crossing line
    for (int i = 0; i < sizeOfInputX - 1; ++i){
        for (int j = 0; j < sizeOfInputY - 1; ++j){
            if (!isPeriod){
                break;
            }
            if ((inputArray[j][i] >> 3 & 1) && (inputArray[j + 1][i] >> 1 & 1)){
                isPeriod = false;
                break;
            }
        }
    }

    int period = -1;
    for (int i = 1; i < countDivide; i++){
        if (!isPeriod){
            break;
        }
        period = dividers[i] - dividers[0];
        for (int j = 1; j <= period; j++){
            if (!isPeriod){
                break;
            }
            for (int x = 0; x < countDivide - i; x++){
                if (!compareTwoRows(inputArray, dividers[x] + j, dividers[x + i] + j)){
                    isPeriod = false;
                    break;
                }
            }
        }
        if (isPeriod){
            if (sizeOfInputX / period < 2){
                isPeriod = false;
            }
            else if (sizeOfInputX - dividers[countDivide - 1] > period){
                isPeriod = false;
            }
            else{
                break;
            }
        }
        isPeriod = true;
    }
    if (sizeOfInputX % period == 1){
        if (!compareTwoRows(inputArray, 0, sizeOfInputX - 1)){
            period = -1;
        }
    }


    if (!isPeriod){
        period = -1;
    }
    return period;
}

bool isHorizontalRefl(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isHorizontalRefl = true;
    if (sizeOfInputY % 2 == 1){
        int axis = sizeOfInputY / 2;
        for (int i = 0; i < sizeOfInputX; ++i){
            for (int j = 0; j < sizeOfInputY / 2 + 1; j++){
                int digit1 = inputArray[axis + j][i] >> 0 & 1;
                int digit2 = inputArray[axis + j][i] >> 1 & 1;
                int digit4 = inputArray[axis + j][i] >> 2 & 1;
                int digit8 = inputArray[axis + j][i] >> 3 & 1;
                int compareDigit1 = inputArray[axis - j + 1][i] >> 0 & 1;
                int compareDigit2 = inputArray[axis - j][i] >> 1 & 1;
                int compareDigit4 = inputArray[axis - j][i] >> 2 & 1;
                int compareDigit8 = inputArray[axis - j][i] >> 3 & 1;
                if (digit1 != compareDigit1 || digit2 != compareDigit8 || digit4 != compareDigit4 || digit8 != compareDigit2){
                    isHorizontalRefl = false;
                    break;
                }

            }
            if (!isHorizontalRefl){
                break;
            }
        }

    }
    else{
        int axis = sizeOfInputY / 2 - 1;
        for (int i = 0; i < sizeOfInputX; ++i){
            for (int j = 0; j < sizeOfInputY / 2 + 1; j++){
                int digit1 = inputArray[axis + j][i] >> 0 & 1;
                int digit2 = inputArray[axis + j][i] >> 1 & 1;
                int digit4 = inputArray[axis + j][i] >> 2 & 1;
                int digit8 = inputArray[axis + j][i] >> 3 & 1;
                int compareDigit1 = inputArray[axis - j + 2][i] >> 0 & 1;
                int compareDigit2 = inputArray[axis - j + 1][i] >> 1 & 1;
                int compareDigit4 = inputArray[axis - j + 1][i] >> 2 & 1;
                int compareDigit8 = inputArray[axis - j + 1][i] >> 3 & 1;
                if (digit1 != compareDigit1 || digit2 != compareDigit8 || digit4 != compareDigit4 || digit8 != compareDigit2){
                    isHorizontalRefl = false;
                    break;
                }

            }
            if (!isHorizontalRefl){
                break;
            }
        }
    }
    return isHorizontalRefl;
}

bool isGlidedHorizontalRefl(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    if (period % 2 == 1){
        return false;
    }
    if (sizeOfInputY % 2 == 0){
        for (int i = 0; i < sizeOfInputX; ++i){
            if (i >= (sizeOfInputX - period / 2 - period % 2 - 1)){
                for (int j = 0; j < sizeOfInputY; ++j){
                    inputArray[j][i] = 0;
                }
            }
            else{
                for (int j = sizeOfInputY / 2; j < sizeOfInputY; ++j){
                    inputArray[j][i] = inputArray[j][i + period / 2 + period % 2];
                }
            }

        }
    }
    else{
        for (int i = 0; i < sizeOfInputX; ++i){
            if (i >= (sizeOfInputX - period / 2 - period % 2 - 1)){
                for (int j = 0; j < sizeOfInputY; ++j){
                    inputArray[j][i] = 0;
                }
            }
            else{
                int changeDigit1 = inputArray[sizeOfInputY / 2][i] >> 0 & 1;
                int changeDigit2 = inputArray[sizeOfInputY / 2][i] >> 1 & 1;
                if ((inputArray[sizeOfInputY / 2][i + period / 2 + period % 2] >> 2 & 1) != (inputArray[sizeOfInputY / 2][i] >> 2 & 1)){
                    return false;
                }
                int changeDigit4 = inputArray[sizeOfInputY / 2][i + period / 2 + period % 2] >> 2 & 1;
                int changeDigit8 = inputArray[sizeOfInputY / 2][i + period / 2 + period % 2] >> 3 & 1;
                inputArray[sizeOfInputY / 2][i] = changeDigit1 + changeDigit2 * 2 + changeDigit4 * 4 + changeDigit8 * 8;
                for (int j = sizeOfInputY / 2 + 1; j < sizeOfInputY; ++j){
                    inputArray[j][i] = inputArray[j][i + period / 2 + period % 2];
                }
            }

        }
    }
    return isHorizontalRefl(inputArray, period);
}


bool isVerticalRefl1(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isVR = false;
    for (int i = period; i < period * 2; ++i){
        if (isVR){
            break;
        }
        else{
            isVR = true;
        }
        for (int j = 0; j < period; ++j){
            for (int x = 1; x < sizeOfInputY - 1; x++){
                int digit1 = inputArray[x][i + j + 1] >> 0 & 1;
                int digit2 = inputArray[x][i + j] >> 1 & 1;
                int digit4 = inputArray[x][i + j] >> 2 & 1;
                int digit8 = inputArray[x][i + j] >> 3 & 1;
                int compareDigit1 = inputArray[x][i - j] >> 0 & 1;
                int compareDigit2 = inputArray[x + 1][i - j] >> 1 & 1;
                int compareDigit4 = inputArray[x][i - j] >> 2 & 1;
                int compareDigit8 = inputArray[x - 1][i - j] >> 3 & 1;
                if (digit1 != compareDigit1 || digit4 != compareDigit4 || digit2 != compareDigit8 || digit8 != compareDigit2){
                    isVR = false;
                    break;
                }
            }
            if (!isVR){
                break;
            }
        }
    }
    return isVR;
}

bool isVerticalRefl2(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isVR = false;
    for (int i = period; i < period * 2; ++i){
        if (isVR){
            break;
        }
        else{
            isVR = true;
        }
        for (int j = 0; j < period; ++j){
            for (int x = 1; x < sizeOfInputY - 1; x++){
                int digit1 = inputArray[x][i + j] >> 0 & 1;
                int digit2 = inputArray[x][i + j] >> 1 & 1;
                int digit4 = inputArray[x][i + j] >> 2 & 1;
                int digit8 = inputArray[x][i + j] >> 3 & 1;
                int compareDigit1 = inputArray[x][i - j] >> 0 & 1;
                int compareDigit2 = inputArray[x + 1][i - j - 1] >> 1 & 1;
                int compareDigit4 = inputArray[x][i - j - 1] >> 2 & 1;
                int compareDigit8 = inputArray[x - 1][i - j - 1] >> 3 & 1;
                if (digit1 != compareDigit1 || digit4 != compareDigit4 || digit2 != compareDigit8 || digit8 != compareDigit2){
                    isVR = false;
                    break;
                }
            }
            if (!isVR){
                break;
            }
        }
    }
    return isVR;
}

bool isRotation1(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isRT = false;
    for (int i = period; i < period * 2; ++i){
        if (isRT){
            break;
        }
        else{
            isRT = true;
        }
        for (int j = 0; j < period; ++j){
            for (int x = 1; x < sizeOfInputY - 1; x++){
                int digit1 = inputArray[x][i + j] >> 0 & 1;
                int digit2 = inputArray[x][i + j] >> 1 & 1;
                int digit4 = inputArray[x][i + j] >> 2 & 1;
                int digit8 = inputArray[x][i + j] >> 3 & 1;
                int compareDigit1 = inputArray[sizeOfInputY - x][i - j] >> 0 & 1;
                int compareDigit2 = inputArray[sizeOfInputY - x][i - j - 1] >> 1 & 1;
                int compareDigit4 = inputArray[sizeOfInputY - x - 1][i - j - 1] >> 2 & 1;
                int compareDigit8 = inputArray[sizeOfInputY - x - 2][i - j - 1] >> 3 & 1;
                if (digit1 != compareDigit1 || digit4 != compareDigit4 || digit2 != compareDigit2 || digit8 != compareDigit8){
                    isRT = false;
                    break;
                }
            }
            if (!isRT){
                break;
            }
        }
    }
    return isRT;
}

bool isRotation2(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isRT = false;
    for (int i = period; i < period * 2; ++i){
        if (isRT){
            break;
        }
        else{
            isRT = true;
        }
        for (int j = 0; j < period; ++j){
            for (int x = 0; x < sizeOfInputY - 0; x++){
                int digit1;
                int digit2;
                if (x <= 0){
                    digit1 = 0;
                    digit2 = 0;
                }
                else{
                    digit1 = inputArray[x][i + j + 1] >> 0 & 1;
                    digit2 = inputArray[x][i + j + 1] >> 1 & 1;
                }
                int digit4 = inputArray[x][i + j] >> 2 & 1;
                int digit8;
                if (x >= sizeOfInputY - 1){
                    digit8 = 0;
                }
                else{
                    digit8 = inputArray[x][i + j] >> 3 & 1;
                }
                int compareDigit1;
                if (sizeOfInputY - x == 0){
                    compareDigit1 = 0;
                }
                else{
                    compareDigit1 = inputArray[sizeOfInputY - x][i - j] >> 0 & 1;
                }
                int compareDigit2;
                if (sizeOfInputY - x - 1 <= 0){
                    compareDigit2 = 0;
                }
                else{
                    compareDigit2 = inputArray[sizeOfInputY - x - 1][i - j] >> 1 & 1;
                }
                int compareDigit4 = inputArray[sizeOfInputY - x - 1][i - j] >> 2 & 1;
                int compareDigit8;
                if (sizeOfInputY - x - 2 >= sizeOfInputY - 1){
                    compareDigit8 = 0;
                }
                else{
                    compareDigit8 = inputArray[sizeOfInputY - x - 2][i - j] >> 3 & 1;
                }
                if (digit1 != compareDigit1 || digit4 != compareDigit4 || digit2 != compareDigit2 || digit8 != compareDigit8){
                    isRT = false;
                    break;
                }
            }
            if (!isRT){
                break;
            }
        }
    }
    return isRT;
}

void checkFrieze(int inputArray[sizeOfInputY][sizeOfInputX], int period){
    bool isVR = isVerticalRefl1(inputArray, period) || isVerticalRefl2(inputArray, period);
    bool isHR = isHorizontalRefl(inputArray, period);
    bool isRT = isRotation1(inputArray, period) || isRotation2(inputArray, period);
    bool isGHR = isGlidedHorizontalRefl(inputArray, period);
    // this is a bug, if I do not do this below and use the frieze_6.txt as an input file at the same time, all of these four flags are FALSEs, I have no idea about why this situation happens.
    int a = isVR;
    int b = isHR;
    int c = isRT;
    int d = isGHR;
    if (!isVR && !isGHR && !isHR && !isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation only.\n", period);
    }
    else if (isVR && !isGHR && !isHR && !isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation\n        and vertical reflection only.\n", period);
    }
    else if (!isVR && !isGHR && isHR && !isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation\n        and horizontal reflection only.\n", period);
    }
    else if (!isVR && isGHR && !isHR && !isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation\n        and glided horizontal reflection only.\n", period);
    }
    else if (!isVR && !isGHR && !isHR && isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation\n        and rotation only.\n", period);
    }
    else if (isVR && isGHR && !isHR && isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation,\n        glided horizontal and vertical reflections, and rotation only.\n", period);
    }
    else if (isVR && !isGHR && isHR && isRT){
        printf("Pattern is a frieze of period %d that is invariant under translation,\n        horizontal and vertical reflections, and rotation only.\n", period);
    }
}


int main(int argc, char **argv) {
    produceInput();
    if (isIncorrect){
        printf("Incorrect input.\n");
        return EXIT_FAILURE;
    }
    int inputArray[sizeOfInputY][sizeOfInputX];
    int x = 0;
    int y = 0;
    for (int i = 0; i < 2048; i++){
        if (input[i] == -2){
            break;
        }
        else if (input[i] == -1){
            x = 0;
            y++;
        }
        else{
            inputArray[y][x] = input[i];
            x++;
        }

    }
    int period = getPeriod(inputArray);
    if (period)
        if (period == -1 || period < 2 || sizeOfInputX / period < 2 || sizeOfInputX % period > 1){
            printf("Input does not represent a frieze.\n");
            return EXIT_FAILURE;
        }

    if (argc > 2 || argc == 2 && strcmp(argv[1], "print")) {
        printf("I expect no command line argument or \"print\" as unique command line argument.\n");
        return EXIT_FAILURE;
    }
    if (argc == 2) {
        for (int i = 0; i < sizeOfInputY; i++){
            for (int j = 0; j < sizeOfInputX; j++){
                produceNum(inputArray[i][j], j, i);
            }
        }
        bubble_sort();
        printOut();
        return EXIT_SUCCESS;
    }
    else{
        checkFrieze(inputArray, period);
    }
    return EXIT_SUCCESS;
}

