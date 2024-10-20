
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
void passwordMatch(string name, string password){
    try{
        int strLength=0;
        for(int i=0;password[i]!='\0';i++){
           strLength++;
        }

        if(strLength<6){
            throw 's';
        }
          bool digit= false;
         for(int i=0;password[i]!='\0';i++){
            if(password[i]>='0' && password[i]<='9'){
                      digit = true;
                      break;
            }
        }
        if(!digit){
            throw 'd';
        }
        cout<<"Correct";
    }catch(char str){
        if(str == 's'){
            cout<<"Too short!";
        }else if(str=='d'){
            cout<<"No digit";
        }
    }
}
int main()
{
   string name;
   string password;
   cin>>name>>password;
   passwordMatch(name, password);
    return 0;
}
