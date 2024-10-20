#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed

using namespace std;
class Person
{
  public:
  string name ,color;
  int number_of_eyes,debut_year;
};
class Actor : public Person
{
    string name ,color;
  int number_of_eyes,debut_year;
  public:
  Actor(string n, string c, int e, int l){
  name = n;
  color = c;
  number_of_eyes = e;
  debut_year = l;
  }
  string toString(){
  string str = "The person " + name + " is an Actor. He is " + color + " in color, has " + to_string(number_of_eyes) +  " eyes and debut in " + to_string(debut_year) + "\n";
  return str;
  }
};
class Actress : public Person
{
  string name ,color;
  int number_of_eyes,debut_year;
  public:
  Actress(string n, string c, int e, int l){
  name = n;
  color = c;
  number_of_eyes = e;
  debut_year = l;
  }
  string toString(){
  string str = "The person " + name + " is an Actress. She is " + color + " in color, has " + to_string(number_of_eyes) +  " eyes and debut in " + to_string(debut_year) + "\n";
  return str;
  }
};
int main()
{
	string c,n;
	int e;
	int l;
	cin>>n;
	cin>>c;
	cin>>e;
	cin>>l;
	
	Actor m(n,c,e,l);
//	cin.ignore();
	cin>>n;
	cin>>c;
	cin>>e;
	cin>>l;
	Actress j(n,c,e,l);
	cout<<m.toString();
	cout<<j.toString();
	return 0;
}