#include <iostream>
#include <cmath>
using namespace std;

void playGame();
bool wantToPlayAgain();
bool isGameOver(int secretNumber, int numberOfTries, int guess);
int getGuess(int numberOfTries);
void displayResult(int numberOfTries , int secretNumber);

const int IGNORE_CHARS = 256;

int main(){

	do{
		playGame();
	}while(wantToPlayAgain());
	return 0;
}

void playGame(){
	const int UPPER_BOUND = 100;
	int secretNumber = 85;
	int numberOfTries = ceil(log2(UPPER_BOUND));
	int guess = 0;

	cout<<"The range of the number is between 0 and 100."<<endl;
	do{
	
		guess = getGuess(numberOfTries);

		if(guess != secretNumber){

			numberOfTries--;

			if(guess > secretNumber){
				cout<<"Your guess was too high!"<<endl;
			}else{
				cout<<"Your guess was too low!"<<endl;
			}

		}
	
	}while(!isGameOver(secretNumber,numberOfTries,guess));

	displayResult(numberOfTries,secretNumber);
}

bool wantToPlayAgain(){
	char input;
	bool failure;
	do{
		failure = false;
		cout<<"Do you want to play again? (y/n) " ;
		cin>>input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<"Input error! Please try again."<<endl;
			failure = true;
		}
	}while(failure);
	
	return input == 'y';
}
	

bool isGameOver(int secretNumber,int numberOfTries,int guess){
	return secretNumber ==  guess || numberOfTries <= 0;
}

int getGuess(int numberOfTries){

	int guess;
	bool failure;
	do{
		failure = false;
	cout<<"Please enter your guess ( number of guesses left : "<< numberOfTries<<" ) : ";
	cin>>guess;

	if(cin.fail()){
		cin.clear();
		cin.ignore(IGNORE_CHARS,'\n');
		cout<<"Input error! Please try again."<<endl;
		failure = true;
	}
	}while(failure);

	return guess;
}	

void displayResult(int numberOfTries , int secretNumber){

	if(numberOfTries > 0){
		cout<<"You got it! It was : "<<secretNumber<<endl;
	}else{
		cout<<"You didn't get it ... It was : " <<secretNumber<<endl;
	}
}
