#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node));		// 더미 노드 추가
	tail = head;

	// 데이터 입력 //
	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//노드 추가
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	// 데이터 출력 //
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == tail)
		printf("저장된 자연수가 존재하지 않습니다.\n");
	else {
		cur = head;

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리 해제 //
	if (head == NULL)
		return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		while (delNextNode != NULL) {	// dummy 노드 빼고 삭제
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}