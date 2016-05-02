#include "euler.h"

#include <iostream>
#include <vector>


using namespace::std;

int main()
{
	double ans = 10000;
	double y=0;
	double x=0;
	integrator(x,y,100,ans);
	cout << x << '\t' << y << '\t' << ans*ans << endl;

	return 0;
}
