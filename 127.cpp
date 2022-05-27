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
    
    int n, vBegin, vEnd;
    fin >> n;
    vector <vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> a[i][j];
    fin >> vBegin >> vEnd;
    vBegin--;
    vEnd--;
    const int UNDEF = -1;
    vector <int> len(n, UNDEF);
    queue <int> q;
    q.push(vBegin);
    len[vBegin] = 0;
    while (true)
    {
        if (q.empty())
        {
            fout << -1;
            return 0;
        }
        int cur = q.front();
        q.pop();
        if (cur == vEnd)
        {
            fout << len[vEnd];
            return 0;
        }
        for (int next = 0; next < n; ++next)
            if (len[next] == UNDEF && a[cur][next] == 1)
            {
                q.push(next);
                len[next] = len[cur] + 1;
            }
    }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

