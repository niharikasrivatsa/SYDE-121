/*
clang++ -std=c++20 -Wall -Werror -Wextra -Wpedantic -g3 /usr/share/syde121/lab5/splitstring.o /usr/share/syde121/lab5/stringfromstringvector.o -o q2 q2.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
//#include <cmath> // for isnan()

using namespace std;
typedef vector< string > stringvector;

vector <string> varWithoutValue;
auto SplitString( string s ) -> stringvector; 
auto StringFromStringVector( stringvector, map<string,float> &varibles) -> string; // function declaration

// Returns true if s is a number else false
bool isNumber(string s)
{
    for (unsigned long i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}
 

auto main() -> int
{
    map<string, float> varibles;
    string currentLine;

    while ( getline( cin, currentLine ) )
    {
        auto splitLine { SplitString( currentLine ) };
        string answer = StringFromStringVector( splitLine, varibles );
        if (answer != ""){
            cout << StringFromStringVector( splitLine, varibles ) << endl;
        }
    }
}

auto StringFromStringVector (stringvector strvect, map<string, float> &varibles) -> string 
{
    int size = strvect.size();

    try{
        if (strvect[0] == "declare"){
            try{
                if (size == 3)
                {
                    //when declare is used with var and its value 
                    string varName = strvect[1];
                    float varValue = std::stof(strvect[2]) ;
                    varibles.insert(make_pair(varName, varValue));
                    string returnStr = "";
                    return returnStr;
                } else {
                    throw 505;
                }      
            }
            catch(...){
                //when declare is used with only var name
                varWithoutValue.push_back(strvect[1]);
                string returnStr = "";
                return returnStr;
            }

        
        } else if(strvect[0] == "display") {
            if (size == 2) {
                auto varibleKey = strvect[1];
                auto it = varibles.find(varibleKey);

                if (it == varibles.end()){
                    //did not find variable value 
                    string returnStr = "Varible Name and Value Does not exist";
                    return returnStr;  
                } else {
                    //found variable value
                    string returnStr =  string(it->first) + string(" = ") + to_string(it->second);
                    return returnStr;
                }
            } else if (size == 1){

            }


        } else if((strvect[0] == "add") || (strvect[0] == "+") ){
            try{
                auto value1 {0};
                auto value2 {0};

                if (size == 4){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);

                    }else {
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }

                    auto result = value1 + value2;

                    string varName = strvect[3];
                    float varValue = result ;
                    varibles.insert(make_pair(varName, varValue));
                    string returnStr = "";
                    return returnStr;

                }else if (size == 3){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);
                    } else{
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }
                    auto result = value1 + value2;

                    string returnStr = to_string(result);
                    return returnStr;

                }else{
                    throw 505;
                }
            }
            catch (...){
                string returnStr = "Invalid Command Parameters";
                return returnStr;
            }

        }
        else if((strvect[0] == "subtract") || (strvect[0] == "-") ){
            try{
                auto value1 {0};
                auto value2 {0};

                if (size == 4){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);

                    }else {
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }

                    auto result = value1 - value2;

                    string varName = strvect[3];
                    float varValue = result ;
                    varibles.insert(make_pair(varName, varValue));
                    string returnStr = "";
                    return returnStr;

                }else if (size == 3){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);
                    } else{
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }
                    auto result = value1 - value2;

                    string returnStr = to_string(result);
                    return returnStr;

                }else{
                    throw 505;
                }
            }
            catch (...){
                string returnStr = "Invalid Command Parameters";
                return returnStr;
            }

        }
        else if((strvect[0] == "multiply") || (strvect[0] == "*") ){
            try{
                auto value1 {0};
                auto value2 {0};

                if (size == 4){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);

                    }else {
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }

                    auto result = value1 * value2;

                    string varName = strvect[3];
                    float varValue = result ;
                    varibles.insert(make_pair(varName, varValue));
                    string returnStr = "";
                    return returnStr;

                }else if (size == 3){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);
                    } else{
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }
                    auto result = value1 * value2;

                    string returnStr = to_string(result);
                    return returnStr;

                }else{
                    throw 505;
                }
            }
            catch (...){
                string returnStr = "Invalid Command Parameters";
                return returnStr;
            }

        }
        else if((strvect[0] == "divide") || (strvect[0] == "/") ){
            try{
                auto value1 {0};
                auto value2 {0};

                if (size == 4){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);

                    }else {
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }

                    auto result = value1 / value2;

                    string varName = strvect[3];
                    float varValue = result ;
                    varibles.insert(make_pair(varName, varValue));
                    string returnStr = "";
                    return returnStr;

                }else if (size == 3){
                    auto varible1Key = strvect[1];
                    auto it1 = varibles.find(varible1Key);
                    value1 = it1->second;

                    if(isNumber(strvect[2])){
                        value2 = stoi(strvect[2]);
                    } else{
                        auto varible2Key = strvect[2];
                        auto it2 = varibles.find(varible2Key);
                        value2 = it2->second;
                    }
                    auto result = value1 / value2;

                    string returnStr = to_string(result);
                    return returnStr;

                }else{
                    throw 505;
                }
            }
            catch (...){
                string returnStr = "Invalid Command Parameters";
                return returnStr;
            }

        }else {
            throw 505;
        }
            
    }
    catch(...){
        //when a invaild command is given 
        string returnStr = "Invalid Command";
        return returnStr;
    }

    string returnStr = "";
    return returnStr;

}
