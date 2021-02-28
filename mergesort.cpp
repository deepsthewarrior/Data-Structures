#include<cstdio>
#include<vector>

using namespace std;

void printVec(vector<int> vec) {
	printf("Vector: ");
	for(int i=0; i<vec.size(); i++) {
		printf("%d ", vec[i]);
	}
}

void mergesort(vector<int> &arr, int start, int end) {
	// Recursion Exit Condition
	// When the start and end index are same, return
	if(start >= end) {
		return;
	}
	
	// Split the Array into two 
	int mid = (start + end)/2;
	mergesort(arr, start, mid);
	mergesort(arr, mid+1, end);

	// A temporary vector to store the sorted values	
	vector<int> sorted;
	
	int i, j;
	
	// Merge two vector
	for(i=start, j=mid+1; i<=mid && j<=end; ) {
		if(arr[i] < arr[j]) {
			sorted.push_back(arr[i]);
			i++;
		} else {
			sorted.push_back(arr[j]);
			j++;
		}
	}
	while(i < mid+1) {
		sorted.push_back(arr[i]); 
		i++;
	}
	while(j <= end) {
		sorted.push_back(arr[j]);
		j++;
	}

	// Copy the contents of temporary vector to the main vector
	for(i=start, j=0; i<=end; i++, j++) {
		arr[i] = sorted[j];
	}
	
	return;
}

int main() {
	vector<int> arr;
	int count, val;
	
	printf("Number of elements: ");
	scanf("%d", &count);
	printf("Enter the input values");
	
	for(int i=0; i<count; i++) {
		scanf("%d", &val);
		arr.push_back(val);
	}
	
	mergesort(arr, 0, arr.size()-1);
	
	printVec(arr);
	
	return 0;
}
