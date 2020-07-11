#include <iostream>

using namespace std;

int main(){    

    int sumam = 0;	// sum of all amicable numbers <= 10000 times 2
    // Loop through numbers 2 to 10000
    for (int i = 1; i < 10001; i++){
	
	int sumdiv = 0;		// sum of all the proper divisors of i
        // find proper divisors
	for (int j = 1; j < i; j++){
            if (i%j < 10e-8){sumdiv += j;}				
	}
        
	// find proper divisors for the sum
	int sumdiv2 = 0;	// sum of all the proper divisors of sumdiv
	if (sumdiv != i){
    	    for (int j = 1; j < sumdiv; j++){
                if (sumdiv%j < 10e-8){sumdiv2 += j;}				
    	    }
	}

	if (sumdiv2 == i){
	    cout << i << " and " << sumdiv << " are an amicable pair." << endl;
	    sumam += (sumdiv + i);
	}
    }
    // Divide sumam by 2 to get the answer because I'm too lazy to find the duplicate pairs
    cout << "The sum of the amicable pairs <= 10000 is: " << sumam/2 << endl;   
}
