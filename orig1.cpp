#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include "sublayer.h"

using namespace std;

//function prototypes
float cf(float matind,float min,float ds);
float grad(float right,float left,float up,float down,float ds);

int main(int argc, char* argv[]) {

if(argc<6) {
cout<<"Usage: ./main [Min x/y val][Max x/y val][x/y divisions (ds)][Circle Radius][No. Iterations][Output type]\n";
return 1;
}
  
float smin=strtod(argv[1],NULL);
float smax=strtod(argv[2],NULL);
float ds=strtod(argv[3],NULL);
float r=strtod(argv[4],NULL);
int iter=strtod(argv[5],NULL);
int index=strtod(argv[6],NULL);
  
//get matrix size
int matsize = (((float)smax-smin)/ds) - fmod((smax-smin)/ds,1);  

//get mindpoint of matrix for circle
float mid = (matsize/2.0) - (fmod(matsize,2.0));
float vals[matsize][matsize][3]; //made 3 for array of grad values
  
int row,column,i;
  
//generate initial matrix
for(row=0;row<matsize;row++) {
  for(column=0;column<matsize;column++) {
    if(column==0) {
      vals[row][column][0]=vals[row][column][1]=1;
      }
      else if(column==matsize-1) {
	vals[row][column][0]=vals[row][column][1]=-1;
      }
      else if( (pow((cf(row,smin,ds)-cf(mid,smin,ds)),2.0) + pow((cf(column,smin,ds)-cf(mid,smin,ds)),2.0)) < pow(r,2.0) ) {
	vals[row][column][0]=vals[row][column][1]=0;
      }
      else {
	vals[row][column][0]=vals[row][column][1]=0;
      }
	
  }
}
  
//open file to write data to
ofstream datafile;

//define position values for ease of use
float up,down,left,right;

//run algorithm to get average of values
for(i=0;i<iter;i++) {
  for(row=0;row<matsize;row++) {
    for(column=1;column<matsize-1;column++) {
      //get position values for step
      up    = vals[row-1][column][i%2];
      down  = vals[row+1][column][i%2];
      left  = vals[row][column-1][i%2];
      right = vals[row][column+1][i%2];
      //do check on gradient to see how it's changing
      //if(row>0 && row<matsize-1){
	//vals[row][column][2] = grad(right,left,up,down,ds);
      //}
      if(row==0) {
	vals[row][column][-(i%2)+1] = (left+right+down)/3.00;
	vals[row][column][2] = grad(right,left,0,down,ds);
      }
      else if(row==matsize-1) {
	vals[row][column][-(i%2)+1] = (left+right+up)/3.00;
	vals[row][column][2] = grad(right,left,up,0,ds);
      }
      else if( (pow((cf(row,smin,ds)-cf(mid,smin,ds)),2.0) + pow((cf(column,smin,ds)-cf(mid,smin,ds)),2.0)) < pow(r,2.0) ) {
	vals[row][column][-(i%2)+1]=0;
	vals[row][column][2] = grad(right,left,up,down,ds);
      }
      else {
	vals[row][column][-(i%2)+1] = 0.25*(left+right+up+down);
	vals[row][column][2] = grad(right,left,up,down,ds);
      }		
    }
  }
}
  
datafile.open("the_datafile.dat");

for(row=0;row<matsize;row++) {
  for(column=0;column<matsize;column++) {
    if(index==0){
      //gradient test. see function 'grad' for more info.
      datafile<<cf(row,smin,ds)<<" "<<cf(column,smin,ds)<<" "<<vals[row][column][2]<<"\n";
    }
    else if(index==1){
      //actual values of potential (for plotting etc.)
      datafile<<row<<" "<<column<<" "<<vals[row][column][((i%2)==0)?0:1]<<"\n";
    }
    else if(index==2){
      //display values in terminal
      cout<<vals[row][column][((i%2)==0)?0:1]<<" ";
    }
  }
  //cout<<"\n";
  datafile<<"\n";
}


datafile.close(); 


return 0;

}

//CoordiFy converts the matrix location of a point into its physical coordinate
float cf(float matind,float min,float ds){
  //matind = index of value in array, min = min true coord value, ds = coord division
  return min + (ds*matind);
}

//Check on gradient. Returns a value based on 4 surrounding points (needs some tweaking in order to calibrate tolerance)
float grad(float right,float left,float up,float down,float ds){
  float result = pow(pow((right-left)/ds,2.00)+pow((down-up)/ds,2.00),0.50);
  
  /*for now, return result to see values
  if(result>100 || result<0.001){
    return 0;
  }
  else{
    return result;
  }*/

  if (result>0.25){
      return 1;
    }
    else{
      return 0;
    }
  
}
