//
// Created by jakub on 02.04.19.
//

#ifndef SORTER_INTROSORT_HH
#define SORTER_INTROSORT_HH

#include <cmath>
#include <algorithm>

/*
template <typename typeOfDataInArray>
long int ChoosePivotForQuickSort(typeOfDataInArray *sourceArray, long int start, long int over){
    //Increasing perfomance of sorting already sorted list
    long int middle = (start/2)+(over/2);
    if (sourceArray[middle]<sourceArray[start]) std::swap(sourceArray[start],sourceArray[middle]);
    if (sourceArray[over]<sourceArray[start]) std::swap(sourceArray[start],sourceArray[over]);
    if (sourceArray[middle]<sourceArray[over]) std::swap(sourceArray[middle],sourceArray[over]);
    return over;
}*/

long int iParent(long int i);

long int iLeftChild(long int i);

long int iRightChild(long int i);

template <typename typeOfDataInArray>
void ShiftDown(typeOfDataInArray* sourceArray, long int start, long int end){
    long int root = start;
    while (iLeftChild(root)<=end){
        long int child = iLeftChild(root);
        long int swap = root;

        if (sourceArray[swap]<sourceArray[child]) swap=child;
        if (child+1<=end && sourceArray[swap] < sourceArray[child+1]) swap = child+1;
        if (swap == root) return;
        else {
            std::swap(sourceArray[root], sourceArray[swap]);
            root = swap;
        }

    }
}

template <typename typeOfDataInArray>
void BuildHeap(typeOfDataInArray* sourceArray, long int sizeOfArray){
    long int start = iParent(sizeOfArray-1);
    while(start>=0){
        ShiftDown(sourceArray, start, sizeOfArray-1);
        start--;
    }
}


template <typename typeOfDataInArray>
void HeapSort(typeOfDataInArray* sourceArray, long int sizeOfArray){
    BuildHeap(sourceArray, sizeOfArray);
    long int end = sizeOfArray-1;
    while(end>0){
        std::swap(sourceArray[end],sourceArray[0]);
        end--;
        ShiftDown(sourceArray,0,end);
    }
}



template <typename typeOfDataInArray>
void IntroSortRecursive(typeOfDataInArray* sourceArray, long int maxDepth, long int start, long int over){
    long int length = over-start+1;
    long int middle = (start+over)/2;
    long int position = middle;

    if (length<=1) return;
    else if(maxDepth==0) HeapSort(sourceArray,length);
    else {
        IntroSortRecursive(sourceArray, maxDepth-1, start, position);
        IntroSortRecursive(sourceArray, maxDepth-1, position+1, over);
    }
}

template <typename typeOfDataInArray>
void IntroSort(typeOfDataInArray* sourceArray, long int sizeOfArray){
    long int maxDepth = static_cast<long int>(log10(sizeOfArray)) * 2;
    IntroSortRecursive(sourceArray, maxDepth, 0, sizeOfArray-1);

}



#endif //SORTER_INTROSORT_HH
