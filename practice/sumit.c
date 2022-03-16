#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct data *next;
};
typedef struct node* NODE;
NODE ins_beg(NODE);
/*NODE *ins_end(NODE *);
NODE *ins_aft(NODE *);
NODE *ins_bef(NODE *);
NODE *ins_spec(NODE *);
NODE *del_beg(NODE *);
NODE *del_end(NODE *);
NODE *del_spec(NODE *);
NODE *del_aft(NODE *);
NODE *del_bef(NODE *);
NODE *sort(NODE *);
NODE *reverse(NODE *);*/
NODE display(NODE);

int main()
{
    NODE  head;
    int ch,ch1,ch2;
    head=(NODE*)malloc(sizeof(NODE));
    while(1)
    {
        printf("\n**********MENU*********\n");
        printf("1.INSERT AT BEGINNING\n");
        printf("2.INSERT AT END \n");      
        printf("3.INSERT ANY POSITION\n");
        printf("4.DELETE AT BEGINNING\n");
        printf("5.DELETE AT END\n");
        printf("6.DELETED ANY POSITION\n");
        printf("7.SORT LIST\n");
        printf("8.REVERSE LIST\n");
        printf("9.DISPLAY\n");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=ins_beg(head);
                break;
            /*case 2:
                head=ins_end(head);
                break;
            case 3:
                printf("\n1.INSERT AFTER NODE\n2.INSERT BEFORE NODE\n3.INSERT AT A SPECIFIC POSITION\n");
                scanf("%d",ch1);
                switch(ch1)
                {
                    case 1:
                        head=ins_aft(head);
                        break;
                    case 2:
                        head=ins_bef(head);
                        break;
                    case 3:
                        head=ins_spec(head);
                        break;
                    default
                        printf("\nWrong input\n");
                        break;
                }
                break;
            case 4:
                head=del_beg(head);
                break;
            case 5:
                head=del_end(head);
                break;
            case 6:
                printf("\n1.DELETE AFTER NODE\n2.DELETE BEFORE NODE\n3.DELETE AT A SPECIFIC POSITION\n");
                printf("Enter your choice: ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                        head=del_aft(head);
                        break;
                    case 2:
                        head=del_bef(head);
                        break;
                    case 3:
                        head=del_spec(head);
                        break;
                    default
                        printf("\nWrong choice\n");
                        break;
                }
                break;l
            case 7:
                head=sort(head);
                break;
            case 8:
                head=reverse(head);
                break;*/
            case 2:
                head=display(head);
                break;
            default:
                printf("\nWrong choice\n");
                break;
        }
    }
}

NODE ins_beg(NODE head)
{
    NODE nw1;
    nw1=(NODE)malloc(sizeof(NODE));
    int i,data;
    printf("Enter the data: ");
    scanf("%d",&data);
    nw1->data=data;
    if(head==NULL)
    {
        nw1->next=NULL;
        nw1->prev=NULL;
        head=nw1;
    }
    else
    {
        nw1->next=head;
        nw1->prev=NULL;
        head->prev=nw1;
        head=nw1;
    }
    return head;

}

NODE *display(NODE *head)
{
    NODE *p=head;
    if(head==NULL)
        printf("Empty list\n");
    else
    {
        printf("NULL <=>");
        while(p!=NULL)
        {
            printf("|%d| <=>",p->data);
            p=p->next;
            
        }
        printf("NULL");

    }
    return head;
}


