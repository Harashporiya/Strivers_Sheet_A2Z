#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Distance
{
  private:
  double feet, inch;
  public:
  void readDistance(){
    cin>>feet>>inch;
  }
  Distance operator +(Distance D3){
    Distance res;
    res.feet = feet + D3.feet;
    res.inch = inch + D3.inch;
    if(res.inch >=12){
        res.feet +=int (res.inch / 12);
        res.inch = (int) res.inch %12;
    }
    return res;
  }
    Distance operator -(Distance D4){
    Distance res1;
    res1.feet = feet - D4.feet;
    res1.inch = inch - D4.inch;
    if(res1.inch <0 ){
        res1.feet -= 1;
        res1.inch += 12;
    }
    return res1;
  }
   
  void display(){
    int convertFeetCm = feet * 30;
    int inchConvertCm = inch * 2.5;
    cout<<convertFeetCm / 100<<"'"<<inchConvertCm/100<<endl;
  }
};
int main()
{
    Distance D1,D2,D3,D4;
    D1.readDistance();
    D2.readDistance();
    D3=D1+D2;
  	D4=D1-D2;
    D3.display();
    cout<<endl;
  	D4.display();
    return 0;
}