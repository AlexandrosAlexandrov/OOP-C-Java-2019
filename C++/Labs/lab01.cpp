#include <iostream>
#include <string>
#include<cmath>

using namespace std;


int ReturnOdd(int a){
	return a%2;
}

int ReturnPrime(int a){
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		return 0;
	}
	return 1;
}



int main(){
	int give;
	cin >> give;
	
	int* primes = nullptr;
	int primeCount = 0;
	
	int* primeodds = nullptr;
	int primeOddCount = 0;
	
	int* primeevens = nullptr;
	int primeEvenCount = 0;
	
	for (int i = 1; i <= give; i++){
		if (ReturnPrime(i) == 1)
		{
			primeCount++;
			
			if (ReturnOdd(i) == 1){
				primeOddCount ++;
			
			int* tempPrimeOdds = new int[primeCount];
			memcpy(tempPrimeOdds, primeodds, (primeOddCount - 1) * sizeof(int));
			delete[] primeodds;
			
			primeodds = tempPrimeOdds;
			primeodds[primeOddCount - 1] = i;	
			}
			else{
				
				primeEvenCount ++;
				
			int* tempPrimeEven = new int[primeCount];
			memcpy(tempPrimeEven, primeevens, (primeEvenCount - 1) * sizeof(int));
			delete[] primeevens;
			
			primeevens = tempPrimeEven;
			primeevens[primeEvenCount - 1] = i;
			}
				
			int* tempPrimes = new int[primeCount];
			memcpy(tempPrimes, primes, (primeCount - 1) * sizeof(int));
			delete[] primes;
			
			primes = tempPrimes;
			primes[primeCount - 1] = i;
		}
	}
	
	cout << endl << "Primes: " << endl;
	cout << "------------------------------------------" << endl;
	
	for (int i = 0; i < primeCount; i++)
	{
		cout << primes[i] << endl;
	}
	cout << endl << "Odds: " << endl; 
	cout << "------------------------------------------" << endl;
	 
	for (int i = 0; i < primeOddCount; i++)
	{
		cout << primeodds[i] << endl;
		
	}
	cout << endl <<"Evens: " << endl;
	cout << "------------------------------------------" << endl;
	
	for (int i = 0; i < primeEvenCount; i++)
	{
		cout << primeevens[i] << endl;
	}
	
	delete[] primes;
	delete[] primeodds;
	delete[] primeevens;
}
