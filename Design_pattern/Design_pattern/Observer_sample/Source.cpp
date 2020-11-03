#include <conio.h>
#include <cstdio>
#include <iostream>
#include <vector>

class Observer
{
public:
	virtual void update(int value) = 0;
};

class Subject
{
	int m_value;
	std::vector<Observer *> m_views;
public:
	void attach(Observer *obs){
		m_views.push_back(obs);
	}
	void set_val(int value){
		m_value = value;
		notify();
	}
	void notify(){
		for (int i = 0; i < m_views.size(); ++i)
			m_views[i]->update(m_value);
	}
};

class DivObserver : public Observer
{
	int m_div;
public:
	DivObserver(Subject *model, int div){
		model->attach(this);
		m_div = div;
	}
	void update(int v){
		printf("%d div %d is %d \n",v,m_div, v / m_div);
	}
};

class ModObserver : public Observer
{
	int m_mod;
public:
	ModObserver(Subject *model, int mod){
		model->attach(this);
		m_mod = mod;
	}
	void update(int v){
		printf("%d mod %d is %d \n", v, m_mod, v % m_mod);
	}
};

int main()
{
	Subject subj;
	DivObserver divObs1(&subj, 4);
	DivObserver divObs2(&subj, 3);
	ModObserver modObs3(&subj, 3);

	divObs1.update(14);

	subj.set_val(14);


	system("pause");

}