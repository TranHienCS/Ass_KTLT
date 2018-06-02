#include "Admin.h"

#include <iostream>
#include <string>

Admin::Admin() {
	
	
}



void Admin::Add(){
	string in, admin, temp;
	giangvien gv;
	user u;
	
	cout << "Ban muon them giang vien hay sinh vien ( teacher or student ) : ";
	cin >> in;
	while (in != "teacher"&&in != "student") {
		cout << "Khong Hop Le! Moi nhap lai !" << endl;
		cout << "Ban muon them giang vien hay sinh vien (teacher or student): ";
		cin >> in;
	}
	fstream f1, f2;
	fstream t1, t2;
	f2.open("user.csv", ios::in);
	t1.open("teacheruser.csv", ios::out);
	t2.open("studentuser.csv", ios::out);
	while (!f2.eof()) {
		getline(f2, u.acc, ',');
		getline(f2, u.pass, ',');
		getline(f2, u.type);
		if (u.acc == "") break;
		if (u.type == "teacher"||u.type=="admin") {
			t1 << u.acc << "," << u.pass << "," << u.type << endl;
		}
		if (u.type == "student") {
			t2 << u.acc << "," << u.pass << "," << u.type << endl;
		}
	}
	t1.close();
	t2.close();
	f2.close();
	if (in == "teacher") {
		f2.open("user.csv", ios::in);
		cout << "Nhap Ma Giang Vien: ";
		cin >> gv.ID_GV;
		while (!f2.eof()) {
			getline(f2, u.acc, ',');
			getline(f2, temp);
			while (gv.ID_GV == u.acc) {
				cout << "Ma Giang Vien da ton tai! Moi Nhap lai: ";
				cin >> gv.ID_GV;
			}
			f2.close();
		}
		cout << "Nhap Ho va Ten Gian Vien: ";
		cin.ignore();
		getline(cin, gv.FullName);
		cout << "Nhap ngay sinh cua Gian vien: ";
		getline(cin, gv.BirthDay);
		cout << "Nhap So Dien Thoai Giang Vien: ";
		getline(cin, gv.phoneNumber);
		cout << "Nhap Dia chi cua Giang Vien: ";
		getline(cin, gv.Address);
		f1.open("teacher.csv", ios::app);
		f1 << gv.ID_GV << "," << gv.FullName << "," << gv.BirthDay << "," << gv.phoneNumber << "," << gv.Address << endl;
		t1.open("teacheruser.csv", ios::app);
		t1 << gv.ID_GV << "," << gv.ID_GV << ",teacher" << endl;

	}
	f1.close();
	sinhvien sv;
	if (in == "student") {
		f2.open("user.csv", ios::in);
		cout << "Nhap Ma Sinh Vien: ";
		cin >> sv.ID_sv;
		while (!f2.eof()) {
			getline(f2, u.acc, ',');
			getline(f2, temp);
			while (sv.ID_sv == u.acc) {
				cout << "Ma Sinh Vien da ton tai! Moi Nhap lai: ";
				cin >> sv.ID_sv;
			}
			f2.close();
		}
		cout << "Ho va Ten cua Sinh Vien: ";
		cin.ignore();
		getline(cin, sv.FullName_sv);
		cout << "Nhap ngay sinh cua Sinh Vien: ";
		getline(cin, sv.BirthDay_sv);
		cout << "Nhap dia chi cua Sinh Vien: ";
		getline(cin, sv.Address_sv);
		f1.open("student.csv", ios::app);
		f1 << sv.ID_sv << "," << sv.FullName_sv << "," << sv.BirthDay_sv << "," << sv.Address_sv << endl;
		t2.open("studentuser.csv", ios::app);
		t2 << sv.ID_sv << "," << sv.ID_sv << ",student" << endl;
	}

	f1.close();
	t1.close();
	t2.close();
	f1.open("temp.csv", ios::out);
	t1.open("teacheruser.csv", ios::in);
	t2.open("studentuser.csv", ios::in);
	while (!t1.eof()) {
		getline(t1, u.acc, ',');
		getline(t1, u.pass, ',');
		getline(t1, u.type);
		if (u.acc == "") break;
		f1 << u.acc << "," << u.pass << "," << u.type << endl;
	}
	while (!t2.eof()) {
		getline(t2, u.acc, ',');
		getline(t2, u.pass, ',');
		getline(t2, u.type);
		if (u.acc == "") break;
		f1 << u.acc << "," << u.pass << "," << u.type << endl;
	}
	cout << "Them Thanh Cong !" << endl;
	system("pause");
	f1.close();
	t1.close();
	t2.close();
	remove("user.csv");
	rename("temp.csv", "user.csv");
	remove("teacheruser.csv"); 
	remove("studentuser.csv");
}

