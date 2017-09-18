#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *dt,*di;

   char aranan[10];
   char kelime[10];
   char c,s;
   int i=1,o;
   int sonuc;

   printf("Ingilizce-Turkce Sozluge Hos Geldiniz..\n\n");

   tekrar:

   printf("\nGirilecek kelime hangi dilde? (Turkce)t/(Ingilizce)i?  ");
   scanf(" %c",&c);

   if(c=='t'||c=='T')
   {
       dt=fopen("turkce.txt","r");
       if(dt==NULL)
       {
           printf("\nturkce.txt dosyasi acilamadi !!!\n\n");
       }
       else
       {
           printf("\n\nAranan Turkce kelimeyi giriniz : ");
           scanf(" %s",&aranan);
           do{

               o=fscanf(dt," %s",&kelime);

               sonuc=strcmp(kelime,aranan);

               if(sonuc==0)
               {
                    printf("\nAradiginiz kelime %s ve metin belgesinde %d. satirdadir.\n",aranan,i);
                    goto iyidir;
               }


                  i++;


           }while(o!=EOF);

           printf("\nAradiginiz kelime sozlukte bulunmamaktadir..\n\n");

           iyidir:
           i=1;

           tekrar1:

           printf("\nTekrar arama yapmak ister misiniz? Evet(E)/Hayir(H) : ");

           scanf(" %c",&s);

           if(s=='E'||s=='e')
           {
               goto tekrar;
           }
           else if(s=='h'||s=='H')
           {
               printf("\nProgram basarili bir sekilde sonlandi..\n\n");
           }
           else
           {
               printf("\nE yada H'den farkli bir harf girdiniz..\n\n");
               goto tekrar1;
           }

       }
       fclose(dt);

   }

   else if(c=='ý'||c=='i'||c=='I'||c=='Ý')
   {

       di=fopen("ingilizce.txt","r");
       if(di==NULL)
       {
           printf("\ningilizce.txt dosyasi acilamadi !!!");
       }
       else
       {
           printf("\n\nAranan Ingilizce kelimeyi giriniz : ");
           scanf(" %s",&aranan);
           do{

               o=fscanf(di," %s",&kelime);

               sonuc=strcmp(kelime,aranan);

               if(sonuc==0)
               {
                    printf("\nAradiginiz kelime %s ve metin belgesinde %d. satirdadir.\n",aranan,i);
                    goto iyidir1;
               }


                  i++;


           }while(o!=EOF);

           printf("\nAradiginiz kelime sozlukte bulunmamaktadir..\n\n");

           iyidir1:
           i=1;

           tekrar2:

           printf("\nTekrar arama yapmak ister misiniz? Evet(E)/Hayir(H) : ");

           scanf(" %c",&s);

           if(s=='E'||s=='e')
           {
               goto tekrar;
           }
           else if(s=='h'||s=='H')
           {
               printf("\nProgram basarili bir sekilde sonlandi..\n\n");
           }
           else
           {
               printf("\nE yada H'den farkli bir harf girdiniz..\n\n");
               goto tekrar2;
           }

       }
       fclose(di);


   }

   else
   {
       printf("\nT veya I haflerinden farkli karakter girdiniz!\n");
       goto tekrar;
   }



 return 0;
}
