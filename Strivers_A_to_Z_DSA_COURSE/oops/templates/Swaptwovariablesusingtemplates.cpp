#include <iostream>
using namespace std;
template<typename T>
void Swap(T &a, T &b){
    T temp = a;
    a=b;
    b = temp;
}
int main()
{
  int i1, i2;
  float f1, f2;
  char c1, c2;
  cin>>i1>>i2;
  cin>>f1>>f2;
  cin>>c1>>c2;
  cout <<i1 << " " << i2<<endl;
  cout <<f1 << " " << f2<<endl;
  cout <<c1 << " " << c2<<endl;
  Swap(i1, i2);	  Swap(f1, f2);	  Swap(c1, c2);
  cout <<i1 << " " << i2<<endl;
  cout <<f1 << " " << f2<<endl;
  cout <<c1 << " " << c2<<endl;
  return 0;
}