#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
	const int phonenum_size = 13; //???????? ????-??????????

	char* name;
	char* lastname;
	char* middlename;

	int year;
	int month;
	int day;

	char* address;
	char* phonenum;

	int pass_size = 6;
	int course_size = 5;
	int exam_size = 4;
	int* pass;
	int* course;
	int* exam;

public:
	/*????????????*/
	Student()
	{
		const char* rand_names[10] = { "Alexander", "Vladimir", "Alexei", "Leonid", "Nikita", "Dmitriy", "Ivan", "Lev", "Andrei", "Pasha" };
		const char* rand_lastnames[10] = { "Vannovskiy", "Azarov", "Afanasyev", "Belov", "Bunin", "Volkov", "Voloshin", "Golov", "Dyogtev", "Dyomin" };
		const char* rand_middlenames[10] = { "Alexandrovich", "Ivanovich", "Petrovich", "Andreevich", "Timurovich", "Vasilyevich", "Vladimirovich", "Yaroslavich", "Timurovich", "Nikolaevich" };

		SetFullName(rand_names[rand() % 10], rand_lastnames[rand() % 10], rand_middlenames[rand() % 10]);
		SetDate(1970 + rand() % 33, 1 + rand() % 11, 1 + rand() % 30);
		SetAddress("Chornomorskaya 46");
		SetPhoneNum("380980461387");

		pass = new int[pass_size];
		course = new int[course_size];
		exam = new int[exam_size];

		for (int i = 0; i < pass_size; i++)
			pass[i] = 3 + rand() % 9;
		for (int i = 0; i < course_size; i++)
			course[i] = 3 + rand() % 9;
		for (int i = 0; i < exam_size; i++)
			exam[i] = 3 + rand() % 9;
	}

	/*??????*/
	void ShowStudent() const;
	void WriteStudent(ofstream& file) const;
	void ChangeRatingElement(int arr_type, int index, int value);
	void CopyStudentDataFrom(const Student& tmp);
	double GetGPA();

	/*??????????*/
	~Student();

	/*???????*/
	void SetFullName(const char* name, const char* lastname, const char* middlename);
	void SetDate(int year, int month, int day);

	void SetAddress(const char* address);
	void SetPhoneNum(const char* phonenum);

	void SetPassElement(int index, int value);
	void SetCourseElement(int index, int value);
	void SetExamElement(int index, int value);

	/*???????*/
	char* GetName() const;
	char* GetLastName() const;
	char* GetMiddleName() const;

	char* GetAddress() const;
	char* GetPhoneNum() const;

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	int GetPassSize() const;
	int GetCourseSize() const;
	int GetExamSize() const;
	int GetPassElement(int index) const;
	int GetCourseElement(int index) const;
	int GetExamElement(int index) const;
};