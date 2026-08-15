## SWE-001 - Unit Testing and Debugging C Code Using Python + PyTest + GDB

### Problem
A common flow in embedded systems development is unit testing some firmware modules.  
firmware is primarily written in C or C++. 
Let's explore the common ways to do so in the next few sections.

### Solution #1 - The Testbench Program
One of the ways to do unit testing is writing a testbench program that verifies the functionality
of a certain module. This verification can be done manually through inspection or automatically by writing a 
self-checking testbench.
```c
// module under test
// SWE-001/module.c
int add_nums(int a, int b) {
    return a + b;
}
```

```c
// SWE-001/manual_testbench.c

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

```

```bash
$ ./run.sh manual_testbench.c 

Input: a=5, b=6 | Output: sum=11
Input: a=2, b=3 | Output: sum=5
Input: a=4, b=9 | Output: sum=13
```

The challenge with this manual approach is that it is prone to human error.
This can be addressed using a `self-checking testbench` using C keyword `assert`.

```c
// SWE-001/automatic_testbench.c

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
```

```bash
$ ./run.sh automatic_testbench.c

exe: automatic_testbench.c:20: main: Assertion `sum_3 == 14' failed.
./run.sh: line 3: 93681 Aborted
```

### Solution #2 - Unit Testing Frameworks
Unit testing frameworks such as **PyTest** for Python and **Unity** for C/C++ 
provide tools to write and automatically run tests for individual software units, 
helping detect bugs early and ensure changes do not break existing functionality.  
Basically, it is a systemic way of writing self-checking testbenches.

#### A. Unity Framework

```c
// SWE-001/unity_testbench.c

#include "unity.h"

#include "module.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_add_1(void) {
    TEST_ASSERT_EQUAL_INT(11, add_nums(5, 6));
}

void test_add_2(void) {
    TEST_ASSERT_EQUAL_INT(5, add_nums(2, 3));
}

void test_add_3(void) {
    TEST_ASSERT_EQUAL_INT(13, add_nums(4, 9));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_1);
    RUN_TEST(test_add_2);
    RUN_TEST(test_add_3);

    return UNITY_END();
}
```

```bash
$ ./run_unity_test.sh # valid testbench run 

unity_testbench.c:28:test_add_1:PASS
unity_testbench.c:29:test_add_2:PASS
unity_testbench.c:30:test_add_3:PASS

-----------------------
3 Tests 0 Failures 0 Ignored 
OK
```

```bash
$ ./run_unity_test.sh # invalid testbench run

unity_testbench.c:28:test_add_1:PASS
unity_testbench.c:29:test_add_2:PASS
unity_testbench.c:22:test_add_3:FAIL: Expected 12 Was 13

-----------------------
3 Tests 1 Failures 0 Ignored 
FAIL
```

A simple comparison between `C Assert` and `Unity`
| `C Assert`                            | Unity                                                |
| ------------------------------------- | ---------------------------------------------------- |
| Built into C                          | External testing framework                           |
| Very simple                           | More structured                                      |
| Good for checking runtime errors      | Designed specifically for unit testing               |
| Usually stops execution when it fails | Can run and report many tests                        |
| Minimal output/reporting              | Provides detailed test results                       |
| No test organization                  | Supports test setup, teardown, test runners and more |

- TODO: C Test Hastle
- TODO: PyTest framework
- TODO: Python C FFI
- TODO: Python `ctypesgen`
- TODO: Python PDB Debug
- TODO: Linux SIGTRAP
- TODO: PyTest + GDB setup
- TODO: PyTest + GDB + VSCode setup
