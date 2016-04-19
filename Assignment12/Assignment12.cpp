#include <iostream>
#include "HashTable.h"

using namespace std;

void displayMenu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Insert movie" << endl;
  cout << "2. Delete movie" << endl;
  cout << "3. Find movie" << endl;
  cout << "4. Print table contents" << endl;
  cout << "5. Quit" << endl;
}

int main(){
  HashTable hashFour20;
  int choice=0;

  while(choice!=5){
    displayMenu();
    cin >> choice;
    string title;
    int year;
    cin.ignore();

    if(choice==1){
      cout << "Enter title:" << endl;
      getline(cin,title);
      cout << "Enter year:" << endl;
      cin >> year;
      hashFour20.insertMovie(title, year);
    }else if(choice==2){
      cout << "Enter title:" << endl;
      getline(cin,title);
      hashFour20.deleteMovie(title);
    }else if(choice==3){
      cout << "Enter title:" << endl;
      getline(cin,title);
      hashFour20.findMovie(title);
    }else if(choice==4){
      hashFour20.printTableContents();
    }else if(choice==5){
      cout << "Goodbye!" << endl;
    }
  }
}
