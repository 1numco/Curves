#pragma once
class Curve 
{
public:
	virtual double* get_point(double t)=0;
	virtual double* get_fderivate(double t)=0;
	virtual void get_param() = 0;
	virtual int get_rad() { return 0; };

};

class Circle : public Curve
{
private:
	int rad;
public:
	Circle(int);
	~Circle();
	double* get_point(double);
	double* get_fderivate(double);
	int get_rad();
	void get_param();
};

class Ellipse : public Curve
{
private:
	int rad_x;
	int rad_y;
public:
	Ellipse(int, int);
	~Ellipse();
	double* get_point(double);
	double* get_fderivate(double);
	void get_param();
};

class Helix : public Curve
{
private:
	int rad;
	int step;
public:
	Helix(int,int);
	~Helix();
	double* get_point(double);
	double* get_fderivate(double);
	void get_param();
};