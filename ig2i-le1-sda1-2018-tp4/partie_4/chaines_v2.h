#ifndef chaine_h
#define chaine_h
#define MAX 80
typedef char TCHAINE[MAX];

//Prototypes des fonctions
int StringLenght(const char *);
char *StringCopy(char*, const char*);
char *StringNCopy(char*, const char*, int);
char* StringConcat(char*, const char*);
char* StringNConcat(char*, const char*, int);
int StringCompare(const char*, const char*);
int menu();
#endif

