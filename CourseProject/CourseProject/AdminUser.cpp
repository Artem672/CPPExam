#include "AdminUser.h"

bool AdminUser::GetAdminExist() const
{
    return this->AdminExist;
}

string AdminUser::GetLogin() const
{
    return this->Login;
}

string AdminUser::GetPassword() const
{
    return this->Password;
}

void AdminUser::SetLogin(string Login)
{
    this->Login = Login;
}

void AdminUser::SetPassword(string Password)
{
    this->Password = Password;
}

void AdminUser::SetAdminExist(bool AdminExist)
{
    this->AdminExist = AdminExist;
}
