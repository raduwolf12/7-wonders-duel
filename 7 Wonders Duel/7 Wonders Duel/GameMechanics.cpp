#include "GameMechanics.h"
GameMechanics::GameMechanics()
{

};



int GameMechanics::PlayTurn(Turn turn)
{
	switch (turn)
	{
	case GameMechanics::Turn::First:
	{ 

		break;
	}
	case GameMechanics::Turn::Second:
	{
		break;
	}
	case GameMechanics::Turn::Third:
	{
		break;
	}

	default:
		throw "No turn is currently taking place";
		break;
	}
	return 0;
}

bool GameMechanics::SetPlayerBoughtResource(Cost c, Player& player1, Player player2, int costCount, int resourcesCountPlayer)
{

	if (costCount > resourcesCountPlayer)
	{
		int differenceOfResource = costCount - resourcesCountPlayer;
		for (int i = 0; i < differenceOfResource; i++)
		{
			try {
				BuyingResource(c, player1, player2);
				switch (c.GetManufacturedGood().GetManufacturedGood())
				{
				case ManufacturedGoodsClass::ManufacturedGoods::Glass:
				{
					player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
					break;
				}
				case ManufacturedGoodsClass::ManufacturedGoods::Papirus:
				{
					player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
					break;
				}
				case ManufacturedGoodsClass::ManufacturedGoods::None:
				{break; }
				default:
					break;
				}
				switch (c.GetRawMaterial().GetRawMaterial())
				{
				case  RawMaterialsCLass::RawMaterials::None:
				{
					break;
				}
				case  RawMaterialsCLass::RawMaterials::Stone:

				{
					player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
					break;
				}
				case RawMaterialsCLass::RawMaterials::Wood:
				{
					player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
					break;
				}
				case RawMaterialsCLass::RawMaterials::Clay:
				{
					player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
					break;
				}
				default:
					break;
				}
				break;
			}
			catch (const char* error)
			{

				std::cout << error << std::endl;
				return false;
			}
			break;
			return true;


		}
	}
}

bool GameMechanics::BuyingResource(Cost cost, Player& player1, Player player2)
{
	auto enemyResource = [](Cost cost, Player player2) {
		int numberOfResource = 0;
		for (auto it : player2.GetResources())
		{
			if (cost.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass || cost.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
			{
				if (it.GetManufacturedGood().GetManufacturedGood() == cost.GetManufacturedGood().GetManufacturedGood())
				{
					numberOfResource++;
				}
			}
			if (cost.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone || cost.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood || cost.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay)
			{
				if (it.GetRawMaterial().GetRawMaterial() == cost.GetRawMaterial().GetRawMaterial())
				{
					numberOfResource++;
				}
			}
		}
		if (numberOfResource == 0)
			std::cout << "\nThe enemy doesn't have any resources from the wanted one!";
		else
			std::cout << "\nThe enemy have the resource in a quantity  " << numberOfResource << " pieces.";
		return numberOfResource; };
	int moneyRequired = 2 + enemyResource(cost, player2); //formula de calcul pt trading
	std::cout << "\nTo buy the reosurce are required " << moneyRequired << " coins.";

	std::cout << "\n" << player1.GetName() << " has " << player1.GetMoney() << " coins.";
	if (player1.GetMoney() >= moneyRequired) //pot cumpara cartea
	{

		player1.DecreaseMoney(moneyRequired);
		std::cout << "\n" << player1.GetName() << " has " << player1.GetMoney() << " coins.";
		std::cout << "\nSuccessfully purchased resource!\n";
		return true;
	}
	throw (player1.GetName() + std::string(" doesn't afford the resource."));

	//return false;
}

int GameMechanics::CountBuildingsByColor(Card::Color c, Player player1)
{
	int counterColor = 0;
	for (auto color : player1.GetPlayerDeck2())
	{
		if (color.GetColor() == c)
			counterColor++;
	}
	return counterColor;
}

int GameMechanics::CountRawMaterialsWood(Player player1)
{
	int counter = 0;
	for (auto itPla : player1.GetResources())
	{
			if (itPla.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood)
			{
				counter++;
			}
	}

	return counter;
}

int GameMechanics::CountRawMaterialsClay(Player player1)
{
	int counter = 0;
	for (auto itPla : player1.GetResources())
	{
		if (itPla.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay)
		{
			counter++;
		}
	}

	return counter;
}

int GameMechanics::CountRawMaterialsStone(Player player1)
{
	int counter = 0;
	for (auto itPla : player1.GetResources())
	{
		if (itPla.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone)
		{
			counter++;
		}
	}

	return counter;
}

int GameMechanics::CountMaterialsGoodsGlass(Player player1)
{
	int counter = 0;
	for (auto itPla : player1.GetResources())
	{
		if (itPla.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass)
		{
			counter++;
		}
	}

	return counter;
}

int GameMechanics::CountMaterialsGoodsPapirus(Player player1)
{
	int counter = 0;
	for (auto itPla : player1.GetResources())
	{
		if (itPla.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
		{
			counter++;
		}
	}

	return counter;
}



void GameMechanics::UseSign(Player& player1, Card c)
{	
		if (c.GetSign() == Signs::Sign::Barrel)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Book)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Column)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::HalfMoon)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Harp)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Helmet)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Horseshoe)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Lamp)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Mask)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Sun)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Sword)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Target)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Temple)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Tower)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Vessel)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::WaterDrop)
			player1.SetSign(c.GetSign());

		if (c.GetSign() == Signs::Sign::Wheel)
			player1.SetSign(c.GetSign());


}

