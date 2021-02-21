#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

class TestUser
{
private:
	string Login;
	string Name;
	string HomeAddress;
	string PhoneNumber;
	string Password;
public:
	string GetLogin() const;

	string GetName() const;

	string GetHomeAddress() const;

	string GetPhoneNumber() const;

	string GetPassword() const;

	void SetName(string Name);

	void SetHomeAddress(string HomeAddress);

	void SetPhoneNumber(string PhoneNumber);

	void SetPassword(string Password);

	void SetLogin(string Login);

	void PrintUserInfo() const;

	void AddTestUser(string Login, string Name, string HomeAddress, string PhoneNumber, string Password);
};

