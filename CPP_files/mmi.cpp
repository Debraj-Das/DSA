#include<iostream>
#include<vector>
using namespace std;

//Euclid's Algorithm
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

// Extended Euclid's Algorithm ax + by = gcd(a,b)
vector<int> extendedGCD(int a,int b){

	if(b==0){
		//return the values of x and y 
		return {1,0,a};
	}
	vector<int> result = extendedGCD(b, a%b);

	// After recursive call is over
	int smallX = result[0];
	int smallY = result[1]; 
	int gcd  = result[2];

	int x = smallY;
	int y = smallX - (a/b)*smallY;

	return {x,y, gcd};
}
//Code for MMI
int modInverse(int a,int m){

	vector<int> result = extendedGCD(a, m);
	int x = result[0];
	int gcd = result[2];

	if(gcd!=1){
		cout<<"Multiplicative Modulo Inverse doesn't exist";
		return -1;
	}

	int ans = (x%m + m)%m; //x can be negative also, {1,2,3....m-1}
	return ans;
}




int main(){
	int a,m;
	cin>> a >> m; //relatively prime
	cout << modInverse(a,m) <<endl;

	/*int a,b;
	cin>>a>>b;

	// a x + b y = gcd (a,b);
	int x,y;
	vector<int> result = extendedGCD(a,b);
	cout<< result[0] <<" and "<<result[1] << " gcd " << result[2] << endl;

	cout <<"Algorithm Euclid's "<< gcd(a,b) <<endl; */

	return 0;
}