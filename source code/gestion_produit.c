
#include "gestion_produit.h"

/**fonction d'affichage de produit
*/
void affiche_produit(PROD prd)
{
    printf("%s|%s|%.2f\n",prd.nom, prd.designation, prd.prix);
}
/**
Fonction d'affichage d'une liste de produit de taille nb
Cette fonction affiche à partir d'un tableau de produit "listProduit"
Passé en argument de la fonction
le type de retour est vide (void)
*/
void affiche_liste_produit(PROD* listProduit, int nb)
{
    int i;
    for(i =0; i< nb; i++ )
    {
        affiche_produit(listProduit[i]);
    }
}
/** fonction de saisie de produit
   Elle saisie un produit temporaire et le retourne à la fin de la saisie
*/
PROD saisir_produit()
{
    PROD prdtmp;
    printf("Introduire le nom : ");
    scanf("%s",&prdtmp.nom);
    prdtmp.nom[39] = '\0';
    fflush(stdin);
    printf("Introduire la designation : ");
    scanf("%s",&prdtmp.designation);
    prdtmp.nom[59] = '\0';
    fflush(stdin);
    printf("Introduire le prix : ");
    scanf("%f",&prdtmp.prix);

    return prdtmp;
}
/**
Fonction de saisie d'une liste de produit de taille nb
*/

void saisir_liste_produit(int nb, PROD * listProduit)
{
    int i;
    for(i=0; i< nb; i++)
    {
        listProduit[i] = saisir_produit();
    }
}

/**fonction de tri de liste produit
Cette fonction demande à l'utilisateur le choix du type du tri
1 - tri par nom
2 - tri par prix
Elle prend en argument un nombre de produit ainsi que la liste de ces produits
Le tri s'effectue sur le tableau listProduit
*/
void tri_liste_produit(int nb, PROD* listProduit)
{
    PROD prdTmp;
    int positionMax;
    int i;
    int j;
    int choix;

    do
    {
        printf("Introduire votre choix : \n");
        printf("-%d tri par prix\n",TRI_PRIX);
        printf("-%d tri par nom\n",TRI_NOM);
        scanf("%d",&choix);
    }
    while(choix!=TRI_PRIX&& choix!=TRI_NOM);

// Traitement
    if(choix==TRI_PRIX)
    {
        for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si la valeur max courante est plus petite que la prochaine valeur
                if (listProduit[positionMax].prix < listProduit[j].prix)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieProd(listProduit[i],&prdTmp);
                copieProd(listProduit[positionMax],&listProduit[i]);
                copieProd(prdTmp,&listProduit[positionMax]);
            }
        }

    }
    else if(choix ==TRI_NOM)
    {
        for (i = 0; i < nb-1; i++)
        {
            for (j = i+1, positionMax = i; j < nb; j++)
            {
                // Check si le nom est > sur le plan ascii au nom de position max
                if (strcmp(listProduit[positionMax].nom, listProduit[j].nom)<0)
                {
                    positionMax = j;
                }
            }
            // Permutation des valeurs
            if(positionMax != i)
            {
                copieProd(listProduit[i],&prdTmp);
                copieProd(listProduit[positionMax],&listProduit[i]);
                copieProd(prdTmp,&listProduit[positionMax]);
            }
        }
    }

}
void copieProd(PROD prdSource, PROD*prDdestination)
{
    strcpy(prDdestination->designation, prdSource.designation);
    strcpy(prDdestination->nom, prdSource.nom);
    prDdestination->prix = prdSource.prix;
}

/**
Inserer un produit dans un tableau trié
Cette fonction insère un produit dans une liste de produit
Si le tableau est déjà remplis ou si le produit existe déjà
 ==> La fonction retourne 0
Sinon si l'insertion a été bien effectuée
 ==> la fonction retourne 1

*/
int inserer_un_produit(int nb,PROD* listProduit, PROD new_prod)
{
    int  INDEX_INSERTION;
    int i;
    int result_insertion;

    if(nb==MAX_SIZE_TAB_PRODUIT || rechercher_produit(nb, listProduit, new_prod)!=-1)
    {
        result_insertion = 0;
    }
    else
    {
//insersion d'une valeur dans un tableau trié par prix
//Chercher l'index d'insertion
        for(INDEX_INSERTION=nb,i=0; i<nb; i++)
        {
            if(new_prod.prix <listProduit[i].prix)
            {
                INDEX_INSERTION = i;
                i=nb;
            }
        }
//decalage à droite
        for(i=nb; i>INDEX_INSERTION; i--)
        {
            copieProd(listProduit[i-1],&listProduit[i]);
        }
//insertion et incrementation du compteur N
        copieProd(new_prod, &listProduit[INDEX_INSERTION]);
        result_insertion = 1;
    }
    return result_insertion;

}

/**rechercher un produit dans une liste de produit
//retourne l'index du produit dans le tableau listProduit
//sinon -1*/
int rechercher_produit(int nb, PROD*listProduit, PROD prd_recheche )
{
    int result_recherche = -1;
    int i;
    for(i =0; i<nb ; i++)
    {
        if(strcmp(listProduit[i].nom,prd_recheche.nom) == 0 && listProduit[i].prix == prd_recheche.prix && strcmp(listProduit[i].designation,prd_recheche.designation) == 0 )
            result_recherche = i;
        i = nb;
    }
    return result_recherche;

}

/**
Fonction de suppression de produit à partir d'un liste de produit
Retour 1 si le produit a été supprimé
Sinon la fonction retourne 0
*/
int supprimer_produit(int nb, PROD*listProduit, PROD prd_a_supprimer )
{
//declaration
    int i;
    int j;
    int result =0;
    for(i=0; i<nb && result==0 ; i++)
    {

        if(strcmp(listProduit[i].nom,prd_a_supprimer.nom) == 0 && listProduit[i].prix == prd_a_supprimer.prix && strcmp(listProduit[i].designation,prd_a_supprimer.designation) == 0 )
        {
            result=1;
            for(j=i ; j<nb-1 ; j++)
            {

                copieProd(listProduit[j+1],&listProduit[j]);
            }
        }
        return result;
    }
}

/**
Fonction de modification de produit à partir d'un liste de produit
Retour 1 si le produit a été modifié
Sinon la fonction retourne 0
*/
int modifier_produit(int nb, int index_prod_to_modif, PROD*listProduit, PROD prd_modifie)
{

}

/**
Fonction d'enregistrement d'une liste de produit dans un fichier
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
*/
void save_tabproduit_in_file(int nb, PROD*listProduit,char*nom_file)
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
        fprintf(fp_write,"%s|%s|%f\n",listProduit[i].nom, listProduit[i].designation, listProduit[i].prix);
    }
    fclose(fp_write);

}
/**
Fonction de chargement d'une liste de produit à partir d'un fichier externe
identifié par son nom (ça peut être un path "C:\\fileproduit\fichierproduit.txt")
Cette fonction retourne :
- le nombre de ligne du fichier => le nombre de produit
- à ==> si le fichier est vide
*/
int load_tabproduit_from_file(PROD*listProduit,char*nom_file)
{
    FILE* fp_read = NULL;
    int i;
    char ligne[100];
    fp_read= fopen(nom_file,"r"); /**r:read ; w: write ; a : append ; r+ : lecture et écriture*/

    if(!fp_read)
    {
        printf("Erreur de l'ouverture du fichier");
    }
    i = 0;
    while(fgets(ligne,200,fp_read))
    {
        sscanf(ligne,"%s|%s|%f\n",listProduit[i].nom,listProduit[i].designation,&listProduit[i].prix);
        i++;
    }

    fclose(fp_read);
    return i;
}

