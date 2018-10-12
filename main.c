#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char sno[20];
    char name[20];
    double score;
    void AddStd();
    void QueryById();
    void ListAll();
    void AvgScore();
    void MaxScore();
    void menu();
};
//    1、输入学生信息函数AddStd实现添加学生相关信息；
void student::AddStd()
{
    system("cls");
    char op;
    printf("请依次输入学生的学号、姓名（汉语拼音）和分数（回车键隔开）：\n");
    scanf("%s",sno);
    scanf("%s",name);
    scanf("%lf",&score);
    FILE *info=fopen("score.txt","a+");
    if(info==NULL)
        printf("文件操作失败\n");
    fprintf(info,"%s,%s,%0.2f\n",sno,name,score);
    fclose(info);
    system("cat score.txt");//Linux下显示score.txt文件的内容，Windows下为system("type score.txt");
    printf("是否继续添加学生信息，y/n\n");
    getchar();
    scanf("%c",&op);
    if(op=='y')
        AddStd();
    else
        menu();
}
//2、按学号查询学生详细信息（包括成绩）QueryById;
void student::QueryById()
{
    system("cls");
    char sno1[20],op;
    char allmost[100];
    int flag=1;
    printf("请输入您要查询的学号：\n");
    scanf("%s",sno1);
    FILE *info=fopen("score.txt","r");
    if(info==NULL)
        printf("读取文件失败\n");
    while(!feof(info))
    {
        flag=1;
        fscanf(info,"%s",allmost);
        for(int i=0;i<strlen(sno1);i++)
            if(allmost[i]!=sno1[i])
                flag=0;
        if(flag)
        {
            printf("学号为%s的学生的详细信息如下：\n%s\n\n",sno1,allmost);
            break;
        }
    }
    if(flag==0)
        printf("未查询到相应的学生的详细信息\n\n");
    fclose(info);
    printf("是否继续查询学生信息，y/n\n");
    getchar();
    scanf("%c",&op);
    if(op=='y')
        QueryById();
    else
        menu();
}
//3、成绩列表函数ListAll按学号排序输出学生信息；
void student::ListAll()
{
    system("cls");
    char origin[100][100];//二维数组和指针一维数组的区别
    char subo[100][20];
    int i,j,k;
    FILE* info=fopen("score.txt","r");
    if(info==NULL)
        printf("读取文件失败\n");
    for(i=0;!feof(info);i++)
    {
        fscanf(info,"%s",origin[i]);
    }
    k=i-1;
    for(i=0;i<k;i++)
        for(j=0;origin[i][j]!=',';j++)
            subo[i][j]=origin[i][j];
    for(i=0;i<k-1;i++)
        for(j=0;j<k-i-1;j++)
        if(strcmp(subo[j],subo[j+1])>0)//大于返回大于0的数，小于返回小于0的数，等于返回0
        {
            char temp[20];
            strcpy(temp,subo[j]);
            strcpy(subo[j],subo[j+1]);
            strcpy(subo[j+1],temp);
        }


    for(i=0;i<k;i++)
    {
        char sno1[20];
        strcpy(sno1,subo[i]);
        int flag=1;
        for(j=0;j<k;j++)
        {
            flag=1;
            for(int i=0;i<strlen(sno1);i++)
                if(origin[j][i]!=sno1[i])
                    flag=0;
            if(flag)
            {
                printf("%s\n",origin[j]);
                break;
            }
        }
    }

    fclose(info);
    printf("请按任意键继续...\n");
    getchar();
    getchar();
}
//4、输出平均分AvgScore；
void student::AvgScore()
{
    system("cls");
    int i,j,k;
    int sum[100]={0};
    float avger=0;
    char sno1[100][20],name1[100][20],allm[100][100];
    char sc1[100][20];
    FILE* info=fopen("score.txt","r");
    if(info==NULL)
        printf("读取文件失败\n");
    for(i=0;!feof(info);i++)
    {
        fscanf(info,"%s",allm[i]);
        sscanf(allm[i],"%[^,],%[^,],%[0-9]",sno1[i],name1[i],sc1[i]);//读取逗号间隔的字符串
    }
    k=i-1;
//将字符串类型的成绩转换为int类型
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
            if(sc1[i][j]!=0)
            {
                sum[i]=sum[i]*10+(sc1[i][j]-'0');
            }
    }
    for(i=0;i<k;i++)
        avger+=sum[i];
    printf("平均分数为：\n%0.2f\n",avger/k);

    fclose(info);
    printf("请按任意键继续\n");
    getchar();
    getchar();
}
//5、输出最高分MaxScore学生信息（需要注意的是最高分的学生可能不只一人）。
void student::MaxScore()
{
    system("cls");
    int i,j,k;
    int sum[100]={0},sum1[100]={0};
    char sno1[100][20],name1[100][20],allm[100][100];
    char sc1[100][20];
    FILE* info=fopen("score.txt","r");
    if(info==NULL)
        printf("读取文件失败\n");
    for(i=0;!feof(info);i++)
    {
        fscanf(info,"%s",allm[i]);
        sscanf(allm[i],"%[^,],%[^,],%[0-9]",sno1[i],name1[i],sc1[i]);//读取逗号间隔的字符串
    }
    k=i-1;
//将字符串类型的成绩转换为int类型
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
            if(sc1[i][j]!=0)
            {
                sum[i]=sum[i]*10+(sc1[i][j]-'0');
            }
    }
    for(i=0;i<k-1;i++)
        for(j=0;j<k-i-1;j++)
            if(sum[j]<sum[j+1])
            {
                int temp=sum[j];
                sum[j]=sum[j+1];
                sum[j+1]=sum[j];
            }
    printf("最高成绩为：\n%d\n\n",sum[0]);
    printf("获得最高成绩学生的基本信息如下：\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
            if(sc1[i][j]!=0)
            {
                sum1[i]=sum1[i]*10+(sc1[i][j]-'0');
            }
        if(sum1[i]==sum[0])
            printf("%s\n",allm[i]);
    }

    fclose(info);
    printf("\n请按任意键继续\n");
    getchar();
    getchar();
}
//利用while循环实现功能界面输出，根据用户选择调用对应的功能选项。
void student::menu()
{
    int flag;
    while(1)
    {
        system("cls");//Linux下的清屏函数，Windows是system("cls");
        printf("\n\n*****************学生成绩管理系统*****************\n\n");
        printf("0、退出\n");
        printf("1、输入学生信息添加学生相关信息\n");
        printf("2、按学号查询学生详细信息\n");
        printf("3、按学号排序输出学生信息\n");
        printf("4、输出平均分\n");
        printf("5、输出最高分的学生信息\n\n");
        printf("请输入您要进行的操作：\n");
        scanf("%d",&flag);
        switch(flag)
        {
        case 0:
            exit(0);
            break;
        case 1:
            AddStd();
            break;
        case 2:
            QueryById();
            break;
        case 3:
            ListAll();
            break;
        case 4:
            AvgScore();
            break;
        case 5:
            MaxScore();
            break;
        default:
            printf("输入错误，请重新输入\n");
            getchar();
            getchar();
            break;
        }
    }
}
int main()
{
    student stu1;
    stu1.menu();
    return 0;
}
