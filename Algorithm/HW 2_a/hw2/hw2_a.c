#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnt = 0;
int temparr[8];

void swap(int* a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}

void arrayPrint(int arr[]) {
	int size = sizeof(arr);
	printf("���: [ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("] \n");
}

void selectionSort(int arr[], int size) { //��������
	int minindex;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		minindex = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		swap(&arr[i], &arr[minindex]);
		if (cnt < 5) {
			printf("%d��° ���� ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
		
	}
	printf("\n���� ��� ");
	arrayPrint(arr);
	cnt = 0;
}

void bubbleSort(int arr[], int size) { //��������
	int i, j;
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
			if (cnt < 5) {
				printf("%d��° ���� ", cnt + 1);
				arrayPrint(arr);
				cnt++;
			}
		}
	}
	printf("\n���� ��� ");
	arrayPrint(arr);
	cnt = 0;
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
		if (cnt < 5) {
			printf("%d��° ���� ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
	}
	printf("\n���� ��� ");
	arrayPrint(arr);
	cnt = 0;
}

void merge(int arr[], int left, int mid, int right) {
	

	int i = left;
	int j = mid+1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			temparr[k] = arr[j];
			j++;
			k++;
		}
		else {
			temparr[k] = arr[i];
			i++;
			k++;
		}
	}

	if (i > mid) {
		while (1) {
			if (j > right)
				break;
			temparr[k] = arr[j];
			j++;
			k++;
		}
	}
	if (j > right) {
		while (1) {
			if (i > mid)
				break;
			temparr[k] = arr[i];
			i++;
			k++;
		}
	}
		
	
	for (int l = left; l <= right; l++)
		arr[l] = temparr[l];

}

void mergeSort(int arr[], int left, int right) { //��������
	int mid = (left + right) / 2;

	if (cnt < 5) {

		printf("%d��° ���� \n", cnt + 1);

		printf("�º�: [ ");
		for (int i = left; i <= mid; i++) {
			printf("%d ", arr[i]);
		}
		printf("]      ");

		printf("�캯: [ ");
		for (int i = mid + 1; i <= right; i++) {
			printf("%d ", arr[i]);
		}
		printf("] \n");

		cnt++;
	}
	

	if (left < right) {
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	
	
}

int partition(int arr[], int left, int right) {
	int pivot = left;

	int low = left+1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= arr[pivot] && low <= right) {
			low++;			
		}
		while (arr[high] >= arr[pivot] && high >= left+1) {
			high--;
			
		}

		if (low < high) {
			swap(&arr[low], &arr[high]);
		}
	}
	
	swap(&arr[left], &arr[high]);

	return high;
}

void quickSort(int arr[], int left, int right) { //������

	if (left <= right) {
		int p = partition(arr, left, right);

		if (cnt < 5) {
			printf("%d��° ���� \n", cnt + 1);

			printf("�º�: [ ");
			for (int i = 0; i <= p - 1; i++) {
				printf("%d ", arr[i]);
			}
			printf("]    ");

			printf("    %d (Pivot)    ", arr[p]);

			printf("�캯: [ ");
			for (int i = p + 1; i < 8; i++) {
				printf("%d ", arr[i]);
			}
			printf("] \n");

			cnt++;
		}

		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);

		
	}

}

void heapify(int arr[], int size, int i) {
	int largest = i;
	int left_index = 2 * i + 1;
	int right_index = 2 * i + 2;

	if (left_index < size) {
		if (arr[left_index] > arr[largest]) {
			largest = left_index;
		}
	}
	if (right_index < size) {
		if (arr[right_index] > arr[largest]) {
			largest = right_index;
		}
	}

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}

}

void buildheap(int arr[], int size) {
	
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
	
}

void heapSort(int arr[], int size) { //������

	buildheap(arr, size);

	for (int i = size - 1; i >= 0; i--) {
		
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);

		if (cnt < 5) {
			printf("%d��° ���� ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
	}

}

int main() {
	int Q[8] = { 12, 70, 30, 20, 55, 25, 40 ,50 };
	int input[8] = { 0, };
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	printf("���� �Է�: [ ");
	for (int i = 0; i < 8; i++) {
		printf("%d ", Q[i]);
	}
	printf("] \n");
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int)*8);
	printf("<���� ����> \n\n");
	selectionSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<���� ����> \n\n");
	bubbleSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<���� ����> \n\n");
	insertionSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<���� ����> \n\n");
	mergeSort(input, 0, 7);
	printf("\n���� ��� ");
	arrayPrint(input);
	cnt = 0;
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<�� ����> \n\n");
	quickSort(input, 0, 7);
	printf("\n���� ��� ");
	arrayPrint(input);
	cnt = 0;

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<�� ����> \n\n");
	heapSort(input, 8);
	printf("\n���� ��� ");
	arrayPrint(input);
	cnt = 0;

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	return 0;
}