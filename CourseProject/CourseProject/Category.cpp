#include "Category.h"


size_t Category::GetVectorSize()
{
	return sub.size();
}

void Category::SetSubjectName(string SubjectName)
{
	S.SetSubjectName(SubjectName);
	sub.push_back(S);
}

void Category::AddQuestion(int SubjectN, string Question, string Answer)
{
	sub[SubjectN].AddQuestion(Question, Answer);
}

void Category::SetNumberOfQuestion(int SubjectN, int NumberQ)
{
	sub[SubjectN].SetNumberQ(NumberQ);
}

void Category::DeleteQuestion(int SubjectN)
{
	int QuestionN = 0;
	this->sub[SubjectN].ShowAllQuestions();

	cout << endl << "Введіть номер запитання -> ";
	cin >> QuestionN;

	this->sub[SubjectN].DeleteQuestion(QuestionN);
}

void Category::AddQuestion(int SubjectN)
{
	this->sub[SubjectN].AddQuestion();
}

void Category::ChangeQuestionName(int SubjectId)
{
	string Name;
	int QuestionN = 0;
	this->sub[SubjectId].ShowAllQuestions();

	cout << endl << "Введіть номер запитання -> ";
	cin >> QuestionN;
	cout << "Введіть нове запитання -> ";
	getline(cin, Name);

	sub[SubjectId].ChangeQuestionName(Name, QuestionN);
}

void Category::ChangeQuestionAnswer(int SubjectId)
{
	string Name;
	int AnswerN = 0;
	this->sub[SubjectId].ShowAllQuestions();

	cout << endl << "Введіть номер відповіді -> ";
	cin >> AnswerN;
	cout << "Введіть нову відповідь -> ";
	getline(cin, Name);

	sub[SubjectId].ChangeQuestionAnswer(Name, AnswerN);
}

void Category::EraseSubject(int SubjectNumber)
{
	if (!sub.empty())
	{
		if (SubjectNumber >= 0 && SubjectNumber < sub.size())
		{
			sub.erase(sub.begin() + SubjectNumber);
		}
		else
		{
			cout << "Не правильні дані!" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "Предмети відстуні!" << endl;
	}
}

void Category::SetCategoryName(string CategoryName)
{
	this->CategoryName = CategoryName;
}

void Category::AddSubject()
{
	S.AddSubject();

	sub.push_back(S);
}

void Category::StartTesting(int SubjectNumber)
{
	if (!sub.empty())
	{

		if (SubjectNumber >= 0 && SubjectNumber < sub.size())
		{
			sub[SubjectNumber].StartTesting();
		}
		else
		{
			system("cls");
			cout << "Неправильний номер!" << endl;
		}
	}
	else
	{
		cout << "Предмети відсутні!" << endl;
	}
}

void Category::ShowSubject() 
{
	if (!sub.empty())
	{
		auto Iterator = 0;
		for (auto i = 0; i < sub.size(); i++)
		{
			cout << Iterator++ << ". " << sub[i].GetSubjectName() << endl;

		}
	}
	else
	{
		cout << "Предмети відсутні, добавте спочатку!" << endl;
	}
}

string Category::GetCategoryName()
{
	return this->CategoryName;
}

size_t Category::GetQuestionVectorSize(int Iterator)
{
	return sub[Iterator].GetQuestionSize();
}

string Category::GetQuestionName(int SubjectIterator, int QuestionIterator)
{
	return sub[SubjectIterator].GetQuestion(QuestionIterator);
}

string Category::GetQuestionAnswer(int SubjectIterator,int QuestionIterator)
{
	return sub[SubjectIterator].GetAnswer(QuestionIterator);
}

string Category::GetSubjectName(int SubjectIterator)
{
	return sub[SubjectIterator].GetSubjectName();
}
