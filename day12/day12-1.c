#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int cheol[10001] = { 0, };
    int brother[10001] = { 0, };
    int cheol_kind = 0;
    int brother_kind = 0;
    int result = 0;

    for (int i = 0; i < topping_len; i++) {
        int pre_topp = topping[i];
        if (brother[pre_topp] == 0) {
            brother_kind++;
        }
        brother[pre_topp]++;
    }

    for (int i = 0; i < topping_len; i++) {
        int pre_topp = topping[i];
        brother[pre_topp]--;
        if (brother[pre_topp] == 0) {
            brother_kind--;
        }
        if (cheol[pre_topp] == 0) {
            cheol_kind++;
        }
        cheol[pre_topp]++;

        if (cheol_kind == brother_kind) {
            result++;
        }
    }

    return result;
}