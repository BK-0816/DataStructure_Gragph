#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphType {
	int n;	// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
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
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


void dfs_mat(GraphType* g, int v)
{
	int w;
	visited[v] = true;		// ���� v�� �湮 ǥ�� 
	printf("%d ", v);		// �湮�� ���� ���
	for (w = 0; w < g->n; w++) 		// ���� ���� Ž��
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);	//���� w���� DFS ���� ����
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
	printf("1:  ���� �켱 Ž��\n");
	printf("2:  �ʺ� �켱 Ž��\n");
	printf("3:  ����\n");
	while (menu != 3) {
		printf("\n");
		printf("\n");
		printf("�޴� �Է�: ");
		scanf_s(" %d", &menu);

		switch (menu) {
		case 1:
			int start;
			int value;

			printf("���� ��ȣ�� Ž���� �� �Է�:");
			scanf_s("%d %d", &start, &value);
			printf("���� �켱 Ž�� ���:\n");
			for (int i = 0; i < g->n; i++) {
				visited[i] = 0; // �湮 ��� �ʱ�ȭ
			}
			dfs_mat(g, start);
			printf("\n");
			if (visited[value] == true) {
				printf("Ž�� ����!\n");
				break;
		case 2:
			printf("���� ��ȣ�� Ž���� �� �Է�:");

			break;
		case 3:
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �޴� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
			}
		}
		printf("\n");
		free(g);
		return 0;
	}
}