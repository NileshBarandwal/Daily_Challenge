/******************************************************************************

Sample input: 1 20000
Sample output: 16800

Sample input: 3 20000
Sample output: 14892.6

*******************************************************************************/

#include <iostream>
using namespace std;

// priceDrop = (current_price - 12000) 2 / 20000

int price(int years, int current_price) {
    int priceDrop=0;
    if(years>0){
        priceDrop = (current_price - 12000)*(current_price - 12000) / 20000;
        //cout<<"PD ="<<priceDrop<<endl;
        current_price-=priceDrop;
        //cout<<"cp ="<<current_price<<endl;
        years--;
        //cout<<"year ="<<years<<endl;
    }else{
        return current_price;
    }
    return price(years, current_price);
}

int main() {
    int years, current_price;
    cin >> years >> current_price;
    cout << price(years, current_price) << endl;
    return 0;
}
