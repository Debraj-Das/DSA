#include<iostream>
using namespace std;

//Brute Force O(N)
void factorise(int n){

	for(int i=2; i<=n; i++){
		if(n%i == 0){
			int cnt = 0;
			while(n%i == 0){
				cnt++;
				n = n/i;
			}

			cout<<i<<"^"<<cnt<<",";
		}
	}
}

//Optimised Approach
/*
Obs: Once N is reduced to a prime number, the 
only factor that number will be the number itself.

If a number doesn't have any factor till sqrt(n) 
then it is a prime number.
*/
// O(Sqrt(N))
void factoriseOpt(int n){

	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			int cnt = 0;
			while(n%i == 0){
				cnt++;
				n = n/i;
			}

			cout<<i<<"^"<<cnt<<",";
		}
	}

	//Out of the loop
	if(n!=1){
		cout << n <<"^"<< 1 <<endl;
	}
}


int main(){

	int n;
	cin>>n;

	factoriseOpt(n);

	return 0;
}