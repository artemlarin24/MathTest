#include "MathTest.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
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

void MathTest::set_answer(int index, int user_answer)
{
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

        std::cout << "Question " << i + 1 << ": ";
        std::cout << tasks[i].num_1 << " "
            << tasks[i].operation << " "
            << tasks[i].num_2 << " = ";

        std::cin >> user_answer;

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

    cout << "Total Result: "
        << correct_count << " / "
        << count << " (mark: "
        << mark << ")" << endl;
}

int MathTest::get_correct_count()
{
    return correct_count;
}


int MathTest::get_user_answer(int index)
{
    return user_answers[index];
}


Task MathTest::get_task(int index)
{
    return tasks[index];
}

int MathTest::get_count()
{
    return count;
}