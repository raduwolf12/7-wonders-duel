#include<iostream>
#include"Player.h"
#include"AgeICards.h"
#include"Age2Deck.h"
#include"Age3Deck.h"
#include"GameMechanics.h"
#include<unordered_map>
#include "Board.h"
#include"WonderCardDeck.h"
#include"ActiveProgressTokens.h"
#include"GameLogic.h"


void GameLogic::SettingGame()
{
	player1.SetName("Adi");
	player2.SetName("Radu");
	player1.SetDirection(false);
	player2.SetDirection(true);
	player1.SetMoney(7);
	player2.SetMoney(7);
	progressTokens.PopulateProgressTokens();
	progressTokens.SetUpProgressTokensForGame();
	age1.PopulateDeck();
	age1.ShuffleInCards();
	firstPlacement.PlaceCards(age1);

	age2.PopulateDeck();
	age2.ShuffleInCards();
	secondPlacement.PlaceCards(age2);

	age3.PopulateDeck();
	age3.ShuffleInCards();
	thirdPlacement.PlaceCards(age3);
}

void GameLogic::RunGame()
{
	SettingGame();
	//ChosingWonderCards();
	ChosingAgeCards();

}

bool GameLogic::BuyingResource(Cost cost, Player& player1, Player player2)
{
	uint16_t moneyRequired = 2 + CountPlayerResource(player2, cost); //formula de calcul pt trading
	std::cout << "\nTo buy the reosurce are required " << moneyRequired << " coins.";

	std::cout << "\n" << player1.GetName() << " has " << player1.GetMoney() << " coins.";
	if (player1.GetMoney() >= moneyRequired) //pot cumpara cartea
	{
		player1.DecreaseMoney(moneyRequired);
		std::cout << "\n" << player1.GetName() << " has " << player1.GetMoney() << " coins.";
		std::cout << "\nSuccessfully purchased resource!\n";
		return true;
	}
	throw"The player doesn't afford the resource.";
	return false;
}

void GameLogic::MoveConflictPawn(Board& b, Player& player1, Player& player2, Card c)
{
	uint32_t militaryPoints = 0;
	auto s = c.GetPoints();
	militaryPoints = std::count_if(s.begin(), s.end(), [](Points i) {return i.GetPointsType() == Points::PointsType::MilitaryVictoryPoints; });
	uint32_t victoryPoints = std::count_if(s.begin(), s.end(), [](Points i) {return i.GetPointsType() == Points::PointsType::VictoryPoints; });

	player1.SetMilitarryPoints(militaryPoints);
	player1.SetVictoryPoints(victoryPoints);

	std::cout << "Military Points " << player1.GetMilitarryPoints();

	std::cout << "\nVictory Points " << player1.GetVictoryPoints();
	if (player1.GetDirection() == true)
		b.SetConflictPawn(b.GetPownPosition() - militaryPoints, b);
	if (player1.GetDirection() == false)
		b.SetConflictPawn(b.GetPownPosition() + militaryPoints, b);
	std::cout << std::endl << b.PawnPosition(b);
	std::cout << "\n Player 2 money:";
	std::cout << player2.GetMoney();
	if (b.PawnPosition(b) == "Your power increases with 5 Military Tokens.")
	{
		std::cout << "\n Player 2 money:";

		player2.DecreaseMoney(5);
	}
	if (b.PawnPosition(b) == "Your power increases with 2 Military Tokens.")
	{
		std::cout << "\n Player 2 money:";

		player2.DecreaseMoney(2);
	}

}

void GameLogic::UseCardSymbol(Player& player1, Card c)
{
	std::vector<Symbols::Symbol> symbols;
	symbols.insert(symbols.begin(), { Symbols::Symbol::Bol,Symbols::Symbol::Feather,Symbols::Symbol::Gyroscope,Symbols::Symbol::Pendulum,Symbols::Symbol::SolarClock,Symbols::Symbol::Wheel });
	for (auto symbol : symbols)
		if (c.GetSymbol() == symbol)
		{
			SetSymbol(player1, c.GetSymbol());
		}
}

