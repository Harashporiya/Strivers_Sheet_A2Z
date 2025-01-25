#include<bits/stdc++.h>
using namespace std;
class MyStack{
    int *arr;
    int top;
    int size;
    public:
    MyStack(){
        top=-1;
        size=1000;
        arr=new int[size];
    }
    bool isEmpty(){
      return top==-1;
    }
    bool isFull(){
        return top==size-1;
    }
    void push(int x){
        top+=1;
        arr[top]=x;
        size++;
    }
    int pop(){
        int n=arr[top];
        top--;
        return n;
    }
    int Top(){
        return arr[top];
    }
    int Size(){
        return top+1;
    }
    void diplay(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main(){
   MyStack s;
  s.push(6);
  s.push(3);
  s.push(7);
  s.diplay();
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
}