#include "sublayer.h"
#include <iostream>

int main()
{
  using namespace std;
  cout << "We have a top-layer matrix that looks like this:" << endl;
  cout << "0 0 0 0" << endl;
  cout << "0 6 0 0" << endl;
  cout << "8 5 4 0" << endl;
  cout << "0 2 0 0" << endl;
  cout << "We want to create a submatrix for the point with value 5." << endl;
  cout << "Creating matrix..." << endl;
  
  double **matrix = new double*[4];

  for (int x = 0; x < 4; x++)
    {
      matrix[x] = new double[4];
    }

  for (int r = 0; r < 4; r++)
    {
      for (int c = 0; c < 4; c++)
	{
	  matrix[r][c] = 0;
	}
    }

  matrix[1][1] = 6;
  matrix[2][0] = 8;
  matrix[2][1] = 5;
  matrix[2][2] = 4;
  matrix[3][1] = 2;

  // The function takes the x coordinate, y coordinate, source matrix, and
  // side length of the output matrix as input, in that order
  cout << "Defining a submatrix now..." << endl;
  Sublayer Test = *sublayer(1, 2, matrix, 4);
  cout << "The x-coordinate is " << Test.topx << " and should be 1." << endl;
  cout << "The y-coordiante is " << Test.topy << " and should be 2." << endl;
  cout << "The matrix is:" << endl;
 
  for (int r = 0; r < 4; r++)
    {
      for (int c = 0; c < 4; c++)
	{
	  cout << Test.array[r][c] << " ";
	}
      cout << endl;
    }

  cout << "The matrix should be:" << endl;
  cout << "7 6 6 5" << endl;
  cout << "8 5 5 4" << endl;
  cout << "8 5 5 4" << endl;
  cout << "5 2 2 3" << endl;

  return 0;
}
