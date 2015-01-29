#ifndef TIMER_FUNC
#define TIMER_FUNC

#include <ctime>
#include <iostream>

// A funtion that returns the number of seconds (to the nearest 0.01)
// a program has been running. If used with input argument '1',
// print this value to stdout.

double timer(int output = 0)
{
  double time = clock() / (double)CLOCKS_PER_SEC;

  if ( output == 1 )
    {
      using namespace std;
      cout << "Time elapsed: " << time << " seconds" << endl;
    }

  return time;
}

#endif
