
#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here

    auto cmp = [](auto a,auto b)->bool{
        return a > b;
    };
    
    auto fruitLenCompare = [](string f1,string f2)->bool{
        return f1.length() < f2.length();
    };

   // cout<< cmp(200,100) <<endl;

    //cout<<"----------";
    vector<int> v = {100,2,3,10,12,13,15};
    vector<string> vs = {"appleeeee","mangoo","ban","guava"};

    sort(v.begin(), v.end(), cmp);
    sort(vs.begin(),vs.end(), fruitLenCompare);


    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
        cout<< *it <<" ";
    }

    // for each loop 
    for(auto ele : vs){
        cout << ele <<endl;
    }






	return 0;
}

