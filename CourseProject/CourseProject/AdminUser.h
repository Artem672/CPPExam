#pragma once
#include "TestUser.h"

class AdminUser
{
private:
	string Login;
	string Password;
	bool AdminExist = false;
public:
	bool GetAdminExist() const;

	string GetLogin() const;

	string GetPassword() const;

	void SetLogin(string Login);

	void SetPassword(string Password);

	void SetAdminExist(bool AdminExist);

};