bool GameLogic::CountSymbolInPlayersDeck(Player& player1)
{
	auto playerActiveSymbols = player1.GetActiveSymbols();
	std::vector<Symbols::Symbol> symbols;
	symbols.insert(symbols.begin(), { Symbols::Symbol::Bol,Symbols::Symbol::Feather , Symbols::Symbol::Gyroscope , Symbols::Symbol::Pendulum ,Symbols::Symbol::SolarClock,Symbols::Symbol::Wheel });
	for (auto symbol : symbols)
	{
		uint8_t symbolNumber = std::count_if(playerActiveSymbols.begin(), playerActiveSymbols.end(), [&symbol](Symbols::Symbol& s) {return s == symbol; });
		if (symbolNumber == 2) {
			player1.DeactivateSymbol(symbol);
			return true;
		}
	}
	return false;
}

void GameLogic::UseSign(Player& player1, Card c)
{
	std::vector<Signs::Sign> signs;
	signs.insert(signs.begin(), { Signs::Sign::Barrel,Signs::Sign::Book ,Signs::Sign::Column ,Signs::Sign::HalfMoon,Signs::Sign::Harp,Signs::Sign::Helmet,Signs::Sign::Horseshoe,Signs::Sign::Lamp,Signs::Sign::Mask,Signs::Sign::Sun,Signs::Sign::Sword,Signs::Sign::Target,Signs::Sign::Temple,Signs::Sign::Tower,Signs::Sign::Vessel,Signs::Sign::WaterDrop,Signs::Sign::Wheel });
	for (auto sign : signs)
	{
		if (c.GetSign() == sign)
			player1.SetSign(sign);
	}
}

bool GameLogic::VerifyCardSign(Player& player1, Card c)
{
	auto ageDub = player1.GetPlayerDeck2();
	auto it = std::find_if(std::begin(ageDub), end(ageDub), [&c](Card& p) { return p.GetSign() == c.GetSign()&&p.GetSign()!=Signs::Sign::Null; });
	if (it == ageDub.end())
	{
		return false;
	}
	return true;
}

ProgressToken GameLogic::FindProgressToken(std::string C)
{
	auto a = progressTokens.GetActiveProgressTokens();
	for (auto index = 0; index < progressTokens.GetActiveProgressTokens().size(); index++)
	{
		auto scientificSymbol = a.at(index).GetScientificSymbol();
		if (scientificSymbol.find(C) != std::string::npos) {
			return progressTokens.GetActiveProgressTokens().at(index);
		}
	}
	throw "Invalid Token";
}

void GameLogic::SetSpecial(Player& player1, Card c)
{
	if (c.GetSpecial() == "2 Wood")
	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
	}
	if (c.GetSpecial() == "2 Clay")
	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
	}
	if (c.GetSpecial() == "2 Stone")
	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
	}

	if (c.GetSpecial() == "Glass")
	{
		player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
	}
	if (c.GetSpecial() == "Papirus")
	{
		player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
	}

	if (c.GetSpecial() == "Glass/Papirus")
	{
		std::cout << "\nYou have to chose between Glass and Papirus.\n";
		std::string str;
		std::cin >> str;
		if (str == "Glass")
			player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
		if (str == "Papirus")
			player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
	}
	if (c.GetSpecial() == "Wood/Clay/Stone")
	{
		std::cout << "\nYou have to chose between Wood,Clay and Stone.\n";
		std::string str;
		std::cin >> str;
		if (str == "Wood")
			player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
		if (str == "Stone")
			player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
		if (str == "Clay")
			player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));

	}
}

void GameLogic::ChoseResource(Player& player)
{
	std::cout << "Chose between Stone, Wood and Clay.\n";
	std::string resource;
	std::cin >> resource;
	if (resource == "Stone")
		player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
	else if (resource == "Clay")
		player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
	else if (resource == "Wood")
		player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
	else
		throw"Invalid option.";
}

void GameLogic::ValidResourceChosen(Player& player)
{
	bool ok = false;
	while (ok == false)
	{
		try {
			ChoseResource(player);
			ok = true;
			break;
		}
		catch (const char* error)
		{
			std::cout << error;
		}
	}
}

