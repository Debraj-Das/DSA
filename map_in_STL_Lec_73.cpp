#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> marks;
    marks[90] = "debraj"; //* store in a arrage decreasing of  first data type.
    marks.insert({{96, "deb"}, {98, "raj"}});
    map<int, string>::iterator iter;
    for (iter = marks.begin(); iter != marks.end(); ++iter)
    {
        cout << "name of student " << iter->second << " and his marks is " << iter->first << endl;
    }
    return 0;
}