#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<random>
#include<vector>
#include<map>
#include<array>
#include<algorithm>

using std::string;
using std::cout;

class Massive
{
	public:
	Massive()
	{
		//Список не был создан
		isListCreated = false;
	}
	void createList()
	{
		//Список был создан
		isListCreated = true;
		
		//Ввод размера списка и проверка (200>n>0)
		do
		{
			cout<<"Введите размер списка учащихся: ";
			std::cin>>listLength;
		}while (listLength>200+listLength<0);
		
		//"Создание" списка по размеру
		StudentsNamesList.resize(listLength) ;
		StudentsGradesList.resize(listLength);
		
		//Присвоение каждому студенту имени из файла "names.txt"
		std::map<int, string> namesMap;
		std::ifstream namesListFile ("names.txt");
		int fileSize = 200;
		if (namesListFile.is_open())
		{
			for (int i = 1;i<=fileSize;i++)
			std::getline(namesListFile, namesMap[i]);
		}
		
		//Присвоение каждому студенту случайной оценки от 2 до 5
		int *seed = new int;
		*seed = time(NULL);
		for (int student = 0;student<listLength;student++)
		{
			StudentsNamesList.at(student) = namesMap[randInt(1,200,seed)];
			for (int j = 0;j<8;j++)
			{
				StudentsGradesList.at(student)[j] = randInt(2,5,seed);
			}
		}
	}
	void printList()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout<<"Список не был создан";
			return ;
		}
		
		//Вывод списка студентов
		for(int student = 0;student<listLength;student++)
		{
			cout<<"\n"<<StudentsNamesList.at(student)<<"\n";
			for(int j = 0;j<8;j++)
			{
				cout<<"\t"<<StudentsGradesList.at(student)[j];
			}
		}
	}
	void printAStudents()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout << "Список не был создан";
			return;
		}
		//Поиск студентов с оценкой 5
		std::vector <string> aStudents = searchForStudentsByGrade(5);

		//Сортировка списка от А до Я
		std::sort(begin(aStudents), end(aStudents));

		//Вывод списка
		for (string student : aStudents)
		{
			cout << "\n" << student;
		}
	}
	void printBStudents()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout << "Список не был создан";
			return;
		}
		//Поиск студентов с оценкой 4
		std::vector <string> bStudents = searchForStudentsByGrade(4);

		//Сортировка списка от А до Я
		std::sort(begin(bStudents), end(bStudents));

		//Вывод списка
		for (string student : bStudents)
		{
			cout << "\n" << student;
		}
	}
	void printCStudents()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout << "Список не был создан";
			return;
		}
		//Поиск студентов с оценкой 3
		std::vector <string> cStudents = searchForStudentsByGrade(3);

		//Сортировка списка от А до Я
		std::sort(begin(cStudents), end(cStudents));

		//Вывод списка
		for (string student : cStudents)
		{
			cout << "\n" << student;
		}
	}
	void printDStudents()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout<<"Список не был создан";
			return ;
		}
		
		//Поиск студентов с оценкой 2
		std::vector <string> dStudents = searchForStudentsByGrade(2);

		//Сортировка списка от А до Я
		std::sort(std::begin(dStudents), std::end(dStudents));

		//Вывод списка
		for (string student : dStudents)
		{
			cout << "\n" << student;
		}
	}
	void printAverageGrade()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout<<"Список не был создан";
			return ;
		}
		
		//Расчёт средней оценки
		int averageGroupeGrade[8];
		for (int student = 0; student<listLength;student++)
		{
			for (int j = 0; j<8; j++)
			{
				averageGroupeGrade[j] += StudentsGradesList.at(student)[j];
			}
		}
		//Вывод
		for (int j = 0; j<8; j++)
		{	
			averageGroupeGrade[j]/=listLength;
			cout<<"\t"<<averageGroupeGrade[j];
		}
		cout<<"\n";
	}
	void searchForStudentByName()
	{
		//Завершение функции, если список не был создан
		if (!isListCreated)
		{
			cout<<"Список не был создан";
			return ;
		}
		string name;
		cout<<"Введите имя студента/Студентов";
		std::getline(std::cin,name);
		//Поиск в введённой строке ФИО студентов
		for (int student; student<listLength; student++)
		{
			if (name.find(StudentsNamesList.at(student)) != std::string::npos)
			{
			
				//Вывод ФИО студента и его оценки если он найден в строке ввода
				cout<<"\n"<<StudentsNamesList.at(student)<<"\n\tОценки:";
				for (int j; j<8; j++)
				{
					cout<<"\t"<<StudentsGradesList.at(student)[j];
				}
				cout<<"\n";
			}
			
		}
	}
	
	private:
	bool isListCreated;
	std::vector <string> StudentsNamesList;
	std::vector <std::array<int, 8>>StudentsGradesList;
	int	listLength;
	int	randInt(int min, int max, int* seed)
	{
		srand((*seed)++);
		return (min + rand()%(max-min+1));
	}
	std::vector <string> searchForStudentsByGrade(int n)
	{
		//Вектор-вывод, хранящий номера всех студентов с оценкой n
		std::vector<string> foundedStudents;

		//Если одна из оценок ниже заданной - студент не записывается в вектор
		bool hasLowerGrade;
		for (int student = 0; student<=listLength; student++)
		{
			hasLowerGrade = false;
			for (int j = 0; j < 8; j++)
			{
				if (StudentsGradesList.at(student)[j] < n)
				{
					hasLowerGrade = true;
				}
			}
			if (not hasLowerGrade)
			{
				foundedStudents.push_back(StudentsNamesList.at(student));
			}
		}
		return foundedStudents;
	}
};
