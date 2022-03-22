//DM de la semaine prochaine 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h>
//déclaration de structure rdv.
typedef struct RDV { 
char nom[20];  
char prenom[20]; 
char lieu[20]; 
int jour; 
int mois; 
int annee; 
int minute; 
int heure;
char objet[200]; 
int numero ;  
struct RDV * suivant, *precedent ;  
}RDV;  

// déclaration de la tête de liste.
RDV * teteListe  = NULL;  

//signature des procédures et des fonctions

//=========================================================================================================================================================
//===============================================================AJOUTER DES RDV============================================================================
void ajouterRdv()
{
	//créer le pointeur rdv
	RDV *ptr;
	//Allocation dynamique 
	ptr = (RDV *) malloc(sizeof(RDV));
	//saisie des données
	printf("\n\t\t Donnez votre nom : ");
	fflush(stdin);
	gets(ptr->nom);
	
	printf("\n\t\t Donnez votre prenom : ");
	fflush(stdin);
	gets(ptr->prenom);
	
	printf("\n\t\t Donnez le lieu du Rendez-vous : ");
	fflush(stdin);
	gets(ptr->lieu);
	
	printf("\n\t\t Donnez le jour : ");
	fflush(stdin);
	scanf("%d",&ptr->jour);
	
	printf("\n\t\t Donnez le mois : ");
	fflush(stdin);
	scanf("%d",&ptr->mois);
	
	printf("\n\t\t Donnez votre annee : ");
	fflush(stdin);
	scanf("%d",&ptr->annee);
	
	printf("\n\t\t Donnez l'heure : ");
	fflush(stdin);
	scanf("%d",&ptr->heure);
	
	printf("\n\t\t Donnez les minutes : ");
	fflush(stdin);
	scanf("%d",&ptr->minute);

	
	
	printf("\n\t\t Donnez votre numero : ");
	fflush(stdin);
	scanf("%d",&ptr->numero);
	
	//insertion et mise à jour des liens  
	if (teteListe == NULL) 
	{ 
	teteListe = ptr ;  
	ptr ->suivant = NULL;  
	} else { 
	//aller à la fin de la liste  
	RDV *p = teteListe ;  
	while (p->suivant != NULL) 
	{ 
	p = p->suivant ; 
	} 
	p->suivant = ptr ;  
	ptr->suivant = NULL;  
	} 
	printf("\n\t\t _____ INSERTION REUSSIE _____\n"); 
} 
//=========================================================================================================================================================
//===============================================================LISTER LES RDV============================================================================
void listerRdvs(){
	// déclarer mon pointeur de type rdv
RDV *ptr;
	// Initialiser le pointeur à la tête de liste
ptr = teteListe;
	// Afficher les infos
while(ptr !=NULL)
{
	printf("\n\t\t ================== RENDEZ-VOUS SUIVANT =====================");
	printf("\n\n\t\t Nom : %s",ptr->nom);
	printf("\n\t\t Prenom : %s",ptr->prenom);
	printf("\n\t\t Lieu : %s",ptr->lieu);
	printf("\n\t\t Date : %d/%d/%d",ptr->jour,ptr->mois,ptr->annee);
	printf("\n\t\t Horaire : %dh%d ",ptr->heure,ptr->minute);
	printf("\n\t\t Numero : %d",ptr->numero);
	ptr = ptr->suivant;
}	 
} 
//=========================================================================================================================================================
//=================================================================SUPPRIMER DES RDV==============================================================
void supprimerRdv()
{
//déclarer un pointeur de parcours
RDV *ptr;
RDV *prec;
//déclarer un numéro de personne à rechercher
int numRech;
printf("\n\t\t Donner le numero de la personne que vous recherchez : ");
scanf("%d",&numRech);
//parcourir la liste
ptr = teteListe;
prec = ptr;
while(ptr !=NULL)
{
	//Tester les numéros
	if(ptr-> numero == numRech)
	{
		//s'il y égalité sur les numéros recherchés on supprimer la personne selon sa position
		if(ptr == teteListe)
		{
			//En tête de liste
			teteListe = ptr->suivant;
			free(ptr);
		}
		else if (ptr->suivant ==NULL)
		{
			//En queue de liste
			prec->suivant =NULL;
			free(ptr);
		}
		else
		{
			//en milieu de liste
			prec->suivant=ptr->suivant;
			free(ptr);	
		}
		printf("\n\t\t ===================SUPPRESSION REUSSI==================== \n");
		break;
	}
	else
	{
		prec = ptr;
		ptr = ptr->suivant;	
	}
}
} 
//==========================================================================A FAIRE=================================================
void prochainsRdvs()
{
int h, min, s, day, mois, an;
time_t now;

// Renvoie l'heure actuelle
time(&now);
// Convertir au format heure locale
printf("\n\t\t Aujourd'hui est : %s", ctime(&now));
struct tm *local = localtime(&now);
h = local->tm_hour;
min = local->tm_min;
s = local->tm_sec;
day = local->tm_mday;
mois = local->tm_mon + 1;
an = local->tm_year + 1900;
printf("\n\t\t L'heure : %02d:%02d:%02d", h, min, s);
// Afficher la date courante printf("\n\t\t La date : %02d/%02d/%d\n", day, mois, an);
//declarer un pointeur de type RDV
RDV *ptr;
//intialiser la aÂ  teteListe
ptr = teteListe;
//parcourir les personnes avec While
while (ptr !=NULL) {
//afficher les infos
if( ptr->annee > an
	or (ptr->annee == an and ptr->mois > mois)
	or (ptr->annee == an and ptr->mois == mois and ptr->jour > day))
 	{
	printf("\n\t\t rdv numro : %d", ptr->numero);
	printf("\n\t\t Nom : %s", ptr->nom);
	printf("\n\t\t Prenom : %s", ptr->prenom);
	printf("\n\t\t Date : %d/%d/%d", ptr->jour,ptr->mois,ptr->annee); 
		printf("\n\t\t Horaire : %dh%d ",ptr->heure,ptr->minute);
	printf("\n\t\t Lieu : %s", ptr->lieu); }
	ptr = ptr->suivant;
	}


} 

