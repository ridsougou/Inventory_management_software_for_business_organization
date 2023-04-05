#include "gestion_fournisseur.h"

/**fonction d'affichage de fournisseur
*/
void affiche_fournisseur(FOURNI frn)
{
    int i;
    printf("%d|%ld|%d\n",frn.code,frn.tel,frn.nbProd);

    for(i=0;i<frn.nbProd;i++){

        printf("%s|%s|%f|%d|%f|%d|%d|%d|\n",frn.tabListProduit[i].nom,frn.tabListProduit[i].designation,frn.tabListProduit[i].prix,
           frn.tabListDetailProd[i].code,frn.tabListDetailProd[i].qteStock,frn.tabListDetailProd[i].dateLimite.mois,frn.tabListDetailProd[i].dateLimite.annee ,frn.tabListDetailProd[i].dateLimite.jour );
    }
}
/**fonction d'affichage de l'adresse
*/
void affiche_adresse(ADR adr){
    printf("%d|%s|%s|%d|%s\n",adr.codePostal,adr.nomRue,adr.nomVille,adr.numero,adr.pays);
}
/**
Fonction d'affichage d'une liste de fournisseurs de taille nb
Cette fonction affiche à partir d'un tableau de fournisseurs "listeFournisseur"
Passé en argument de la fonction
le type de retour est vide (void)
*/
void affiche_liste_fournisseurs(FOURNI* listeFournisseur, int nb, ADR adr )
{
 int i;
    for(i =0; i< nb; i++ )
    {
        affiche_fournisseur(listeFournisseur[i]);
        affiche_adresse(adr);
    }

}


DETPROD saisir_detail()
{


    DETPROD det;


    printf("Introduire un code produit  :");
    scanf("%d",&det.code);

    printf("Introduire une quantite de produit  :");
    scanf("%f",&det.qteStock);

    printf("Introduire un jour limite :");
    scanf("%d",&det.dateLimite.jour);

    printf("Introduire un mois limite :");
    scanf("%d",& det.dateLimite.mois);

    printf("Introduire une annee limite :");
    scanf("%d",&det.dateLimite.annee);


    return det;


}




/** fonction de saisie de fournisseur
   Elle saisie un fournisseur temporaire et le retourne à la fin de la saisie
*/

FOURNI saisir_fournisseur()
{

FOURNI frntmp;

int j;

    printf("Introduire le code de fournisseur : ");
    scanf("%d",&frntmp.code);
    saisir_adresse();
    printf("Introduire le tel du fournisseur : ");
    scanf("%ld",&frntmp.tel);
    printf("Introduire le nombre de produit : ");
    scanf("%d",&frntmp.nbProd);
for (j = 0; j <frntmp.nbProd ; j++)
    {
     frntmp.tabListProduit[j] = saisir_produit();
     frntmp.tabListDetailProd[j]=saisir_detail();

    }
    return frntmp;

}

ADR saisir_adresse()
{
    ADR adrtmp;
    printf("Introduire l'adresse : \n");
        printf("Introduire le numero de la rue : ");
        scanf("%d",&adrtmp.numero);
        fflush(stdin);
        printf("Introduire le nomRue : ");
        scanf("%s",&adrtmp.nomRue);
        adrtmp.nomRue[30] = '\0';
        fflush(stdin);
        printf("Introduire le nomVille : ");
        scanf("%s",&adrtmp.nomVille);
        adrtmp.nomVille[30] = '\0';
        fflush(stdin);
        printf("Introduire le code Postal : ");
        scanf("%d",&adrtmp.codePostal);
        fflush(stdin);
        printf("Introduire le pays : ");
        scanf("%s",&adrtmp.pays);
        adrtmp.pays[30] = '\0';
        fflush(stdin);
}
/**
Fonction de saisie d'une liste de fournisseurs de taille nb
*/
void saisir_liste_fournisseurs(FOURNI* listeFournisseur,int nb)
{

int i;
    for(i=0; i< nb; i++)
    {
        listeFournisseur[i] = saisir_fournisseur();
    }
}
/**fonction de tri de liste de fournisseurs
Cette fonction permet à l'utilisateur de trier la liste de fournisseurs par code
Le tri s'effectue sur le tableau listeFournisseur
*/
void tri_liste_fournisseurs_code(int nb, FOURNI* listeFournisseur)
{
     FOURNI frnTmp;
    int positionMax;
    int i;
    int j;
 for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si la valeur max courante est plus petite que la prochaine valeur
                if (listeFournisseur[positionMax].code < listeFournisseur[j].code)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieFourni(listeFournisseur[i],&frnTmp);
                copieFourni(listeFournisseur[positionMax],&listeFournisseur[i]);
                copieFourni(frnTmp,&listeFournisseur[positionMax]);
            }
        }

}

