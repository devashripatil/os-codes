#include <iostream>
using namespace std;

class CloudStorage {
public:
    void solve(int n, int S, int importance[], int size[]) {
        int table[n + 1][S + 1];

        // Step 1: Build DP Table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= S; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (size[i - 1] <= j)
                    table[i][j] = max(importance[i - 1] + table[i - 1][j - size[i - 1]], table[i - 1][j]);
                else
                    table[i][j] = table[i - 1][j];
            }
        }

        // Step 2: Display DP Table (for demonstration)
        cout << "\nDP Table (Importance vs Storage Capacity):\n";
        cout << "\ti\\S\t";
        for (int s = 0; s <= S; s++) cout << s << "\t";
        cout << "\n";

        for (int i = 0; i <= n; i++) {
            cout << "\t" << i << "\t";
            for (int s = 0; s <= S; s++)
                cout << table[i][s] << "\t";
            cout << "\n";
        }

        // Step 3: Backtrack to find which files are selected
        int totalImportance = table[n][S];
        int totalSize = 0;
        int s = S;

        cout << "\nFiles selected for backup: ";
        for (int i = n; i > 0 && totalImportance > 0; i--) {
            if (totalImportance == table[i - 1][s])
                continue; // not selected
            else {
                cout << "File " << i << " ";
                totalImportance -= importance[i - 1];
                totalSize += size[i - 1];
                s -= size[i - 1];
            }
        }

        // Step 4: Display final result
        cout << "\nTotal Storage Used: " << totalSize << " GB";
        cout << "\nMaximum Importance Score: " << table[n][S] << endl;
    }
};

int main() {
    int n, S;
    cout << "\nEnter the number of files: ";
    cin >> n;
    cout << "Enter total available storage capacity (GB): ";
    cin >> S;

    int importance[n], size[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter importance value of file " << i + 1 << ": ";
        cin >> importance[i];
        cout << "Enter size of file " << i + 1 << " (GB): ";
        cin >> size[i];
    }

    CloudStorage obj;
    obj.solve(n, S, importance, size);

    return 0;
}
