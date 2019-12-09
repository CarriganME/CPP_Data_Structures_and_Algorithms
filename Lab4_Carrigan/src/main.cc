//Lab 4
//Mike Carrigan
//File Reading and Dynamic Arrays
#include <cmath>
#include <iostream>
#include <fstream>
#define pi 4*atan(1)
using namespace std;

int findmax( int one, int two, int three, int four, int five);

//Main Program
int main()
{
	// open up files
	ifstream infile;
	ofstream outfile;
	infile.open("lab4_input.txt");
	outfile.open("lab4_output.txt");
	// check that files are open
	if ( infile.is_open() & outfile.is_open() )
	{
		int n = 0;
		cout << "Input file succesfully loaded."<< endl << endl;
		// get size for array
		cout << "How many lines in array?" << endl;
		cin >> n;
		cout << endl;
		int  *OUT = NULL;
		OUT = new int[n];
		// populate array
		for( int i = 0; i < n; ++i)
		{
			int x1, x2, x3, x4, x5;
			infile >> x1 >> x2 >> x3 >> x4 >> x5;
			OUT[i] = findmax( x1, x2, x3, x4, x5);
		}
		// populate output file
		for( int i = 0; i < n; ++i)
		{
			outfile << OUT[i] << " ";
		}		

		// close everything out
		delete [] OUT;
		OUT = NULL;
	    infile.close();
		outfile.close();
	}
	else
	{
		cout << "error in file opening. Program aborted."<< endl;
	}

	
}

int findmax( int one, int two, int three, int four, int five)
{
	int Max = one;
	if (Max < two) { Max = two;}
	if (Max < three) {Max = three;}
	if (Max < four) {Max = four;}
	if (Max < five) {Max = five;}
	return Max;
}