# include <stdio.h>

int binarySearch(int arr[], int n, int K) {
  int l = 0;
  int r = n-1;

  while(l <= r) {
      int m = (l + r) / 2;

      if( K == arr[m] ) {
          return m;
      } else if ( K > arr[m] ) {
          l = m+1;
      } else {
          r = m-1;
      }
  }
  
  return -1;
}


void main() {
    int arr[] = {3,14,27,31,39,42,55,70,74,81,85,93,98};
    int n = sizeof(arr)/sizeof(arr[0]);
    int K = 70;

    printf("Binary Search를 통해 얻어진 70의 인덱스 번호 = %d", binarySearch(arr, n, K));
    printf("\n");
}