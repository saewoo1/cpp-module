#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <exception>
# include <iostream>

//key - value 사용이라 map이 맞지 않을가 하는,,..
class BitcoinExchange {
    private:
        std::map<std::string, float> bitcoinData;
        
        void checkCsvFile();
        void checkInputFile(char *file);
        bool validateDate(std::string date);
        bool validateValue(std::string value);
        void inputBitcoin(char *file);
        void validateInformation(std::string str);
        bool checkDateInputFile(const std::string &date);
        bool checkValueInputFile(const std::string &value);
        void printResult(std::string date, float value);

        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange& operator=(const BitcoinExchange &obj);

        void btc(char *file);

        class Error : public std::exception {
            public:
                const char *what() const throw();
        };

};

#endif