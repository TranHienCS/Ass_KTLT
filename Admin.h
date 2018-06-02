#pragma once
#include "GiangVien.h"
#include "DangNhap.h"
#include "SinhVien.h"
#include "User.h"
#include<iomanip>
class Admin
{
public:
	Admin();

	
	void Add();
	void Delete();
	void FindUser();
	void ScreenAdmin();

	~Admin();
};

