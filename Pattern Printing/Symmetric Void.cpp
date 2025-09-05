void symmetry(int n) {
    // Write your code here.
    int totalRows = 2 * n;

    for (int i = 1; i <= totalRows; i++) {
        int stars = (i <= n) ? n - i + 1 : i - n;
        int spaces = (i <= n) ? 2 * (i - 1) : 2 * (totalRows - i);

        for (int j = 0; j < stars; j++) {
            cout << "* ";
        }

        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        
        for (int j = 0; j < stars; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}
