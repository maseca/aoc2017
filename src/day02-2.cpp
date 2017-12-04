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
        int h, H;
        h = H = 0;

        for(auto &j : i){
            for(auto &J : i){
                if(J > j && J % j == 0){
                    H = J;
                    h = j;
                    break;
                }
            }

            if(H > h && H % h == 0) {
                sum += H / h;
                break;
            }
        }
    }

    printf("sum: %d\n", sum);

    return 0;
}
