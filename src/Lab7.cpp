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
	protected:
		int *data;
		int length;
		int max;
		double avg;
	public:
		Signal();		// default constructor.
		Signal(int);	// parametric constructor file number
                Signal(string);         //parametric constructor file name
		~Signal();		// destructor
                int* Offset(int*);
                int* Scale(int*);
                int* Center(int*);
                int*  Normalize(int*);
                void Statistics();
                void Sig_info();
                void Save_file();
};

Signal::Signal(){
	length = 0;
	max = 0;
	avg = 0;
	data = int[];
        
        int i = 0, sum = 0;
        
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
	fpointer.open("Raw_data_01.txt", ios::in);
	if (fpointer.is_open())
	{
		fread();
		//for(int i = 0; i < length; i++)
                while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}

                length = i;
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

}

Signal::Signal(int L){
	int i = 0, sum = 0;
	length = 0;
        max = 0;
        avg = 0;
	data = int[];
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
	if ( L < 10)
            fpointer.open("Raw_data_0" + string(itoa(L)) +  ".txt", ios::in);
	else
            fpointer.open("Raw_data_" + string(itoa(L)) +  ".txt", ios::in);
        
        
        if (fpointer.is_open())
	{
		fread();
		//for(int i = 0; i < length; i++)
                while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}

                length = i;
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

Signal::Signal(string instr){
	int i = 0, sum = 0;
	length = 0;
        max = 0;
        avg = 0;
	data = int[];
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
            fpointer.open(instr + ".txt", ios::in);
        
        
        if (fpointer.is_open())
	{
		fread();
		//for(int i = 0; i < length; i++)
                while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}

                length = i;
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



int* Signal::Offset(int* array)
{
	double outarray[50];
	int i, factor;
	char outstr[50];
        
        cout << "Input an offset factor: ";
        cin >> factor;
        
	for(i = 0; i < length; i++)
	{
		outarray[i] = (double)array[i] + factor;
	}

	//saving
	sprintf(outstr, "Offset_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, factor);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}





void scale(int numdata, int *array, double factor, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
		outarray[i] = (double)array[i] * factor;
	}

	//saving
	sprintf(outstr, "Scaled_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, factor);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}


void center(int numdata, int *array, double avg, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
		outarray[i] = (double)array[i] - avg;
	}

	//saving
	sprintf(outstr, "Centered_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, avg);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}





void normal(int numdata, int *array, int max, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
			outarray[i] = (double)array[i] / (double) max;
	}

	//saving Normal
	sprintf(outstr, "Normalized_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
			perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
			fprintf(fp, "%d %d\n", numdata, max);
			for(i = 0; i < numdata; i++)
			{
					fprintf(fp, "%lf\n", outarray[i]);
			}
	}
	fclose(fp);
}










int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
