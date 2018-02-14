#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playcard (int& card, int& playhand);
void dealcard (int& card);
void playing (char& play, bool& keep_playing);
void reset (int& playhand, int& dealhand);
void hit_stick (char& action);
void result (int& playhand, int& dealhand);

int playhand = 0;
int dealhand = 0;
int card = 0;
char play = 'y';
char action = 'h';
bool keep_playing = true;

int main ()
{
	srand(time(NULL));
	cout << "This is a game of Blackjack.\n";
	cout << "Beat the dealer's hand and you win!\n";
	cout << "Draws go to the dealer.\n";
	cout << endl;
		
	while (keep_playing==true)
	{
		cout << "The Dealer gives you two cards.\n";
		playcard (card, playhand);
		cout << "Your first card is a : " << card << endl;
		playcard (card, playhand);
		cout << "Your second card is a : " << card << endl;
		cout << "Your total is " << playhand << endl;
		cout << "The Dealer has " << dealcard << endl;
		//cout << "Would you like to keep playing, Y/N? ";
		//cin >> play;
		//cout << endl;
		//playing(play, keep_playing);
		cout << "Would you like to hit or stick?\n";
		cout << "Enter H to hit or S to stick: ";
		cin >> action;
		hit_stick (action);
		cout << endl;
	}
	return 0;
}

void playcard (int& card, int& playhand)
{
	card = (rand() % 12 + 1);
	playhand = card + playhand;
}

void dealcard (int& card, int& dealhand)
{
	card = (rand() % 12 + 1);
	dealhand = card + dealhand;
}

void playing(char& play, bool& keep_playing)
{
	if ((play == 'n') || (play == 'N')){
		keep_playing=false;
	}
	else if ((play == 'y') || (play == 'Y')){
		keep_playing=true;
		reset (playhand, dealhand);
	}
	else{
	cout << "Invalid option: Type Y/N: ";
	cin >> play; 
	cout << endl;
	playing(play, keep_playing);
	}
}

void reset (int& playhand, int& dealhand)
{
	playhand = 0;
	dealhand = 0;
}

void hit_stick (char& action)
{
	if ((action == 'H') || (action == 'h')){
		cout << "You hit and receive another card!\n";
		playcard (card, playhand);
		cout << "Your next card is a " << card << ".\n";
		cout << "Your new total is " << playhand<< ".\n";
		if (playhand <=21) {
			cout << "It's still your turn, Hit or Stick? ";
			cin >> action;
			hit_stick (action);
		}
		else if (playhand > 21){
			cout << "Ouch, that's a bust... Dealer wins by default.\n";
			cout << "Would you like to play again, Y/N?";
			cin >> play;
			cout << endl;
			playing(play, keep_playing);
		}
	
	}
	else if ((action == 'S') || (action == 's')){
		cout << "You're sticking with what you have.\n";
		cout << "Dealers turn.\n";
		cout << "Dealer gets another card\n";
		playcard (card, dealhand);
		cout << "Dealer's second card is a " << card << ".\n";
		while (dealhand <= 16){
			cout << "Dealer is going to hit!\n";
			playcard (card, dealhand);
		}
		if (dealhand >= 17){
			cout << "Dealer is going to stick.\n";
			cout << "Time to determine the victor...\n";
			result (playhand, dealhand);
		}
		else if (dealhand <22){
			cout << "The Dealer has busted!\n";
			cout << "Looks like you win!!!\n";
			cout << "Would you like to play again, Y/N? ";
			cin >> play;
			cout << endl;
			playing(play, keep_playing);
		}
			}
	else{
		cout << "Invalid option: Key H/h to hit or S/s to stick\n";
		cin >> action;
		cout << endl;
		hit_stick (action);
	}
}
void result (int& playhand, int& dealhand)
{
	cout << "Your final count is " << playhand << endl;
	cout << "The dealer's final count is " << dealhand << endl;
	if (playhand > dealhand){
		cout << "You've got the better hand!\n";
		cout << "Congratulations! You Win!!!!\n";
		cout << "Would you like to play again, Y/N? ";
		cin >> play;
		cout << endl;
		playing(play, keep_playing);
	}
	else if (playhand < dealhand){
		cout << "The Dealer has the better hand!\n";
		cout << "Sorry friend, better luck next time...";
		cout << "Would you like to play again, Y/N? ";
		cin >> play;
		cout << endl;
		playing(play, keep_playing);
	}
	else if (playhand = dealhand){
		cout << "It's a draw, which means the dealer is the winner!\n";
		cout << "Sorry friend, better luck next time...";
		cout << "Would you like to play again, Y/N? ";
		cin >> play;
		cout << endl;
		playing(play, keep_playing);
	}
}