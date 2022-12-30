#include <iostream>

using namespace std;

class CWH
{
  string title;
  float rating;

public:
  CWH(string tl, float r)
  {
    title = tl;
    rating = r;
  }
  virtual void display()
  {
    cout << "The title is " << title << endl;
    cout << "The rating is " << rating << endl;
    return;
  }
};

class CWHVIDEO : public CWH
{
  double videolenth;

public:
  CWHVIDEO(double vl, string tl = "untitle video ", float r = 4.5) : CWH(tl, r)
  {
    videolenth = vl;
  }
  void display()
  {
    cout << "\nThe video realted data : " << endl;
    CWH::display();
    cout << "The length of video is " << videolenth << endl;
    return;
  }
};

class CWHTEXT : public CWH
{
  int words_number;

public:
  CWHTEXT(int wn, string tl = "untitle video ", float r = 4.5) : CWH(tl, r)
  {
    words_number = wn;
  }
  void display()
  {
    cout << "\nThe text realted data : " << endl;
    CWH::display();
    cout << "The number of words is " << words_number << endl;
    return;
  }
};

int main()
{
  double video_length = 45.26;
  string name = "Dash video";
  float rate = 4.9;
  int words = 4563;

  CWHVIDEO obj_video(video_length, name, rate);
  obj_video.display();
  name = "Dash text";
  CWHTEXT obj_text(words, name, rate);
  obj_text.display();

  CWH *ptr_obj[2];
  ptr_obj[0] = &obj_video;
  ptr_obj[1] = &obj_text;
  ptr_obj[0]->display();
  ptr_obj[1]->display();

  return 0;
}