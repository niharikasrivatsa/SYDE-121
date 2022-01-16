#include <iostream>
#include <string>

auto main() -> int
{
	std::string line;

	while ( getline( std::cin, line) )
	{
        int len = line.length();
        int n = len - 1;

        for(int i = 0; i < (len/2); i++){
            std::swap(line[i],line[n]);
            n = n - 1;
        }
        std::cout << line << std::endl;
    }
}