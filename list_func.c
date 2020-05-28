#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <string.h>
#include "list.h"

Node* newNode(int* errCode)
{
	/*Node* newE = NULL;
	int k = 0;
	*errCode = 0;
	newE = (Node*)malloc(sizeof(Node));
	if (newE == NULL)
	{
		*errCode = 1;
		return NULL;
	}
	printf("Въведете име на студент:");
	if (fgets(newE->a.name, sizeof(newE->a.name) - 2, stdin) == NULL)
	{
		*errCode = 2;
		return NULL;
	}
	newE->a.name[strlen(newE->a.name) - 1] = '\0';
	do
	{
		printf("Въведете оценка на студент: ");
		k = scanf("%f", &newE->a.mark);
		while (getchar() != '\n');
		if (k == EOF)
		{
			*errCode = 2;
			return NULL;
		}
	} while (newE->a.mark < 2 || newE->a.mark>6);

	return newE;*/
	Node* newNode = NULL;
	
	*errCode = 0;
	
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		*errCode = 1;
		return NULL;
	}

	const long long int range = 100000000000;
	int err;

	do
	{
		printf("Въведете номенклатурен номер на телефон(12 цифрен код): ");
		err = scanf("%lli", &newNode->phone.ID);
		while (getchar() != '\n');
		if (err == EOF)
		{
			*errCode = 2;
			return NULL;
		}
	} while (newNode->phone.ID < range || newNode->phone.ID >= range * 10);

	printf("Въведете модел на телефон:");
	if (fgets(newNode->phone.model, sizeof(newNode->phone.model) - 2, stdin) == NULL)
	{
		*errCode = 3;
		return NULL;
	}
	newNode->phone.model[strlen(newNode->phone.model) - 1] = '\0';

	printf("Въведете цена на устройството: ");
	err = scanf("%f", &newNode->phone.price);
	while (getchar() != '\n');
	if(err == EOF)
	{
		*errCode = 4;
		return NULL;
	}
	
	printf("Въведете количество:");
	err = scanf("%d", &newNode->phone.amount);
	while (getchar() != '\n');
	if (err == EOF)
	{
		*errCode = 5;
		return NULL;
	}
	return newNode;
}
//*********************************
Node* addToHead(Node* head, Node* newE)
{
	if (head == NULL)
	{
		newE->next = NULL;
		head = newE;
	}
	else
	{
		newE->next = head;
		head = newE;
	}

	return head;
}
//****************************************************
Node* addToTail(Node* head, Node* newE)
{
	if (head == NULL)
	{
		newE->next = NULL;
		head = newE;
	}
	else
	{
		Node* crnt = head;
		while (crnt->next != NULL)
			crnt = crnt->next;

		newE->next = crnt->next;
		crnt->next = newE;
	}
	return head;
}
//******************************************************************
Node* addBeforeSearchNodeByID(Node* head, Node* newE, int* errCode)
{
	/*char buf[30];
	Node* crnt = head, * prev = NULL;
	*errCode = 0;
	printf("Въведете име на търсен студент:");
	if (fgets(buf, sizeof(buf) - 2, stdin) == NULL)
	{
		*errCode = 1;
		return head;
	}
	buf[strlen(buf) - 1] = '\0';
	while (crnt != NULL)
	{
		if (strcmp(crnt->a.name, buf) == 0)
		{
			if (crnt == head)
			{
				newE->next = head;
				head = newE;
				break;
			}
			else
			{
				newE->next = crnt;
				prev->next = newE;
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;*/
	Node* crnt = head;
	Node* prev = NULL;
	*errCode = 0;
	const long long int range = 100000000000;
	long long int tempID;
	int err;
	do
	{
		printf("Въведете номенклатурен номер на телефон от листа: ");
		err = scanf("%lli", &tempID);
		while (getchar() != '\n');
		if (err == EOF)
		{
			*errCode = 2;
			return NULL;
		}
	} while (tempID < range || tempID >= range * 10);
	
	while (crnt != NULL)
	{
		if (crnt->phone.ID == tempID)
		{
			if (crnt == head)
			{
				newE->next = head;
				head = newE;
				break;
			}
			else
			{
				newE->next = crnt;
				prev->next = newE;
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;
}
//*********************************************************
Node* addAfterSearchNodeByID(Node* head, Node* newE, int* errCode)
{
	/*char buf[30];
	Node* crnt = head;
	*errCode = 0;
	printf("Въведете име на търсен студент:");
	if (fgets(buf, sizeof(buf) - 2, stdin) == NULL)
	{
		*errCode = 1;
		return head;
	}
	buf[strlen(buf) - 1] = '\0';
	while (crnt != NULL)
	{
		if (strcmp(crnt->a.name, buf) == 0)
		{
			newE->next = crnt->next;
			crnt->next = newE;
			break;
		}
		crnt = crnt->next;
	}
	return head;*/
	Node* crnt = head;
	*errCode = 0;
	const long long int range = 100000000000;
	int err;
	long long int tempID;
	do
	{
		printf("Въведете номенклатурен номер на телефон: ");
		err = scanf("%lli", &tempID);
		while (getchar() != '\n');
		if (err == EOF)
		{
			*errCode = 3;
			return NULL;
		}
	} while (tempID < range || tempID >= range * 10);

	
	while (crnt != NULL)
	{
		if (crnt->phone.ID == tempID)
		{
			newE->next = crnt->next;
			crnt->next = newE;
			break;
		}
		crnt = crnt->next;
	}
	return head;
}
//***************************************************
void printList(Node* head)
{
	while (head)
	{
		printf("Номенклатурен номер:%lli\nМодел:%s\nЦена: %.2f\nКоличество: %d\n", head->phone.ID, head->phone.model, head->phone.price, head->phone.amount);
		head = head->next;
	}
}
//****************************************
int countNodes(Node* head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}
//****************************************
Node* deleteList(Node* head)
{
	Node* crnt = NULL;
	while (head != NULL)
	{
		crnt = head;
		head = head->next;
		free(crnt);
	}
	return head;
}
//***********************************
Node* deleteHead(Node* head)
{
	Node* crnt = head;
	head = head->next;
	free(crnt);
	return head;
}
//*********************************
Node* deleteTail(Node* head)
{
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node* crnt = head;
		Node* prev = NULL;
		while (crnt->next != NULL)
		{
			prev = crnt;
			crnt = crnt->next;
		}
		prev->next = crnt->next;
		free(crnt);
	}
	return head;
}
//*********************************************************
Node* deleteSearchNodeByID(Node* head, int* errCode)
{
	/*char buf[30];
	Node* crnt = head, * prev = NULL;
	*errCode = 0;
	printf("Въведете име на търсен студент:");
	if (fgets(buf, sizeof(buf) - 2, stdin) == NULL)
	{
		*errCode = 1;
		return head;
	}
	buf[strlen(buf) - 1] = '\0';
	while (crnt)
	{
		if (strcmp(crnt->a.name, buf) == 0)
		{
			if (crnt == head)
			{
				head = head->next;
				free(crnt);
				break;
			}
			else
			{
				prev->next = crnt->next;
				free(crnt);
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;*/
	Node* crnt = head;
	Node* prev = NULL;
	*errCode = 0;
	const long long int range = 100000000000;
	long long int tempID;
	int err;
	do
	{
		printf("Въведете номенклатурен номер на телефон от листа: ");
		err = scanf("%lli", &tempID);
		while (getchar() != '\n');
		if (err == EOF)
		{
			*errCode = 2;
			return NULL;
		}
	} while (tempID < range || tempID >= range * 10);

	while (crnt)
	{
		if (tempID == crnt->phone.ID)
		{
			if (crnt == head)
			{
				head = head->next;
				free(crnt);
				break;
			}
			else
			{
				prev->next = crnt->next;
				free(crnt);
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;
}
//***************************************************
Node* readNodeFromHead(Node* head, Phone* copyphone)
{
	Node* crnt = head;
	head = head->next;
	*copyphone = crnt->phone;
	free(crnt);
	return head;
}
//************************************************
Node* readNodeFromTail(Node* head, Phone* copyphone)
{
	if (head->next == NULL)
	{
		*copyphone = head->phone;
		free(head);
		return NULL;
	}
	else
	{
		Node* crnt = head;
		Node* prev = NULL;
		while (crnt->next != NULL)
		{
			prev = crnt;
			crnt = crnt->next;
		}
		prev->next = crnt->next;
		*copyphone = crnt->phone;
		free(crnt);
	}
	return head;
}
//***************************************************************
Node* readSearchNodeByID(Node* head, Phone* copyphone, int* errCode)
{
	/*char buf[30];
	Node* crnt = head, * prev = NULL;
	*errCode = 0;
	printf("Въведете име на търсен студент:");
	if (fgets(buf, sizeof(buf) - 2, stdin) == NULL)
	{
		*errCode = 1;
		return head;
	}
	buf[strlen(buf) - 1] = '\0';
	while (crnt)
	{
		if (strcmp(crnt->a.name, buf) == 0)
		{
			if (crnt == head)
			{
				head = head->next;
				*d = crnt->a;
				free(crnt);
				break;
			}
			else
			{
				prev->next = crnt->next;
				*d = crnt->a;
				free(crnt);
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;*/
	Node* crnt = head;
	Node* prev = NULL;
	*errCode = 0;
	const long long int range = 100000000000;
	long long int tempID;
	int err;
	do
	{
		printf("Въведете номенклатурен номер на телефон от листа: ");
		err = scanf("%lli", &tempID);
		while (getchar() != '\n');
		if (err == EOF)
		{
			*errCode = 2;
			return NULL;
		}
	} while (tempID < range || tempID >= range * 10);
	while (crnt)
	{
		if (crnt->phone.ID == tempID)
		{
			if (crnt == head)
			{
				head = head->next;
				*copyphone = crnt->phone;
				free(crnt);
				break;
			}
			else
			{
				prev->next = crnt -> next;
				*copyphone = crnt->phone;
				free(crnt);
				break;
			}
		}
		prev = crnt;
		crnt = crnt->next;
	}
	return head;
}

//********************************************************************
short writeListInBinaryFile(Node* head, FILE* fout)
{
	while (head != NULL)
	{
		if (fwrite(&head->phone, sizeof(Phone), 1, fout) != 1)
			break;
		head = head->next;
	}
	if (ferror(fout))
		return 1;
	fclose(fout);
	return 0;

}
//*******************************************************************
Node* createListFromBinaryFile(Node* head, FILE* fin, int* errCode)
{
	Node* newE = NULL;
	while (1)
	{
		if ((newE = (Node*)malloc(sizeof(Node))) == NULL)
		{
			*errCode = 1;
			return NULL;
		}
		if (fread(&newE->phone, sizeof(Phone), 1, fin) != 1)
			break;
		head = addToHead(head, newE);
	}
	if (ferror(fin))
	{
		*errCode = 2;
		return NULL;
	}
	return head;
	}