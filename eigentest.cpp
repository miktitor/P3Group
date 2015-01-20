#include <iostream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main()
{
  MatrixXd vals(10,10,2);
  vals(3,3,1) = 6;
  vals(6,6,2) = 5;

  cout<<va
