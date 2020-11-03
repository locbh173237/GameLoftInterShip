#include <conio.h>
#include <cstdio>
#include <iostream>

//#define USE_GLOBAL
//#define USE_POINTER
#define USE_SINGGLETON

class MyClass
{
	int i, i1, i2;
	long l, l1, l2;
	float f, f1, f2;
	double d, d1, d2;
	std::string str, str1, str2;
};


class Sample_Singleton
{
public:
	MyClass *m_pMystruct;
	Sample_Singleton() {
		printf("create object from class Sample_Singleton \n");
		// much thing to do
		// a huge memory need to alocation
		m_pMystruct = new MyClass();
	}

	~Sample_Singleton() {
		delete m_pMystruct;
	}

	void print() {
		printf("print from class Sample_Singleton \n");
	}
#ifdef USE_SINGGLETON

	static Sample_Singleton * m_Instance;
	static void CreateInstance() {
		if (m_Instance == 0)
			m_Instance = new Sample_Singleton();
	}
	static Sample_Singleton * GetInstance() {
		if (m_Instance == 0) {
			m_Instance = new Sample_Singleton();
		}
		return m_Instance;
	}
	static void DestroyInstance() {
		delete m_Instance;
	}
#endif
private:

};


#ifdef USE_GLOBAL
Sample_Singleton g_sample;
#endif

#ifdef USE_POINTER
Sample_Singleton * p_sample;
#endif

#ifdef USE_SINGGLETON
Sample_Singleton *Sample_Singleton::m_Instance = 0;
#endif




void Function_one()
{
	printf("call function_one \n");

#ifdef USE_GLOBAL
	g_sample.print();
#endif

#ifdef USE_POINTER
	p_sample->print();
#endif

#ifdef USE_SINGGLETON
	Sample_Singleton::GetInstance()->print();
#endif
}

void Function_two()
{
	printf("call function_two \n");
#ifdef USE_GLOBAL
	g_sample.print();
#endif

#ifdef USE_POINTER
	p_sample->print();
#endif

#ifdef USE_SINGGLETON
	Sample_Singleton::GetInstance()->print();
#endif
}


void DoSomeThing(){
	printf("Start call function DoSomeThing \n");
	Function_one();
	Function_two();
	Function_one();
	Function_one();
	Function_two();
}

int main()
{
	printf("Start main function \n");
	//system("pause");
	//Function_one();

#ifdef USE_POINTER
	p_sample = new Sample_Singleton();
#endif
	//system("pause");

#ifdef USE_SINGGLETON
///	Sample_Singleton::CreateInstance();
#endif

	DoSomeThing();
	//system("pause");

#ifdef USE_POINTER
	delete p_sample;
#endif

#ifdef USE_SINGGLETON
	Sample_Singleton::DestroyInstance();
#endif
	system("pause");

}
