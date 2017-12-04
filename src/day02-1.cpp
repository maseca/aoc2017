#define X 16
#define Y 16
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    ifstream iFS;
    int min, max, sum = 0;
    int matrix[X][Y];

    iFS.open("../inputs/day02.in", ifstream::in);

    for (auto &i : matrix) {
        for (int &j : i) {
            iFS >> j;
        }
    }

    for (auto &i : matrix){
        min = 9999;
        max = 0;
        for(auto &j : i){
            if(j > max)
                max = j;
            if(j < min)
                min = j;
        }
        sum += max - min;
    }

    printf("sum: %d\n", sum);

    return 0;
}
