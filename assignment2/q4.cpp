// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q4 q4.cpp

#include<string>
#include<iostream>

using namespace std;
auto  IsCharInString(string str, char chr) -> bool
{
    int len = str.length();
    for(int i = 0; i < len; i++ ){
        if (str[i] == chr){
            return 1;
        }
        if  ((len -1) == i){
            if (str[i] == chr){
                return 1;
            }else{
                return 0;
            }  
        }
    }
    return 0;
}

auto main() -> int
{
    int linesRead {0};
    string currentLine;
    string sourceString;
    char targetChar;

    cout << boolalpha;

	while ( getline( cin, currentLine ) )
	{
        linesRead += 1;
        if ( ( linesRead % 2 ) == 1 ) { sourceString = currentLine; }
        else
        {
            targetChar = currentLine[0];
            cout << sourceString << "\t" << targetChar << "\t" << IsCharInString( sourceString, targetChar ) << endl;
        }
    }
}