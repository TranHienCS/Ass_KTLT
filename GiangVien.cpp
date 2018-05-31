#include "GiangVien.h"
#include "DangNhap.h"



GiangVien::GiangVien() {

}

bool GiangVien::checkmh(Monhoc a) {
	/*ifstream f;
	f.open("course.csv", ios::out);
	if (f.fail())
	cout << "Failed to open this file!" << endl;
	return -1;
	string str;
	Monhoc mh;
	string temp;
	while (!f.eof) {
	getline(f, str);
	stringstream ss;
	ss<> mh.ID_MonHoc;ss >> temp;ss >> mh.Giangvien;ss >> temp;ss >> mh.Ten_MonHoc;ss >> temp;ss >> mh.slot;ss >> temp;ss >> mh.slot;
	}
	if (a.ID_MonHoc==mh.ID_MonHoc) return true;
	else return false;*/
	return 0;
}

void GiangVien::MoMonHoc() {
	string IDcur, IDu, temp, hk;
	ifstream fobj;
	ifstream fcur;
	fcur.open("curuser.csv", ios::out);
	getline(fcur, IDcur, ',');
	fobj.open("object.csv", ios::out);
	int max_obj = 0;
	while (!fobj.eof()) {
		getline(fobj, temp, ',');
		getline(fobj, temp, ',');
		getline(fobj, IDu, ',');
		getline(fobj, temp, ',');
		getline(fobj, hk);
		if (IDu == IDcur&&hk == "171") {
			max_obj++;
		}
	}
	if (max_obj <= 5) {
		cout << "Nhap Thong Tin Mon Hoc:" << endl;
		Monhoc mh;
		cout << "Nhap ma mon hoc: ";
		cin >> mh.ID_MonHoc;
		cout << "Nhap ma Giang vien: ";
		cin >> mh.ID_Giangvien;
		cout << "Nhap Ten mon hoc: ";
		cin.ignore();
		getline(cin, mh.Ten_MonHoc);
		cout << "Nhap So luong Sinh vien: ";
		cin >> mh.slot;
		ofstream f;
		f.open("course.csv", ios::out | ios::app);
		if (f.fail())
			cout << "Failed to open this file course.csv!" << endl;
		else {
			f << mh.ID_Giangvien << "," << mh.ID_Giangvien << "," << mh.Ten_MonHoc << "," << mh.SLSV << "," << mh.slot << endl;
		}
		f.close();
	}
	else cout << "Ban chi duoc phep mo 5 mon hoc trong hoc ki nay! " << endl;
	fobj.close();
	fcur.close();
}
void GiangVien::changePass() {
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
	string s1, s2, s3,stam;

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
		if (k != i-1) {
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
	system("pause");
}

void GiangVien::TongKetDiem() {

}
void GiangVien::SuaDiem() {

}

void GiangVien::ScreenGV() {
	system("cls");
	cout << "WELCOM TEACHER!" << endl;
	cout << "__________________" << endl;
	cout << "1. Mo Mon Hoc." << endl;
	cout << "2. Tong Ket Diem." << endl;
	cout << "3. Sua Diem." << endl;
	cout << "4. Doi Mat Khau." << endl;
	cout << "5. Dang Xuat." << endl;
	cout << "6. Thoat." << endl;
	int chon;
	DangNhap d;
	cin >> chon;
	switch (chon)
	{
	case 1:
		MoMonHoc();
		ScreenGV();
	case 2:
		TongKetDiem();
		ScreenGV();
	case 3:SuaDiem();
		ScreenGV();
	case 4:changePass();
		ScreenGV();
	case 5:cin.ignore();
		rm;
		d.Login();
		
	case 6:	rm;
		break;
	
	default:
		cout << "Lua chon khong dung!" << endl;
		system("pause");
		ScreenGV();
	}
}
GiangVien::~GiangVien() {
}
