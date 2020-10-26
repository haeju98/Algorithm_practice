#include <stdio.h>
#define MAX 1001

int matrix[MAX][MAX];
int visited[MAX * MAX];


// 반복문을 통한 DFS 구현
void DFS_recursion (int v, int N) {
	// 정점 출력
	printf("%d ", v);
	
	// 방문 표시
	visited[v] = 1;
	
	// 인접 정점 체크
	for (int d = 1; d <= N; d++) {
		// 방문하지 않았고 이동 가능하다면
		if (!visited[d] && matrix[v][d]) {
			DFS_recursion(d, N);
		}
	}
}


// 스택을 이용한 DFS 구현
void DFS_stack(int v, int N)
{
    // 스택에 관련된 변수 선언
    int top = -1;
    int stack[MAX * MAX] = { 0, };
    
    // 방문 표시
	visited[v] = 1;

    // 시작 노드를 stack에 push
    top++;
    stack[top] = v;
 
    while(top != -1)
    {
        // pop
        int popnode = stack[top];
        printf("%d ", popnode);
        top--;
       
        // 인접 정점 체크
		for (int d = N; d >= 1; d--) {
			// 방문하지 않았고, 이동이 가능하다면 push
			if (!visited[d] && matrix[popnode][d]) {
                    // 방문 표시
	                visited[d] = 1;

                    top++;
                    stack[top] = d;
            }
        }
    }
}


// 큐를 이용한 BFS 구현
void BFS (int v, int N) {
	// 큐에 관련된 변수 선언
	int front = -1, rear = -1;
	int queue[MAX * MAX] = { 0, };
	
	// 첫번째 추가
	rear++;
	queue[rear] = v;
	
	// 방문 표시
	visited[v] = 1;
	
	// 출력
	printf("%d ", v);
	
	// 너비 우선 탐색
	while (front < rear) {
		// dequeue
		front++;
		int nextV = queue[front];
		
		// 인접 정점 체크
		for (int d = 1; d <= N; d++) {
			// 방문하지 않았고, 이동이 가능하다면 enqueue
			if (!visited[d] && matrix[nextV][d]) {
				rear++;
				visited[d] = 1;
				queue[rear] = d;
				
				printf("%d ", d);
			}
		}
	}
}

void init (int N) {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

int main(void) {
	int N = 0; // 정점의 개수
	int M = 0; // 간선의 개수
	int V = 0; // 시작할 정점의 번호
	
    printf("정점의 개수, 간선의 개수, 시작할 정점의 번호를 입력해주세요: ");
	scanf("%d %d %d", &N, &M, &V);
	
    // 그래프 그리기
	for (int i = 0; i < M; i++) {
		int s = 0;
		int d = 0;
		
        printf("연결할 vertex 두개를 선택해주세요: ");
		scanf("%d %d", &s, &d);
		
		matrix[s][d] = 1;
		matrix[d][s] = 1;
	}
	
    printf("재귀함수를 이용한 DFS 결과: ");
	DFS_recursion(V, N);
	
    // 전부 방문 안한 상태로 다시 설정
	init(N);
	
    printf("stack을 이용한 DFS 결과: ");
    DFS_stack(V, N);

    // 전부 방문 안한 상태로 다시 설정
	init(N);

    printf("queue를 이용한 BFS 결과: ");
	BFS(V, N);
	
	return 0;
}