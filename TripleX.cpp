#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\n##########################################################\n";
    std::cout << "You are a secret agent breaking into a Level " << Difficulty;
    std::cout << " secure server room.\nEnter the correct code to continue...\n";
    std::cout << "##########################################################\n\n";
}

void PrintHints(int codeSum, int codeProduct)
{
    std::cout << "+ There are 3 numbers in the code.";
    std::cout << "\n+ The codes add-up to: " << codeSum;
    std::cout << "\n+ The codes multply to give: " << codeProduct;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintHints(CodeSum, CodeProduct);

    // Store player guess
    int GuessA;
    int GuessB;
    int GuessC;
    std::cout << "\n\nPlease enter your guess by typing one number at a time seperated by a space: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nAccess Status: *Granted*";
        std::cout << "\nNext Level Unlocked! Keep moving forward.";
        return true;
    }
    else
    {
        std::cout << "\nAccess Status: *Denied*";
        std::cout << "\nReturning to previous level... try again...";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n####################################################################################";
    std::cout << "\nCongratulations you have broken through each secure server and obtained the package.";
    std::cout << "\n####################################################################################";

    return 0;
}