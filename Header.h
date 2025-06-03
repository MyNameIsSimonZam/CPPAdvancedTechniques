#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>

int find_word(std::ifstream& words);
void file_viewer(std::string& path);
int salary_amount(std::ifstream& payroll);
std::string person_with_max_salary(std::ifstream& payroll);
void if_png(std::string& path);
