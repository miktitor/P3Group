#ifndef SUBLAYER_CLASS
#define SUBLAYER_CLASS

// A class to contain a sublayer of our grid, for when we want to look at one
// point at a higher resolution.

class Sublayer
{
public:
  // The x co-ordinate of the top-layer point
  int topx;
  // The y co-ordinate of the top-layer point
  int topy;
  // The size of the submatrix (length along one side)
  int size;
  // The submatrix itself
  double** array;

  // The format is array[row][column]

  // The constructor function
  Sublayer(int, int, double, double, double, double, double, int);
};


// Constructor function to create the submatrix
// Takes as input the grid co-ordinates, the value of the point
// on the top layer, the values of the adjacent points,
// and grid size (number of points to a side)
  Sublayer::Sublayer(int xpoint, int ypoint, double self,
		     double above, double below, double left, double right,
		     int gridsize)
{
  using namespace std;

  // Convert arguments into struct values
  topx = xpoint;
  topy = ypoint;
  size = gridsize;

  // Create the submatrix
  // The compiler complains about variable-sized arrays,
  // and this is the workaround I found
  array = new double*[size];

  for (int r = 0; r < size; r++)
    {
      array[r] = new double[size];
    }

  // Define the submatrix's initial values

  // All non-edge values are set to the top-layer value
  for (int r = 1; r < (size - 1); r++)
    {
      for (int c = 1; c < (size - 1); c++)
	{
	  array[r][c] = self;
	}
    }

  // Edge values are then set to the values of the top-layer
  // adjacent points

  // Top row
  int r = 0;
  for ( int c = 1; c < size-1; c++ )
    {
      array[r][c] = above;
    }
  // Bottom row
  r = size - 1;
  for ( int c = 1; c < size-1; c++ )
    {
      array[r][c] = below;
    }
  // Left column
  int c = 0;
  for ( int r = 1; r < size-1; r++ )
    {
      array[r][c] = left;
    }
  // Right column
  c = size - 1;
  for ( int r = 1; r < size-1; r++ )
    {
      array[r][c] = right;
    }

  // Corners are the average of two top-layer points
  array[0][0] = ( above + left ) / 2.0;
  array[0][size-1] = ( above + right ) / 2.0;
  array[size-1][0] = ( below + left ) / 2.0;
  array[size-1][size-1] = ( below + right) / 2.0;

}


// Function to create a sublayer for a given point in the top layer
// Takes as input the x and y co-ordiantes, the array containing the top layer,
// and opltionally how many layers deep this is (for sublayers within sublayers)
// Returns a pointer to a matrix containing the data
// Function will break if used on top, bottom, leftmost or rightmost points
Sublayer* sublayer(int column, int row, double** toplayer, int size = 13)
{
  Sublayer Temporary(column, row, toplayer[row][column],
		     toplayer[row-1][column], toplayer[row+1][column],
		     toplayer[row][column-1], toplayer[row][column+1],
		     size);
  Sublayer *pointer = &Temporary;
  return pointer;
}

#endif
