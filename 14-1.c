#include <stdio.h>
#define NU 30

typedef struct
{
    int SumP;
    float AveP;
}data_b;

typedef struct
{
    int No;
    char Name[FILENAME_MAX];
    int LanP;
    int MatP;
    int EngP;
    data_b data;
}data_a;

FILE *fp;
int i;

//全て表示(1)
void print_a(data_a x[], int n)
{
    
    for(i = 0; i < n; i++)
    {
        printf("学籍番号 : %d\n氏　　名 : %s\n国語点数 : %d\n数学点数 : %d\n英語点数 : %d\n平均点数 : %.1f\n合計点数 : %d\n\n", 
            x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.AveP, x[i].data.SumP);
    }
    
}
//科目(平均、合計点)表示(3)
void print_b(data_a x[], int n)
{
    float Lsum = 0, Msum = 0, Esum = 0;
    
    for(i = 0; i < n; i++)
    {
        Lsum += x[i].LanP;
        Msum += x[i].MatP;
        Esum += x[i].EngP;
    }
        printf("国　語の平均点 : %.1f\n数　学の平均点 : %.1f\n英　語の平均点 : %.1f\n全科目の平均点 : %.1f\n", Lsum / n, Msum / n, Esum / n, (Lsum + Msum + Esum) / (n*3));

}

//番号からの表示(2)
void No_Sub(data_a x[], int n)
{
    int tmp;
    printf("学籍番号の入力 : ");    scanf("%d", &tmp);
    for(i = 0; i < n; i++)
        if(x[i].No == tmp)
            printf("学籍番号 : %d\n氏　　名 : %s\n国語点数 : %d\n数学点数 : %d\n英語点数 : %d\n平均点数 : %.1f\n合計点数 : %d\n\n", 
                x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.AveP, x[i].data.SumP);
}

//(5)
void max_max(data_a x[], int n)
{
    int count = 0;
    data_a max;

    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].data.SumP > max.data.SumP)
            max.data.SumP = x[i].data.SumP;

    for(i = 0; i < n; i++)
        if(x[i].data.SumP == max.data.SumP)
            printf("合計最高得点該当者\n学籍番号 : %d, 氏名 : %s, 国語点数 : %d, 数学点数 : %d, 英語点数 : %d, 合計点数 : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.SumP);
                puts("");
}
//(4)
void max_sp(data_a x[], int n)
{
    int count = 0;
    data_a max;

    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].LanP > max.LanP)
            max.LanP = x[i].LanP;

    for(i = 0; i < n; i++)
        if(x[i].LanP == max.LanP)
                printf("\n国語の最高得点該当者\n学籍番号 : %d, 氏名 : %s, 国語点数 : %d, 数学点数 : %d, 英語点数 : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);


    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].MatP > max.MatP)
            max.MatP= x[i].MatP;

    for(i = 0; i < n; i++)
        if(x[i].MatP == max.MatP)
                printf("\n数学の最高得点該当者\n学籍番号 : %d, 氏名 : %s, 国語点数 : %d, 数学点数 : %d, 英語点数 : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);


    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].EngP > max.EngP)
            max.EngP = x[i].EngP;

    for(i = 0; i < n; i++)
        if(x[i].EngP == max.EngP)
                printf("\n英語の最高得点該当者\n学籍番号 : %d, 氏名 : %s, 国語点数 : %d, 数学点数 : %d, 英語点数 : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);
}

