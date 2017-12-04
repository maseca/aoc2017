#include <cstdio>

int _fget(FILE* f){ return fgetc(f) - '0'; }

int main(){
    FILE* inF = fopen("../inputs/day01.in", "r");
    if(!inF)
        return 1;

    int first, cur, prev, sum = 0;

    first = cur = _fget(inF);

    do{
        prev = cur;
        cur = _fget(inF);
        if(prev == cur)
            sum += cur;
    }while(cur != '\n' - '0');
    fclose(inF);

    if(prev == first)
        sum += first;

    printf("Sum: %d\n", sum);
    return 0;
}