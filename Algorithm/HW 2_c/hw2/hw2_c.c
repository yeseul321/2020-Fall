#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

clock_t start, end;  //���۽ð��� ���ð��� �˱����� ����
float temparr[20000];

void swap(float* a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;

}

void arrayPrint(float arr[]) {
	int size = sizeof(arr);
	printf(" : [ ");
	for (int i = 0; i < size; i++) {
		printf("%.3f ", arr[i]);
	}
	printf("] \n");
}

void selectionSort(float arr[], int size) { //��������
	
	int minindex;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		minindex = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		swap(&arr[i], &arr[minindex]);
		
	}
	
}

void bubbleSort(float arr[], int size) { //��������
	int i, j;
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	
}
				

void insertionSort(float arr[], int size) { //��������
	int i, j;
	float key;

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

void merge(float arr[], int left, int mid, int right) {
	

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

void mergeSort(float arr[], int left, int right) { //��������
	int mid = (left + right) / 2;
	

	if (left < right) {
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	
	
}

int partition(float arr[], int left, int right) {
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

void quickSort(float arr[], int left, int right) { //������

	if (left <= right) {
		int p = partition(arr, left, right);

		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);

		
	}

}

void heapify(float arr[], int size, int i) {
	int largest = i;
	int left_index = 2*i + 1;
	int right_index = 2*i + 2;

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

void buildheap(float arr[], int size) {
	for (int i = size/2-1; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

void heapSort(float arr[], int size) { //������

	buildheap(arr, size);
	
	for(int i = size-1; i >=0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr,i,0);
	}

}

void init_array(float arr[], float res[], int size) {
	for (int i = 0; i < size; i++) {
		res[i] = arr[i];
	}
}


int main() {

	double result;
	srand(50); 

	for (int n = 1000; n <= 20000; n += 1000) {
		float * Q = malloc(sizeof(float)*n); //�����޸��Ҵ�
		for (int i = 0; i < n; i++) {
			Q[i] = (float)(((float)rand()*2.0f - RAND_MAX) / RAND_MAX); 
		}

		float * input = malloc(sizeof(float)*n);

		init_array(Q, input, n);
		printf("\n\n<���� ����> ");
		start = clock(); //������ ������ �� �ð�
		selectionSort(input, n);
		end = clock(); //������ ���� ���� �ð�
		result = (double)(end - start); //�����ϴµ� �ɸ� �ð�
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		init_array(Q, input, n);
		printf("\n\n<���� ����> ");
		start = clock();
		bubbleSort(input, n);
		end = clock();
		result = (double)(end - start);
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		init_array(Q, input, n);
		printf("\n\n<���� ����> ");
		start = clock();
		insertionSort(input, n);
		end = clock();
		result = (double)(end - start);
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		init_array(Q, input, n);
		printf("\n\n<���� ����> ");
		start = clock();
		mergeSort(input, 0, n - 1);
		end = clock();
		result = (double)(end - start);
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		init_array(Q, input, n);
		printf("\n\n<�� ����> ");
		start = clock();
		quickSort(input, 0, n - 1);
		end = clock();
		result = (double)(end - start);
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		init_array(Q, input, n);
		printf("\n\n<�� ����> ");
		start = clock();
		heapSort(input, n);
		end = clock();
		result = (double)(end - start);
		printf("%d���� �Է� ó�� �ð�: %.1lf ms\n", n, result);

		free(Q);
		free(input);  //�����޸𸮸� �Ҵ������Ƿ� free�� ���־����.

		printf("\n\n========================================================================\n\n");
	}
	

	return 0;
}