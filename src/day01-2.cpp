#include <cstdio>

int _fget(FILE* f){ return fgetc(f) - '0'; }

int _length(FILE* f){
    int cur, i = 0;
    cur = _fget(f);

    while(cur != '\n' - '0'){
        ++i;
        cur = _fget(f);
    }

    rewind(f);
    return i;
}

int main(){
    FILE* inF = fopen("../inputs/day01.in", "r");
    if(!inF)
        return 1;

    int length, half_sum = 0;
    int* ary;

    length = _length(inF);
    ary = new int[length];

    for(int i = 0; i < length; ++i){
        ary[i] = _fget(inF);
    }
    fclose(inF);

    for(int i = 0; i < length / 2; ++i){
        if(ary[i] == ary[i + length / 2])
            half_sum += ary[i];
    }
    delete ary;

    printf("Sum: %d\n", half_sum * 2);

    return 0;
}