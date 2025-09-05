

void nStarTriangle(int n) {
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // Print the stars
        for (int k = 0; k < 2 * (n - i) - 1; k++) {
            cout << "*";
        }
        // Move to the next line
        cout <<endl;
    }
}
