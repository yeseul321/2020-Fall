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

void arrayPrint(int arr[]) { //배열 출력하는 함수
	int size = sizeof(arr);
	printf("출력: [ ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("] \n");
}

void selectionSort(int arr[], int size) { //선택정렬
	int minindex;
	int i, j;
	for (i = 0; i < size - 1; i++) {
		minindex = i; //첫번째 인덱스를 최소값으로 잡고
		for (j = i + 1; j < size; j++) {  //두번째 인덱스부터 값을 비교하여 최소값을 재정비
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		swap(&arr[i], &arr[minindex]);
		if (cnt < 5) { //5개의 스텝 출력
			printf("%d번째 스텝 ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
		
	}
	printf("\n최종 결과 ");
	arrayPrint(arr);
	cnt = 0;
}

void bubbleSort(int arr[], int size) { //버블정렬
	int i, j;
	for (i = size - 1; i > 0; i--) { 
		for (j = 0; j < i; j++) { //인접해있는 두 배열요소를 비교하여 작으면 왼쪽으로 정렬
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
			if (cnt < 5) {
				printf("%d번째 스텝 ", cnt + 1);
				arrayPrint(arr);
				cnt++;
			}
		}
	} //최대값이 마지막 인덱스에 들어가면 그 인덱스를 제외하고 정렬
	printf("\n최종 결과 ");
	arrayPrint(arr);
	cnt = 0;
}
				

void insertionSort(int arr[], int size) { //삽입정렬
	int i, j, key;

	for (i = 1; i < size; i++) {
		key = arr[i]; //기준이 되는 값 지정
		j = i - 1; 
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		if (cnt < 5) {
			printf("%d번째 스텝 ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
	}
	printf("\n최종 결과 ");
	arrayPrint(arr);
	cnt = 0;
}

void merge(int arr[], int left, int mid, int right) { //구간이 나뉘어 정렬되었던 배열을 합치는 함수
	

	int i = left;
	int j = mid+1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) { //각 정렬된 배열의 첫번째값부터 비교하며
			temparr[k] = arr[j]; //또 다른 배열에 차례대로 넣어준다
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
		
	
	for (int l = left; l <= right; l++) //또 다른 배열에 정렬되어있던 수들을 다시 원래 배열로 옮긴다.
		arr[l] = temparr[l];

}

void mergeSort(int arr[], int left, int right) { //병합정렬
	int mid = (left + right) / 2;

	if (cnt < 5) { //스텝출력

		printf("%d번째 스텝 \n", cnt + 1);

		printf("좌변: [ ");
		for (int i = left; i <= mid; i++) {
			printf("%d ", arr[i]);
		}
		printf("]      ");

		printf("우변: [ ");
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

int partition(int arr[], int left, int right) { //quick sort를 위해 pivot을 정하고 구간을 나누는 함수
	int pivot = left; //pivot은 제일 배열의 제일 왼쪽에 있는 값으로 지정

	int low = left+1; //pivot을 제외한 배열의 제일 왼쪽값을 left로 지정
	int high = right; //제일 오른쪽값을 right로 지정

	while (low <= high) {
		while (arr[low] <= arr[pivot] && low <= right) {
			low++;			
		}
		while (arr[high] >= arr[pivot] && high >= left+1) {
			high--;
			
		}

		if (low < high) { //low가 가리키는 값이 pivot보다 크면서 high가 가리키는 값이 pivot보다 작은 수 인데 low<high라면 두개의 요소를 swap
			swap(&arr[low], &arr[high]);
		}
	}
	
	swap(&arr[left], &arr[high]); 

	return high; //다음 pivot의 값을 리턴
}

void quickSort(int arr[], int left, int right) { //퀵정렬

	if (left <= right) {
		int p = partition(arr, left, right); //이전 정렬에서 리턴받은 high값

		if (cnt < 5) {
			printf("%d번째 스텝 \n", cnt + 1);

			printf("좌변: [ ");
			for (int i = 0; i <= p - 1; i++) {
				printf("%d ", arr[i]);
			}
			printf("]    ");

			printf("    %d (Pivot)    ", arr[p]);

			printf("우변: [ ");
			for (int i = p + 1; i < 8; i++) {
				printf("%d ", arr[i]);
			}
			printf("] \n");

			cnt++;
		}

		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right); // partition을 통해 나누어진 두개의 배열을 재귀함수를 통해 각각 정렬

		
	}

}

void heapify(int arr[], int size, int i) { //배열 arr을 힙의 모양으로 만드는 함수
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
	//여기까지 제일 최대값을 찾았다면 제일 첫번째 값으로 옮겨준다.

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest); //largest값을 첫값으로 갖는 heap의 모양을 다시 만들어서 반복.
	}

}

void buildheap(int arr[], int size) { //최대힙구조를 만들어주는 함수
	
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
	
}

void heapSort(int arr[], int size) { //힙정렬

	buildheap(arr, size);

	for (int i = size - 1; i >= 0; i--) {
		
		swap(&arr[0], &arr[i]); //올림차순을 위해 최솟값부터 배열의 첫번째 원소로 넣어준다.
		heapify(arr, i, 0);

		if (cnt < 5) {
			printf("%d번째 스텝 ", cnt + 1);
			arrayPrint(arr);
			cnt++;
		}
	}

}

int main() {
	int Q[8] = { 12, 70, 30, 20, 55, 25, 40 ,50 };
	int input[8] = { 0, };
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	printf("최초 입력: [ ");
	for (int i = 0; i < 8; i++) {
		printf("%d ", Q[i]);
	}
	printf("] \n");
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int)*8);
	printf("<선택 정렬> \n\n");
	selectionSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<버블 정렬> \n\n");
	bubbleSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<삽입 정렬> \n\n");
	insertionSort(input, 8);

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<병합 정렬> \n\n");
	mergeSort(input, 0, 7);
	printf("\n최종 결과 ");
	arrayPrint(input);
	cnt = 0;
	
	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<퀵 정렬> \n\n");
	quickSort(input, 0, 7);
	printf("\n최종 결과 ");
	arrayPrint(input);
	cnt = 0;

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	memcpy(input, Q, sizeof(int) * 8);
	printf("<힙 정렬> \n\n");
	heapSort(input, 8);
	printf("\n최종 결과 ");
	arrayPrint(input);
	cnt = 0;

	printf("\n----------------------------------------------------------------------------------------------------\n\n");

	return 0;
}