#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int size) { //��������
	int minindex;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		minindex = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[minindex])
				minindex = j;

		swap(&arr[i], &arr[minindex]);
	}
}

void bubbleSort(int arr[], int size) { //��������
	int i, j;
	for (i = size - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int size) { //��������
	int i, j, key;

	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void mergeSort(int arr[]) { //��������

}

void quickSort(int arr[]) { //������

}

void heapSort(int arr[]) { //������

}
