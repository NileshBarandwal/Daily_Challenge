/******************************************************************************

                             Compare Two Strings character's

*******************************************************************************/

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    map<char, int> ch1;
    map<char, int> ch2;
    char stringA[100];
    char stringB[100];
    cin.getline(stringA, 100);
    cin.getline(stringB, 100);
    
    for(int i=0;i<strlen(stringA);i++){
        if(stringA[i] != ' '){
            if(ch1.find(stringA[i]) != ch1.end()){ // Char present in string
                ch1[stringA[i]]++;
            }else{
                ch1[stringA[i]]=1;
            }
        }
    }
    
    for(int i=0;i<strlen(stringB);i++){
        if(stringB[i] != ' '){
            if(ch2.find(stringB[i]) != ch2.end()){ // Char present in string
                ch2[stringB[i]]++;
            }else{
                ch2[stringB[i]]=1;
            }
        }
    }
    
    bool equal = ch1 == ch2;
    
    if(equal){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}