void GameLogic::ChoseManufacturedGood(Player& player)
{
	std::cout << "Chose between Glass and Papirus";
	std::string good;
	std::cin >> good;
	if (good == "Glass")
		player.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
	else if (good == "Papirus")
		player.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
	else
		throw"Invalid option.";

}

void GameLogic::ValidManufacturedGoodChosen(Player& player)
{
	bool ok = false;
	while (ok == false)
	{
		try {
			ChoseManufacturedGood(player);
			ok = true;
			break;
		}
		catch (const char* error)
		{
			std::cout << error;
		}
	}
}

void GameLogic::Agriculture(Player& player)
{
	player.AddMoney(6);
	player.SetVictoryPoints(4);
	std::cout << player.GetMoney();
}

void GameLogic::Arhitecture(Player& player)
{
	ValidResourceChosen(player);
	ValidResourceChosen(player);
}

void GameLogic::Economy(Player& player)
{
	player.AddMoney(7);
}

void GameLogic::Law(Player& player)
{
	player.SetVictoryPoints(3);
}

void GameLogic::Masonry(Player& player)
{
	ValidResourceChosen(player);
	ValidResourceChosen(player);
}

void GameLogic::Mathematics(Player& player)
{
	player.AddMoney(player.GetProgressTokens().size());
}

void GameLogic::Philosophy(Player& player)
{
	player.SetVictoryPoints(7);
}

void GameLogic::Theology(Player& player)
{
	ValidManufacturedGoodChosen(player);
	ValidManufacturedGoodChosen(player);
}

void GameLogic::Strategy(Player& player)
{
	player.SetMilitarryPoints(3);
}

void GameLogic::Urbanism(Player& player)
{
	player.AddMoney(6);
}

void GameLogic::UseProgressToken(Player& player, std::string s)
{
	if (s == "Agriculture")
		Agriculture(player);
	else if (s == "Arhitecture")
		Arhitecture(player);
	else if (s == "Economy")
		Economy(player);
	else if (s == "Law")
		Law(player);
	else if (s == "Masonry")
		Masonry(player);
	else if (s == "Mathematics")
		Mathematics(player);
	else if (s == "Philosophy")
		Philosophy(player);
	else if (s == "Theology")
		Theology(player);
	else if (s == "Strategy")
		Strategy(player);
	else if (s == "Urbanism")
		Urbanism(player);
}

void GameLogic::PickToken(Player& player1, ActiveProgressTokens& progressTokens)
{
	std::cout << "\n\nYou own two cards with the same symbol; \nPlease chose a Progress Tokens from the following:\n";
	std::cout << progressTokens;
	bool ok = false;
	while (ok == false)
	{
		std::string progressTokenName;
		std::cin >> progressTokenName;
		try {

			ProgressToken pr = FindProgressToken(progressTokenName);
			player1.SetProgressTokens(pr);
			/*Functor<void (*)(Player & player1)> f();
			f()(player1);*/
			UseProgressToken(player1, progressTokenName);
			progressTokens.DiscardProgressToken(pr);
			ok = true;
		}
		catch (char* error)
		{
			std::cout << error;
		}
	}
}

void GameLogic::BuildersGuild(Player& player1, Player& player2)
{
	if (player1.GetBuildedWonders().size() > player2.GetBuildedWonders().size())
	{
		uint32_t money = player1.GetMoney();
		player1.SetVictoryPoints(2 * player1.GetBuildedWonders().size());
	}
	if (player1.GetBuildedWonders().size() < player2.GetBuildedWonders().size())
	{
		uint32_t money = player2.GetMoney();
		player2.SetVictoryPoints(2 * player2.GetBuildedWonders().size());
	}
}

void GameLogic::MoneyLendersGuild(Player& player1, Player& player2)
{
	
	if (player1.GetMoney() > player2.GetMoney())
	{
		uint32_t money = player1.GetMoney();
		player1.SetMoney(money + money / 3);
	}
	if (player2.GetMoney() > player1.GetMoney())
	{
		uint32_t money = player2.GetMoney();
		player2.SetMoney(money + money / 3);

	}

}

