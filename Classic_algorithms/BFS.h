#include <algorithm>
#include "problem_definition.h"
#include <queue>

void search(Map &map, Planner &planner)
{
    // create closed 2 array filled with 0s and first element 1
    vector<vector<int>> closed(map.getHeight(), vector<int>(map.getWidth()));
    closed[planner.getStartPosition().first][planner.getStartPosition().second] = 1;

    // define triplet values
    int x = planner.getStartPosition().first;
    int y = planner.getStartPosition().second;
    int g = 0;

    // store the expansions
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> open;
    open.push({g, x, y});

    vector<vector<int>> expand(map.getHeight(), vector<int>(map.getWidth(), -1));

    // Flags
    bool found = false;
    bool resign = false;
    int count = 0;

    int x2;
    int y2;

    while (!found && !resign)
    {
        if (open.size() == 0)
        {
            resign = true;
            cout << "Failed to reach a goal" << endl;
        }
        else
        {
            vector<int> next;
            next = open.top();
            open.pop();

            x = next[1];
            y = next[2];
            g = next[0];

            expand[x][y] = count;
            count += 1;

            if (x == planner.getGoalPosition().first && y == planner.getGoalPosition().second)
            {
                found = true;
                cout << '[' << g << " , " << x << " , " << y << "]" << endl;
            }

            else
            {
                for (int i = 0; i < planner.getMovementDirections().size(); i++)
                {
                    x2 = x + planner.getMovementDirections()[i][0];
                    y2 = y + planner.getMovementDirections()[i][1];
                    if (x2 >= 0 && x2 < map.getGrid().size() && y2 >= 0 && y2 < map.getGrid()[0].size())
                    {
                        if (closed[x2][y2] == 0 and map.getGrid()[x2][y2] == 0)
                        {
                            int g2 = g + planner.getMovementCost();
                            open.push({g2, x2, y2});
                            closed[x2][y2] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << "closed list " << endl;
    print2DVector(closed);
    cout << "/////////////////" << endl;
    cout << "expand list" << endl;
    print2DVector(expand);
}
