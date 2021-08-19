#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));	// ���� ��� ����
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}
void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		// ���ı����� ���õ��� �ʾҴٸ�,
		FInsert(plist, data);		// �Ӹ��� ��� �߰�
	else							// ���ı����� ���õǾ��ٸ�,
		SInsert(plist, data);		// ���ı��ؿ� �ٰ��Ͽ� ��带 �߰�
}
void FInsert(List* plist, LData data) {
	Node * new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = plist->head->next;
	plist->head->next = new;
	(plist->numOfData)++;
}
void SInsert(List* plist, LData data) {

}
int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {

}
int LCount(List* plist) {

}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {

}