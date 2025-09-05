void alphaHill(int n) {
    // Write your code here.
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // Print the first half of the alphabet sequence
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++;
        }

        // Print the second half of the alphabet sequence
        ch -= 2;
        for (int j = 1; j < i; j++) {
            cout << ch << " ";
            ch--;
        }
        cout << "\n";
    }
}
