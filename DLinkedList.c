#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));	// 더미 노드 생성
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}
void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)		// 정렬기준이 마련되지 않았다면,
		FInsert(plist, data);		// 머리에 노드 추가
	else							// 정렬기준이 마련되었다면,
		SInsert(plist, data);		// 정렬기준에 근거하여 노드를 추가
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