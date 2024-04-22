/******************************************************************************

Question 6: (8 marks)

You are to write a program which takes 2 complex numbers as input and prints the sum and multiplication of the 2 complex numbers.

INPUT FORMAT:

The first and second lines contain 2 integers (the real and imaginary parts) for each complex number involved.

OUTPUT FORMAT:

The complex numbers sum and product on separate lines in the form a+bi or a-bi (depending on whether the complex part is negative or not).

Sample input:
1 2
1 3

Sample output:
2+5i
-5+5i

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    
    cin>>a>>b>>c>>d;
    
    // (a + ib) (c + id) = (ac - bd) + i(ad + bc)
    
    cout<<a+c<<" + "<<b+d<<"i"<<endl;
    cout<<a*c-b*d<<" + "<<a*d+b*c<<"i";

    return 0;
}
