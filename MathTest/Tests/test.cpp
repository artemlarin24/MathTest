#include "pch.h"
#include "MathTest.h"

TEST(TaskTest, DefaultConstructor) {
    Task task;

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}
TEST(TaskTest, ConstructorWithRange) {
    Task task(5, 10);

    EXPECT_EQ(task.operation, '+');
}
TEST(TaskTest, Plus) {
    Task task(1, 10, '+');

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}
TEST(TaskTest, Minus) {
    Task task(1, 10, '-');

    EXPECT_EQ(task.operation, '-');
    EXPECT_EQ(task.answer, task.num_1 - task.num_2);
}
TEST(TaskTest, Multiply) {
    Task task(1, 10, '*');

    EXPECT_EQ(task.operation, '*');
    EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}


TEST(MathTestTest, Count){
    MathTest test(5);

    EXPECT_EQ(test.get_count(), 5);
}

TEST(MathTestTest, CorrectCount){
    MathTest test(5);

    EXPECT_EQ(test.get_correct_count(), 0);
}

TEST(MathTestTest, Range){
    MathTest test(5, 1, 10);

    Task task = test.get_task(0);

    EXPECT_GE(task.num_1, 1);
    EXPECT_LE(task.num_1, 10);

    EXPECT_GE(task.num_2, 1);
    EXPECT_LE(task.num_2, 10);
}

TEST(MathTestTest, Plus){
    MathTest test(5, 1, 10, '+');

    Task task = test.get_task(0);

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}

TEST(MathTestTest, Minus){
    MathTest test(5, 1, 10, '-');

    Task task = test.get_task(0);

    EXPECT_EQ(task.operation, '-');
    EXPECT_EQ(task.answer, task.num_1 - task.num_2);
}

TEST(MathTestTest, CorrectAnswer){
    MathTest test(5, 1, 10, '+');

    Task task = test.get_task(0);

    test.set_answer(0, task.answer);

    EXPECT_EQ(test.get_correct_count(), 1);
}

TEST(MathTestTest, WrongAnswer){
    MathTest test(5, 1, 10, '+');

    Task task = test.get_task(0);

    test.set_answer(0, task.answer + 1);

    EXPECT_EQ(test.get_correct_count(), 0);
}


