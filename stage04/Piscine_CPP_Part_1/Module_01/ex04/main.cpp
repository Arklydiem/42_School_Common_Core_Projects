#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

std::string	replace(std::string save, std::string strings[3]);

int main(int argc, char **argv){
	std::string	strings[3];
	if (argc != 4)
	{
		std::cout << "Only 3 args" << std::endl;
		return (1);
	}
	for (size_t i = 1; i < 4; i++){
		strings[i - 1] = argv[i];
		if (i < 3 && strings[i - 1].empty())
		{
			std::cout << "No empty arg" << std::endl;
			return (1);
		}
	}

	std::ifstream in; 
	std::ofstream out;
	in.open(strings[0].c_str(), std::ofstream::in);
	if (!in)
	{
		std::cout << "Impossible to open : " << strings[0] << std::endl;
		return (1);
	}
	out.open ((strings[0] + ".replace").c_str(), std::ofstream::out);
	if (!out)
	{
		in.close();
		std::cout << "Impossible to open : " << strings[0] << ".replace" << std::endl;
		return (1);
	}
	std::string		line;
	std::string		save;
	while (std::getline(in, line)){
		save += line;
		if (!in.eof())
			save += "\n";
	}
	in.close();

	
	out << replace(save, strings);
	out.close();
	return (0);
}

std::string	replace(std::string save, std::string strings[3]){
	size_t			i = 0;
	size_t			find_occur = save.find(strings[1]);
	std::string		file;
	while (save[i]){
		if (i != find_occur)
			file += save[i];
		else {
			file += strings[2];
			find_occur = save.find(strings[1], i + 1);
			i += strings[1].length() - 1;
		}
		i++;
	}
	return (file);
}