#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
   element data;
   struct ListNode *link;
}ListNode;

void insert_node(ListNode **phead, ListNode **p, ListNode *new_node) {
   ListNode *q;
   q = *p;

   if (*phead == NULL) {
      new_node->link = NULL;
      *phead = new_node;
      *p = new_node;
   }
   else {
      new_node->link = q->link;
      q->link = new_node;
      *p = new_node;
   }
}

void display(ListNode *head) {
   ListNode *p = head;
   printf("head ->");
   while (p != NULL) {
      printf("%d->", p->data);
      p = p->link;
   }
   printf("  NULL");
   printf("\n");
}

ListNode *create_node(element data, ListNode *link) {
   ListNode *new_node;
   new_node = (ListNode*)malloc(sizeof(ListNode));
   if (new_node == NULL) printf("메모리 할당 에러");
   new_node->data = data;
   new_node->link = link;
   return(new_node);

}
void merge(ListNode **list3, ListNode *list1, ListNode *list2) {
   ListNode *p1 = list1;
   ListNode *p2 = list2;
   ListNode *p3 = NULL;
   if (p1->data > p2->data) {

      *list3 = list2;
      p2 = p2->link;
   }
   else if (p1->data < p2->data) {
      *list3 = list1;
      p1 = p1->link;
   }
   p3 = *list3;
      while (p2 != NULL && p1 != NULL) {
         if (p1->data > p2->data) {
            p3->link = p2;
            p3 = p3->link;
            p2 = p2->link;

         }
         else if (p1->data < p2->data) {
            p3->link = p1;
            p3 = p3->link;
            p1 = p1->link;
         }
      }
      if (p1 == NULL) {
         p3->link = p2;
         
      }else if(p2 == NULL) {
         p3->link = p1;

      }
   }


int main(void)
{

   ListNode *list1 = NULL;
   ListNode *list2 = NULL;
   ListNode *list3 = NULL;
   ListNode *p = NULL;
   insert_node(&list1, &p, create_node(10, NULL));
   insert_node(&list1, &p, create_node(30, NULL));
   insert_node(&list1, &p, create_node(40, NULL));
   insert_node(&list1, &p, create_node(70, NULL));
   insert_node(&list2, &p, create_node(20, NULL));
   insert_node(&list2, &p, create_node(50, NULL));
   insert_node(&list2, &p, create_node(60, NULL));
   insert_node(&list2, &p, create_node(80, NULL));
   
   printf("첫번째 오름차순으로 저장된 노드");
   display(list1);
   printf("두번째 오름차순으로 저장된 노드");
   display(list2);
   merge(&list3, list1, list2);
   printf("두 노드를 오름차순으로 저장한 노드");
   display(list3);
}