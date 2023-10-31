#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
int visited[MAX_VERTICES];
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


void dfs_mat(GraphType* g, int v)
{
	int w;
	visited[v] = true;		// 정점 v의 방문 표시 
	printf("%d ", v);		// 방문한 정점 출력
	for (w = 0; w < g->n; w++) 		// 인접 정점 탐색
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);	//정점 w에서 DFS 새로 시작
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 11; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 5);
	insert_edge(g, 0, 6);
	insert_edge(g, 0, 9);
	insert_edge(g, 1, 4);
	insert_edge(g, 1, 5);
	insert_edge(g, 1, 7);
	insert_edge(g, 1, 10);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);
	insert_edge(g, 4, 6);
	insert_edge(g, 4, 7);
	insert_edge(g, 6, 7);
	insert_edge(g, 6, 8);
	insert_edge(g, 7, 10);
	insert_edge(g, 8, 9);
	insert_edge(g, 8, 10);
	
	int menu = 0;
	printf("1:  깊이 우선 탐색\n");
	printf("2:  너비 우선 탐색\n");
	printf("3:  종료\n");
	while (menu != 3) {
		printf("\n");
		printf("\n");
		printf("메뉴 입력: ");
		scanf_s(" %d", &menu);

		switch (menu) {
		case 1:
			int start;
			int value;

			printf("시작 번호와 탐색할 값 입력:");
			scanf_s("%d %d", &start, &value);
			printf("깊이 우선 탐색 결과:\n");
			for (int i = 0; i < g->n; i++) {
				visited[i] = 0; // 방문 기록 초기화
			}
			dfs_mat(g, start);
			printf("\n");
			if (visited[value] == true) {
				printf("탐색 성공!\n");
				break;
		case 2:
			printf("시작 번호와 탐색할 값 입력:");

			break;
		case 3:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
			}
		}
		printf("\n");
		free(g);
		return 0;
	}
}