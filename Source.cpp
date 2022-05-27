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
    
    int n, n2, n3;
    fin >> n;
    if (n % 3 == 0) { n2 = 0; n3 = n / 3; }
    else if (n % 3 == 1) { n2 = 2; n3 = (n - 4) / 3; }
    else { n2 = 1; n3 = (n - 2) / 3; }
    if (n2 > 0 && n3 > 0) { fout << 2 << " " << n2 << " " << 3 << " " << n3; }
    else if (n2 > 0) { fout << 2 << " " << n2; }
    else { fout << 3 << " " << n3; }

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

