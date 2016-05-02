#include "rungeKutta.h"
//#include "heun.h"
#include <iostream>
#include <vector>


using namespace::std;

int main()
{
	double ans = 5;
	double y=0;
	double x=0;
	integrator(x,y,.000001,ans);
	cout << x << '\t' << y << '\t' << ans*ans+ans*ans*ans+ans*ans*ans*ans << endl;

	return 0;
}
