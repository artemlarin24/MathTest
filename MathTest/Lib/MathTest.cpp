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
    if (operation == '/') {
        answer = num_1 / num_2;
    }
}

MathTest::MathTest(int count)
{
    this->count = count;

    tasks = new Task[count];
    user_answers = new int[count];

    correct_count = 0;

    for (int i = 0; i < count; i++)
    {
        user_answers[i] = 0;
    }
}


MathTest::MathTest(int count, int min, int max)
{
    this->count = count;

    tasks = new Task[count];
    user_answers = new int[count];

    correct_count = 0;

    for (int i = 0; i < count; i++)
    {
        tasks[i] = Task(min, max);
        user_answers[i] = 0;
    }
}


MathTest::MathTest(int count, int min, int max, char operation)
{
    this->count = count;

    tasks = new Task[count];
    user_answers = new int[count];

    correct_count = 0;

    for (int i = 0; i < count; i++)
    {
        tasks[i] = Task(min, max, operation);
        user_answers[i] = 0;
    }
}


MathTest::~MathTest()
{
    delete[] tasks;
    delete[] user_answers;
}