//Project 3a
//Assignment by Selean Ridley and Camille Cash

#include <iostream>
#include "dictionary.h"
#include "grid.h"
#include "heap.h"
#include <string>
#include <fstream>

using namespace std;

void findMatches(dictionary dict, grid grid);
void searchx(grid &grid);
void search(int pick, dictionary &dict, heap<int> &heap);
string GrabUpperLeftDiagonal(grid grid, int row, int col);
string GrabUpperRightDiagonal(grid grid, int row, int col);
string GrabHorizontal(grid grid, int row);
string GrabVertical(grid grid, int col);


int main()
{
    dictionary dict;
    grid grid;
    heap<int> heap;
    dict.readInDictionary(); //reads in words in dictionary
    // dict.SortWords(); //sorts dictionary words
    // dict.quickSort();
    heap.setDictionary();
    //heap.heapsort(dictionarysize);
    //cout<<"yo"<<endl;
    //cout<<dict; //calls overloaded operator
    int pick;
    while(pick != 1 && pick != 2 && pick != 3) {
      cout<<"Pick a algorithm: 1:quickSort 2:Heapsort 3: selectionSort"<<endl; //asks user for grid choice
      cin >> pick; //sets grid choice
    }
    search(pick, dict, heap);
    searchx(grid);
    findMatches(dict, grid);

    cout<<"Words have been found.\nCompleted."<<endl;
    cout<<"This is a test"<<endl;
}

void findMatches(dictionary dict, grid grid)
{
    int limit = grid.gridrow - 1;
    string upperleftcheck;
    for(int j = 4; j <= limit; j++) {
      /* First Half Left Diagonal Check */
      int i = limit;
      upperleftcheck = GrabUpperLeftDiagonal(grid, i, j);
      string temp = upperleftcheck;
      dict.Search(upperleftcheck);

      //to swap the word to check if it matches in other direction
      int x = temp.length();
      for (int s=0; s<x/2; s++) {
          swap(temp[s], temp[x-s-1]); }

      dict.Search(temp);
      }


      for(int i = limit; i>= 4; i--) {
        // Second Half Left Diagonal Check
        int j = limit;
        upperleftcheck = GrabUpperLeftDiagonal(grid, i, j);
        string temp = upperleftcheck;
        dict.Search(upperleftcheck);

        //to swap the word to check if it matches in other direction
        int x = temp.length();
        for (int s=0; s<x/2; s++) {
            swap(temp[s], temp[x-s-1]); }

        dict.Search(temp);
        }


      string upperrightcheck;
      for(int i = 4; i <= limit; i++) {
        //First Half Right Diagonal Check
        int j = 0;
        upperrightcheck = GrabUpperRightDiagonal(grid, i, j);
        string temp = upperrightcheck;
        dict.Search(upperrightcheck);

        //to swap the word to check if it matches in other direction
        int x = temp.length();
        for (int s=0; s<x/2; s++) {
            swap(temp[s], temp[x-s-1]); }

        dict.Search(temp);
       }


        for(int j = 0; j < limit - 4; j++) {
           //Second Half Right Diagonal Check
          int i = limit;
          string secondupperrightcheck;
          secondupperrightcheck = GrabUpperRightDiagonal(grid, i, j);
          string temp = secondupperrightcheck;
          dict.Search(secondupperrightcheck);

          //to swap the word to check if it matches in other direction
          int x = temp.length();
          for (int s=0; s<x/2; s++) {
              swap(temp[s], temp[x-s-1]); }

          dict.Search(temp);
          }

        string horizontalcheck;
        for(int i = 0; i <= limit; i++) {
          //Horizontal Check
          horizontalcheck = GrabHorizontal(grid, i);
          string temp = horizontalcheck;
          dict.Search(horizontalcheck);

          //to swap the word to check if it matches in other direction
          int x = temp.length();
          for (int s=0; s<x/2; s++) {
              swap(temp[s], temp[x-s-1]); }

          dict.Search(temp);
          }


         string verticalcheck;
         for(int i = 0; i <= limit; i++) {
           //Vertical Check
           verticalcheck = GrabVertical(grid, i);
           string temp = verticalcheck;
           dict.Search(verticalcheck);

           //to swap the word to check if it matches in other direction
           int x = temp.length();
           for (int s=0; s<x/2; s++) {
               swap(temp[s], temp[x-s-1]); }
            dict.Search(temp);
            }


        int foundwordsize = dict.foundwords.size();
        for(int z = 0; z < foundwordsize; z++) {
             cout<<"found: "<<dict.foundwords[z]<<endl;
        }



    dict.foundwords.clear();
}



