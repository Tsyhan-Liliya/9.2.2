#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <conio.h>  
#include <stdarg.h>  

// �������� �� � ������ ������ 
#define IS_DIGIT_MACRO(c) ((c) >= '0' && (c) <= '9')

// �������� �� � ������ ������
#define IS_ALPHA_MACRO(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))

// �������� �� � ������ �������������
#define IS_PUNCT_MACRO(c) (((c) == '!') || ((c) == '.') || ((c) == ',') || \
                           ((c) == '?') || ((c) == ';') || ((c) == ':') || \
                           ((c) == '-') || ((c) == '_'))

// ��������� ������� ����
#define PRINT_DIGIT_COUNT(count) printf("Digits: %d\n", count)

// ��������� ������� ����
#define PRINT_ALPHA_COUNT(count) printf("Alphabetic: %d\n", count)

// ��������� ������� ������������� �������
#define PRINT_PUNCT_COUNT(count) printf("Punctuation: %d\n", count)

// ��������� ������� ����� �������
#define PRINT_OTHER_COUNT(count) printf("Other: %d\n", count)

// ��������� ���������� ��� ��������� ������ ���� �������
#define PRINT_MISSING(type, count) printf("Missing %s: %d\n", type, count)

// ����� ������� ���������, num_chars - ������� ��������� �������
void count_characters(int num_chars, ...) {
    int digit_count = 0;     // ˳������� ����
    int alpha_count = 0;     // ˳������� ����
    int punct_count = 0;     // ˳������� ������������� �������
    int other_count = 0;     // ˳������� ����� �������

    va_list args;            // ����� ��� ������ � ������� �����������
    va_start(args, num_chars); // ������� ����� ������� ���������

    // ��������� ����� �� ������� �������
    for (int i = 0; i < num_chars; i++) {
        char c = va_arg(args, int);  // �������� ������ ����� ���������� va_arg

        // ���������� �� � ������ ������, ���� ��� �� �������� ��������
        if (IS_DIGIT_MACRO(c)) {
            digit_count++; 
        }
        // ���������� �� � ������ ������, ���� ��� �� �������� ��������
        else if (IS_ALPHA_MACRO(c)) {
            alpha_count++; 
        }
        // ���������� �� � ������ �����������, ���� ��� �� �������� ��������
        else if (IS_PUNCT_MACRO(c)) {
            punct_count++; 
        }
        // ϳ�������� ����� �������
        else {
            other_count++; 
        }
    }

    va_end(args); // ������� ����� ������� ���������

    // �������� ������� ������� ���� �������
    PRINT_DIGIT_COUNT(digit_count);
    PRINT_ALPHA_COUNT(alpha_count);
    PRINT_PUNCT_COUNT(punct_count);
    PRINT_OTHER_COUNT(other_count);

    // �������� ��������� ������ ���� ������� ������� ������������� ��������
    int max_count = (digit_count > alpha_count) ? digit_count : alpha_count;
    max_count = (max_count > punct_count) ? max_count : punct_count;

    // ���� ������� ���� ����� �� ����������� ������� �������� ������ �� �� �������
    if (digit_count < max_count) {
        PRINT_MISSING("digits", max_count - digit_count);
    }
    // ���� ������� ��������� ������� ����� �� ����������� ������� �������� ������ �� �� �������
    if (alpha_count < max_count) {
        PRINT_MISSING("alphabetic characters", max_count - alpha_count);
    }
    // ���� ������� ������������� ������� ����� �� ����������� ������� �������� ������ �� �� �������
    if (punct_count < max_count) {
        PRINT_MISSING("punctuation characters", max_count - punct_count);
    }
}

int main(void) {
    // ������� � ��������� ����������
    printf("Test 1:\n");
    count_characters(6, 'a', '1', '!', 'b', '2', '-'); 

    printf("\nTest 2:\n");
    count_characters(4, '3', '7', '9', '*'); 

    printf("\nTest 3:\n");
    count_characters(2, 'x', '?'); 

    // �������� ���� �� ��������� ����-��� ������ 
    while (_kbhit());

    return 0; 
}
