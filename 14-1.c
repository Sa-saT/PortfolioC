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

//�S�ĕ\��(1)
void print_a(data_a x[], int n)
{
    
    for(i = 0; i < n; i++)
    {
        printf("�w�Дԍ� : %d\n���@�@�� : %s\n����_�� : %d\n���w�_�� : %d\n�p��_�� : %d\n���ϓ_�� : %.1f\n���v�_�� : %d\n\n", 
            x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.AveP, x[i].data.SumP);
    }
    
}
//�Ȗ�(���ρA���v�_)�\��(3)
void print_b(data_a x[], int n)
{
    float Lsum = 0, Msum = 0, Esum = 0;
    
    for(i = 0; i < n; i++)
    {
        Lsum += x[i].LanP;
        Msum += x[i].MatP;
        Esum += x[i].EngP;
    }
        printf("���@��̕��ϓ_ : %.1f\n���@�w�̕��ϓ_ : %.1f\n�p�@��̕��ϓ_ : %.1f\n�S�Ȗڂ̕��ϓ_ : %.1f\n", Lsum / n, Msum / n, Esum / n, (Lsum + Msum + Esum) / (n*3));

}

//�ԍ�����̕\��(2)
void No_Sub(data_a x[], int n)
{
    int tmp;
    printf("�w�Дԍ��̓��� : ");    scanf("%d", &tmp);
    for(i = 0; i < n; i++)
        if(x[i].No == tmp)
            printf("�w�Дԍ� : %d\n���@�@�� : %s\n����_�� : %d\n���w�_�� : %d\n�p��_�� : %d\n���ϓ_�� : %.1f\n���v�_�� : %d\n\n", 
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
            printf("���v�ō����_�Y����\n�w�Дԍ� : %d, ���� : %s, ����_�� : %d, ���w�_�� : %d, �p��_�� : %d, ���v�_�� : %d\n"
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
                printf("\n����̍ō����_�Y����\n�w�Дԍ� : %d, ���� : %s, ����_�� : %d, ���w�_�� : %d, �p��_�� : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);


    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].MatP > max.MatP)
            max.MatP= x[i].MatP;

    for(i = 0; i < n; i++)
        if(x[i].MatP == max.MatP)
                printf("\n���w�̍ō����_�Y����\n�w�Дԍ� : %d, ���� : %s, ����_�� : %d, ���w�_�� : %d, �p��_�� : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);


    max = x[0];

    for(i = 1; i < n; i++)
        if(x[i].EngP > max.EngP)
            max.EngP = x[i].EngP;

    for(i = 0; i < n; i++)
        if(x[i].EngP == max.EngP)
                printf("\n�p��̍ō����_�Y����\n�w�Дԍ� : %d, ���� : %s, ����_�� : %d, ���w�_�� : %d, �p��_�� : %d\n"
                    , x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP);
}

//(6)�`
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
    printf("�Ȗڂ�I�����Ă������� \n���@�� : 1\n���@�w : 2\n�p�@�� : 3\n���v�_ : 4\n�I�@�� : 5\n���� : ");
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
    printf("�w�Дԍ� : %d\n���@�@�� : %s\n����_�� : %d\n���w�_�� : %d\n�p��_�� : %d\n���ϓ_�� : %.1f\n���v�_�� : %d\n\n", 
        x[i].No, x[i].Name, x[i].LanP, x[i].MatP, x[i].EngP, x[i].data.AveP, x[i].data.SumP);
}



int menu()
{
    int tmp;
    do
    {
    puts("\n    ** ���j���[��I�сA���͂��Ă������� **");
    puts("\n 1 �S���k�̊w�Дԍ��A�����A�e�Ȗړ_���A���v�_�A���ς�\��\n");
    puts(" 2 �w�Дԍ�����͂��āA�l�̊w�Дԍ��A�����A�e�Ȗړ_���A���v�_�A���ϓ_��\��\n");
    puts(" 3 �e�ȖځA�S�Ȗڂ̕��ς�\��\n");
    puts(" 4 �e�Ȗڍō����_�̊w�Дԍ��A�����A�e�Ȗړ_���A���v�_��\��\n");
    puts(" 5 ���v�ō��_�̊w�Дԍ��A�����A�e�Ȗړ_���A���v�_��\��\n");
    puts(" 6 �e�ȖځA�S�Ȗڂ���I�����A�_�����~���ɕ��בւ��A�w�Дԍ��A�����A�Ȗړ_����\��\n");
    puts(" 7 �w�Дԍ����ɕ��בւ��A�w�Дԍ��A�����A�Ȗړ_���A���v�_����\��\n");
    puts(" 8 �I��\n");
    printf("���� : ");  scanf("%d", &tmp);

    } while (tmp < 0 && tmp < 8);
    return tmp;
}

int main()
{
    int x, z = 0;
    data_a std[NU] = {NULL};

    if((fp = fopen("data.dat", "r")) == NULL)
        printf("�t�@�C�����I�[�v���ł��Ȃ�");
    
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