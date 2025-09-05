#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> triangle(N); 
    for (int i = 0; i < N; i++) {
        triangle[i].resize(i + 1, 1); // Resize the row and initialize with 1s
        for (int j = 1; j < i; j++) {
            // Compute each inner element using the sum of two values above it
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}
