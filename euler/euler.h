#ifndef GUARD_euler_h
#define GUARD_euler_h



void derivs(const double& x,const double& y,double& dydx)
{
	dydx = 2*x;
}

void euler(double& x, double& y, const double& h)
{
	double dydx;
	derivs(x,y,dydx);
	y += dydx*h;
	x += h;
}
	

void integrator(double& x, double& y,double h, const double& xend)
{
	
	while(x<xend) {
		if(xend-x<h) h = xend-x;
		euler(x,y,h);
	}	
}


#endif
