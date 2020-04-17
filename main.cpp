/*****************************************
* Filename : main.cpp
* Creator : Soni, Vijay
* Date : 2018-04-13
*****************************************/
#include "Character.h"


int main()
{
	Character* pHero = new Character(40, 1, 0, "Hero");
	Character* pOrca = new Character(7, 1, 1300, "Orca");
	Character* pDragon = new Character(20, 3, 2600, "Dragon");

	while (pHero->getHealth() != 0)
	{
		pHero->toAttack(pDragon);
		pHero->toAttack(pOrca);

		pDragon->toAttack(pHero);
		pHero->toAttack(pDragon, 2);

		pOrca->toAttack(pHero);
		pHero->toAttack(pOrca, 2);

		if (pDragon->getHealth() == 0 && pOrca->getHealth() == 0)
		{
			std::cout << "Hero wins, Hurray! \n";
			pHero->setHealth(0);
		}
		else if (pHero->getHealth() == 0)
		{
			std::cout << "Game over, Hero looses! \n";
			pHero->setHealth(0);

		}
	}
	   	 

	delete pHero;
	delete pDragon;
	delete pOrca;

	return 0;
}
