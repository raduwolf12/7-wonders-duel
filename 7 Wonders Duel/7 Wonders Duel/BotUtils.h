#pragma once
#include"Player.h"
#include"Card.h"
#include"Symbols.h"
#include "Board.h"
#include<map>
#include<iostream>
#include<time.h>
#include<vector>
#include "AIStates.h"
#include"CardRender.h"
#include"GameMechanics.h"
#include<thread>
using namespace std::chrono_literals;

class BotUtils : public Player
{
public:
	
	BotUtils()=default;
	
	std::chrono::milliseconds m_processingTime = 45ms;
	template<class Deck>
	int PickCard(std::vector<CardRender*>cards, std::vector<int> &dr, std::vector<int>&st, Deck deck,
		std::vector<int> &taken,std::vector<bool>fliped,GameMechanics m_mechanics,int curentIndex)
	{
		
		int stAc = 0;
		for (int i = 0; i < st.size(); i++)
		{
			if (st.at(i) == 0)
			{
				stAc++;
			}
		}
		int drAc = 0;
		for (int i = 0; i < dr.size(); i++)
		{
			if (dr.at(i) == 0)
			{
				drAc++;
			}
		}
		int min;
			if (stAc >= drAc)
			{
				min = drAc;
			}
			else
			{
				min = stAc;
			}
		std::this_thread::sleep_for(m_processingTime);
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 rng(seed);
		std::uniform_int_distribution<int> die(0, min-1);
		
		target:int index = die(rng);
		index = die(rng);
		Card card = deck.GetDeck().at(index);
		isActive = false;		
		


		for (int i = 0; i < cards.size(); i++)
		{

			CardRender* cardRender = cards.at(i);
			bool press2 = cardRender->isPressed();
			if (!press2)
			{
				if (st.at(i) == 0 && dr.at(i) == 0)
				{

					Card card2 = m_mechanics.FindCard(cards.at(i)->getName(), deck);

					if (card2.GetCardName() == card.GetCardName())
					{

						if (fliped.at(i) == false)
						{
							if (taken.at(i) != 0)
							{
								CardRender* cardRender = cards.at(i);
								bool press = cardRender->isPressed();
								if (!press)
								{
									taken.at(i) = 0;
									return i;
								}
								else
									goto target;
							}
						}
						else
							goto target;

					}

					if (i == cards.size() - 1)
					{
						goto target;
					}

				}
				else
					goto target;


			}
			else
				goto target;
		}
	}
	Player dataSource;
	bool isActive = false;
	

private:
	/*Strategy m_activeStrategy;
	Board& m_board;
	std::unordered_map<uint64_t, float>m_stateActionEstimations;
	std::vector<uint64_t>m_previousStateAction;
	std::string m_name;*/
	
};

