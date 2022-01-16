#include <iostream>
#include <string>
#include <vector>
using namespace std;


auto main() -> int
{
    auto line_counter {0};
    auto elements {0};
    auto row_count{0};
    auto col_count{0};

    std::vector<vector<float>> matrix = {};
    std::vector<float> data_list = {};
    std::vector<int> target_rows = {};
    std::vector<int> target_col = {};

    std::string lineInput;

    while ( getline( std::cin, lineInput ) )
	{
         line_counter = line_counter + 1;

        if (line_counter == 1){
            row_count = std::stoi(lineInput);
         }
         else if (line_counter == 2){
            col_count = std::stoi(lineInput);
            elements = row_count * col_count;
         }
         else if (line_counter <= elements + 2){
            float value =  std::stof(lineInput);
            data_list.push_back(value);
         }
         else if(line_counter > elements + 2){
             if(!lineInput.empty()){

                 if((elements + 2) % 2 == 0){

                     if (line_counter % 2 != 0){
                        auto row_target = std::stoi(lineInput);
                        if ((row_target > row_count) || row_target < 0){
                            target_rows.push_back(-1);
                        } else {
                            target_rows.push_back(row_target);
                        }
                     } else {
                         auto col_target = std::stoi(lineInput);
                         if ((col_target > col_count) || col_target < 0){
                            target_col.push_back(-1);
                        } else {
                            target_col.push_back(col_target);
                        }
                     }
                 } else if ((elements + 2) % 2 != 0){

                     if (line_counter % 2 == 0){
                        auto row_target = std::stoi(lineInput);
                        if ((row_target > row_count) || row_target < 0){
                            target_rows.push_back(-1);
                        } else {
                            target_rows.push_back(row_target);
                        }
                     } else {
                         auto col_target = std::stoi(lineInput);
                         if ((col_target > col_count) || col_target < 0){
                            target_col.push_back(-1);
                        } else {
                            target_col.push_back(col_target);
                        }
                     }
                 }
             }
         }
    }

    //Making matrix with data list 
    if ((row_count - col_count == 1) || (col_count - row_count == 1)){
        for(int j = 0; j < row_count; j++){
            std::vector<float> rowList = {};
            for (int k = 0; k < col_count; k++){
                rowList.push_back(data_list[(row_count + 1) * j + k]);
            }
            matrix.push_back(rowList);
        }
    } else {
        for(int j = 0; j < row_count; j++){
            std::vector<float> rowList = {};
            for (int k = 0; k < col_count; k++){
                rowList.push_back(data_list[row_count * j + k]);
             }
             matrix.push_back(rowList);
        }
    }

    //Printing Matrix by row and coloumn
    std::cout << std::string("Matrix:" ) << std::endl; 
    for (int row = 0; row < row_count; row ++){
        for (int col = 0 ; col < col_count; col++ ){
            std::cout << std::to_string(matrix[row][col]) << std::string(" "); 
        }
        std::cout << std::string("") << std::endl; 
    }

    std::cout << std::string("\nTargets:" ) << std::endl; 
    for (int target = 0 ; target < target_rows.size(); target++){
        int row = target_rows[target];
        int col = target_col[target];

        if ((target_rows[target] == -1) || (target_col[target] == -1)){
             std::cout << std::string("Target") << std::to_string(target + 1) << std::string(": ERROR TARGET NOT IN MATRIX") << std::endl;
        } else {
            auto target_output =  std::string("Target ") + std::to_string(target + 1) + std::string(": Matrix: [") + std::to_string(row) + std::string("][") + std::to_string(col) + std::string("] =") + std::to_string(matrix[row - 1][col -  1]);
             std::cout << target_output << std::endl;
        }
    }

}