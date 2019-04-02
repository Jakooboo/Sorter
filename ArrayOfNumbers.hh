//
// Created by jakub on 19.03.19.
//

#ifndef SORTER_ARRAYOFNUMBERS_HH
#define SORTER_ARRAYOFNUMBERS_HH


#include "OrderOfArray.hh"
#include <iostream>
#include <ctime>
#include <random>
#include <cmath>

const unsigned long int DEFAULT_ARRAY_SIZE = 50;

template <class typeOfArray>
class ArrayOfNumbers {
private:

    const unsigned long int sizeOfArray;
    typeOfArray* generateRandomArray();
    typeOfArray* generatePartlyRandomArray(float sortedPart);
    typeOfArray* generateInvertedArray();
    typeOfArray* generateOrderedArray();

public:
    ArrayOfNumbers();
    ArrayOfNumbers(const unsigned int size, orderOfArray A);
    ArrayOfNumbers(typeOfArray* pointer, const unsigned int size);
    void checkOrder();
    unsigned long int returnSizeOfArray();
    typeOfArray* returnPointerToArray();
    typeOfArray* pointerToArray;

    virtual ~ArrayOfNumbers();

    void printArray();
};
/*Generator domyslny, tworzy tablice liczb o rozmiarze DEFAULT_ARRAY_SIZE*/
template<class typeOfArray>
ArrayOfNumbers<typeOfArray>::ArrayOfNumbers(): sizeOfArray(DEFAULT_ARRAY_SIZE) {
    for(long int i = 0; i<DEFAULT_ARRAY_SIZE; i++){
        pointerToArray = new typeOfArray[sizeOfArray];
    }
}

/*Konstruktor z parametrami rozmiar i porzadek ulozenia*/
template<class typeOfArray>
ArrayOfNumbers<typeOfArray>::ArrayOfNumbers(const unsigned int size, orderOfArray A):sizeOfArray(size) {
    switch (A){
        case randomOrder:
            pointerToArray=generateRandomArray();
            break;
        case invertedOrder:
            pointerToArray=generateInvertedArray();
            break;
        case partlyRandomOrder25:
            pointerToArray=generatePartlyRandomArray(25.0);
            break;
        case partlyRandomOrder50:
            pointerToArray=generatePartlyRandomArray(50.0);
            break;
        case partlyRandomOrder75:
            pointerToArray=generatePartlyRandomArray(75.0);
            break;
        case partlyRandomOrder95:
            pointerToArray=generatePartlyRandomArray(95.0);
            break;
        case partlyRandomOrder99:
            pointerToArray=generatePartlyRandomArray(99.0);
            break;
        case partlyRandomOrder99_7:
            pointerToArray=generatePartlyRandomArray(99.7);
            break;
        case inOrder:
            pointerToArray=generateOrderedArray();
            break;
        default:
            std::cout << "Bledna wartosc" << std::endl;
    }
}

/*Metod do wypelniania tablicy losowymi liczbami*/
template<class typeOfArray>
typeOfArray *ArrayOfNumbers<typeOfArray>::generateRandomArray() {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<typeOfArray> distribution(std::numeric_limits<typeOfArray>::min(), std::numeric_limits<typeOfArray>::max());//Tutaj jest rzutowanie, do poprawy jak sie dowiem o rozmiarze liczb

    typeOfArray* pointer = new typeOfArray[sizeOfArray];
    for(int i = 0; i<sizeOfArray; i++)
    {
        pointer[i]=distribution(generator);
    }
    return pointer;
}

template<class typeOfArray>
void ArrayOfNumbers<typeOfArray>::printArray() {
    std::cout << "\nTablica:\n";
    for(int i=0; i<sizeOfArray; i++){
        std::cout << pointerToArray[i] << " ";
    }
}

