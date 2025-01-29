#include "GlobalState.h"

bool GlobalState::PlayerisActive()
{
	if (m_player.GetName() == "User") return true;
	return false;
}

void GlobalState::EnterState(BotUtils* m_bot)
{

}

void GlobalState::ExecuteState(BotUtils*)
{

}

void GlobalState::ExitState(BotUtils*)
{

}
