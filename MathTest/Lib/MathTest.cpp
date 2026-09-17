#include "MathTest.h"
#include <cstdlib>

Task::Task() {
    num_1 = rand() % 10 + 1;
    num_2 = rand() % 10 + 1;
    operation = '+';
    answer = num_1 + num_2;
}

Task::Task(int min, int max, char op) {
    num_1 = rand() % (max - min + 1) + min;
    num_2 = rand() % (max - min + 1) + min;

    if (op == '\0') {
        operation = '+';
    }
    else {
        operation = op;
    }

    if (operation == '+') {
        answer = num_1 + num_2;
    }

    if (operation == '-') {
        answer = num_1 - num_2;
    }

    if (operation == '*') {
        answer = num_1 * num_2;
    }
}