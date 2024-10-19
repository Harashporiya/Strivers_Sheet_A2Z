#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void cq1(int n)
{
  try{
     if(n < 0){
        throw -1;
     }else if (n == 0){
        throw "ZERO";
     }else if(n > 0){
        throw 1.0;
     }
  }catch(int a){
        cout<<"NEGATIVE";
  }catch(char const *e){
      cout<<"ZERO";
  }catch(double a){
    cout<<"POSITIVE";
  }
}
int main()
{
  int num;
  cin>>num;
  cq1(num);
  return 0;
}