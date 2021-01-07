#include "PlaceCardsAge2.h"

void PlaceCardsAge2::PlaceCards(Age2Deck &age)
{
	this->age2 = age;
	auto age2deck = age2.GetDeck();
	for (int index = 0; index < kNoCardsFirstLine; ++index)
	{
		m_placeCards.at(index) = { age2deck.at(index),"Accessible" };
	}
	for (int index = 2; index < kNoCardsPlaced; ++index)
	{
		m_placeCards.at(index) = { age2deck.at(index),"Inaccessible" };
	}
}

void PlaceCardsAge2::MakeAccessibleCards()
{

		if (m_placeCards.at(0).second == "Taken" && m_placeCards.at(2).second == "Inaccessible")
		{
			m_placeCards.at(2).second = "Accessible";
		}
		if (m_placeCards.at(0).second == "Taken" && m_placeCards.at(1).second == "Taken" && m_placeCards.at(3).second != "Taken")
		{
			m_placeCards.at(3).second = "Accessible";
		}
		if (m_placeCards.at(1).second == "Taken" && m_placeCards.at(4).second != "Taken")
		{
			m_placeCards.at(4).second= "Accessible";
		}
		if (m_placeCards.at(2).second == "Taken" && m_placeCards.at(5).second != "Taken")
		{
			m_placeCards.at(5).second = "Accessible";
		}
		if (m_placeCards.at(2).second == "Taken" && m_placeCards.at(3).second == "Taken" && m_placeCards.at(6).second != "Taken")
		{
			m_placeCards.at(6).second = "Accessible";
		}
		if (m_placeCards.at(3).second == "Taken" && m_placeCards.at(4).second == "Taken" && m_placeCards.at(7).second != "Taken")
		{
			m_placeCards.at(7).second = "Accessible";
		}
		if (m_placeCards.at(4).second == "Taken" && m_placeCards.at(8).second != "Taken")
		{
			m_placeCards.at(8).second = "Accessible";
		}
		if (m_placeCards.at(5).second == "Taken" && m_placeCards.at(9).second != "Taken")
		{
			m_placeCards.at(9).second = "Accessible";
		}
		if (m_placeCards.at(5).second == "Taken" && m_placeCards.at(6).second == "Taken" && m_placeCards.at(10).second != "Taken")
		{
			m_placeCards.at(10).second = "Accessible";
		}
		if (m_placeCards.at(6).second == "Taken" && m_placeCards.at(7).second == "Taken" && m_placeCards.at(11).second != "Taken")
		{
			m_placeCards.at(11).second= "Accessible";
		}
		if (m_placeCards.at(7).second == "Taken" && m_placeCards.at(8).second == "Taken" && m_placeCards.at(12).second != "Taken")
		{
			m_placeCards.at(12).second = "Accessible";
		}
		if (m_placeCards.at(8).second == "Taken" && m_placeCards.at(13).second != "Taken")
		{
			m_placeCards.at(13).second = "Accessible";
		}
		if (m_placeCards.at(9).second == "Taken" && m_placeCards.at(14).second != "Taken")
		{
			m_placeCards.at(14).second = "Accessible";
		}
		if (m_placeCards.at(9).second == "Taken" && m_placeCards.at(10).second == "Taken" && m_placeCards.at(15).second != "Taken")
		{
			m_placeCards.at(15).second = "Accessible";
		}
		if (m_placeCards.at(10).second == "Taken" && m_placeCards.at(11).second == "Taken" && m_placeCards.at(16).second != "Taken")
		{
			m_placeCards.at(16).second = "Accessible";
		}
		if (m_placeCards.at(11).second == "Taken" && m_placeCards.at(12).second == "Taken" && m_placeCards.at(17).second != "Taken")
		{
			m_placeCards.at(17).second= "Accessible";
		}
		if (m_placeCards.at(13).second == "Taken" && m_placeCards.at(14).second == "Taken" && m_placeCards.at(18).second != "Taken")
		{
			m_placeCards.at(18).second== "Accessible";
		}
		if (m_placeCards.at(13).second == "Taken" && m_placeCards.at(19).second != "Taken")
		{
			m_placeCards.at(19).second = "Accessible";
		}
	
}

void PlaceCardsAge2::AccessibleCards()
{
	for (int index = 0; index < kNoCardsPlaced; ++index)
	{
		if (m_placeCards.at(index).second == "Accessible")
		{
			std::cout << m_placeCards.at(index).first << std::endl;
		}
	}
}

void PlaceCardsAge2::DiscardCard(Card card)
{
	for (int index = 0; index < kNoCardsPlaced; ++index)
	{
		if (m_placeCards.at(index).first.GetCardName() == card.GetCardName())
		{
			m_placeCards.at(index).second = "Taken";
		}
	}
}

