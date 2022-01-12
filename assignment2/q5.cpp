// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q5 q5.cpp

#include<string>
#include<iostream>

using namespace std;

auto IsStringInString (string str1, string str2) -> bool
{
    int len1 = str1.length();
    int len2 = str2.length();
    bool matched;

    for(int i = 0; i < len1; i++ ){
        if (str1[i] == str2[0]){
            matched = true;
            int match_counter = 1;
            while (matched == true){
                if (str1[i + match_counter] == str2[match_counter]){
                    matched = true;
                    match_counter++;
                }else{
                    matched = false;
                }
                if (len2 <= match_counter){
                    return 1;
                }
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
    string targetString;

    cout << boolalpha;

	while ( getline( cin, currentLine ) )
	{
        linesRead += 1;
        if ( ( linesRead % 2 ) == 1 ) { sourceString = currentLine; }
        else
        {
            targetString = currentLine;
            cout << sourceString << "\t" << targetString << "\t" << IsStringInString( sourceString, targetString ) << endl;
        }
    }
}