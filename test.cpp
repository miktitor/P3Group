#include <iostream>
#include <stdlib.h>
#include <Eigen/Eigen>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	float smin=strtod(argv[1],NULL);
	float smax=strtod(argv[2],NULL);
	float ds=strtod(argv[3],NULL);
	float r=strtod(argv[4],NULL);
	int iter=strtod(argv[5],NULL);

	//get matrix size
	int matsize = (((float)smax-smin)/ds) - fmod((smax-smin)/ds,1);

	float vals[matsize][matsize][iter];

	int i,j,k;

	//generate initial matrix
	for(k=0;k<iter;k++)
	{
		for(i=0;i<matsize;i++)
		{
			for(j=0;j<matsize;j++)
			{
				if(i==0)
					vals[i][j][k]=1;
				else if(i==matsize-1)
					vals[i][j][k]=-1;
				else
				{
					vals[i][j][k]=0;
				}
			}
		}
	}

	//print matrix
	/*for(i=0;i<=matsize-1;i++)
	{
		for(j=0;j<=matsize-1;j++)
		{
			cout<<vals[i][j][0]<<" ";
		}
		cout<<"\n";
	}*/
	//run algorithm to get average of values
	for(k=1;k<iter;k++)
	{
		for(i=1;i<matsize-1;i++)
		{
			for(j=0;j<matsize;j++)
			{
				if(j==0)
				{
					vals[i][j][k] = (vals[i-1][j][k-1]+vals[i+1][j][k-1]+vals[i][j+1][k-1])/3.00;
				}
				else if(j==matsize)
				{
					vals[i][j][k] = (vals[i-1][j][k-1]+vals[i+1][j][k-1]+vals[i][j-1][k-1])/3.00;
				}
				else
				{
					vals[i][j][k] = 0.25*(vals[i+1][j][k-1]+vals[i-1][j][k-1]+vals[i][j+1][k-1]+vals[i][j-1][k-1]);
				}
			}
		}
	}

	for(i=0;i<matsize;i++)
	{
		for(j=0;j<matsize;j++)
		{
			cout<<vals[i][j][iter-2]<<" ";
		}
		cout<<"\n";
	}


	return 0;
}
