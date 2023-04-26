//Linked List basic operations using C
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;

//Method declarations
node* create(int n);
void print(node* temp);
void count(node* temp);
void search(node* temp);
node* insert_At_Begin(node* head);
node* insert_At_Middle(node* head);
void insert_At_End(node* head);
node* delete_At_Begin(node* head);
node* delete_At_Middle(node* head);
node* delete_At_End(node* head);

//Calling methods
int main() {
    node* head = NULL;
    int ch,no;
    do {
        printf("\n\n********Queue Operations********");
        printf("\n1. Create node");
        printf("\n2. Print node");
        printf("\n3. Coutn node");
        printf("\n4. Search node");
        printf("\n5. Node insert at Begin");
        printf("\n6. Node insert at Middle");
        printf("\n7. Node insert at End");
        printf("\n8. Node delete from Begin");
        printf("\n9. Node delete from Middle");
        printf("\n10. Node delete from End");
        printf("\n11. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch) { 
            case 1:
                printf("\nHow much nodes do you wants to create : ");
                scanf("%d",&no);
                head = create(no);
                break;
            case 2:
                print(head);
                break;
            case 3:
                count(head);
                break;
            case 4:
                search(head);
                break;
            case 5:
                head = insert_At_Begin(head);
                break;
            case 6:
                head = insert_At_Middle(head);
                break;
            case 7:
                insert_At_End(head);
                break;
            case 8:
                head = delete_At_Begin(head);
                break;
            case 9:
                    head = delete_At_Middle(head);
                    break;
            case 10:
                head = delete_At_End(head);
                break;
            
            case 11:
                printf("\nThank you!!");
                break;
            default:
                printf("\nInvalid chice!!");
            break;
        }
    }while(ch != 11);
    return 0;
}

//Create method definations
node* create(int n) {
    node *newNode, *temp;
    int x,i;
    printf("\nEnter the data : ");
    scanf("%d",&x);
    newNode = (node*)malloc(sizeof(node));
    newNode -> data = x;
    newNode -> next = NULL;
    temp = newNode;
    for(i = 2; i <= n; i++) {
        printf("\nEnter the data : ");
        scanf("%d",&x);
        temp -> next = (node*)malloc(sizeof(node));
        temp = temp -> next;
        temp -> data = x;
        temp -> next = NULL;
    }
    return (newNode);
}

//Print method defination
void print(node* temp) {
    if(temp == NULL) {
        printf("\nList is empty, anable to print!!");
    }
    else {
        printf("\nLinked List Data : ");
        while(temp != NULL) {
            printf("%d -> ",temp -> data);
            temp = temp -> next;
        }
    }
}


//Count method defination
void count(node* temp) {
    int Count = 0;
    if(temp == NULL) {
        printf("\nList is empty, anable to count!!");
    }
    else {
        while(temp != NULL) {
            Count++;
            temp = temp -> next;
        }
        printf("\nTotal nodes present in the list : %d",Count);
    }
}

//Search method defination
void search(node* temp) {
    int key, flag = 0;
    printf("\nEnter the data do want to search in this list : ");
    scanf("%d",&key);
    while(temp != NULL ) {
        if(temp -> data == key) {
            flag = 1;
            break;
        }
        temp = temp -> next;
    }
    if(flag == 1) {
        printf("\nYou entered data is present in the list ");
    }
    else {
        printf("\nYou entered data is not present in the list ");
    }
}

//Node insert at begin method defination
node* insert_At_Begin(node* head) {
    node* newNode;
    int x;
    printf("\nEnter data for inserting at begin of list : ");
    scanf("%d",&x);
    newNode = (node*)malloc(sizeof(node));
    newNode -> data = x;
    newNode -> next = head;
    head = newNode;
    printf("Node inserted at beging of list!!");
    return (head);
}

//Node insert at middle method defination
node* insert_At_Middle(node* head) {
    node *justCreate, *newNode = head;
    int x,loc,i;
    printf("\nEnter location for inserting node at middle of list : ");
    scanf("%d",&loc);
    printf("\nEnter data for inserting at middle of list : ");
    scanf("%d",&x);
    for(i = 1; i < loc - 1; i++) {
        newNode = newNode -> next;
    }
    justCreate = (node*)malloc(sizeof(node));
    justCreate -> data = x;
    justCreate -> next = newNode -> next;
    newNode -> next = justCreate; 
    printf("Node inserted at middle!!");
    return (head);
}

//Node insert at end method defination
void insert_At_End(node* head) {
    node* justCreate;
    int x;
    printf("\nEnter data for inserting data at end of list : ");
    scanf("%d",&x);
    justCreate = (node*)malloc(sizeof(node));
    justCreate -> data = x;
    justCreate -> next = NULL;
    while(head -> next != NULL) {
        head = head -> next;
    }
    head -> next = justCreate;
    printf("Node inserted at end of list!!");
}

//Node delete from begin method definattion
node* delete_At_Begin(node* temp) {
    node* newNode;
    if(temp == NULL) {
        printf("\nList is empty, anable to delete from begin!!");
    }
    else {
        newNode = temp;
        newNode = newNode -> next;
        free(temp);
    }
    printf("\nNode deleted from begin!!");
    return (newNode);
}

//Node delete from middle method definattion
node* delete_At_Middle(node* head) {
    node *newNode, *justCreate;
    int loc, i;
    if(head == NULL) {
        printf("\nList is empty, anable to delete from middle!!");
    }
    else {
        newNode = head;
        printf("\nEnter the location for node deletion : ");
        scanf("%d",&loc);
        for(i = 1; i < loc - 1; i++) {
            newNode = newNode -> next;
        }
        justCreate = newNode -> next;
        newNode -> next = justCreate -> next;
        free(justCreate);
    }
    printf("\nNode deleted from middle!!");
    return (head);
}

//Node delete from end method definattion
node* delete_At_End(node* head) {
    node *newNode, *justCreate;
    if(head == NULL) {
        printf("\nList is empty, anable to delete from end of list!!");
    }
    else {
        newNode = head;
        while(newNode -> next -> next != NULL){
            newNode = newNode -> next;
        }
        justCreate = newNode -> next;
        newNode -> next = NULL;
        free(justCreate);
    }
    printf("\nNode deleted from end!!");
    return (head);
}