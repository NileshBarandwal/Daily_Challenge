/******************************************************************************

                             Prime Factor

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,a;
    cin>>i;
    vector<int> prime;
    a=i;
    for(int j=2;j<a+1;j++){
        while(i%j==0){
            i=i/j;
            if (find(prime.begin(), prime.end(), j) == prime.end()) {
                prime.push_back(j);
            }
            if(i%j==1){
                j++;
            }
        }
    }
    for(int i=0;i<prime.size();i++){
        cout<<prime[i];
        if(i<prime.size()-1){
            cout<<" ";
        }
    }
    return 0;
}
