#pragma once

struct Task
{
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();
    Task(int min, int max, char operation ='\0');
};

class MathTest {
private:
    Task* tasks;
    int count;
    int* user_answers;
    int correct_count;

public:
    MathTest(int count);
    MathTest(int count, int min, int max);
    MathTest(int count, int min, int max, char operation);

    ~MathTest();

    void run();
    void set_answer(int index, int user_answer);
    void show_statistics();

    int get_correct_count();
    int get_user_answer(int index);
    Task get_task(int index);
    int get_count();
};