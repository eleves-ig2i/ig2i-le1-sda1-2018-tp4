
//Ce fichier contient la description de chacune des fonctions programmées dans ce TP."

#ifndef chaine_h
#define chaine_h
#define MAX 80
typedef char TCHAINE[MAX];


// Déclaration des fonctions
int StringLenght(const char *);
/***********************************************************************************************/
/*Nom de la fonction : StringLenght							       */
/*Description : mesure la taille n de la chaîne de caractères.				       */ 
/*Retourne : la taille de la chaîne de caractères					       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : la chaîne de caractères T					       */
/*Paramètres en sortie : la taille n							       */
/***********************************************************************************************/


char *StringCopy(char*, const char*);
/***********************************************************************************************/
/*Nom de la fonction : StringCopy							       */
/*Description : copie la chaîne source sur la chaîne dest, si cette dernière est assez grande. */
/*Retourne : le pointeur de la chaîne dest.						       */ 
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest			       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/


char *StringNCopy(char *, const char *, size_t );
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


char *StringConcat(char *, const char *);
/***********************************************************************************************/
/*Nom de la fonction : StringConcat							       */
/*Description : concatène la chaîne source sur la chaîne dest, si cette dernière est assez     */
/*		grande.									       */
/*Retourne : le pointeur de la chaîne dest.						       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest			       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/


char *StringNConcat(char *, const char*, size_t);
/***********************************************************************************************/
/*Nom de la fonction : StringNConcat							       */
/*Description : ajoute n octets de la chaine source sur la chaine dest. Attention à la taille. */
/*Retourne : le pointeur de la chaîne dest.						       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes source et dest, et la taille de la chaine   */
/*			 source. 							       */
/*Paramètres en sortie : le pointeur de la chaîne dest					       */
/***********************************************************************************************/


int StringCompare(const char *, const char *):
/***********************************************************************************************/
/*Nom de la fonction : Stringcompare							       */
/*Description : Compare les chaînes de caractères à l'aide du code Ascii. Par exemple, si la   */
/*		la première chaine est inférieur à la seconde, elle renvoit un négatif.        */
/*Retourne : un entier positif si la chaîne 2 est plus grande, ou 0 si les deux chaînes sont   */
/*	     identiques.								       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : les pointeurs des chaînes 1 et 2				       */
/*Paramètres en sortie : un entier (cf Retourne)					       */
/***********************************************************************************************/
#endif


