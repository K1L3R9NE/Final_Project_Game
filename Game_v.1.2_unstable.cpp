#include <iostream>
#include <string>  // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>   // Needed to use time for randomize
#define TAB ' '	   // To do small TABs
using namespace std;

//PLAYER
class PLAYER
{	public:
		string Name;
		float Balance;
		float Offer;
	};

//PLAYER OPPONENT (PC / BOT)
class BOT
{
	public:
		string Name;
		float Balance;
		float Offer;
};

//SYSTEM & VALUES
class SYSTEM
{
	public:
		const int sizeline = 100;	//width of feld for game
		int posX = sizeline / 2;	//automatic poxX 
		float RandBotBalance;		//to randomize Bot Balance
		float TotalOffer;
		int dice;
		int dice1;
		float rand2;
		int posX;
		int posZ;
};

string RandomName()
{		
	const int SIZE = 20;
	string Name[SIZE] = {"Andriy", "Anna", "Benedict", "Christopher", "Carol", "Daniel", "Elizabet", "Franklin", "Georgia", "Lisa", "Sofia", "Shasha", "Max", "Tom", "Tony", "Amelia", "Josh", "Oleg", "Nastya", "Linda"};
	int dice;
	dice = rand() % SIZE + 1;
	return Name[dice];
}

void Rules()
{
	cout << "\n\t\t//-------Welcome in our GRAND de CASINO-------//\t\t" << endl;
	cout << "\n\t\t//-------------Soo.. How to play?-------------//\t\t" << endl;
	cout << "\n\t\t//-------------1. Enter your name-------------//\t\t" << endl;
	cout << "\n\t\t//-----------2. Enter your $ balance----------//\t\t" << endl;
	cout << "\n\t//#. Your oponent generate random Name and Balance//\t\t" << endl;
	cout << "\n\t\t//-----------#. Now you can to play-----------//\t\t" << endl;
	cout << "\n\t\t//------------3. Enter your offer-------------//\t\t" << endl;
	cout << "\n\t\t//------------4. Enter ZERO or ONE------------//\t\t" << endl;
	cout << "\n//#. Your oponent generate random offer that near your//\t\t" << endl;
	cout << "\n\t\t//--------------#. See the Game---------------//\t\t" << endl;
	cout << "\n\t//5. Take a money if you win or lost them if you lost//\t\t" << endl;
	cout << "\n\t\t//-------6. And repeat it until you win!------//\t\t" << endl;
	cout << "\n\t\t//---------------#. Good Luck!----------------//\t\t" << endl;
}

bool Lose(float PlayerBalance) 
{
	if (PlayerBalance <= 0)
	{
		cout << "Sorry but you lose, your balance is 0$ or less" << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Win(float BotBalance)
{
	if (BotBalance <= 0)
	{
		cout << "YES! You WIN!!!" << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}

	

int main()
{
	PLAYER Player;
	BOT Bot;
	SYSTEM System_One;

	srand(time(0));

	Rules();

	//name
	cout << "\n\t\t\t\tEnter your name : " << endl;
	cout << "\t\t\t\t";
	getline(cin, Player.Name);
	cout << "\t\t\t\tOk, hello Mr " << Player.Name << endl << endl;

	//player balance
	cout << Player.Name << " ,please enter your balance $ ";
	cin >> Player.Balance;
	cout << "Ok your balance is " << Player.Balance << "$" << endl << endl;


	//pc balance
	System_One.RandBotBalance = rand() % 12 + 8;
	Bot.Balance = Player.Balance * (System_One.RandBotBalance / 10);
	cout << Bot.Name << " balance is " << Bot.Balance << "$" << endl << endl;
	    
	//gameplay
	while ( !Lose(Player.Balance) || !Win(Bot.Balance) )
	{   

		cout << "Enter your offer" << endl;
		cin >> Player.Offer;
		if (Player.Offer >= Player.Balance || Player.Offer <= 0)
		{
			cout << "Your offer is too big," << endl;
			cout << "Please try again, and remember that your offer should be more that zero and less that your balance" << endl;
		}

		Player.Balance = Player.Balance - Player.Offer;
		cout << "Your balance is " << Player.Balance << "$" << endl;
		cout << "Your offer is " << Player.Offer << "$" << endl;

		//pc offer
		if (Bot.Balance - (Player.Offer * 0.8) < 0)
		{
			Bot.Balance = Bot.Balance - (Player.Offer / 4);
			Player.Offer = Player.Offer + (Player.Offer / 4);
			cout << "Total offer is " << Player.Offer << endl;
		}

		Bot.Balance = Bot.Balance - (Player.Offer * 0.8);
		Player.Offer = Player.Offer + (Player.Offer * 0.8);
		cout << "Total offer is " << System_One.TotalOffer << endl;

		//game
		cout << "OK, slect ONE(1) or ZERO(0)" << endl;
		cin >> System_One.dice1;

		if (System_One.dice1 > 1 || System_One.dice1 < 0)
		{
			System_One.dice1 = 0;
			cout << "You enter a wrong number!!" << endl;
			cout << "Try again!!" << endl;
			goto System;
		}


		while (true)
		{
			//check is you win or no
			if (System_One.posX == (System_One.sizeline - 1))
			{
				System_One.dice = 1;
				break;
			}
			else if (System_One.posX == 1)
			{
				System_One.dice = 0;
				break;
			}

			//start of line
			cout << "||ZERO||";


			System_One.posZ = rand() % 3 - 1;
			System_One.posX =+ System_One.posZ;
			for (int b = 0; b < System_One.posX; b++)
			{
				cout << TAB;
			}

			cout << Player.Name;

			for (int b = 0; b < (sizeline - posX); b++)
			{
				cout << TAB;
			}

			cout << " ||ONE||" << endl;
			//end of line

		}


		srand(time(0));
		if (System_One.dice1 == System_One.dice)
		{
			cout << "Ouuuu, you win, get your " << offer << " bucks" << endl;
			PlayerBalance = PlayerBalance + offer;
			cout << "Your balance is " << PlayerBalance << endl;
			cout << PCName << " balance is " << PCBalance << endl;
			offer = 0;
		}
		else
		{
			cout << "Ouuuu, you lose" << endl;
			PCBalance = PCBalance + offer;
			cout << "Your balance is " << PlayerBalance << endl;
			cout << PCName << " balance is " << PCBalance << endl;
			offer = 0;
		}


	}

	//lose
	if (PlayerBalance <= 1)
	{
		cout << "Sorry but you lose, your balance is 0$" << endl << endl;
		goto start;
	}

	//win
	if (PCBalance <= 1)
	{
		cout << "Heeeeyyyy, you WIN!!! Your balance  is" << PlayerBalance << "$" << endl << endl;
		goto start;
	}

}