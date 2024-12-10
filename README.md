<h2>Q-Learning Algorithm</h2>

This repository contains a C++ implementation of the Q-Learning algorithm applied to a simple grid world problem. The grid world consists of states represented by rows and actions represented by columns. The goal is to reach a specific state denoted by F from any staring point.


<h3>-Description of code :</h3>

The Q_LearningAlgorithm.cpp file contains the main implementation of the Q-Learning algorithm. Here's an overview of the key components:
<ul>
  <li>printArray: Function to print a 2D array.</li>
  <li>initializeRewardArray: Function to initialize the reward matrix based on the problem description.</li>
  <li>getRandomPossibleAction: Function to select a random possible action from a given state.</li>
  <li>QLearningAlgorithm: Function implementing the Q-Learning algorithm. It updates the Q-table based on the rewards and learns the optimal policy.</li>
  <li>main: The entry point of the program. It initializes the reward matrix, sets up the Q-table, runs the Q-Learning algorithm, and prints the final Q-table.</li>
</ul>




