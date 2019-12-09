//Mike Carrigan
//ECE 2620_001
//Circle Class, don't use commas on point inputs
#include <cmath>
#include <iostream>
#define pi 4*atan(1)
using namespace std;

template< class T> //Creates a template where all types are T

class circle
{
	private:
		T x1, y1, x2, y2;
	protected:
		double distance();
	public :
		double radius(); 
		double circumference(); 
		double area();
		void   populate_classobj(T x1in, T y1in, T x2in, T y2in);
		circle(T = 0, T = 0, T = 0, T = 0);
};

//Defining all functions

template< class T>
double circle<T>::distance() //Define distance between two points
{ 
	double tDist = 0, hDist = 0, vDist = 0;
	hDist = x1 - x2;
	vDist = y1 - y2;
	tDist = sqrt(pow(hDist,2) + pow(vDist,2));
	return tDist;
}

template< class T>
double circle<T>::radius() //Calculate the radius from the distance
{
	return distance();
}

template< class T>
double circle<T>::circumference() //Calculate the circumference from the radius
{
	return (2*radius())*pi;
}

template< class T>
double circle<T>::area() //Calculate the area from the radius
{
	return (radius()*radius())*pi;
}

template< class T> // Redefine circle 1 points
void   circle<T>::populate_classobj(T x1in, T y1in, T x2in, T y2in)
{
	x1 = x1in;
	y1 = y1in;
	x2 = x2in;
	y2 = y2in;
}

template< class T> // Redefine circle 2 points
circle<T>::circle(T ex1, T why1, T ex2, T why2)
{
	x1 = ex1;
	y1 = why1;
	x2 = ex2;
	y2 = why2;
}