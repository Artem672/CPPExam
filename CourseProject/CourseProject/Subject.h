#pragma once
#include "TestUser.h"

class Subject
{
private:
	class Question
	{
	private:
		string question;
		string answer;
	public:

		void AddQuestion(string question, string answer)
		{
			this->answer = answer;
			this->question = question;
		}

		string GetQuestion()
		{
			return this->question;
		}

		string GetAnswer()
		{
			return this->answer;
		}

		void SetQuestion(string question)
		{
			this->question = question;
		}

		void SetAnswer(string answer)
		{
			this->answer = answer;
		}
	};

	vector <Question> questions;

	Question Q;
	string SubjectName;
	double MaxMark = 12;
	double NumberQ = 0;

public:

	string GetSubjectName()
	{
		return this->SubjectName;
	}

	string GetAnswer(int Iterator)
	{
		return questions[Iterator].GetAnswer();
	}

	string GetQuestion(int Iterator)
	{
		return questions[Iterator].GetQuestion();
	}

	void ChangeQuestionName(string Name, int QuestionId)
	{
		if(!questions.empty())
		{
			if (QuestionId >= 0 && QuestionId < questions.size())
			{
				questions[QuestionId].SetQuestion(Name);
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
			cout << "Питання відсутні!" << endl;
		}
	}

	void ChangeQuestionAnswer(string Name, int AnswerId)
	{
		if (!questions.empty())
		{
			if (AnswerId >= 0 && AnswerId < questions.size())
			{
				questions[AnswerId].SetAnswer(Name);
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
			cout << "Питання відсутні!" << endl;
		}
	}

	void AddSubject()
	{

		cin.ignore();
		cout << "Введіть назву предмета -> ";
		getline(cin, this->SubjectName);
		cout << "Введіть кількість запитань -> ";
		cin >> this->NumberQ;	
		system("cls");
		if (NumberQ == 0)
		{
			system("cls");
			cout << "Неможливо додати 0 запитань!" << endl;
		}
		else if(NumberQ > 0)
		{
			cin.ignore();
			for (auto i = 0; i < this->NumberQ; i++)
			{
				string question, answer;
				cout << "Введіть запитання -> ";
				getline(cin, question);
				cout << "Введіть відповідь до запитання -> ";
				getline(cin, answer);
				Q.AddQuestion(question, answer);
				questions.push_back(Q);
				system("cls");
			}
			cout << "Запитання були добавлені!" << endl;
		}

	}

	void SetSubjectName(string SubjectName)
	{
		this->SubjectName = SubjectName;
	}

	double StartTesting()
	{
		if (this->NumberQ == 0)
		{
			cout << "Запитань поки що немає, зачекайте поки добавлять!" << endl;
			return 0;
		}
		else
		{
			double CurrentMark = 0;
			string Answer;
			double AverageMark = this->MaxMark / this->NumberQ;
			cout << "---Тестування з " << this->SubjectName << endl;
			cin.ignore();
			for (auto i = 0; i < this->NumberQ; i++)
			{
				cout << "Запитання: " << this->questions[i].GetQuestion();
				cout << endl << "Ваща відповідь -> ";
				getline(cin, Answer);

				if (Answer == this->questions[i].GetAnswer())
				{
					CurrentMark += AverageMark;
				}
			}
			
			cout << "Ваша оцінка: " << CurrentMark << endl;

			return CurrentMark;

		}
	}

	void AddQuestion()
	{
		cin.ignore();
		system("cls");
		string question, answer;
		cout << "Введіть запитання -> ";
		getline(cin, question);
		cout << "Введіть відповідь до запитання -> ";
		getline(cin, answer);
		Q.AddQuestion(question, answer);
		questions.push_back(Q);
		system("cls");
	}

	void DeleteQuestion(size_t QuestionNumber)
	{
		if (!questions.empty())
		{
			if (questions.size() != 1)
			{
				if (QuestionNumber >= 0 && QuestionNumber < questions.size())
				{
					questions.erase(questions.begin() + QuestionNumber);
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
				cout << "Неможливо видалити єдиний елемент!" << endl;
			}

		}
		else
		{
			system("cls");
			cout << "Питання відсутні!" << endl;
		}
		system("pause");
	
	}

	void ShowAllQuestions()
	{
		
		if (questions.size() != 0)
		{
			for (auto i = 0; i < questions.size(); i++)
			{
				cout << i << ". " << questions[i].GetQuestion() << endl;
				cout << "Відповідь: " << questions[i].GetAnswer() << endl;
			}
		}
		else
		{
			system("cls");
			cout << "Питання відсутні!" << endl;
		}

	}

	void SetNumberQ(double NumberQ)
	{
		this->NumberQ = NumberQ;
	}

	void AddQuestion(string Question,string Answer)
	{
		Q.AddQuestion(Question, Answer);
		questions.push_back(Q);
	}

	size_t GetQuestionSize()
	{
		return questions.size();
	}
};

