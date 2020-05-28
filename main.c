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
		printf("\n1.�������� �� ��� ����� �� ��� �������");
		printf("\n2.�������� �� ��� ����� �� ��� ��������");
		printf("\n3.�������� �� ��� ����� ����� ������ ����� �� ���");
		printf("\n4.�������� �� ��� ����� ���� ������ ����� �� ���");
		printf("\n5.��������� ������������ �� �������");
		printf("\n6.�������� ���� �� �������");
		printf("\n7.��������� �� �������");
		printf("\n8.��������� �� �������");
		printf("\n9.��������� �� ��������");
		printf("\n10.��������� �� ������ ����� �� ���");
		printf("\n11.������ �� �������");
		printf("\n12.������ �� ��������");
		printf("\n13.������ �� ������ ����� �� ���");
		printf("\n14.����� �� ������� � ������� ����");
		printf("\n15.���������  �� ������ �� ������� ����");
		printf("\n16.�����\n");
		do
		{
			printf("��������:");
			count = scanf("%d", &k);
			while (getchar() != '\n');
		} while (count != 1);

		switch (k)
		{
		/*case 1:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\n������ ��� �������� �� ����� �� ��� �����.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\n������ ��� ��������� �� ����� �� ��� �����.");
					break;
				}
			head = addToHead(head, newE);
			break;*/
		case 1:
			errCode = 0;
			newE = newNode(&errCode);
			int shouldBreak = 0;
			/*�������� �� ������*/
			switch (errCode)
			{
				case 1:
					printf("\n ������ ��� �������� �� ����� �� ��� �����. ");
					shouldBreak = 1;
					break;
				
				case 2:
					printf("\n ������ ��� ��������� �� ������������� ����� �� �������.");
					shouldBreak = 1;
					break;

				case 3:
					printf("\n ������ ��� ��������� �� ����� �� �������.");
					shouldBreak = 1;
					break;

				case 4: 
					printf("\n ������ ��� ��������� �� ���� �� ������������.");
					shouldBreak = 1;
					break;

				case 5:
					printf("\n ������ ��� ��������� �� ����������.");
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
				printf("\n������ ��� �������� �� ����� �� ��� �����.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\n������ ��� ��������� �� ����� �� ��� �����.");
					break;
				}
			head = addToTail(head, newE);
			break;
		case 3:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\n������ ��� �������� �� ����� �� ��� �����.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\n������ ��� ��������� �� ����� �� ��� �����.");
					break;
				}
			head = addBeforeSearchNodeByID(head, newE, &errCode);
			if (errCode == 1)
				printf("������ ��� ��������� ����� �� ������ �������");
			break;
		case 4:errCode = 0;
			newE = newNode(&errCode);
			if (errCode == 1)
			{
				printf("\n������ ��� �������� �� ����� �� ��� �����.");
				break;
			}
			else
				if (errCode == 2)
				{
					printf("\n������ ��� ��������� �� ����� �� ��� �����.");
					break;
				}
			head = addAfterSearchNodeByID(head, newE, &errCode);
			if (errCode == 1)
				printf("������ ��� ��������� ����� �� ������ �������");
			break;
		case 5:
			if (head == NULL)
			{
				printf("������ ������");
				break;
			}
			printList(head);
			break;
		case 6:
			if (head == NULL)
			{
				printf("������ ������");
				break;
			}
			count = countNodes(head);
			printf("\n���� �� �������=%d", count);
			break;
		case 7:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			  head = deleteList(head);
			  break;
		case 8:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			  head = deleteHead(head);
			  break;
		case 9:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			  head = deleteTail(head);
			  break;
		case 10:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			   errCode = 0;
			   head = deleteSearchNodeByID(head, &errCode);
			   if (errCode == 1)
				   printf("������ ��� ��������� ����� �� ������ �������");
			   break;
		case 11:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			   head = readNodeFromHead(head, &d);
			   printf("�������� �����:");
			  // printf("\n���-%s\t\t������-%.2f", d.name, d.mark);
			   break;
		case 12:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			   head = readNodeFromTail(head, &d);
			   printf("�������� �����:");
			   //printf("\n���-%s\t\t������-%.2f", d.name, d.mark);
			   break;
		case 13:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			   errCode = 0;
			   head = readSearchNodeByID(head, &d, &errCode);
			   if (errCode == 1)
			   {
				   printf("������ ��� ��������� ����� �� ������ �������");
				   break;
			   }
			   printf("�������� �����:");
			   //printf("\n���-%s\t\t������-%.2f", d.name, d.mark);
			   break;
		case 14:if (head == NULL)
		{
			printf("������ ������");
			break;
		}
			   do
			   {
				   printf("�������� ��� �� ������� ���� �� �����:");
				   count = scanf("%s", fname);
				   while (getchar() != '\n');
			   } while (count != 1);
			   if ((fout = fopen(fname, "wb")) == NULL)
			   {
				   printf("�� �� ������ ������� ���� �� �����!");
				   break;
			   }
			   count = writeListInBinaryFile(head, fout);
			   if (count != 0)
				   printf("������ ��� ����� � ������� ����!");
			   break;
		case 15:errCode = 0;
			do
			{
				printf("�������� ��� �� ������� ���� �� ������:");
				count = scanf("%s", fname);
				while (getchar() != '\n');
			} while (count != 1);
			if ((fin = fopen(fname, "rb")) == NULL)
			{
				printf("�� �� ������ ������� ���� �� ������!");
				break;
			}
			head = createListFromBinaryFile(head, fin, &errCode);
			if (errCode == 1)
				printf("������ ��� �������� �� �����!");
			else
				if (errCode == 2)
					printf("������ ��� ������ �� ������� ����!");
			break;
		}
	} while (k != 16);
	_fcloseall();
	return 0;
}