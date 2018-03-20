//Ce fichier contient le code des programmes de la bibliothèque chaines.h
//chaines.o sert à faire la compilation avec le programme principal.

#include "chaines.h"		//On inclut la bibiothèque chaines.h (fonctions + type TCHAINE)
#include <stdio.h>
#include <stdlib.h>

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


/***************************************************************************/
/* NOM FONCTION : StringCopy						   */
/* DESCRIPTION :  Retourne une copie de la chaine s1		           */
/* Retourne :dest (chaine de caractÃšres)			   	   */
/* Effets de bords : 			                                   */
/* ParamÃštres en entree : src (chaine  source)	                   	   */
/* ParamÃštres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringCopy(char* dest, const char* src)
{
int i=0;
while (dest[i]=src[i]) i++;
return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringLenght					   */
/* DESCRIPTION : calcule la longueur de la chaine passee en parametres     */
/* Retourne : int (valeur de la longueur)				   */
/* Effets de bords : 			                                   */
/* ParamÃštres en entree :ch1 (const TCHAINE)                                 */
/* ParamÃštres en sortie :      			                           */
/***************************************************************************/

int StringLenght(const char *ch)
{int n=0;
while(ch[n]!='\0') n++;
return n;
}



/***************************************************************************/
/* NOM FONCTION : StringNCopy						   */
/* DESCRIPTION :  Retourne l'adresse de la chaine dest		           */
/* Retourne :dest (chaine de caractÃšres)			   	   */
/* Effets de bords : 			                                   */
/* ParamÃštres en entree : src (chaine  source)				   */
/*			  n (nombre de caracteres a copier)		   */
/* ParamÃštres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringNCopy(char* dest, const char* src, int n)
{int i=0;
while(i!=n && src[i]!='\0') {
dest[i]=src[i];
i++;
}
if(dest[i]!='\0') dest[i]='\0';

return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringConcat						   */
/* DESCRIPTION :  Concatene dest+src				           */
/* Retourne :dest (chaine de caractÃšres obtenue par contenation de deux src*/
/* Effets de bords : 			                                   */
/* ParamÃštres en entree : dest et src (chaines  sources)	           */
/* ParamÃštres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringConcat(char* dest, const char * src)
{int i=0,a=0;
while(dest[i]!='\0') i++;	//On cherche la taille de dest
while(src[a]!='\0') {
	dest[i]=src[a];
	a++;
	i++;
}
dest[i+1]='\0';
return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringNConcat						   */
/* DESCRIPTION :  Concatene dest+ N caracteres de src		 	   */
/* Retourne :dest (chaine de caractÃšres obtenue par contenation de deux src*/
/* Effets de bords : 			                                   */
/* ParamÃštres en entree : dest et src (chaines  sources)	           */
/*			  n (nombre de caracteres a copier)		   */
/* ParamÃštres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringNConcat(char* dest, const char * src, int b)
{int i=0,a=0;
while(dest[i]!='\0') i++;	//On cherche la taille de dest
while(a!=b) {
dest[i]=src[a];
i++;a++;
}
dest[i+1]='\0';
return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringCompare					  	   */
/* DESCRIPTION :  Compare deux chaines de caracteres. Retoune 0 si elles   */
/* sont identiques, sinon la premire position de leur difference	   */
/* Retourne :0 si les chaines sont egales 				   */
/* Effets de bords : 			                                   */
/* ParamÃštres en entree : ch1 et ch2 (chaines  sources)	           	   */
/* ParamÃštres en sortie :    		   */
/***************************************************************************/

int StringCompare(const char* ch1, const char * ch2)
{int i=0,a;
while(ch1[i]==ch2[i] && (ch1[i]!='\0' && ch2[i]!='\0')) i++;
a=ch1[i]-ch2[i];
return a;
}
