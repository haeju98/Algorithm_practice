# include <stdio.h>
# include <string.h>

int stringmatch(char text[], char pattern[]) {
  int n = strlen(text);
  int m = strlen(pattern);
  printf("n: %d, m: %d\n", n, m);
  int i, j;

  for(i=0; i<=n-m; i++) {
      j = 0;
      while(j<m && pattern[j]==text[i+j])
        j += 1;

      if(j==m)
        return i;
  }

  return -1;
}


void main() {
    char text[10] = "abcdoght";
    char pattern[10] = "dog";

    printf("\'abcdoght\'와 \'dog\'를 대상으로 패턴분석을 진행한 결과: ");
    printf("%d\n", stringmatch(text, pattern));
}