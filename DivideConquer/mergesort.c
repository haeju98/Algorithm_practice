# include <stdio.h>
int sorted[8]; // 정렬된 배열


/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int list[], int left, int mid, int right) {
  int i, j, k, l;
  i = left; // i: 정렬된 왼쪽 리스트에 대한 인덱스
  j = mid+1; // j: 정렬된 오른쪽 리스트에 대한 인덱스
  k = left; // k: 정렬될 리스트에 대한 인덱스

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){  // i=0, j=1, mid=0, right=1, {21, 10}
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else  // list[0] > list[1]
      sorted[k++] = list[j++]; // sorted[0] = list[1] -> k=1, j=2
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){ // i=0, mid=0
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else {
    for(l=i; l<=mid; l++) // i=0, mid=0
      sorted[k++] = list[l]; // sorted[1] = list[0]
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right) {
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

void main() {
  int i;
  int list[8] = {21, 10, 12, 20, 25, 13, 15, 22};

  // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
  merge_sort(list, 0, 7);

  // 정렬 결과 출력
  for(i=0; i<8; i++) {
    printf("%d\n", list[i]);
  }
}