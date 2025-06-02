#include <limits>

#include "Header.h"

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main() {
  int choice;
  bool running = true;

  do {
    std::cout << "Choose a task to run\n";
    std::cout << "Урок 1. Чтение из файлов\n";
    std::cout << "1. Задача 1\n";
    std::cout << "2. Задача 2\n";
    std::cout << "3. Задача 3\n";
    std::cout << "4. Задача 4\n";
    std::cout << "Enter your choice: ";
    std::cout << "Урок 2. Запись в файлы\n";
    std::cout << "6. Задание 1. Реализация записи в ведомость учёта\n\n";
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();  // сброс failbit
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // очистка мусора
      std::cout << "Please enter a valid number!\n\n";
      continue;
    }

    switch (choice) {
      case 1:
        task1();
        running = false;
        break;
      case 2:
        task2();
        running = false;
        break;
      case 3:
        task3();
        running = false;
        break;
      case 4:
        task4();
        running = false;
        break;
      case 5:
        task5();
        running = false;
        break;
      case 6:
        task6();
        running = false;
        break;
      case 7:
        task7();
        running = false;
        break;
      case 8:
        task8();
        running = false;
        break;
      case 9:
        task9();
        running = false;
        break;
      default:
        std::cout << "Invalid choice...\n";
    }
  } while (running);

  return 0;
}