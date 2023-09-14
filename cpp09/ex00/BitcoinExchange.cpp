#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

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
    return false;
}

//범위 검수?
bool BitcoinExchange::validateValue(std::string value)
{
    return false;
}
