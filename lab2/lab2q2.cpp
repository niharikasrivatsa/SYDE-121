// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

auto main() -> int
{
	std::string lineInput;

	auto line_counter {0};
	auto sum_length {0};
    auto max_length {0};
    auto min_length {0};

	while ( getline( std::cin, lineInput ) )
	{
		auto lineLength = lineInput.length();

		auto stringLineLength = std::to_string( lineLength );

        if (lineLength > max_length){
            max_length = lineLength; 

        } else if (min_length == 0) {
            min_length = lineLength;

        } else if (lineLength < min_length){
            min_length = lineLength ;
        }

		auto outputLine = stringLineLength + "\t" + lineInput;

  		std::cout << outputLine << std::endl; 

		line_counter = line_counter + 1;
		sum_length = sum_length + lineLength;
	}

auto avg_length = sum_length / static_cast<float>(line_counter);

auto outputLine2 =  std::string("lines:")  + std::string("\t" ) + std::to_string( line_counter )
+ std::string("\t") +  std::string("total length:") + std::string("\t") + std::to_string( sum_length ) 
+ std::string("\t") + std::string("averge length:") + std::string("\t") + std::to_string( avg_length )
+ std::string("\t") +std::string("max:") + std::string("\t") + std::to_string( max_length)
+ std::string("\t") +std::string("min:") + std::string("\t") + std::to_string( min_length);

std::cout << outputLine2 << std::endl;

}
