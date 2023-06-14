// Created by Debraj Das on 26/05/23.
// This code for printing the path of the file.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string s = argv[0] ;
    s = s.substr(0, s.find_last_of("\""));
    cout<<"Path :: "<<s<<'\n';  
    return 0;
}