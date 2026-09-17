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
>>>>>>> a7f55c3 (Добавлена реализация Task + добавлены тесты)
}