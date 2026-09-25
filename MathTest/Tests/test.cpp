#include "pch.h"
#include "MathTest.h"
#include <stdexcept>

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


TEST(TaskTest, InvalidRange) {
    EXPECT_THROW(Task(10, 5), std::invalid_argument);
}

TEST(TaskTest, InvalidOperation) {
    EXPECT_THROW(Task(1, 10, '%'), std::invalid_argument);
}

TEST(TaskTest, DivisionByZero) {
    EXPECT_THROW(Task(0, 0, '/'), std::invalid_argument);
}

TEST(MathTestTest, InvalidCount) {
    EXPECT_THROW(MathTest(0), std::invalid_argument);
    EXPECT_THROW(MathTest(-1), std::invalid_argument);
}

TEST(MathTestTest, InvalidRange) {
    EXPECT_THROW(MathTest(5, 10, 1), std::invalid_argument);
}

TEST(MathTestTest, InvalidOperation) {
    EXPECT_THROW(MathTest(5, 1, 10, '%'), std::invalid_argument);
}

TEST(MathTestTest, InvalidIndexInSetAnswer) {
    MathTest test(5);

    EXPECT_THROW(test.set_answer(-1, 10), std::out_of_range);
    EXPECT_THROW(test.set_answer(5, 10), std::out_of_range);
}

TEST(MathTestTest, InvalidIndexInGetUserAnswer) {
    MathTest test(5);

    EXPECT_THROW(test.get_user_answer(-1), std::out_of_range);
    EXPECT_THROW(test.get_user_answer(5), std::out_of_range);
}

TEST(MathTestTest, InvalidIndexInGetTask) {
    MathTest test(5);

    EXPECT_THROW(test.get_task(-1), std::out_of_range);
    EXPECT_THROW(test.get_task(5), std::out_of_range);
}