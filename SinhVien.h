#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class SinhVien {
private:
	string ID_sv, FullName_sv, Address_sv;
public:
	SinhVien();



	void changePass();
	void CourseRegistration();
	void DropCouse();
	void viewPersonalInformation();

	~SinhVien();
};

