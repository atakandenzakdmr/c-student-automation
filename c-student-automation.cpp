#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>    

//  isdigit fonksiyonu	Karakterin sayý olup olmadýðýný sýnar kontrol þeklinde FONKSÝYON oluþturma nedenimiz bu.


using namespace std;

int kontrol(char *b)
{

	int u,i=0,sonuc=1;
	char *b1;
	b1=b;
	u=strlen(b);
	while(i<u)
	{
	 if(isdigit(*b)==0)
	{
	sonuc=0;
	break;
	}
	i++;
	b++;
	}
	
}



void ogrenciekle(int a)
{
	a = 1;
	
	int i=0,u;                
 /* kullanýcýdan aldýðým bilgileri önceden Pointerlar sayesinde bellekte ayýrmýþ olduðým alanda tuttum ve daha sonra dosyaya yazdýrdým. */
	char *p,*c;                 
	float *asb;
	p=(char*)malloc((sizeof(char)*20)*4);
	c=(char*)malloc((sizeof(char)*20)*3);
	asb=(float*)calloc(sizeof(float),3);
	
			printf("\n\n\nÖðrencinin Fakültesi :  ");
			scanf("%s",p);
			printf("\nÖðrencinin Okuduðu Bölüm :  ");
			scanf("%s",p+20);	
			printf("\nÖðrencinin Adýný Giriniz :  ");
			scanf("%s",p+40);
			printf("\nÖðrencinin Soy Adýný Giriniz :  ");
			scanf("%s",p+60);
			
			
			printf("\nÖðrencinin Numarasýný Giriniz :  ");
			
			scanf("%s",c);while(kontrol(c)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c);}
			
			printf("\nÖðrencinin T.C Kimlik Numarasýný Giriniz :  ");
			
			scanf("%s",c+20);while(kontrol(c+20)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+20);}
			
			printf("\nÖðrecinin Okumakta Olduðu Sýnýf (1-2-3-4) :  ");
			
			scanf("%s",c+40); while(kontrol(c+40)==0) {printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+40);}                        	

	*asb=atof(c);
	*(asb+1)=atof(c+20);
	*(asb+2)=atof(c+40);
	
		FILE *fp;

	if((fp=fopen("OgrenciKayit.txt","a"))!=0)
	{
	
	/*Uygulamada ilk süslü parantezlerde klavyeden bir yazý enter tuþuna basýldýktan sonra strupr fonksiyonu ile büyük harf yapýlýr.  */
	printf("\n\t%s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
    fprintf(fp,"\t%s\t%s\t%s\t%s\t%.0f\t%.0f\t%.0f\t\n",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
	fflush(fp);fclose(fp);
	/*fflush normalde herhangi bir dosya iþlemi sýrasýnda klavyeden alýnarak tampona yüklenmiþ girdileri kendisine parametre olarak 
	verilen FILE* türünden iþaretçi ile iliþkili olan dosyaya yazar ve klavyeden alýnmýþ bilgileri tampondan siler. */
	sleep(1.2);
	printf("\n\n\n\t Öðrenci Baþarýyla Eklendi :)) )");
	system("cls");
	  
	}
	else printf("Dosya Bulunamadi.");
	free(p);
	free(c);
	free(asb);
}

void ogrencisil() 
{		
	/*	int silinen;
		char sil[10];
	 	printf("\n\nÖðrencinin Bilgilerini Silmek Ýstiyorsanýz\n");
        printf("Öðrencinin T.C Kimlik Numarasýný Giriniz :  ");
        scanf("%s",&sil);
        printf("\t***  Silinecek Arac Numarasi  :  ");scanf("%s",sil);while(kontrol(sil)==0 || atoi(sil)<0 ||atoi(sil)>a)
		{
		printf("Lutfen Gecerli Bir Arac Numarasi Giriniz  :"); scanf("%s",sil);

		}silinen=atoi(sil); */
        
}

void ogrencilistele()
{  
      FILE *fp;
   		int c;
  	 	fp = fopen("OgrenciKayit.txt","r");
   if (fp == NULL) printf("Kayýt Yeri Bulunamamýþtýr :(  )\n");
   else {
     do {
       c = getc(fp);    /* Bir karakter oku  */
       putchar(c);         /* ekranda goster    */
     } while (c != EOF);    /* Dosya sonuna (END OF FILE) a kadar devam */
   }
   fclose(fp);
}
	
int main() {
	
	setlocale(LC_ALL, "Turkish");
	system("color 0C");
	int secim; //menü seçimleri için kullanýlan deðiþken  *******  normalde char olarak tanýmladým fakat  harf veri giriþinden sonra sürekli ayný deðeri döndürdü o yüzden integer'a çeviriyorum hocam
do{
	printf("\n\n\n\n\n\t\t\t\t\t***** ÖÐRENCÝ ÝÞLEMLERÝ ***** ");
	sleep(1.2);
	system("cls");
	printf("Öðrenci Kayýt Sistemine Hoþgeldiniz\n");
	for(int i = 0; i < 35; i++){printf("-");}
	
		
	printf("\nLütfen Yapmak Ýstediðiniz Ýþlemi Seçiniz\n");
	printf("\nÖðrenci Kayýt : 1");
	printf("\nÖðrenci Kayýt Silme : 2 (((hocam bazý hatalar oluþtu yollamadan önce kontrol ederken 2. seçenekte)))");
	printf("\nÖðrenci Kayýt Ýþlem Listesi : 3");
	printf("\nÇýkýþ Ýþlemi Ýçin : 0\n");
	printf("\nLütfen Seçiminiz Yapýnýz:");
	scanf("%d",&secim);

if(secim == 1) //öðrenci kayýt seçimi kod satýrlarý
	   {
	   		int x;
	   		system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t***** ÖÐRENCÝ KAYIT ***** ");
			sleep(1.2);
			system("cls");
			for(int i = 0; i < 35; i++){printf("-");}
			printf("\n\n\n\t\tKayýt Ýþleminin Düzgün Bir Þekilde Gerçekleþebilmesi Ýçin \n\t\tLütfen Türkçe Karakterler Kullanmayýnýz  \n\t\t(***(Ö ö -- Ç ç -- Ý ý -- Ü ü -- Ð ð -- Þ þ)***)\n\n\n");
		
			ogrenciekle(x);
			printf("\n\n\n\n::KAYIT ÝÞLEMÝ YAPILMIÞTIR::\n\nANA MENÜYE GERÝ DÖNÜLÜYOR...");
			sleep(3);		
			system("cls");
			
			
		}

if(secim == 2){
               
            
               	system("cls");
               	for(int i = 0; i < 35; i++){printf("-");}           	
              	ogrencisil();
              	sleep(5);
              	system("cls");
							   

			}
			
if(secim == 3){
	
	system("Cls");
	printf("\tFAKÜLTE _ BÖLÜM _ AD _ SOYAD _ ÖÐRENCÝ NO _ TC NO _ SINIF NO\n\n\n");
	ogrencilistele();
	sleep(5);
	system("cls");
			}

if ((secim != 1) && (secim != 2) && (secim != 3) && (secim != 0)) { // sistemin tercihleri dýþýndaki giriþleri tespit için kod satýrý sadece (( ÝNTEGER DEÐERLER ÝÇÝN ))
			system("cls");
			printf(" HATALI SEÇÝM\n ");
			system("pause");
			system("cls");
		}
	} while (secim != 0);
	system("cls");
	
	printf(" PROGRAMDAN ÇIKILMIÞTIR. \n ");
	system("pause");
	return 0;

}




