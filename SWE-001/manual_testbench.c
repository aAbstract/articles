// Note: this is not the formal way to write and include C modules
// but it is sufficient for demonstration purposes.

#include <stdio.h>

#include "module.c"

void print_test_result(int a, int b, int sum) {
    printf("Input: a=%d, b=%d | Output: sum=%d\n", a, b, sum);
}

int main() {
    int a_1 = 5, b_1 = 6;
    int sum_1 = add_nums(a_1, b_1);
    print_test_result(a_1, b_1, sum_1);

    int a_2 = 2, b_2 = 3;
    int sum_2 = add_nums(a_2, b_2);
    print_test_result(a_2, b_2, sum_2);

    int a_3 = 4, b_3 = 9;
    int sum_3 = add_nums(a_3, b_3);
    print_test_result(a_3, b_3, sum_3);

    return 0;
}