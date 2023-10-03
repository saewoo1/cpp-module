#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void	printRes() const;
		int		fillCsv();
		int		inputValue(char *filename) const;
		int		parseValue(float value) const;
		int		parseDate(std::string date) const;
		bool	isLeapYear(int year) const;
		bool	checkFormat(std::string date) const;
		float	getExchangeRate(const std::string &date) const;
};

#endif