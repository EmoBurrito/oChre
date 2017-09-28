#ifndef THING_H
#define THING_H
#include <string>

using namespace std;

//class Statistic
//{
//	private:
//		int value;
//		unsigned int experience;
//	protected:
//	public:
//		addExperience(int);
//		getValue();
//};
//
//class stats
//{
//
//};

class Thing
{
	//TODO Replace these with a stats object which is a collection of Statistic objects
	private:
	protected:
		string name;
		int health;
		int mana;
		int accuracy;
		int strength;
		int speed;
		int intellect;
		int wisdom;
		int luck;
	public:
};

#endif //THING_H
