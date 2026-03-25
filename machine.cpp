#include <iostream>
using namespace std;

class MachineUpgrade {
public:
    void solve(int n, int B, int gain[], int cost[]) {
        int table[n + 1][B + 1];

        // Step 1: Build DP Table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= B; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (cost[i - 1] <= j)
                    table[i][j] = max(gain[i - 1] + table[i - 1][j - cost[i - 1]], table[i - 1][j]);
                else
                    table[i][j] = table[i - 1][j];
            }
        }

        // Step 2: Display DP Table (for understanding)
        cout << "\nDP Table (Performance Gain vs Budget):\n";
        cout << "\ti\\B\t";
        for (int b = 0; b <= B; b++) cout << b << "\t";
        cout << "\n";

        for (int i = 0; i <= n; i++) {
            cout << "\t" << i << "\t";
            for (int b = 0; b <= B; b++)
                cout << table[i][b] << "\t";
            cout << "\n";
        }

        // Step 3: Backtrack to find selected machines
        int totalGain = table[n][B];
        int totalCost = 0;
        int b = B;

        cout << "\nMachines selected for upgrade: ";
        for (int i = n; i > 0 && totalGain > 0; i--) {
            if (totalGain == table[i - 1][b])
                continue; // not selected
            else {
                cout << "Machine " << i << " ";
                totalGain -= gain[i - 1];
                totalCost += cost[i - 1];
                b -= cost[i - 1];
            }
        }

        // Step 4: Display final result
        cout << "\nTotal Investment Made: " << totalCost;
        cout << "\nMaximum Performance Gain Obtained: " << table[n][B] << endl;
    }
};

int main() {
    int n, B;
    cout << "\nEnter the number of machines: ";
    cin >> n;
    cout << "Enter total available budget: ";
    cin >> B;

    int gain[n], cost[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter performance gain of machine " << i + 1 << ": ";
        cin >> gain[i];
        cout << "Enter upgrade cost of machine " << i + 1 << ": ";
        cin >> cost[i];
    }

    MachineUpgrade obj;
    obj.solve(n, B, gain, cost);

    return 0;
}
