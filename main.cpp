#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

const int max = 20;
Curve* create_curve(short n)
{
	switch (n) {
	case 1:{
		int rad =  rand() % max +1;
		Circle* crl = new Circle(rad);
		return crl;
	}		
		break;
	case 2:{
		int rad_x = rand() % max +1;
		int rad_y =  rand() % max +1;
		Ellipse* ell = new Ellipse(rad_x,rad_y);
		return ell;
	}		
		break;
	case 3: {
		int rad =  rand() % max+1;
		int step = rand() % max +1;
		Helix* hel = new Helix(rad, step);
		return hel;
	}
		
		break;
	default:
		break;
	}
}
using namespace std;
void point(double* mass)
{
	cout << "3D point with coordinates: x=" << mass[0] << " y=" << mass[1] << " z=" << mass[2] << endl;
	delete[] mass;
}

void f_der(double* mass1)
{
	cout << "Vector of first derivate: (" << mass1[0] << ", " << mass1[1] << ", " << mass1[2] <<")"<< endl;
	delete[] mass1;
}

void sort(vector<Curve*> &vec)
{
	for(int i=0;i<vec.size()-1;i++)
		for(int j=i+1;j<vec.size();j++)
			if (vec[i]->get_rad() > vec[j]->get_rad())
			{
				Curve* ptr = vec[i];
				vec[i] = vec[j];
				vec[j] = ptr;
			}
}
int main()
{
	srand(time(NULL));
	vector<Curve*> vec1;
	vector<Curve*> vec2;
	int num = rand() % max+5;
	Curve* cur;
	for (int i = 0; i < num; i++)
	{
		int n = rand() % 3 + 1;
		cur = create_curve(n);
		vec1.push_back(cur);
		if (n == 1)
		{
			vec2.push_back(cur);
		}
	}

	//example of return 3D point and first derivate

	int rand_num = rand() % vec1.size();
	double t = (double)(rand() % max +1) / (rand() % (max * 2)+1);
	cout << "Now I display random curve with its parameters and 3D point and first derivate, determined by parameter t = " << t << endl;
	vec1[rand_num]->get_param();
	point(vec1[rand_num]->get_point(t));
	f_der(vec1[rand_num]->get_fderivate(t));
	cout << endl;
	// sort elements of container
	cout << "Radii of the circles from second container before sort:" << endl;
	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i]->get_rad() << " ";
	cout << endl;
	sort(vec2);
	cout << "Radii of the circles from second container after sort:" << endl;
	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i]->get_rad() << " ";
	cout << endl;
	int sum = 0;
	for (int i = 0; i < vec2.size(); i++)
		sum += vec2[i]->get_rad();
	cout << endl;
	cout << "Sum of all elements in second container: " <<sum<< endl;

	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec1[i]->get_rad() == 0)
		{
			delete vec1[i];
			vec1[i] = NULL;
		}
	}

	for (int i = 0; i < vec2.size(); i++)
	{
		delete vec2[i];
		vec2[i] = NULL;
	}
	vec1.erase(vec1.begin(), vec1.end());
	vec2.erase(vec2.begin(), vec2.end());
	system("pause");
	return 0;
}