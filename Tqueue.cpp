/*
File: Tqueue.cpp
Project: CMSC 202 Project 5 , Fall 2020
Author WEi zhang weng
Date: 11/18/2020
Section: 10
email: wweng2@umbc.edu

This file contain the function impemetation of the of the templated Tqueue class that allow to add and remove data. and allow the user to sort , display and return the size and check to see if it it is empty
*/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: Enqueue
  //Desc: Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At() 
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};

template <class T, int N> 
Tqueue<T,N>::Tqueue(){
  m_data = new T[N];// Creates a dynamically allocated array that is type T
  m_front = 0;
  m_back = 0;
}
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){
  int i;
  m_front = x.m_front;
  m_back = x.m_back;
  m_data = new T[N];// Create a new dynamically allocated array that is type T

  for(i = 0; i<m_back; i++){// Copy all of the data from the orginally object to the new one
    m_data[i] = x.m_data[i];
  }
}

template <class T, int N>

Tqueue<T,N>::~Tqueue(){
  delete []m_data;// delete the entire array to prevent memory issues
  m_data = nullptr;
  m_front = 0;
  m_back = 0;
}

template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){
  if (IsFull() == 0){// This will only add to the list when the list is not full
    m_data[m_back] = data;// Adds it to the array postion of the futherest one and then increase m_back
    m_back++;
  }
  else if (IsFull() == 1){
    cout<<"The queue is full , please make some same that try again"<<endl;
  }
}
template <class T, int N>
void Tqueue<T,N>::Dequeue(){
  int i;
  for (i = 0; i<m_back ; i++){
    m_data[i] = m_data[i + 1];// This will move everything up one and get rid of the data in the front
  }
  m_back --;
}

template <class T, int N>
void Tqueue<T,N>::Sort(){
  int  i ;
  int  a;
  T min;// Used for flipping values
  T temp;
  
   for(i = 0 ; i < m_back - 1; i++){
     for (a = i + 1 ; a < m_back; a++){
       if (*m_data[i] < *m_data[a]){// If the value of a is greater then i in the m_data postions, flip them
	min = m_data[a];
	temp = m_data[i];
	m_data[i] = min;// Flips m_data[i] to m_data[a]
	m_data[a] = temp;
      }
    }
   }
}
template <class T, int N>

int Tqueue<T,N>::IsEmpty(){
  int NotEmpty = 0;
  if (m_back == 0){// If m_back is 0 and such is empty return 1
    return 1;
  }
  else{
    return NotEmpty;// Won't return 0 so use a varible that has 0 and return 0
  }
}
template <class T, int N>

int Tqueue<T,N>::IsFull(){
  int Full = 1;
  int NotFull = 0;
  if(m_back > N){// If m_back is then greater N the maxium size then return Full, as m_back will be 3001 when when the m_data is full up to it's entire capcaity 
    return Full;
  }
  else{
    return NotFull;
  }
}
 
template <class T, int N>
int Tqueue<T,N>::Size(){
  int size;
  size = m_back - m_front;// Return the size as m_front will always be 0 and such the accurate size of element in m_data
  return size;
}

template <class T, int N>

Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){
  if (this != &y){
    delete []m_data;// Get rid of prexisting data in m_data to get new data
    m_front = y.m_front;
    m_back = y.m_back;
    
    int i;
    
    m_data = new T[N];
    
    for(i = 0;i<m_back;i++){// Copy all of the data from the orginal obejct to the new one
      m_data[i] = y.m_data[i];
    }

  }

  return *this;
  }
template <class T, int N>

T& Tqueue<T,N>::At(int x){
 
  return m_data[x];// Return the element at the postion X

  
}
  
template <class T, int N>
void Tqueue<T,N>::DisplayAll(){
  int i;
  
  for (i = 0; i < Size(); i++){// Display all of the values in m_data
    cout<<i + 1<<". "<<m_data[i]->GetTitle()<<" by "<<m_data[i]->GetArtist()<<" from "<< m_data[i]->GetYear()<<endl;
  }



}


#endif
