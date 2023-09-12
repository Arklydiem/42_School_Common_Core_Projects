#include <iostream>
#include <string.h>

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; argv[i]; i++){
			for (int y = 0; argv[i][y]; y++)
				std::cout << (char) ::toupper(argv[i][y]);
		}
		std::cout << std::endl;
	}
}