/**fonction de tri de liste de fournisseurs
Cette fonction permet à l'utilisateur de trier la liste de fournisseurs par tel
Le tri s'effectue sur le tableau listeFournisseur
*/
void tri_liste_fournisseurs_tel(int nb, FOURNI* listeFournisseur)
{

 FOURNI frnTmp;
    int positionMax;
    int i;
    int j;
 for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si la valeur max courante est plus petite que la prochaine valeur
                if (listeFournisseur[positionMax].tel < listeFournisseur[j].tel)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieFourni(listeFournisseur[i],&frnTmp);
                copieFourni(listeFournisseur[positionMax],&listeFournisseur[i]);
                copieFourni(frnTmp,&listeFournisseur[positionMax]);
            }
        }


}
void copieFourni(FOURNI frnSource, FOURNI*frNdestination)
{
    strcpy(frNdestination->code, frnSource.code);
    strcpy(frNdestination->tel, frnSource.tel);
    frNdestination->nbProd = frnSource.nbProd;
}
/**
Inserer un fournisseur dans un tableau trié
Cette fonction insère un fournisseur dans une liste de fournisseur
Si le tableau est déjà remplis ou si le fournisseur existe déjà
 ==> La fonction retourne 0
Sinon si l'insertion a été bien effectuée
 ==> la fonction retourne 1

*/
void inserer_un_fournisseur(int nb,FOURNI* listeFournisseur, FOURNI new_fourni)
{
int  INDEX_INSERTION;
    int i;
    int result_insertion;
    //FOURNI listeFournisseur[MAX_SIZE_TAB_FOURNI];
    int code_founisseur;
    if(nb==MAX_SIZE_TAB_FOURNI || recherche_founisseur(listeFournisseur, nb,code_founisseur )!=-1)
    {
        result_insertion = 0;
    }
    else
    {
//insersion d'une valeur dans un tableau trié par code
//Chercher l'index d'insertion
        for(INDEX_INSERTION=nb,i=0; i<nb; i++)
        {
            if(new_fourni.code <listeFournisseur[i].code)
            {
                INDEX_INSERTION = i;
                i=nb;
            }
        }
//decalage à droite
        for(i=nb; i>INDEX_INSERTION; i--)
        {
            copieFourni(listeFournisseur[i-1],&listeFournisseur[i]);
        }
//insertion et incrementation du compteur N
        copieFourni(new_fourni, &listeFournisseur[INDEX_INSERTION]);
        result_insertion = 1;
    }
    return result_insertion;

}
/**
Fonction de suppression de produit à partir d'un liste de produit
Retour 1 si le produit a été supprimé
Sinon la fonction retourne 0
*/
int supprimer_fournisseur(int nb, FOURNI*listeFournisseur, FOURNI frn_a_supprimer )
{
//declaration
    int i;
    int j;
    int result =0;
    for(i=0; i<nb && result==0 ; i++)
    {

        if(strcmp(listeFournisseur[i].code,frn_a_supprimer.code) == 0 && listeFournisseur[i].nbProd == frn_a_supprimer.nbProd && strcmp(listeFournisseur[i].tel,frn_a_supprimer.tel) == 0 )
        {
            result=1;
            for(j=i ; j<nb-1 ; j++)
            {

                copieFourni(listeFournisseur[j+1],&listeFournisseur[j]);
            }
        }
        return result;
    }
}
/**
Fonction d'enregistrement d'une liste de produit dans un fichier
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
*/
void save_tabFourni_in_file(int nb, FOURNI*listeFournisseur,char*nom_file)
{
    FILE* fp_write = NULL;
    int i;
    fp_write= fopen(nom_file,"w"); /**r:read ; w: write ; a : append ; r+ : lecture et écriture*/

    if(!fp_write)
    {
        printf("Erreur de l'ouverture du fichier");
    }
    //traitement
    //CHANEL|Sac|6000
    //DELL|Ordinateur|1200
    for(i=0; i<nb; i++)
    {
        fprintf(fp_write,"%s|%s|%f\n",listeFournisseur[i].code, listeFournisseur[i].tel, listeFournisseur[i].nbProd);
    }
    fclose(fp_write);

}






//fonction de recherche founisseur
//retourne -1 si le fournisseur a été retrouvé sinon l'index du founisseur dans le tableau des fournisseurs
int recherche_founisseur(FOURNI* listeFournisseur, int nb,int code_founisseur ){
    int index= -1;


     int i;
    for(i =0; i<nb ; i++)
    {
        if(strcmp(listeFournisseur[i].code,code_founisseur) == 0 )
            index = i;
        i = nb;
    }

    return index;
}

