#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
class Complex
{
  private:
   int real, imag;
  public:
   Complex(int r=0, int i=0)
   {
     real = r;
     imag = i;
   }

   Complex operator +(Complex D3){
      Complex res;
      res.real = real + D3.real;
      res.imag = imag + D3.imag;
      return res;
   }
     Complex operator -(Complex D4){
      Complex res;
      res.real = real - D4.real;
      res.imag = imag - D4.imag;
      return res;
   }
  void display(){
    cout<<real<<" + "<<imag<<"i";
  }
};
int main()
{
  int r,i;
  cin>>r>>i;
  Complex D1(r,i);
  cin>>r>>i;
  Complex D2(r,i);
  Complex D3,D4;
  D3=D1+D2;
  D4=D1-D2;
  D3.display();
  cout<<endl;
  D4.display();
  return 0;
}