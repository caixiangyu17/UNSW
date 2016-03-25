#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
typedef struct word {
    char value[100];
    struct word *pt_to_next_word;
} Word;
typedef struct sentence {
    struct word *value;
    struct sentence *pt_to_next_sentence;
} Sentence;
Word *create_word(const char value[100]){
    Word *const pt_to_word = (Word*)malloc(sizeof(Word));
    assert(pt_to_word);
    strcpy(pt_to_word->value, value);
    pt_to_word->pt_to_next_word = NULL;
    return pt_to_word;
}
void append_to_word_list(const char value[100], Word **const pt_to_pt_to_word){
    Word *pt_to_new_word = create_word(value);
    if (!*pt_to_pt_to_word){
        *pt_to_pt_to_word = pt_to_new_word;
        return;
    }
    Word *pt_to_word = *pt_to_pt_to_word;
    while (pt_to_word->pt_to_next_word != NULL){
        pt_to_word = pt_to_word->pt_to_next_word;
    }
    pt_to_word->pt_to_next_word = pt_to_new_word;
}
Sentence *create_sentence(Word *word){
    Sentence *pt_to_sentence = (Sentence*)malloc(sizeof(Sentence));
    assert(pt_to_sentence);
    pt_to_sentence->value = word;
    pt_to_sentence->pt_to_next_sentence = NULL;
    return pt_to_sentence;
}
void append_to_sentence_list(Word *value, Sentence **pt_to_pt_to_sentence){

    Sentence *pt_to_new_sentence = create_sentence(value);
    if (*pt_to_pt_to_sentence == NULL){
        *pt_to_pt_to_sentence = pt_to_new_sentence;
        return;
    }
    Sentence *pt_to_sentence = *pt_to_pt_to_sentence;
    while (pt_to_sentence->pt_to_next_sentence != NULL){
        pt_to_sentence = pt_to_sentence->pt_to_next_sentence;
    }
    pt_to_sentence->pt_to_next_sentence = pt_to_new_sentence;
}
void doNothing(){
}
#define CONST_LV1_signed 0
#define CONST_LV1_unsigned 1
#define CONST_LV1_char 2
#define CONST_LV1_short 3
#define CONST_LV1_int 4
#define CONST_LV1_long 5
#define CONST_LV1_float 6
#define CONST_LV1_double 7
#define CONST_LV1_void 8
#define CONST_LV1_first_letter_is_A 9
#define CONST_LV1_first_letter_is_An 10
#define CONST_LV1_second_letter_is_begin_with_vowel 11
#define CONST_LV1_contain_variable_name 12
#define LV1_LENGTH  13
int **check_lv1;
bool isIncorrect_lv1 = false;
int count_sentences = 0;
void check_lv_1(Sentence *st_list){
    check_lv1 = (int **)malloc(sizeof(int) * count_sentences * LV1_LENGTH);
    for (int i = 0; i < count_sentences; i++){
        check_lv1[i] = (int *)malloc(sizeof(int) * LV1_LENGTH);
    }
    for (int i = 0; i < count_sentences; i++){
        for (int j = 0; j < LV1_LENGTH; j++){
            check_lv1[i][j] = false;
        }
    }
    int sentence_id = 0;
    while (st_list){
        int count_words = 0;
        struct word *tempValue = st_list->value;
        while (tempValue){
            if (count_words == 0){
                check_lv1[sentence_id][CONST_LV1_first_letter_is_A] = (strcmp(tempValue->value, "A") == 0 ? true : false);
                check_lv1[sentence_id][CONST_LV1_first_letter_is_An] = (strcmp(tempValue->value, "An") == 0 ? true : false);
            }
            if (count_words == 1){
                bool begin_with_vowel = false;
                begin_with_vowel = (strcmp(tempValue->value, "int") == 0 ? true : false) || begin_with_vowel;
                begin_with_vowel = (strcmp(tempValue->value, "unsigned") == 0 ? true : false) || begin_with_vowel;
                begin_with_vowel = (strcmp(tempValue->value, "array") == 0 ? true : false) || begin_with_vowel;
                check_lv1[sentence_id][CONST_LV1_second_letter_is_begin_with_vowel] = begin_with_vowel;
            }
            check_lv1[sentence_id][CONST_LV1_signed] += (strcmp(tempValue->value, "signed") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_unsigned] += (strcmp(tempValue->value, "unsigned") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_char] += (strcmp(tempValue->value, "char") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_short] += (strcmp(tempValue->value, "short") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_int] += (strcmp(tempValue->value, "int") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_long] += (strcmp(tempValue->value, "long") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_float] += (strcmp(tempValue->value, "float") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_double] += (strcmp(tempValue->value, "double") == 0 ? true : false);
            check_lv1[sentence_id][CONST_LV1_void] += (strcmp(tempValue->value, "void") == 0 ? true : false);
            count_words++;
            tempValue = tempValue->pt_to_next_word;
        }
        sentence_id++;
        st_list = st_list->pt_to_next_sentence;
    }
}
#define PSW_char 1000000
#define PSW_signed_char 101000000
#define PSW_unsigned_char 11000000
#define PSW_short 100000
#define PSW_signed_short 100100000
#define PSW_unsigned_short 10100000
#define PSW_short_int 110000
#define PSW_signed_short_int 100110000
#define PSW_unsigned_short_int 10110000
#define PSW_int 10000
#define PSW_signed 100000000
#define PSW_unsigned 10000000
#define PSW_unsigned_int 10010000
#define PSW_signed_int 100010000
#define PSW_long 1000
#define PSW_signed_long 100001000
#define PSW_unsigned_long 10001000
#define PSW_long_int 11000
#define PSW_signed_long_int 100011000
#define PSW_unsigned_long_int 10011000
#define PSW_long_long 2000
#define PSW_signed_long_long 100002000
#define PSW_unsigned_long_long 10002000
#define PSW_long_long_int 12000
#define PSW_signed_long_long_int 100012000
#define PSW_unsigned_long_long_int 10012000
#define PSW_float 100
#define PSW_double 10
#define PSW_long_double 1010
#define PSW_void 1
#define PSW_refer 0
int getBasicTypeByRecursion(int sentence_id, char **referrence, char **variable_name){
    int password = 0;
    if (referrence[sentence_id][0] != '\0'){
        for (int i = 0; i < count_sentences; i++){
            if (strcmp(variable_name[i], referrence[sentence_id]) == 0){
                password = getBasicTypeByRecursion(i, referrence, variable_name);
                break;
            }
        }
    }
    else{
        for (int j = 0; j < LV1_LENGTH - 4; j++){
            password = password * 10 + check_lv1[sentence_id][j];
        }
    }
    return password;
}

