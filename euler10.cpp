#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

bool isprime(int n);

int main(){
   clock_t ck0 = clock();
   const int limit = 5000000;
   const int mxdgs = 3500;   

   int dgs[mxdgs];
   dgs[0] = 2;
   for (int i = 1; i < mxdgs; i++) dgs[i] = 0;
   for (int k = 3; k <= limit; k += 2){
       if (isprime(k)) {
           int cary = 0;
           dgs[0] = dgs[0] + k;                      
           cary = dgs[0]/10;
           dgs[0] -= 10*cary;
           int j = 1;               
           while (cary > 0){
               dgs[j] = dgs[j] + cary;                            
               cary = dgs[j]/10;
               dgs[j] -= 10*cary;
               j++;
           } 
       } 
   }   

   // counting number of digits in the sum
   int count = mxdgs - 1;
   while(!dgs[count]) count--;
   

   // priniting sum: lowest digit dgs[count] first, 
   // highest digit dgs[0] last.  
   cout << "There are " << count + 1 << " digits in the sum of primes up to "
        << limit << ". They are:\n";
   
   clock_t ck1 = clock();
    
   for (int i = count; i >= 0; i--) cout << dgs[i];
   cout << '\n';
   cout << "Was found in " << double(ck1-ck0)/CLOCKS_PER_SEC << " seconds. \n";

   return 0;
}


bool isprime(int n){

   if (n ==1 ){
       return 0;
   }
   else if (n < 4){
       return 1;
   }
   else if (n%2 == 0) {
       return 0;
   }
   else if (n < 9){
       return 1;
   }
   else if (n%3 == 0){
      return 0;    
   }
   else{
       int r = floor(sqrt((double)n));
       int f = 5;
       while (f <= r){
           if (n%f == 0) return 0;
           if (n%(f+2) == 0) return 0;
           f = f + 6;
       }
       return 1;     
   }

}