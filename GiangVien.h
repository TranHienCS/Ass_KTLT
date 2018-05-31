#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

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
		Monhoc() { SLSV = 0; }
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
