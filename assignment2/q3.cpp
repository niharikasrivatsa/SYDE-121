// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q3 q3.cpp

#include<string>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

auto DisplayMatrix( vector< vector< float > > matrix, bool highlightUpperTriangle ) -> void
{
    int row_count = matrix.size();
    int col_count = matrix[0].size();
    std::cout  << std::setprecision(2);
    
    //if highlight is true
    if (highlightUpperTriangle == 1){
        for (int row = 0; row < row_count; row ++){
            for (int col = 0 ; col < col_count; col++ ){
                if (row > col){
                    std::cout << std::setw(6)  << (matrix[row][col]) << std::string("\t");
                } else {
                    std::cout << std::string("\033[1;34m") << std::setw(6) << (matrix[row][col]) << std::string("\033[0m") << std::string("\t");    
                }
            } 
            std::cout << std::string("") << std::endl; 
        }
    } else {
        for (int row = 0; row < row_count; row ++){
            for (int col = 0 ; col < col_count; col++ ){
                std::cout << std::setw(6) << (matrix[row][col]) << std::string("\t"); 
            }
            std::cout << std::string("") << std::endl; 
        }
    }
}

auto LoadMatrix() -> vector< vector< float > >
{
    int numnberOfRows;
    int numnberOfColumns;

    string currentLine;
    getline( cin, currentLine );
    numnberOfRows = stoi( currentLine );
    getline( cin, currentLine );
    numnberOfColumns = stoi( currentLine );

    vector< vector< float > > matrix;

    for ( int currentRowNumber = 0; currentRowNumber < numnberOfRows; currentRowNumber++ )
    {
        vector< float > currentRow;
        for ( int currentColumnNumber = 0; currentColumnNumber < numnberOfColumns; currentColumnNumber++ )
        {
            getline( cin, currentLine );
            float currentValue = stof( currentLine );
            currentRow.push_back( currentValue );
        }
        matrix.push_back( currentRow );
    }
    return matrix;
}

auto main() -> int
{
    cout << std::fixed;
    auto matrix = LoadMatrix();
    string currentLine;
    getline( cin, currentLine );
    auto highlightUpperTriangle = ( currentLine.length() != 0 );
    DisplayMatrix( matrix, highlightUpperTriangle );
}