uint32_t GameLogic::CountBuildingsByColor(Card::Color c, Player player1)
{
	uint32_t counterColor = 0;
	std::vector<Card> colors = player1.GetPlayerDeck2();
	counterColor = std::count_if(colors.begin(), colors.end(), [&c](Card i) {return i.GetColor() == c; });
	return counterColor;
}

void GameLogic::ComparingPlayersCardColor(Player& player1, Player& player2, Card::Color color)
{
	if (CountBuildingsByColor(color, player1) >
		CountBuildingsByColor(color, player2))
		player1.SetMoney(player1.GetMoney() + CountBuildingsByColor(color, player1));

	if (CountBuildingsByColor(color, player1) <
		CountBuildingsByColor(color, player2))
		player2.SetMoney(player2.GetMoney() + CountBuildingsByColor(color, player2));
}

void GameLogic::ShipownersGuild(Player& player1, Player& player2)
{
	ComparingPlayersCardColor(player1, player2, Card::Color::Grey);
	ComparingPlayersCardColor(player1, player2, Card::Color::Brown);
}

void GameLogic::ScientistGuild(Player& player1, Player& player2)
{
	ComparingPlayersCardColor(player1, player2, Card::Color::Green);
}

void GameLogic::TradersGuild(Player& player1, Player& player2)
{
	ComparingPlayersCardColor(player1, player2, Card::Color::Yellow);
}

void GameLogic::MagistratedGuild(Player& player1, Player& player2)
{
	ComparingPlayersCardColor(player1, player2, Card::Color::Blue);
}

void GameLogic::TacticiansGuild(Player& player1, Player& player2)
{
	ComparingPlayersCardColor(player1, player2, Card::Color::Red);
}

bool GameLogic::FindGuilCard(std::string C, Player player)
{
	for (auto index = 0; index < player.GetPlayerDeck2().size(); index++)
	{
		if (player.GetPlayerDeck2().at(index).GetCardName().find(C) != std::string::npos) {
			return true;
		}
	}
	return false;
}

void GameLogic::UseGuildCards(Player& player1, Player& player2)
{
	if (FindGuilCard("MONEYLENDERS GUILD", player1) == true || FindGuilCard("MONEYLENDERS GUILD", player2) == true)
	{
		MoneyLendersGuild(player1, player2);
	}

	if (FindGuilCard("TACTICIANS GUILD", player1) == true || FindGuilCard("TACTICIANS GUILD", player2) == true)
	{
		TacticiansGuild(player1, player2);
	}

	if (FindGuilCard("SCIENTISTS GUILD", player1) == true || FindGuilCard("SCIENTISTS GUILD", player2) == true)
	{
		ScientistGuild(player1, player2);

	}
	if (FindGuilCard("MAGISTRATES GUILD", player1) == true || FindGuilCard("MAGISTRATES GUILD", player2) == true)
	{
		MagistratedGuild(player1, player2);

	}
	if (FindGuilCard("BUILDERS GUILD  ", player1) == true || FindGuilCard("BUILDERS GUILD  ", player2) == true)
	{
		BuildersGuild(player1, player2);

	}
	if (FindGuilCard("SHIPOWNERS GUILD", player1) == true || FindGuilCard("SHIPOWNERS GUILD", player2) == true)
	{

		ShipownersGuild(player1, player2);
	}
	if (FindGuilCard("MERCHANTS GUILD ", player1) == true || FindGuilCard("MERCHANTS GUILD ", player2) == true)
	{
		TradersGuild(player1, player2);

	}
}

void GameLogic::ShowingWonderCardCost(WonderCardModel wonderCard)
{
	std::cout << wonderCard.GetCardName() << "  -> Cost: ";
	for (auto cost : wonderCard.GetCost())
	{
		std::cout << cost << " ";
	}
}

bool GameLogic::BuildWonderCard(Player& p1, Player p2, WonderCardDeck wonderDeck, WonderCardModel wonderCard)
{
	bool ok = false;
	while (ok == false)
	{
		try {
			std::cout << "\n" << "Do you want to buy/build the wonder?\n";

			std::string chose;
			std::cin >> chose;
			if (chose == "YES") {
				if (BuyingCard(wonderCard, p1, p2, wonderDeck) == true)
				{
					std::cout << "\n" << player1.GetName() << " have built " << wonderCard.GetCardName() << "!\n";
					p1.SetBuildedWonders(wonderCard);
					return true;
				}
				else
				{
					throw"You don't have enough resources to build the wonder.\n";
					return true;
				}
			}
			else if (chose == "NO")
			{
				return false;
			}
			else
			{
				std::cout << "Invalid option.";
			}
		}
		catch (const char* error)
		{
			std::cout << error << std::endl;
		}
	}
}

