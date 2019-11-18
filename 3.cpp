#include<string>
#include <Windows.h>
#include<iostream>
using namespace std;

class Graduate
{
private:
	char *name;
	bool gender;
	char *id;
	double score;
	string research;
	string tutor;
public:
	static int Information;
	Graduate(char *na, bool ge, char *id, int sc, string re, string tu);
	~Graduate();
	char *getname()
	{
		return this->name;
	}
	bool getgender()
	{
		return this->gender;
	}
	char *getid()
	{
		return this->id;
	}
	int getscore()
	{
		return this->score;
	}
	string getresearch()
	{
		return this->research;
	}
	string gettutor()
	{
		return this->tutor;
	}
	void print();
	friend void grade(Graduate A);
};

void Graduate::print()//学生A的信息
{
	cout << name << "\n" << gender << "\n" << endl;
    cout << id << "\n" << score << "\n"<< endl;
    cout  << research << "\n" << tutor <<"\n" << endl;
}

int Graduate::Information = 0;//其他研究生的信息
Graduate::Graduate(char *na, bool ge, char *id, int sc, string re, string tu)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	if (id)
	{
		id = new char[strlen(id) + 1];
		strcpy(id, id);
	}
	gender = ge;
	score = sc;
	research = re;
	tutor = tu;
	Information++;
}

void grade(Graduate A)
{
	int dengji;
	int n = A.getscore();
	if (n >= 90)
		cout << "A" << endl;
	if ((89 >= n) && (n >= 80))
		cout << "B" << endl;
	if ((79 >= n) && (n >= 70))
		cout << "C" << endl;
	if ((69 >=n) && (n >= 60))
		cout << "D" << endl;
	if (n < 60)
		cout << "E" << endl;
}

int main()
{
	double s = 0, ave = 0;
	Graduate A((char*)"xiaoming", "true", (char*)"20182019", 88, "C++", "zhang");
	grade(A);
	A.print();
	s = s + A.getscore();
	Graduate B((char*)"xiaohong", "flase", (char*)"20182020", 77, "PS", "gao");
	B.print();
	s = s + B.getscore();
	Graduate C((char*)"xiaogang", "true", (char*)"20182021", 66, "Web", "lv");
	C.print();
	s = s + C.getscore();
	ave = s / B.print();
	cout << "平均成绩为：" << ave << endl;
	system("pause");
	return 0;
}