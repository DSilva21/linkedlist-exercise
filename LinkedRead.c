#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
typedef struct _node
{
	int data;
	struct _node *next;
}Node;

int main(void)
{
	Node*head = NULL;
	Node*tail = NULL;
	Node*cur = NULL;

	Node*newNode = NULL;

	int readData;

	head = (Node*)malloc(sizeof(Node));
	tail = head;
	//데이터를 입력받는 과정/
	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;

	}
	printf("\n");

	//입력받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체 출력 ! \n");
	if (head == tail)
	{
		printf("저장된 자연수가 존재하지 않습니다.\n");
	}
	else
	{
		cur = head;
		

		while (cur->next != NULL) //두번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d", cur->data);
		}
	}
	printf("\n\n");

	//메모리의 해제과정
	if (head == tail)
	{
		return 0; //해제할 노드가 없다.
	}
	else
	{
		Node*delNode = head;
		Node*delNextNode = head->next;
		while (delNextNode != NULL) //두 번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("%d를 삭제 합니다.\n", delNode->data);
			free(delNode);
		}
	}

	getch();
	return 0;

}