#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
struct giangvien {
	string ID_GV;
	string FullName, BirthDay, phoneNumber, Address;
};
class GiangVien 
{
private:
	string ID_GV;
	string FullName, BirthDay, phoneNumber, Address;

	
public:
	struct Monhoc {
		string ID_MonHoc;
		string ID_Giangvien;
		string Ten_MonHoc;
		int SLSV;
		int slot;
		int hocki;
		Monhoc() { SLSV = 0; }
	};
	struct user {
		string ID;
		string pass;
		string type;
	};
	GiangVien();
	bool checkmh(Monhoc a);
	void changePass();
	void MoMonHoc();
	void SuaDiem();
	void TongKetDiem();
	void ScreenGV();
	~GiangVien();
};
