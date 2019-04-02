//
// Created by jakub on 02.04.19.
//

#include "Introsort.hh"


long int iParent(long int i){
    return floor((i-1)/2);
}

long int iLeftChild(long int i){
    return 2*i+1;
}

long int iRightChild(long int i){
    return 2*i+2;
}