#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>    

//  isdigit fonksiyonu	Karakterin sayı olup olmadığını sınar kontrol şeklinde FONKSİYON oluşturma nedenimiz bu.


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
 /* kullanıcıdan aldığım bilgileri önceden Pointerlar sayesinde bellekte ayırmış olduğım alanda tuttum ve daha sonra dosyaya yazdırdım. */
	char *p,*c;                 
	float *asb;
	p=(char*)malloc((sizeof(char)*20)*4);
	c=(char*)malloc((sizeof(char)*20)*3);
	asb=(float*)calloc(sizeof(float),3);
	
			printf("\n\n\nÖğrencinin Fakültesi :  ");
			scanf("%s",p);
			printf("\nÖğrencinin Okuduğu Bölüm :  ");
			scanf("%s",p+20);	
			printf("\nÖğrencinin Adını Giriniz :  ");
			scanf("%s",p+40);
			printf("\nÖğrencinin Soy Adını Giriniz :  ");
			scanf("%s",p+60);
			
			
			printf("\nÖğrencinin Numarasını Giriniz :  ");
			
			scanf("%s",c);while(kontrol(c)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c);}
			
			printf("\nÖğrencinin T.C Kimlik Numarasını Giriniz :  ");
			
			scanf("%s",c+20);while(kontrol(c+20)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+20);}
			
			printf("\nÖğrecinin Okumakta Olduğu Sınıf (1-2-3-4) :  ");
			
			scanf("%s",c+40); while(kontrol(c+40)==0) {printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+40);}                        	

	*asb=atof(c);
	*(asb+1)=atof(c+20);
	*(asb+2)=atof(c+40);
	
		FILE *fp;

	if((fp=fopen("OgrenciKayit.txt","a"))!=0)
	{
	
	/*Uygulamada ilk süslü parantezlerde klavyeden bir yazı enter tuşuna basıldıktan sonra strupr fonksiyonu ile büyük harf yapılır.  */
	printf("\n\t%s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
    fprintf(fp,"\t%s\t%s\t%s\t%s\t%.0f\t%.0f\t%.0f\t\n",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
	fflush(fp);fclose(fp);
	/*fflush normalde herhangi bir dosya işlemi sırasında klavyeden alınarak tampona yüklenmiş girdileri kendisine parametre olarak 
	verilen FILE* türünden işaretçi ile ilişkili olan dosyaya yazar ve klavyeden alınmış bilgileri tampondan siler. */
	sleep(1.2);
	printf("\n\n\n\t Öğrenci Başarıyla Eklendi :)) )");
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
	 	printf("\n\nÖğrencinin Bilgilerini Silmek İstiyorsanız\n");
        printf("Öğrencinin T.C Kimlik Numarasını Giriniz :  ");
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
   if (fp == NULL) printf("Kayıt Yeri Bulunamamıştır :(  )\n");
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
	int secim; //menü seçimleri için kullanılan değişken  *******  normalde char olarak tanımladım fakat  harf veri girişinden sonra sürekli aynı değeri döndürdü o yüzden integer'a çeviriyorum hocam
do{
	printf("\n\n\n\n\n\t\t\t\t\t***** ÖĞRENCİ İŞLEMLERİ ***** ");
	sleep(1.2);
	system("cls");
	printf("Öğrenci Kayıt Sistemine Hoşgeldiniz\n");
	for(int i = 0; i < 35; i++){printf("-");}
	
		
	printf("\nLütfen Yapmak İstediğiniz İşlemi Seçiniz\n");
	printf("\nÖğrenci Kayıt : 1");
	printf("\nÖğrenci Kayıt Silme : 2");
	printf("\nÖğrenci Kayıt İşlem Listesi : 3");
	printf("\nÇıkış İşlemi İçin : 0\n");
	printf("\nLütfen Seçiminiz Yapınız:");
	scanf("%d",&secim);

if(secim == 1) //öğrenci kayıt seçimi kod satırları
	   {
	   		int x;
	   		system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t***** ÖĞRENCİ KAYIT ***** ");
			sleep(1.2);
			system("cls");
			for(int i = 0; i < 35; i++){printf("-");}
			printf("\n\n\n\t\tKayıt İşleminin Düzgün Bir Şekilde Gerçekleşebilmesi İçin \n\t\tLütfen Türkçe Karakterler Kullanmayınız  \n\t\t(***(Ö ö -- Ç ç -- İ ı -- Ü ü -- Ğ ğ -- Ş ş)***)\n\n\n");
		
			ogrenciekle(x);
			printf("\n\n\n\n::KAYIT İŞLEMİ YAPILMIŞTIR::\n\nANA MENÜYE GERİ DÖNÜLÜYOR...");
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
	printf("\tFAKÜLTE _ BÖLÜM _ AD _ SOYAD _ ÖĞRENCİ NO _ TC NO _ SINIF NO\n\n\n");
	ogrencilistele();
	sleep(5);
	system("cls");
			}

if ((secim != 1) && (secim != 2) && (secim != 3) && (secim != 0)) { // sistemin tercihleri dışındaki girişleri tespit için kod satırı sadece (( İNTEGER DEĞERLER İÇİN ))
			system("cls");
			printf(" HATALI SEÇİM\n ");
			system("pause");
			system("cls");
		}
	} while (secim != 0);
	system("cls");
	
	printf(" PROGRAMDAN ÇIKILMIŞTIR. \n ");
	system("pause");
	return 0;

}