//===========================================================================DEPLACER RDV======================================
void deplacerRdv(){
RDV *prec,*ptr,*ptr2;  
int num1, num2,temp ;  

printf("\n Donner le numero de la personne :");  
scanf("%d", & num1); 

int trouve =0; 
ptr = teteListe ;
int jour; 
int mois;
int annee; 
int heure;
int minute;

	while (ptr!= NULL && trouve ==0)
	{ 
		if (ptr->numero == num1) 
		{ 
			trouve = 1;  
		}
		else 
		{ 
			ptr =ptr->suivant; 
		} 
	} 
	if (trouve == 0 ) 
	{ 
	printf("\n La personne n'a pas ete trouvee, echec de deplacement de rdv");  
	} 
	else
	{
	printf("\n\t\t ================== Voici la personne selectionnee =====================");
	printf("\n\t\t Nom : %s",ptr->nom);
	printf("\n\t\t Prenom : %s",ptr->prenom);
	printf("\n\t\t Lieu : %s",ptr->lieu);
	printf("\n\t\t Date : %d/%d/%d",ptr->jour,ptr->mois,ptr->annee);
	printf("\n\t\t Horaire %dh%d",ptr->heure,ptr->minute);
	printf("\n\t\t Numero : %d",ptr->numero);
	
	printf("\n\t\t Donner un nouveau jour de rdv : ");
	scanf("%d",&jour);
	
	ptr->jour = jour;
	
	printf("\n\t\t Donner un nouveau mois de rdv : ");
		scanf("%d",&mois);
	
	ptr->mois = mois;
	
	printf("\n\t\t Donner une nouvelle annee de rdv : ");
		scanf("%d",&annee);
	
	ptr->annee = annee;
	
		printf("\n\t\t Donner une nouvelle heure de rdv : ");
		scanf("%d",&heure);
	
	ptr->heure = heure;
	
		printf("\n\t\t Donner les minutes du rdv : ");
		scanf("%d",&minute);
	
	ptr->minute = minute;
	
	printf("\n\t\t Voici la nouvelle date  : %d/%d/%d a %dh%d ",ptr->jour,ptr->mois,ptr->annee,ptr->heure,ptr->minute);
	}
} 
//==========================================================================NOMBRE DE RDV==================================================
int NbRdvs()
{
	//déclarer un pointeur de type Guichet 
RDV *ptr ; 
int cpt = 0;  
//initialiser le pointeur à teteListe  
ptr = teteListe ; 
//parcourir et compter les personnes  
while (ptr != NULL) 
{ 
ptr= ptr->suivant;  
cpt ++ ; 
} 
//retourner le nombre de personnes  
return cpt;  
} 
//=================================================================================================================================================
void listerRdvsJoursNbs()
{
RDV *prec,*ptr,*ptr2;  
int num1, num2,temp ;  
int trouve =0; 
ptr = teteListe ;
int jour; 
int mois;
int annee; 

printf("\n Donner le jour : ");  
scanf("%d",&jour); 
printf("\n Donner le mois : ");  
scanf("%d",&mois); 
printf("\n Donner le annee : ");  
scanf("%d",&annee); 

	while (ptr!= NULL )
	{ 
		if (ptr->jour == jour && ptr->mois == mois && ptr->annee == annee) 
		{ 
			printf("\n\t\t ================== Voici la personne selectionnee =====================");
							printf("\n\t\t Nom : %s",ptr->nom);
							printf("\n\t\t Prenom : %s",ptr->prenom);
							printf("\n\t\t Lieu : %s",ptr->lieu);
							printf("\n\t\t Date : %d/%d/%d",ptr->jour,ptr->mois,ptr->annee);
							printf("\n\t\t Horaire : %dh%d",ptr->heure,ptr->minute);
							printf("\n\t\t Numero : %d",ptr->numero);
							trouve = 1; 
		}
		ptr =ptr->suivant; 
		
	
	} 
	if (trouve == 0 ) 
	{ 
	  printf("Il n'y pas de RDV a cette date");
	} 
	
}
//====================================================================================================================================
//==========================================================================SAUVEGARDER===============================================
void save()
{
	FILE * f ;  
RDV *ptr = teteListe ;  
f = fopen("rdv.txt", "w");  
while (ptr != NULL) 
{ 
fwrite(ptr, 1, sizeof(RDV), f); 
ptr=ptr->suivant;   
} 
fclose(f); 
} 
//=========================================================================================================================================
//=============================================================================CHARGER UN FICHIER===========================================
void load()
{
FILE *f;
    RDV *ptr;
    f = fopen("RDV.txt", "r");
    teteListe = NULL;
    while (!feof(f))
    {
        ptr = (RDV *)malloc(sizeof(RDV));
        fread(ptr, 1, sizeof(RDV), f);
        if (feof(f))
            break;
        //insertion de la personne lue binairement du fichier
        //recopie code insertion
        if (teteListe == NULL)
        {
            teteListe = ptr;
            ptr->suivant = NULL;
        }
        else
        {
            //aller Ã  la fin de la liste
            RDV *p = teteListe;
            while (p->suivant != NULL)
            {
                p = p->suivant;
            }
            p->suivant = ptr;
            ptr->suivant = NULL;
        }
    }
    fclose(f);
 
} 
//======================================================================================
void menu (){
	int choix = 0;
	
	do{
		system("cls");
		printf("\n\t\t ============================PLANNING DE RENDEZ-VOUS============================");
		printf("\n\t\t 1. Ajouter un rdv");
		printf("\n\t\t 2. Lister les rdv");
		printf("\n\t\t 3. Supprimer un rdv");
		printf("\n\t\t 4. Prochain rdv");
		printf("\n\t\t 5. Deplacer un rdv");
		printf("\n\t\t 6. Nombre de rdv");
		printf("\n\t\t 7. Lister les rdv par jour");
		printf("\n\t\t 8. Sauvegarder");
		printf("\n\t\t 9. Chargement");
		printf("\n\t\t 0. Quitter");
		printf("\n\t\t Votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1 : ajouterRdv(); break; //fait
			case 2 : listerRdvs(); break; //fait
			case 3 : supprimerRdv(); break;//fait
			case 4 : prochainsRdvs(); break;//fait
			case 5 : deplacerRdv(); break; //fait
			case 6 : printf("\n\t\t Nombre de rdv : %d \n", NbRdvs()); break; //fait 
			case 7 : listerRdvsJoursNbs(); break; //fait
			case 8 : save(); break; //fait
			case 9 : load(); break;	//fait
		}
		system("pause");
		system("cls");
	} while(choix!=0);
} 

int main (){ 
menu();
  

return 0;  

} 
