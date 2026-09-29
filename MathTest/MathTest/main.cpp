#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "MathTest.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    try {
        MathTest test(5, 1, 10);

        std::cout << "Ответьте на 5 вопросов:" << std::endl;
        test.run();
        test.show_statistics();
    }
    catch (const std::exception& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}