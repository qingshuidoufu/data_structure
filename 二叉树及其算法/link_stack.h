#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct my_stack {
	void* x;
	struct my_stack* next;
}my_stack;

my_stack* init() {
	my_stack* head;
	head = (my_stack*)malloc(sizeof(my_stack));
	head->next = NULL;
	return head;
}
void stack_print(my_stack* head) {
	my_stack* tem;
	tem = head->next;
	while (tem != NULL)
	{
		printf("%c ", tem->x);
		tem = tem->next;
	}
}
void push(my_stack* head, void* x) {
	my_stack* s = (my_stack*)malloc(sizeof(my_stack));
	s->x = x;
	s->next = NULL;
	s->next = head->next;
	head->next = s;
}
void pop(my_stack* head) {
	my_stack* tem;
	if (!is_empty(head)) {
		tem = head->next;
		head->next = tem->next;
		free(tem);
	}
}
int is_empty(my_stack* head) {
	if (head->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void* get_top_(my_stack* head) {
	return head->next->x;
}
