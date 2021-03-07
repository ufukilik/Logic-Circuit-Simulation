#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#define MAX 200

typedef struct kapi
{
    char type[5];
    int girisSayisi;
    char giris1;
    char giris2;
    char giris3;
    char cikis;
    int time;

} kp;
kp door[5];

char giris[10];
int deger[10];
char *girisler;
char *cikislar;
int degerSatSay,kapis;
char islem[0];

timesirala()
{
    int i,j,k;
    char z2;
    int z6;
    for(i=0; i<kapis-1; i++)
    {
        for(j=0; j<kapis; j++)
        {
            if(door[j].time>door[j+1].time)
            {
                z6=door[j].time;
                door[j].time=door[j+1].time;
                door[j+1].time=z6;

                z2=door[j].giris1;
                door[j].giris1=door[j+1].giris1;
                door[j+1].giris1=z2;

                z2=door[j].giris2;
                door[j].giris2=door[j+1].giris2;
                door[j+1].giris2=z2;

                z2=door[j].giris3;
                door[j].giris3=door[j+1].giris3;
                door[j+1].giris3=z2;

                z2=door[j].cikis;
                door[j].cikis=door[j+1].cikis;
                door[j+1].cikis=z2;

                for(k=0; k<5; k++)
                {
                    z2=door[j].type[k];
                    door[j].type[k]=door[j+1].type[k];
                    door[j+1].type[k]=z2;
                }
            }
        }
    }

}
int sayac1=1,sayac2=1;
void Hislemi()
{

    int i,j,k,q1,q2,q3,sayi,index,index1,index2,zaman,kacTaneVar=0;

    for(i=0; i<degerSatSay; i++)
    {
        if(giris[i]==islem[0])
        {
            sayi=deger[i];
        }
    }
    if(sayac2==1)
    {
        for(i=0; i<degerSatSay; i++)
        {
            if(door[i].giris1==islem[0] || door[i].giris2==islem[0])
            {
                kacTaneVar++;
            }
        }
    }
    for(i=0; i<kapis; i++)
    {

        if(door[i].giris1==islem[0]||door[i].giris2==islem[0])
        {
            for(j=0; j<degerSatSay; j++)
            {
                if(door[i].giris1==giris[j] && door[i].cikis!=cikislar[0])
                {
                    q1=deger[j];
                    j=index1;
                }
            }
            for(j=0; j<degerSatSay; j++)
            {
                if(door[i].giris2==giris[j] && door[i].cikis!=cikislar[0])
                {
                    q2=deger[j];
                    j=index2;
                }
            }
            for(j=0; j<degerSatSay; j++)
            {
                if(door[i].cikis==giris[j])
                {
                    q3=deger[j];
                    index=j;
                }
            }
            if(strcmp(door[i].type,"OR")==0)
            {
                if(q1+q2==0)
                {
                    deger[index]=0;
                }
                else
                {
                    deger[index]=1;
                }
                for(k=0; k<kapis; k++)
                {
                    if(door[i].cikis==door[k].giris1)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                    if(door[i].cikis==door[k].giris2 )
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                }
            }
            if(strcmp(door[i].type,"NOR")==0)
            {

                if(q1+q2==0)
                {
                    deger[index]=1;
                }
                else
                {
                    deger[index]=0;
                }
                for(k=0; k<kapis; k++)
                {
                    if(door[i].cikis==door[k].giris1)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                    if(door[i].cikis==door[k].giris2)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                }
            }
            if(strcmp(door[i].type,"AND")==0)
            {
                if(q1*q2==0)
                {
                    deger[index]=0;
                }
                else
                {
                    deger[index]=1;
                }
                for(k=0; k<kapis; k++)
                {
                    if(door[i].cikis==door[k].giris1)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                    if(door[i].cikis==door[k].giris2)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                }
            }
            if(strcmp(door[i].type,"NAND")==0)
            {
                if(q1*q2==0)
                {
                    deger[index]=1;
                }
                else
                {
                    deger[index]=0;
                }
                for(k=0; k<kapis; k++)
                {
                    if(door[i].cikis==door[k].giris1)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                    if(door[i].cikis==door[k].giris2)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                }
            }
            if(strcmp(door[i].type,"XOR")==0)
            {
                if(q1+q2==1)
                {
                    deger[index]=1;
                }
                else
                {
                    deger[index]=0;
                }
                for(k=0; k<kapis; k++)
                {
                    if(door[i].cikis==door[k].giris1)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                    if(door[i].cikis==door[k].giris2)
                    {
                        if(kacTaneVar==1)
                        {
                            islem[0]=door[i].cikis;
                            Hislemi();
                            sayac2--;
                        }
                        else
                        {
                            kacTaneVar--;
                            goto L;
                        }
                    }
                }
            }
            if(strcmp(door[i].type,"NOT")==0)
            {
                if(door[i].giris1==islem[0])
                {
                    if(deger[index1]==0)
                    {
                        deger[index1]=1;
                    }
                    else if(deger[index1]==1)
                    {
                        deger[index1]=0;
                    }
                    if(kacTaneVar==1)
                    {
                        islem[0]=door[i].cikis;
                        Hislemi();
                        sayac2--;
                    }
                    else
                    {
                        kacTaneVar--;
                        goto L;
                    }
                }
                if(door[i].giris2==islem[0])
                {
                    if(deger[index2]==0)
                    {
                        deger[index2]=1;
                    }
                    else if(deger[index2]==1)
                    {
                        deger[index2]=0;
                    }
                    if(kacTaneVar==1)
                    {
                        islem[0]=door[i].cikis;
                        Hislemi();
                        sayac2--;
                    }
                    else
                    {
                        kacTaneVar--;
                        goto L;
                    }
                }
            }

        }
L:
        continue;
    }
}

