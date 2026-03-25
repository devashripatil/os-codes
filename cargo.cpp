#include <iostream>
using namespace std;

class Cargo {
public:
    void solve(int n, int W, int profit[], int weight[]) {
        int table[n + 1][W + 1];

        // Build DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (weight[i - 1] <= j)
                    table[i][j] = max(profit[i - 1] + table[i - 1][j - weight[i - 1]],
                                      table[i - 1][j]);
                else
                    table[i][j] = table[i - 1][j];
            }
        }

        // Display DP Table
        cout << "\nDP Table (Profit values for boxes vs Capacity):\n";
        cout << "\ti\\j\t";
        for (int j = 0; j <= W; j++)
            cout << j << "\t";
        cout << "\n";

        for (int i = 0; i <= n; i++) {
            cout << "\t" << i << "\t";
            for (int j = 0; j <= W; j++)
                cout << table[i][j] << "\t";
            cout << "\n";
        }

        // Backtrack to find selected boxes
        int totalProfit = table[n][W];
        int totalWeight = 0;
        int j = W;

        cout << "\nSelected Boxes: ";
        for (int i = n; i > 0 && totalProfit > 0; i--) {
            if (totalProfit == table[i - 1][j])
                continue; // not included
            else {
                cout << "Box " << i << " ";
                totalProfit -= profit[i - 1];
                j -= weight[i - 1];
                totalWeight += weight[i - 1];
            }
        }

        cout << "\nTotal Weight Used: " << totalWeight;
        cout << "\nMaximum Profit Achieved: " << table[n][W] << endl;
    }
};

int main() {
    int n, W;
    cout << "\nEnter number of boxes: ";
    cin >> n;
    cout << "Enter truck capacity: ";
    cin >> W;

    int profit[n], weight[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter profit of box " << i + 1 << ": ";
        cin >> profit[i];
        cout << "Enter weight of box " << i + 1 << ": ";
        cin >> weight[i];
    }

    CargoKnapsack obj;
    obj.solve(n, W, profit, weight);

    return 0;
}
