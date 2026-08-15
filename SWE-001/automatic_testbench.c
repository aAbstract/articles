// Note: this is not the formal way to write and include C modules
// but it is sufficient for demonstration purposes.

#include <assert.h>
#include <stdio.h>

#include "module.c"

int main() {
    int a_1 = 5, b_1 = 6;
    int sum_1 = add_nums(a_1, b_1);
    assert(sum_1 == 11);

    int a_2 = 2, b_2 = 3;
    int sum_2 = add_nums(a_2, b_2);
    assert(sum_2 == 5);

    int a_3 = 4, b_3 = 9;
    int sum_3 = add_nums(a_3, b_3);
    assert(sum_3 == 14);  // invalid assert

    return 0;
}