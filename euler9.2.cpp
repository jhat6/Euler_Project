#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

bool isprime(int n);

int main(){
   clock_t ck0 = clock();
   const int limit = 2000000;
   int count = 1;
   int candidate = 1;

   while (count < limit){
       candidate += 2;
       if (isprime(candidate)) count++;
   }
   clock_t ck1 = clock();
   cout << "The " << limit << "th prime is = " << candidate << endl;
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