void GameLogic::TheAppianWay(Player& player1, Player& player2, bool& extraTurn)
{
	player1.AddMoney(3);
	player2.DecreaseMoney(3);
	player1.SetVictoryPoints(3);
	extraTurn = true;
}

void GameLogic::CircusMaximus(Board &b,Player& player1, Player& player2)
{
	player1.SetMilitarryPoints(1);
	if (player1.GetDirection() == true)
		b.SetConflictPawn(b.GetPownPosition() - 1, b);
	if (player1.GetDirection() == false)
		b.SetConflictPawn(b.GetPownPosition() + 1, b);
	player1.SetVictoryPoints(3);
}

void GameLogic::TheColossus(Board &b,Player& player)
{
	player.SetVictoryPoints(3);
	player.SetMilitarryPoints(2);
	if (player1.GetDirection() == true)
		b.SetConflictPawn(b.GetPownPosition() - 2, b);
	if (player1.GetDirection() == false)
		b.SetConflictPawn(b.GetPownPosition() + 2, b);
}

void GameLogic::TheGreatLibrary(Player& player)
{
	player.SetVictoryPoints(4);
}

void GameLogic::TheGreatLightHouse(Player& player)
{
	ValidResourceChosen(player);
}

void GameLogic::TheMausoleum(Player& player1)
{
	player1.SetVictoryPoints(2);
}

void GameLogic::Piraeus(Player& player, bool& extraTurn)
{
	ChoseManufacturedGood(player);
	player.SetVictoryPoints(2);
	extraTurn = true;
}

void GameLogic::ThePyramids(Player& player)
{
	player.SetVictoryPoints(9);
}

void GameLogic::TheSphinx(Player& player, bool& extraTurn)
{
	player.SetVictoryPoints(6);
	extraTurn = true;
}

void GameLogic::TheStatueOfZeus(Board&b,Player& player)
{
	player.SetMilitarryPoints(1);
	if (player1.GetDirection() == true)
		b.SetConflictPawn(b.GetPownPosition() - 1, b);
	if (player1.GetDirection() == false)
		b.SetConflictPawn(b.GetPownPosition() + 1, b);
	player.SetVictoryPoints(3);
}

void GameLogic::TheTempleOfArtemis(Player& player, bool& extraTurn)
{
	player.AddMoney(12);
	extraTurn = true;
}

void GameLogic::TheHangingGardens(Player& player, bool& extraTurn)
{
	player.AddMoney(6);
	player.SetVictoryPoints(3);
	extraTurn = true;
}

void GameLogic::UseWonderCard(Board &board,Player& player1, Player& player2, WonderCardModel wonderCard, bool& extraTurn)
{
	if (wonderCard.GetCardName() == "PIRAEUS")
	{
		Piraeus(player1, extraTurn);
	}
	if (wonderCard.GetCardName() == "CIRCUS MAXIMUS")
	{
		CircusMaximus(board, player1, player2);
	}
	if (wonderCard.GetCardName() == "THE GREAT LIGHTHOUSE")
	{
		TheGreatLightHouse(player1);
	}
	if (wonderCard.GetCardName() == "TEMPLE OF ARTEMIS") {
		TheTempleOfArtemis(player1, extraTurn);
	}
	if (wonderCard.GetCardName() == "THE APPIAN WAY") {
		TheAppianWay(player1, player2, extraTurn);
	}
	if (wonderCard.GetCardName() == "THE COLOSSUS") {
		TheColossus(board, player1);
	}
	if (wonderCard.GetCardName() == "THE GREAT LIBRARY") {
		TheGreatLibrary(player1);
	}
	if (wonderCard.GetCardName() == "THE HANGING GARDENS") {
		TheHangingGardens(player1, extraTurn);
	}
	if (wonderCard.GetCardName() == "THE STATUE OF ZEUS") {
		TheStatueOfZeus(board, player1);
	}
	if (wonderCard.GetCardName() == "THE MAUSOLEUM") {
		TheMausoleum(player1);
	}
	if (wonderCard.GetCardName() == "THE PYRAMIDS") {
		ThePyramids(player1);
	}
	if (wonderCard.GetCardName() == "THE SPINX") {
		TheSphinx(player1, extraTurn);
	}
}

