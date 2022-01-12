// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q2 q2.cpp

#include<string>
#include<iostream>

using namespace std;

string ReverseString( string line);


auto main() -> int
{
    string currentLine;

	while ( getline( cin, currentLine ) )
	{
        cout << currentLine << "\t" << ReverseString( currentLine ) << endl;
    }
}

string ReverseString(string line) {

    int len = line.length();
    int n = len - 1;

    for(int i = 0; i < (len/2); i++){
        std::swap(line[i],line[n]);
        n = n - 1;
    }
    return line;
}