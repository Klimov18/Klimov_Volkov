#pragma once
#include <iostream>
#include <map>

using std::cout;
using std::cin;
using std::string;
class Program
{
	public:
	void menu(Massive lst)
	{
		string input;
		cout<<"\n";
		for (std::pair<string, int> command : commands)
		{
			cout<<"\n"<<command.first;
		}
		cout<<":  ";
		std::getline(cin, input);
		if (!commands.count(input))
		{
			cout<<"\nКоманды не найдено";
			return menu(lst);
		}
		cout<<"\n";
		switch(commands[input])
		{
			case 1://"Заполнить основные списки"
				lst.createList();
			break;
			case 2://"Вывести основные списки"
				lst.printList();
			break;
			case 3://"Просмотр списка отличников"
				lst.printAStudents();
			break;
			case 4://"Просмотр списка хорошистов"
				lst.printBStudents();
			break;
			case 5://"Просмотр списка троечников"
				lst.printCStudents();
			break;
			case 6://"Просмотр списка должников"
				lst.printDStudents();
			break;
			case 7://"Просмотр списка среднего балла"
				lst.printAverageGrade();
			break;
			case 8://"Поиск данных об обучающемся"
				lst.searchForStudentByName();
			break;
			case 9://"Выход"
				cout<<"\n\n\tВерсия программы - 1.0.0";
				cout<<"\n\tФункции программы - \t1 – заполнить основные списки";
				cout<<"\n\t\t\t\t2 – вывести основные списки";
				cout<<"\n\t\t\t\t3 – просмотр список отличники";
				cout<<"\n\t\t\t\t4  – просмотр список хорошисты";
				cout<<"\n\t\t\t\t5 – просмотр список троечники";
				cout<<"\n\t\t\t\t6 – просмотр список двоечники";
				cout<<"\n\t\t\t\t7 – просмотр список средний балл";
				cout<<"\n\t\t\t\t8 – поиск данных об обучающимся в основном списке";
				cout<<"\n\tДанные о разработчиках - 2 ИСП 2023 Волков Иван и Климов Никита";
				cout<<"\n\t©️ все права защищены\n\n";
				return ;
			break;
		}
		return menu(lst);
	}
	private:
	std::map <string, int> commands
	{
		{"Заполнить основные списки", 1},
		{"Вывести основные списки", 2},
		{"Просмотр списка отличников", 3},
		{"Просмотр списка хорошистов", 4},
		{"Просмотр списка троечников", 5},
		{"Просмотр списка должников", 6},
		{"Просмотр списка среднего балла", 7},
		{"Поиск данных об обучающемся", 8},
		{"Выход", 9}
	};
	
};
