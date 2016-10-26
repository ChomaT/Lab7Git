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
                void Offset();
                void Scale();
                void Center();
                void Normalize();
                void Statistics();
                void Sig_info();
                void Save_file(string);
};



Signal::Signal(){
	length = 0;
	max = 0;
	avg = 0;
	data = new int[100];
        
        int i = 0, sum = 0;
        
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
	fpointer.open("Raw_data_01.txt", ios::in);
	if (fpointer.is_open())
	{
		//fread();
		//for(int i = 0; i < length; i++)
        while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}
        		fpointer.close();
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
	data = new int[100];
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
	if ( L < 10)
            fpointer.open("Raw_data_0" + string(std::itoa(L)) +  ".txt", ios::in);
	else
            fpointer.open("Raw_data_" + string(std::itoa(L)) +  ".txt", ios::in);
        
        
        if (fpointer.is_open())
	{
		//fread();
		//for(int i = 0; i < length; i++)
                while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}

                fpointer.close();
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
	data = new int[100];
	if(data == NULL)
		cerr << "Error in memory allocation";

	ifstream fpointer;
            fpointer.open(instr + ".txt", ios::in);
        
        
        if (fpointer.is_open())
	{
		//fread();
		//for(int i = 0; i < length; i++)
                while(!fpointer.eof())
		{
                    
			fpointer >> data[i];
                        i++;
		}
                fpointer.close();
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



void Signal::Offset()
{
	int i, factor;

        cout << "Input an offset factor: ";
        cin >> factor;
        
	for(i = 0; i < length; i++)
	{
		data[i] = (double)data[i] + factor;
	}
}





void Signal::Scale()
{
	int i, factor;

	cout << "Input a scaling factor: ";
	cin >> factor;

	for(i = 0; i < length; i++)
	{
		data[i] = (double)data[i] * factor;
	}

}


void Signal::Center()
{
	int i;

	for(i = 0; i < length; i++)
	{
		data[i] = (double)data[i] - avg;
	}
}





void Signal::Normalize()
{
	int i;

	for(i = 0; i < length; i++)
	{
			data[i] = (double)data[i] / (double) max;
	}

}


void Signal::Sig_info()
{
	cout<<"Length: " << length << "Max: " << max << "Average: " << avg << endl;
}

void Signal::Save_file(string outstr)
{
	//outstr = outstr + ".txt";
	fstream outstream;
	outstream.open (outstr + ".txt");
	outstream << length << max << "\n";
	for(int i = 0; i < length; i++)
	{
		outstream << data[i] << "\n";
	}
	outstream.close();
}





int main(int argc, char *argv[]) {
	int i = 0, fnum, choice = 0;
	string fname, outname;
	Signal *sig2;

	if(argv[0][1] == 'n')
		{
			fnum = atoi(argv[i+1]);
			Signal sig1(fnum);
			sig2 = new Signal(fnum);
		}
	else if(argv[0][1] == 'f')
		{
			fname == argv[i+1];
			Signal sig1(fname);
			sig2 = new Signal(fname);
		}
	else
		{
			Signal sig1();
			sig2 = new Signal();
		}

	while(choice != 7)
	{
		cout << "Make an operation choice: "
				"1. Offset"
				"2. Scale"
				"3. Center"
				"4. Normalize"
				"5. Print Info"
				"6. Save Data"
				"7. Quit" << endl;
		cin >> choice;

		if(choice == 1)
		{
			sig2->Offset();
		}
		else if(choice == 2)
		{
			sig2->Scale();
		}
		else if(choice == 3)
		{
			sig2->Center();
		}
		else if(choice == 4)
		{
			sig2->Normalize();
		}
		else if(choice == 5)
		{
			sig2->Sig_info();
		}
		else if(choice == 6)
		{
			cout << "Please input desired output name without extension: ";
			cin >> outname;
			sig2->Save_file(outname);
		}
	}

	delete sig2;
}
