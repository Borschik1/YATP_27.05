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


int move(int p, int n, map<pair<int, int>, int> &mp) {
    int answer = 1;
    pair<int, int> plug;
    for (int i = p + 1; i < n / 2 + n % 2; ++i) {
        plug.first = i;
        plug.second = n - i;
        if (!mp.contains(plug)) { mp.emplace(plug, move(i, n - i, mp)); }
        answer += mp[plug];
    }
    return answer;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n, ans = 0;
    map<pair<int, int>, int> mp;
    fin >> n;
    for (int i = 1; i < n / 2 + n % 2; ++i) {
        ans += move(i, n - i, mp);
    }
    fout << ans;

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

