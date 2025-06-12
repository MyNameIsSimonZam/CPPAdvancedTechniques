#pragma once
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int find_word(std::ifstream& words);
void file_viewer(std::string& path);
int salary_amount(std::ifstream& payroll);
std::string person_with_max_salary(std::ifstream& payroll);
void if_png(std::string& path);
void fill_the_file(std::ofstream& in_river);
void fillPayroll(std::ofstream& file);
void list_payroll(std::ifstream& payroll);
void add_payroll(std::ofstream& payroll);
void addRecord(std::map<std::string, std::string>& phoneBook,
               std::map<std::string, std::vector<std::string>>& surnameBook);
void printSurname(std::map<std::string, std::string>& phoneBook);
void printNumber(std::map<std::string, std::vector<std::string>>& surnameBook);