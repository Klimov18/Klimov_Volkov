#include<iostream>
#include<string>
#include<fstream>

using std::string;
using std::getline;
using std::cout;
using std::to_string;

struct time
{
	public:
	time(string minutesHours = "00:00")
	{
		while (minutesHours.size() < 5) minutesHours = '0' + minutesHours;
		minutesHours.erase(5);
		minutesHours[2] = ':';
		this->time = time;
		this->hour = std::stoi(time[0] + time[1]);
		this->minutes = std::stoi(time[3]+ time[4]);
	}
	time(int minutes = 0)
	{
		this->hour = 0;
		this->minutes = 0;
		while(minutes>60)
		{
			this->hour++;
			minutes -= 60;
		}
		this->minutes = minutes;
		this->time = to_string(this->hour) + ":" + to_string(this->minutes);
	}
	int operator =(int minutes)
	{
		this->hour = 0;
		this->minutes = 0;
		while(minutes>60)
		{
			this->hour++;
			minutes -= 60;
		}
		this->minutes = minutes;
		this->time = ('0'*(hour<10))+to_string(hour) +':'+((minutes<10)*'0')+to_string(minutes);
		return this->minutes+this->hour*60;
	}
	int operator =(string minutesHours)
	{
		while (minutesHours.size() < 5) minutesHours = '0' + minutesHours;
		minutesHours.erase(5);
		minutesHours[2] = ':';
		this->time = minutesHours;
		this->hour = std::stoi(time[0] + time[1]);
		this->minutes = std::stoi(time[3] + time[4]);
		return this->minutes + this->hour * 60;
	}
	int operator +(string minutesHours)
	{
		while (minutesHours.size < 5) minutesHours = '0' + minutesHours;
		minutesHours.erase(5);
		minutesHours[2] = ':';
		this->hour += std::stoi(minutesHours[0] + minutesHours[1]);
		this->minutes += std::stoi(time[3] + time[4]);
		this->time = ('0' * (hour < 10)) + to_string(hour) + ':' + ((minutes < 10) * '0') + to_string(minutes);
		return this->minutes + this->hour * 60;
	}
	int operator +(int minutes)
	{
		while (minutes > 60)
		{
			this->hour++;
			minutes -= 60;
		}
		this->minutes += minutes;
		this->time = ('0' * (hour < 10)) + to_string(hour) + ':' + ((minutes < 10) * '0') + to_string(minutes);
		return this->minutes + this->hour * 60;
	}
	int operator
	private:
	int hour;
	int minutes;
	string time;
};
class Calculations
{
	availablePeriods()
	{
		std::ifstream timeList{"Test.txt"};
		time []startTimes;
		int durations;
		time time2;
		time beginWorkingTime;
		time endWorkingTime;
		int consultationTime;
		if (timeList.open())
		{
			while(std::getline(timeList, line))
			{
				
			}
			cout<<"\n";
			return ;
		}
		cout<<"\nФайл не был открыт";
		return ;
	}
};
