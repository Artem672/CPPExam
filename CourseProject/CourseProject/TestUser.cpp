#include "TestUser.h"

string TestUser::GetLogin() const
{
    return this->Login;
}

string TestUser::GetName() const
{
    return this->Name;;
}

string TestUser::GetHomeAddress() const
{
    return this->HomeAddress;
}

string TestUser::GetPhoneNumber() const
{
    return this->PhoneNumber;
}

string TestUser::GetPassword() const
{
    return this->Password;
}

void TestUser::SetName(string Name)
{
    this->Name = Name;
}

void TestUser::SetHomeAddress(string HomeAddress)
{
    this->HomeAddress = HomeAddress;
}

void TestUser::SetPhoneNumber(string PhoneNumber)
{
    this->PhoneNumber = PhoneNumber;
}

void TestUser::SetPassword(string Password)
{
    this->Password = Password;
}

void TestUser::SetLogin(string Login)
{
    this->Login = Login;
}

void TestUser::PrintUserInfo() const
{
    cout << "Логін:\t" << this->GetLogin() << endl
        << "Ім'я:\t" << this->GetName() << endl
        << "Адреса:\t" << this->GetHomeAddress() << endl
        << "Номер телефону:\t" << this->GetPhoneNumber() << endl;
}

void TestUser::AddTestUser(string Login, string Name, string HomeAddress, string PhoneNumber, string Password)
{
    this->Login = Login;
    this->Name = Name;
    this->HomeAddress = HomeAddress;
    this->PhoneNumber = PhoneNumber;
    this->Password = Password;
}
