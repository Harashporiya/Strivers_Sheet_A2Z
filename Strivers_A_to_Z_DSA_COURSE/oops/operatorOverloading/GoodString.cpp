#include<iostream>

using namespace std;

int main()
{
  string str;
  int n;
  cin>>n;
  cin.ignore();
  getline(cin, str);
  for(int i=0;i<n && str[i]!='\0';i++){
    cout<<str[i];
  }
    return 0;
}
