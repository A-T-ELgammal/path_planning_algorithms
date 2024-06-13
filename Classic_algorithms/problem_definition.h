#ifndef PROBLEM_DEFINITION_H
#define PROBLEM_DEFINITION_H

#include <iostream>
#include <vector>

using namespace std;

class Map
{
public:
    Map(int height, int width, vector<vector<int>> grid) : height_(height), width_(width),
                                                           grid_(grid)
    {
    }
    int getHeight()
    {
        return this->height_;
    }
    int getWidth()
    {
        return this->width_;
    }
    vector<vector<int>> getGrid()
    {
        return this->grid_;
    }

private:
    const int height_;
    const int width_;
    vector<vector<int>> grid_;
};

class Planner
{
public:
    Planner()
    {
        this->startPosition_ = {0, 0};
        this->goalPosition_ = {4, 5};
        this->movementDirection_ = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        this->movementArrows_ = {'^', '<', 'v', '>'};
        this->movementCost_ = 1;
    }
    pair<int, int> getStartPosition()
    {
        return this->startPosition_;
    }
    pair<int, int> getGoalPosition()
    {
        return this->goalPosition_;
    }
    vector<vector<int>> getMovementDirections()
    {
        return this->movementDirection_;
    }
    int getMovementCost()
    {
        return this->movementCost_;
    }

    vector<char> getMovementArrows()
    {
        return this->movementArrows_;
    }

private:
    pair<int, int> startPosition_;
    pair<int, int> goalPosition_;
    vector<vector<int>> movementDirection_;
    vector<char> movementArrows_;
    int movementCost_;
};

template <typename T>
void print2DVector(const vector<vector<T>> &vec)
{
    for (int row = 0; row < vec.size(); row++)
    {
        for (int column = 0; column < vec[row].size(); ++column)
        {
            cout << vec[row][column] << " ";
        }
        cout << endl;
    }
}

#endif
