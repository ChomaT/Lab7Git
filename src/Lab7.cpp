//============================================================================
// Name        : Lab7.cpp
// Author      : Theo Choma
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Signal{
	private:
		int *data;
		int length;
		int max;
		double avg;
	public:
		Signal();		// default constructor.
		Signal(int);	// parametric constructor
		~Signal();		// destructor
};

Signal::Signal(){
	length = 0;
	max = 0;
	avg = 0;
	data = NULL; 								//Need to add default file
	cout << "\nDefault constructor" << endl;
}

Signal::Signal(int L){
	int i = 0, sum = 0;
	string	in=NULL;
	length = L;
	data = new int[L];
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
	fpointer.open("Raw_data_01.txt", ios::in);
	if (fpointer.is_open())
	{
		fread()
		for(int i = 0; i < length; i++)
		{
			fpointer >> data[i];
		}

	}



	//Define max
	max = data[0];
	for (i = 0; i < length; i++)
	{
		if (data[i] > max)
			max = data[i];
	}

	//Define avg
	for (i = 0; i < length; i++)
	{
		sum = sum + data[i];
	}
	avg = (double) sum / (double) length;

	cout << "\nParametric constructor, length =  " << length << "max = " << max << "average = " << avg << endl;
}

Signal::~Signal(){
	delete[] data;	// instead of 'free'
	cout << "\nDestructor" << endl;
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
