#include <iostream>
#include <numeric>
int knapSack(int wt[], int val[], int n, int W);

int MCRec(int total, int coins[], int size);


int main() {

    int total, size;
    int coins[size + 1];


    std::cin >> total >> size;

    int MC[total + 1][size + 1];



    for (int k = 0; k < size + 1; k++) {
        for (int t = 0; t < total + 1; t++) {
            MC[t][k] = 0;
        }
    }


    for (int k = 0; k < size; k++) {
        for (int t = 0; t < total; t++) {
            for (int i = 1; i <= 5; i++) {
                int store = MC[t][k];
                MC[t][k] = std::max(MC[t][k - 1],
                        (MC[t - coins[k]][k - 1]));
                if(store > MC[t][k])
                {
                    MC[t][k] = store;
                }
            }
        }
    }

    for (int i = 0; i < total + 1; i++) {
        for (int j = 0; j < size + 1; ++j) {
            std::cout << "MC[" << i << "]" << "[" << j << "] = " << MC[i][j] << "\n";
        }
    }
    std::cout << "\n";

        if (MC[total][size] <= 0) {return -1; }
        return MC[total][size];
    }


/*
   int total, size;
    int coins[(size+1)];

    std::cin >> total >> size;
    int currCoin;
    std::cin >> currCoin;
    coins[0] = 0;
    for (int i = 1; i < size+1; i++)
    {
        coins[i] = currCoin;
        if(i % 5 == 0)
        {
            std::cin >> currCoin;
        }
    }

    int MC[total + 1][size + 1];

    for (int i = 0; i < total + 1; ++i) {
        for (int j = 0; j < size + 1; ++j) {
            MC[i][j] = 0;
        }
    }


    for (int i = 1; i < total + 1; ++i) {
        for (int j = 1; j < size + 1; ++j) {

            if ((i - coins[j]) < 0) {
                //if undef
                MC[i][j] = MC[i - 1][j];
            }
            else {
                    for(int l = 1; l <= 5; l++)
                    {
                        if(i - l*(coins[j] <= 0))
                        {
                            MC[i][j] = MC[i - 1][j];
                        }
                        else {
                            MC[i][j] = std::max(
                                    (MC[i - 1][j]),
                                    ((l+MC[i - l * (coins[j])][j - 1])));
                        }
                    }
            }
        }
    }

    for (int i = 0; i < total + 1; i++) {
        for (int j = 0; j < size + 1; ++j) {
           std::cout << "MC[" << i << "]" << "[" << j << "] = " << MC[i][j] << "\n";
        }
        std::cout << "\n";
    }

   std::cout << "MC[" << total << "]" << "[" << size << "] = " << MC[total][size] << "\n";

    if (MC[total][size] <= 0) { return -1; }
    return MC[total][size];
    }
 */