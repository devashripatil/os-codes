#include<iostream>
using namespace std;

class campaign {
public:
    void demo(int n, int budget, int reach[], int cost[]) {
        int table[n+1][budget+1];

        // Build DP Table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= budget; j++) {
                if (i == 0 || j == 0)
                    table[i][j] = 0;
                else if (cost[i-1] <= j)
                    table[i][j] = max(reach[i-1] + table[i-1][j-cost[i-1]], table[i-1][j]);
                else
                    table[i][j] = table[i-1][j];
            }
        }

        // Display DP Table
        cout << "\nDP Table (Reach values for each campaign vs Budget):\n";
        cout << "\ti\\B\t";  
        for (int w = 0; w <= budget; w++) {
            cout << w << "\t";
        }
        cout << "\n";
 
        for (int i = 0; i <= n; i++) {
            cout << "\t" << i << "\t"; 
            for (int w = 0; w <= budget; w++) {
                cout << table[i][w] << "\t";
            }
            cout << "\n";
        }

        // Backtrack to find selected campaigns
        int totalReach = table[n][budget];
        int w = budget;
        cout << "\nSelected Campaigns: ";
        for (int i = n; i > 0 && totalReach > 0; i--) {
            if (totalReach == table[i-1][w])
                continue; // not selected
            else {
                cout << "Campaign " << i << " ";
                totalReach -= reach[i-1];
                w -= cost[i-1];
            }
        }

        // Final Output
        cout << "\nTotal Cost Used: " << (budget - w);
        cout << "\nMaximum Reach Achieved: " << table[n][budget] << endl;
    }
};

int main() {
    int n, budget;
    cout << "\nEnter the number of campaigns: ";
    cin >> n;
    cout << "\nEnter the total available budget: ";
    cin >> budget;

    int reach[n], cost[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter expected reach of campaign " << i+1 << ": ";
        cin >> reach[i];
        cout << "Enter cost of campaign " << i+1 << ": ";
        cin >> cost[i];
    }

    campaign obj;
    obj.demo(n, budget, reach, cost);
    return 0;
}
