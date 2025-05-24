#include "Header.h"

int find_word() {  // функция возвращает количество упоминаний слова
  std::ifstream words;
  words.open("data/words.txt", std::ios::binary);

  if (!words.is_open()) std::cerr << "File can't be opened";

  words.close();

  return 0;
}