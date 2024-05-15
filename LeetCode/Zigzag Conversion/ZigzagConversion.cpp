/******************************************************************************

                              Zigzag Conversion
                              
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Zigzag {
    public:
            string convert(string s, int numRows){
                if(numRows == 1) return s;
                
                vector<string> rows(min(numRows, int(s.length())));
                
                int currentRow=0;
                bool goingDown = false;
                
                for(char c : s){
                    rows[currentRow] += c;
                    if(currentRow == 0 || currentRow == numRows-1){
                        goingDown = !goingDown;
                    }
                    
                    currentRow += goingDown ? 1:-1;
                }
                
                string result;
                for(string& row: rows){
                    result += row;
                }
                return result;
            }  
};

int main()
{
    Zigzag sol;
    string s1, result;
    int k;
    cin>>s1;
    cin>>k;
    result = sol.convert(s1, k);
    cout<<result;
    
    return 0;
}
