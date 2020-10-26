# include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j, v;

  for(i = 0; i < n; i++) {
      v = arr[i];
      j = i-1;

      while(j >= 0 && arr[j] > v) {
        arr[j+1] = arr[j];
        j--;
      }

      arr[j+1] = v;
  }

  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
}


void main() {
    int arr[] = {6,4,1,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("length: %d \n", n);

    printf("Insertion Sort를 진행한 결과: ");
    insertionSort(arr, n);
    printf("\n");
}