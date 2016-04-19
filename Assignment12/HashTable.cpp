#include <iostream>
#include <vector>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(){
  for(int i=0; i<10;i++){
    hashTable[i]=NULL;
  }
}

HashTable::~HashTable(){
  //dtor
}

void HashTable::printTableContents(){
  HashElem *temp = new HashElem;
  int emptyFlag=0;
  for(int i=0; i<10; i++){
    if(hashTable[i]!=NULL){
      emptyFlag=1;
      temp = hashTable[i];
      while(temp!=NULL){
        cout << temp->title << ":" << temp->year << endl;
        temp=temp->next;
      }
    }
  }
  if(emptyFlag==0){
    cout << "empty" << endl;
  }
}

void HashTable::insertMovie(string name, int year){
  HashElem *newMovie = new HashElem(name, year);
  HashElem *temp = new HashElem;
  int index = hashSum(name, tableSize);
  if(hashTable[index]==NULL){
    hashTable[index] = newMovie;
  }else{
    temp = hashTable[index];
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next = newMovie;
    newMovie->previous = temp;
  }
}

void HashTable::deleteMovie(string name){
  int index = hashSum(name, tableSize);
  HashElem *temp = new HashElem;
  temp = hashTable[index];
  if(hashTable[index]->title==name){
    hashTable[index] = temp->next;
    delete temp;
  }else{
    while(temp!=NULL){
      if(temp->title==name){
        if(temp->next==NULL){
          temp->previous->next=NULL;
          delete temp;
        }else{
          temp->next->previous=temp->previous;
          temp->previous->next=temp->next;
          delete temp;
        }
        break;
      }else{
        temp=temp->next;
      }
    }
  }
}

void HashTable::findMovie(string name){
  int index = hashSum(name, tableSize);
  HashElem *temp = new HashElem;
  temp = hashTable[index];
  if(hashTable[index]->title==name){
    cout << index << ":" << temp->title << ":" << temp->year << endl;
  }else if(temp==NULL){
    cout << "not found" << endl;
  }else{
    while(temp!=NULL){
      if(temp->title==name){
        cout << index << ":" << temp->title << ":" << temp->year << endl;
        break;
      }else{
        temp=temp->next;
        if(temp==NULL){
          cout << "not found" << endl;
        }
      }
    }
  }
}

int HashTable::hashSum(string x, int s){
  int sum = 0;
  for(int i=0; i < x.length(); i++){
    sum+=x[i];
  }
  sum%=s;
  return sum;
}
