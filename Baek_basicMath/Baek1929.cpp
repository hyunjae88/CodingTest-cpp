#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

#define MAX_INPUT 1000000

using namespace std;

void makePrimeNumberVector(vector<bool>& primeSet, int& nEnd)
{
    primeSet.assign(nEnd+1, true);
    primeSet[0] = primeSet[1] = false;
    
    for(int i = 2 ; i <= sqrt(nEnd) ; ++i)
    {
       if(primeSet.at(i) == true)
       {
            for(int j = i*2 ; j <= nEnd ; j+=i)
            {
                primeSet[j] = false;
            }
       }
    }      
   
}

void makePrimeNumberArr(bool& primeSet, int& nEnd)
{
    


}

int main()
{
   auto nStart = 0;
   auto nEnd   = 0;
   auto nMax   = MAX_INPUT;
    
   cin>> nStart >> nEnd;
   auto pPrimeSet = make_unique<bool[]>(nEnd+1);
  
   for(int i = 0 ; i <= nEnd ; ++i)
   {
       pPrimeSet[i] = true;
   }

    pPrimeSet[0] = false;
    pPrimeSet[1] = false;

    for(int i = 2 ; i <= sqrt(nEnd) ; ++i)
    {
       if(pPrimeSet[i] == true)
       {
            for(int j = i*2 ; j <= nEnd ; j+=i)
            {
                pPrimeSet[j] = false;
            }
       }
    }  
    
   for( auto i = nStart; i <= nEnd; ++i)
   {
      if(pPrimeSet[i])
      {
          cout<< i << "\n";
      }
   }
    
    return 0;
}
    
    