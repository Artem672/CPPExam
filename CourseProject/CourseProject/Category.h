#pragma once
#include "TestUser.h"
#include "Subject.h"

class Category
{
private:

	string CategoryName;
	vector<Subject> sub;

	Subject S;

public:

	size_t GetVectorSize();

	void SetSubjectName(string SubjectName);

	void AddQuestion(int SubjectN, string Question, string Answer);

	void SetNumberOfQuestion(int SubjectN ,int NumberQ);

	void DeleteQuestion(int SubjectN);

	void AddQuestion(int SubjectN);

	void ChangeQuestionName(int SubjectId);

	void ChangeQuestionAnswer(int SubjectId);

	void EraseSubject(int SubjectNumber);

	void SetCategoryName(string CategoryName);

	void AddSubject();

	void StartTesting(int SubjectNumber);

	void ShowSubject();

	string GetCategoryName();

	size_t GetQuestionVectorSize(int Iterator);

	string GetQuestionName(int SubjectIterator, int QuestionIterator);

	string GetQuestionAnswer(int SubjectIterator, int QuestionIterator);

	string GetSubjectName(int SubjectIterator);
};

