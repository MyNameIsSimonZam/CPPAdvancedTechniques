#include "Header.h"

void task1();
void task2();
void task3();
void task4();

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
    std::cin >> choice;

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
    default:
      std::cout << "Invalid choice...\n";
    }
  } while (running);

  return 0;
}