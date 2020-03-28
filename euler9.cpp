// solve a^2 + b^2 + c^2 and a+b+c = 1000

#include<iostream>
using namespace std;

int main(){
    double a, c, b = 0.0;
    double decpt = 1.0;  // decimal point 
    // while loop finds first integer a   	
    while (decpt > 10e-8) {
            b += 1;
	    a = (-1000*1000 + 2000*b)/(2*b-2000);  // eliminate c and solve for a
            decpt = a - (int) a;	// subtract integer portion from a    
    }	
    c = sqrt(a*a + b*b);  // find c
    cout << a << " , " << b << " , " << c << endl; 
    cout << "a+b+c = " << a+b+c << endl;
    cout << "abc =" << a*b*c << endl;
    return 0;
}