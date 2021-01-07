#pragma once
#include"AIStates.h"
#include"BotUtils.h"
//#include"Player.h"
class GlobalState:public AiStates<BotUtils>
{
public:
	
	GlobalState();
	~GlobalState();
	bool PlayerisActive();
	// Inherited via AiStates
	virtual void EnterState(BotUtils*) override;
	virtual void ExecuteSate(BotUtils*) override;
	virtual void ExitState(BotUtils*) override;
private:
	Player m_player;
	BotUtils m_bot;

};

