/*


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector< string > stringvector;
typedef vector< float > floatvector;
typedef vector< floatvector > floatmatrix;
struct fillresult 
{ 
    int errorCode; 
    unsigned int line;
};

auto DisplayMatrix( floatmatrix, bool = false ) -> void;
auto SplitString( string s ) -> vector< string >;  

auto FillStructuredMatrix( floatmatrix & matrixToFill ) -> fillresult // Change this function to match the requirements
{
    struct fillresult result { .errorCode = 0, .line = 0 };
    int dim_row;
    int dim_col;

    try {
        // Error check for line 1 startrmatrix
        string currentLine;
        getline( cin, currentLine );

        if (currentLine != "startmatrix"){
            throw (1);
        } else  {
             // Get dimensions if it exists or just get row
            getline( cin, currentLine );
            vector<string> lineTwo = SplitString(currentLine);
            cout << lineTwo[0] << endl;
            dim_row = stoi(lineTwo[1]);
            dim_col = stoi(lineTwo[2]);

            for ( int i = 0; i < dim_row; i++ ){
                vector< float > currentRow;
                getline( cin, currentLine );

                vector <string> currentRowString = SplitString(currentLine);

                for ( int j = 0; j < dim_col; j++ ){
                    float currentValue = stof( currentRowString[j-1]);
                    currentRow.push_back( currentValue );
                    }
                matrixToFill.push_back( currentRow );
        }   

        } 
    }
    catch(int exp){
        fillresult result { 
            .errorCode = -1, 
            .line = static_cast<unsigned int>(exp) };  
            return result;  
    }

    return result;

}


auto main() -> int
{    
    floatmatrix newMatrix;
    auto fillResult { FillStructuredMatrix( newMatrix ) };
    if ( fillResult.errorCode )
    {
        cerr << "Error [" << fillResult.errorCode << 
            "] on line [" << fillResult.line << "]" << endl; // endl for the newline not to flush
    }
    else
    {
        DisplayMatrix( newMatrix );
    }
    return fillResult.errorCode; // pass the error code back to the shell
}
