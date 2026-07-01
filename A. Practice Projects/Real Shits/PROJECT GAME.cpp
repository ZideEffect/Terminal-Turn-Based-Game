#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::string;

int moveset;
int randomNumber;
int DiceRoll;
int enemySelection;
int luck;

namespace player_data{
    string NAME;
    int HP = 1000;
    int ATK = 100;
    int HEAVY_ATK = 300;
}

namespace enemy_noob_data{
    string NAME = "Noob";
    int HP = 900;
    int ATK = 100;
    int HEAVY_ATK = 300;
}

namespace enemy_john_data{
    string NAME = "John";
    int HP = 800;
    int ATK = 110;
    int HEAVY_ATK = 200;
}

void sleep(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void generateRandomNumber(){
    srand(time(0));
    randomNumber = (rand() % 2) + 1;
}

void diceSystem(){
    srand(time(0));
    DiceRoll = (rand() % 4) + 1;

    switch (DiceRoll){
        case 1:
            cout << "You got 5 percent crit!\n";
            sleep();
            enemy_noob_data::HP -= player_data::ATK * 105/(double)100;
            enemy_john_data::HP -= player_data::ATK * 105/(double)100;
            break;
        case 2:
            cout << "You got 10 percent crit!\n";
            sleep();
            enemy_noob_data::HP -= player_data::ATK * 110/(double)100;
            enemy_john_data::HP -= player_data::ATK * 110/(double)100;
            break;
        case 3:
            cout << "You got 15 percent crit!\n";
            sleep();
            enemy_noob_data::HP -= player_data::ATK * 115/(double)100;
            enemy_john_data::HP -= player_data::ATK * 115/(double)100;
            break;
        case 4:
            cout << "You got 20 percent crit!\n";
            sleep();
            enemy_noob_data::HP -= player_data::ATK * 120/(double)100;
            enemy_john_data::HP -= player_data::ATK * 120/(double)100;
            break;
    }
}

void probabilitySystem(){
    srand(time(0));
    luck = (rand() % 3) + 1;

    switch(luck){
        case 1:
            cout << "Heavy Attack sucessfully proceeded!\n";
            sleep();
            enemy_noob_data::HP -= player_data::HEAVY_ATK;
            enemy_john_data::HP -= player_data::HEAVY_ATK;
            break;
        case 2:
            cout << "Heavy Attack unsecessfully Proceeded!\n";
            sleep();
            break;
        case 3:
            cout << "You hit yourself!\n";
            player_data::HP -= player_data::HEAVY_ATK;
    }
    sleep();
}

void gameResultsCheck(){
    sleep();
    cout << "---------------------------- RESULTS ----------------------------\n"
        << "------------- PLAYER -------------\n"
        << "NAME: " << player_data::NAME << '\n'
        << "HP: " << player_data::HP << '\n'
        << "ATK: " << player_data::ATK << '\n'
        << "------------- ENEMY -------------\n"
        << "NAME: " << enemy_noob_data::NAME << '\n'
        << "HP: " << enemy_noob_data::HP << '\n'
        << "ATK: " << enemy_noob_data::ATK << '\n';

    
    if(enemy_noob_data::HP <=0 || enemy_john_data::HP <=0){
            cout << "You win!\n";
            exit(EXIT_SUCCESS);
    }
    else if(player_data::HP <= 0){
            cout << "You lose!\n";
            exit(EXIT_SUCCESS);
    }
}

void gameplayNoob(){
    cout << "---------------------------- ENEMY' DATA ----------------------------\n"
        << "NAME: " << enemy_noob_data::NAME << '\n'
        << "HP: " << enemy_noob_data::HP << '\n'
        << "ATK: " << enemy_noob_data::ATK << '\n';

    sleep();
    cout << "Proceeding for gameplay...\n";
    sleep();

    for(int i = 5; i >= 1; i--){
        cout << i << '\n';
        sleep();
    }
    cout << "GO!\n";
    sleep();

    do{
        do{
            cout << "---------------------------- GAMEPLAY ----------------------------\n"
                << "1. Light Attack\n"
                << "2. Heavy Attack\n"
                << "Please, choose your next move (1/2): ";
            cin >> moveset;

            if(moveset <= 0 || moveset >= 3){
                cout << "Unavaiable moveset! Try again.\n";
                sleep();
            }
        }while (moveset <= 0 || moveset >= 3);

        if(moveset == 1){
            diceSystem();
            cout << "Enemy' health is now " << enemy_noob_data::HP << '\n';
        }
        else if(moveset == 2){
            probabilitySystem();
            cout << "Enemy' health is now " << enemy_noob_data::HP << '\n';
        }

        gameResultsCheck();

        sleep();
        cout << "The enemy is choosing his next moves..\n";
        sleep();

        generateRandomNumber();

        if(randomNumber == 1){
            srand(time(0));
            DiceRoll = (rand() % 4) + 1;

            switch (DiceRoll){
                case 1:
                    cout << "The Enemy got 5 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_noob_data::ATK * 105/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 2:
                    cout << "The Enemy got 10 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_noob_data::ATK * 110/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 3:
                    cout << "The Enemy got 15 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_noob_data::ATK * 115/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 4:
                    cout << "The Enemy got 20 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_noob_data::ATK * 120/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                }
            }
            
        else if(randomNumber == 2){
            srand(time(0));
            luck = (rand() % 3) + 1;

            switch(luck){
                case 1:
                    cout << "Noob's Heavy Attack sucessfully proceeded!\n";
                    sleep();
                    player_data::HP -= enemy_noob_data::HEAVY_ATK;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 2:
                    cout << "Noob's Heavy Attack unsecessfully Proceeded!\n";
                    sleep();
                    break;
                case 3:
                    cout << "Noob hit himself!\n";
                    enemy_noob_data::HP -= enemy_noob_data::HEAVY_ATK;
            }
            sleep();
        }

        sleep();
        cout << "Loading..\n";
        sleep();

        gameResultsCheck();

    }while(enemy_noob_data::HP > 0 || player_data::HP > 0);
}

void gameplayJohn(){
    cout << "---------------------------- ENEMY' DATA ----------------------------\n"
        << "NAME: " << enemy_john_data::NAME << '\n'
        << "HP: " << enemy_john_data::HP << '\n'
        << "ATK: " << enemy_john_data::ATK << '\n';

    sleep();
    cout << "Proceeding for gameplay...\n";
    sleep();

    for(int i = 5; i >= 1; i--){
        cout << i << '\n';
        sleep();
    }
    cout << "GO!\n";
    sleep();


    do{
        do{
            cout << "---------------------------- GAMEPLAY ----------------------------\n"
                << "1. Light Attack\n"
                << "2. Heavy Attack\n"
                << "Please, choose your next move (1/2): ";
            cin >> moveset;

            if(moveset <= 0 || moveset >= 3){
                cout << "Unavaiable moveset! Try again.\n";
                sleep();
            }
        }while (moveset <= 0 || moveset >= 3);

        cout << "Attacking...\n";
        sleep();

        if(moveset == 1){
            diceSystem();
            cout << "Enemy' health is now " << enemy_john_data::HP << '\n';
        }
        else if(moveset == 2){
            probabilitySystem();
            cout << "Enemy' health is now " << enemy_john_data::HP << '\n';
        }

        gameResultsCheck();

        sleep();
        cout << "The enemy is choosing his next moves..\n";
        sleep();

        generateRandomNumber();

        if(randomNumber == 1){
            switch (DiceRoll){
                case 1:
                    cout << "The Enemy got 5 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_john_data::ATK * 105/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 2:
                    cout << "The Enemy got 10 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_john_data::ATK * 110/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 3:
                    cout << "The Enemy got 15 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_john_data::ATK * 115/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 4:
                    cout << "The Enemy got 20 percent crit!\n";
                    sleep();
                    player_data::HP -= enemy_john_data::ATK * 120/(double)100;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                }
        }
        else if(randomNumber == 2){
            srand(time(0));
            luck = (rand() % 3) + 1;

            switch(luck){
                case 1:
                    cout << "John's Heavy Attack sucessfully proceeded!\n";
                    sleep();
                    player_data::HP -= enemy_john_data::HEAVY_ATK;
                    cout << "Your health is now " << player_data::HP << '\n';
                    break;
                case 2:
                    cout << "John's Heavy Attack unsecessfully Proceeded!\n";
                    sleep();
                    break;
                case 3:
                    cout << "John hit himself!\n";
                    enemy_john_data::HP -= enemy_john_data::HEAVY_ATK;
            }
            sleep();
        }

        sleep();
        cout << "Loading..\n";
        sleep();

        gameResultsCheck();

    }while(enemy_john_data::HP > 0 || player_data::HP > 0);
}

int main(){
    cout << "---------------------------- WELCOME ----------------------------\n";
    while(player_data::NAME.empty()){
        cout << "Enter your name: ";
        std::getline(std::cin, player_data::NAME);

        if(player_data::NAME.empty()){
            cout << "please, Enter your name! Try again.\n";
            sleep();
        }
    }

    cout << "Loading...\n";
    sleep();

    cout << "---------------------------- PLAYER'S DATA ----------------------------\n"
        << "NAME: " << player_data::NAME << '\n'
        << "HP: " << player_data::HP << '\n'
        << "ATK: " << player_data::ATK << '\n';

    sleep();
    cout << "Loading..\n";
    sleep();

    cout << "---------------------------- ENEMY SELECTION ----------------------------\n"
        << "1. Noob\n"
        << "2. John\n";

    sleep();

    do{
        cout << "Choose your enemy:";
        cin >> enemySelection;

        switch (enemySelection){
        case 1:
            gameplayNoob();
            break;

        case 2:
            gameplayJohn();
            break;
    
        default:
            cout << "Enemy Unavaiable!\n";
        }
    }while(enemySelection < 1 || enemySelection > 2);

    return 0;
}