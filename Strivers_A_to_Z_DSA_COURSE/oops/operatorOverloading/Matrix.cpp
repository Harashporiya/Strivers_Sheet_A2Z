#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Matrix
{
	  int m,n,a[20][20];
  public:
    Matrix(int x,int y){
        m = x;
        n = y;
    };
    void  readmat(){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
    };
    Matrix operator +(Matrix a2){
        Matrix res(m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
           res.a[i][j] = a[i][j] + a2.a[i][j];
            }
        }
        return res;
    };
    void display(){
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
         cout<<a[i][j]<<" ";
            }
        }  
    };
};
int main()
{
  int m1,n1;
  cin>>m1>>n1;
  Matrix a(m1,n1),b(m1,n1),c(m1,n1);
  a.readmat();
  b.readmat();
  c = a + b;
  c.display();
  return 0;
}