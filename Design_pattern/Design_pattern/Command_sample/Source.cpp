#include <conio.h>
#include <cstdio>
#include <iostream>
#include <list>

#define USE_COMMAND


class Giant
{
public:
	enum Type
	{
		ATTACK, RUN, FLY
	};
	Giant() {
		m_id = s_next++;
		m_type = (Type)(m_id % 3);
	}
	Type get_type() {
		return m_type;
	}
	void Attack() {
		printf("Giant Attack \n");
	}
	void Run() {
		printf("Giant Run \n");
	}
	void Fly() {
		printf("Giant Fly \n");
	}
private:
	Type m_type;
	int m_id;
	static int s_next;
};
int Giant::s_next = 0;

#ifdef USE_COMMAND

class Command
{
public:
	typedef void(Giant:: *Action)();
	Command(Giant *object, Action method){
		m_object = object;
		m_method = method;
	}
	void execute(){
		(m_object->*m_method)();
	}
private:
	Giant *m_object;
	Action m_method;
};

#endif


int main()
{
#ifndef USE_COMMAND
	printf("Normal way: \n");

	std::list<Giant*> list_G;
	Giant input[6], *bad_guy;

	for (int i = 0; i < 6; i++)
		list_G.push_back(&input[i]);

	for (int i = 0; i < 6; i++)
	{
		bad_guy = list_G.back();
		if (bad_guy->get_type() == Giant::ATTACK)
			bad_guy->Attack();
		else if (bad_guy->get_type() == Giant::RUN)
			bad_guy->Run();
		else if (bad_guy->get_type() == Giant::FLY)
			bad_guy->Fly();
		list_G.pop_back();
	}

#endif 

#ifdef USE_COMMAND

	printf("Normal using command: \n");

	std::list<Command*> list_cmd;
	Command *input_cmd[] =
	{
		new Command(new Giant, &Giant::Attack),
		new Command(new Giant, &Giant::Run),
		new Command(new Giant, &Giant::Fly),
		new Command(new Giant, &Giant::Attack),
		new Command(new Giant, &Giant::Run),
		new Command(new Giant, &Giant::Fly)
	};

	for (int i = 0; i < 6; i++)
		list_cmd.push_back(input_cmd[i]);

	for (int i = 0; i < 6; i++)
	{
		list_cmd.back()->execute();
		list_cmd.pop_back();
	}

#endif

	printf("\n\n");
	system("pause");
}