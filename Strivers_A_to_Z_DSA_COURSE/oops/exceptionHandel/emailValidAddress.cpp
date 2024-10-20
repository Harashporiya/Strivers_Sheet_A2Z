#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
void isvalidemail(string id)
{
    bool isvaild = false;
    bool dotVaild = false;
try{
      for(int i=0;id[i]!='\0';i++){
    if(id[i] == '@'){
        isvaild = true;
    }

    if(isvaild && id[i] == '.'){
        dotVaild = true;
    }

  }
  if(!isvaild || !dotVaild){
    throw 'n';
  }
  cout<<"vaild";
}catch(char e){
    cout<<"Invaild";
}
}
int main()
{
  string id;
  cin>>id;
  isvalidemail(id);
  return 0;
}