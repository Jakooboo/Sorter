//
// Created by jakub on 02.04.19.
// Inspirowano sie:
// https://en.wikipedia.org/wiki/Quicksort
//

#ifndef SORTER_QUICKSORT_HH
#define SORTER_QUICKSORT_HH

#include <algorithm>




template<typename typeOfDataInArray>
long int Split(typeOfDataInArray* sourceArray, long int start, long int over){
    long int middle = (start+over)/2;
    typeOfDataInArray pivot = sourceArray[middle];
    long int i = start;
    for(int j = start; j<=over-1; j++){
        if (sourceArray[j] < pivot){
            std::swap(sourceArray[i],sourceArray[j]);
            i++;
        }
    }
    std::swap(sourceArray[i], sourceArray[over]);
    return i;
}

template<typename typeOfDataInArray>
void QuickSort(typeOfDataInArray* sourceArray, long int start, long int over){
    if (start<over){
        long int p = Split(sourceArray, start, over);
        QuickSort(sourceArray, start, p-1);
        QuickSort(sourceArray, p+1, over);
    }
}

#endif //SORTER_QUICKSORT_HH
