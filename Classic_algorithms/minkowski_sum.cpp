#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print2DVector(vector<vector<int>> vec)
{

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[0].size(); ++j)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

vector<vector<int>> delete_duplicate(vector<vector<int>> &C)
{
    sort(C.begin(), C.end());
    for (int i = 0; i < C.size() - 1; i++)
    {
        if (C[i] == C[i + 1])
            C.erase(C.begin() + i);
    }
    return C;
}

vector<vector<int>> minkowski_sum(vector<vector<int>> A, vector<vector<int>> B)
{
    return B;
}

int main()
{
    // Define the coordinates of triangle A and B using 2D vectors
    vector<vector<int>> A(3, vector<int>(2));
    A = {
        {1, 0},
        {0, 1},
        {0, -1},
        {1, 0}};
    vector<vector<int>> B(3, vector<int>(2));
    B = {
        {0, 0},
        {1, 1},
        {1, -1},
    };
    vector<vector<int>> S(4, vector<int>(2));
    S = {{1, 2},
         {2, 3},
         {1, 2},
         {3, 1}};

    // Compute the minkowski sum of triangle A and B
    // vector<vector<int>> C;
    // C = minkowski_sum(A, B);

    // // Print the resulting vector
    // delete_duplicate(S);
    // print2DVector(B);
    print2DVector(delete_duplicate(S));

    return 0;
}
