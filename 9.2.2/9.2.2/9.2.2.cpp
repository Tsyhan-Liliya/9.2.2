#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <conio.h>  
#include <stdarg.h>  

// Перевірка чи є символ цифрою 
#define IS_DIGIT_MACRO(c) ((c) >= '0' && (c) <= '9')

// Перевірка чи є символ буквою
#define IS_ALPHA_MACRO(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))

// Перевірка чи є символ пунктуаційним
#define IS_PUNCT_MACRO(c) (((c) == '!') || ((c) == '.') || ((c) == ',') || \
                           ((c) == '?') || ((c) == ';') || ((c) == ':') || \
                           ((c) == '-') || ((c) == '_'))

// Виведення кількості цифр
#define PRINT_DIGIT_COUNT(count) printf("Digits: %d\n", count)

// Виведення кількості букв
#define PRINT_ALPHA_COUNT(count) printf("Alphabetic: %d\n", count)

// Виведення кількості пунктуаційних символів
#define PRINT_PUNCT_COUNT(count) printf("Punctuation: %d\n", count)

// Виведення кількості інших символів
#define PRINT_OTHER_COUNT(count) printf("Other: %d\n", count)

// Виведення інформації про відсутність певних типів символів
#define PRINT_MISSING(type, count) printf("Missing %s: %d\n", type, count)

// Змінна кількості аргументів, num_chars - кількість переданих символів
void count_characters(int num_chars, ...) {
    int digit_count = 0;     // Лічильник цифр
    int alpha_count = 0;     // Лічильник букв
    int punct_count = 0;     // Лічильник пунктуаційних символів
    int other_count = 0;     // Лічильник інших символів

    va_list args;            // Змінна для роботи зі змінними аргументами
    va_start(args, num_chars); // Обробка змінної кількості аргументів

    // Проходимо через усі передані символи
    for (int i = 0; i < num_chars; i++) {
        char c = va_arg(args, int);  // Отримуємо символ через особливість va_arg

        // Перевіряємо чи є символ цифрою, якщо так то збільшуємо лічильник
        if (IS_DIGIT_MACRO(c)) {
            digit_count++; 
        }
        // Перевіряємо чи є символ буквою, якщо так то збільшуємо лічильник
        else if (IS_ALPHA_MACRO(c)) {
            alpha_count++; 
        }
        // Перевіряємо чи є символ пунктуацією, якщо так то збільшуємо лічильник
        else if (IS_PUNCT_MACRO(c)) {
            punct_count++; 
        }
        // Підрахунок інших символів
        else {
            other_count++; 
        }
    }

    va_end(args); // Обробка змінної кількості аргументів

    // Виводимо кількість кожного типу символів
    PRINT_DIGIT_COUNT(digit_count);
    PRINT_ALPHA_COUNT(alpha_count);
    PRINT_PUNCT_COUNT(punct_count);
    PRINT_OTHER_COUNT(other_count);

    // Перевірка відсутності певних типів символів відносно максимального значення
    int max_count = (digit_count > alpha_count) ? digit_count : alpha_count;
    max_count = (max_count > punct_count) ? max_count : punct_count;

    // Якщо кількість цифр менша за максимальну кількість виводимо скільки їх не вистачає
    if (digit_count < max_count) {
        PRINT_MISSING("digits", max_count - digit_count);
    }
    // Якщо кількість алфавітних символів менша за максимальну кількість виводимо скільки їх не вистачає
    if (alpha_count < max_count) {
        PRINT_MISSING("alphabetic characters", max_count - alpha_count);
    }
    // Якщо кількість пунктуаційних символів менша за максимальну кількість виводимо скільки їх не вистачає
    if (punct_count < max_count) {
        PRINT_MISSING("punctuation characters", max_count - punct_count);
    }
}

int main(void) {
    // Функція з тестовими прикладами
    printf("Test 1:\n");
    count_characters(6, 'a', '1', '!', 'b', '2', '-'); 

    printf("\nTest 2:\n");
    count_characters(4, '3', '7', '9', '*'); 

    printf("\nTest 3:\n");
    count_characters(2, 'x', '?'); 

    // Затримка поки не натиснута будь-яка клавіша 
    while (_kbhit());

    return 0; 
}
