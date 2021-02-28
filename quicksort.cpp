#include<cstdio>
#include<vector>

using namespace std;

void printVector(vector<int> &arr) {
	vector<int>::iterator i;	
	for(i=arr.begin(); i<arr.end(); i++) {
		printf("%d ", *i);
	}
}

void quicksort(vector<int> &arr, int start, int end) {
	// Exit condition
	if(start<0 || end<0 || start >= end) {
		return;	
	}

	int iter, lastMin, temp;	

	// Select the last element as the pivot
	int pivot = arr[end];
	lastMin = start-1;
	
	for(iter=0; iter<end; iter++) {		
		if(arr[iter] <= pivot) {
			// Increment lastMin index
			lastMin += 1;

			// Swap Values
			temp = arr[iter];
			arr[iter] = arr[lastMin];
			arr[lastMin] = temp;				
		}
	}
	
	// Swap pivot element to its exact position
	lastMin += 1;
	temp = arr[iter];
	arr[iter] = arr[lastMin];
	arr[lastMin] = temp;
	
	quicksort(arr, start, lastMin-1);
	quicksort(arr, lastMin+1, end);
}

int main() {
	vector<int> numbers;
	int count, temp;
	
	printf("Number of elements: ");
	scanf("%d", &count);
	
	for(int i=0; i<count; i++) {
		scanf("%d", &temp);
		numbers.push_back(temp);
	}
	
	quicksort(numbers, 0, numbers.size()-1);
	
	printf("Sorted Vector: ");
	printVector(numbers);

	return 0;
}
