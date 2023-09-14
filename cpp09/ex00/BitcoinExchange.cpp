#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <sstream>

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
    while (std::getline(csv, read)) {
        if (read != "date,exchange_rate") {
            comma_idx = read.find(',');
            if (!validateDate(read.substr(0, comma_idx))) {
                std::cout << "Error: invalid date" << std::endl;
                throw Error();
            }

            if (!validateValue(read.substr(comma_idx + 1, read.length()))) {
                std::cout << "Error: invalid value" << std::endl;
                throw Error();
            }
        }
    }
    //데이터 어케 담지??
}

//split으로 타입 검수, 윤년 검수
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
            //윤달 계산.. 어케하노
        }
        
    }
    if (i != 3) return false;

    return true;
}

//범위 검수?
bool BitcoinExchange::validateValue(std::string value)
{
    return false;
}
