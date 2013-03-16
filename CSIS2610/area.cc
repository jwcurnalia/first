#include <iostream>

using namespace std;

struct Point {
  int x,y;
};

Point pointList[] = {
{3,4},
{1,7},
{6,3},
{8,8},
{9,0},
{5,2},
{4,1},
{2,2},
{1,6}
};

int nPoints = 9;

int main(void) {
  int i,area=0;

  for (i=0;i<nPoints;i++)
    area = area + pointList[i].x * pointList[(i+1)%nPoints].y -
                  pointList[(i+1)%nPoints].x * pointList[i].y;

  if (area < 0)
    area = -area;

  cout << "The area is " << (area/2.0) << endl;

  return 0;
}
