#include <stdio.h>
#include <stdlib.h>

typedef struct Etudiant Etudiant;
struct Etudiant{
    char nom[30];
    char prenom[30];
    int age;
    char sexe;
};
int static j=0;

//Fonction pour afficher les etudiants
void affLEtu(Etudiant tab[]){
    int i;
    for (i = 0; i < j; i++)
    {
        printf("Nom : %s \tPrenom : %s \t Age : %d \tSexe : %c \n", tab[i].nom, tab[i].prenom, tab[i].age, tab[i].sexe);
    }
}

//Fonction afficher le moins agé
void moinsAge(Etudiant *tab, int val){
    int min,k;
    min = tab[0].age;
    for (int i=0 ; i< val ; i++)
      {
        if(tab[i].age<min){
            min=tab[i].age;
            k=i;
        }
      }
    printf("LE MOINS AGE EST : \n");
    printf("Nom : %s \tPrenom : %s \t Age : %d \tSexe : %c \n", tab[k].nom, tab[k].prenom, tab[k].age, tab[k].sexe);
}

//Fonction pour remplir la table etudiant
void remplirEtu( Etudiant *Etu){
    char reponse = 'o';
    printf("ENTREZ LES INFORMATIONS DES ETUDIANTS");
    do{
        printf("Etudiant : %d \n", j+1);
        printf("Entrer le nom : \n");
        scanf("%s",Etu[j].nom);
        printf("Entrer le Prenom : \n");
        scanf("%s",Etu[j].prenom);
        printf("Entrer l'age : \n");
        scanf("%d",&Etu[j].age);
        fflush(stdin);
        printf("Entrer le sexe : \n");
        scanf("%c",&Etu[j].sexe);
        fflush(stdin);

        j++;
        fflush(stdin);
        printf("\nContinuer ? _(o/n)_");
        scanf("%c",&reponse);
    }while(j<10 && reponse == 'o');
}

//Programme principal
int main()
{
    Etudiant Etud[10];
    remplirEtu(Etud);
    affLEtu(Etud);
    moinsAge(Etud, j);
}
