#include <iostream>

#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "Maze.h"
#include "Agent.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

enum States
{
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(void)
{

    bool mode = NORMAL_MODE;
    // read Mode

    if (mode == NORMAL_MODE)
    {
        mcpp::MinecraftConnection mc;
        mc.doCommand("time set day");

        States curState = ST_Main;
        int input;
        // State machine for menu
        while (curState != ST_Exit)
        {
            if (curState == ST_Main)
            {
                printStartText(); // Assume this prints introductory text
                printMainMenu();
            }
            // Do something
            std::cin >> input;

            if (input == 1)
            {
                printGenerateMazeMenu();
                curState = ST_GetMaze;
                int nextinput;
                std::cin >> nextinput;
                if (nextinput == 1)
                {
                    readFromTerminal();
                }
                else if (nextinput == 2)
                {
                    // TODO
                }
                else
                {
                    curState = ST_Main;
                }
            }
            else if (input == 2)
            {
                // TODO BUILD MAZE
            }
            else if (input == 3)
            {
                curState = ST_SolveMaze;
                printSolveMazeMenu();
                int nextinput;
                std::cin >> nextinput;
                if (nextinput == 1)
                {
                    // solve manually
                    int x, y, z;
                    x = 0;
                    y = 0;
                    z = 0;
                    mcpp::Coordinate coords = mcpp::Coordinate(x, y, z);
                    coords = mc.getPlayerPosition();
                    // teleport them to a random pos in the maze
                    // int randx = rand() %
                    // int randz = rand() %
                    // mc.setPlayerPosition(coords);
                }
                else if (nextinput == 2)
                {
                    // show escape route
                }
                else
                {
                    curState = ST_Main;
                }
            }
            else if (input == 4)
            {
                curState = ST_Creators;
                printTeamInfo();
                curState = ST_Main;
            }
            else if (input == 5)
            {
                curState = ST_Exit;
                printExitMassage();
            }
            else
            {
                std::cerr << "Invalid input. Please enter a valid option.\n";
                // TODO HANDLE ERROR WITH STRING
            }
        }

        printExitMassage();

        return EXIT_SUCCESS;
    }
}

// expected output:

// |------|
// |=---|-|

// if input i received != expected output
// throw Error test case failed