bool GameMechanics::CountSymbolInPlayersDeck(Player& player1)
{
	
		int bol = 0;
		int feather = 0;
		int gyroscope = 0;
		int pendulum = 0;
		int solarClock = 0;
		int wheel = 0;
		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::Bol)
				bol++;
		}
		if (bol == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::Bol);
			return true;
		}

		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::Feather)
				feather++;
		}
		if (feather == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::Feather);
			return true;
		}

		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::Gyroscope)
				gyroscope++;
		}
		if (gyroscope == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::Gyroscope);
			return true;
		}
		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::Pendulum)
				pendulum++;
		}
		if (pendulum == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::Pendulum);
			return true;
		}
		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::SolarClock)
				solarClock++;
		}
		if (solarClock == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::SolarClock);
			return true;
		}

		for (auto symbol : player1.GetSymbols())
		{
			if (symbol == Symbols::Symbol::Wheel)
				wheel++;
		}
		if (wheel == 2) {
			player1.DeactivateSymbol(Symbols::Symbol::Wheel);
			return true;
		}

		return false;
	
}

void GameMechanics::SetSpecial(Player& player1, Card c)
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

bool GameMechanics::VerifyCardSign(Player& player1, Card c)
{
	for (auto card : player1.GetPlayerDeck2())
	{
		if (card.GetSign() == c.GetSign() && card.GetSign() != Signs::Sign::Null)
			return true;
	}
	return false;
	
}

void GameMechanics::UseCardSymbol(Player& player1, Card c)
{
	if (c.GetSymbol() == Symbols::Symbol::Bol)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
	if (c.GetSymbol() == Symbols::Symbol::Feather)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
	if (c.GetSymbol() == Symbols::Symbol::Gyroscope)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
	if (c.GetSymbol() == Symbols::Symbol::Pendulum)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
	if (c.GetSymbol() == Symbols::Symbol::SolarClock)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
	if (c.GetSymbol() == Symbols::Symbol::Wheel)
	{
		player1.SetSymbol(c.GetSymbol());
		player1.SetActiveSymbol(c.GetSymbol());
	}
}

void GameMechanics::PickToken(Player& player1, ActiveProgressTokens& progressTokens, std::string progressTokenName)
{
	std::cout << "\n\nYou own two cards with the same symbol; \nPlease chose a Progress Tokens from the following:\n";
	std::cout << progressTokens;
	bool ok = false;
	while (ok == false)
	{
		
		//std::cin >> progressTokenName;
		try {

			ProgressToken pr = FindProgressToken(progressTokenName, progressTokens);
			player1.SetProgressTokens(pr);
			/*Functor<void (*)(Player & player1)> f();
			f()(player1);*/
			UseProgressToken(player1, progressTokenName);
			//progressTokens.DiscardProgressToken(pr);
			ok = true;
		}
		catch (char* error)
		{
			std::cout << error;
		}
	}
}

ProgressToken GameMechanics::FindProgressToken(std::string C, ActiveProgressTokens progressTokens)
{
	for (auto index = 0; index < progressTokens.GetActiveProgressTokens().size(); index++)
	{
		ProgressToken p = progressTokens.GetActiveProgressTokens().at(index);
		
		if (p.GetScientificSymbol()._Equal(C)) {
			return progressTokens.GetActiveProgressTokens().at(index);
		}
	}
	throw "Invalid Token";
}

void GameMechanics::UseProgressToken(Player& player, std::string s)
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

