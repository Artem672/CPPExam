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
		cout << "Введіть логін -> ";
		getline(cin, login);
		cout << "Введіть пароль -> ";
		getline(cin, password);

		for (auto i = 0; i < this->UserDataBase.size(); i++)
		{
			if (this->UserDataBase[i].GetLogin() == login && this->UserDataBase[i].GetPassword() == password)
			{
				system("cls");
				cout << "Ви залогінились!" << endl;
				this->SetLoginStatus(true);
				this->SetUserId(i);
				Sleep(300);
				break;
			}
		}

		if (!this->GetLoginStatus())
		{
			system("cls");
			cout << "Неправильний пароль або логін!" << endl;
		}
	}
	else
	{
		cout << "Юзери відсутні!Зареєструйтесь спочатку!" << endl;
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
		cout << "Неможливо загрузити базу данних!" << endl;
	}
}

void Menu::Registration()
{
	string login, password, name, address, phonenumber, psswd, confirm_password;
	bool SuccesfullRegistration = false, LoginExist = false;

	do
	{
		system("cls"); cin.ignore();
		cout << "Введіть логін-> ";
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
			cout << "Логін вже зайнятий, спробуйте ще раз!" << endl;
			continue;
		}

		do
		{
			cout << "Введіть пароль(не менше 6 значень) -> ";
			getline(cin, psswd);
			cout << "Підтвердіть пароль -> ";
			getline(cin, confirm_password);
			if (confirm_password != psswd || psswd.size() < 6)
			{
				cout << "Паролі не співпадають або занадто короткий пароль, спробуйте ще раз!" << endl;
				Sleep(500);
				system("cls");
			}
			
		} while (confirm_password != psswd || psswd.size() < 6);

		cout << "Введіть ім'я -> ";
		getline(cin, name);
		cout << "Введіть адресу -> ";
		getline(cin, address);
		cout << "Введіть номер телефону -> ";
		getline(cin, phonenumber);

		T.AddTestUser(login, name, address, phonenumber, psswd);
		UserDataBase.push_back(T);
		SuccesfullRegistration = true;
	} while (!SuccesfullRegistration);

	if (SuccesfullRegistration)
	{
		system("cls");
		cout << "Юзер вдало зареєстрований!" << endl;
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
			cout << "--- Стартове меню ---" << endl
				<< "0. Вийти" << endl
				<< "1. Залогінитися" << endl
				<< "2. Реєстрація" << endl;
			cout << "Ваш вибір -> ";
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
				cout << "1.В якості адміна" << endl
					<< "2.В якості звичайного користувача" << endl
					<< "3. Вихід" << endl
					<< "Ваш вибір -> ";
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
				cout << "1.В якості адміна" << endl
					<< "2.В якості звичайного користувача" << endl
					<< "3. Вихід" << endl
					<< "Ваш вибір -> ";
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
		cout << "Логін : admin" << endl;
		cout << "Введіть пароль -> ";
		cin >> Password;

		if (Password == AU.GetPassword())
		{
			system("cls");
			cout << "Залогінені в якості адміна!" << endl;
			this->SetAdminLoginStatus(true);
			system("pause");
			system("cls");

		}
		else
		{
			system("cls");
			cout << "Неправильний пароль, спробуйте ще раз!" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		system("cls");
		cout << "Зареєструйтеся для початку!" << endl;
		system("pause");
		system("cls");
	}

}

void Menu::AdminRegistration()
{
	if (!AU.GetAdminExist())
	{
		string Login, Password;
		cout << "Логін по завмовчуванню: admin" << endl; Login = "admin";
		cout << "Введіть пароль -> ";
		cin >> Password; 
		AU.SetAdminExist(true);
		AU.SetLogin(Login);
		AU.SetPassword(Password);

		cout << "Адмін зареєстрований!" << endl;
		this->SetAdminLoginStatus(true);
		system("pause");
		system("cls");
	}
	else if (AU.GetAdminExist())
	{
		system("cls");
		cout << "Адмін вже існує!" << endl;
		system("pause");
		system("cls");
	}
}
