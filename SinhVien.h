#pragma once
#include"DangNhap.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
struct sinhvien {
	string ID_sv, FullName_sv,BirthDay_sv, Address_sv;
};
class SinhVien {
private:
	string ID_sv, FullName_sv, Address_sv;
public:
	SinhVien();



	void changePass();
	void CourseRegistration();
	void DropCouse();
	void viewPersonalInformation();
	void ScreenSV();
	~SinhVien();
};

