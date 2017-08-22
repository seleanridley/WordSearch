#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include "heap.h"

using namespace std;


class dictionary
{
public:
    void readInDictionary();
    void SortWords();
    void Search(string checkword);
    void quickSort(vector<string> &A, int left, int right);
    int partition(vector<string> &A, int p, int r);
    void heapSort(int n);
    vector<string> dictionaryWords;
    vector<string> foundwords; //vector with all found words
    bool match(string firststring, string secondstring);
    friend ostream& operator<<(ostream& os, const dictionary& dict);



private:
    void selectionSort();
};

ostream& operator<<(ostream& os, const dictionary& dict) {
    //overloaded operator to print dictionary words
    int dictionarysize = dict.dictionaryWords.size();
    for(int i = 0; i < dictionarysize; i++) {
        os<< dict.dictionaryWords[i]<<endl;
    }
    return os;
}

void dictionary::readInDictionary()
{
    string words;
    ifstream infile;
    infile.open ("dictionary.txt");
    //after the words were sorted once, we made a new file with the sorted
    //words so we didn't need to sort them each time
    while(!infile.eof()) // To get all the lines.
    {
        infile >> words;
        dictionaryWords.push_back(words); //saves all words in vector
    }
    infile.close();
}

void dictionary::quickSort(vector<string> &A, int left, int right) {
    if(left < right) {
      int s;
      s = partition(A, left, right);
      quickSort(A, left, s);
      quickSort(A, s+1, right);
    }
}

int dictionary::partition(vector<string> &A, int p, int r) {
  string x = A[p];
  int i, returnvalue;
  i = p;
  for(int j = p+1; j < r; j++) {
    if(A[j] <= x) {
      i = i + 1;
      swap(A[i], A[j]);
    }
  }
  swap(A[i], A[p]);
  returnvalue = i;
  return returnvalue;
}

void dictionary::SortWords()
{
    selectionSort();
}

void dictionary::selectionSort()
{
    //sorts all the words in the dictionary in alphabetical order
    int i, j, first;
    string temp;
    int dictLength = dictionaryWords.size();
    for(i = 0; i < dictLength - 1; i++)
    {
        first = 0;
        for(j = dictLength - 1; j>=i; j--)
        {
            if(dictionaryWords[j] < dictionaryWords[first])
                first = j;
        }
        temp = dictionaryWords[first];
        dictionaryWords[first] = dictionaryWords[i];
        dictionaryWords[i] = temp;
    }
}

void dictionary::heapSort(int n)
{
    heap<int> heap;
    heap.heapsort(n);
}


    //below is the code for outputting the sorted words into it's own file
    /*int sizeofDict = dictionaryWords.size();
     for(int i = 0; i < sizeofDict; i++) {
     cout<<dictionaryWords[i]<<endl;
     }
     */
    /*
     ofstream fout;
     string fileName = "sorteddictionary.txt";
     fout.open(fileName.c_str());
     int sizeofDict = dictionaryWords.size();
     for(int i = 0; i < sizeofDict; i++) {
     fout << dictionaryWords[i];
     fout << endl;
     }
     fout.close();

     */


//this function checks the return of the match function and if true, adds found
//word to foundwords vector
void dictionary::Search(string checkword)
{

    int sizeofDict = dictionaryWords.size();
    for(int i = 0; i < sizeofDict; i++) {
        string finding = dictionaryWords[i]; //word we're trying to find
        int findingsize = finding.size();
        if(findingsize >= 5) { //skips words smaller than 5
            bool findmatch = match(checkword, finding);
            if(findmatch == true)
                foundwords.push_back(finding); //adds found word to vector
        }
    }
}

//this function searches for the dictionary word (second string) as a substring
//of the grabbed string (first string) which can be a row, column, or Diagonal
//of the grid. returns True if second string is substring of first string
bool dictionary::match(string firststring, string secondstring) {
    int secondsize = secondstring.size();
    int firstsize = firststring.size();
    if(secondsize > firstsize)
        return false;
    for (int i = 0; i < firstsize; i++){
        int j = 0;
        if(firststring[i] == secondstring[j]
           && firststring[i] != firststring[i+1]){
            while (firststring[i] == secondstring[j] && j < secondsize){
                j++;
                i++;
            }

            if (j == secondsize) {
                return true;
            }
        }
    }
    return false;
}
