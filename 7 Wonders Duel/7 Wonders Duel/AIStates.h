#include <stack>
#include"Player.h"
#include<assert.h>

#pragma once
template<class Bot> class AiStates
{
public:
	virtual void EnterState(Bot*) = 0;
	virtual void ExecuteState(Bot*) = 0;
	virtual void ExitState(Bot*) = 0;
	virtual ~AiStates();

};
template <class entity_type>class StateMachine
{
private:
	entity_type* m_entity_type;
	AiStates<entity_type>* m_currentState;
	AiStates<entity_type>* m_previousState;
	AiStates<entity_type>* m_globalState;
public:
	StateMachine() = default;
	StateMachine(entity_type* m_owner) :m_entity_type(m_owner),m_currentState(NULL)
	{
		
		m_previousState(NULL);
		m_globalState(NULL);
}
	void SetCurrentState(AiStates<entity_type>* s) { m_currentState = s; }
	void SetPreviousState(AiStates<entity_type>* s) { m_previousState = s; }
	void SetGlobalState(AiStates<entity_type>* s) { m_globalState = s; }
	void Update()
	{
		//if a global state exists,call it's execute method
		if (m_globalState)m_globalState->ExecuteSate(m_entity_type);
		if (m_currentState)m_currentState->ExecuteSate(m_entity_type);
	}
	void ChangeState(AiStates<entity_type>* pmNewState)
	{
		assert(pmNewState && "<StateManchine::ChangeState> is trying to change to a null state");
		// keep a record of the previous state
		m_previousState = m_currentState;
		//call the exit method for the current state
		m_currentState->ExitState(m_entity_type);
		//change the state to a new one
		m_currentState = pmNewState;
		//execute new state
		m_currentState->EnterState(m_entity_type);

	}
	void RevertToPreviousState()
	{
		ChangeState(m_previousState);
	}
	//get-ers
	AiStates<entity_type>* CurrentState()
	{
		return m_currentState;
	}
	AiStates<entity_type>* PreviousState() { return m_previousState; }
	AiStates<entity_type>* GlobalState(){return m_globalState;}

	bool IsInState(const AiStates<entity_type>& m_state)const;


};


