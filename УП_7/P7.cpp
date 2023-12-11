#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <array>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::to_string;
using std::array;

class Temperature
{
	public:
	
	string to_String()
	{
		return 	"\n\tДата и время измерения: " + getDateAndTime() + 
				"\n\tТемпература в цельсиях: " + to_string(getTempC()) + 
				"\n\tТемпература в кельвинах: " + to_string(getTempK()) + 
				"\n\tТемпература в фаренгейтах: " + to_string(getTempF()) + 
				"\n\tВлажность воздуха: " + to_string(getWetness()) + 
				"\n\tНаличие осадков: " + getPrecipitationPresence()+'\n';
	}
	
	string getDateAndTime(){return dateAndTime;};
	double getTempC(){return tempC;};
	double getTempK(){return tempK;};
	double getTempF(){return tempF;};
	double getWetness(){return wetness;};
	string getPrecipitationPresence(){return precipitationPresence;};

	void setDateAndTime(std::string dateAndTime){this->dateAndTime = dateAndTime;};
	void setTempC(double tempC){this->tempC = tempC;};
	void setTempK(double tempK){this->tempK = tempK;};
	void setTtempF(double tempF){this->tempF = tempF;};
	void setWetness(double wetness){this->wetness = wetness;};
	void setPrecipitationPresence(bool precipitationPresence)
	{
		if (precipitationPresence)
		{
			this->precipitationPresence = "Были";
			return ;
		}
		this->precipitationPresence = "Не были";
	};
	private:
	string dateAndTime;
	double tempC;
	double tempK;
	double tempF;
	double wetness;
	string precipitationPresence;
};

class Applicable
{
	public:
	bool conditionVerify(int n);
	Temperature* generationArray(int n);	
	void display(Temperature* array);
};
class Library : Applicable
{
	public:
	bool conditionVerify(int n)
	{
		if (n<=0)
		{
			cout<<"\tn должно быть больше 0!";
			return false;
		}
		return true;
	}
	Temperature* generationArray(int n)
	{
		Temperature* objArray = new Temperature[n];
		int *seed = new int;
		*seed = time(NULL);
		string date[3];
		string time[2];
		double tempC;
		double tempK;
		double tempF;
		double wetness;
		bool precipitationPresence;
		//int genRandInt(int min, int max, int* seed)
		for (int i = 0; i<n; i++)
		{
			*seed+=i;
			date [0] = to_string(genRandInt(1, 29, seed));
			date [1] = to_string(genRandInt(1, 12, seed));
			date [2] = to_string(genRandInt(2016, 2023, seed+i));
			time [0] = to_string(genRandInt(0, 23, seed));
			time [1] = to_string(genRandInt(1, 59, seed));
			tempC = genRandInt(-10, 20, seed)+(genRandInt(0, 99, seed)/100.0);
			tempK = 273.0+tempC;
			tempF = (9.0/5.0)*tempC + 32.0;
			wetness = genRandInt(5, 89, seed)+(genRandInt(1, 99, seed)/100.0);
			precipitationPresence = genRandInt(0, 1, seed);

			(objArray+i)->setDateAndTime(date[0]+'.'+date[1]+'.'+date[2]+' '+time[2]+':'+time[1]);
			(objArray+i)->setTempC(tempC);
			(objArray+i)->setTempK(tempK);
			(objArray+i)->setTtempF(tempF);
			(objArray+i)->setWetness(wetness);
			(objArray+i)->setPrecipitationPresence(precipitationPresence);
		}
		return objArray;
	}
	void display(Temperature* objArray, int n)
	{
		for (int i = 0; i<n ; i++)
		{
		cout<<"Object "<<i<<":"<<(objArray+i)->to_String();
		}
	}
	int genRandInt(int min, int max, int* seed)
	{
		srand(*seed++);
		return ( min + rand()%(max - min + 1) );
	}
	void getElementsFromObjArray(Temperature* objArray,int n, string element)
	{
		std::map<string, int> parameters
		{
			{"Дата и время",0},
			{"Дата",1},
			{"Время",2},
			{"Температура в цельсиях",3},
			{"Температура в кельвинах",4},
			{"Температура в фарингейтах",5},
			{"Температура", 6},
			{"Влажность воздуха",7},
			{"Наличие осадков",8}
		};

		switch(parameters[element])
		{
			case 0://"Дата и время"
			case 1://"Дата"
			case 2://"Время"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray + i)->getDateAndTime()<<'\n';
				}
				break;
			case 3://"Температура в цельсиях"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray+i)->getTempC() << '\n';
				}
				break;
			case 4://"Температура в кельвинах"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray+i)->getTempK() << '\n';
				}
				break;
			case 5://"Температура в фарингейтах"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray+i)->getTempF() << '\n';
				}
				break;
			case 6://"Температура"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray + i)->getTempC() << '\n';
					cout << (objArray + i)->getTempK() << '\n';
					cout << (objArray + i)->getTempF() << '\n';
				}
				break;
			case 7://"Влажность воздуха"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray+i)->getWetness() << '\n';
				}
				break;
			case 8://"Наличие осадков"
				for (int i = 0;i<n; i++)
				{
					cout << (objArray+i)->getPrecipitationPresence() << '\n';
				}
				break;
			default:
				cout<<"Параметр не найден" << '\n';
				break;
		}
	}
};

int main()
{
	Library obj;
	int n;
	do 
	{
		cout<<"\nВведите натуральное n: ";
		cin>>n;
	} while (!obj.conditionVerify(n));

	Temperature* a = obj.generationArray(n);
	cout << "Исходная база данных:\n";
	obj.display(a, n);
	cout << "Вывод одного из параметров: (введите параметр) ";
	string input;
	cin >> input;
	obj.getElementsFromObjArray(a, n, input);

	return 0;
}