bool GameLogic::VerifyWonderCardCost(Board& b,Player& p1, Player &p2, WonderCardDeck wonderDeck, bool& extraTurn)
{
	bool ok = false;
	wonderDeck.PopulateDeck();
	for (auto wonderCard : p1.GetWonderCards())
	{
		ShowingWonderCardCost(wonderCard);
			try 
			{
				if (BuildWonderCard(p1, p2, wonderDeck, wonderCard) == true)
				{
					UseWonderCard(b,p1, p2, wonderCard, extraTurn);
					return true;
				}
			}
			catch (const char* error)
			{
				std::cout << error;
				return false;
			}
	}
	std::cout<<"Please select another card : ";
	return false;
}

void GameLogic::ChosingWonderCards()
{
	system("cls");
	wonderDeck.PopulateDeck();
	wonderDeck.ShuffleInCards();
	std::reference_wrapper<Player> pickingPlayer = player1;
	std::reference_wrapper<Player> placingPlayer = player2;
	uint32_t rows = 0;
	std::cin.ignore();
	while (rows < 2)
	{
		wonderDeck.FaceingFourWonderCards();
		std::cout << "\n" << pickingPlayer << ", you should pick a wonder card:  ";
		WonderCardModel wonderCard;
		while (true)
		{
			try
			{
				std::string name;
				std::getline(std::cin, name);
				wonderCard = std::move(pickingPlayer.get().PickWonderCards(name, wonderDeck));
				wonderDeck.EraseCardsFromVector(name);

				break;
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}
		}
		std::cout << "\n" << placingPlayer << ", you should pick a wonder card:  ";
		while (true)
		{
			try
			{
				std::string name;
				std::getline(std::cin, name);

				wonderCard = std::move(placingPlayer.get().PickWonderCards(name, wonderDeck));
				wonderDeck.EraseCardsFromVector(name);

				break;
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}
		}
		std::cout << "\n" << placingPlayer << ", you should pick a wonder card:  ";
		while (true)
		{
			try
			{
				std::string name;
				std::getline(std::cin, name);

				wonderCard = std::move(placingPlayer.get().PickWonderCards(name, wonderDeck));

				wonderDeck.EraseCardsFromVector(name);

				break;
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}
		}
		std::cout << "\n" << pickingPlayer << ", recive last wonder card  " << wonderDeck.GetDeck().at(0).GetCardName() << "\n";
		while (true)
		{
			try
			{
				wonderCard = std::move(pickingPlayer.get().PickWonderCards(wonderDeck.GetDeck().at(0).GetCardName(), wonderDeck));
				std::string lastCard = wonderDeck.GetDeck().at(0).GetCardName();
				wonderDeck.EraseCardsFromVector(lastCard);

				break;
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}
		}
		rows++;
		std::swap(pickingPlayer, placingPlayer);
	}
}

void GameLogic::ShowingWonderCostAndResources(Player player1)
{
	for (auto wonder : player1.GetWonderCards())
	{
		ShowingWonderCardCost(wonder); std::cout << "\n";
	}
	std::cout << "\n";
}

bool GameLogic::ScientificVictory(Player player)
{
	std::vector<Symbols::Symbol> s = player.GetSymbols();
	std::sort(s.begin(), s.end());
	uint32_t differentSymbols = 0;
	std::vector<uint32_t>::const_iterator it;
	auto i = std::unique(s.begin(), s.end());
	s.erase(i, s.end());
	if (s.size() == 6)
		return true;
	return false;
}

bool GameLogic::MilitaryVictory(Board b)
{
	if (b.PawnPosition(b) == "Game Over!")
		return true;
	return false;
}

