#include <iostream>
#include "ArrayOfNumbers.hh"
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "MergeSorting.hh"
#include "Quicksort.hh"
#include "Introsort.hh"


std::vector<std::string> orderTypes = {
        "randomOrder", "partlyRandomOrder25", "partlyRandomOrder50", "partlyRandomOrder75", "partlyRandomOrder95", "partlyRandomOrder99", "partlyRandomOrder99_7", "invertedOrder", "inOrder"
};

int main() {
    auto programStart = std::chrono::system_clock::now();
    std::cout << "Hello, World!" << std::endl;
    int size_of_used_array[] = {10000, 50000, 100000, 500000, 1000000};
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    elapsedTime = 0;
    int i = 0;
    std::fstream file;
    short unsigned int numberOfArrays = 100;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//QuickSort
    {
        char *filename = "reportQ.txt";
        file.open(filename, std::ios::trunc | std::ios::out);
        if (file.good() == true) {
            file << "Raport z programu do sortowania liczb.\n";
            file << "\n\nRodzaj sortowania: QuickSort";
            file.close();
        }
        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: short int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<short int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    QuickSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }
        std::cout << "skonczylem short" << std::endl;

        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    QuickSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem int" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    QuickSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    QuickSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long long" << std::endl;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MergeSort
    {
        char *filename = "reportM.txt";
        file.open(filename, std::ios::trunc | std::ios::out);
        if (file.good() == true) {
            file << "Raport z programu do sortowania liczb.\n";
            file << "\n\nRodzaj sortowania: MergeSort";
            file.close();
        }
        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: short int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<short int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    MergeSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }
        std::cout << "skonczylem short" << std::endl;

        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    MergeSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem int" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    MergeSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    MergeSort(array1.returnPointerToArray(), 0, array1.returnSizeOfArray() - 1);
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long long" << std::endl;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//IntroSort
    {
        char *filename = "reportI.txt";
        file.open(filename, std::ios::trunc | std::ios::out);
        if (file.good() == true) {
            file << "Raport z programu do sortowania liczb.\n";
            file << "\n\nRodzaj sortowania: IntroSort";
            file.close();
        }
        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: short int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<short int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    IntroSort(array1.returnPointerToArray(), array1.returnSizeOfArray());
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }
        std::cout << "skonczylem short" << std::endl;

        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    IntroSort(array1.returnPointerToArray(), array1.returnSizeOfArray());
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem int" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    IntroSort(array1.returnPointerToArray(), array1.returnSizeOfArray());
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long" << std::endl;


        file.open(filename, std::ios::app | std::ios::out);
        if (file.good() == true) {
            file << "\n\nRodzaj liczby: long long int.";
            file.close();
        }
        for (int j = 1; j <= partlyRandomOrder99_7; j++) {
            file.open(filename, std::ios::app | std::ios::out);
            if (file.good() == true) {
                file << "\n\nRodzaj tablicy: " << orderTypes[j] << std::endl;
                file.close();
            }
            for (int k = 0; k <= 4; k++) {
                elapsedTime = 0;
                for (i = 0; i < numberOfArrays; i++) {
                    ArrayOfNumbers<long long int> array1(size_of_used_array[k], orderOfArray(j));
                    start = std::chrono::system_clock::now();
                    IntroSort(array1.returnPointerToArray(), array1.returnSizeOfArray());
                    end = std::chrono::system_clock::now();
                    elapsedTime =
                            elapsedTime + std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                }
                file.open(filename, std::ios::app | std::ios::out);
                if (file.good() == true) {
                    file << "\nRozmiar tablic: " << size_of_used_array[k];
                    file << "\nCzas trwania " << numberOfArrays << " sortowan: " << elapsedTime << "ms.\n";
                    file << "Sredni czas trwania 1 sortowania: " << elapsedTime / i << "ms.";
                    file.close();
                }
            }
        }

        std::cout << "skonczylem long long" << std::endl;
    }


    auto programStop = std::chrono::system_clock::now();
    auto programDuration = std::chrono::duration_cast<std::chrono::milliseconds>(programStop - programStart).count();
    std::cout << "\nCzas dzialania programu: " << programDuration << "ms.\n";

}