template<class typeOfArray>
ArrayOfNumbers<typeOfArray>::~ArrayOfNumbers() {
    delete pointerToArray;
    //std::cout << "destruktor" << std::endl;
}

 template<class typeOfArray>
 typeOfArray *ArrayOfNumbers<typeOfArray>::generatePartlyRandomArray(float sortedPart) {
     typeOfArray* pointer = new typeOfArray[sizeOfArray];
     long long int sortedElementsOfArray = static_cast<long long int>(sortedPart * this->sizeOfArray / 100);
     //std::cout << "sortedElemetsOfArray: " << sortedElementsOfArray << std::endl;
     //std::cout << "leftElemetsOfArray: " << leftElementsOfArray << std::endl;
     float ratio = static_cast<float>(static_cast<float>(this->sizeOfArray) / (static_cast<float>(std::numeric_limits<typeOfArray>::max()) - static_cast<float>(std::numeric_limits<typeOfArray>::min())));//stosuenk rozmiaru tablicy do zakresu typu danych
     if (ratio<=1){
         //std::cout << "Mieszcze sie" << std::endl;
         for (int i = 0; i < sortedElementsOfArray; i++) {
             pointer[i] = std::numeric_limits<typeOfArray>::min() + i;
             //std::cout << "W miejsce: " << i << " wpisuje: " << pointer[i] << std::endl;
         }
     }
     else if (ratio > 1) {
         //std::cout << "Nie mieszcze sie << std::endl";
         int roundedRatio = static_cast<int>(ceil(ratio));
         for (int i = 0; i < sortedElementsOfArray; i++){
         //modulo
             pointer[i] = std::numeric_limits<typeOfArray>::min() + (i/roundedRatio);
             //std::cout << "W miejsce: " << i << " wpisuje: " << pointer[i] << std::endl;
         }
     }
     else std::cerr << "Blad przy liczeniu proporcji" << std::endl;
     std::random_device device;
     std::mt19937 generator(device());
     std::uniform_int_distribution<typeOfArray> distribution(std::numeric_limits<typeOfArray>::min(), std::numeric_limits<typeOfArray>::max());
     for(int i = sortedElementsOfArray-1; i<sizeOfArray; i++)
     {
         pointer[i]=distribution(generator);
         //std::cout << "Losowo w miejsce: " << i << " wpisuje: " << pointer[i] << std::endl;
     }
     return pointer;
 }

template<class typeOfArray>
void ArrayOfNumbers<typeOfArray>::checkOrder() {
     for(int i = 0; i<sizeOfArray-1; i++){
         if(pointerToArray[i]>pointerToArray[i+1]){
            std::cout << "zle posegregowane w miejcu:" << i+1 << std::endl;
            break;
         }
     }
}

template<class typeOfArray>
typeOfArray *ArrayOfNumbers<typeOfArray>::generateInvertedArray() {
    typeOfArray* pointer = new typeOfArray[sizeOfArray];
    float ratio = static_cast<float>(static_cast<float>(this->sizeOfArray) / (static_cast<float>(std::numeric_limits<typeOfArray>::max()) - static_cast<float>(std::numeric_limits<typeOfArray>::min())));//stosuenk rozmiaru tablicy do zakresu typu danych
    if (ratio<=1){
        //std::cout << "Mieszcze sie" << std::endl;
        for (int i = 0; i < sizeOfArray; i++) {
            pointer[i] = std::numeric_limits<typeOfArray>::max() - i;
        }
    }
    else if (ratio > 1) {
        //std::cout << "Nie mieszcze sie << std::endl";
        int roundedRatio = static_cast<int>(ceil(ratio));
        for (int i = 0; i < sizeOfArray; i++){
            //modulo
            pointer[i] = std::numeric_limits<typeOfArray>::max() - (i/roundedRatio);
        }
    }
    else std::cerr << "Blad przy liczeniu proporcji" << std::endl;
    return pointer;
}

template<class typeOfArray>
typeOfArray *ArrayOfNumbers<typeOfArray>::generateOrderedArray() {
    typeOfArray* pointer = new typeOfArray[sizeOfArray];
    float ratio = static_cast<float>(static_cast<float>(this->sizeOfArray) / (static_cast<float>(std::numeric_limits<typeOfArray>::max()) - static_cast<float>(std::numeric_limits<typeOfArray>::min())));//stosuenk rozmiaru tablicy do zakresu typu danych
    if (ratio<=1){
        //std::cout << "Mieszcze sie" << std::endl;
        for (int i = 0; i < sizeOfArray; i++) {
            pointer[i] = std::numeric_limits<typeOfArray>::min() + i;
        }
    }
    else if (ratio > 1) {
        //std::cout << "Nie mieszcze sie << std::endl";
        int roundedRatio = static_cast<int>(ceil(ratio));
        for (int i = 0; i < sizeOfArray; i++){
            //modulo
            pointer[i] = std::numeric_limits<typeOfArray>::min() + (i/roundedRatio);
        }
    }
    else std::cerr << "Blad przy liczeniu proporcji" << std::endl;
    return pointer;
}

template<class typeOfArray>
unsigned long int ArrayOfNumbers<typeOfArray>::returnSizeOfArray() {
    return this->sizeOfArray;
}

template<class typeOfArray>
typeOfArray *ArrayOfNumbers<typeOfArray>::returnPointerToArray() {
    return pointerToArray;
}

template<class typeOfArray>
ArrayOfNumbers<typeOfArray>::ArrayOfNumbers(typeOfArray *pointer, const unsigned int size):sizeOfArray(size) {
    pointerToArray=pointer;
}


#endif //SORTER_ARRAYOFNUMBERS_HH
