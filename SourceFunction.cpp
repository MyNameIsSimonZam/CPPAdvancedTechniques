#include "Header.h"

// функция возвращает количество упоминаний слова
int find_word(std::ifstream& words) {
  if (!words.is_open()) {
    std::cerr << "File can't be opened ";
    return 0;
  }

  std::cout << "Enter a word: ";
  std::string target_word;
  std::cin >> target_word;

  std::string word_in_file;
  size_t count{};  // uniform-инициализация
  while (words >> word_in_file) {
    if (word_in_file == target_word) ++count;
  }

  return count;
}

// функция принимает путь и возвращает содержимое файла
void file_viewer(std::string& path) {
  std::ifstream content;
  content.open(path, std::ios::binary);
  if (!content.is_open()) {
    std::cerr << "File can't be opened";
    return;
  }

  char buffer[512];

  while (content.read(buffer, sizeof(buffer)) || content.gcount() > 0) {
    std::cout.write(buffer, content.gcount());
  }

  content.close();  // закроется сам по завершении функции, но оставлю для
                    // явного обозначения
}

// Функция суммирует зарпалату
int salary_amount(std::ifstream& payroll) {
  std::string first_name;
  std::string second_name;
  std::string date;
  int salary;
  int result{};

  while (payroll >> first_name >> second_name >> salary >> date) {
    result += salary;
  }

  return result;
}

// Возвращает имя того, кто больше всех заработал
std::string person_with_max_salary(std::ifstream& payroll) {
  std::string first_name;
  std::string second_name;
  std::string date;
  int salary;
  std::string result;
  int max_salary{};

  while (payroll >> first_name >> second_name >> salary >> date) {
    if (max_salary < salary) {
      max_salary = salary;
      result = first_name + " " + second_name;
    }
  }

  return result;
}

// It output a massege, file is PNG or not
void if_png(std::string& path) {
  std::ifstream content(path, std::ios::binary);
  if (!content.is_open()) {
    std::cerr << "File can't be opened";
    return;
  }

  char buffer[4];
  content.read(buffer, 4);

  if (content.gcount() < 4) {
    std::cout << "No\n";
    return;
  }
  bool flag = true;
  char etalon[] = {-119, 'P', 'N', 'G'};
  for (int i = 0; i < 4; ++i) {
    if (buffer[i] != etalon[i]) flag = false;
  }

  if (flag)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}

// Write into the file the list whith vector
void fill_the_file(std::ofstream& out_river) {
  std::vector<std::string> fishes;
  std::string word;

  std::cout << "Fill the list (Enter stop when you'll finish)\n";
  while (word != "stop") {
    std::cin >> word;
    if (word == "stop") break;
    fishes.push_back(word);
  }

  for (auto x : fishes) {
    out_river << x << "\n";
  }
}

void list_payroll(std::ifstream& payroll) {
  struct Payroll {
    std::string fName_;
    std::string sName_;
    std::string date_;
    size_t amount_;
  };

  std::cout << std::filesystem::current_path()
            << "\n";  // выводит текущий рабочий каталог, из которого была
                      // запущена программа
  if (!payroll.is_open()) {
    std::cerr << "File can't be opened";
    return;
  }

  Payroll record;
  std::vector<Payroll> vpayroll;
  while (true) {
    payroll >> record.fName_;
    if (payroll.eof()) break;
    payroll >> record.sName_;
    payroll >> record.date_;
    payroll >> record.amount_;
    vpayroll.push_back(record);
  };

  for (const auto& x : vpayroll) {
    std::cout << x.fName_ << " " << x.sName_ << " " << x.date_ << " "
              << x.amount_ << " " << "\n";
  }
}

void add_payroll(std::ofstream& payroll) {
  struct Payroll {
    std::string fName_;
    std::string sName_;
    std::string date_;
    size_t amount_;
  };

  std::cout << std::filesystem::current_path()
            << "\n";  // выводит текущий рабочий каталог, из которого была
                      // запущена программа
  if (!payroll.is_open()) {
    std::cerr << "File can't be opened";
    return;
  }

  Payroll record;
  while (true) {
    std::cout << "Enter your first name(stop for exit): ";
    std::getline(std::cin, record.fName_);
    if (record.fName_ == "stop") break;
    std::cout << "Enter your last name (stop for exit): ";
    std::getline(std::cin, record.sName_);
    if (record.sName_ == "stop") break;
    std::cout << "Enter a date of issue (01.01.2026)(stop for exit): ";
    std::getline(std::cin, record.date_);
    if (record.date_ == "stop") break;
    std::cout << "Enter payment amount: ";
    std::cin >> record.amount_;
    std::cin.ignore();

    payroll << record.fName_ << " " << record.sName_ << " " << record.date_ << " " << record.amount_ << "\n";
  }
}