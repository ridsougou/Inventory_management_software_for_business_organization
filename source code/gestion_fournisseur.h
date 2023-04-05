#ifndef GESTION_FOURNISSEUR_H_INCLUDED
#define GESTION_FOURNISSEUR_H_INCLUDED

#define MAX_SIZE_TAB_PROD_FOURNI 10
#define MAX_SIZE_TAB_FOURNI 11
#define MAX_SIZE_TAB_FOURNI 100
#include "gestion_produit.h"
//menu_1
#define SAISIE_LST_FOURNI 1
#define CHARGE_FOURNI_FICHIER_EXTER 2
#define CHARG_FOURNI_BD 3
#define SUPP_FOURNI  4
#define AJOUT_FOURNI  5
#define RECHERCHE_FOURNI  6
#define AFFICHE_LISTE_FOURNI  7
#define EXPORT_LISTE_FOURNI_FICHIER 8
#define EXPORTER_LST_FOURNI_BD 9
#define MENU_GERER_FOUNISSEUR 10
#define QUITTER 11
//menu_2
#define MODIF_FOURNI 1
#define AJOUT_PROD_A_LST_PROD_FOURNI 2
#define AJOUT_LST_PROD_FOURNI 3
#define METTRE_JR_DETAIL 4
#define SUPP_PROD_LST_PROD_FOURNI 5
#define AFFICHE_LISTE_PROD_FOURNI 6
#define REVENIR_MENU_PRINCPAL 7




struct Adresse
{
    int numero;
    char nomRue[30];
    char nomVille[30];
    int codePostal;
    char pays[30];
};
typedef struct Adresse ADR;
struct Date
{
    int jour;
    int mois;
    int annee;
};
typedef struct Date DATE;

struct Detail_Produit
{
    int code;
    float prix;
    float qteStock;
    DATE dateLimite;
};
typedef struct Detail_Produit DETPROD;


struct Fournisseur
{
    int code;
    ADR adresse;
    long tel;
    PROD tabListProduit[MAX_SIZE_TAB_PROD_FOURNI];
    DETPROD tabListDetailProd[MAX_SIZE_TAB_PROD_FOURNI];
    int nbProd;
    int nbFourni;
};
typedef struct Fournisseur FOURNI;




void affiche_fournisseur(FOURNI frn); //fonction d'affichage de fournisseur
void affiche_adresse(ADR adr); //fonction d'affichage de l'adreese
void affiche_liste_fournisseurs(FOURNI* listeFournisseur, int nb,ADR adr); //fonction d'affichage de fournisseur
FOURNI saisir_fournisseur(); // fonction de saisie de founisseur
ADR saisir_adresse(); // fonction de saisie d'adresse
void saisir_liste_fournisseurs(FOURNI* listeFournisseur,int nb); //fonction saisie de liste fournisseur
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFournisseur);
void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFournisseur);
void copieFourni(FOURNI frnSource, FOURNI*frDdestination);
void inserer_un_fournisseur(int nb,FOURNI* listeFournisseur, FOURNI new_fourni);
int supprimer_fournisseur(int nb, FOURNI*listeFournisseur, FOURNI frn_a_supprimer );
void save_tabFourni_in_file(int nb, FOURNI*listeFournisseur,char*nom_file);
int recherche_founisseur(FOURNI* listeFournisseur, int nb,int code_founisseur );
int menu_fournisseur();
int menu_gerer_un_fournisseur();

bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche);
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod);



#endif // GESTION_FOURNISSEUR_H_INCLUDED
