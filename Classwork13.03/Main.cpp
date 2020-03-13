#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>
using namespace std;

void TestFstream() {

	fstream fs("test.txt", ios::in | ios::out);
	if (!fs)
	{
		cout << "Error: can not open file!" << endl;
		return;
	}
	cout << "Content file: " << endl;
	cout << fs.rdbuf() << endl; //read whole file
	fs.seekg(0);
	char s = 0;
	while (!fs.eof())
	{
		fs.get(s);
		if (s >= 48 && s <= 57)
		{
			fs.seekg(-1, ios::cur);
			fs << '*';
			fs.seekg(fs.tellg(), ios::beg);//return number of position
		}
	}
	cout << "ok ";
 
	fs.close();
}


int main() {

	srand( time(0));

	//ofstream os("test.txt");
	//ofstream os;
	//os.open("test.txt");
	//if(os.is_open())
	/*if (!os)
	{
		cout << "Error: can not open file!" << endl;
		return 0;
	}

	os << "Hello World!" << endl;
*/
	/*ifstream is("test.txt");

	char str[250];

	if (!is)
	{
		cout << "Error: can not open file!" << endl;
		return 0;
	}

	//is >> str; - one word
	is.getline(str, 100); //100 symbols
	cout << "You are reading: " << str << " from file" << endl;

	TestFstream();*/

	ofstream fout("randomArray.txt");
	ifstream fin("randomArray.txt");
	const int size = 10;
	int array[size];
	int min= 0;
	int max = 0;

	//fout.open();
	if (!fout.is_open())
	{
		cout << "Error: can not open file!" << endl;
	}
	else
	{	
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 50 + 1;
			fout << array[i] << " ";

		}
	}
	fout.close();

	fout.open("randomArray.txt", ios::app);
	
	if (!fin.is_open())
	{
		cout << "Error: can not open file!" << endl;
	}
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			fin >> array[i];
			cout << array[i] << endl;
		}
		for (int i = 0; i < 10; i++)
		{

		
			if (i == 0)
			{
				max = array[i];
				min = array[i];
			}
			else
			{
				if (max <= array[i])
				{
					max = array[i];
				}
				if (min >= array[i])
				{
					min = array[i];
				}
			}
			
		}
	}
fout << "Max =" << max << endl;
fout << "Min =" << min;

cout << "Max =" << max << endl;
cout << "Min =" << min << endl;

	fout.close();
	fin.close();






	system("pause");
	return 0;
}