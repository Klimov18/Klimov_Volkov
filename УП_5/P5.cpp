#include<iostream>
#include<vector>
#include<string>
#include<map>

class Vich
{
	public:
	void calcS(){}
	void calcX(){}
	void calcV(){}
	void calcT(){}
	void calcA(){}
	void calcAngle(){}
};

class Program
{
	public:
	Program()
	{
		//Приветствие
		std::cout<< "Решение задач на движение тел под углом к горизонту\n";
		std::cout<< "Дано:\n";
		
		//Ввод переменных/Дано
		variablesInput();
	}
	void variablesInput()
	{
		//Словарь переменных
		std::map <int, std::string> param
		{
			{0, "S"},{1, "x"},{2, "v"},{3, "t"},{4, "a"},{5, "Angle"}
		};
		int paramIndex;
		std::string paramVar;
		//Словарь "значений" переменных
		std::map <int, std::string> simbols
		{
			{0, "?"},{1, "?"},{2, "?"},{3, "?"},{4, "?"},{5, "?"}
		};
		
		//Строка Ввода (параметр = значение;параметр = значение;параметр = значение)
		std::string input;
		//Строка выражения (параметр = значение)
		std::string inputParam;
		//Переменная для перебора
		int count;
		
		
		//Ввод значений (до получения continue)
		while(true)
		{
			//Вывод всех параметров (Параметр - значение)
			for(int i = 0; i<6;i++)
			{
				std::cout<< param[i]<< " - "<< simbols[i]<< '\n';
			}
			//Ввод значений
			std::cout<< "Измените значения параметров (параметр = значение, параметр = значение); Для начала решения задачи напишите continue \n";
			std::getline(std::cin, input);
			
			//Проверка длины ввода
			if (input.length()>60)
			{
				std::cout<< "Input is too long";
				continue;
			}
			
			//Проверка на завершение функции
			if (input.find("continue") != std::string::npos)
			{
				return ;
			}
			
			//"Чтение" ввода через перебор словаря параметров и сравнение
			for (const auto& element : param)
			{
				paramIndex = element.first;
				paramVar = element.second;
			 	//Если в вводе присутствует параметр (следовательно есть выражение), то
				if (input.find(paramVar)!=std::string::npos)
				{
					//Присвоение count индекса параметра в input
					count = input.find(paramVar);
					inputParam = "";
					//Запись выражения от count до символа ',' или ';'
					do
					{
						inputParam+=input[count];
						count++;
					}while ((input[count] != ',') * (input[count] != ';') * (count<input.length()));
					
					//Удаление не чисел из выражения, т.к. переменная нам известна
					for (int i = 0; i<inputParam.length();i++)
					{
						if( not( std::isdigit( inputParam[i])) + (inputParam[i] == '-')) inputParam.erase(i,1);
					}
					
					simbols[paramIndex]= inputParam;
					switch(paramIndex)
					{
						case 0:
							this->S = std::stoi(inputParam);
							break;
						case 1:
							this->X = std::stoi(inputParam);
							break;
						case 2:
							this->V = std::stoi(inputParam);
							break;
						case 3:
							this->T = std::stoi(inputParam);
							break;
						case 40:
							this->A = std::stoi(inputParam);
							break;
						case 5:
							this->Angle = std::stoi(inputParam);
							break;
					}
				}
			}
		}
	}
	private:
	double S;
	double X;
	double V;
	double T;
	double A;
	double Angle;
};
int main()
{
	Program *prog = new Program();
	return 0;
}
