//SORT.H
/*
    Sort.h / Sort/*
    Sort.h
    Create a sort class, handle bubble, selection, insertion, quick and merge sorts
    7.14.18
*/

#if !defined SORT_H
#define SORT_H

class Sort
{
    private:
        int* items;
        int size;
        int* clone ();

        //Provide private complex functions for sorts...
        void _bubbleSort (int* sorted);
        void _selectionSort (int* sorted);
        void _insertionSort (int* sorted);
        void _quickSort (int* sorted, int left, int right);
        
        //Functions for Merge Sort
        void _mergeSort(int* A, int left, int right);
<<<<<<< Updated upstream
        void _merge(int* A, int* B, int* C, int left, int right);
=======
        void _merge(int* A, int* B, int* C, int p, int q);
>>>>>>> Stashed changes

        //Functions for Quick Sort
        void choosePivot (int* sorted, int left, int right);
        int lamutoPartition (int* sorted, int left, int right);
    public:
        Sort (int sz);
        ~Sort ();
        int* bubbleSort ();
        int* selectionSort ();
        int* insertionSort ();
        int* quickSort ();
        int* mergeSort ();


        void addData (int index, int data);
        int getData (int index);
        int getSize ();
};

#endif