void Admin::FindUser() {
	string s1,t,tem;
	cout << "Nhap Ten Dang Nhap cua User: ";
	cin >> s1;
	fstream f1;
	int bool1 = 0;
	f1.open("user.csv", ios::in);
	while (bool1 == 0) {
		while (!f1.eof()) {
			getline(f1, t, ',');
			getline(f1, tem);
			if (t == s1) bool1 = 1;
		}
		if (bool1 == 0) {
			cout << "Ten Dang Nhap cua user khong ton tai! Moi Nhap lai: ";
			cin >> s1;
		}
	}
	f1.close();
	f1.open("user.csv", ios::in);
	string ss1, ss2, ss3, temp;
	while (!f1.eof()) {
		getline(f1, ss1, ',');
		getline(f1, ss2,',');
		getline(f1, ss3);
		if (s1 == ss1) {
			cout << "Thong Tin cua user." << endl;
			cout << "Ten Dang Nhap: " << ss1 << endl;
			cout << "Mat Khau: " << ss2 << endl;
			cout << "Loai user: " << ss3 << endl;
			break;
		}
	}
	f1.close();
	fstream f2;
	giangvien gv;
	sinhvien sv;
	if (ss3 == "teacher") {
		f2.open("teacher.csv", ios::in);
		while (!f2.eof()) {
			getline(f2, gv.ID_GV, ',');
			getline(f2, gv.FullName, ',');
			getline(f2, gv.BirthDay, ',');
			getline(f2, gv.phoneNumber, ',');
			getline(f2, gv.Address);
			if (gv.ID_GV == s1) {
				cout << setw(25) << left << "Ho va Ten" << setw(15) << left << "Ngay Sinh" << setw(15) << left << "So Dien Thoai" << setw(30) << left << "Dia chi" << endl;
				cout << setw(25) << left << gv.FullName << setw(15) << left << gv.BirthDay << setw(15) << left << gv.phoneNumber << setw(30) << left << gv.Address << endl;
				f2.close();
				break;
			}
		}
	}
	if (ss3 == "student") {
		f2.open("student.csv", ios::in);
		while (!f2.eof()) {
			getline(f2, sv.ID_sv, ',');
			getline(f2, sv.FullName_sv, ',');
			getline(f2, sv.BirthDay_sv, ',');
			getline(f2, sv.Address_sv);
			if (sv.ID_sv == s1) {
				cout << setw(25) << left << "Ho va Ten" << setw(15) << left << "Ngay Sinh" << setw(30) << left << "Dia chi" << endl;
				cout << setw(25) << left << sv.FullName_sv << setw(15) << left << left << sv.BirthDay_sv << setw(30) << left << left << sv.Address_sv << endl;
				f2.close();
				break;
			}
		}
	}
	cout << ss1 << endl;
}

void Admin::Delete() {

}

void Admin::ScreenAdmin() {
	system("cls");
	cout << "WELCOM ADMIN! " << endl;
	cout << "1. Tim kiem user." << endl;
	cout << "2. Them user." << endl;
	cout << "3. Xoa user." << endl;
	cout << "4. Doi Mat Khau." << endl;
	cout << "5. Dang Xuat." << endl;
	cout << "6. Thoat." << endl;
	int chon;
	cin >> chon;
	GiangVien g;
	DangNhap d;
	switch (chon)
	{
	case 1:FindUser();
		system("pause");
		ScreenAdmin();
		break;
	case 2: Add();
		ScreenAdmin();
		break;
	case 3: Delete();
		ScreenAdmin();
		break;
	case 4: g.changePass();
		ScreenAdmin();
		break;
	case 5:cin.ignore();
		rm;
		d.Login();
		
	case 6:
		rm;
		break;
		
	default:
		cout << "Lua chon khung dung! Moi Nhap lai." << endl;
		system("pause");
		ScreenAdmin();
		
		
	}
}

Admin::~Admin() {

}
