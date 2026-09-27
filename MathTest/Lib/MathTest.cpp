#include "MathTest.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

Task::Task() : Task(1, 10) {
}

Task::Task(int min, int max, char op) {
    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

    if (op != '\0' && op != '+' && op != '-' &&
        op != '*' && op != '/') {
        throw invalid_argument("Недопустимая операция");
    }

    const char operations[] = { '+', '-', '*', '/' };
    operation = (op == '\0') ? operations[rand() % 4] : op;

    if (operation == '/' && min == 0 && max == 0) {
        throw invalid_argument("Деление на ноль");
    }

    num_1 = rand() % (max - min + 1) + min;
    num_2 = rand() % (max - min + 1) + min;

    switch (operation) {
    case '+':
        answer = num_1 + num_2;
        break;
    case '-':
        answer = num_1 - num_2;
        break;
    case '*':
        answer = num_1 * num_2;
        break;
    case '/':
        if (num_2 == 0) {
            num_2 = (min < 0) ? -1 : 1;
        }
        answer = num_1 / num_2;
        break;
    }
}

void MathTest::init(int count) {
    if (count <= 0) {
        throw invalid_argument("Количество вопросов должно быть больше нуля");
    }

    this->count = count;
    correct_count = 0;
    tasks.resize(count);
    user_answers.assign(count, 0);
    answered.assign(count, false);
}

MathTest::MathTest(int count) {
    init(count);
}

MathTest::MathTest(int count, int min, int max) {
    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

    init(count);

    for (int i = 0; i < count; ++i) {
        tasks[i] = Task(min, max);
    }
}

MathTest::MathTest(int count, int min, int max, char operation) {
    if (min > max) {
        throw invalid_argument("Минимум больше максимума");
    }

    if (operation != '\0' && operation != '+' &&
        operation != '-' && operation != '*' && operation != '/') {
        throw invalid_argument("Недопустимая операция");
    }

    if (operation == '/' && min == 0 && max == 0) {
        throw invalid_argument("Деление на ноль");
    }

    init(count);

    for (int i = 0; i < count; ++i) {
        tasks[i] = Task(min, max, operation);
    }
}

void MathTest::set_answer(int index, int user_answer) {
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    if (answered[index] && user_answers[index] == tasks[index].answer) {
        --correct_count;
    }

    user_answers[index] = user_answer;
    answered[index] = true;

    if (user_answer == tasks[index].answer) {
        ++correct_count;
    }
}

void MathTest::run() {
    correct_count = 0;

    for (int i = 0; i < count; ++i) {
        user_answers[i] = 0;
        answered[i] = false;
    }

    for (int i = 0; i < count; ++i) {
        int user_answer;

        cout << "Вопрос " << i + 1 << ": "
            << tasks[i].num_1 << " "
            << tasks[i].operation << " "
            << tasks[i].num_2 << " = ";

        if (!(cin >> user_answer)) {
            throw runtime_error("Ответ должен быть целым числом");
        }

        set_answer(i, user_answer);
    }
}

void MathTest::show_statistics() const {
    cout << endl << "|          No |";

    for (int i = 0; i < count; ++i) {
        cout << setw(8) << i + 1 << " |";
    }

    cout << endl << "|    Question |";

    for (int i = 0; i < count; ++i) {
        cout << setw(3) << tasks[i].num_1
            << " " << tasks[i].operation
            << " " << setw(2) << tasks[i].num_2
            << " |";
    }

    cout << endl << "| True Answer |";

    for (int i = 0; i < count; ++i) {
        cout << setw(8) << tasks[i].answer << " |";
    }

    cout << endl << "| Your Answer |";

    for (int i = 0; i < count; ++i) {
        if (answered[i]) {
            cout << setw(8) << user_answers[i] << " |";
        }
        else {
            cout << setw(8) << "-" << " |";
        }
    }

    cout << endl << "|      Result |";

    for (int i = 0; i < count; ++i) {
        const bool correct =
            answered[i] && user_answers[i] == tasks[i].answer;

        cout << setw(8) << (correct ? "+" : "-") << " |";
    }

    cout << endl << endl;

    const int percent = correct_count * 100 / count;
    char mark;

    if (percent >= 80) {
        mark = 'A';
    }
    else if (percent >= 60) {
        mark = 'B';
    }
    else if (percent >= 40) {
        mark = 'C';
    }
    else if (percent >= 20) {
        mark = 'D';
    }
    else {
        mark = 'F';
    }

    cout << "Итог: " << correct_count << " / " << count
        << " (оценка: " << mark << ")" << endl;
}

int MathTest::get_correct_count() const {
    return correct_count;
}

int MathTest::get_user_answer(int index) const {
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    return user_answers[index];
}

const Task& MathTest::get_task(int index) const {
    if (index < 0 || index >= count) {
        throw out_of_range("Неверный номер вопроса");
    }

    return tasks[index];
}

int MathTest::get_count() const {
    return count;
}