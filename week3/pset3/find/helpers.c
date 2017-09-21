/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
//BinarySearch 
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm 
    int left_index = 0;
    int right_index = n - 1;
    
    //if l=r, list size = 0
    while (left_index <= right_index){
        int middle = (left_index + right_index) / 2;
        
        if (values[middle] == value) {
            return true;
        }
        
        else if (values[middle] > value) {
            right_index = middle - 1;
        }
        
        else if (values[middle] < value) {
            left_index = middle + 1;        
        }
        
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    for (int i = 0; i < n - 2; i++){
        int min_index = i;

        //find smallest element from i to n - 1
        for (int j = i + 1; j < n - 1; j++){
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        //swap the smallest element with the 1st element
        // of the unsorted array
        // need temporal since one value overwrites the other
        if (min_index != i) {
            int temporal = values[i];
            values[i] = values[min_index];
            values[min_index] = temporal;
        }
    }
    return;
}
