#include <stdio.h>
#include <stdlib.h>
#include "chaines.h"


main()
{
 TCHAINE chaine1,chaine2;
 int n,choix;


do
{
choix=menu();
switch (choix) {
case 1 : printf("\n\t\t\tEntrer une chaine de caracteres (1) : ");
	   fflush(stdin);
 	   gets(chaine1);
	   printf("\n\t\t\t La longueur de  '%s' est : %d \n\n", chaine1,StringLenght(chaine1));
	   printf("\n\t\t\tEntrer une chaine de caracteres (2) : ");
	   fflush(stdin);
 	   gets(chaine2);
	   printf("\n\t\t\t La longueur de  '%s' est : %d \n\n", chaine2,StringLenght(chaine2));
	   break;
case 2 : printf("\n\t\t\tEntrer une chaine de caracteres : ");
 	   gets(chaine1);
	   StringCopy(chaine2,chaine1);
	   printf("\n\t\t\t La chaine2 est  '%s' \n\n", chaine2);
	   break;
case 3 : printf("\n\nCombien de caractÃšres de la chaine source souhaitez vous copier ?\n");
	   scanf("%d",&n);
	   if(n<=StringLenght(chaine2)) {
	   StringNCopy(chaine1,chaine2,n);
	   printf("\n\t\t\tLa nouvelle chaine 1 est '%s'.\n",chaine1);
	   }
	   else {printf("\n\nN'oubliez pas que la chaÃ®ne source contient %d caractÃšres.\n\n",StringLenght(chaine2));}
	 break;
	 
case 4 : printf("\n\nLa chaine 1 va Ãªtre modifiÃ©e.\n\n");
	 StringConcat(chaine1,chaine2);
	 printf("\n\nChaine 1 : %s\n\n",chaine1);
	 break;
case 5 : printf("\n\nLa chaine 2 va Ãªtre modifiÃ©e. Combien de caractÃšres de chaine 1 souhaitez-vous ajouter ?\n\n");
	 scanf("%d",&n);
	 if(n<=StringLenght(chaine2)) {
	    StringNConcat(chaine2,chaine1,n);
	    printf("\n\nChaine 2 : %s\n\n",chaine2);
	    }
	   else {printf("\n\nN'oubliez pas que la chaÃ®ne source contient %d caractÃšres.\n\n",StringLenght(chaine1));
	   }
	 break;
case 6 : if(StringCompare(chaine1,chaine2)>0) printf("\n\nchaine1 est supÃ©rieure Ã  chaine2.\n\n");
	 else if(StringCompare(chaine1,chaine2)<0) printf("\n\nchaine1 est infÃ©rieure Ã  chaine2.\n\n");
	 else printf("\n\nchaine1 est Ã©gale Ã  chaine2.\n\n");
	 break;	
case 9 : // Option pour quitter
	 break;	
default : printf("\n\n Cas imprevu !!! \n\n");
	}
}
while (choix!=9);
}
	 
