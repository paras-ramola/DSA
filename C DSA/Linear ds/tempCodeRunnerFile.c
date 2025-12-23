
typedef struct node{
    int info;
    struct node *next;
}ll;

ll *createNode(int info){
ll *newNode=(ll *)malloc(sizeof(ll));
if(newNode==NULL){
    printf("Menory not Available!!\n");
}
else{
newNode->info=info;
newNode->next=NULL;
}
return newNode;
};
void display(ll *ptr){
while(ptr!=NULL){
    printf("Element:%d\n",ptr->info);
    ptr=ptr->next;
}
}
 ll *insertNode(ll *head,int info){
    ll *newNode=createNode(info);
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        newNode->info=info;
        return head;
    }
    else{
        ll *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;
        newNode->info=info;
    }
    return head;
 };
 void reverse(ll *head){
  ll *prevNode,*currNode,*nextNode;
  prevNode=NULL;
  currNode=nextNode=head;
    while(nextNode!=NULL){
        nextNode=nextNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }
    head=prevNode;//bcz nextNode=0,and currNode=nextNode
display(head);
 }
ll * reverseK(ll *head,int k){
    ll *prevNode=NULL;
    ll *currNode=head;
    ll *nextNode;
    int count=0;
    while(currNode!=NULL&&count<k){
    
           nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
        count++;
     }
    if(nextNode!=NULL){
    head->next=reverseK(nextNode,k);//head reverse ho jayega to vo last ho jayega  aur isilye head->next(i.e last wli node) se next k node link ho jayegi
    }
return prevNode;
}

int main(){
    ll *head=NULL;
    int choice,value,k;
    do{
        printf("Enter:1-insertion,2-Reverse,3-Reverse by K order,3-Display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value to insert:");
            scanf("%d",&value);
            head=insertNode(head,value);
            break;
            case 2:reverse(head);
            break;
            case 3:printf("Enter the order:");
            scanf("%d\n",&k);
            head=reverseK(head,k);
            break;
            case 4:display(head);
            break;
            default:printf("Invalid Choice");
            exit(0);
        }
    }while(1);
    return 0;
}