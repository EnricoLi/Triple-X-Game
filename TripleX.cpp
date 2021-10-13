#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    cout << "\n\nYou are a secret agent braking into a level " << Difficulty;
    cout << " secure server rom...\nEnter the correct code to continue...\n\n";
}

bool PlayGame (int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declare 3 numbers code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    cout << "+ There are 3 numbers in the code";
    cout << "\n+ The codes add-up to: " << CodeSum;
    cout << "\n+ The codes multiply to give: " << CodeProduct << endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n*** Well done agent! You have extracted a file! Keep going ***";
        return true;
    }
    else
    {
        cout << "\nYou entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // Clears any erros
        cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;

        }
    }
    cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n"; 
    return 0;
}