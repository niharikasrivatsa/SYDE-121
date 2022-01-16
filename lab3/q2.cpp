// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

auto main() -> int
{
    std::string lineInput;

    auto sum {0};
    std::vector<int> valuelist = {};

    while ( getline( std::cin, lineInput ) )
	{
        if(!lineInput.empty()){
            auto value = std::stoi(lineInput);
            sum = sum + value;
            valuelist.push_back(value);
        }
    }
    
    int size = valuelist.size();

    if (size < 2){
        std::cout << "Error: Not enough intergers" << std::endl; 
    } else {
        auto average = sum/size;
        auto sqaured_sum {0};

        std::string lineInput2;

       for(int i =0; i < size; i++){
            sqaured_sum = ((valuelist[i] - average)*(valuelist[i] - average)) + sqaured_sum; 
        }

        auto sd = std::sqrt(static_cast<float>(sqaured_sum) / size );

        std::cout << std::string("Standard Devation:" ) + std::string("\t") + std::to_string (sd) << std::endl; 
    
    }
}