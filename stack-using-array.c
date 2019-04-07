#include<stdio.h>
#include<stdlib.h>


struct stack
{
    int index;
    char c[50];
};


void pop(int n){

}

void push(struct stack s[],int n,int *count){
    if(*count<n){
        s[*count].index=*count;
        printf("Enter Name: ");
        scanf("%s",&s[*count].c);
        ++*count;
    }else{
        printf("Stack is full");
    }
}

void show(struct stack *s, int n){
    int i=0;
    for(i;i<n;i++){
        printf("\tName:%s\n",s[i].c);
    }
}

void main(){
    struct stack *s;
    int n,*i,j,count=0;
    int choice;
    printf("Enter number of element: ");
    scanf("%d",&n);
    i=(int *) malloc (n*sizeof(int));
    s=(struct stack*) malloc (n*sizeof(struct stack));
    do{
            printf("1.push\n2.pop\n3.show\n4.exit\n");
            printf("Enter the Choice:\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    push(s,n,&count);
                    break;
                case 2:
                    pop(n);
                    break;
                case 3:
                    show(s,count);
                    break;
                case 4:
                    // choice=4;
                    break;
                default:
                    printf("Enter correct option\n");
                    break;
            }
    }while(choice!=4);    
}