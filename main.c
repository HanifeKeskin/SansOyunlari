#include <stdio.h>
#include <stdlib.h>
#include <time.h> //RASTGELE SAYI DONDURMEK ICIN (time(NULL))
#include <conio.h> // srand() - rand() KOMUTLARINI ALMAK ICIN
int secim1,secim2,secim4,i,j,geciciSayi1=0,geciciSayi2=0;
char secim3;
int saLoOynananSayi[6],saLoCikanSayi[6],saLoTutmaSayisi=0,saLoOdul=0,saLoRastgeleSayi,saLoOyunSayisi=0,saLoToplamTutturma=0,saLoToplamOdul=0,saLoTekrarEdenSayi=1;
int saToOynananSayi[5],saToCikanSayi[5],saToTutmaSayisi=0,saToOynananSayi1,saToCikanSayi1,saToTutmaSayisi1=0,saToOdul=0,saToRasgeleSayi,saToRastgeleSayi1,saToOyunSayi=0,saToToplamTutturma=0,saToToplamOdul=0,saToTekrarEdenSayi=1,saToTekrarEdenSayi1;
int onNuOynananSayi[10],onNuCikanSayi[22],onNuTutmaSayisi=0,onNuOdul=0,onNuRastgeleSayi,onNuOyunSayisi=0,onNUToplamTutturma=0,onNuToplamOdul=0,onNuTekrarEdenSayi=1;
int suLoOynananSayi[6],suLoCikanSayi[6],suLoTutmaSayisi=0,suLoOdul=0,suLoRastgeleSayi,suLoOyunSayisi=0,suLoToplamTutturma=0,suLoToplamOdul=0,suLoTekrarEdenSayi=1;
unsigned int seed;
int main()
{
    printf("\nRastgele Sayi Ureticisi Icin Cekirdek(Seed) Degerini Giriniz:");
    scanf("%u",&seed);
    seed=time(NULL);
    srand(seed);
    printf("\n");
    for(;;)
    {
        printf("   ANA MENU\n 1.Sans Oyunlari\n 2.Istatistikler\n 3.Cikis\n");
        int secim1;
        printf("Secimizi Girin:");
        scanf("%d",&secim1);
        system("cls");
        switch(secim1)  //ANA MENU OLUÞUMU
        {
        case 1:
            SansOyunlari();
            break;
        case 2:
            Istatistikler();
            break;
        case 3:
            printf("\tCIKIS YAPILDI.\n");
            exit(0);
        default:
            printf("Hatali Giris Yaptiniz.Lutfen ' 1-3 ' Arasinda Bir Secim Yapiniz.\n");
        }
    }
    return 0;
}
void SansOyunlari()
{
    for(;;)
    {
        printf(" \nSANS OYUNLARI ALT MENUSU\n 1.Sayisal Loto Oynama \n 2.Sans Topu Oynama \n 3.On Numara Oynama\n 4.Super Loto Oynama\n 5.Ana Menu\n\n");
        printf("(Toplam Odulunuz:%d )",saLoToplamOdul+saToToplamOdul+onNuToplamOdul+suLoToplamOdul);
        printf("\tSecimizi Girin:");
        scanf("%d",&secim2);
        system("cls");
        switch(secim2)  //SANS OYUNLARI ALT MENUSU OLUÞUMU
        {
        case 1:
            SayisalLoto();
            break;
        case 2:
            SansTopu();
            break;
        case 3:
            OnNumara();
            break;
        case 4:
            SuperLoto();
            break;
        case 5:
            main();
        default:
            printf("\n Hatali Giris Yaptiniz.Lutfen ' 1-5 ' Arasinda Bir Secim Yapiniz.\n");
        }
    }
}
int Istatistikler()
{
    printf("   ISTATISTIKLER\n1.Sayisal Loto Istatistikleri\n2.Sans Topu Istatistikleri\n3.On Numara Istatistikleri\n4.Super Loto Istatistikleri\n");
    printf("\nGORMEK ISTEDIGINIZ ISTATISTIGI SECINIZ:");
    scanf("%d",&secim4);
    system("cls");
    switch(secim4)
    {
    case 1:
        return SayisalLotoIstatistikleri();
        break;
    case 2:
        return SansTopuIstatistikleri();
        break;
    case 3:
        return OnNumaraIstatistikleri();
        break;
    case 4:
        return SuperLotoIstatistikleri();
        break;
    default:
        printf("Hatali Giris Yaptiniz.Lutfen ' 1-4 ' Arasinda Bir Secim Yapiniz.\n");
    }
    return 0;
}
void SayisalLoto()
{
    system("cls");
    seed=time(NULL);
    srand(seed);
    for(i = 0 ; i <6 ; i++)
    {

        printf(" '1-49' ARALIGINDA %d. SAYIYI GIRINIZ:",i+1);
        scanf("%d",&saLoOynananSayi[i]);
        if(saLoOynananSayi[i]>=1 && saLoOynananSayi[i]<50)
        {
            for(j=0; j<i; j++)
            {
                if(saLoCikanSayi[j] == saLoOynananSayi[i])
                {
                    break;
                }
            }
            if(i == j )
            {
                saLoCikanSayi[i] = saLoOynananSayi[j];
            }
            if ( i != j)
            {
                printf("[HATA]:AYNI SAYI GIRISI YAPILDI.LUTFEN TEKRAR GIRINIZ\n ");
                i--;
            }
        }
        else
        {
            printf("[HATA]:LUTFEN TEKRAR");
            i--;
        }
    }
    for(i=0; i<6; i++)
    {
        saLoRastgeleSayi=1+rand()%49; // 1-49 ARASINDA RASTGELE SAYI URETILDI.
        saLoCikanSayi[i]=saLoRastgeleSayi; //URETILEN SAYILAR SIRASIYLA DIZIYE ATANDI.
    }
    saLoOyunSayisi++;
    for(i=0; i<6; i++) //OYNANAN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<5; j++)
        {
            if(saLoOynananSayi[j]>saLoOynananSayi[j+1])
            {
                geciciSayi1=saLoOynananSayi[j];
                saLoOynananSayi[j]=saLoOynananSayi[j+1];
                saLoOynananSayi[j+1]=geciciSayi1;
            }
        }
    }
    for(i=0; i<6; i++) //RASTGELE URETILEN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<5; j++)
        {
            if(saLoCikanSayi[j]>saLoCikanSayi[j+1])
            {
                geciciSayi2=saLoCikanSayi[j];
                saLoCikanSayi[j]=saLoCikanSayi[j+1];
                saLoCikanSayi[j+1]=geciciSayi2;
            }
        }
    }
    for(i=0; i<6; i++) //TUTTURMA
    {
        for(j=0; j<6; j++)
        {
            if(saLoOynananSayi[i]==saLoCikanSayi[j])
                saLoTutmaSayisi++;
        }
    }
    saLoToplamTutturma+=saLoTutmaSayisi;

    printf("\tSAYISAL LOTO SONUCLARI\n 'OYNANAN SAYILAR'\t'CIKAN SAYILAR'\n");
    for(i=0; i<6; i++)
    {
        printf("\t%d\t\t%d\n",saLoOynananSayi[i],saLoCikanSayi[i]);
    }
    printf("TUTTURULAN SAYI=%d\n",saLoTutmaSayisi); // TUTMA SAYISI EKRANA YAZDIRILDI.
    if(saLoTutmaSayisi==3)
    {
        saLoOdul=32;
        saLoToplamOdul+=saLoOdul;
    }
    else if(saLoTutmaSayisi==4)
    {
        saLoOdul=64;
        saLoToplamOdul+=saLoOdul;
    }

    else if(saLoTutmaSayisi==5)
    {
        saLoOdul=128;
        saLoToplamOdul+=saLoOdul;
    }
    else if(saLoTutmaSayisi==6)
    {
        saLoOdul=256;
        saLoToplamOdul+=saLoOdul;
    }
    else
    {
        saLoOdul=0;
        saLoToplamOdul+=saLoOdul;
    }
    saLoTutmaSayisi=0;
    printf("KAZANILAN ODUL=%d\n",saLoOdul);
    printf("TEKRAR SAYISAL LOTO OYNAMAK ICIN 'e/E' , CIKIS YAPMAK ICIN LUTFEN 'h/H' BASINIZ:");
    secim3=getch();
    for(;;)
    {
        switch(secim3)
        {
        case 'e':
        case 'E':
            return SayisalLoto();
            break;
        case 'h':
        case 'H':
            return SansOyunlari();
            break;
        default:
            printf("\nGECERSIZ GIRIS YAPTINIZ.\tTEKRAR DENEYIN:");
            secim3=getch();
        }
    }

}
void SansTopu()
{
    seed=time(NULL);
    srand(seed);
    for(i = 0 ; i <5 ; i++)
    {
        printf(" '1-34' ARALIGINDA %d. SAYIYI GIRINIZ:",i+1);
        scanf("%d",&saToOynananSayi[i]);
        if(saToOynananSayi[i]>=1 && saToOynananSayi[i]<35)
        {
            for(j=0; j<i; j++)
            {
                if(saToCikanSayi[j] == saToOynananSayi[i])
                {
                    break;
                }
            }
            if(i == j )
            {
                saToCikanSayi[i] = saToOynananSayi[j];
            }
            if ( i != j)
            {
                printf("[HATA]:AYNI SAYI GIRISI YAPILDI.LUTFEN TEKRAR GIRINIZ\n ");
                i--;
            }
        }
        else
        {
            printf("[HATA]:LUTFEN TEKRAR");
            i--;
        }
    }

    do
    {
        printf("'1-14' ARALIGINDA BIR SAYI GIRINIZ:");
        scanf("%d",&saToOynananSayi1);
        if(saToOynananSayi1<1 || saToOynananSayi1>14)
            printf("[HATA]:LUTFEN TEKRAR");
    }
    while(saToOynananSayi1<1 || saToOynananSayi1>14);
    for(i=0; i<6; i++)
    {
        saToRasgeleSayi=1+rand()%34; // 1-49 ARASINDA RASTGELE SAYI URETILDI.
        saToCikanSayi[i]=saToRasgeleSayi; //URETILEN SAYILAR SIRASIYLA DIZIYE ATANDI.
    }
    saToRastgeleSayi1=1+rand()%14;
    saToCikanSayi1=saToRastgeleSayi1;
    saToOyunSayi++;
    for(i=0; i<5; i++) //OYNANAN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<4; j++)
        {
            if(saToOynananSayi[j]>saToOynananSayi[j+1])
            {
                geciciSayi1=saToOynananSayi[j];
                saToOynananSayi[j]=saToOynananSayi[j+1];
                saToOynananSayi[j+1]=geciciSayi1;
            }
        }
    }
    for(i=0; i<5; i++) //RASTGELE URETILEN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<4; j++)
        {
            if(saToCikanSayi[j]>saToCikanSayi[j+1])
            {
                geciciSayi2=saToCikanSayi[j];
                saToCikanSayi[j]=saToCikanSayi[j+1];
                saToCikanSayi[j+1]=geciciSayi2;
            }
        }
    }
    for(i=0; i<5; i++) //TUTTURMA1
    {
        for(j=0; j<5; j++)
        {
            if(saToOynananSayi[i]==saToCikanSayi[j])
                saToTutmaSayisi++;
        }
    }
    if(saToOynananSayi1==saToCikanSayi1)
        saToTutmaSayisi1++;
    saToToplamTutturma+=(saToTutmaSayisi+saToTutmaSayisi1);
    printf("\tSUPER LOTO SONUCLARI\n 'OYNANAN SAYILAR'\t'CIKAN SAYILAR'\n");
    for(i=0; i<5; i++)
    {
        printf("\t%d\t\t%d\n",saToOynananSayi[i],saToCikanSayi[i]);
    }
    printf("\n\t%d\t\t%d",saToOynananSayi1,saToCikanSayi1);
    if(saToTutmaSayisi==0)
        printf("\nTUTTURULAN SAYI:%d\n",saToTutmaSayisi);
    else
        printf("\nTUTTURULAN SAYI:%d+%d",saToTutmaSayisi,saToTutmaSayisi1);
    if(saToTutmaSayisi==1 && saToTutmaSayisi1==1)
    {
        saToOdul=2;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==2 && saToTutmaSayisi1==1)
    {
        saToOdul=4;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==3)
    {
        saToOdul=8;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==3 && saToTutmaSayisi1==1)
    {
        saToOdul=16;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==4)
    {
        saToOdul=32;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==4 && saToTutmaSayisi1==1)
    {
        saToOdul=64;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==5)
    {
        saToOdul=128;
        saToToplamOdul+=saToOdul;
    }
    else if(saToTutmaSayisi==5 && saToTutmaSayisi1==1)
    {
        saToOdul=256;
        saToToplamOdul+=saToOdul;
    }
    else
    {
        saToOdul=0;
        saToToplamOdul+=saToOdul;
    }
    saToTutmaSayisi=0;
    printf("\nKAZANILAN ODUL=%d\n",saToOdul);
    printf("TEKRAR SUPER LOTO OYNAMAK ICIN 'e/E' , CIKIS YAPMAK ICIN LUTFEN 'h/H' BASINIZ:");
    secim3=getch();
    for(;;)
    {
        switch(secim3)
        {
        case 'e':
        case 'E':
            return SansTopu();
            break;
        case 'h':
        case 'H':
            return SansOyunlari();
            break;
        default:
            printf("\nGECERSIZ GIRIS YAPTINIZ.\tTEKRAR DENEYIN:");
            secim3=getch();
        }
    }

}
void OnNumara()
{
    seed=time(NULL);
    srand(seed);
    for(i = 0 ; i <10 ; i++)
    {

        printf(" '1-80' ARALIGINDA %d. SAYIYI GIRINIZ:",i+1);
        scanf("%d",&onNuOynananSayi[i]);
        if(onNuOynananSayi[i]>=1 && onNuOynananSayi[i]<81)
        {
            for(j=0; j<i; j++)
            {
                if(onNuCikanSayi[j] == onNuOynananSayi[i])
                {
                    break;
                }
            }
            if(i == j )
            {
                onNuCikanSayi[i] = onNuOynananSayi[j];
            }
            if ( i != j)
            {
                printf("[HATA]:AYNI SAYI GIRISI YAPILDI.LUTFEN TEKRAR GIRINIZ\n ");
                i--;
            }
        }
        else
        {
            printf("[HATA]:LUTFEN TEKRAR");
            i--;
        }
    }
    for(i=0; i<22; i++)
    {
        onNuRastgeleSayi=1+rand()%80; // 1-49 ARASINDA RASTGELE SAYI URETILDI.
        onNuCikanSayi[i]=onNuRastgeleSayi; //URETILEN SAYILAR SIRASIYLA DIZIYE ATANDI.
    }
    onNuOyunSayisi++;
    for(i=0; i<10; i++) //OYNANAN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<9; j++)
        {
            if(onNuOynananSayi[j]>onNuOynananSayi[j+1])
            {
                geciciSayi1=onNuOynananSayi[j];
                onNuOynananSayi[j]=onNuOynananSayi[j+1];
                onNuOynananSayi[j+1]=geciciSayi1;
            }
        }
    }
    for(i=0; i<22; i++) //RASTGELE URETILEN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<21; j++)
        {
            if(onNuCikanSayi[j]>onNuCikanSayi[j+1])
            {
                geciciSayi2=onNuCikanSayi[j];
                onNuCikanSayi[j]=onNuCikanSayi[j+1];
                onNuCikanSayi[j+1]=geciciSayi2;
            }
        }
    }
    for(i=0; i<10; i++) //TUTTURMA
    {
        for(j=0; j<22; j++)
        {
            if(onNuOynananSayi[i]==onNuCikanSayi[j])
                onNuTutmaSayisi++;
        }
    }
    onNUToplamTutturma+=onNuTutmaSayisi;

    printf("\tON NUMARA LOTO SONUCLARI\n\n");
    printf("'OYNANAN SAYILAR-->'");
    for(i=0; i<10; i++)
    {
        printf("%d   ",onNuOynananSayi[i]);
    }
    printf("\n\n'CIKAN SAYILAR-->'");
    for(j=0; j<22; j++)
    {
        printf("%d  ",onNuCikanSayi[j]);
    }
    printf("\n");
    printf("TUTTURULAN SAYI=%d\n",onNuTutmaSayisi); // TUTMA SAYISI EKRANA YAZDIRILDI.
    if(onNuTutmaSayisi==0)
    {
        onNuOdul=8;
        onNuToplamOdul+=onNuOdul;
    }
    else if(onNuTutmaSayisi==6)
    {
        onNuOdul=16;
        onNuToplamOdul+=onNuOdul;
    }

    else if(onNuTutmaSayisi==7)
    {
        onNuOdul=32;
        onNuToplamOdul+=onNuOdul;
    }
    else if(onNuTutmaSayisi==8)
    {
        onNuOdul=64;
        onNuToplamOdul+=onNuOdul;
    }
    else if(onNuTutmaSayisi==9)
    {
        onNuOdul=128;
        onNuToplamOdul+=onNuOdul;
    }
    else if(onNuTutmaSayisi==10)
    {
        onNuOdul=256;
        onNuToplamOdul+=onNuOdul;
    }
    else
    {
        onNuOdul=0;
        onNuToplamOdul+=onNuOdul;
    }

    onNuTutmaSayisi=0;
    printf("KAZANILAN ODUL=%d\n",onNuOdul);
    printf("TEKRAR ON NUMARA OYNAMAK ICIN 'e/E' , CIKIS YAPMAK ICIN LUTFEN 'h/H' BASINIZ:");
    secim3=getch();
    for(;;)
    {
        switch(secim3)
        {
        case 'e':
        case 'E':
            return OnNumara();
            break;
        case 'h':
        case 'H':
            return SansOyunlari();
            break;
        default:
            printf("\nGECERSIZ GIRIS YAPTINIZ.\tTEKRAR DENEYIN:");
            secim3=getch();
        }
    }
}
void SuperLoto()
{
    seed=time(NULL);
    srand(seed);
    for(i = 0 ; i <6 ; i++)
    {

        printf(" '1-54' ARALIGINDA %d. SAYIYI GIRINIZ:",i+1);
        scanf("%d",&suLoOynananSayi[i]);
        if(suLoOynananSayi[i]>=1 && suLoOynananSayi[i]<55)
        {
            for(j=0; j<i; j++)
            {
                if(suLoCikanSayi[j] == suLoOynananSayi[i])
                {
                    break;
                }
            }
            printf("\n%d\t\t\t%d var\n",onNuCikanSayi[i],onNuTekrarEdenSayi);
            onNuTekrarEdenSayi=1;
            if(i == j )
            {
                suLoCikanSayi[i] = suLoOynananSayi[j];
            }
            if ( i != j)
            {
                printf("[HATA]:AYNI SAYI GIRISI YAPILDI.LUTFEN TEKRAR GIRINIZ\n ");
                i--;
            }
        }
        else
        {
            printf("[HATA]:LUTFEN TEKRAR");
            i--;
        }
    }
    for(i=0; i<6; i++)
    {
        suLoRastgeleSayi=1+rand()%54; // 1-49 ARASINDA RASTGELE SAYI URETILDI.
        suLoCikanSayi[i]=suLoRastgeleSayi; //URETILEN SAYILAR SIRASIYLA DIZIYE ATANDI.
    }
    suLoOyunSayisi++;
    for(i=0; i<6; i++) //OYNANAN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<5; j++)
        {
            if(suLoOynananSayi[j]>suLoOynananSayi[j+1])
            {
                geciciSayi1=suLoOynananSayi[j];
                suLoOynananSayi[j]=suLoOynananSayi[j+1];
                suLoOynananSayi[j+1]=geciciSayi1;
            }
        }
    }
    for(i=0; i<6; i++) //RASTGELE URETILEN SAYILAR KUCUKTEN BUYUGE SIRALANDI
    {
        for(j=0; j<5; j++)
        {
            if(suLoCikanSayi[j]>suLoCikanSayi[j+1])
            {
                geciciSayi2=suLoCikanSayi[j];
                suLoCikanSayi[j]=suLoCikanSayi[j+1];
                suLoCikanSayi[j+1]=geciciSayi2;
            }
        }
    }
    for(i=0; i<6; i++) //TUTTURMA
    {
        for(j=0; j<6; j++)
        {
            if(suLoOynananSayi[i]==suLoCikanSayi[j])
                suLoTutmaSayisi++;
        }
    }
    suLoToplamTutturma+=suLoTutmaSayisi;
    printf("\tSUPER LOTO SONUCLARI\n 'OYNANAN SAYILAR'\t'CIKAN SAYILAR'\n");
    for(i=0; i<6; i++)
    {
        printf("\t%d\t\t%d\n",suLoOynananSayi[i],suLoCikanSayi[i]);
    }
    printf("TUTTURULAN SAYI=%d\n",suLoTutmaSayisi); // TUTMA SAYISI EKRANA YAZDIRILDI.
    if(suLoTutmaSayisi==3)
    {
        suLoOdul=32;
        suLoToplamOdul+=suLoOdul;
    }
    else if(suLoTutmaSayisi==4)
    {
        suLoOdul=64;
        suLoToplamOdul+=suLoOdul;
    }

    else if(suLoTutmaSayisi==5)
    {
        suLoOdul=128;
        suLoToplamOdul+=suLoOdul;
    }
    else if(suLoTutmaSayisi==6)
    {
        suLoOdul=256;
        suLoToplamOdul+=suLoOdul;
    }
    else
    {
        suLoOdul=0;
        suLoToplamOdul+=suLoOdul;
    }

    suLoTutmaSayisi=0;
    printf("KAZANILAN ODUL=%d\n",suLoOdul);
    printf("TEKRAR SUPER LOTO OYNAMAK ICIN 'e/E' , CIKIS YAPMAK ICIN LUTFEN 'h/H' BASINIZ:");
    secim3=getch();
    for(;;)
    {
        switch(secim3)
        {
        case 'e':
        case 'E':
            return SuperLoto();
            break;
        case 'h':
        case 'H':
            return SansOyunlari();
            break;
        default:
            printf("\nGECERSIZ GIRIS YAPTINIZ.\tTEKRAR DENEYIN:");
            secim3=getch();
        }
    }

}
int SayisalLotoIstatistikleri()
{

    if(saLoOyunSayisi==0)
        printf("SAYISAL LOTO OYNANMAMISTIR.\n");
    else
    {
        printf("EN COK CIKAN 6 SAYI\t CIKMA SAYISI\n");
        for(i=0; i<6; i++)
        {
            if(saLoCikanSayi[i]!=-1)
            {
                for(j=i+1; j<6; j++)
                {
                    if(saLoCikanSayi[i]==saLoCikanSayi[j])
                    {
                        saLoTekrarEdenSayi++;
                        saLoCikanSayi[j]=-1;
                    }
                }
            }
            printf("\n%d\t\t\t%d cikmistir.\n",saLoCikanSayi[i],saLoTekrarEdenSayi);
            saLoTekrarEdenSayi=1;
        }
    }
    printf("BUTUN OYUNLARDAN KAZANILAN ODUL:%d\n",saLoToplamOdul);
    printf("BUTUN OYUNLARDAN TOPLAM TUTTURMA:%d\n",saLoToplamTutturma);
    return 0;
}
int SansTopuIstatistikleri()
{
    if(saToOyunSayi==0)
        printf("SANS TOPU OYNANMAMISTIR.\n");
    else
    {
        printf("EN COK CIKAN 5+1 SAYI\t CIKMA SAYISI\n");
        for(i=0; i<5; i++)
        {
            if(saToCikanSayi[i]!=-1)
            {
                for(j=i+1; j<5; j++)
                {
                    if(saToCikanSayi[i]==saToCikanSayi[j])
                    {
                        saToTekrarEdenSayi++;
                        saToCikanSayi[j]=-1;
                    }
                }
            }
            printf("\n%d\t\t\t%d cikmistir.",saToCikanSayi[i],saToTekrarEdenSayi);
            saToTekrarEdenSayi=1;
        }
        if(saToCikanSayi1!=-1)
        {
            if(saToCikanSayi1==saToCikanSayi1)
            {
                saToTekrarEdenSayi1++;
            }

        }
        printf("\n%d\t\t\t%d cikmistir.\n",saToCikanSayi1,saToTekrarEdenSayi1);
        saToTekrarEdenSayi1=1;
    }
    printf("BUTUN OYUNLARDAN KAZANILAN ODUL:%d\n",saToToplamOdul);
    printf("BUTUN OYUNLARDAN TOPLAM TUTTURMA:%d\n",saToToplamTutturma);
    return 0;
}
int OnNumaraIstatistikleri()
{
    if(onNuOyunSayisi==0)
        printf("ON NUMARA OYNANMAMISTIR.\n");
    else
    {
        printf("EN COK CIKAN 10 SAYI\t CIKMA SAYISI\n");
        for(i=0; i<22; i++)
        {
            if(onNuCikanSayi[i]!=-1)
            {
                for(j=i+1; j<22; j++)
                {
                    if(onNuCikanSayi[i]==onNuCikanSayi[j])
                    {
                        onNuTekrarEdenSayi++;
                        onNuCikanSayi[j]=-1;

                    }
                }
            }
            printf("\n%d\t\t\t%d cikmistir.\n",onNuCikanSayi[i],onNuTekrarEdenSayi);
            onNuTekrarEdenSayi=1;
        }
    }
    printf("BUTUN OYUNLARDAN KAZANILAN ODUL:%d\n",onNuToplamOdul);
    printf("BUTUN OYUNLARDAN TOPLAM TUTTURMA:%d\n",onNUToplamTutturma);
    return 0;
}
int SuperLotoIstatistikleri()
{
    if(suLoOyunSayisi==0)
        printf("SUPER LOTO OYNANMAMISTIR.\n");
    else
    {
        printf("EN COK CIKAN 6 SAYI\t CIKMA SAYISI\n");
        for(i=0; i<6; i++)
        {
            if(suLoCikanSayi[i]!=-1)
            {
                for(j=i+1; j<6; j++)
                {
                    if(suLoCikanSayi[i]==suLoCikanSayi[j])
                    {
                        suLoTekrarEdenSayi++;
                        suLoCikanSayi[j]=-1;
                    }
                }
            }
            printf("\n%d\t\t\t%d cikmistir.\n",suLoCikanSayi[i],suLoTekrarEdenSayi);
            suLoTekrarEdenSayi=1;
        }
    }
    printf("BUTUN OYUNLARDAN KAZANILAN ODUL:%d\n",suLoToplamOdul);
    printf("BUTUN OYUNLARDAN TOPLAM TUTTURMA:%d\n",suLoToplamTutturma);
    return 0;
}
