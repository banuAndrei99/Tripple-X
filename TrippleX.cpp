#include <iostream>
#include <ctime>


void PlayIntro(){
    std:: cout << "You are a secret agent trying to brake into the last floor of an evil corporation's building.";
    std:: cout << std:: endl;
    std:: cout << "The only way to get to the top is to unlock the elevator which requires a different 3 digit code on each level.";
}

void PlayOutro(bool Winning){
    if ( Winning ){
        std:: cout << "GGs, you've beaten the game!";
    }
    else{
        std:: cout << "You entered the wrong code which triggered a trap door. You died...";
    }
}

bool PlayLevel(int Difficulty){
    const int CodeA = Difficulty + rand() % Difficulty;
    const int CodeB = Difficulty + rand() % Difficulty;
    const int CodeC = Difficulty + rand() % Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std:: cout << "You are on level " << Difficulty << " and you know that:\n";
    std:: cout << "The 3 digit code sum is: " << CodeSum;
    std:: cout << std:: endl;
    std:: cout << "The 3 digit code product is: " << CodeProduct;
    std:: cout << std:: endl;
    std:: cout<< "Enter your guesses:\n";

    int GuessA, GuessB, GuessC;
    std:: cin >> GuessA >> GuessB >> GuessC;
    std:: cin.clear();
    std:: cin.ignore();

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}


int main(){
    srand(time(NULL));

    int CurrentLevel = 0;
    const int MAX_LEVEL = 10;


    bool CorrectGuess = true;
    PlayIntro();
    while ( CorrectGuess && CurrentLevel <= MAX_LEVEL){
        CurrentLevel ++;
        CorrectGuess = PlayLevel(CurrentLevel);
    }
    PlayOutro(CurrentLevel == MAX_LEVEL);
    return 0;
}