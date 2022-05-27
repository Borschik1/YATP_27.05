#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    size_t n, k, answ;
    string word;
    fin >> n >> k >> word;
    if (k == n) {
        answ = n;
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) { answ += n / i + 1; }
            else { answ += n / i + 2; }
        }
        fout << answ;
        return 0;
    }
    answ = n;
    for (int i = 1; i < k + 1; ++i)
    {
        answ += tgamma(i + 2);
    }
    for (int count = k + 2; count < n; ++count) {
        for (int i = 0; i < n - count + 1; ++i) {
            for (int j = i; j < i + count / 2; ++j) {
                size_t temp = 0;
                if (word[j] != word[count - j - 1]) { temp++; }
                if (temp > k) { break; }
                if (j >= count / 2 - 1) { answ++; break; }
            }
        }
    }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

