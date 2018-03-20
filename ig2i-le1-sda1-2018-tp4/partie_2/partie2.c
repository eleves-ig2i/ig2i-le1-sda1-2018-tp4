/***************************************************************/
/* TP n°4 : Chaines de caracteres			       */
/* Nom : SALEZ Nathan					       */
/* Date : 20/11/2017					       */			   
/* Version : 1.0					       */		   
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>


#define  MAX	80

typedef char TCHAINE[MAX];		// TCHAINE = chaîne de (au plus) MAX caractères 


//Prototypes des fonctions



int StringLenght(const char *);
char *StringCopy(char*, const char*);
char *StringNCopy(char*, const char*, int);
char* StringConcat(char*, const char*);
char* StringNConcat(char*, const char*, int);
int StringCompare(const char*, const char*);

int menu();

main()
{
 TCHAINE chaine1,chaine2;
 int n,choix;

//On suppose que la taille des chaînes de caractères ne sera jamais supérieur à MAX.
do
{
choix=menu();
switch (choix) {
case 1 : printf("\n\t\t\tEntrer une chaine de caracteres (1) : ");
	   fflush(stdin);		// Le buffer est vidé (sécurité)
 	   gets(chaine1);		// Fonction dangereuse car ne contrôle pas le nombre d'éléments.
	   printf("\n\t\t\t La longueur de  '%s' est : %d \n\n", chaine1,StringLenght(chaine1));
	   printf("\n\t\t\tEntrer une chaine de caracteres (2) : ");
	   fflush(stdin);
 	   gets(chaine2);
	   printf("\n\t\t\t La longueur de  '%s' est : %d \n\n", chaine2,StringLenght(chaine2));
	   break;
case 2 : printf("\n\t\t\tEntrer une chaine de caracteres : ");
 	   gets(chaine1);
	   StringCopy(chaine2,chaine1);		//La chaîne 2 est modifiée.
	   printf("\n\t\t\t La chaine2 est  '%s' \n\n", chaine2);
	   break;
case 3 : printf("\n\nCombien de caractères de la chaine source souhaitez vous copier ?\n");
	   scanf("%d",&n);
	   if((n<=StringLenght(chaine2))&&(n>0)) {	//On vérifie si le nombre n d'octets est correct.
	   StringNCopy(chaine1,chaine2,n);	//La chaîne 1 est modifiée dans ce cas.
	   printf("\n\t\t\tLa nouvelle chaine 1 est '%s'.\n",chaine1);
	   }
	   else {printf("\n\nN'oubliez pas que la chaîne source contient %d caractères.\n\n",StringLenght(chaine2));}
	 break;
	 
case 4 : printf("\n\nLa chaine 1 va être modifiée.\n\n");
	 StringConcat(chaine1,chaine2);		//La chaîne 1 est modifiée.
	 printf("\n\nChaine 1 : %s\n\n",chaine1);
	 break;
case 5 : printf("\n\nLa chaine 2 va être modifiée. Combien de caractères de chaine 1 souhaitez-vous ajouter ?\n\n");
	 scanf("%d",&n);
	 if((n<=StringLenght(chaine2))&&(n>0)) {	//Cf ligne 55
	    StringNConcat(chaine2,chaine1,n);	//La chaîne 2 est modifiée.
	    printf("\n\nChaine 2 : %s\n\n",chaine2);
	    }
	   else {printf("\n\nN'oubliez pas que la chaîne source contient %d caractères.\n\n",StringLenght(chaine1));
	   }
	 break;
case 6 : if(StringCompare(chaine1,chaine2)>0) printf("\n\nchaine1 est supérieure à chaine2.\n\n");
	 else if(StringCompare(chaine1,chaine2)<0) printf("\n\nchaine1 est inférieure à chaine2.\n\n");
	 else printf("\n\nchaine1 est égale à chaine2.\n\n");
	 printf("\n\nStringCompare=%d\n\n",StringCompare(chaine1,chaine2));
	 break;	
case 9 : // Option pour quitter
	 break;	
default : printf("\n\n Cas imprevu !!! \n\n");
	}
}
while (choix!=9);
	 
  

	   


 return 1;
}



