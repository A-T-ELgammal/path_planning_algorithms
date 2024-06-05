#include <iostream>
#include <vector>
#include "problem_definition.h"

using namespace std;

int main()
{
    vector<vector<int>> grid = {{0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 1, 1, 0}};
    Map map(5, 6, grid);
    Planner planner;
    print2DVector(grid);
    return 0;
}