string GrabUpperLeftDiagonal(grid grid, int row, int col) {
  //returns string of the left diagonal based on the position that
  //was passed in.
  string check;
  int j = col;
  for(int i = row - 1; i >= 0; i--) {
    if(i < 0 || j < 0)
      break;
    if(grid.gridrow == 15)
      check.append(grid.fifteengrid[i][j]);
    if(grid.gridrow == 30)
      check.append(grid.thirtygrid[i][j]);
    if(grid.gridrow == 50)
      check.append(grid.fiftygrid[i][j]);
    j--;
  }
  int x = check.size();
  for (int i=0; i<x/2; i++) {
      swap(check[i], check[x-i-1]); }
  return check;
}

string GrabUpperRightDiagonal(grid grid, int row, int col) {
  //returns string of the lright diagonal based on the position that
  //was passed in.
  string check;
  int j = col;
  int limit = grid.gridrow - 1;
  for(int i = row - 1; i >= 0; i--) {
    if(i > limit || j > limit )
      break;
    if(grid.gridrow == 15)
      check.append(grid.fifteengrid[i][j]);
    if(grid.gridrow == 30)
      check.append(grid.thirtygrid[i][j]);
    if(grid.gridrow == 50)
      check.append(grid.fiftygrid[i][j]);
  j++;
  }
  return check;
}


string GrabHorizontal(grid grid, int row) {
  //returns string of the horizontal row based on the position that
  //was passed in.
  string check;
  int i = row;
  int limit = grid.gridrow - 1;
  for(int j = 0; j <= limit; j++) {
    if(i > limit || j > limit)
      break;
    if(grid.gridrow == 15)
      check.append(grid.fifteengrid[i][j]);
    if(grid.gridrow == 30)
      check.append(grid.thirtygrid[i][j]);
    if(grid.gridrow == 50)
      check.append(grid.fiftygrid[i][j]);
  }
  return check;
}

string GrabVertical(grid grid, int col) {
  //returns string of the vertical column based on the position that
  //was passed in.
  string check;
  int j = col;
  int limit = grid.gridrow - 1;
  for(int i = 0; i <= limit; i++) {
    if(i > limit || j > limit)
      break;
    if(grid.gridrow == 15)
      check.append(grid.fifteengrid[i][j]);
    if(grid.gridrow == 30)
      check.append(grid.thirtygrid[i][j]);
    if(grid.gridrow == 50)
      check.append(grid.fiftygrid[i][j]);
  }
  return check;
}

void searchx(grid &grid) {
  int pick = 0;
  while(pick != 15 && pick != 30 && pick != 50) {
    cout<<"Pick a grid: 15 30 50"<<endl; //asks user for grid choice
    cin >> pick; //sets grid choice
  }
  grid.gridcol = pick; //set variable for the number of cols in grid
  grid.gridrow = pick; //set variable for the number of rows in grid
  grid.readGrid(pick); //passes in grid choice
}

void search(int pick, dictionary &dict, heap<int> &heap) {
  vector<string> dictionaryWords = dict.dictionaryWords;
  int dictionarysize = dict.dictionaryWords.size();
  if (pick == 1) {
    dict.quickSort(dict.dictionaryWords, 0, dictionarysize);
    cout<<dict;
    }
  if(pick == 2 )
    heap.heapsort(dictionarysize);
  if(pick == 3) {
    dict.SortWords();
    cout<<dict;
  }

}