char *getBasicType(int sentence_id, char **referrence, char **variable_name){
    long password = 0;
    for (int j = 0; j < LV1_LENGTH - 4; j++){
        password = password * 10 + check_lv1[sentence_id][j];
    }
    if (referrence[sentence_id][0] != '\0'){
        password = getBasicTypeByRecursion(sentence_id, referrence, variable_name);
    }
    switch (password){
        case PSW_char:
            return "char";
            break;
        case PSW_signed_char:
            return "signed char";
            break;
        case PSW_unsigned_char:
            return "unsigned char";
            break;
        case PSW_short:
            return "short";
            break;
        case PSW_signed_short:
            return "short";
            break;
        case PSW_unsigned_short:
            return "unsigned short";
            break;
        case PSW_short_int:
            return "short";
            break;
        case PSW_signed_short_int:
            return "short";
            break;
        case PSW_int:
            return "int";
            break;
        case PSW_signed:
            return "int";
            break;
        case PSW_signed_int:
            return "int";
            break;
        case PSW_unsigned:
            return "unsigned";
            break;
        case PSW_unsigned_int:
            return "unsigned";
            break;
        case PSW_long:
            return "long";
            break;
        case PSW_signed_long:
            return "long";
            break;
        case PSW_unsigned_long:
            return "unsigned long";
            break;
        case PSW_long_int:
            return "long";
            break;
        case PSW_signed_long_int:
            return "long";
            break;
        case PSW_unsigned_long_int:
            return "unsigned long";
            break;
        case PSW_long_long:
            return "long long";
            break;
        case PSW_signed_long_long:
            return "long long";
            break;
        case PSW_unsigned_long_long:
            return "unsigend long long";
            break;
        case PSW_long_long_int:
            return "long long";
            break;
        case PSW_signed_long_long_int:
            return "long long";
            break;
        case PSW_unsigned_long_long_int:
            return "unsigned long long";
            break;
        case PSW_float:
            return "float";
            break;
        case PSW_double:
            return "double";
            break;
        case PSW_long_double:
            return "long double";
            break;
        case PSW_void:
            return "void";
            break;
        default:
            return "Incorrect input";
    }
}
#define CONST_LV2_judge_status_none 0
#define CONST_LV2_judge_status_array1 1
#define CONST_LV2_judge_status_array2 2
#define CONST_LV2_judge_status_array3 3
#define CONST_LV2_judge_status_array4 4
#define CONST_LV2_judge_status_pointer1 5
#define CONST_LV2_judge_status_pointer2 6
#define CONST_LV2_judge_status_pointer3 7
#define CONST_LV2_judge_status_function1 8
#define CONST_LV2_judge_status_function2 9
#define CONST_LV2_judge_status_function3 10
#define CONST_LV2_judge_status_datum 11
#define CONST_LV2_judge_status_type1 12
#define CONST_LV2_judge_status_type2 13
#define CONST_LV2_judge_status_type3 14
#define CONST_LV2_judge_status_type4 15
#define CONST_LV2_main_type_array 16
#define CONST_LV2_main_type_pointer 17
#define CONST_LV2_main_type_function 18
#define CONST_LV2_main_type_others 19
#define CONST_LV2_main_type_init 20
int lv2_judge_status = CONST_LV2_judge_status_none;
bool lv2_is_a = false;
bool lv2_is_an = false;
int lv2_count = 0;
bool isIncorrect_lv2 = false;
void get_variable_name(Sentence *st_list, int *main_type, char **variable_name){
    int sentence_id = 0;
    char **temp_variable_name = (char **)malloc(sizeof(char) * count_sentences * 100);
    for (int i = 0; i < count_sentences; i++){
        temp_variable_name[i] = (char *)malloc(sizeof(char) * 100);
        temp_variable_name[i][0] = '\0';
    }
    while (st_list){
        int count_words = 0;
        struct word *tempValue = st_list->value;
        while (tempValue){
            if (count_words == 1){
                ((strcmp(tempValue->value, "array") != 0) && (strcmp(tempValue->value, "pointer") != 0) && (strcmp(tempValue->value, "function") != 0)) ? main_type[sentence_id] = CONST_LV2_main_type_others : doNothing();
                (strcmp(tempValue->value, "array") == 0) ? main_type[sentence_id] = CONST_LV2_main_type_array : doNothing();
                (strcmp(tempValue->value, "function") == 0) ? main_type[sentence_id] = CONST_LV2_main_type_function : doNothing();
                (strcmp(tempValue->value, "pointer") == 0) ? main_type[sentence_id] = CONST_LV2_main_type_pointer : doNothing();
            }
            if (tempValue->pt_to_next_word == NULL && main_type[sentence_id] == CONST_LV2_main_type_others){
                strcpy(temp_variable_name[sentence_id], tempValue->value);
            }

            if (main_type[sentence_id] != CONST_LV2_main_type_others && count_words == 2){
                strcpy(temp_variable_name[sentence_id], tempValue->value);
            }
            tempValue = tempValue->pt_to_next_word;
            count_words++;
        }
        sentence_id++;
        st_list = st_list->pt_to_next_sentence;
    }
    for (int i = 0; i < count_sentences; i++){
        if (strcmp(temp_variable_name[i], "signed") == 0){
        }
        else if (strcmp(temp_variable_name[i], "unsigned") == 0){
        }
        else if (strcmp(temp_variable_name[i], "char") == 0){
        }
        else if (strcmp(temp_variable_name[i], "short") == 0){
        }
        else if (strcmp(temp_variable_name[i], "int") == 0){
        }
        else if (strcmp(temp_variable_name[i], "long") == 0){
        }
        else if (strcmp(temp_variable_name[i], "float") == 0){
        }
        else if (strcmp(temp_variable_name[i], "double") == 0){
        }
        else if (strcmp(temp_variable_name[i], "of") == 0){
        }
        else if (strcmp(temp_variable_name[i], "to") == 0){
        }
        else if (strcmp(temp_variable_name[i], "returning") == 0){
        }
        else{
            strcpy(variable_name[i], temp_variable_name[i]);
        }
    }
}
int string2int(char *string){
    int value = 0;
    for (int i = 0; string[i] != '\0'; i++){
        if (isdigit(string[i])){
            value = value * 10 + (string[i] - '0');
        }
        else{
            value = -1;
            break;
        }
    }
    return value;
}
void addParentheses(int sentence_id, char **left, char **right){
    if (lv2_judge_status == CONST_LV2_judge_status_pointer2 || lv2_judge_status == CONST_LV2_judge_status_pointer3){
        strcat(left[sentence_id], "(");
        strcat(right[sentence_id], ")");
    }
}

