#include <iostream>
using namespace std;

int main()
{
    string s = "1101";
    int step = 0;
    while(s!="1"){
        if(s.back() == '0'){
            s.pop_back();
        }else{
            int i = s.size()-1;
            while(i>=0 && s[i] == '1'){
                s[i] = '0';
                i--;
            }
            if(i >= 0){
                s[i] = '1';
            }else{
                s = '1' + s;
            }
        }
        step++;
    }
    cout << step << endl;
    return 0;
}
