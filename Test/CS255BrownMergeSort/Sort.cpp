#pragma
#include "Sort.h"

Sort::Sort(int sz) {
	items = new int[sz];
	size = sz;
}

Sort::~Sort() {
	delete[] items;
}

void Sort::_bubbleSort(int* sorted) {
	int swap;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (sorted[j] > sorted[j + 1]) {
				swap = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = swap;
			}
		}
	}
}

int* Sort::bubbleSort() {
	int* sorted = clone();
	_bubbleSort(sorted);
	return sorted;
}

void Sort::_selectionSort(int* sorted) {
	int min, swap;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (sorted[j] < sorted[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap = sorted[min];
			sorted[min] = sorted[i];
			sorted[i] = swap;
		}
	}
}

int* Sort::selectionSort() {
	int* sorted = clone();
	_selectionSort(sorted);
	return sorted;
}

void Sort::_insertionSort(int* sorted) {
	int curr;
	int swap;
	for (int i = 1; i < size; i++) {
		swap = sorted[i];
		curr = i;
		while ((curr > 0) && (sorted[curr - 1] > swap)) {
			sorted[curr] = sorted[curr - 1];
			curr--;
		}
		sorted[curr] = swap;
	}
}

int* Sort::insertionSort() {
	int* sorted = clone();
	_insertionSort(sorted);
	return sorted;
}

void Sort::_quickSort(int* sorted, int left, int right) {
	int pivot;
	if (left < right) {
		pivot = lamutoPartition(sorted, left, right);
		_quickSort(sorted, left, pivot - 1);
		_quickSort(sorted, pivot + 1, right);
	}
}

int* Sort::quickSort() {
	int* sorted = clone();
	_quickSort(sorted, 0, size - 1);
	return sorted;
}

void Sort::choosePivot(int* sorted, int left, int right) {
	int mid = (left + right) / 2;
	int swap = sorted[left];
	sorted[left] = sorted[mid];
	sorted[mid] = swap;
}

int Sort::lamutoPartition(int* sorted, int left, int right) {
	int swap;
	choosePivot(sorted, left, right);	//Avoid the worst case

	int pivot = sorted[left];
	int lastS1 = left;

	for (int unk = left + 1; unk <= right; unk++) {
		if (pivot > sorted[unk]) {
			lastS1++;
			swap = sorted[unk];
			sorted[unk] = sorted[lastS1];
			sorted[lastS1] = swap;
		}
	}

	swap = sorted[left];
	sorted[left] = sorted[lastS1];
	sorted[lastS1] = swap;

	return lastS1;
}


void Sort::_mergeSort(int* A, int left, int right) {
	// get the size of the array based on the position
	int n = right - left;

	// get the middle point
	int mid = n / 2;

	// get the extra for the array if not even
	int midExtra = (n % 2 != 0) ? (n - mid) : mid;

	int* B = new int[midExtra];
	int* C = new int[mid];

	if (n > 1) {

		for (int i = 0; i < n; ++i) {
			if (i >= (n / 2)) {
				B[i - mid] = A[i];
			}
			else {a
				C[i] = A[i];
			}
		}

		_mergeSort(B, 0, midExtra);
		_mergeSort(C, 0, mid);
		_merge(B, C, A, midExtra, mid);
		delete[] B;
		delete[] C;
	}
}


void Sort::_merge(int* B, int* C, int* A, int p, int q) {
	int i = 0, j = 0, k = 0;

	while (i < p && j < q) {
		if (B[i] <= C[j]) {
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = C[j];
			j++;
		}
		k++;
	}

	if (i == p) {
		while (j < q && k < (p + q) ) {
			A[k] = C[j];
			j++;
			k++;
		}
	}
	else {
		while (i < p && k < (p + q)) {
			A[k] = B[i];
			k++;
			i++;
		}
	}
}

int* Sort::mergeSort() {
	int* sorted = clone();
	_mergeSort(sorted, 0 , size);
	return sorted;
}


int* Sort::clone() {
	int* sorted = new int[size];
	for (int i = 0; i < size; i++) {
		sorted[i] = items[i];
	}
	return sorted;
}

void Sort::addData(int index, int data) {
	items[index] = data;
}

int Sort::getData(int index) {
	return items[index];
}

int Sort::getSize() {
	return size;
}