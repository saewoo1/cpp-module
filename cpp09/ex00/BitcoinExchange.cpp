#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <sstream>

//csv 파일을 읽은 후 map에 담아주기
void BitcoinExchange::checkCsvFile() {
    std::ifstream csv("data.csv");
    std::string read;

    size_t comma_idx;
    float value;

    if (!csv) {
        std::cout << "Error: invalid database file" << std::endl;
        throw Error();
    }
    if (std::getline(csv, read).eof()) {
        std::cout << "Error: empty database file" << std::endl;
        throw Error();
    }

    //첫 줄 읽기
    std::getline(csv, read);
    if (read != "date,exchange_rate") {

        std::cout << "Error: invalid first Line" << std::endl;
        throw Error();
    }

    while (std::getline(csv, read)) {
        comma_idx = read.find(',');
        if (!validateDate(read.substr(0, comma_idx))) {
            std::cout << "Error: invalid date" << std::endl;
            throw Error();
        }

        if (!validateValue(read.substr(comma_idx + 1, read.length()))) {
            std::cout << "Error: invalid value" << std::endl;
            throw Error();
        }
        std::istringstream(read.substr(comma_idx + 1, read.length())) >> value;
        bitcoinData[read.substr(0, comma_idx)] = value;
    }
}

//split으로 타입 검수, 윤년 검수
// 짝수 월일 땐 6월 전까진 30일까지, 홀수 월일땐 7월 후부터 30일까지
bool BitcoinExchange::validateDate(std::string date)
{
    if (date.length() != 10) return false;
    std::string splitted;
    std::stringstream ss(date);

    int year, month, day;
    int i = 0;

    while (std::getline(ss, splitted, '-')) {
        if (i == 0) {
            std::istringstream(splitted) >> year;
            if (year < 1000 || year > 9999) return false;
        } else if (i == 1) {
            std::istringstream(splitted) >> month;
            if (month < 1 || month > 12) return false;
        } else if (i == 2) {
            std::istringstream(splitted) >> day;
            if (day < 1 || day > 31) return false;
            if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) return false;
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
               if (month == 2 && day > 29) return false;
            } else if (month == 2 && day > 28) return false;
        }
        i++;
    }
    if (i != 3) return false;
    return true;
}

//범위 검수?
bool BitcoinExchange::validateValue(std::string value)
{
    char *ptr = NULL;
    double val = std::strtod(value.c_str(), &ptr);
    if (val == 0.0 && !std::isdigit(value[0])) return false;
    if (*ptr && std::strcmp(ptr, "f")) return false;
    if (val < 0 || val > 1000) return false;
    return true;
}
