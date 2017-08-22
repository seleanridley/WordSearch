#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "dictionary.h"
#include <math.h>


using namespace std;

template <class T>
class heap
{
public:
  heap() {};
  T setItem(T newItem);
  T getItem(int n);
  void maxheapify(int i, int n);
  void buildMaxHeap(int n);
  void setDictionary();
  vector<string> A;
  T left(int root);
  T right(int root);
  T parent(int child);
  void heapsort(int n);

private:
  T item;
};

template<class T>
T heap<T>::setItem(T newItem)
// setter for item in heap
{
    item = newItem;
    return item;
}

template<class T>
T heap<T>::getItem(int n)
// returns nth item in heap
{
  //  return item;
}

template<class T>
void heap<T>::setDictionary()
{
  string words;
  ifstream infile;
  infile.open ("dictionary.txt");
  //after the words were sorted once, we made a new file with the sorted
  //words so we didn't need to sort them each time
  while(!infile.eof()) // To get all the lines.
  {
      infile >> words;
      A.push_back(words); //saves all words in vector
  }
  infile.close();

}

template<class T>
void heap<T>::maxheapify(int i, int n)
{

  int l, r, largest;
  l = 2 * i;
  r = (2*i) + 1;
  if((l < n) && A[l] > A[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if((r < n) && (A[r] > A[largest]))
  {
    largest = r;
  }
  if(largest != i)
  {
    swap(A[i], A[largest]);
    maxheapify(largest, n);
  }
}

template<class T>
void heap<T>::buildMaxHeap(int n)
{
  // int heapsize = pow(2, A.size()+1) - 1;
  //int heapsize = A.size();
  for(int i = n/2; i >= 0; i --)
  {
    maxheapify(i, n);
  }
}


template<class T>
void heap<T>::heapsort(int n)
{
  cout<<n<<endl;
  buildMaxHeap(n);
  //int heapsize = pow(2, A.size()+1) - 1;
  for(int i = n - 1; i >= 0; i --)
  {
    swap(A[0], A[i]);
    maxheapify(0, i-1);
  }
  for(int f = 0; f < n; f++){
     cout<<A[f]<<endl;
   }

}
