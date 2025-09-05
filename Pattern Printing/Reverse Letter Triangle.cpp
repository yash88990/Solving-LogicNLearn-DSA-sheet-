void nLetterTriangle(int n) {
    // Write your code here.
    for (int i = n; i >= 1; i--) {
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << "\n";
    }
}
