/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:51:00 by argomez           #+#    #+#             */
/*   Updated: 2023/04/19 10:39:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

static	void	parseDataBase(std::ifstream& inputFile, std::map<std::string, float>& dataBase);
static	void	manageInputDatas(std::ifstream& inputFile, std::map<std::string, float>& dataBase);
static	bool	isDateValid(std::string stringDate);	

static unsigned int lineNb = 0;	
static bool			dataBaseError = false;


void	BitcoinExchange::run(int argc, char* argv[]){
	{	// Check Arguments
		try {
			std::cout << std::fixed;
			if (argc != 2)
				throw BitcoinExchange::ArgumentsException();
		}
		catch(const std::exception& e) {
			std::cout << e.what() << argc - 1 << std::endl;
			return ;
		}
	}
	
	std::ifstream	inputFile;
	std::ifstream	dataBaseFile;
	{	// Check Infiles
		std::string		file;
		std::string		line;
		try {
			file = argv[1];
			inputFile.open(argv[1]);
			if (!inputFile)
				throw BitcoinExchange::OpenFileException();
			file = "data.csv";
			dataBaseFile.open("data.csv");
			if (!dataBaseFile)
			{
				inputFile.close();
				throw BitcoinExchange::OpenFileException();
			}
		}
		catch(const std::exception& e) {
			std::cout << e.what() << file << std::endl;
			return ;
		}
	}

	std::map<std::string, float>	dataBase;
	{	//Parsing of DataBaseFile and Register it in a Map
		try	{
			parseDataBase(dataBaseFile, dataBase);
		}
		catch(const std::exception& e) {
			inputFile.close();
			dataBaseFile.close();
			std::cout << e.what() << '\n';
			return ;
		}
	}

	if (dataBaseError == false)
		std::cout << "\e[38;5;118m[Info]\e[0m DataBase ok ✅" << std::endl;
	std::cout << std::endl;

	{	//Manage Input with DataBase
		manageInputDatas(inputFile, dataBase);
	}

	inputFile.close();
	dataBaseFile.close();	
}

void	parseDataBase(std::ifstream& dataBaseFile, std::map<std::string, float>& dataBase){
	std::string line;
	std::string	date;
	std::string	value;
	float		floatValue;
	char*		restValue;
	size_t		commaIndex;

	lineNb = 0;
	while (!dataBaseFile.eof()){
		try
		{
			// Parsing dataBase File
			getline(dataBaseFile, line);
			lineNb++;
			if (line.empty() && dataBaseFile.eof())
				continue;
			if (line.empty())
				throw BitcoinExchange::DataBaseFormatException();

			// Check the Date
			commaIndex = line.find_last_of(",");
			if (commaIndex > 10)
				throw BitcoinExchange::DataBaseFormatException();
			date = line.substr(0, commaIndex);
			if (date == "date" && lineNb == 1)
				continue;
			if (commaIndex < 10)
				throw BitcoinExchange::DataBaseFormatException();
			if (!isDateValid(date))
				throw BitcoinExchange::DataBaseDateException();

			// Check the Value
			value = line.substr(commaIndex + 1);
			if (!isdigit(value[0]) && value[0] != '-')
				throw BitcoinExchange::DataBaseFormatException();
			floatValue = strtof(value.c_str(), &restValue);
			if (floatValue < 0)
				throw BitcoinExchange::DataBaseFormatException();
			if (strlen(restValue))
				throw BitcoinExchange::DataBaseFormatException();
				
			// If No Error, then save in the dataBase
			std::map<std::string, float>::iterator it = dataBase.begin();
			dataBase.insert(it, std::pair<std::string, float>(date, floatValue));
		}
		catch(const std::exception& e)
		{
			dataBaseError = true;
			std::cout << e.what() << lineNb << std::endl;
		}
	}

	if (dataBase.begin() == dataBase.end())
		throw BitcoinExchange::DataBaseEmptyException();
}

void	manageInputDatas(std::ifstream& inputFile, std::map<std::string, float>& dataBase){
	std::string	line;
	std::string date;
	std::string value;
	size_t		pipeIndex;
	float		floatValue;
	char*		restValue;

	lineNb = 0;
	while (!inputFile.eof()){
		try
		{
			// Parsing InputFile
			getline(inputFile, line);
			lineNb++;
			if (line.empty() && inputFile.eof())
				continue;
			if (line.empty())
				throw BitcoinExchange::InputEmptyFormatException();
			
			// Check the Date
			pipeIndex = line.find_last_of("|");
			if (pipeIndex > 11)
				throw BitcoinExchange::InputFormatException();
			date = line.substr(0, pipeIndex);
			if (date == "date " && lineNb == 1)
				continue;
			pipeIndex = line.find_last_of(" | ");
			date = line.substr(0, pipeIndex - 2);
			if (pipeIndex <= 11)
				throw BitcoinExchange::InputFormatException();
			if (!isDateValid(date))
				throw BitcoinExchange::InputFormatException();

			// Check the Value
			value = line.substr(pipeIndex + 1);
			if (!isdigit(value[0]) && value[0] != '-')
				throw BitcoinExchange::InputFormatException();
			floatValue = strtof(value.c_str(), &restValue);
			if (floatValue > 1000)
				throw BitcoinExchange::BigNumberException();
			if (floatValue < 0)
				throw BitcoinExchange::NegativeNumberException();
			if (strlen(restValue))
				throw BitcoinExchange::InputFormatException();
			
			// Check Input with DataBase
			std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
			if (it == dataBase.begin() && date < dataBase.begin()->first)
				throw BitcoinExchange::OutOfDateException();
			if (it != dataBase.begin() && it->first != date)
				it--;
			std::cout << date << " =>" << value << " = " << it->second * floatValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << "\"" << line << "\"" << std::endl;
		}
	}
}

bool	isDateValid(std::string stringDate){

	// Check if the Date Format is correct before send it to strptime
	if (stringDate.length() > 10)
		return (false);
	for (size_t i = 0; stringDate[i]; i++)
	{
		if (!isdigit(stringDate[i]) && stringDate[i] != '-')
			return (false);
	}
	
	struct tm	time;

	//	Collect date values with strptime fuction
	if (!strptime(stringDate.c_str(), "%Y-%m-%d", &time))
		return (false);
	time.tm_year += 1900;
	time.tm_mon += 1;

	// Check if day overflow and can cause false output
	if (strtol(stringDate.substr(stringDate.find_last_of("-") + 1).c_str(), NULL, 10) > 31)
		return (false);

	// Define if the year is leap or not
	bool	isLeap = 0;
	if ((time.tm_year % 4 == 0 && time.tm_year % 100 != 0) || time.tm_year % 400 == 0)
		isLeap = 1;

	// Define if there is too much day for febuary
	if (time.tm_mon == 2 && isLeap && time.tm_mday > 29)
		return (false);
	if (time.tm_mon == 2 && !isLeap && time.tm_mday > 28)
		return (false);

	// Define if there is too much days for all months
	if (time.tm_mon <= 7 && time.tm_mon % 2 == 0 && time.tm_mday > 30)
		return (false);
	if (time.tm_mon >= 8 && time.tm_mon % 2 == 1 && time.tm_mday > 30)
		return (false);
	return (true);
}


/* ---- Exceptions ---- */

const char *BitcoinExchange::DataBaseFormatException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Bad DataBase Format At Line : ");
}

const char *BitcoinExchange::DataBaseDateException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Bad DataBase Date   At Line : ");
}

const char *BitcoinExchange::DataBaseEmptyException::what() const throw(){
	return ("\e[38;5;196m[ERROR]\e[0m Empty DataBase.");
}

const char *BitcoinExchange::ArgumentsException::what() const throw(){
	return ("\e[38;5;196m[Error]\e[0m: Only One Argument Is Needed To Run, Actual :");
}

const char *BitcoinExchange::OpenFileException::what() const throw(){
	return ("\e[38;5;196m[Error]\e[0m: Impossible To Open The File : ");
}

const char *BitcoinExchange::DateFormatException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Wrong Date  ");
}

const char *BitcoinExchange::BigNumberException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Too Large Value => ");
}

const char *BitcoinExchange::NegativeNumberException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Negative Value => ");
}

const char *BitcoinExchange::InputEmptyFormatException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Empty Line => ");
}

const char *BitcoinExchange::InputFormatException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Bad input => ");
}

const char *BitcoinExchange::OutOfDateException::what() const throw(){
	return ("\e[38;5;208m[Warning]\e[0m Date Too Anterior => ");
}