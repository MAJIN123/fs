#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char word[15];
    struct node *next;
}Node;

int Is_THE(char word[]){
    if(strcmp(word,"THE")&&strcmp(word,"The")&&strcmp(word,"the")){
        return 0;
    }
    return 1;
}
int Is_NewWord(Node *head,char word[]){
    Node *p=head;
    while(p->next){
        if(strcmp(word,p->next->word)==0){
            return 0;
        }
        p=p->next;
    }
    return 1;
}
void Insert(Node *head,Node *p){
    Node *q=head;
    while(q->next){
        q=q->next;
    }
    q->next=p;
}
void  ReadDate(char *filename,Node *head){
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    char temp[15];
    while(fscanf(fp,"%s",temp)!=EOF){
        //printf("%s\n",temp);
        //Is_THE过滤掉the  Is_NewWord查看是否有重复
        if(!Is_THE(temp)&&Is_NewWord(head,temp)) {

            Node *p = (Node *) malloc(sizeof(Node));
            if (p) {
                strcpy(p->word, temp);
                p->next = NULL;
            }
            Insert(head,p);
        }

    }//end for while

    fclose(fp);
}
void WriteDate(char *filename,Node *head){
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    Node *p=head;
    while(p->next){
        if(p->next->word[0]>='a'&&p->next->word[0]<='z'){
            p->next->word[0]-=32;
        }
        fprintf(fp,"%s\n",p->next->word);
        p=p->next;
    }


    fclose(fp);
}
void Display(Node *head){
    Node *p=head;
    while(p->next){
        printf("%s\n",p->next->word);
        p=p->next;
    }
}
int main() {
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    ReadDate("/home/jinm32/by/2008_new/org.data",head);
    WriteDate("/home/jinm32/by/2008_new/output.data",head);
    //Display(head);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}