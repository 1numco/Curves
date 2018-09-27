#include "Header.h"
#include <iostream>
#include <cmath>
using namespace std;

//---------------------------------------------class Circle------------------------------

Circle::Circle(int r)
{
	rad = r;
}

Circle::~Circle()
{

}

double* Circle::get_point(double t)
{
	double* point=new double[3];
	point[0] = rad*cos(t);
	point[1] = rad*sin(t);
	point[2] = 0.0;
	return point;
}

double* Circle::get_fderivate(double t)
{
	double* fdir = new double[3];
	fdir[0] = -rad*sin(t);
	fdir[1] = rad*cos(t);
	fdir[2] = 0;
	return fdir;
}

int Circle::get_rad()
{
	return rad;
}

void Circle::get_param()
{
	cout << "It is instance of Circle  with rad = " << rad<<endl;
}

//-------------------------------class Ellipse-----------------------------------

Ellipse::Ellipse(int a, int b)
{
	rad_x = a;
	rad_y = b;
}

Ellipse::~Ellipse()
{

}

double* Ellipse::get_point(double t)
{
	double* point = new double[3];
	point[0] = rad_x*cos(t);
	point[1] = rad_y*sin(t);
	point[2] = 0.0;
	return point;
}

double* Ellipse::get_fderivate(double t)
{
	double* fdir = new double[3];
	fdir[0] = -rad_x*sin(t);
	fdir[1] = rad_y*cos(t);
	fdir[2] = 0;
	return fdir;
}

void Ellipse::get_param()
{
	cout << "It is instance of Ellipse with rad_x = " << rad_x <<", and rad_y= "<<rad_y<< endl;
}

//------------------------------------------class Helix------------------------------------

Helix::Helix(int r, int s)
{
	rad = r;
	step = s;
}

Helix::~Helix()
{
	
}

double* Helix::get_point(double t)
{
	double* point = new double[3];
	point[0] = rad*cos(t);
	point[1] = rad*sin(t);
	point[2] = step*t;
	return point;
}

double* Helix::get_fderivate(double t)
{
	double* fdir = new double[3];
	fdir[0] = -rad*sin(t);
	fdir[1] = rad*cos(t);
	fdir[2] = step;
	return fdir;
}

void Helix::get_param()
{
	cout << "It is instance of Helix with rad = " << rad << ", and step= " << step << endl;
}
