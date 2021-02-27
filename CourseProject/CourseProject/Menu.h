#pragma once
#include "TestUser.h"
#include "AdminUser.h"
#include "Category.h"

class Menu
{
private:
	TestUser T;
	AdminUser AU;
	Category C;
	vector<Category> CategoryData;
	bool login_status = false;
	bool admin_login_status = false;
	size_t UserId;
public:
	Menu();

	~Menu();

	bool GetAdminLoginStatus() const;

	size_t GetUserId() const;

	bool GetLoginStatus() const;

	void SetLoginStatus(bool login_status);

	void SetUserId(size_t UserId);

	void SetAdminLoginStatus(bool admin_login_status);

	vector<TestUser> UserDataBase;

	void Login();

	void DownloadUserData();

	void Registration();

	void Start();

	void AdminLogin();

	void AdminRegistration();

	void DownloadAdminData();

	void UpdateAdminData();

	void UpdateUserData();

	void ShowUserList() const;

	void AddCategory();

	void ShowCategoryList();

	void AddSubject(int CategoryChoice);

	void EditUser(int UserId);

	void PrintCategoryAndSubject();

	void EditSubject(int CategoryN, int SubjectN);

	string EncryptPassword(string Password);

	void UpdateQuestionData();

	void DownloadQuestionData();
};

