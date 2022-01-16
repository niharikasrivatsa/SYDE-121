#include <iostream>
#include <string>
#include <vector>
using namespace std;


auto main() -> int
{
    auto row_count = 5;
    auto col_count = 5;

    std::vector<vector<float>> matrix = {};

    std::vector<float> data_list = {};

    //Create a list of random floating points
    for(int i = 0; i < 25 ; i++){
        float value = static_cast <float> (rand()) /  (static_cast <float> (RAND_MAX/100.0));
        data_list.push_back(value);
    }

    //Create matrix with the floating points
    for(int j = 0; j < row_count; j++){

        std::vector<float> rowList = {};

        for (int k = 0; k < col_count; k++){
            rowList.push_back(data_list[row_count * j + k]);
        }

        matrix.push_back(rowList);
    }


    //Accessing Elements of Matrix
    auto target_output = std::string("Matrix: [2][4] =") + std::to_string(matrix[2][4]) + ;
    std::cout << target_output << std::endl;

}

