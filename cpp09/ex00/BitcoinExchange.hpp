#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <exception>

//key - value 사용이라 map이 맞지 않을가 하는,,..
class BitcoinExchange {
    private:
        std::map<std::string, float> bitcoinData;
        
        void checkCsvFile();
        void checkInputFile(char *file);
        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange& operator=(const BitcoinExchange &obj);

        void validation(char *file);

        class Error : public std::exception {
            public:
                const char *what() const throw();
        };

};

#endif