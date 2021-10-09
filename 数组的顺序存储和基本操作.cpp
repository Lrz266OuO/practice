#include<iostream>
#include<stdarg.h>
using namespace std;
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef struct _ARRAY_{
    ElemType *pBase;
    int dim;
    int *pBounds;
    int *pContants;
}Array,*pArray;  

bool InitArray(pArray pArrayTemp,int iDim,...);
bool DestroyArray(pArray pArrayTemp);
void TravelArray(pArray pArrayTemp);
bool Assign(pArray pArrayTemp,ElemType e,...);
bool Locate(pArray pArrayTemp,va_list temp,int *offset);
bool Value(pArray pArrayTemp,ElemType *e,...);
bool InitArray(pArray pArrayTemp,int iDim,...){   
    if(iDim<1 || iDim>MAX_ARRAY_DIM){        
        return false;   
    }   
    pArrayTemp->dim = iDim;    
    int i = 0;            
    pArrayTemp->pBounds = (int*)malloc(sizeof(int)*iDim);
    if(pArrayTemp->pBounds == NULL){       
        return false;  
    }     
    va_list temp = {0};    
    va_start(temp,iDim);   
    int elemTotal = 1;    
    for(i = 0; i < iDim; i++){       
        pArrayTemp->pBounds[i] = va_arg(temp,int);
        if(pArrayTemp->pBounds[i] < 0){            
            free(pArrayTemp->pBounds);            
            return false;        
        }        
        elemTotal *= pArrayTemp->pBounds[i];
    }   
    va_end(temp);   
    pArrayTemp->pBase = (ElemType *)malloc(sizeof(ElemType)*elemTotal);
    if(pArrayTemp->pBase == NULL){        
        free(pArrayTemp->pBounds);        
        return false;   
    }        
    pArrayTemp->pContants = (int *)malloc(sizeof(int) * iDim);
    if(pArrayTemp->pContants == NULL){        
        free(pArrayTemp->pBounds);        
        free(pArrayTemp->pBase);        
        return false;    
    }    
    pArrayTemp->pContants[iDim-1] = 1;    
    for(i=iDim-2; i>=0; i--){       
        pArrayTemp->pContants[i] = pArrayTemp->pContants[i+1]*pArrayTemp->pBounds[i+1];
    }   
    return true;
}

bool DestroyArray(pArray pArrayTemp){    
    if(pArrayTemp->pBase != NULL){        
        free(pArrayTemp->pBase);        
        pArrayTemp->pBase = NULL;    
    }    
    if(pArrayTemp->pBounds != NULL){        
        free(pArrayTemp->pBounds);        
        pArrayTemp->pBounds = NULL;    
    }    
    if(pArrayTemp->pContants != NULL){        
        free(pArrayTemp->pContants);        
        pArrayTemp->pContants = NULL;    
    }   
    return true;
} 

void TravelArray(pArray pArrayTemp){    
    int i;    
    cout<<"dim:"<<pArrayTemp->dim<<endl;    
    cout<<"bounds:";    
    for(i = 0; i < pArrayTemp->dim; i++){       
        cout<<pArrayTemp->pBounds[i]<<" ";    
    }    
    cout<<endl;    
    cout<<"pConstants:";    
    for(i = 0; i<pArrayTemp->dim; i++){        
        cout<<pArrayTemp->pContants[i]<<" ";    
    }    
    cout<<endl;    
    cout<<"data:";    
    int count = 1;    
    for(i = 0; i < pArrayTemp->dim; i++){        
        count *= pArrayTemp->pBounds[i];   
    }    
    for(i = 0; i < count; i++){        
        cout<<pArrayTemp->pBase[i]<<" ";    
    }    
    cout<<endl;
} 

bool Assign(pArray pArrayTemp,ElemType e,...){    
    va_list temp = {0};    
    int offset = 0;    
    va_start(temp,e);    
    bool result = Locate(pArrayTemp,temp,&offset);    
    *(pArrayTemp->pBase + offset) = e;    
    va_end(temp);    
    return result;
}

bool Locate(pArray pArrayTemp,va_list temp,int *offset){    
    int iTemp = 0;    int i = 0;    *offset = 0;
    for(i = 0; i < pArrayTemp->dim; i++){        
        iTemp = va_arg(temp,int);        
        *offset += iTemp*(pArrayTemp->pContants[i]);    
    }    
    return true;
}

bool Value(pArray pArrayTemp,ElemType *e,...){    
    va_list temp;   
    va_start(temp,e);   
    bool result = false;    
    int offset;    
    result = Locate(pArrayTemp,temp,&offset);    
    *e = pArrayTemp->pBase[offset];    
    va_end(temp);    
    return result;
}

int main(){   
    Array ArrayTemp = {0};    
    InitArray(&ArrayTemp,3,3,2,2);    
    int i = 0,j = 0,k = 0;    
    for(i = 0; i<ArrayTemp.pBounds[0];i++){        
        for(j = 0; j < ArrayTemp.pBounds[1];j++){            
            for(k = 0; k <ArrayTemp.pBounds[2];k++){                
                Assign(&ArrayTemp,i*100+j*10+k,i,j,k);            
            }        
        }    
    }    
    ElemType e;    
    Value(&ArrayTemp,&e,1,1,1);    
    TravelArray(&ArrayTemp);    
    cout<<"e = "<<e<<endl;    
    DestroyArray(&ArrayTemp);    
    return 0;
}
