#include <iostream>

using namespace std ;

template <class Type>
class Vector
{
 Type *array ;
 int arr_size ;
 public:
  Vector(int m)
  {
     arr_size = m;
     array = new Type[arr_size];
  }
  void set_data()
  {
     for(int i=0 ; i<arr_size;++i)
     {
       cout<<"Enter "<<(i+1)<<"th member of array : ";
       cin>>array[i];
     }
     cout<<endl ;
     return ;
  }
  Type dot_product(Vector &vec2)
  {
     Type value = 0;
     for(int i=0 ;i<arr_size;++i)
     {
        value += (this->array[i]*vec2.array[i]);
     }
     return value ;
  }

};


int main()
 {
    Vector <int> myvector1(3) ,myvector2(3) ;
    myvector1.set_data();
    myvector2.set_data();
    cout<<"\n dot product of vectors is "<<myvector1.dot_product(myvector2) <<endl ;
  
  return 0;
 }