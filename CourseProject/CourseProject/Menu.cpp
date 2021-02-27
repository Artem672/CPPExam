#include "Menu.h"

Menu::Menu()
{
	this->DownloadUserData();
	this->DownloadAdminData();
	this->DownloadQuestionData();

	Sleep(2000);
	system("cls");
}

Menu::~Menu()
{
	this->UpdateAdminData();
	this->UpdateUserData();
	this->UpdateQuestionData();
}

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
		cin >> login;
		cout << "Введіть пароль -> ";
		cin >> password;

		for (auto i = 0; i < this->UserDataBase.size(); i++)
		{
			if (password == this->UserDataBase[i].GetPassword())
			{
				if (login == this->UserDataBase[i].GetLogin())
				{
					system("cls");
					cout << "Ви залогінились!" << endl;
					this->SetLoginStatus(true);
					this->SetUserId(i);
					Sleep(300);
					break;
				}
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
	string Login, Name, HomeAddress, PhoneNumber, EncryptedPassword, DecryptedPassword;

	fstream download("UserDataBase.txt");

	if (download.is_open())
	{
		cout << "Завантажуємо базу даних юзерів!" << endl;
		while (getline(download, Login))
		{
			getline(download, Name);
			getline(download, HomeAddress);
			getline(download, PhoneNumber);
			getline(download, EncryptedPassword);
			DecryptedPassword = EncryptPassword(EncryptedPassword);
			T.AddTestUser(Login, Name, HomeAddress, PhoneNumber, DecryptedPassword);
			UserDataBase.push_back(T);
		}
		
	}
	else
	{
		cout << "Неможливо загрузити базу данних юзерів!" << endl;
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
		cin >> login;

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
			cin >> psswd;
			cout << "Підтвердіть пароль -> ";
			cin >> confirm_password;
			if (confirm_password != psswd || psswd.size() < 6)
			{
				cout << "Паролі не співпадають або занадто короткий пароль, спробуйте ще раз!" << endl;
				Sleep(500);
				system("cls");
			}
			
		} while (confirm_password != psswd || psswd.size() < 6);
		cin.ignore();
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
	bool MenuCheck = true, UserMenuCheck = true, AdminMenuCheck = true;
	while (MenuCheck)
	{
		if (this->GetLoginStatus() == false	&& this->GetAdminLoginStatus() == false)
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
					<< "3.Вихід" << endl
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
					system("cls");
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
					system("cls");
					break;
				}
				}

			break;
			}
			}
		}

		if (this->GetAdminLoginStatus() == true)
		{
			while (AdminMenuCheck)
			{
				int AdminChoice;
				cout << "0. Вийти" << endl
					<< "1. Керувати списком юзерів" << endl
					<< "2. Добавити категорію" << endl
					<< "3. Добавити предмет до категорії" << endl
					<< "4. Переглянути список предметів категорії" << endl
					<< "5. Змінити пароль адміна" << endl
					<< "Ваш вибір -> ";
				cin >> AdminChoice;
				switch (AdminChoice)
				{
				case 0:
				{
					system("cls");
					this->SetAdminLoginStatus(false);
					AdminMenuCheck = false;
					break;
				}
				case 1:
				{
					if (!this->UserDataBase.empty())
					{
						system("cls");
						this->ShowUserList();
						int UserId = 0;
						cout << "Введіть айді юзера -> ";
						cin >> UserId;
						if (UserId >= 0 && UserId < this->UserDataBase.size())
						{
							system("cls");
							int UserMenu;
							cout << "Меню юзера" << endl
								<< "0. Вихід" << endl
								<< "1. Змінити дані" << endl
								<< "2. Видалити юзера" << endl;
							cout << "Ваш вибір -> ";
							cin >> UserMenu;
							switch (UserMenu)
							{
							case 0:
								system("cls");
								break;
							case 1:
								system("cls");
								this->EditUser(UserId);
								break;
							case 2:
								this->UserDataBase.erase(UserDataBase.begin() + UserId);
								break;
							default:
								cout << "Неправильне значення!" << endl;
								break;
							}
						}
						else
						{
							system("cls");
							cout << "Неправильне значення!" << endl;
						}
					}
					else
					{
						system("cls");
						cout << "Юзери відсутні!" << endl;
					}

					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					system("cls");
					this->AddCategory();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					system("cls");
					int CategoryChoice = 0;
					this->ShowCategoryList();
					if (!this->CategoryData.empty())
					{
						cout << endl << "Введіть номер категорії, щоб добавити тестування(-1 для виходу) -> ";
						cin >> CategoryChoice;
						if (CategoryChoice == -1)
						{
							system("cls");
							break;
						}
						else
						{
							this->AddSubject(CategoryChoice);
							system("pause");
							system("cls");
						}
					}
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					system("cls");
					int FourthCaseMenu = 0;
					this->PrintCategoryAndSubject();
					cout << endl << "Введіть 0 щоб вийти, 1 щоб почати редагувати -> ";
					cin >> FourthCaseMenu;

					switch (FourthCaseMenu)
					{
					case 0:
					{
						system("cls");
						break;
					}
					case 1:
					{
						int EditSubjectMenu = 0, categoryN = 0, subjectN = 0;
						system("cls");
						this->PrintCategoryAndSubject();

						cout << "Введіть номер категорії -> ";
						cin >> categoryN;
						cout << "Введіть номер предмету -> ";
						cin >> subjectN;

						if (categoryN >= 0 && categoryN < CategoryData.size())
						{
							system("cls");
							this->EditSubject(categoryN, subjectN);
							system("pause");
						}
						else
						{
							system("cls");
							cout << "Неправильні дані категорій!" << endl;
							system("pause");
						}
						break;
					}
					}
					
					system("cls");
					break;
				}
				case 5:
				{
					system("cls");
					string NewPassword;
					cout << "Введіть новий пароль адміна -> ";
					cin >> NewPassword;

					AU.SetPassword(NewPassword);
					system("cls");
					cout << "Пароль змінено!" << endl;
					system("pause");
					system("cls");
					break;
				}
				}
			}

			AdminMenuCheck = true;
		}

		if (this->GetLoginStatus() == true)
		{
			bool UserMenu = true;

			while (UserMenu)
			{
				int UserMenuChoice = 0;
				cout << "0. Вихід" << endl
					<< "1. Змінити дані" << endl
					<< "2. Скласти тестування" << endl
					<< "Ваш вибір -> ";
				cin >> UserMenuChoice;

				switch (UserMenuChoice)
				{
				case 0:
				{
					system("cls");
					UserMenu = false;
					this->SetLoginStatus(false);
					break;
				}
				case 1:
				{
					system("cls");
					this->EditUser(this->UserId);
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					system("cls");
					int CategoryN, SubjectN;
					this->PrintCategoryAndSubject();

					if (!CategoryData.empty())
					{
						cout << endl << "Введіть номер категорії -> ";
						cin >> CategoryN;
						cout << "Введіть номер предмету -> ";
						cin >> SubjectN;

						system("cls");

						this->CategoryData[CategoryN].StartTesting(SubjectN);
					}
					system("pause");
					system("cls");
					break;
				}
				}
			}

			UserMenu = true;
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

void Menu::DownloadAdminData()
{
	fstream fst("AdminUserData.txt");

	if (fst.is_open())
	{
		string login, EncryptedPassword;
		fst >> login >> EncryptedPassword;
		string DecryptedPassword = EncryptPassword(EncryptedPassword);
		if (login.empty() && DecryptedPassword.empty())
		{
		}
		else
		{
			AU.SetLogin(login);
			AU.SetPassword(DecryptedPassword);
			AU.SetAdminExist(1);
		}
		cout << "Завантажуємо базу даних адміна!" << endl;
	}
	else
	{
		cout << "Неможливо загрузити базу данних адміна!" << endl;
	}
}

void Menu::UpdateAdminData()
{
	fstream update("AdminUserData.txt");
	
	if (AU.GetAdminExist())
	{
		string EncryptePassword = EncryptPassword(AU.GetPassword());
		update << AU.GetLogin() << "  " << EncryptePassword;
	}	
}

void Menu::UpdateUserData()
{
	fstream update("UserDataBase.txt");

	if (update.is_open())
	{
		for (int i = 0; i < UserDataBase.size(); i++)
		{
			string EncryptedPassword = EncryptPassword(UserDataBase[i].GetPassword());
			update << UserDataBase[i].GetLogin() << endl
				<< UserDataBase[i].GetName() << endl
				<< UserDataBase[i].GetHomeAddress() << endl
				<< UserDataBase[i].GetPhoneNumber() << endl
				<< EncryptedPassword<< endl;
		}
	}
}

void Menu::ShowUserList() const
{
	cout << "---User data base---" << endl;
	if (UserDataBase.empty())
	{
		cout << "\t Empty!" << endl;
	}
	else
	{
		for (auto i = 0; i < this->UserDataBase.size(); i++)
		{
			cout << "Айді: " << i << endl;
			this->UserDataBase[i].PrintUserInfo();
			cout << endl;
		}
	}
	
}

void Menu::AddCategory()
{
	string CategoryName;
	cin.ignore();
	cout << "Введіть назву категорії -> ";
	getline(cin, CategoryName);

	C.SetCategoryName(CategoryName);

	CategoryData.push_back(C);
}

void Menu::ShowCategoryList()
{
	if (!CategoryData.empty())
	{
		int Iterator = 0;
		for (auto i = 0; i < CategoryData.size(); i++)
		{
			cout << Iterator++ << ". " << CategoryData[i].GetCategoryName() << endl;
		}
	}
	else
	{
		cout << "Категорії відсутні!" << endl;
	}
}

void Menu::AddSubject(int CategoryChoice)
{
	system("cls");

	CategoryData[CategoryChoice].AddSubject();
}

void Menu::EditUser(int UserId)
{
	string Login,Name, Password, ConfirmPassword, PhoneNumber, HomeAddress;
	bool SuccesfullEdit = false, LoginExist = false;

	do
	{
		system("cls"); 
		cout << "Введіть логін-> ";
		cin >> Login;

		for (auto i = 0; i < UserDataBase.size(); i++)
		{
			if (UserDataBase[i].GetLogin() == Login )
			{
				LoginExist = true;
				if (UserDataBase[UserId].GetLogin() == Login)
				{
					LoginExist = false;
				}
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
			cin >> Password;
			cout << "Підтвердіть пароль -> ";
			cin >> ConfirmPassword;
			if (ConfirmPassword != Password || Password.size() < 6)
			{
				cout << "Паролі не співпадають або занадто короткий пароль, спробуйте ще раз!" << endl;
				Sleep(500);
				system("cls");
			}

		} while (ConfirmPassword != Password || Password.size() < 6);
		cin.ignore();
		cout << "Введіть ім'я -> ";
		getline(cin, Name);
		cout << "Введіть адресу -> ";
		getline(cin, HomeAddress);
		cout << "Введіть номер телефону -> ";
		getline(cin, PhoneNumber);

		UserDataBase[UserId].AddTestUser(Login, Name, HomeAddress, PhoneNumber, Password);
		SuccesfullEdit = true;
	} while (!SuccesfullEdit);

}

void Menu::PrintCategoryAndSubject()
{
	int CategoryIterator = 0;
	if (!CategoryData.empty())
	{
		for (auto i = 0; i < CategoryData.size(); i++)
		{
			cout << "\t" << CategoryIterator++ << ". " << CategoryData[i].GetCategoryName() << endl;
			CategoryData[i].ShowSubject();
			cout << endl;
		}
	}
	else
	{
		cout << "Пусто!" << endl;
	}

}

void Menu::EditSubject(int CategoryN, int SubjectN)
{
	if (CategoryData[CategoryN].GetVectorSize() != 0)
	{
		int MenuChoice = 0;
		cout << "Меню редагування" << endl
			<< "0. Вийти" << endl
			<< "1. Видалити предмет" << endl
			<< "2. Добавити запитання" << endl
			<< "3. Видалити запитання" << endl
			<< "4. Замінити відповідь" << endl
			<< "5. Замінити запитання" << endl
			<< "Ваш вибір -> ";
		cin >> MenuChoice;

		switch (MenuChoice)
		{
		case 0:
		{
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			this->CategoryData[CategoryN].EraseSubject(SubjectN);
			break;
		}
		case 2:
		{
			system("cls");
			this->CategoryData[CategoryN].AddQuestion(SubjectN);
			break;
		}
		case 3:
		{
			system("cls");
			this->CategoryData[CategoryN].DeleteQuestion(SubjectN);
			break;
		}
		case 4:
		{
			system("cls");
			this->CategoryData[CategoryN].ChangeQuestionAnswer(SubjectN);
			break;
		}
		case 5:
		{
			system("cls");
			this->CategoryData[CategoryN].ChangeQuestionName(SubjectN);
			break;
		}
		default:
		{
			system("cls");
			cout << "Не правильне значення!" << endl;
			break;
		}
		}
	}
	else
	{
		system("cls");
		cout << "Неправильне значення предмету!" << endl;
	}
	
}

string Menu::EncryptPassword(string Password)
{
	char key[3] = { 'K', 'C', 'Q' };
	string EncryptedPassword = Password;

	for (int i = 0; i < EncryptedPassword.size(); i++)
		EncryptedPassword[i] = Password[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return EncryptedPassword;
}

void Menu::UpdateQuestionData()
{
	fstream Update("QuestionDataBase.txt");
	Update.clear();
	if (Update.is_open())
	{
		if (!CategoryData.empty())
		{
			Update << CategoryData.size() << endl;
			for (int i = 0; i < CategoryData.size(); i++)
			{
				Update << CategoryData[i].GetCategoryName() << endl;
				Update << CategoryData[i].GetVectorSize() << endl;
				if (CategoryData[i].GetVectorSize() > 0)
				{
					for (int a = 0; a < CategoryData[i].GetVectorSize(); a++)
					{
						Update << CategoryData[i].GetSubjectName(a) << endl;
						Update << CategoryData[i].GetQuestionVectorSize(a) << endl;
						for (int j = 0; j < CategoryData[i].GetQuestionVectorSize(a); j++)
						{
							Update << CategoryData[i].GetQuestionName(a, j) << endl;
							Update << CategoryData[i].GetQuestionAnswer(a, j) << endl;
						}
						
					}
				}
			}
		}
	}
	Update.close();
}

void Menu::DownloadQuestionData()
{
	fstream Download("QuestionDataBase.txt");
	string CategoryName, SubjectName,  Question, Answer;
	string SubjectSize, QuestionSize, CategorySize;
	if (Download.is_open())
	{
		getline(Download, CategorySize);
		for (int i = 0; i < stoi(CategorySize); i++)
		{
			getline(Download, CategoryName);
			C.SetCategoryName(CategoryName);
			CategoryData.push_back(C);
			getline(Download, SubjectSize);
			if (stoi(SubjectSize) > 0)
			{
				for (int a = 0; a < stoi(SubjectSize); a++)
				{
					getline(Download, SubjectName);
					CategoryData[i].SetSubjectName(SubjectName);
					getline(Download, QuestionSize);
					CategoryData[i].SetNumberOfQuestion(a, stoi(QuestionSize));
					for (int j = 0; j < stoi(QuestionSize); j++)
					{
						getline(Download, Question);
						getline(Download, Answer);
						CategoryData[i].AddQuestion(a, Question, Answer);
					}
				}
			}
		}
		
		
		Download >> SubjectSize;

	}

	Download.close();
}

