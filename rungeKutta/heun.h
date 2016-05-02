#ifndef GUARD_heun_h
#define GUARD_heun_h
#include <iostream>
#include <math.h>

void derivs(const double& x, const double& y, double& dydx)
{
	dydx = 2*x+3*x*x+4*x*x*x+y;
}


// heun single 
void heun(double& x, double& y, const double& h)
{
	double dydx1, dydx2;
	double ytemp = y;
	derivs(x,ytemp,dydx1);
	ytemp += dydx1*h;
	derivs(x+h,ytemp,dydx2);
	y += h*(dydx1+dydx2)/2.;
	x += h;
}

// heun with corrector
void heunCorr(double& x, double& y, const double& h,
		double es = 0.000001, double maxit = 200)
{
	double dydx1, dydx2;
	double ye=y;
	derivs(x,y,dydx1);
	ye += dydx1*h;
	int it = 0;
	double ea = 1e9;
	while(ea>es and it<maxit) {
		double yold = ye;
		derivs(x+h,ye,dydx2);
		ye = y + 0.5*(dydx1+dydx2)*h;
		ea = fabs((ye-yold)/ye);
		++it;
		
	}
	y = ye;
	x = x+h;
}

void integrator(double& x, double& y,double h, const double& xend, bool corrector=true)
{

	if(corrector) {	
		while(x<xend) {
			if(xend-x<h) h = xend-x;
			heunCorr(x,y,h);
		}
	} else {
		while(x<xend) {
			if(xend-x<h) h = xend-x;
			heun(x,y,h);
		}
	}
}

#endif
