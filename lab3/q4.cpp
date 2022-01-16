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

    //Making random list of floating points
    for(int i = 0; i < 25 ; i++){
        float value = static_cast <float> (rand()) /  (static_cast <float> (RAND_MAX/100.0));
        data_list.push_back(value);
    }

    //Making matrix from that data list
    for(int j = 0; j < row_count; j++){

        std::vector<float> rowList = {};

        for (int k = 0; k < col_count; k++){
            rowList.push_back(data_list[row_count * j + k]);
        }

        matrix.push_back(rowList);
    }

    //Printing matrix by row and column
    std::cout << std::string("Matrix:" ) << std::endl; 
    for (int row = 0; row < row_count; row ++){
        for (int col = 0 ; col < col_count; col++ ){
        std::cout << std::to_string(matrix[row][col]) << std::string(" "); 
        }
        std::cout << std::string("") << std::endl; 
    }
       

}