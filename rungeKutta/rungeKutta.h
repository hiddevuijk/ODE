#ifndef GUARD_rungeKutta_h
#define GUARD_rungeKutta_h

void derivs(const double& x, const double& y, double& dydx)
{
	dydx = 2*x+3*x*x+4*x*x*x+y;
}

void rk4(double& x, double& y, const double& h)
{

	double k1,k2,k3,k4;
	derivs(x,y,k1);
	derivs(x+h/2,y+k1*h/2,k2);
	derivs(x+h/2,y+k2*h/2,k3);
	derivs(x+h,y+k3*h,k4);	
	y += (k1+2*k2+2*k3+k4)*h/6;
	x += h;

}

void integrator(double& x, double& y,double h, const double& xend, bool corrector=true)
{

	while(x<xend) {
		if(xend-x<h) h = xend-x;
		rk4(x,y,h);
	}
}

#endif
