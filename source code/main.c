#include "gestion_produit.h"
#include "gestion_fournisseur.h"

int main()
{
    //déclaration des variables
    PROD listeProd[MAX_SIZE_TAB_PRODUIT];
    FOURNI listeFournisseur[MAX_SIZE_TAB_FOURNI];
    ADR adr;
    PROD prd_a_supprimer;
    FOURNI liste_a_supprimer;
    FOURNI new_fourni;
    FOURNI affichage_de_la_liste;
    PROD new_prod;
    PROD new_list_prod;
    int nb;
    char nom_file;
    int retour;
    int choix;
    int code_founisseur;
    int index_founisseur;
    do
    {
        choix = menu_fournisseur();
        switch(choix)
        {
        case(SAISIE_LST_FOURNI):
            do
            {
                system("cls");
                printf("Introduire nb : ");
                scanf("%d",&nb);
            }
            while(nb<=0||nb>MAX_SIZE_TAB_FOURNI);

            //sasiie des données

            saisir_liste_fournisseurs(listeFournisseur,nb);
           //
            //break;
        case(CHARGE_FOURNI_FICHIER_EXTER):
//ajout_fournisseur(nb,listeFournisseur);
            break;
        case(CHARG_FOURNI_BD):
            break;
        case(SUPP_FOURNI):
            printf("Saisir le code du fournisseur a supprimer : \n");
            scanf("%d",&code_founisseur);
           // liste_a_supprimer = ;
            listeFournisseur[index_founisseur].nbProd-=supprimer_produit(listeFournisseur[index_founisseur].nbProd,listeFournisseur[index_founisseur].tabListProduit,prd_a_supprimer);

            break;
        case(AJOUT_FOURNI):
             new_fourni = saisir_fournisseur();
             listeFournisseur[index_founisseur].nbProd+=inserer_un_produit(listeFournisseur[index_founisseur].nbProd,listeFournisseur[index_founisseur].tabListProduit,new_prod);

            break;
            case(RECHERCHE_FOURNI):
                recherche_founisseur(nb,listeFournisseur,code_founisseur);
            break;
            case(AFFICHE_LISTE_FOURNI):

                system("cls");
                printf("Voici la liste des fournisseurs:  \n");
                affiche_liste_fournisseurs(listeFournisseur,nb,adr);
                printf("Veuillez introduire '1' pour retourner au menu pricipal:  \n");
                scanf("%d",&retour);
                if(retour =!1){
                   menu_fournisseur();
                }

            break;
            case(EXPORT_LISTE_FOURNI_FICHIER):
            save_tabFourni_in_file(nb,listeFournisseur,nom_file);
            break;
            case(EXPORTER_LST_FOURNI_BD):
            break;


        case(MENU_GERER_FOUNISSEUR):
            system("cls");
            printf("Inroduire le code du founisseur a gerer : ");
            scanf("%d",&code_founisseur);
            index_founisseur = recherche_founisseur(listeFournisseur, nb,code_founisseur );

            do
            {
                choix = menu_gerer_un_fournisseur(code_founisseur);
                switch(choix)
                {
                case(MODIF_FOURNI):
                    break;
                case (AJOUT_PROD_A_LST_PROD_FOURNI):
                    printf("Saisir le produit a inserer : \n");
                    new_prod = saisir_produit();
                    listeFournisseur[index_founisseur].nbProd+=inserer_un_produit(listeFournisseur[index_founisseur].nbProd,listeFournisseur[index_founisseur].tabListProduit,new_prod);

                    break;
               case (AJOUT_LST_PROD_FOURNI):
                    printf("Saisir la liste de produit a inserer : \n");
                    saisir_produit();
                    saisir_detail();
                    listeFournisseur[index_founisseur].tabListProduit;
                case (SUPP_PROD_LST_PROD_FOURNI):
                    printf("Saisir le produit a supprimer : ");
                    prd_a_supprimer = saisir_produit();
                    listeFournisseur[index_founisseur].nbProd-=supprimer_produit(listeFournisseur[index_founisseur].nbProd,listeFournisseur[index_founisseur].tabListProduit,prd_a_supprimer);
                    break;
                case(REVENIR_MENU_PRINCPAL) :
                    printf("Retour au menu principal\n");
                    break;
                default:
                    break;
                }
            }
            while(choix!=REVENIR_MENU_PRINCPAL);
            break;
        case(QUITTER):
            printf("Au revoir \n");
            break;
        default :
            break;
        }
    }
    while(choix != QUITTER);
        /*do
        {
            printf("Introduire nb : ");
            scanf("%d",&nb);
        }
        while(nb<=0||nb>MAX_SIZE_TAB_PRODUIT);

        //sasiie des données
        saisir_liste_produit(nb,listeProd);

        //affichage
        printf("\nAffichage liste Produits Test :\n");
        affiche_liste_produit(listeProd,nb);

        tri_liste_produit(nb,listeProd);
        //affichage
        printf("\nAffichage liste Produits Apres tri :\n");
        affiche_liste_produit(listeProd,nb);*/

    return 0;
}
