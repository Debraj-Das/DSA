#include <iostream>

using namespace std;

class CWH   // This class create for inheritance other
{
     protected :
     string title ;
     double rating ;
     public :
     CWH(string s , double r) 
     {
          title = s ;
          rating = r ;
     }
     virtual void display() {}
};

class CWHVideo : public CWH
{
     private :
     double CWHVideo_lenth ;
     public :
     CWHVideo(string s,double r,double CWHVideo_lenth) : CWH(s,r)
     {
          this->CWHVideo_lenth = CWHVideo_lenth ;
     }
     void display();
};

void CWHVideo ::display()
{
     cout<<"The title of CWH Video is "<<title<<endl
          <<"The rating of CWH Video is "<<rating<<endl
          <<"The Video length of CWH Video is "<<CWHVideo_lenth<<endl;
     return ;
}

class CWHText : public CWH
{
     private :
     int word ;
     public :
     CWHText(string s,double r,double w) : CWH(s,r)
     {
          word = w ;
     }
     void display()
     {
          cout<<"The title of CWH Text is "<<title<<endl
               <<"The rating of CWH Text is "<<rating<<endl
               <<"The CWH Text words number is "<<word<<endl;
          return ;
     }
};

int main()
{
     CWHVideo video_obj("virtual function",4.35,23.32);
     video_obj.display();
     cout<<endl;
     CWHText text_obj("virtual function text",4.12,234);
     text_obj.display();
     CWH *base_pointer ;
     cout<<endl ;
     base_pointer = &video_obj ;
     base_pointer->display();  //run CWHVideo class display function due to virtual keyword
     cout<<endl ;
     base_pointer = &text_obj ;
     base_pointer->display();  //run CWHText class display function due to virtual keyword
     return 0 ;
}
