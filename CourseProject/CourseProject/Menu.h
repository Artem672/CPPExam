#pragma once
#include "TestUser.h"
#include "AdminUser.h"

class Menu
{
private:
	TestUser T;
	AdminUser AU;
	bool login_status = false;
	bool admin_login_status = false;
	size_t UserId;
public:
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
};

