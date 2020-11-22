#include"game.h"
int player(char p[ROW][COL],int row,int col,char p2[ROW][COL])
{
    int u;
    while(1)
    {
        int x,y;
        printf("请输入一个位置坐标，行 列：\n");
        scanf("%d%d",&x,&y);
        if(x-1>=0 && x-1<row &&y-1>=0 &&y-1<col && p[x-1][y-1]!='*')
        {
            system("cls");
            p2[x-1][y-1]=p[x-1][y-1];
            lian(p,p2,row,col,x-1,y-1);
            chuang(p2,ROW,COL);
            u=win(p2,row,col);
            if(u==LEI)
                return 1;
        }
        else if(p[x-1][y-1]=='*')
        {
           system("cls");
           chuang(p,ROW,COL);
           return 0;
        }
        else
        {
            printf("输入违规\n");
        }
    }
}
int win(char p2[ROW][COL],int row,int col)
{
    int u=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(p2[i][j]==' ')
            {
                u++;
            }
        }
    }
    return u;
}
void lian(char p[ROW][COL],char p2[ROW][COL],int row,int col,int i,int j)
{
    if(p[i][j]=='0')
    {
                if(p[i+1][j]!='*' && (i+1)<row)
                {
                    p2[i+1][j]=p[i+1][j];
                    lian(p,p2,row,col,i+1,j);
                }
                if(p[i+1][j+1]!='*' && (i+1)<row && (j+1)<col)
                {
                    p2[i+1][j+1]=p[i+1][j+1];
                }
                if(p[i+1][j-1]!='*' && (i+1)<row && (j-1)>=0)
                {
                    p2[i+1][j-1]=p[i+1][j-1];
                }
                if(p[i][j-1]!='*' && (j-1)>=0)
                {
                    p2[i][j-1]=p[i][j-1];
                }
                if(p[i][j+1]!='*' && i<row && (j+1)<col)
                {
                    p2[i][j+1]=p[i][j+1];
                    lian(p,p2,row,col,i,j+1);
                }
                if(p[i-1][j-1]!='*' && (i-1)>=0 && (j-1)>=0)
                {
                    p2[i-1][j-1]=p[i-1][j-1];
                }
                if(p[i-1][j]!='*' && (i-1)>=0)
                {
                    p2[i-1][j]=p[i-1][j];
                }
                if(p[i-1][j+1]!='*' && (i-1)>=0 && (j+1)<col)
                {
                    p2[i-1][j+1]=p[i-1][j+1];
                }
    }
}
void shu(char p[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            char d='0';
            if(p[i][j]=='0')
            {
                if(p[i+1][j]=='*' && (i+1)<row)
                {
                    d++;
                }
                if(p[i+1][j+1]=='*' && (i+1)<row && (j+1)<col)
                {
                    d++;
                }
                if(p[i+1][j-1]=='*' && (i+1)<row && (j-1)>=0)
                {
                    d++;
                }
                if(p[i][j-1]=='*' && (j-1)>=0)
                {
                    d++;
                }
                if(p[i][j+1]=='*' && i<row && (j+1)<col)
                {
                    d++;
                }
                if(p[i-1][j-1]=='*' && (i-1)>=0 && (j-1)>=0)
                {
                    d++;
                }
                if(p[i-1][j]=='*' && (i-1)>=0)
                {
                    d++;
                }
                if(p[i-1][j+1]=='*' &&  (j+1)<col  && (i-1)>=0)
                {
                    d++;
                }
                p[i][j]=d;
            }
        }
    }
}
void chu0(char p[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(p[i][j]!='*')
            {
                p[i][j]='0';
            }
        }
    }
}
void lei(char p[ROW][COL],int row,int col)
{
    int i=0;
    while(i<LEI)
    {
       int x=rand()%10;
       int y=rand()%10;
       if(x !=0 && y!=0)
       {
           if(p[x-1][y-1]!='*')
       {
           p[x-1][y-1]='*';
           i++;
       }
       }
       else if(x==0 &&y!= 0)
       {
           if(p[x][y-1]!='*')
       {
           p[x][y-1]='*';
           i++;
       }
       }
       else if(x!=0 &&y== 0)
       {
           if(p[x-1][y]!='*')
       {
           p[x-1][y]='*';
           i++;
       }
       }
       else
       {
           if(p[x][y]!='*')
       {
           p[x][y]='*';
           i++;
       }
       }

    }
}
void chu(char p[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            p[i][j]=' ';
        }
    }
}
void chuang(char p[ROW][COL],int row,int col)
{
        for(int j=0;j<col;j++)
        {
            printf("  %d ",j+1);
        }
        printf("\n");
    int l=0;
    for(int i=0;i<row;)
    {
        if(l==0 || l%2==0)
        {
            printf("%d",i+1);
            for(int j=0;j<col;j++)
        {
            printf(" %c ",p[i][j]);
            if(j!=col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        i++;
        l++;
        }
        else
        {
            printf(" ");
            for(int j=0;j<col;j++)
            {
                printf("---");
                if(j!=col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
            l++;
        }
    }
}
void menu()
{
    printf("*******************      提示：数字表示周围雷的个数   *********************\n");
    printf("*******************              共10个雷             *********************\n");
    printf("*******************                扫雷               *********************\n");
    printf("*******************            1.play 0.exit          *********************\n");
    printf("                                  请输入：");
}
void game()
{
    int o;
    srand((unsigned int)time(NULL));
    char p[ROW][COL];
    chu(p,ROW,COL);
    chuang(p,ROW,COL);
    lei(p,ROW,COL);
    chu0(p,ROW,COL);
    shu(p,ROW,COL);
    char p2[ROW][COL];
    chu(p2,ROW,COL);
    do
    {
        o = player(p,ROW,COL,p2);
    }
    while(o!=0 && o!=1);
    if(o==0)
        printf("你输了，游戏结束\n");
    if(o==1)
        printf("你赢了\n");
}
