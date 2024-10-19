#include<iostream>
using namespace std;
class Box{
    int a,b;
    public:
    Box(){};
    Box(int x, int y){
        a = x;
        b = y;
    }
   Box operator+(Box o){
    Box res;
    res.a = a + o.a ;
     res.b = b + o.b;
     return res;
   }
   void display(){
    cout<<a<<" "<<b;
   }
};
int main(){
  Box o1(2,3), o2(4,5), o3(6,7), o4(8,9), o5(10,11);
  Box o = o1+o2+o3+o4+o5;
  o.display();
}