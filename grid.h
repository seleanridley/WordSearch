#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

class grid
{
public:
  void readGrid(int gridpick);
  string fifteengrid[15][15];
  string thirtygrid[30][30];
  string fiftygrid[50][50];
  int gridrow;
  int gridcol;
private:
  void readInGrid(int gridpick);

};

void grid::readGrid(int gridpick)
{
  readInGrid(gridpick);
}

void grid::readInGrid(int gridpick)
{
  if(gridpick == 15) {
      string letters;
      ifstream infile;
      infile.open ("input15.txt");
      getline(infile, letters);
      while(!infile.eof()) // To get all the lines.
      {
          for(int i = 0; i < 15; i++)
          {
            for(int j = 0; j < 15; j++){
                infile >> fifteengrid[i][j]; // Saves the line in words.
            }
          }
      }
      infile.close();

      for(int i = 0; i < 15; i++)
      {
        for(int j = 0; j < 15; j++){
          cout<<fifteengrid[i][j]<<" ";
        }
        cout<<endl;
      }
  }
  if(gridpick == 30) {
      string letters;
      ifstream infile;
      infile.open ("input30.txt");
      getline(infile, letters);
      while(!infile.eof()) // To get all the lines.
      {
          for(int i = 0; i < 30; i++)
          {
            for(int j = 0; j < 30; j++){
                infile >> thirtygrid[i][j]; // Saves the line in words.
            }
          }
      }
      infile.close();

      for(int i = 0; i < 30; i++)
      {
        for(int j = 0; j < 30; j++){
          cout<<thirtygrid[i][j]<<" ";
        }
        cout<<endl;
      }
  }
  if(gridpick == 50) {
      string letters;
      ifstream infile;
      infile.open ("input50.txt");
      getline(infile, letters);
      while(!infile.eof()) // To get all the lines.
      {
          for(int i = 0; i < 50; i++)
          {
            for(int j = 0; j < 50; j++){
                infile >> fiftygrid[i][j]; // Saves the line in words.
            }
          }
      }
      infile.close();

      for(int i = 0; i < 50; i++)
      {
        for(int j = 0; j < 50; j++){
          cout<<fiftygrid[i][j]<<" ";
        }
        cout<<endl;
      }
  }

}
