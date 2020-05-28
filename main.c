#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <Windows.h>
#include "list.h"

void printNode(Node* node)
{
	printf("%lli\n", node->phone.ID);
	printf("%s\n", node->phone.model);
	printf("%f\n", node->phone.price);
	printf("%d\n", node->phone.amount);
}

int main()
{
	Node* head = NULL, * newE = NULL;
	int k = 0, errCode = 0, count = 0;
	Phone d;
	char fname[40];
	FILE* fin = NULL, * fout = NULL;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	do
	{
		printf("\n1.Добавяне на нов възел от към главата");
		printf("\n2.Добавяне на нов възел от към опашката");
		printf("\n3.Добавяне на нов възел преди търсен възел по име");
		printf("\n4.Добавяне на нов възел след търсен възел по име");
		printf("\n5.Показване съдържанието на списъка");
		printf("\n6.Намиране броя на възлите");
		printf("\n7.Изтриване на списъка");
		printf("\n8.Изтриване на главата");
		printf("\n9.Изтриване на опашката");
		printf("\n10.Изтриване на търсен възел по име");
		printf("\n11.Четене на главата");
		printf("\n12.Четене на опашката");
		printf("\n13.Четене на търсен възел по име");
		printf("\n14.Запис на списъка в двоичен файл");
		printf("\n15.Създаване  на списък от двоичен файл");
		printf("\n16.Изход\n");
		do
		{
			printf("Изберете:");
			count = scanf("%d", &k);
			while (getchar() != '\n');
		} while (count != 1);

		switch (k)
		{
		/*case 1:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\nГрешка при заделяне на памет за нов възел.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\nГрешка при въвеждане на данни за нов възел.");
					break;
				}
			head = addToHead(head, newE);
			break;*/
		case 1:
			errCode = 0;
			newE = newNode(&errCode);
			int shouldBreak = 0;
			/*Проверка за грешка*/
			switch (errCode)
			{
				case 1:
					printf("\n Грешка при заделяне на памет за нов възел. ");
					shouldBreak = 1;
					break;
				
				case 2:
					printf("\n Грешка при въвеждане на номенклатурен номер на телефон.");
					shouldBreak = 1;
					break;

				case 3:
					printf("\n Грешка при въвеждане на модел на телефон.");
					shouldBreak = 1;
					break;

				case 4: 
					printf("\n Грешка при въвеждане на цена на устройството.");
					shouldBreak = 1;
					break;

				case 5:
					printf("\n Грешка при въвеждане на количество.");
					shouldBreak = 1;
					break;

			}
			if (shouldBreak == 1)
			{
				break;
			}
			head = addToHead(head, newE);
			printNode(newE);
			break;
		case 2:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\nГрешка при заделяне на памет за нов възел.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\nГрешка при въвеждане на данни за нов възел.");
					break;
				}
			head = addToTail(head, newE);
			break;
		case 3:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\nГрешка при заделяне на памет за нов възел.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\nГрешка при въвеждане на данни за нов възел.");
					break;
				}
			head = addBeforeSearchNodeByID(head, newE, &errCode);
			if (errCode == 1)
				printf("Грешка при въвеждане името на търсен студент");
			break;
		case 4:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\nГрешка при заделяне на памет за нов възел.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\nГрешка при въвеждане на данни за нов възел.");
					break;
				}
			head = addAfterSearchNodeByID(head, newE, &errCode);
			if (errCode == 1)
				printf("Грешка при въвеждане името на търсен студент");
			break;
		case 5:
			if (head == NULL)
			{
				printf("Празен списък");
				break;
			}
			printList(head);
			break;
		case 6:
			if (head == NULL)
			{
				printf("Празен списък");
				break;
			}
			count = countNodes(head);
			printf("\nБрой на възлите=%d", count);
			break;
		case 7:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			  head = deleteList(head);
			  break;
		case 8:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			  head = deleteHead(head);
			  break;
		case 9:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			  head = deleteTail(head);
			  break;
		case 10:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			   errCode = 0;
			   head = deleteSearchNodeByID(head, &errCode);
			   if (errCode == 1)
				   printf("Грешка при въвеждане името на търсен студент");
			   break;
		case 11:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			   head = readNodeFromHead(head, &d);
			   printf("Прочетен възел:");
			  // printf("\nИме-%s\t\tОценка-%.2f", d.name, d.mark);
			   break;
		case 12:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			   head = readNodeFromTail(head, &d);
			   printf("Прочетен възел:");
			   //printf("\nИме-%s\t\tОценка-%.2f", d.name, d.mark);
			   break;
		case 13:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			   errCode = 0;
			   head = readSearchNodeByID(head, &d, &errCode);
			   if (errCode == 1)
			   {
				   printf("Грешка при въвеждане името на търсен студент");
				   break;
			   }
			   printf("Прочетен възел:");
			   //printf("\nИме-%s\t\tОценка-%.2f", d.name, d.mark);
			   break;
		case 14:if (head == NULL)
		{
			printf("Празен списък");
			break;
		}
			   do
			   {
				   printf("Въведете име на двоичен файл за запис:");
				   count = scanf("%s", fname);
				   while (getchar() != '\n');
			   } while (count != 1);
			   if ((fout = fopen(fname, "wb")) == NULL)
			   {
				   printf("Не се отваря двоичен файл за запис!");
				   break;
			   }
			   count = writeListInBinaryFile(head, fout);
			   if (count != 0)
				   printf("Грешка при запис в двоичен файл!");
			   break;
		case 15:errCode = 0;
			do
			{
				printf("Въведете име на двоичен файл за четене:");
				count = scanf("%s", fname);
				while (getchar() != '\n');
			} while (count != 1);
			if ((fin = fopen(fname, "rb")) == NULL)
			{
				printf("Не се отваря двоичен файл за четене!");
				break;
			}
			head = createListFromBinaryFile(head, fin, &errCode);
			if (errCode == 1)
				printf("Грешка при заделяне на памет!");
			else
				if (errCode == 2)
					printf("Грешка при четене от двоичен файл!");
			break;
		}
	} while (k != 16);
	_fcloseall();
	return 0;
}