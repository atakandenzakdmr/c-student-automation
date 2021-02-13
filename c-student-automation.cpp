#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <locale.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>    

//  isdigit fonksiyonu	Karakterin say� olup olmad���n� s�nar kontrol �eklinde FONKS�YON olu�turma nedenimiz bu.


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
 /* kullan�c�dan ald���m bilgileri �nceden Pointerlar sayesinde bellekte ay�rm�� oldu��m alanda tuttum ve daha sonra dosyaya yazd�rd�m. */
	char *p,*c;                 
	float *asb;
	p=(char*)malloc((sizeof(char)*20)*4);
	c=(char*)malloc((sizeof(char)*20)*3);
	asb=(float*)calloc(sizeof(float),3);
	
			printf("\n\n\n��rencinin Fak�ltesi :  ");
			scanf("%s",p);
			printf("\n��rencinin Okudu�u B�l�m :  ");
			scanf("%s",p+20);	
			printf("\n��rencinin Ad�n� Giriniz :  ");
			scanf("%s",p+40);
			printf("\n��rencinin Soy Ad�n� Giriniz :  ");
			scanf("%s",p+60);
			
			
			printf("\n��rencinin Numaras�n� Giriniz :  ");
			
			scanf("%s",c);while(kontrol(c)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c);}
			
			printf("\n��rencinin T.C Kimlik Numaras�n� Giriniz :  ");
			
			scanf("%s",c+20);while(kontrol(c+20)==0){printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+20);}
			
			printf("\n��recinin Okumakta Oldu�u S�n�f (1-2-3-4) :  ");
			
			scanf("%s",c+40); while(kontrol(c+40)==0) {printf("\t* Lutfen Gecerli Deger Giriniz :"); scanf("%s",c+40);}                        	

	*asb=atof(c);
	*(asb+1)=atof(c+20);
	*(asb+2)=atof(c+40);
	
		FILE *fp;

	if((fp=fopen("OgrenciKayit.txt","a"))!=0)
	{
	
	/*Uygulamada ilk s�sl� parantezlerde klavyeden bir yaz� enter tu�una bas�ld�ktan sonra strupr fonksiyonu ile b�y�k harf yap�l�r.  */
	printf("\n\t%s\t%s\t%s\t%s\t%.f\t%.f\t%.f\t",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
    fprintf(fp,"\t%s\t%s\t%s\t%s\t%.0f\t%.0f\t%.0f\t\n",strupr(p),strupr(p+20),strupr(p+40),strupr(p+60),*(asb),*(asb+1),*(asb+2));
	fflush(fp);fclose(fp);
	/*fflush normalde herhangi bir dosya i�lemi s�ras�nda klavyeden al�narak tampona y�klenmi� girdileri kendisine parametre olarak 
	verilen FILE* t�r�nden i�aret�i ile ili�kili olan dosyaya yazar ve klavyeden al�nm�� bilgileri tampondan siler. */
	sleep(1.2);
	printf("\n\n\n\t ��renci Ba�ar�yla Eklendi :)) )");
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
	 	printf("\n\n��rencinin Bilgilerini Silmek �stiyorsan�z\n");
        printf("��rencinin T.C Kimlik Numaras�n� Giriniz :  ");
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
   if (fp == NULL) printf("Kay�t Yeri Bulunamam��t�r :(  )\n");
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
	int secim; //men� se�imleri i�in kullan�lan de�i�ken  *******  normalde char olarak tan�mlad�m fakat  harf veri giri�inden sonra s�rekli ayn� de�eri d�nd�rd� o y�zden integer'a �eviriyorum hocam
do{
	printf("\n\n\n\n\n\t\t\t\t\t***** ��RENC� ��LEMLER� ***** ");
	sleep(1.2);
	system("cls");
	printf("��renci Kay�t Sistemine Ho�geldiniz\n");
	for(int i = 0; i < 35; i++){printf("-");}
	
		
	printf("\nL�tfen Yapmak �stedi�iniz ��lemi Se�iniz\n");
	printf("\n��renci Kay�t : 1");
	printf("\n��renci Kay�t Silme : 2 (((hocam baz� hatalar olu�tu yollamadan �nce kontrol ederken 2. se�enekte)))");
	printf("\n��renci Kay�t ��lem Listesi : 3");
	printf("\n��k�� ��lemi ��in : 0\n");
	printf("\nL�tfen Se�iminiz Yap�n�z:");
	scanf("%d",&secim);

if(secim == 1) //��renci kay�t se�imi kod sat�rlar�
	   {
	   		int x;
	   		system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t***** ��RENC� KAYIT ***** ");
			sleep(1.2);
			system("cls");
			for(int i = 0; i < 35; i++){printf("-");}
			printf("\n\n\n\t\tKay�t ��leminin D�zg�n Bir �ekilde Ger�ekle�ebilmesi ��in \n\t\tL�tfen T�rk�e Karakterler Kullanmay�n�z  \n\t\t(***(� � -- � � -- � � -- � � -- � � -- � �)***)\n\n\n");
		
			ogrenciekle(x);
			printf("\n\n\n\n::KAYIT ��LEM� YAPILMI�TIR::\n\nANA MEN�YE GER� D�N�L�YOR...");
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
	printf("\tFAK�LTE _ B�L�M _ AD _ SOYAD _ ��RENC� NO _ TC NO _ SINIF NO\n\n\n");
	ogrencilistele();
	sleep(5);
	system("cls");
			}

if ((secim != 1) && (secim != 2) && (secim != 3) && (secim != 0)) { // sistemin tercihleri d���ndaki giri�leri tespit i�in kod sat�r� sadece (( �NTEGER DE�ERLER ���N ))
			system("cls");
			printf(" HATALI SE��M\n ");
			system("pause");
			system("cls");
		}
	} while (secim != 0);
	system("cls");
	
	printf(" PROGRAMDAN �IKILMI�TIR. \n ");
	system("pause");
	return 0;

}




