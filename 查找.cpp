#include<stdio.h>
#include<stdlib.h>

typedef int Status;
typedef int KeyType;
typedef struct{
    KeyType key;
}ElemType;

typedef struct{
    ElemType *elem;
    int length;
}SSTable;

Status InitSSTable_Seq(SSTable &t){
    t.elem=(ElemType*)malloc(100*sizeof(ElemType));
    if(!t.elem){
        printf("Failed.\n");
        exit(-2);
    }
    t.length=0;
    return 1;
}

Status SSTableInput_Seq(SSTable &t){
    int n;
    printf("Please input the number of the table: ");
    scanf("%d",&n);
    printf("Please input the Seq_Table: ");
    for(int i=1;i<=n;i++){
        scanf("%d",&t.elem[i].key);
    }
    t.length=n;
    return 1;
}

Status SSTableEmpty_Seq(SSTable t){
    if(t.length==0) return 1;
    else return 0;
}

int Search_Seq(SSTable t,KeyType key){
    t.elem[0].key=key;
    for(int i=t.length;i>=0;--i){
        if(t.elem[i].key==key) return i;
    }
    return 0;
}

Status SortSSTable_Seq(SSTable &t){
    if(SSTableEmpty_Seq(t)) return 0;
    int low=1,high=t.length,tmp,j;
    while(low<high){
        for(j=low;j<high;++j){
            if(t.elem[j].key>t.elem[j+1].key){
                tmp=t.elem[j].key;
                t.elem[j].key=t.elem[j+1].key;
                t.elem[j+1].key=tmp;
            }
        }
        --high;
        for(j=high;j>low;--j){
            if(t.elem[j].key<t.elem[j-1].key){
                tmp=t.elem[j].key;
                t.elem[j].key=t.elem[j-1].key;
                t.elem[j-1].key=tmp;
            }
        }
        ++low;
    }
}

int Search_Bin(SSTable t,KeyType key,int &visit){
    int low=1,high=t.length,mid;
    while(low<=high){
        visit++;
        mid=(low+high)/2;
        if(t.elem[mid].key==key) return mid;
        else if(t.elem[mid].key>key) high=mid-1;
        else low=mid+1;
    }
    return 0;
}

void DestroySSTable_Seq(SSTable &t){
    free(t.elem);
    t.elem=NULL;
}

int main(){
    SSTable t;
    KeyType k;
    Status flag;
    int visit=0;
    InitSSTable_Seq(t);
    SSTableInput_Seq(t);
    printf("Please input the target number: ");
    scanf("%d",&k);
    flag=Search_Seq(t,k);
    if(!flag) printf("Search_Seq failed.\n");
    else{ 
        printf("Search_Seq success, the number is ");
        printf("%d\n",flag);
    }
    SortSSTable_Seq(t);
    flag=Search_Bin(t,k,visit);
    if(!flag) printf("Search_Bin failed.\n");
    else{
        printf("Search_Bin success, the number is ");
        printf("%d\n",flag);
        printf("In Search_Bin, the number of visiting is ");
        printf("%d\n",visit);
    }

    DestroySSTable_Seq(t);
    return 0;
}