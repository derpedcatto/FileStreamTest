#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;

// ��� ������ ������ 1 � �������� ���� ������������ (���� ������������ � �����) ���� ������ ���������� ���� Person.
// ��� ������ ������ 2 - �� ������ ������������ ���������� ����� ���� �������� �� ����� �����

int main()
{
	int num;
	Student student;

	while (true)
	{
		cout << "\n\n1. Write \n2. Read \n3. Clear file \n4. Exit\n\n--> ";
		cin >> num;

		switch (num)
		{

		case 1:
		{
			ofstream file;
			file.open("file", ofstream::app);

			student.WriteStudent(file);

			file.close();
			break;
		}

		case 2:
		{
			ifstream file;
			file.open("file", ios::in);

			if (!file.is_open())
			{
				std::cout << "\nFile is not found!\n";
			}

			string line;
			while (getline(file, line))
			{
				cout << line << endl;
			}

			break;
		}

		case 3:
		{
			ifstream isOpen;
			isOpen.open("file", ios::in);
			if (!isOpen.is_open())
			{
				std::cout << "\nFile is not found!\n";
				break;
			}

			fstream file;
			file.open("file", ios::out | ios::trunc);

			file.close();
			break;
		}

		case 4:
		{
			return 0;
		}
		}
	}
}