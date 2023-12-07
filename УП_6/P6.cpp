#include<iostream>
#include<array>
#include<time.h>
#include<random>

class Library
{
	public:
	void printMinMax()
	{
		std::cout<<"Min"<<getMinValue();
		std::cout<<"Max"<<getMaxValue();
	}
	void MinMaxCount()
	{
		std::cout<<countMinMax;
	}
	void calcAverageTemp()
	{
		int averageTemp;
		for (int i = 0;i<arrLength;i++)
			{
				averageTemp+=*(array+i);
			}
			averageTemp/=arrLength;
		this->averageTemp=averageTemp;
	}
	void whenMinMaxFound()
	{
		std::cout<<"Hour when max was found: "<<maxIndex;
		std::cout<<"Hour when min was found: "<<minIndex;
	}
	void diffMinHourAndMaxHour()
	{
		std::cout<<"Hour differense beetween Max Hours and Min Hours"<<(maxIndex-minIndex)*(maxIndex>minIndex) + (maxIndex-minIndex)*(minIndex>maxIndex);
	}
	bool arraySizeCheck(int length)
	{
		return length>0;
	}
	void generationArray(int length, int randomMin, int randomMax)
	{
		int *randomArray = new int[length];
		int seed = time(NULL);
		for (int i = 0;i<length;i++)
		{
			srand(seed++);
			*(randomArray+i) = randomMin + rand()%(randomMax-randomMin+1);
		}
		arrLength = length;
		array = randomArray;
	}
	int minValueSearch()
	{
		int min = *array;
		int countMin = 1;
		int index = 0;
		for (int i = 1; i<arrLength; i++) 
		{
			if (min>=*(array+i)) 
			{
				index = i;
				min = *(array+i);
				countMin++;
			}
			if ((array+i) == 0) zeroEncounter=true;
		}
		minIndex = index;
		this->countMinMax+=countMin;
		this->min=min;
		return min;
	}
	void maxIndexSearch()
	{
		int max = *array;
		int index = 0;
		int countMax = 1;
		for (int i = 1; i<(arrLength-1); i++) 
		{
			if (max<=*(array+i)) 
			{
			index = i;
			max = *(array+i);
			countMax++;
			}
			if ((array+i) == 0) zeroEncounter=true;
		}
		this->countMinMax+=countMax;
		this->max=max;
		this->maxIndex = index;
	}
	void printArray()
	{
		for (int i = 0;i<arrLength;i++)
		{
			std::cout<<std::to_string(*(array+i))<<" ";
		}
		std::cout<<'\n';
	}
	int getMaxIndex(){return maxIndex;}
	int getMinIndex(){return minIndex;}
	int getMinValue(){return min;}
	int getMaxValue(){return max;}
	private:
	int maxIndex;
	int minIndex;
	bool zeroEncounter=false;
	int *array;
	int min;
	int max;
	int arrLength;
	int countMinMax;
	double averageTemp;
};

int main()
{
	Library lib;
	int length;
	do
	{
    	std::cout << "Введите размер массива\n";
		std::cin>>length;
		if (!lib.arraySizeCheck(length)) 
		{
			std::cout<<"Размер массива должен быть больше 0\n";
		}
	}while(!lib.arraySizeCheck(length));
	int maxForGen;
	int minForGen;
    std::cout << "Минимальные и максимальные значения заполнения:";
	std::cin>>maxForGen;
	std::cin>>minForGen;
	if (maxForGen<minForGen)
	{
		int switchValue = maxForGen;
		maxForGen = minForGen;
		minForGen = switchValue;
	}
	lib.generationArray(length, minForGen, maxForGen);
	std::cout<<"Массив сгенерирован: ";
	lib.printArray();
	lib.maxIndexSearch();
	std::cout<<"\nMax Index = "<<lib.getMaxIndex();
	std::cout<<"\nMin = "<<lib.minValueSearch()<<'\n';
}
