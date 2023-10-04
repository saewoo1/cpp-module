#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	if (this != &obj)
		*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	_data.insert(obj._data.begin(), obj._data.end());
	return (*this);
}

int BitcoinExchange::fillCsv() {
	std::ifstream infile("data.csv");
	if (infile.is_open() == false) {
		std::cout << "Open data.csv failed" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		int	comma = line.find(',', 0);
		std::string	date = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);

		float value;
		std::istringstream iss(valueStr);
		if (!(iss >> value)) {
			std::cout << "Bad value : " << valueStr << std::endl;
			return 2;
		}
		_data[date] = value;
	}
	infile.close();
	return 0;
}

void BitcoinExchange::printRes() const {
	for (std::map<std::string, float>::const_iterator iter = _data.begin(); iter != _data.end(); iter++) {
		std::cout << iter->first << ", " << std::fixed << std::setprecision(2) << iter->second << std::endl;
	}
}

int BitcoinExchange::inputValue(char *filename) const {
	std::ifstream input(filename);
	if (input.is_open() == false) {
		std::cout << "Open " << filename << " failed" << std::endl;
		return 1; 
	}

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		std::istringstream iss(line);
		std::string	date;
		char	delimiter;
		float	value = 0.0;
		float	rate = 0.0;
		std::string	rest;

		if (iss >> date >> delimiter >> value >> rest)
			std::cerr << "Bad line : " << line << std::endl;
		else if (parseValue(value))
			;
		else if (parseDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else {
			rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << rate * value << std::endl;
		}
	}
	input.close();
	return 0;
}

int BitcoinExchange::parseValue(float value) const {
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return 2;
	}
	return (0);
}

int BitcoinExchange::parseDate(std::string date) const {
	if (checkFormat(date))
		return 1;
	std::istringstream iss(date);

	int	year, month, day;
	int	maxDay = 31;
	char del;

	iss >> year >> del >> month >> del >> day;
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		return (2);
	else if (year == 2009 && month == 1 && day < 02)
		return (3);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else if (month == 2) {
		if (isLeapYear(year))
			maxDay = 29;
		else
			maxDay = 28;
	}
	return (!(day <= maxDay));
}

bool BitcoinExchange::checkFormat(std::string date) const {
	std::istringstream iss(date);
	std::string year, month, day;

	std::getline(iss, year, '-');
	std::getline(iss, month, '-');
	std::getline(iss, day, '-');

	if (year.empty() || month.empty() || day.empty())
		return true;
	return false;
}

bool BitcoinExchange::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
	std::map<std::string, float>::const_iterator iter = _data.lower_bound(date);
	if (iter == _data.end())
		return ((--iter)->second);
	if (iter->first > date)
		iter--;
	return (iter->second);
}