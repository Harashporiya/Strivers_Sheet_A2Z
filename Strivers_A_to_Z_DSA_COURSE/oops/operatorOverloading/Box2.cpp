#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Box2
{
    int length, breadth, height;
    public:
Box2(){}
Box2(int l,int b,int h){
    length = l;
     breadth = b;
     height = h;
}
Box2(Box2 &o1){
  length = o1.length;
  breadth = o1.breadth;
  height = o1.height;
}

int getLength(){
   return length;
} 
int getBreadth(){
    return breadth;
} 
int getHeight(){
    return height;
}
long long CalculateVolume(){
    return length * breadth * height;
}

bool operator<(Box2& b){
    return (length < b.length && breadth < b.breadth && height < b.height);
}
friend ostream& operator<<(ostream& out, Box2& B);
};
ostream& operator<<(ostream& out, Box2& B){
    out<<B.getLength()<<" "<<B.getBreadth()<<" "<<B.getHeight();
    return out;
}
int main()
{
  int l,b,h;
  cin>>l>>b>>h;
  Box2 b1(l,b,h);
  cin>>l>>b>>h;
  Box2 b2(l,b,h);
  Box2 b3(b2);
  cout<<b1<<endl<<b2<<endl<<b3<<endl;
  cout<<(b1<b2);
 
  return 0;
}