//(6)～
void swap(data_a x[], data_a y[])
{
    data_a tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort_LanP(data_a x[], int n)
{
    for(int j = 0; j < n -1; j++)
    {
        for (i = n -1; i > j; i--)
            if(x[i - 1].LanP < x[i].LanP)
                swap(&x[i -1], &x[i]);
    }
    return print_a(x,n);
}

void sort_MatP(data_a x[], int n)
{
    for(int j = 0; j < n -1; j++)
    {
        for (i = n -1; i > j; i--)
            if(x[i - 1].MatP < x[i].MatP)
                swap(&x[i -1], &x[i]);
    }
    return print_a(x,n);
}
void sort_EngP(data_a x[], int n)
{
    for(int j = 0; j < n -1; j++)
    {
        for (i = n -1; i > j; i--)
            if(x[i - 1].EngP < x[i].EngP)
                swap(&x[i -1], &x[i]);
    }
    return print_a(x,n);
}

void sort_SumP(data_a x[], int n)
{
    for(int j = 0; j < n -1; j++)
    {
        for (i = n -1; i > j; i--)
            if(x[i - 1].data.SumP < x[i].data.SumP)
                swap(&x[i -1], &x[i]);
    }
    return print_a(x,n);
}

int SubCho(int tmp)
{
    do
    {
    printf("科目を選択してください \n国　語 : 1\n数　学 : 2\n英　語 : 3\n合計点 : 4\n終　了 : 5\n入力 : ");
    scanf("%d", &tmp);
    }while (tmp < 1&& tmp > 5);
    return tmp;
}

void SubUP(data_a x[], int n)
{
    switch(SubCho(i))
    {
        case 1 : sort_LanP(x, n);   break;
        case 2 : sort_MatP(x, n);   break;
        case 3 : sort_EngP(x, n);   break;
        case 4 : sort_SumP(x, n);   break;
        default:;   break;
    }
}
//(7)
void Sort_No(data_a x[], int n)
{
    for(int j = 0; j < n -1; j++)
    {
        for (i = n -1; i > j; i--)
            if(x[i - 1].No > x[i].No)
                swap(&x[i -1], &x[i]);
    }
    for(i = 0; i < n; i++)
    printf("学籍番号 : %d\n氏　　名 : %s\n国語点数 : %d\n数学点数 : %d\n英語点数 : %d\n平均点数 : %.1f\n合計点数 : %d\n\n", 
        x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.AveP, x[i].data.SumP);
}



int menu()
{
    int tmp;
    do
    {
    puts("\n    ** メニューを選び、入力してください **");
    puts("\n 1 全生徒の学籍番号、氏名、各科目点数、合計点、平均を表示\n");
    puts(" 2 学籍番号を入力して、個人の学籍番号、氏名、各科目点数、合計点、平均点を表示\n");
    puts(" 3 各科目、全科目の平均を表示\n");
    puts(" 4 各科目最高得点の学籍番号、氏名、各科目点数、合計点を表示\n");
    puts(" 5 合計最高点の学籍番号、氏名、各科目点数、合計点を表示\n");
    puts(" 6 各科目、全科目かを選択し、点数を降順に並べ替え、学籍番号、氏名、科目点数を表示\n");
    puts(" 7 学籍番号順に並べ替え、学籍番号、氏名、科目点数、合計点数を表示\n");
    puts(" 8 終了\n");
    printf("入力 : ");  scanf("%d", &tmp);

    } while (tmp < 0 && tmp < 8);
    return tmp;
}

int main()
{
    int x, z = 0;
    data_a std[NU] = {NULL};

    if((fp = fopen("data.dat", "r")) == NULL)
        printf("ファイルをオープンできない");
    
    else
    {
        for(i = 0; i < NU; i++)
        {    
            if( fscanf(fp, "%d %s %d %d %d", &std[i].No, std[i].Name, &std[i].LanP, &std[i].MatP, &std[i].EngP) != 5) break;
            z++;
        }
        fclose(fp);

        for (i = 0; i < z; i++)
        {
            std[i].data.SumP = std[i].LanP + std[i].MatP + std[i].EngP;
            std[i].data.AveP = std[i].data.SumP / 3;
        }
        
    }

    do 
    {
        switch (x = menu())
        {
            case 1 : print_a(std, z);
                break;
            case 2 : No_Sub(std, z);
                break;
            case 3 : print_b(std, z);
                break;
            case 4 : max_sp(std, z);
                break;
            case 5 : max_max(std, z);
                break;
            case 6 : SubUP(std, z);
                break;
            case 7 : Sort_No(std, z);
                break;
        }
    }while (x != 8);
    
    return 0;
}