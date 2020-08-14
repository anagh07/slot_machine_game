#include "SlotMachine.h"

#include <array>

string SlotMachine::display()
{
	/*int tWon;*/
	string status;
	// infer win-loss based on reel shapes and size

	// 3x bet: 2 equal shapes and 2 equal screen areas
	if (((reel[0]->getName()) == (reel[1]->getName())) || ((reel[0]->getName()) == (reel[2]->getName())) || ((reel[1]->getName()) == (reel[2]->getName())) && ((reel[0]->getScreenArea()) == (reel[1]->getScreenArea())) || ((reel[0]->getScreenArea()) == (reel[2]->getScreenArea())) || ((reel[1]->getScreenArea()) == (reel[2]->getScreenArea())))
	{
		tWon = 3 * bet;
		currentTCount = currentTCount+ tWon;
		cout << "(" << reel[0]->getName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") "
			<< "(" << reel[1]->getName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") "
			<< "(" << reel[2]->getName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ")" << endl;
		cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas\n"
			<< "Congratulations! you win 3 times your bet: " << tWon << "\n"
			<< "You now have " << currentTCount << " tokens" << endl;
		status = "win";
	}

	// 2x bet: 3 same shape
	else if (((reel[0]->getName()) == (reel[1]->getName())) && ((reel[1]->getName()) == (reel[2]->getName())))
	{
		tWon = 2 * bet;
		currentTCount = currentTCount + tWon;
		cout << "(" << reel[0]->getName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") "
			<< "(" << reel[1]->getName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") "
			<< "(" << reel[2]->getName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ")" << endl;
		cout << "Three similar shapes\n"
			<< "Congratulations! you win 2 times your bet: " << tWon << "\n"
			<< "You now have " << currentTCount << " tokens" << endl;
		status = "win";
	}

	// 1x bet: screen area: middle symbol > sum(left, right) sumbols
	else if ((reel[1]->getScreenArea()) > ((reel[0]->getScreenArea()) + (reel[2]->getScreenArea())))
	{
		tWon = bet;
		currentTCount = currentTCount + tWon;
		cout << "(" << reel[0]->getName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") "
			<< "(" << reel[1]->getName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") "
			<< "(" << reel[2]->getName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ")" << endl;
		cout << "Middle > Left + Right, in Screen Areas\n"
			<< "Congratulations! you win your bet: " << tWon << "\n"
			<< "You now have " << currentTCount << " tokens" << endl;
		status = "win";
	}

	// 0x bet: left and right shape similar
	else if ((reel[0]->getName()) == (reel[2]->getName()))
	{
		tWon = 0;
		currentTCount = currentTCount + tWon;
		cout << "(" << reel[0]->getName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") "
			<< "(" << reel[1]->getName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") "
			<< "(" << reel[2]->getName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ")" << endl;
		cout << "Lucky this time!\n"
			<< "You don't win, you don't lose, you are safe!\n"
			<< "You now have " << currentTCount << " tokens" << endl;
		status = "safe";
	}

	// -1x bet: lose otherwise
	else 
	{
		tWon = (-1) * bet;
		currentTCount = currentTCount + tWon;
		cout << "(" << reel[0]->getName() << ", " << reel[0]->getBoxHeight() << ", " << reel[0]->getBoxWidth() << ") "
			<< "(" << reel[1]->getName() << ", " << reel[1]->getBoxHeight() << ", " << reel[1]->getBoxWidth() << ") "
			<< "(" << reel[2]->getName() << ", " << reel[2]->getBoxHeight() << ", " << reel[2]->getBoxWidth() << ")" << endl;
		cout << "Oh No!\n"
			<< "You lose your bet\n"
			<< "You now have " << currentTCount << " tokens" << endl;
		status = "lose";
	}

	if (currentTCount > 0)
	{
		cout << "How much would you like to bet (enter 0 to quit)? " << endl;
		cin >> bet;

		while (bet > currentTCount)
		{
			cout << "You can't bet more than " << currentTCount << ", try again!" << endl;
			cout << "How much would you like to bet (enter 0 to quit)? " << endl;
			cin >> bet;
		}
	}
	return status;
}

void SlotMachine::make_shapes()
{
	int ran_num, width, height;

	for (int i = 0; i < 3; i++)
	{
		ran_num = rand() % 4;
		width = rand() % 25 + 1;

		if (ran_num == 0)
			reel[i].reset(new Rhombus(width));
		else if (ran_num == 1)
			reel[i].reset(new AcuteTriangle(width));
		else if (ran_num == 2)
			reel[i].reset(new RightTriangle(width));
		else
		{
			height = rand() % 25 + 1;
			reel[i].reset(new Rectangle(width, height));
		}
		cout << reel[i]->draw();
	}
	cout << endl;
}

void SlotMachine::run()
{
	string buffer;

	buffer.append("\n");
	buffer.append("\n");
	buffer.append("Welcome to 3-Reel Lucky Slot Machine Game!\n");
	buffer.append("Each real will randomly display one of four shapes, each in 25 sizes.\n");
	buffer.append("To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas\n");
	buffer.append("To win 2 x bet, get 3 similar shapes\n");
	buffer.append("To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas\n");
	buffer.append("To win or lose nothing, get same left and Right Shapes.\n");
	buffer.append("Otherwise, you lose your bet.\n");
	buffer.append("You start with 10 free slot tokens!\n");
	buffer.append("\n");

	cout << buffer << endl;

	// Variables needed for algo
	string res;
	//int bet;

	cout << "Do you have slot token? \nEnter Y for yes or any other alphabet for no" << endl;
	cin >> res;

	if (res[0] == 'Y' || res[0] == 'y')
	{
		cout << "Enter total token count:" << endl;
		cin >> currentTCount;
	}
	else
	{
		currentTCount = 10;
	}

	cout << "You have a total of " << currentTCount << " tokens" << endl;

	cout << "How much would you like to bet (enter 0 to quit)? " << endl;
	cin >> bet;

	// Check to see if bet > token count
	while (bet > currentTCount)
	{
		cout << "You can't bet more than " << currentTCount << ", try again!" << endl;
		cout << "How much would you like to bet (enter 0 to quit)? " << endl;
		cin >> bet;
	}

	// break loop if quit/out of token
	while (currentTCount > 0 && bet != 0)
	{
		make_shapes();
		display();
	}
}