void check_lv2_and_3_single_sentence(struct word *tempValue, int sentence_id, int count_words, char **left, char **right, char **referrence, int *to_referrence_type){
    if (lv2_judge_status == CONST_LV2_judge_status_array3){
        if ((strcmp(tempValue->value, "array") != 0) && (strcmp(tempValue->value, "arrays") != 0) && (strcmp(tempValue->value, "pointer") != 0) && (strcmp(tempValue->value, "pointers") != 0) && (strcmp(tempValue->value, "data") != 0) && (strcmp(tempValue->value, "datum") != 0)){
            isIncorrect_lv2 = true;
        }
    }
    if (lv2_judge_status == CONST_LV2_judge_status_pointer3){
        if ((strcmp(tempValue->value, "function") != 0) && (strcmp(tempValue->value, "array") != 0) && (strcmp(tempValue->value, "arrays") != 0) && (strcmp(tempValue->value, "pointer") != 0) && (strcmp(tempValue->value, "pointers") != 0) && (strcmp(tempValue->value, "data") != 0) && (strcmp(tempValue->value, "datum") != 0)){
            isIncorrect_lv2 = true;
        }
    }
    if (lv2_judge_status == CONST_LV2_judge_status_function3){
        if (strcmp(tempValue->value, "pointer") != 0 && strcmp(tempValue->value, "datum") != 0){
            isIncorrect_lv2 = true;
        }
    }
    if (strcmp(tempValue->value, "a") == 0 || strcmp(tempValue->value, "A") == 0){
        lv2_is_a = true;
        lv2_is_an = false;
        lv2_count = 1;
        if (lv2_judge_status == CONST_LV2_judge_status_pointer2){
            lv2_judge_status = CONST_LV2_judge_status_pointer3;
        }
        if (lv2_judge_status == CONST_LV2_judge_status_function2){
            lv2_judge_status = CONST_LV2_judge_status_function3;
        }
    }
    else if (strcmp(tempValue->value, "an") == 0 || strcmp(tempValue->value, "An") == 0){
        lv2_is_a = false;
        lv2_is_an = true;
        lv2_count = 1;
        if (lv2_judge_status == CONST_LV2_judge_status_pointer2){
            lv2_judge_status = CONST_LV2_judge_status_pointer3;
        }
        if (lv2_judge_status == CONST_LV2_judge_status_function2){
            lv2_judge_status = CONST_LV2_judge_status_function3;
        }
    }
    else if (string2int(tempValue->value) > 0){
        lv2_is_a = false;
        lv2_is_an = false;
        lv2_count = string2int(tempValue->value);
        if (lv2_judge_status == CONST_LV2_judge_status_array2){
            strcat(right[sentence_id], "[");
            strcat(right[sentence_id], tempValue->value);
            strcat(right[sentence_id], "]");
            lv2_judge_status = CONST_LV2_judge_status_array3;
        }
    }
    else if (strcmp(tempValue->value, "array") == 0){
        isIncorrect_lv2 = !lv2_is_an || isIncorrect_lv2;
        addParentheses(sentence_id, left, right);
        lv2_judge_status = CONST_LV2_judge_status_array1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_array;
    }
    else if (strcmp(tempValue->value, "arrays") == 0){
        if (lv2_count == 1){
            isIncorrect_lv2 = true;
        }
        addParentheses(sentence_id, left, right);
        lv2_judge_status = CONST_LV2_judge_status_array1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_array;
    }
    else if (strcmp(tempValue->value, "pointer") == 0){
        isIncorrect_lv2 = !lv2_is_a;
        lv2_judge_status = CONST_LV2_judge_status_pointer1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_pointer;
    }
    else if (strcmp(tempValue->value, "pointers") == 0){
        if (lv2_count == 1){
            isIncorrect_lv2 = true;
        }
        lv2_judge_status = CONST_LV2_judge_status_pointer1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_pointer;
    }
    else if (strcmp(tempValue->value, "function") == 0){
        isIncorrect_lv2 = !lv2_is_a || isIncorrect_lv2;
        addParentheses(sentence_id, left, right);
        lv2_judge_status = CONST_LV2_judge_status_function1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_function;
    }
    else if (strcmp(tempValue->value, "functions") == 0){
        if (lv2_count == 1){
            isIncorrect_lv2 = true;
        }
        addParentheses(sentence_id, left, right);
        lv2_judge_status = CONST_LV2_judge_status_function1;
        to_referrence_type[sentence_id] = CONST_LV2_main_type_function;
    }
    else if (strcmp(tempValue->value, "of") == 0){
        if (lv2_judge_status == CONST_LV2_judge_status_array1){
            lv2_judge_status = CONST_LV2_judge_status_array2;
        }
        else if (lv2_judge_status == CONST_LV2_judge_status_datum){

        }
        else if (lv2_judge_status == CONST_LV2_judge_status_type3){
            lv2_judge_status = CONST_LV2_judge_status_type4;
        }
        else{
            isIncorrect_lv2 = true;
        }
    }
    else if (strcmp(tempValue->value, "to") == 0){
        if (lv2_judge_status == CONST_LV2_judge_status_pointer1){
            lv2_judge_status = CONST_LV2_judge_status_pointer2;
            strcat(left[sentence_id], "*");
        }
        else{
            isIncorrect_lv2 = true;
        }
    }
    else if (strcmp(tempValue->value, "returning") == 0){
        if (lv2_judge_status == CONST_LV2_judge_status_function1){
            strcat(right[sentence_id], "()");
            lv2_judge_status = CONST_LV2_judge_status_function2;
        }
        else{
            isIncorrect_lv2 = true;
        }
    }
    else if (strcmp(tempValue->value, "datum") == 0){
        if (lv2_count > 1){

            isIncorrect_lv2 = true;
        }

        lv2_judge_status = CONST_LV2_judge_status_datum;
    }
    else if (strcmp(tempValue->value, "data") == 0){
        if (lv2_count == 1){
            isIncorrect_lv2 = true;
        }
        lv2_judge_status = CONST_LV2_judge_status_datum;
    }
    else if (strcmp(tempValue->value, "type") == 0){
        if (lv2_judge_status == CONST_LV2_judge_status_type2){
            lv2_judge_status = CONST_LV2_judge_status_type3;
        }
        else{
            lv2_judge_status = CONST_LV2_judge_status_type1;
        }
    }
    else if (lv2_judge_status == CONST_LV2_judge_status_type1){
        if (strcmp(tempValue->value, "the") == 0){
            lv2_judge_status = CONST_LV2_judge_status_type2;
        }
        else{
            if ((strcmp(tempValue->value, "signed") != 0) && (strcmp(tempValue->value, "unsigned") != 0) && (strcmp(tempValue->value, "char") != 0) && (strcmp(tempValue->value, "short") != 0) && (strcmp(tempValue->value, "int") != 0) && (strcmp(tempValue->value, "long") != 0) && (strcmp(tempValue->value, "float") != 0) && (strcmp(tempValue->value, "double") != 0)){
                isIncorrect_lv2 = true;
            }
        }
    }
    else if (lv2_judge_status == CONST_LV2_judge_status_type4){
        strcpy(referrence[sentence_id], tempValue->value);
        lv2_judge_status = CONST_LV2_judge_status_none;
    }
}
void check_lv_2_and_3(Sentence *st_list, char **left, char **right, char **referrence, int *to_referrence_type){
    int sentence_id = 0;
    while (st_list){
        int count_words = 0;
        struct word *tempValue = st_list->value;
        while (tempValue){
            check_lv2_and_3_single_sentence(tempValue, sentence_id, count_words, left, right, referrence, to_referrence_type);
            count_words++;
            tempValue = tempValue->pt_to_next_word;
        }
        sentence_id++;
        st_list = st_list->pt_to_next_sentence;
    }
}
char *getRefLeft(int sentence_id, bool isRoot, int parent_type, char **referrence, char **left, int *main_type, int *to_referrence_type, char **variable_name){
    char *temp = (char *)malloc(sizeof(char));
    if (referrence[sentence_id][0] != '\0'){
        for (int i = 0; i < count_sentences; i++){
            if (strcmp(variable_name[i], referrence[sentence_id]) == 0){
                (!isRoot && (main_type[sentence_id] == CONST_LV2_main_type_function || (main_type[sentence_id] == CONST_LV2_main_type_array && parent_type != CONST_LV2_main_type_array)))? strcpy(temp, "(") : doNothing();
                strcat(temp, left[sentence_id]);
                strcat(temp, getRefLeft(i, false, to_referrence_type[sentence_id], referrence, left, main_type, to_referrence_type, variable_name));
                break;
            }
        }
    }
    else {
        strcpy(temp, left[sentence_id]);
    }
    return temp;
}
char *getRefRight(int sentence_id, bool isRoot, int parent_type, char **referrence, char **right, int *main_type, int *to_referrence_type, char **variable_name){
    char *temp = (char *)malloc(sizeof(char));
    if (referrence[sentence_id][0] != '\0'){
        for (int i = 0; i < count_sentences; i++){
            if (strcmp(variable_name[i], referrence[sentence_id]) == 0){
                (!isRoot && (main_type[sentence_id] == CONST_LV2_main_type_function || (main_type[sentence_id] == CONST_LV2_main_type_array && parent_type != CONST_LV2_main_type_array)))?strcpy(temp, ")"):strcpy(temp, right[sentence_id]);
                (!isRoot && (main_type[sentence_id] == CONST_LV2_main_type_function || (main_type[sentence_id] == CONST_LV2_main_type_array && parent_type != CONST_LV2_main_type_array)))?strcat(temp, right[sentence_id]):strcpy(temp, right[sentence_id]);
                strcat(temp, getRefRight(i, false, to_referrence_type[sentence_id], referrence, right, main_type, to_referrence_type, variable_name));
                break;
            }
        }
    }
    else {
        strcpy(temp, right[sentence_id]);
    }
    return temp;
}
bool isKeyWord(char *string){
    bool result = false;
    (strcmp(string, "a") == 0) ? result = true : doNothing();
    (strcmp(string, "an") == 0) ? result = true : doNothing();
    (strcmp(string, "A") == 0) ? result = true : doNothing();
    (strcmp(string, "An") == 0) ? result = true : doNothing();
    (strcmp(string, "the") == 0) ? result = true : doNothing();
    (strcmp(string, "signed") == 0) ? result = true : doNothing();
    (strcmp(string, "unsigned") == 0) ? result = true : doNothing();
    (strcmp(string, "short") == 0) ? result = true : doNothing();
    (strcmp(string, "int") == 0) ? result = true : doNothing();
    (strcmp(string, "long") == 0) ? result = true : doNothing();
    (strcmp(string, "char") == 0) ? result = true : doNothing();
    (strcmp(string, "float") == 0) ? result = true : doNothing();
    (strcmp(string, "double") == 0) ? result = true : doNothing();
    (strcmp(string, "array") == 0) ? result = true : doNothing();
    (strcmp(string, "pointer") == 0) ? result = true : doNothing();
    (strcmp(string, "function") == 0) ? result = true : doNothing();
    (strcmp(string, "arrays") == 0) ? result = true : doNothing();
    (strcmp(string, "pointers") == 0) ? result = true : doNothing();
    (strcmp(string, "functions") == 0) ? result = true : doNothing();
    (strcmp(string, "of") == 0) ? result = true : doNothing();
    (strcmp(string, "to") == 0) ? result = true : doNothing();
    (strcmp(string, "returning") == 0) ? result = true : doNothing();
    (strcmp(string, "data") == 0) ? result = true : doNothing();
    (strcmp(string, "datum") == 0) ? result = true : doNothing();
    (strcmp(string, "void") == 0) ? result = true : doNothing();
    (strcmp(string, "type") == 0) ? result = true : doNothing();
    string2int(string) > 0 ? result = true : doNothing();
    return result;
}
bool checkError(Sentence *st_list){
    int sentence_id = 0;
    bool result = true;
    while (st_list){
        int count_words = 0;
        struct word *tempValue = st_list->value;
        bool isAn = false;
        while (tempValue){
            if (count_words == 0){
                ((strcmp(tempValue->value, "An") != 0) && (strcmp(tempValue->value, "A") != 0)) ? result = false : doNothing();
                (strcmp(tempValue->value, "An") == 0) ? isAn = true : doNothing();
                (strcmp(tempValue->value, "A") == 0) ? isAn = false : doNothing();
            }
            else if (count_words == 1){
                (((strcmp(tempValue->value, "array") == 0) || (strcmp(tempValue->value, "int") == 0) || (strcmp(tempValue->value, "unsigned") == 0)) && !isAn) ? result = false : doNothing();
                (((strcmp(tempValue->value, "array") != 0) && (strcmp(tempValue->value, "int") != 0) && (strcmp(tempValue->value, "unsigned") != 0)) && isAn) ? result = false : doNothing();
            }
            else if (count_words != 2 && tempValue->pt_to_next_word != NULL && !isKeyWord(tempValue->value)){
                result = false;
            }
            if (!result){
                break;
            }
            count_words++;
            tempValue = tempValue->pt_to_next_word;
        }
        if (!result){
            break;
        }
        sentence_id++;
        st_list = st_list->pt_to_next_sentence;
    }
    return result;
}
bool check_variable_name(char **variable_name){
    bool result = true;
    for (int i = 0; i < count_sentences; i++){
        if (variable_name[i][0] == '\0'){
            continue;
        }
        result = !isKeyWord(variable_name[i]);
        isdigit(variable_name[i][0]) ? result = false : doNothing();
        int count_words = 0;

        while (variable_name[i][count_words] != '\0'){
            (!isdigit(variable_name[i][count_words]) && !isalpha(variable_name[i][count_words]) && variable_name[i][count_words] != '_') ? result = false : doNothing();
            if (!result){
                break;
            }
            count_words++;
        }
        if (!result){
            break;
        }
    }
    return result;
}
bool check_variable_repeated(char **variable_name, int *main_type){
    bool result = true;
    return result;
}
bool checkSingleLoop(int ttl, int sentence_id, char **variable_name, char **referrence){
    bool result = true;
    if (ttl > count_sentences){
        result = false;
        return result;
    }
    if (referrence[sentence_id][0] != '\0'){
        for (int i = 0; i < count_sentences; i++){
            if (strcmp(variable_name[i], referrence[sentence_id]) == 0){
                ttl++;
                result = checkSingleLoop(ttl, i, variable_name, referrence);
            }
        }
    }
    return result;
}
bool checkRefersLoop(char **variable_name, char **referrence){
    bool result = true;
    for (int i = 0; i < count_sentences; i++){
        result = checkSingleLoop(0, i, variable_name, referrence);
        if (!result){
            break;
        }
    }
    return result;
}
bool checkWrongReferrence(char **variable_name, char **referrence){
    bool temp = false;
    bool result = true;
    int count_repeat = 0;
    for (int i = 0; i < count_sentences; i++){
        if (referrence[i][0] == '\0'){
            continue;
        }
        for (int j = 0; j < count_sentences; j++){
            if (strcmp(variable_name[j], referrence[i]) == 0){
                temp = true;
                count_repeat++;
            }
            if (j == count_sentences - 1 && !temp){
                result = false;
            }
        }
        if(count_repeat > 1){
            result = false;
        }else{
            count_repeat = 0;
        }
        if (!result){
            break;
        }
    }
    return result;
}
bool checkFuncRefer(char **variable_name, char **referrence, int *main_type){
    bool result = true;
    for (int i = 0; i < count_sentences; i++){
        if (referrence[i][0] == '\0'){
            continue;
        }
        for (int j = 0; j < count_sentences; j++){
            //printf();
            if (strcmp(variable_name[j], referrence[i]) == 0){
                (main_type[i] == CONST_LV2_main_type_array && main_type[j] == CONST_LV2_main_type_function) ? result = false : doNothing();
                (main_type[i] == CONST_LV2_main_type_function && main_type[j] == CONST_LV2_main_type_function) ? result = false : doNothing();
            }
            if (!result){
                break;
            }
        }
        if (!result){
            break;
        }
    }
    return result;
}
int main(int argc, char **argv){
    Sentence *st_list = NULL;
    Word *sentence = NULL;
    if (argv[argc - 1][strlen(argv[argc - 1]) - 1] != '.'){
        isIncorrect_lv1 = true;
    }
    for (int i = 1; i < argc; i++){
        if (strchr(argv[i], '.')){
            int length = strlen(argv[i]);
            if (argv[i][length - 1] == '.'){
                argv[i][length - 1] = '\0';
            }
            append_to_word_list(argv[i], &sentence);
            append_to_sentence_list(sentence, &st_list);
            count_sentences++;
            while (sentence){
                sentence = sentence->pt_to_next_word;
            }
            sentence = NULL;
        }
        else{
            append_to_word_list(argv[i], &sentence);
        }
    }
    int sentence_id = 0;
    Sentence *st_list_lv1 = st_list;
    check_lv_1(st_list_lv1);
    char **left = (char **)malloc(sizeof(char) * count_sentences * 1024);
    char **right = (char **)malloc(sizeof(char) * count_sentences * 1024);
    char **referrence = (char **)malloc(sizeof(char) * count_sentences * 100);
    int *main_type = (int *)malloc(sizeof(int) * count_sentences);
    int *to_referrence_type = (int *)malloc(sizeof(int) * count_sentences);
    char **variable_name = (char **)malloc(sizeof(char) * count_sentences * 100);
    for (int i = 0; i < count_sentences; i++){
        left[i] = (char *)malloc(sizeof(char) * 1024);
        left[i][0] = '\0';
        right[i] = (char *)malloc(sizeof(char) * 1024);
        right[i][0] = '\0';
        referrence[i] = (char *)malloc(sizeof(char) * 100);
        referrence[i][0] = '\0';
        variable_name[i] = (char *)malloc(sizeof(char) * 100);
        variable_name[i][0] = '\0';
        main_type[i] = CONST_LV2_main_type_init;
        to_referrence_type[i] = CONST_LV2_main_type_init;
    }
    Sentence *st_list_lv2_and_3 = st_list;
    check_lv_2_and_3(st_list_lv2_and_3, left, right, referrence, to_referrence_type);
    Sentence *st_list_4_variable_name = st_list;
    get_variable_name(st_list_4_variable_name, main_type, variable_name);
    Sentence *st_list_check = st_list;
    if (!checkError(st_list_check) || isIncorrect_lv1 || isIncorrect_lv2){
        printf("Incorrect input\n");
        return 0;
    }
    if (!check_variable_name(variable_name)){
        printf("Incorrect input\n");
        return 0;
    }
    if (!checkRefersLoop(variable_name, referrence)){
        printf("Incorrect input\n");
        return 0;
    }
    if (!checkWrongReferrence(variable_name, referrence)){
        printf("Incorrect input\n");
        return 0;
    }
    if (!checkFuncRefer(variable_name, referrence, main_type)){
        printf("Incorrect input\n");
        return 0;
    }
    for (int i = 0; i < count_sentences; i++){
        printf("%s", getBasicType(i, referrence, variable_name));
        if(strcmp(getBasicType(i, referrence, variable_name), "Incorrect input") == 0){
            printf("\n");
            return 0;
        }
        char *leftString = getRefLeft(i, true, CONST_LV2_main_type_init, referrence, left, main_type, to_referrence_type, variable_name);
        char *rightString = getRefRight(i, true, CONST_LV2_main_type_init, referrence, right, main_type, to_referrence_type, variable_name);
        if (leftString[0] != '\0' || rightString[0] != '\0' || variable_name[i][0] != '\0'){
            printf(" ");
            for (int j = strlen(leftString) - 1; j >= 0; j--){
                printf("%c", leftString[j]);
            }
            printf("%s%s\n", variable_name[i], rightString);
        }
        else{
            printf("\n");
        }
    }
}