#!/bin/bash

gcc -IUnity/src Unity/src/unity.c unity_testbench.c -o exe && ./exe
