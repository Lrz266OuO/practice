#include<stdio.h>
#include<windows.h>

int main(){
    int i,j;    //表示棋盘横纵坐标
    int chessboard[20][20];
    int color=0;//0表示黑棋，1表示白棋，2表示该位置没有棋
    int iTemp=0, jTemp=0, countTemp=0;
    int colorFlag=0;
    char op;

again:
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            chessboard[i][j]=2;
        }
    }

    while(1){
        printf("请输入棋子的位置（棋盘大小为20*20）：");
        scanf("%d,%d", &i,&j);
        if(i<1||i>20||j<1||j>20){
            printf("输入的位置超出了棋盘的范围，请重新输入。\n");
            continue;
        }
        if(chessboard[i-1][j-1]!=2){
            printf("该位置已经有棋子了，请重新输入。\n");
            continue;
        }

        color = (color+1)%2;//获取棋盘棋子属性
        chessboard[i-1][j-1]=color;//赋予该位置棋子的属性
        
        //根据棋盘对应的属性，绘制最新状态的棋盘
        //边缘位置特殊处理
        for(i=1; i<=20; i++){
            if(i==1){
                if(chessboard[i-1][0]==1) printf("●");
                if(chessboard[i-1][0]==0) printf("○");
                if(chessboard[i-1][0]==2) printf("┌ ");

                for(j=2; j<=19; j++){
                    if(chessboard[i-1][j-1]==1) printf("●");
                    if(chessboard[i-1][j-1]==0) printf("○");
                    if(chessboard[i-1][j-1]==2) printf("┬ ");
                }

                if(chessboard[i-1][j-1]==1) printf("●");
                if(chessboard[i-1][j-1]==0) printf("○");
                if(chessboard[i-1][j-1]==2) printf("┐ ");

                printf("\n");
            }

            if(i>=2&&i<19){
                if(chessboard[i-1][0]==1) printf("●");
                if(chessboard[i-1][0]==0) printf("○");
                if(chessboard[i-1][0]==2) printf("├ ");

                for(j=2; j<=19; j++){
                    if(chessboard[i-1][j-1]==1) printf("●");
                    if(chessboard[i-1][j-1]==0) printf("○");
                    if(chessboard[i-1][j-1]==2) printf("┼ ");
                }

                if(chessboard[i-1][j-1]==1) printf("●");
                if(chessboard[i-1][j-1]==0) printf("○");
                if(chessboard[i-1][j-1]==2) printf("┤ ");

                printf("\n");
            }

            if(i==20){
                if(chessboard[i-1][0]==1) printf("●");
                if(chessboard[i-1][0]==0) printf("○");
                if(chessboard[i-1][0]==2) printf("└ ");

                for(j=2; j<=19; j++){
                    if(chessboard[i-1][j-1]==1) printf("●");
                    if(chessboard[i-1][j-1]==0) printf("○");
                    if(chessboard[i-1][j-1]==2) printf("┴ ");
                }

                if(chessboard[i-1][j-1]==1) printf("●");
                if(chessboard[i-1][j-1]==0) printf("○");
                if(chessboard[i-1][j-1]==2) printf("┘ ");

                printf("\n");
            }
        }

        //判断输赢
        

    }

whileEnd:

}