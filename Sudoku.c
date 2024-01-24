#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void tahtayazdir(char tahta[11][11]){
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            printf("%c ",tahta[i][j]);
        }
        printf("\n");
    }
    
}
int main(){
    srand(time(NULL));
    int sayi,x,y;
    char tahta[11][11];
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j==3 || j== 7)
            {
                tahta[i][j] = '|';
            }
            else if (i==3 || i==7)
            {
                tahta[i][j]= '-';
            }
            else{
                tahta[i][j]= '*';
            }
            
        }
        
    }
    int sayac =0,oluyor =0;
    while(oluyor<35)
    {
        sayi = rand()%9+49;
        x = rand()%12;
        y = rand()%12;
        if (x!=3 && x!=7 && y!= 3 && y!=7)
        {
            for (int j = 0; j < 11; j++)
            {
                if (tahta[x][j] == sayi || tahta[j][y]== sayi)
                {
                    sayac = 1;
                }
                
                
            }
            if (sayac == 0 && tahta[x][y] == '*')
            {
                tahta[x][y] = sayi;
                oluyor++;
            }
            
        }
        sayac = 0;
        
    }
    
    tahtayazdir(tahta);
    int ksatir,ksutun,bitti=1,yildizsayac =0;
    while (1)
    {
        printf("Satir Giriniz: ");
        scanf("%d",&ksatir);
        printf("Sutun Giriniz: ");
        scanf("%d",&ksutun);
        printf("Sayi Gir(1-9): ");
        scanf("%d",&sayi);
        if (tahta[ksatir-1][ksutun-1] == '*')
        {
            tahta[ksatir-1][ksutun-1] = sayi + 48;
        }
        tahtayazdir(tahta);
        for (int i = 0; i < 11; i++)
        {
            if (tahta[ksatir-1][ksutun-1] == tahta[ksatir-1][ksutun+i] || 
            tahta[ksatir-1][ksutun-1] == tahta[ksatir+i][ksutun-1] || 
            tahta[ksatir-1][ksutun-1] == tahta[ksatir-1][ksutun-i-2] ||
            tahta[ksatir-1][ksutun-1] == tahta[ksatir-2-i][ksutun-1])
            {
                printf("LOSE\n");
                break;
                bitti=0;
            }
            
        }
        if (bitti=0)
        {
            break;
        }
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (tahta[i][j]=='*')
                {
                    yildizsayac++;
                }
            }
            
        }
        if (yildizsayac==0)
        {
            printf("WIN");
            break;
        }
        yildizsayac =0;
        
    }
    return 0;
}