#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std;

//function prototypes
float cf(float matind,float min,float ds);

int main(int argc, char* argv[]) {

if(argc<2) {
cout<<"Usage: ./main [Min x/y val][Max x/y val][x/y divisions (ds)][Circle Radius][No. Iterations]\n";
return 1;
}
  
float smin=strtod(argv[1],NULL);
float smax=strtod(argv[2],NULL);
float ds=strtod(argv[3],NULL);
float r=strtod(argv[4],NULL);
int iter=strtod(argv[5],NULL);
  
//get matrix size
int matsize = (((float)smax-smin)/ds) - fmod((smax-smin)/ds,1);  

//get mindpoint of matrix for circle
float mid = (matsize/2.0) - (fmod(matsize,2.0));
float vals[matsize][matsize][2];
  
int row,column,i;
  
//generate initial matrix
for(row=0;row<matsize;row++) {
  for(column=0;column<matsize;column++) {
    if(column==0) {
      vals[row][column][0]=vals[row][column][1]=10;
      }
      else if(column==matsize-1) {
	vals[row][column][0]=vals[row][column][1]=5;
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

//run algorithm to get average of values
for(i=0;i<iter;i++) {
  for(row=0;row<matsize;row++) {
    for(column=1;column<matsize-1;column++) {
      if(row==0) {
	vals[row][column][-(i%2)+1] = (vals[row][column+1][(i%2)]+vals[row][column-1][(i%2)]+vals[row+1][column][(i%2)])/3.00;
      }
      else if(row==matsize-1) {
	vals[row][column][-(i%2)+1] = (vals[row][column+1][(i%2)]+vals[row][column-1][(i%2)]+vals[row-1][column][(i%2)])/3.00;
      }
      else if( (pow((cf(row,smin,ds)-cf(mid,smin,ds)),2.0) + pow((cf(column,smin,ds)-cf(mid,smin,ds)),2.0)) < pow(r,2.0) ) {
	vals[row][column][-(i%2)+1]=0;
      }
      else {
	vals[row][column][-(i%2)+1] = 0.25*(vals[row+1][column][(i%2)]+vals[row-1][column][(i%2)]+vals[row][column+1][(i%2)]+vals[row][column-1][(i%2)]);
      }		
    }
  }
}
  
datafile.open("the_datafile.dat");

for(row=0;row<matsize;row++) {
  for(column=0;column<matsize;column++) {
    datafile<<row<<" "<<column<<" "<<vals[row][column][((i%2)==0)?0:1]<<"\n";
    //cout<<vals[row][column][((i%2)==0)?0:1]<<" ";
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

