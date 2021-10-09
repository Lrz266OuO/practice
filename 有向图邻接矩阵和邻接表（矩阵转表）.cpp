#include<stdio.h>
#include<malloc.h>
#define INF 10000
#define MAXV 100
typedef char InfoType;

typedef struct{
    int no;
    InfoType info;
}VertexType;
typedef struct{
    int edges[MAXV][MAXV];
    int n,e;
    VertexType vexs[MAXV];
}MatGragh;

typedef struct ANode{
    int adjvex;
    struct ANode *nextarc;
    int weight;
}ArcNode;
typedef struct Vnode{
    InfoType info;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode adjlist[MAXV];
    int n,e;
}AdjGragh;

void CreateMat(MatGragh &g,int A[MAXV][MAXV],int n,int e){
    g.n=n;
    g.e=e;
    for(int i=0;i<g.n;i++){
        for(int j=0;j<g.n;j++){
            g.edges[i][j]=A[i][j];
        }
    }
}
void DispMat(MatGragh g){
    for(int i=0;i<g.n;i++){
        for(int j=0;j<g.n;j++){
            if(i==j) printf("0 ");
            else if(g.edges[i][j]==0) printf("N ");
            else printf("%d ",g.edges[i][j]);
        }
        printf("\n");
    }
}

void CreateAdj(AdjGragh *&g,int A[MAXV][MAXV],int n,int e){
    int i,j;
    ArcNode *p;
    g=(AdjGragh*)malloc(sizeof(AdjGragh));
    for(i=0;i<n;i++){
        g->adjlist[i].firstarc=NULL;
    }
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--){
            if(A[i][j]!=0&&A[i][j]!=INF){
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=j;
                p->weight=A[i][j];
                p->nextarc=g->adjlist[i].firstarc;
                g->adjlist[i].firstarc=p;
            }
        }
    }
    g->n=n;
    g->e=e;
}
void DispAdj(AdjGragh *g){
    ArcNode *p;
    for(int i=0;i<g->n;i++){
        p=g->adjlist[i].firstarc;
        printf("%3d: ",i);
        while(p!=NULL){
            printf("%3d(%d)->",p->adjvex,p->weight);
            p=p->nextarc;
        }
        printf("^\n");
    }
}
void DestroyAdj(AdjGragh *&g){
    ArcNode *pre,*p;
    for(int i=0;i<g->n;i++){
        pre=g->adjlist[i].firstarc;
        if(pre!=NULL){
            p=pre->nextarc;
            while(p!=NULL){
                free(pre);
                pre=p;
                p=p->nextarc;
            }
            free(pre);
        }
    }
    free(g);
}

void MatToList(MatGragh g,AdjGragh *&G){
    ArcNode *p;
    G=(AdjGragh*)malloc(sizeof(AdjGragh));
    for(int i=0;i<g.n;i++){
        G->adjlist[i].firstarc=NULL;
    }
    for(int i=0;i<g.n;i++){
        for(int j=g.n-1;j>=0;j--){
            if(g.edges[i][j]!=0&&g.edges[i][j]!=INF){
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=j;
                p->weight=g.edges[i][j];
                p->nextarc=G->adjlist[i].firstarc;
                G->adjlist[i].firstarc=p;
            }
        }
    }
    G->n=g.n;
    G->e=g.e;
}

int main(){
    MatGragh g;
    AdjGragh *G;
    int A[MAXV][MAXV]={{0,1,0,4},{0,0,9,2},{3,5,0,8},{0,0,6,0}};
    int n=4;
    int e=8;
    CreateMat(g,A,n,e);
    printf("The adjacent matrix is: \n");
    DispMat(g);
    printf("\n");
    printf("Convert adjacent matrix to adjacent list.\n");
    MatToList(g,G);
    printf("The adjacent list is: \n");
    DispAdj(G);
    DestroyAdj(G);
    
    return 0;
}