#include <iostream>
#include <string>

using namespace std;

string replaceAll(string str, const string& from, const string& to) {
   if (from.empty() or from == to) {
      return str;
   }
   for (size_t i = 0; (i = str.find(from, i)) != string::npos;
        i += to.length()) {
      str.replace(i, from.length(), to);
   }
   return move(str);
}

int main() {
   string str = "Hello World! World is beautiful.";
   string from = "World";
   string to = "Universe";

   string result = replaceAll(str, from, to);
   cout << result;

   return 0;
}
