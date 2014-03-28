#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_SIZE 20

class Person
{
	int id;
	char name[MAX_SIZE];

public:
	virtual ~Person()
	{
		cout << "Deleting a person." << endl;
	}	
	virtual void aboutMe()
	{
		cout << "I'm a Person" << endl;
	}
	virtual bool addCourse(string s) = 0;
};



class Student : public Person
{
public:
	~Student()
	{
		cout << "Deleting a student." << endl;
	}	
	void aboutMe()
	{
		cout << "and I'm a student" << endl;
	}
	bool addCourse(string s)
	{
		cout << "Added the course " << s << " to student." << endl;
	}
};

int sum(int a, int b =3)
{
	return a+b;
}

void getLastKLines(char *file, int k)
{
	string *kLines = new string[k];


	ifstream inputFile;
	inputFile.open(file);
	string line;
	int count = 0;
	int startIndex = 0;
	if(inputFile)
	{
		while(getline(inputFile, line))
		{
			kLines[count%k] = line;
			startIndex = (count%k + 1)%k;
			count++;
		}
	}
	int totalLine = count+1;
	count = 0;
	while(count < k)
	{
		cout << "Line " << (totalLine-k+count) << " :\t" << kLines[startIndex%k] << endl;
		startIndex++;
		count++;
	}
}


int main()
{
	//Student *s = new Student();
	Person *p = new Student();
	//s->aboutMe();
	p->aboutMe();
	p->addCourse("Advance Operating System");
	//delete s;
	delete p;

	cout << sum(4) << endl;
	cout << sum(1,2) << endl;

	int *ptr = new int;
	*ptr = 3;
	cout << ptr << endl;
	cout << *ptr << endl;

	int a = 7;
	int &b = a;
	b = 12;
	cout << a << endl;

	ofstream file;
	file.open("testFile.txt");
	file << "This line will be written on the first line in the file.\n";
	file << "This line will be written on the second line in the file.";
	file.close();

	int lines;

	cout << "How many lines from end : ";
	cin >> lines;

	getLastKLines("4.4.cpp", lines);

	return 0;
}