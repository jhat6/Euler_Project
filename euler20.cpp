#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{	
	int val = 100;  // factorial to calculate (val!)
	int len = 200;  // set array length
	int* num = new int [len];  // array to hold the factorial value

	// initialize the array
	for (int i = 0; i < len; i++){
	    num[i] = 0;
	}
	num[0] = 1;	

	int prod;
	int dig;
	for (int n = 2; n < val+1; n++){
            int cary = 0;
    	    for (int i = 0; i < len; i++){
	    	prod = n*num[i];		
	        prod = prod + cary;		
		dig = prod%10;			
	        cary = prod/10;	              
		num[i] = dig;		
            }
	}		

	// print answer and compute the sum of the digits in the factorial
	cout << val << "!" << "is equal to: " << endl;
	int sum = 0;
	for (int i = len-1; i >= 0; i--){
	    cout << num[i];
	    sum += num[i];
	}
	cout << endl << "the sum of the digits in " << val << "!" << "is equal to: " << endl;
	cout << sum << endl;
	//system("Pause");

	return 0;
}