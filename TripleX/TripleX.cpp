#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	// Print welcome message to the terminal 
	std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print sum and product to the terminal
	std::cout << std::endl;
	std::cout << "+ There are 3 numbers in the code\n";
	std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
	std::cout << "+ The codes product-up to: " << CodeProduct << std::endl;

	// Store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if the players guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
		return true;
	}
	else
	{
		std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
		return false;
	}
}



int main()
{
	srand(time(NULL)); // Create new random sequence based on time of day

	int LevelDifficulty = 1;
	const int MaxDifficulty = 10;

	while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete) 
		{
			// increase the level difficulty
			++LevelDifficulty;
		}
	}
	std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
	return 0;
}