void listele(int degerSatSay)
{
    int i=0;
    for(i=0; i<degerSatSay; i++)
    {
        printf("\n%c \t %d",giris[i],deger[i]);
    }
}

FILE *fs,*fp;
void degertxtOku()
{

    fs=fopen("deger.txt","r");
    if(!fopen("deger.txt","r"))
    {
        printf("dosya acilamadi\n");
    }
    int i=0;

    while( fscanf(fs,"%c %d ",&giris[i],&deger[i])!=EOF)
    {
        i++;
        degerSatSay=i;
    }
    fclose(fs);
}

void devretxtOku()
{
    fp=fopen("devre.txt","r");

    if(!fopen("devre.txt","r"))
    {

        printf("dosya acilamadi");

    }
    char a[MAX];
    int i=0,j=0,k=0,z=0,t=0,syc=1;
    kapis=0;
    char b[MAX][MAX];

    while(!feof(fp))
    {

        fgets(a,"%s",fp);
        strcat(b[i],a);

        i++;
        k=i;
    }
    fclose(fp);
    char *kapp;
    for(i=0; i<k-1; i++)
    {
        kapp=strstr(b[i],".kapi");
        while (kapp != NULL)
        {
            kapis++;
            kapp = strstr(kapp+1, ".kapi");
        }
    }
    girisler=(char*)malloc(syc*sizeof(char));
    for(i=0; i<MAX; i++)
    {
        if(b[0][i]=='\t')
        {
            t=j;
            j=i;
            if(t!=0)
            {
                for(z=t+1; z<j; z++)
                {
                    if(b[0][z]!='.' && b[0][z]!='#')
                    {
                        girisler[syc-1]=b[0][z];
                        syc++;
                        girisler=(char*)realloc(girisler,syc*sizeof(char));
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

    }
    syc=1;
    cikislar=(char*)malloc(syc*sizeof(char));
    for(i=0; i<MAX; i++)
    {

        if(b[1][i]=='\t')
        {
            t=j;
            j=i;
            if(t!=0)
            {
                for(z=t+1; z<j; z++)
                {
                    if(b[1][z]!='.' && b[1][z]!='#')
                    {
                        cikislar[syc-1]=b[1][z];
                        syc++;
                        cikislar=(char*)realloc(cikislar,syc*sizeof(char));
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

    }
    char xx[5];
    char yed1,yed2;
    for(i=2; i<kapis+2; i++)
    {
        sscanf(b[i],"%s %s %d %c %c %c %d",xx,door[i-2].type,&door[i-2].girisSayisi,&door[i-2].cikis,&door[i-2].giris1,&door[i-2].giris2,&door[i-2].time);
        if(door[i-2].girisSayisi==2)
        {
            sscanf(b[i],"%s %s %d %c %c %c %d",xx,door[i-2].type,&door[i-2].girisSayisi,&door[i-2].cikis,&door[i-2].giris1,&door[i-2].giris2,&door[i-2].time);
        }
        if(door[i-2].girisSayisi==3)
        {
            sscanf(b[i],"%s %s %d %c %c %c %c %d",xx,door[i-2].type,&door[i-2].girisSayisi,&door[i-2].cikis,&door[i-2].giris1,&door[i-2].giris2,&door[i-2].giris3,&door[i-2].time);
        }
    }
}

void basla()
{
    int z=0,i=0,ykont=0,ikont=0;
    char girisAl[20];
    char *degisken;
    char *araislem;
    char tut[20];
    while(1)
    {
        printf("\n>");
        gets(girisAl);
        if(girisAl[0]=='Y' || girisAl[0]=='y')
        {
            degisken=strtok(girisAl," ");
            strcpy(tut,degisken);
            while(degisken!=NULL)
            {
                if(strcmp(degisken,"devre.txt")==0)
                {
                    ykont++;
                    logtxtyaz(tut,degisken);
                    devretxtOku();
                }
                degisken=strtok(NULL," ");
            }
        }
        if(girisAl[0]=='I' || girisAl[0]=='i')
        {
            degisken=strtok(girisAl," ");
            strcpy(tut,degisken);
            while(degisken!=NULL)
            {
                if(strcmp(degisken,"deger.txt")==0)
                {
                    ikont++;
                    logtxtyaz(tut,degisken);
                    degertxtOku();
                }
                degisken=strtok(NULL," ");
            }
        }
        if(ykont==1 && ikont==1)
        {
            if(girisAl[0]=='H' || girisAl[0]=='h')
            {
                degisken=strtok(girisAl," ");
                strcpy(tut,degisken);
                while(degisken!=NULL)
                {
                    araislem=degisken;
                    degisken=strtok(NULL," ");
                }
                for(i=0; i<degerSatSay; i++)
                {
                    degisken=strchr(araislem,giris[i]);
                    if(degisken!=NULL)
                        if(deger[i]==0)
                        {
                            deger[i]=1;
                            logtxtyaz(tut,degisken);
                            strcpy(islem,degisken);
                            Hislemi();
                        }
                        else
                        {
                            printf("\nDeger zaten 0");
                        }
                }

            }
            if(girisAl[0]=='L' || girisAl[0]=='l')
            {
                degisken=strtok(girisAl," ");
                strcpy(tut,degisken);
                while(degisken!=NULL)
                {
                    araislem=degisken;
                    degisken=strtok(NULL," ");
                }
                for(i=0; i<degerSatSay; i++)
                {
                    degisken=strchr(araislem,giris[i]);
                    if(degisken!=NULL)
                        if(deger[i]==1)
                        {
                            deger[i]=0;
                            logtxtyaz(tut,degisken);
                            strcpy(islem,degisken);
                            Hislemi();
                        }
                        else
                        {
                            printf("\nDeger zaten 0");
                        }
                }
            }
        }
        if((girisAl[0]=='G' || girisAl[0]=='g') && girisAl[1]=='*')
        {
            strcpy(tut,girisAl);
            listele(degerSatSay);
            logtxtyaz(tut,tut);
        }
        if(girisAl[0]=='G' || girisAl[0]=='g')
        {
            degisken=strtok(girisAl," ");
            strcpy(tut,degisken);
            while(degisken!=NULL)
            {
                araislem=degisken;
                degisken=strtok(NULL," ");
            }
            for(i=0; i<degerSatSay; i++)
            {
                degisken=strchr(araislem,giris[i]);
                if(degisken!=NULL)
                {
                    printf("%c:%d",giris[i],deger[i]);
                    logtxtyaz(tut,araislem);
                }
            }
        }
        if(girisAl[0]=='K' || girisAl[0]=='k')
        {
            degisken=strtok(girisAl," ");
            while(degisken!=NULL)
            {
                if(strcmp(degisken,"komut1.txt")==0)
                {
                    komuttxtOku();
                }
                degisken=strtok(NULL," ");
            }

        }
        if(strcmp(girisAl,"C")==0 || strcmp(girisAl,"c")==0)
        {
            exit(1);
        }
    }
}

void komuttxtOku()
{
    fp=fopen("komut1.txt","r");

    if(!fopen("komut1.txt","r"))
    {
        printf("dosya acilamadi");
    }
    char oku[MAX];
    char okuyedek[MAX][MAX];
    char *parcala,*araislem;
    int i=0,satSay=0,j=0;
    while(fgets(oku,"%s",fp)!=NULL)
    {
        strcat(okuyedek[i],oku);
        i++;
        satSay=i;
    }
    fclose(fp);
    int sy=0;
    for(i=0; i<satSay; i++)
    {
        if(okuyedek[i][0]=='Y' || okuyedek[i][0]=='y')
        {
            printf("\n%s %s",okuyedek[i]);
            parcala=strtok(okuyedek[i],"\t");
            while(parcala!=NULL)
            {
                if(strcmp(parcala,"devre.txt\n")==0)
                {
                    devretxtOku();
                }
                parcala=strtok(NULL,"\t");
            }
        }
        if(okuyedek[i][0]=='I' || okuyedek[i][0]=='i')
        {
            printf("\n%s %s",okuyedek[i]);
            parcala=strtok(okuyedek[i],"\t");
            while(parcala!=NULL)
            {
                if(strcmp(parcala,"deger.txt\n")==0)
                {
                    degertxtOku();
                }
                parcala=strtok(NULL,"\t");
            }
        }
        if(okuyedek[i][0]=='H' || okuyedek[i][0]=='h')
        {
            printf("\n%s %s",okuyedek[i]);
            parcala=strtok(okuyedek[i],"\t");
            while(parcala!=NULL)
            {
                araislem=parcala;
                parcala=strtok(NULL,"\t");
            }
            for(i=0; i<degerSatSay; i++)
            {
                parcala=strchr(araislem,giris[i]);
                if(parcala!=NULL)
                    if(deger[i]==0)
                    {
                        deger[i]=1;
                        strcpy(islem,araislem);
                        Hislemi();
                    }
                    else
                    {
                        printf("\nDeger zaten 0");
                    }
            }
        }
        if(okuyedek[i][0]=='L' || okuyedek[i][0]=='l')
        {
            printf("\n%s %s",okuyedek[i]);
            parcala=strtok(okuyedek[i],"\t");
            while(parcala!=NULL)
            {
                araislem=parcala;
                parcala=strtok(NULL,"\t");
            }
            for(i=0; i<degerSatSay; i++)
            {
                parcala=strchr(araislem,giris[i]);
                if(parcala!=NULL)
                    if(deger[i]==1)
                    {
                        deger[i]=0;
                        strcpy(islem,araislem);
                        Hislemi();
                    }
                    else
                    {
                        printf("\nDeger zaten 0");
                    }
            }
        }
        if(okuyedek[i][0]=='G' || okuyedek[i][0]=='g')
        {

            printf("\n%s %s",okuyedek[i]);
            parcala=strtok(okuyedek[i],"\t");
            while(parcala!=NULL)
            {
                araislem=parcala;
                parcala=strtok(NULL,"\t");
            }
            for(i=0; i<degerSatSay; i++)
            {
                parcala=strchr(araislem,giris[i]);
                if(parcala!=NULL)
                    printf("%c:%d",giris[i],deger[i]);
            }
        }
        if(okuyedek[i][0]=='C' || okuyedek[i][0]=='c')
        {
            exit(1);
        }
    }
}

void logtxtyaz(char komut[20],char neyi[20])
{
    int i=0;
    struct timeval tv;
    struct timezone tz;
    struct tm *zaman;
    gettimeofday(&tv,&tz);
    zaman=localtime(&tv.tv_sec);
    fs=fopen("log.txt","a");
    if(!fopen("log.txt","a"))
    {
        printf("Dosya acilamadi");
    }
    if((komut[0]=='Y' || komut[0]=='y') && strcmp(neyi,"devre.txt")==0)
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %s %-15s %s yuklendi.\n",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut,neyi,neyi);
    }
    if((komut[0]=='I' || komut[0]=='i') && strcmp(neyi,"deger.txt")==0)
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %s %-15s deger atandi.\n",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut,neyi,neyi);
    }
    if(komut[0]=='H' || komut[0]=='h')
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %s %-15s %s girisi belirlendi.\n",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut,neyi,neyi);
    }
    if(komut[0]=='L' || komut[0]=='l')
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %s %-15s %s girisi belirlendi.\n",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut,neyi,neyi);
    }
    if((komut[0]=='G' || komut[0]=='g') && komut[1]=='*')
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %-15s ",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut);
        for(i=0; i<degerSatSay; i++)
        {
            fprintf(fs,"%c: %d\t",giris[i],deger[i]);
        }
        fprintf(fs,"\n");
    }
    if(komut[0]=='G' || komut[0]=='g')
    {
        fprintf(fs,"%ld/%ld/%ld-%ld:%ld:%-5ld %s %-15s ",zaman->tm_year+1900,zaman->tm_mon,zaman->tm_mday,zaman->tm_hour,zaman->tm_min,zaman->tm_sec,komut,neyi);
        for(i=0; i<degerSatSay; i++)
        {
            if(giris[i]==neyi[0])
            {
                fprintf(fs,"%c: %d\t",giris[i],deger[i]);
            }
        }
        fprintf(fs,"\n");
    }
    fclose(fs);
}

int main()
{
    timesirala();
    basla();
    return 0;
}
