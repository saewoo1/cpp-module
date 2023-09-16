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
    if (read.compare("date,exchange_rate") != 0) {

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

void BitcoinExchange::checkInputFile(char *file) {
    std::fstream fileStream;
    std::string line;

    fileStream.open(file, std::ifstream::in);
    if (!fileStream.is_open()) {
        std::cout << "Error: can't open!!!" << std::endl;
        throw Error();
    }

    if (std::getline(fileStream, line).eof()) {
        std::cout << "Error: empty file!!" << std::endl;
        throw Error();
    }

    if (line.compare("date | value") != 0) {
        std::cout << "Error: format error!" << std::endl;
        throw Error();
    }

    line.erase();
    fileStream.close();
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

void BitcoinExchange::inputBitcoin(char *file) {
    std::ifstream inputFile(file);

    std::string read;

    getline(inputFile, read);
    while(getline(inputFile, read))
        validateInformation(read);
}

void BitcoinExchange::validateInformation(std::string inputLine) {
    std::string date, value;
    std::istringstream format(inputLine);

    float   val;
    int     i = 0;

    while (std::getline(format, value, ' ')) {
        if (i == 0) {
            if (!checkDateInputFile(value)) return ;
            date = value;
        }
        if (i == 1 && value != "|") {
            std::cout << "Error: bad input" << inputLine << std::endl;
            return ;
        }
        if (i == 2) {
            if (!checkValueInputFile(value)) return ;
            val == std::strtod(inputLine.c_str(), NULL);
            if (val < 1 || val > 1000) {
                std::cout << "Error: too large" << std::endl;
                return ;
            }
        }
        i++;
    }

    if (i != 3) {
        std::cout << "Error : bad input" << std::endl;
        return ;
    }

    printResult(date, val);
}

void BitcoinExchange::printResult(std::string date, float value) {
    std::map<std::string, float>::const_iterator iter;
    float res;

    res = 0;
    iter = bitcoinData.find(date);
    if (iter != bitcoinData.end()) {
        res = (iter->second) * value;
    } else {
        iter = bitcoinData.lower_bound(date);
        if (iter == bitcoinData.begin()) {
            std::cout << "Error: invalid date" << std::endl;
            return ;
        }
        --iter;
        res = (iter->second) * value;
    }

    (value == static_cast<int>(value)) ?
      std::cout << date << " => " << static_cast<int>(value) << " = " <<  res << std::endl 
    : std::cout << date << " => " << value << " = " << res << std::endl;


}

bool BitcoinExchange::checkValueInputFile(const std::string &str) {
    char *ptr = NULL;
    double value = std::strtod(str.c_str(), &ptr);

    if (str.find('.', 0) == 0 || str.find('.', str.length() - 1 != std::string::npos)) {
        std::cout << "Error: please input only number" << std::endl;
        return false;
    }

    if (value == 0.0 && !std::isdigit(str[0])) {
        std::cout << "Error: please input only number" << std::endl;
        return false;
    }

    if (*ptr && std::strcmp(ptr, "f")) {
        std::cout << "Error: please input only number" << std::endl;
        return false;
    }
    
    if (value < 0) {
        std::cout << "Error: please input only number" << std::endl;
        return false;
    }

    if (str.length() > 10 || (str.length() == 10 && value > 2147483647)) {
        std::cout << "Error: too large number" << std::endl;
        return false;
    }
    return true;
}


bool BitcoinExchange::checkDateInputFile(const std::string &date) {
    std::string splitted;
    std::istringstream ss(date);
    int year, month, day;
    int i;

    if (date.find('-', date.length() - 1) != std::string::npos) {
        std::cout << "Error: invalid date forman" << date << std::endl;
        return false;
    }

    while (std::getline(ss, splitted, '-')) {
        if (i == 0) {
            std::istringstream(splitted) >> year;
            if (year < 2009 || year > 2022) {
                std::cout << "Error: invalid year" << date << std::endl;
                return false;
            }
        }
        if (i == 1) {
            std::istringstream(splitted) >> month;
            if (month < 1 || month > 12) {
                std::cout << "Error: invalid month" << date << std::endl;
                return false;
            }
        }

        if (i == 2) {
            std::istringstream(splitted) >> day;
            if (day < 1 || day > 31) {
                std::cout << "Error: invalid day" << date << std::endl;
                return false;
            }
            if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
                std::cout << "Error: invalid day" << date << std::endl;
                return false;
            }
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
               if (month == 2 && day > 29) {
                std::cout << "Error: invalid day" << date << std::endl;
                return false;
            } else if (month == 2 && day > 28) {
                std::cout << "Error: invalid day" << date << std::endl;
                return false;
            }
        }
        i++;
    }

    if (i != 3) {
        std::cout << "Error: invalid date type" << date << std::endl;
        return false;
    }
    return true;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    // TODO: insert return statement here
}

void BitcoinExchange::btc(char *file)
{
    try {
        checkCsvFile();
        checkInputFile(file);
    } catch(...) {
        return ;
    }
    inputBitcoin(file);
}