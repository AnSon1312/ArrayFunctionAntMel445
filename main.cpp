#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <clocale> 

int add(int a, int b) {
    return a + b;
}

bool isEven(int num) {
    return num % 2 == 0;
}

double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double average(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    setlocale(LC_ALL, "RU");

    srand(time(0));

    int choice = -1;

    while (choice != 0) {
        std::cout << "\n=========================================\n";
        std::cout << "             ВЫБЕРИТЕ ЗАДАЧУ            \n";
        std::cout << "=========================================\n";
        std::cout << "РАЗДЕЛ: МАССИВЫ\n";
        std::cout << "  1. Базовый (Вывод массива)\n";
        std::cout << "  2. Начальный (Сумма элементов)\n";
        std::cout << "  3. Средний (Поиск максимума)\n";
        std::cout << "  4. Продвинутый (Пузырьковая сортировка)\n";
        std::cout << "  5. Экспертный (Транспонирование матрицы)\n\n";
        std::cout << "РАЗДЕЛ: ФУНКЦИИ\n";
        std::cout << "  6. Базовый (Сумма двух чисел)\n";
        std::cout << "  7. Начальный (Проверка на четность)\n";
        std::cout << "  8. Средний (Возведение в степень)\n";
        std::cout << "  9. Продвинутый (Факториал)\n";
        std::cout << "  10. Экспертный (Среднее арифметическое массива)\n\n";
        std::cout << "  0. ВЫХОД\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Ваш выбор: ";

        std::cin >> choice;
        std::cout << "\n--- РЕЗУЛЬТАТ ---\n\n";

        switch (choice) {
        case 1: {
            int arr[] = { 3, 7, 1, 9, 4 }; 
            std::cout << "Элементы массива: ";
            for (int i = 0; i < 5; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 2: {
            int arr[] = { 5, 2, 9, 1, 7, 4, 6, 3, 8, 0 };
            int sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += arr[i];
            }
            std::cout << "Сумма всех элементов массива: " << sum << std::endl;
            break;
        }
        case 3: {
            int arr[8]; 
            std::cout << "Сгенерированный массив: ";
            for (int i = 0; i < 8; i++) {
                arr[i] = rand() % 100 + 1;
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;

            int maxVal = arr[0];
            for (int i = 1; i < 8; i++) {
                if (arr[i] > maxVal) maxVal = arr[i];
            }
            std::cout << "Максимальное значение в массиве: " << maxVal << std::endl;
            break;
        }
        case 4: {
            int arr[] = { 45, 12, 89, 5, 23, 67, 2, 56, 78, 34, 90, 11 };
            std::cout << "Исходный массив: ";
            for (int i = 0; i < 12; i++) std::cout << arr[i] << " ";
            std::cout << std::endl;

            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            std::cout << "Отсортированный массив: ";
            for (int i = 0; i < 12; i++) std::cout << arr[i] << " ";
            std::cout << std::endl;
            break;
        }
        case 5: {
            int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
            int result[3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    result[j][i] = matrix[i][j];
                }
            }
            std::cout << "Результат транспонирования:\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << result[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;
        }
        case 6: {
            int summa = add(5, 7);
            std::cout << "Вызов функции add(5, 7). Результат: " << summa << std::endl;
            break;
        }
        case 7: {
            int number = 8;
            std::cout << "Проверка числа " << number << ": ";
            if (isEven(number)) std::cout << "число четное\n";
            else std::cout << "число нечетное\n";
            break;
        }
        case 8: {
            std::cout << "3 в степени 4 = " << power(3.0, 4) << std::endl;
            std::cout << "5 в квадрате (значение по умолчанию) = " << power(5.0) << std::endl;
            break;
        }
        case 9: {
            int num = 5;
            std::cout << "Факториал числа " << num << " = " << factorial(num) << std::endl;
            break;
        }
        case 10: {
            int myArr[] = { 10, 20, 30, 40, 50, 60, 70 };
            double avg = average(myArr, 7);
            std::cout << "Среднее арифметическое элементов массива: " << avg << std::endl;
            break;
        }
        case 0:
            std::cout << "Программа завершена. Пока-пока!\n";
            break;
        default:
            std::cout << "Неверный выбор! Пожалуйста, введите число от 0 до 10.\n";
            break;
        }
    }

    return 0;
}
