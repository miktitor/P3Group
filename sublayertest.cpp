#include "sublayer.h"
#include <iostream>

int main()
{
  using namespace std;
  cout << "We have a top-layer matrix that looks like this:" << endl;
  cout << "0 0 0" << endl;
  cout << "0 6 0" << endl;
  cout << "8 5 4" << endl;
  cout << "0 2 0" << endl;
  cout << "We want to create a submatrix for the point with value 5." << endl;
  cout << "Defining a submatrix now..." << endl;
  Sublayer Test(2,3,5,6,2,8,4,4);
  cout << "The x-coordinate is " << Test.topx << " and should be 2." << endl;
  cout << "The y-coordiante is " << Test.topy << " and should be 3." << endl;
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
