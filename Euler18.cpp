#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

// same as problem 67, just different input

int main() {
    clock_t c_start = clock();
    int N, t;
    // data input
    string filename = "0018_triangle.txt";
    string line, str;
    ifstream rfile(filename);
    vector<vector<int>> triangle;
    vector<int> row;
    triangle.clear();
    N = -1; // after reading the first it must be 0 
    while (getline (rfile, line)) {
        row.clear();
        for (int n = 0; n < line.length(); n += 3) {
            str = "";
            str += line[n];
            str += line[n+1];
            t = stoi(str);
            row.push_back(t);
        }
        triangle.push_back(row);
        N++;
    }
    rfile.close();
    // the algorithm itself
    for (int i = N-1; i != -1; i--) {
        for (int j = 0; j != i+1; j++) {
            triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    clock_t c_end = clock();
    cout << triangle[0][0] << endl;
    cout << 1000.0*(c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
    return 0;
}