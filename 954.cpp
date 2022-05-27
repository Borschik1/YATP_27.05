#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int height;
    fin >> height;
    vector<int> count(height + 1, 0);
    count[0] = 1;
    const int MOD = 1000 * 1000;
    for (int h = 1; h <= height; ++h) {
        if (h >= 10)
            count[h] += count[h - 10];
        if (h >= 11)
            count[h] += count[h - 11];
        if (h >= 12)
            count[h] += count[h - 12];
        count[h] %= MOD;
    }
    fout << count[height] * 2 % MOD;

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

