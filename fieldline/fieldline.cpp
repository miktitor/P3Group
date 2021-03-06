#include <iostream>
#include "fieldline.h"
#include <fstream>


using namespace std;

int fldline(int row,int col,double** matrix,float dx,float dy)
{
  int r;
  int c;

  ofstream field;
  field.open("field.dat");
  //Output coords and vals
  for(r=1;r<row-1;r++)
  {
    for(c=1;c<col-1;c++)
    {
      if(c%5==0 && r%5==0)
      {
	Fieldline Test = *fline(r,c,matrix,dx,dy);
	field<<Test.xcord<<" "<<Test.ycord<<" "<<Test.fieldvals[0]<<" "<<Test.fieldvals[1]<<"\n";
      }
    }
    field<<"\n";
  }
  field.close();
  
  return 0;

}
