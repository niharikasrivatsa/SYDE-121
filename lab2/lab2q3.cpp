#include <iostream>
#include <string>
    
#include <sstream>
 

auto main() -> int
{

    std::string lineInput;
    std::string output_string;

	while ( getline( std::cin, lineInput ) )
	{
        int num {0};
        std::istringstream ( lineInput ) >> num;
        
        if (num % 3 == 0 and num % 5 == 0){
            auto output_string = std::to_string( num ) + std::string("\t") + std::string("Fizz  Buzz");
            std::cout << output_string << std::endl;

        } else if  (num % 3 == 0) {
            auto output_string = std::to_string( num ) + std::string("\t") + std::string("Fizz");
            std::cout << output_string << std::endl;

        } else if (num % 5 == 0){
            auto output_string = std::to_string( num ) + std::string("\t") + std::string("Buzz");
            std::cout << output_string << std::endl;

        } else if (num % 5 != 0 and num%3 !=0) {
            auto output_string = std::to_string( num );
            std::cout << output_string << std::endl;
        }

    }
}
