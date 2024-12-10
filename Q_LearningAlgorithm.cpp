
// Ghada Nofal


#include <iostream>
#include <cmath>
#include<ctime>

using namespace std;

// Constants for the array dimensions
const int rows = 6;
const int columns = 6;

void printArray(int array[rows][columns]){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout <<  array[i][j] << " ";
        }
        cout << endl;
    }
}

void initializeRewardArray(int Reward[rows][columns]){

    // Assigning the values to the Reward array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (j == 5 && (i == 1 || i == 4 || i == 5)){

                // If the column is F (If we reach the goal) give it big value
                // In other words if there is a direct action from current state to the gaol state
                Reward[i][j] = 100;

            }else if ((i == 0 && j == 4) || ((i == 1 || i == 2) && ( j == 3)) || (i == 5 && ( j == 1 || j == 4)) ){

                // If there is a possible action give it value 0
                Reward[i][j] = 0;

            }else if (((i == 3) && (j == 1 || j == 2 || j == 4)) || ( i == 4 && ( j == 0 || j == 3))){

                // If there is a possible action give it value 0
                Reward[i][j] = 0;
            }else{

                // If there is no possible action (movement) give it -1
                Reward[i][j] = -1;
            }
        }
    }
}

int getRandomPossibleAction(int state, int Reward[rows][columns]){

    // Randomly choose a possible action
    while (true){

        int randomAction = rand() % columns;

        // If it's possible action break
        if (Reward[state][randomAction] != -1 ){
            return randomAction;
        }
    }
}

void QLearningAlgorithm(int Reward[rows][columns], int QTable[rows][columns], double y, int episodes){

    // Loop for all episodes
    while(episodes--){

        // Choose a random starting state from all states which are represented via rows
        int state = rand() % rows;

        // Do while the goal is not reached, in this case while the state != 5
        while (true){

            // Select one random action from this state call it x, this action should be possible
            int x = getRandomPossibleAction(state, Reward);

            // Get the maximum Q from the x row using QTable
            int maximumQ = -1;
            for (int i = 0; i < columns; i++){
                maximumQ = max(maximumQ, QTable[x][i]);
            }

            // Update the QTable according to this equation
            QTable[state][x] = Reward[state][x] + y * maximumQ;

            // Update the state to be the next state which has been chosen randomly
            state = x;
            if (x == 5){
                break;;
            }
        }
    }
}



int main (){

    // The rows is the states and the columns is the actions
    int Reward[rows][columns];

    // We want to reach F. because F is the goal

    // Assigning the values to the Reward array
    initializeRewardArray(Reward);

    cout << "The Reward array is : "<<endl;
    printArray(Reward);
    cout << endl << endl;

    // Initialize the Q-table array and initially all it's values are -1
    int QTable[rows][columns];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            QTable[i][j] = -1;
        }
    }


    int episode = 1000;

    // learning rate is constant
    double y = 0.8;

    // Seed for random number generator
    srand(time(0));

    // Apply Q-learning algorithm
    QLearningAlgorithm(Reward, QTable, y, episode);

    cout << "The Q_table after " << episode << " episodes is : " << endl;
    printArray(QTable);
    cout << endl;

    return 0;
}