void GameLogic::ChosingAgeCards()
{
	board.SetBoard();
	
	std::reference_wrapper<Player> activePlayer = player1;
	std::reference_wrapper<Player> inactivePlayer = player2;
	uint64_t i = 0;
	bool ok = false;


	while (ok == false)
	{
		system("cls");
		std::cout << board << std::endl;
		std::cout << progressTokens;
		extraTurn = false;
		if (i < 20)
			PlayAge(firstPlacement,age1, activePlayer, inactivePlayer, board, progressTokens, extraTurn);
		if (i >= 20 && i < 40)
		{
			PlayAge(secondPlacement,age2, activePlayer, inactivePlayer, board, progressTokens, extraTurn);
		}
		if (i >= 40 && i < 60)
			PlayAge(thirdPlacement,age3, activePlayer, inactivePlayer, board, progressTokens, extraTurn);

		if (ScientificVictory(activePlayer) == true)
		{
			system("cls");
			std::cout << "\n				Scientific Victory!\n\n\n\n";
			std::cout << "					Congratulations," << activePlayer.get().GetName() << "!\n					You won the game!\n\n\n\n\n\n\n\n\n\n";
			break;
		}
		if (MilitaryVictory(board) == true)
		{
			system("cls");
			std::cout << "\n\n			" << board << "\n";
			std::cout << "\n					Military Victory!\n\n\n\n";
			std::cout << "					Congratulations," << activePlayer.get().GetName() << "!\n					You won the game!\n\n\n\n\n\n\n\n\n\n";
			break;
		}
		if (i == 60)
		{

			system("cls");			
			std::cout << "\n\n				Civilian Victory!\n\nNow let's count the victory points!";
			std::cout << "\nThe conflict pawn is on the position " << board.GetPownPosition();
			UseGuildCards(activePlayer, inactivePlayer);
			if (board.GetPownPosition() > 9)
			{
				if (board.GetPownPosition() == 10 || board.GetPownPosition() == 11)
					activePlayer.get().SetVictoryPoints(2);
				else if (board.GetPownPosition() == 12 || board.GetPownPosition() == 13 || board.GetPownPosition() == 14)
					activePlayer.get().SetVictoryPoints(5);
				else if (board.GetPownPosition() == 15 || board.GetPownPosition() == 16 || board.GetPownPosition() == 17)
					activePlayer.get().SetVictoryPoints(10);
			}
			else if (board.GetPownPosition() < 9)
			{
				if (board.GetPownPosition() == 8 || board.GetPownPosition() == 7)
					inactivePlayer.get().SetVictoryPoints(2);
				else if (board.GetPownPosition() == 6 || board.GetPownPosition() == 5 || board.GetPownPosition() == 4)
					inactivePlayer.get().SetVictoryPoints(5);
				else if (board.GetPownPosition() == 3 || board.GetPownPosition() == 2 || board.GetPownPosition() == 1)
					inactivePlayer.get().SetVictoryPoints(10);
			}
			activePlayer.get().SetVictoryPoints(activePlayer.get().GetMoney() / 3);
			inactivePlayer.get().SetVictoryPoints(inactivePlayer.get().GetMoney() / 3);
			std::cout << "\n" << activePlayer.get().GetName() << " has " << activePlayer.get().GetVictoryPoints();
			std::cout << "\n" << inactivePlayer.get().GetName() << " has " << inactivePlayer.get().GetVictoryPoints();

			if (activePlayer.get().GetVictoryPoints() > inactivePlayer.get().GetVictoryPoints())
			{
				std::cout << "\nCongratulations," << activePlayer.get().GetName() << "!\n You won the game!\n";
				break;
			}
			if (activePlayer.get().GetVictoryPoints() < inactivePlayer.get().GetVictoryPoints())
			{
				std::cout << "\nCongratulations," << inactivePlayer.get().GetName() << "!\n You won the game!\n";
				break;
			}
			if (activePlayer.get().GetVictoryPoints() == inactivePlayer.get().GetVictoryPoints())
			{
				std::cout << "\nDraw!\n";
				break;
			}
		}
		i++;
		if (extraTurn == false)
			std::swap(activePlayer, inactivePlayer);
	}
}
