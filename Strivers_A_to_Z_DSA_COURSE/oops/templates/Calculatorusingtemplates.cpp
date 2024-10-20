#include <iostream>
using namespace std;
template <class T>
class Calculate
{
    T a,  b;
    public:
    Calculate(T x, T y){
        a = x;
        b = y;
    }
    T add(){
        return a+b;
    }
    T sub(){
        return a-b;
    }
    T mul(){
        return a*b;
    }
    T div(){
        return a/b;
    }
  
};
int main()
{
  int a,b;
  float c,d;
  cin>>a>>b;
  cin>>c>>d;
  Calculate<int> intCalc(a, b);
  Calculate<float> floatCalc(c, d);
  cout<<intCalc.add()<<endl;
  cout<<intCalc.sub()<<endl;
  cout<<intCalc.mul()<<endl;
  cout<<intCalc.div()<<endl;
  cout<<floatCalc.add()<<endl;
  cout<<floatCalc.sub()<<endl;
  cout<<floatCalc.mul()<<endl;
  cout<<floatCalc.div()<<endl;
  return 0;
}