#include "phone.h"

typedef struct item
{
	Phone phone;
	struct item* next;
}Node;

Node* newNode(int* errCode);
Node* addToHead(Node* head, Node* newE);
Node* addToTail(Node* head, Node* newE);
Node* addBeforeSearchNodeByID(Node* head, Node* newE, int* errCode);
Node* addAfterSearchNodeByID(Node* head, Node* newE, int* errCode);

void printList(Node* head);
int countNodes(Node* head);

Node* deleteList(Node* head);
Node* deleteHead(Node* head);
Node* deleteTail(Node* head);
Node* deleteSearchNodeByID(Node* head, int* errCode);


Node* readNodeFromHead(Node* head, Phone* copyphone);
Node* readNodeFromTail(Node* head, Phone* copyphone);
Node* readSearchNodeByID(Node* head, Phone* copyphone, int* errCode);


short writeListInBinaryFile(Node* head, FILE* fout);
Node* createListFromBinaryFile(Node* head, FILE* fin, int* errCode);

