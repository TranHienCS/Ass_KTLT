#include "SinhVien.h"
#include<string>

using namespace std;

#define max 1000

SinhVien::SinhVien() {
}

void SinhVien::changePass() {
	cout << "Nhap Mat Khau cu: ";
	string str1, str2, pass, temp, user, type;
	cin >> str1;
	ifstream f;
	f.open("curuser.csv", ios::out);
	if (f.fail()) {
		cout << "Failed to open this file! " << endl;
		system("pause");
		return;
	}
	else {
		getline(f, user, ',');
		getline(f, pass, ',');
		getline(f, type);
	}
	while (pass != str1) {
		cout << "Mat khau khong dung, Moi nhap lai mat khau: ";
		cin >> str1;
	}
	if (pass == str1) {
		cout << "Nhap Mat khau moi: ";
		cin >> str1;
		cout << "Doi Mat Khau Thanh Cong ! " << endl;
	}
	f.close();
	ifstream f1;
	string s1, s2, s3, stam;

	f1.open("user.csv", ios::out);
	fstream ftam;
	ftam.open("usertam.csv", ios::app);
	int i = 0;
	while (!f1.eof()) {
		getline(f1, stam);
		i++;
	}
	f1.close();
	f1.open("user.csv", ios::out);

	int k = 0;
	while (!f1.eof()) {
		getline(f1, s1, ',');
		getline(f1, s2, ',');
		getline(f1, s3);
		if (s1 == "") break;
		if (k != i - 1) {
			if (s1 == user) {
				ftam << user << "," << str1 << "," << type << endl;
				k++;
			}
			else {
				ftam << s1 << "," << s2 << "," << s3 << endl;
				k++;
			}
		}
		else {
			if (s1 == user) {
				ftam << user << "," << str1 << "," << type;
				k++;
			}
			else {
				ftam << s1 << "," << s2 << "," << s3;
				k++;
			}
		}
	}

	f1.close();
	ftam.close();
	remove("user.csv");
	rename("usertam.csv", "user.csv");
}

void SinhVien::CourseRegistration() {
	string IdMonHoc, IdGiaoVien, line;
	string line2;
	string Course_ID, Teacher_ID, Name, n_student, slot;
	int i = 0, k = 0;
	cout << "moi ban nhap id mon hoc: ";
	cin.ignore(100, '\n');
	getline(cin, IdMonHoc);
	cout << "moi ban nhap id giao vien: ";
	getline(cin, IdGiaoVien);
	fstream openF;
	openF.open("course.csv", ios::in);
	while (getline(openF, line))
	{
		i++;
	}
	openF.close();
	fstream f;
	f.open("course.csv", ios::in);
	fstream ftam;
	ftam.open("coursetam.csv", ios::app);
	while (!f.eof())
	{
		getline(f, Course_ID, ',');
		getline(f, Teacher_ID, ',');
		getline(f, Name, ',');
		getline(f, n_student, ',');
		getline(f, slot);
		if (IdMonHoc == Course_ID&&IdGiaoVien == Teacher_ID) {
			int ConvertN_student = stoi(n_student);
			int ConvertSlot = stoi(slot);
			if (ConvertN_student < ConvertSlot) ConvertN_student += 1;
			cout << ConvertN_student << endl;
			if (k != i - 1 && k<i) {
				ftam << IdMonHoc << "," << IdGiaoVien << "," << Name << "," << ConvertN_student << "," << slot << endl;
				k++;
			}
			else
			{
				if (k < i) {
					ftam << IdMonHoc << "," << IdGiaoVien << "," << Name << "," << ConvertN_student << "," << slot;
					k++;
				}
			}
			cout << "dang ki thang cong!!" << endl;
			system("pause");
			fstream fObj;
			fObj.open("object.csv", ios::app);
			ifstream fileLogin;
			fileLogin.open("curuser.csv");
			string TenDangNhap;
			getline(fileLogin, TenDangNhap, ',');
			fObj << "\n" << IdMonHoc << "," << TenDangNhap << "," << Teacher_ID << "," << "-1" << "," << "181";
			fObj.close();
			fileLogin.close();
		}
		else
		{
			if (k != i - 1 && k<i) {
				ftam << Course_ID << "," << Teacher_ID << "," << Name << "," << n_student << "," << slot << endl;
				k++;

			}
			else
			{
				if (k < i) {
					ftam << Course_ID << "," << Teacher_ID << "," << Name << "," << n_student << "," << slot;
					k++;
				}
			}
		}
	}
	f.close();
	ftam.close();
	remove("course.csv");
	rename("coursetam.csv", "course.csv");
}

void SinhVien::ScreenSV() {
	system("cls");
	cout << "WELCOM SINH VIEN!" << endl;
	cout << "__________________" << endl;
	cout << "1. Dang Ky Mon Hoc." << endl;
	cout << "2. Huy Mon Hoc." << endl;
	cout << "3. Doi Mat Khau." << endl;
	cout << "4. Dang Xuat." << endl;
	cout << "5. Thoat." << endl;
	int chon;
	DangNhap d;
	cout << "Nhap Lua chon: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		CourseRegistration();
		ScreenSV();
		break;
	case 2:
		DropCouse();
		ScreenSV();
		break;
	case 3:changePass();
		ScreenSV();
		break;
	case 4:cin.ignore();
		rm;
		d.Login();
	case 5:	rm;
		break;

	default:
		cout << "Lua chon khong dung!" << endl;
		system("pause");
		ScreenSV();
	}
}
void SinhVien::DropCouse() {

}

void SinhVien::viewPersonalInformation() {

}

SinhVien::~SinhVien() {

}
