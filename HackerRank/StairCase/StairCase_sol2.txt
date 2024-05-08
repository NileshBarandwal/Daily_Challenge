void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        int num_spaces = n - i;
        int num_hashes = i;
        
        // Print spaces
        for (int j = 0; j < num_spaces; j++) {
            cout << " ";
        }
        
        // Print hashes
        for (int j = 0; j < num_hashes; j++) {
            cout << "#";
        }
        
        cout << endl;
    }
}
