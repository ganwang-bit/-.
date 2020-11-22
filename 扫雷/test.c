#include"game.h"
void test()
{
    int x;
    while(1)
    {
    menu();
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        system("cls");
        game();
        break;
    case 0:
        system("cls");
        printf("退出游戏\n");
        break;
    default:
        printf("                          请输入1或0\n");
        break;
    }
    if(x==0)
        break;
    }
}
int main()
{
    test();
    return 0;
}

