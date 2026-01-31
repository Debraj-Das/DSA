#include <bits/stdc++.h>
using namespace std;

void quit(string message, int exitCode) {
    cerr << message << endl;
    exit(exitCode);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: ./checker <input> <user_output> <answer>" << endl;
        return 1;
    }

    ifstream inf(argv[1]);
    ifstream ouf(argv[2]);
    ifstream ans(argv[3]);

    int n, m;
    if (!(inf >> n >> m)) quit("Failed to read n, m from input", 1);

    cerr << "Accepted!" << endl;
    return 0;
}