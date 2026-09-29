#pragma once

#include <vector>

struct Task {
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();
    Task(int min, int max, char operation = '\0');
};

class MathTest {
private:
    std::vector<Task> tasks;
    std::vector<int> user_answers;
    std::vector<bool> answered;
    int count = 0;
    int correct_count = 0;

    void init(int count);

public:
    MathTest(int count);
    MathTest(int count, int min, int max);
    MathTest(int count, int min, int max, char operation);

    void run();
    void set_answer(int index, int user_answer);
    void show_statistics() const;

    int get_correct_count() const;
    int get_user_answer(int index) const;
    const Task& get_task(int index) const;
    int get_count() const;
};