int menu_fournisseur()
{
    int choix;
    do
    {
        system("cls");
        printf("******* Menu 1 : Gestion des fournisseurs *********\n");
        printf("Introduire votre choix :\n");
        printf("-%d Saisie Liste Fournisseurs\n",SAISIE_LST_FOURNI);
        printf("-%d Chargement Fournisseurs from File\n",CHARGE_FOURNI_FICHIER_EXTER );
        printf("-%d Chargement Fournisseurs from BD\n",CHARG_FOURNI_BD );
        printf("-%d Supprimer un fournisseur \n",SUPP_FOURNI  );
        printf("-%d Ajouter un fournisseur\n",AJOUT_FOURNI  );
        printf("-%d Rechercher un fournisseur \n",RECHERCHE_FOURNI  );
        printf("-%d Afficher une liste de fournisseur\n",AFFICHE_LISTE_FOURNI  );
        printf("-%d Exporter la liste de fournisseur dans un fichier\n",EXPORT_LISTE_FOURNI_FICHIER );
        printf("-%d Exporter la liste de fournisseur dans une BD\n",EXPORTER_LST_FOURNI_BD );
        printf("-%d ***Menu gerer un fournisseur *** \n",MENU_GERER_FOUNISSEUR );
        printf("-%d QUITTER\n",QUITTER);
        scanf("%d",&choix);
    }
    while(choix!=SAISIE_LST_FOURNI
            && choix !=CHARGE_FOURNI_FICHIER_EXTER
            && choix != CHARG_FOURNI_BD
            && choix != QUITTER
            && choix !=MENU_GERER_FOUNISSEUR
            && choix !=SUPP_FOURNI
            && choix !=AJOUT_FOURNI
            && choix !=RECHERCHE_FOURNI
            && choix !=AFFICHE_LISTE_FOURNI
            && choix !=EXPORT_LISTE_FOURNI_FICHIER
            && choix !=EXPORTER_LST_FOURNI_BD


         );
    return choix;
}

int menu_gerer_un_fournisseur(int code_fournisseur){
/*
Plan du menu
•Modifier un fournisseur
• Ajouter une liste de produit à un fournisse
• Ajouter un produit à la liste produit du fournisseur
• Mettre à jour le détail de produit d’un produit d’un fournisseur
• Supprimer un produit dans la liste de produit du fournisseur
• Afficher la liste de produit du fournisseur
• Revenir au menu 1
*/
int choix;
    do
    {
        system("cls");
        printf("******* Menu 2 : Gerere founisseur < %d >*********\n",code_fournisseur);
        printf("Introduire votre choix :\n");
        printf("-%d Modifier un fournisseur\n",MODIF_FOURNI);
        printf("-%d Ajouter produit a la liste du Fournisseur\n",AJOUT_LST_PROD_FOURNI );
        printf("-%d Ajouter une liste de produit a un fournisseur\n",AJOUT_PROD_A_LST_PROD_FOURNI );
        printf("-%d Mettre a jour le detail de produit d un produit d un fournisseur\n",METTRE_JR_DETAIL );
        printf("-%d Supprimer un produit dans la liste de produit du fournisseur\n",SUPP_PROD_LST_PROD_FOURNI );
        printf("-%d Afficher la liste de produit du fournisseur\n",AFFICHE_LISTE_PROD_FOURNI );
        printf("-%d Rervenir au menu principal\n",REVENIR_MENU_PRINCPAL);
        scanf("%d",&choix);
    }
    while(choix!=MODIF_FOURNI
            && choix !=AJOUT_LST_PROD_FOURNI
            && choix != AJOUT_PROD_A_LST_PROD_FOURNI
            && choix != METTRE_JR_DETAIL
            && choix !=SUPP_PROD_LST_PROD_FOURNI
            && choix !=AFFICHE_LISTE_PROD_FOURNI
            && choix !=REVENIR_MENU_PRINCPAL

         );

    return choix;
}

/**
Rechercher un produit dans le tableau des produit d'un fournisseur
et de retourner true s'il est retrouvé
et de retourner false s'il n'est pas retrouvé
*/
bool rechercher_prod_fournisseur(FOURNI fournisseur, PROD prod_recherche)
{

//les variables
    int i;
    bool retrouve = false;
    for(i=0; retrouve == false && i<fournisseur.nbProd; i++)
    {
        if(strcmp(fournisseur.tabListProduit[i].designation,prod_recherche.designation) == 0
                &&
                strcmp(fournisseur.tabListProduit[i].nom, prod_recherche.nom) == 0
                &&
                fournisseur.tabListProduit[i].prix==prod_recherche.prix)
        {
            retrouve = true;
        }
    }
    return retrouve;
}
/**
Insérer un nouveau produit dans un founisseur
Le produit doit etre déja non existant dans le tableau des produits du fournisseurs
Cette fonction doit être appelée une fois la recherche du nouveau produit a retourné flase (0)
*/
FOURNI inserer_nouveau_produit_a_fournisseur(FOURNI fournisseur, PROD new_prod)
{


}
