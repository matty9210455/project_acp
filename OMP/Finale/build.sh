#!/bin/bash
g++ -std=c++11 -fopenmp main.cpp read.cpp write_update.cpp -I. -o omp