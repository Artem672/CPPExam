#include "Menu.h"

bool Menu::GetAdminLoginStatus() const
{
	return this->admin_login_status;
}

size_t Menu::GetUserId() const
{
	return this->UserId;
}

bool Menu::GetLoginStatus() const
{
    return this->login_status;
}

void Menu::SetLoginStatus(bool login_status)
{
	this->login_status = login_status;
}

void Menu::SetUserId(size_t UserId)
{
	this->UserId = UserId;
}

void Menu::SetAdminLoginStatus(bool admin_login_status)
{
	this->admin_login_status = admin_login_status;
}

void Menu::Login()
{
	if (!UserDataBase.empty())
	{
		string login, password;
		system("cls"); cin.ignore();
		cout << "������ ���� -> ";
		getline(cin, login);
		cout << "������ ������ -> ";
		getline(cin, password);

		for (auto i = 0; i < this->UserDataBase.size(); i++)
		{
			if (this->UserDataBase[i].GetLogin() == login && this->UserDataBase[i].GetPassword() == password)
			{
				system("cls");
				cout << "�� �����������!" << endl;
				this->SetLoginStatus(true);
				this->SetUserId(i);
				Sleep(300);
				break;
			}
		}

		if (!this->GetLoginStatus())
		{
			system("cls");
			cout << "������������ ������ ��� ����!" << endl;
		}
	}
	else
	{
		cout << "����� ������!������������� ��������!" << endl;
	}
}

void Menu::DownloadUserData()
{
	UserDataBase.clear();
	
	string Info;
	fstream download("UserDataBase.txt");

	if (download.is_open())
	{

	}
	else
	{
		cout << "��������� ��������� ���� ������!" << endl;
	}
}

void Menu::Registration()
{
	string login, password, name, address, phonenumber, psswd, confirm_password;
	bool SuccesfullRegistration = false, LoginExist = false;

	do
	{
		system("cls"); cin.ignore();
		cout << "������ ����-> ";
		getline(cin, login);

		for (auto i = 0; i < UserDataBase.size(); i++)
		{
			if (UserDataBase[i].GetLogin() == login)
			{
				LoginExist = true;
			}
		}

		if (LoginExist)
		{
			cout << "���� ��� ��������, ��������� �� ���!" << endl;
			continue;
		}

		do
		{
			cout << "������ ������(�� ����� 6 �������) -> ";
			getline(cin, psswd);
			cout << "ϳ�������� ������ -> ";
			getline(cin, confirm_password);
			if (confirm_password != psswd || psswd.size() < 6)
			{
				cout << "����� �� ���������� ��� ������� �������� ������, ��������� �� ���!" << endl;
				Sleep(500);
				system("cls");
			}
			
		} while (confirm_password != psswd || psswd.size() < 6);

		cout << "������ ��'� -> ";
		getline(cin, name);
		cout << "������ ������ -> ";
		getline(cin, address);
		cout << "������ ����� �������� -> ";
		getline(cin, phonenumber);

		T.AddTestUser(login, name, address, phonenumber, psswd);
		UserDataBase.push_back(T);
		SuccesfullRegistration = true;
	} while (!SuccesfullRegistration);

	if (SuccesfullRegistration)
	{
		system("cls");
		cout << "���� ����� �������������!" << endl;
		this->SetLoginStatus(true);
		this->SetUserId(UserDataBase.size());
		Sleep(500);
	}
}

void Menu::Start()
{
	size_t FirstMenuChoice, SecondMenuChoice;
	bool MenuCheck = true;
	while (MenuCheck)
	{
		if (this->GetLoginStatus() == false || this->GetAdminLoginStatus() == false)
		{
			cout << "--- �������� ���� ---" << endl
				<< "0. �����" << endl
				<< "1. �����������" << endl
				<< "2. ���������" << endl;
			cout << "��� ���� -> ";
			cin >> FirstMenuChoice;
			switch (FirstMenuChoice)
			{
			case 0:
			{
				MenuCheck = false;
				break;
			}
			case 1:
			{
				system("cls");
				size_t Choice;
				cout << "1.� ����� �����" << endl
					<< "2.� ����� ���������� �����������" << endl
					<< "3. �����" << endl
					<< "��� ���� -> ";
				cin >> Choice;

				switch (Choice)
				{
				case 1:
				{
					system("cls");
					this->AdminLogin();
					break;
				}
				case 2:
				{
					system("cls");
					this->Login();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					MenuCheck = false;
					break;
				}
				}
				break;
			}
			case 2:
			{
				system("cls");
				size_t Choice;
				cout << "1.� ����� �����" << endl
					<< "2.� ����� ���������� �����������" << endl
					<< "3. �����" << endl
					<< "��� ���� -> ";
				cin >> Choice;
				
				switch (Choice)
				{
				case 1:
				{
					system("cls");
					this->AdminRegistration();
					break;
				}
				case 2:
				{
					system("cls");
					this->Registration();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					MenuCheck = false;
					break;
				}
				}

			break;
			}
			}
		}
	}
}

void Menu::AdminLogin()
{
	if (AU.GetAdminExist())
	{
		system("cls");
		string Password;
		cout << "���� : admin" << endl;
		cout << "������ ������ -> ";
		cin >> Password;

		if (Password == AU.GetPassword())
		{
			system("cls");
			cout << "�������� � ����� �����!" << endl;
			this->SetAdminLoginStatus(true);
			system("pause");
			system("cls");

		}
		else
		{
			system("cls");
			cout << "������������ ������, ��������� �� ���!" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		system("cls");
		cout << "������������� ��� �������!" << endl;
		system("pause");
		system("cls");
	}

}

void Menu::AdminRegistration()
{
	if (!AU.GetAdminExist())
	{
		string Login, Password;
		cout << "���� �� �������������: admin" << endl; Login = "admin";
		cout << "������ ������ -> ";
		cin >> Password; 
		AU.SetAdminExist(true);
		AU.SetLogin(Login);
		AU.SetPassword(Password);

		cout << "���� �������������!" << endl;
		this->SetAdminLoginStatus(true);
		system("pause");
		system("cls");
	}
	else if (AU.GetAdminExist())
	{
		system("cls");
		cout << "���� ��� ����!" << endl;
		system("pause");
		system("cls");
	}
}
