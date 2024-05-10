#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a;
    cin>>a;
    vector<int> num(a);
    long long count=0;
    for(int i=0;i<a;i++){
        cin>>num[i];
    }
    for(int i=0;i<num.size();i++){
        for(int j=i+1;j<num.size();j++){
            count += num[i]*num[j];
        }
    }
    cout<<count;
    return 0;
}