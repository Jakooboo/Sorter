//
// Created by jakub on 01.04.19.
// Inspirowano sie:
// http://www.algorytm.org/algorytmy-sortowania/sortowanie-przez-scalanie-mergesort/merge-c.html
//

#ifndef SORTER_MERGESORTING_HH
#define SORTER_MERGESORTING_HH

#include <iostream>
#include "ArrayOfNumbers.hh"

template <typename typeOfDataInArray>
void Merge(typeOfDataInArray *sourceArray, int start, int middle, int over){
    typeOfDataInArray *workplaceArray = new typeOfDataInArray[(over-start+1)];

    int firstHalfIterator = start, secondHalfIterator = middle + 1, iterator = 0;

    while (firstHalfIterator <= middle && secondHalfIterator <= over){
        if (sourceArray[secondHalfIterator] < sourceArray[firstHalfIterator]){
            workplaceArray[iterator++] = sourceArray[secondHalfIterator++];
        }
        else{
            workplaceArray[iterator++] = sourceArray[firstHalfIterator++];
        }
    }

    while (firstHalfIterator <= middle){                                                                                                                            //////MERGESORT//////
            workplaceArray[iterator++] = sourceArray[firstHalfIterator++];
    }

    while (secondHalfIterator <= over){
            workplaceArray[iterator++] = sourceArray[secondHalfIterator++];
    }
    
    for (firstHalfIterator = 0; firstHalfIterator <= over - start; firstHalfIterator++)
        sourceArray[start + firstHalfIterator] = workplaceArray[firstHalfIterator];

    delete[] workplaceArray;
}

template <typename typeOdDataInArray>
void MergeSort(typeOdDataInArray sourceArray, int start, int end)
{
    long int middle;

    if (start < end)
    {
        middle = (start + end) / 2;
        MergeSort(sourceArray, start, middle);
        MergeSort(sourceArray, middle + 1, end);
        Merge(sourceArray, start, middle, end);
    }
}

#endif //SORTER_MERGESORTING_HH
