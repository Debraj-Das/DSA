#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student 
{
  private:
    int age ;
    string first_name ;
    string last_name ;
    int standard ;
  public :
    void set_age(int a)
    {
        age = a ;
        return ;
    }
    void set_first_name(string a)
    {
        first_name = a ;
        return ;
    }
    void set_last_name(string a)
    {
        last_name = a ;
        return ;
    }
    
    void set_standard(int a)
    {
        standard = a ;
        return ;
    }
    int get_age()
    {
        return age ;
    }
    string get_first_name()
    {
        return first_name ;
    }
    string get_last_name()
    {
        return last_name ;
    }
    int get_standard()
    {
        return standard ;
    }
    string to_string();
};

string Student::to_string()
{
    ostringstream str1  ;
    str1 << age;
    string val = str1.str();
    val += (','+first_name+' '+last_name+',') ;
    ostringstream str2 ;
    str2 <<standard ;
    val += str2.str() ;
    return val ;
}

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    cout<<endl;
    cout << st.get_age() << "\n";
    cout << st.get_first_name() << " " << st.get_last_name()  << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}