int menu()
{
  int choix;
  printf("\n\t\t\t\t 1 - Longueur d'une chaine ");  
  printf("\n\t\t\t\t 2 - Copie d'une chaine ");
  printf("\n\t\t\t\t 3 - Copie de N caracteres de la chaine 2 sur chaine 1 ");
  printf("\n\t\t\t\t 4 - Concatenation de deux chaines ");
  printf("\n\t\t\t\t 5 - Concatenation d'une chaine destination et des N caracteres de la chaine source ");
  printf("\n\t\t\t\t 6 - Comparaison de deux chaines");
  printf("\n\t\t\t\t 9 - Quitter");
 printf("\n\n\t\t\t\t Votre choix : "); 
 scanf("%d",&choix);
 getchar(); // vide le RC du buffer
 return choix;
}


/***********************************************************************************************/
/*Nom de la fonction : StringCopy							       */
/*Description : copie la chaîne source sur la chaîne dest, si cette dernière est assez grande. */
/*Retourne : le pointeur de la chaîne dest.						       */ 
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest			       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/
char* StringCopy(char* dest, const char* src)
{
int i=0;
while (dest[i]=src[i]) i++;	//Tant que l'on peut faire "dest[i]=src[i];", on incrémente i.
return dest;
}

/***********************************************************************************************/
/*Nom de la fonction : StringLenght							       */
/*Description : mesure la taille n de la chaîne de caractères.				       */ 
/*Retourne : la taille de la chaîne de caractères					       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : la chaîne de caractères T					       */
/*Paramètres en sortie : la taille n							       */
/***********************************************************************************************/
int StringLenght(const char *ch)
{int n=0;
while(ch[n]!='\0') n++;
return n;
}



/***********************************************************************************************/
/*Nom de la fonction : StringNCopy							       */ 
/*Description : copie n octets de la chaine source sur la chaine dest. Attention, il faut que  */
/*		qu'il y ait le caractère nul dans ces n octets.				       */
/*Retourne : le pointeur de la chaîne dest						       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest, et la taille de la chaine   */
/*			 source.							       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/
char* StringNCopy(char* dest, const char* src, int n)
{int i=0;
while(i!=n && src[i]!='\0') {
dest[i]=src[i];
i++;
}
if(dest[i]!='\0') dest[i]='\0';		//On fait attention à la fin de chaîne.

return dest;
}

/***********************************************************************************************/
/*Nom de la fonction : StringConcat							       */
/*Description : concatène la chaîne source sur la chaîne dest, si cette dernière est assez     */
/*		grande.									       */
/*Retourne : le pointeur de la chaîne dest.						       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest			       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/
char* StringConcat(char* dest, const char * src)
{int i=0,a=0;
while(dest[i]!='\0') i++;	//On cherche la taille de dest
while(src[a]!='\0') {		
	dest[i]=src[a];
	a++;
	i++;
}
dest[i]='\0';				//On fait attention à la fin de chaîne.
return dest;
}

/***********************************************************************************************/
/*Nom de la fonction : StringNConcat							       */
/*Description : ajoute n octets de la chaine source sur la chaine dest. Attention à la taille. */
/*Retourne : le pointeur de la chaîne dest.						       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest, et la taille de la chaine   */
/*			 source. 							       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/

char* StringNConcat(char* dest, const char * src, int b)
{int i=0,a=0;
while(dest[i]!='\0') i++;	//On cherche la taille de dest
while(a!=b) {
dest[i]=src[a];
i++;a++;
}
dest[i]='\0';
return dest;
}

/***********************************************************************************************/
/*Nom de la fonction : StringCompare							       */
/*Description : Compare les chaînes de caractères à l'aide du code Ascii. Par exemple, si la   */
/*		la première chaine est inférieur à la seconde, elle renvoit un négatif.        */
/*Retourne : un entier positif si la chaîne 2 est plus grande, ou 0 si les deux chaînes sont   */
/*	     identiques.								       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes 1 et 2				       */
/*Paramètres en sortie : un entier (cf Retourne)					       */
/***********************************************************************************************/
int StringCompare(const char* ch1, const char * ch2)
{int i=0,a;
while(ch1[i]==ch2[i] && (ch1[i]!='\0' && ch2[i]!='\0')) i++;	
//Si ch1[i]=='\0' et ch2[i]=='\0' alors ch1[i]==ch2[i] MAIS on doit s'arrêter !
a=ch1[i]-ch2[i];
return a;
}


  
 



