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
        while (C[i] == C[i + 1])
            C.erase(C.begin() + i + 1);
    }
    return C;
}

vector<vector<int>> minkowski_sum(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> sum;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            sum.push_back({A[i][0] + B[j][0], A[i][1] + B[j][1]});
        }
    }
    return delete_duplicate(sum);
}

int main()
{
    vector<vector<int>> A(3, vector<int>(2));
    A = {
        {1, 0},
        {0, 1},
        {0, -1},
    };

    vector<vector<int>> B(3, vector<int>(2));
    B = {
        {0, 0},
        {1, 1},
        {1, -1},
    };
    print2DVector(minkowski_sum(A, B));
    return 0;
}
