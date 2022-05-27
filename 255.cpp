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
    
	int n, i = 1;
	fin >> n;
	for (int j = 2; i <= sqrt(n); ++j) {
		if (n % j == 0) {
			for (i <= sqrt(n); ++i;) { if (n % i == 0) { break; } }
			fout << n / i << " " << n - (n / i);
			return 0;
		}
	}
	fout << 1 << " " << n - 1;

    fin.close();
    fout.close();
    std::system("pause");
    return 0;
}

