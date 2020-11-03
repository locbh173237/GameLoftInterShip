#include <conio.h>
#include <cstdio>
#include <iostream>

//#define STATE_1
#define STATE_2

#ifdef STATE_1

enum stateEnum
{
	STATE_MORNING,
	STATE_EVENING,
	STATE_NIGHT
};

int m_nCurrentState;

#endif // STATE_1

#ifdef STATE_2

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual    char* ToString() = 0;
};

// State Morning
class Morning : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Class Morning";
	}
};

// State Evening
class Evening : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Class Evening";
	}
};

// State night
class Night : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual    char* ToString() {
		return "Class Night";
	}
};


StateBase* Morning::GetNextState() {

	if(true )
		return new Evening();
	else
		return new Night();
}

StateBase* Evening::GetNextState() {
	return new Night();
}

StateBase* Night::GetNextState() {
	return new Morning();
}

class CSun
{
public:
	CSun() {}
	CSun(StateBase* pContext) {
		m_pState = pContext;
	}
	~CSun() {
		delete m_pState;
	}
	// Handles the next state
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;
};

#endif

void main()
{
#ifdef STATE_1

	m_nCurrentState = STATE_EVENING;
	switch (m_nCurrentState)
	{
	case STATE_MORNING:
		m_nCurrentState = STATE_EVENING;
		break;
	case STATE_EVENING:
		m_nCurrentState = STATE_NIGHT;
		break;
	case STATE_NIGHT:
		m_nCurrentState = STATE_EVENING;
		break;
		//..........
		//..........
		//..........
	default:
		break;
	}

#endif

#ifdef STATE_2

	CSun objSun(new Morning);
	printf("Sun Says Good %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Sun Says Good %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Sun Says Good %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Sun Says Good %s !!!\n\n", objSun.GetStateName());

#endif

	system("pause");

}