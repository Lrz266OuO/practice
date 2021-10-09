#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX_VALUE 1000 
#define MAX_POINT_NUM 10 
typedef int matrix[MAX_POINT_NUM][MAX_POINT_NUM];

typedef struct
{
    int vertex[MAX_POINT_NUM];
    matrix vertex_matrix;
    int vertex_num;
    int arc_num;
}digragh;

int locatevertex(digragh *G,int x){
    for(int i=0;i<G->vertex_num;i++){
        if(G->vertex[i]==x) return i;
    }
    return -1;
}

void init_digraph(digragh *G){
    cout<<"Please input vertex and arc: ";
    cin>>G->vertex_num>>G->arc_num;
    cout<<"Please input vertex point value: ";
    int i;
    for(i=0;i<G->vertex_num;i++){
        cin>>G->vertex[i];
    }
    
    int j;
    i=0;
    for(i=0;i<G->vertex_num;i++){
        for(j=0;j<G->vertex_num;j++){
            G->vertex_matrix[i][j]=MAX_VALUE;
        }
    }

    int v1,v2;
    int weight;
    cout<<"Please input two points and weight between them: "<<endl;
    for(int k=0;k<G->arc_num;k++){
        cin>>v1>>v2>>weight;
        i=locatevertex(G,v1);
        j=locatevertex(G,v2);
        G->vertex_matrix[i][j]=weight;
    }
}

void print_digragh(digragh *G){
    for(int i=0;i<G->vertex_num;i++){
        for(int j=0;j<G->vertex_num;j++){
            if(i==j) cout<<"0 ";
            else if(G->vertex_matrix[i][j]==MAX_VALUE) cout<<"N ";
            else cout<<G->vertex_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    digragh G;
    init_digraph(&G);
    print_digragh(&G);
    return 0;
}