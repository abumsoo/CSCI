#include <iostream>

using namespace std;

int main(){
  double dblDouble[20];
  for (int i;i<20;i++)
    dblDouble[i]=i;
  cout<<"Stuff to print"<<endl;
  for (int i;i<20;i++)
    cout<<dblDouble[i]<<endl;
  double total;
  for (int i;i<20;i++)
    total+=dblDouble[i];
  double average=total/20;
  cout<<"The average value of dblDoubles is: "<<average<<endl;
}
