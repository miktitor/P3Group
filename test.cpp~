#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{

  if(argc<2)
  {
    cout<<"Usage: ./test [Min x/y val][Max x/y val][x/y divisions (ds)][Circle Radius][No. Iterations]\n";
    return 1;
  }
  
  float smin=strtod(argv[1],NULL);
  float smax=strtod(argv[2],NULL);
  float ds=strtod(argv[3],NULL);
  float r=strtod(argv[4],NULL);
  int iter=strtod(argv[5],NULL);
  
  //get matrix size
  int matsize = (((float)smax-smin)/ds) - fmod((smax-smin)/ds,1);
  
  //DEBUG: show matsize
  //cout<<matsize<<"\n";  

  //get mindpoint of matrix for circle
  float mid = (matsize/2.0) - (fmod(matsize,2.0));
  float vals[matsize][matsize][iter];
  
  int row,column,depth;
  
  //generate initial matrix
  for(depth=0;depth<iter;depth++)
    {
      for(row=0;row<matsize;row++)
	{
	  for(column=0;column<matsize;column++)
	    {
              if(pow((row-mid),2.0) < pow(r,2.0))
                vals[row][column][depth]=0;
              else
              {
	        if(row==0)
		  vals[row][column][depth]=1;
	        else if(row==matsize-1)
		  vals[row][column][depth]=-1;
	        else
		  {
		    vals[row][column][depth]=0;
		  }
	      }
	    }
    }
}
  
  //open file to write data to
  ofstream datafile;

  //run algorithm to get average of values
  for(depth=1;depth<iter;depth++)
    {
      for(row=1;row<matsize-1;row++)
	{
	  for(column=0;column<matsize;column++)
	    {
	      if(pow((row-mid+0.00),2.0)<pow(r+0.00,2.0) && pow((column-mid+0.00),2.0)<pow(r+0.00,2.0))
	      {
                  vals[row][column][depth]=0;
              }
	      else
              {
                if(column==0)
		  {
		    vals[row][column][depth] = (vals[row-1][column][depth-1]+vals[row+1][column][depth-1]+vals[row][column+1][depth-1])/3.00;
		  }  
	        else if(column==matsize)
		  {
		    vals[row][column][depth] = (vals[row-1][column][depth-1]+vals[row+1][column][depth-1]+vals[row][column-1][depth-1])/3.00;
		  }
	        else
		  {
		    vals[row][column][depth] = 0.25*(vals[row+1][column][depth-1]+vals[row-1][column][depth-1]+vals[row][column+1][depth-1]+vals[row][column-1][depth-1]);
		  }
               }
            }
	}
    }
  
  datafile.open("the_datafile.dat");
  for(column=0;column<matsize;column++)
    {
      for(row=0;row<matsize;row++)
	{
	  datafile<<row<<" "<<column<<" "<<vals[row][column][iter-2]<<"\n";
          cout<<vals[row][column][iter-2]<<" ";
	}
	cout<<"\n";
	datafile << "\n";
    }
  datafile.close(); 
   
  return 0;
}
