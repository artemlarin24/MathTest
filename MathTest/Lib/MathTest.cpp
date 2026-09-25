#include "MathTest.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Task::Task() {
    num_1 = rand() % 10 + 1;
    num_2 = rand() % 10 + 1;
    operation = '+';
    answer = num_1 + num_2;
}

Task::Task(int min, int max, char op) {
    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

    if (op != '\0' && op != '+' && op != '-' &&
        op != '*' && op != '/') {
        throw invalid_argument("Недопустимая операция");
    }

    if (op == '/' && min == 0 && max == 0) {
        throw invalid_argument("Деление на ноль");
    }

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
        while (num_2 == 0) {
            num_2 = rand() % (max - min + 1) + min;
        }
        answer = num_1 / num_2;
    }
}

MathTest::MathTest(int count)
{
    if (count <= 0) {
        throw invalid_argument("Количество вопросов должно быть больше нуля");
    }

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
    if (count <= 0) {
        throw invalid_argument("Количество вопросов должно быть больше нуля");
    }

    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

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
    if (count <= 0) {
        throw invalid_argument("Количество вопросов должно быть больше нуля");
    }

    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

    if (operation != '\0' && operation != '+' &&
        operation != '-' && operation != '*' &&
        operation != '/') {
        throw invalid_argument("Недопустимая операция");
    }

    if (operation == '/' && min == 0 && max == 0) {
        throw invalid_argument("Деление на ноль");
    }

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

void MathTest::set_answer(int index, int user_answer)
{
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    user_answers[index] = user_answer;

    if (user_answer == tasks[index].answer)
    {
        correct_count++;
    }
}

void MathTest::run()
{
    correct_count = 0;

    for (int i = 0; i < count; i++)
    {
        int user_answer;

        cout << "Вопрос " << i + 1 << ": ";
        cout << tasks[i].num_1 << " "
            << tasks[i].operation << " "
            << tasks[i].num_2 << " = ";

        if (!(cin >> user_answer)) {
            throw runtime_error("Ответ должен быть целым числом");
        }

        set_answer(i, user_answer);
    }
}

void MathTest::show_statistics()
{
    cout << endl;

    cout << "|          No |";

    for (int i = 0; i < count; i++)
    {
        cout << setw(8) << i + 1 << " |";
    }

    cout << endl;

    cout << "|    Question |";

    for (int i = 0; i < count; i++)
    {
        cout << setw(3) << tasks[i].num_1
            << " "
            << tasks[i].operation
            << " "
            << setw(2) << tasks[i].num_2
            << " |";
    }

    cout << endl;

    cout << "| True Answer |";

    for (int i = 0; i < count; i++)
    {
        cout << setw(8) << tasks[i].answer << " |";
    }

    cout << endl;

    cout << "| Your Answer |";

    for (int i = 0; i < count; i++)
    {
        cout << setw(8) << user_answers[i] << " |";
    }

    cout << endl;

    cout << "|      Result |";

    for (int i = 0; i < count; i++)
    {
        if (user_answers[i] == tasks[i].answer)
        {
            cout << setw(8) << "+" << " |";
        }
        else
        {
            cout << setw(8) << "-" << " |";
        }
    }

    cout << endl << endl;

    int percent = correct_count * 100 / count;

    char mark;

    if (percent >= 80)
    {
        mark = 'A';
    }
    else if (percent >= 60)
    {
        mark = 'B';
    }
    else if (percent >= 40)
    {
        mark = 'C';
    }
    else if (percent >= 20)
    {
        mark = 'D';
    }
    else
    {
        mark = 'F';
    }

    cout << "Итог: "
        << correct_count << " / "
        << count << " (оценка: "
        << mark << ")" << endl;
}

int MathTest::get_correct_count()
{
    return correct_count;
}

int MathTest::get_user_answer(int index)
{
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    return user_answers[index];
}

Task MathTest::get_task(int index)
{
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    return tasks[index];
}

int MathTest::get_count()
{
    return count;
}