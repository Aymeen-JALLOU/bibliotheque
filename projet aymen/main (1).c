#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



typedef struct Books
{
    int Id;
    char titre[100];
    char Auteur[100];
    char description[100];
    char nom_utilisateur[100];
    float prix_Books;
    char category [100];
    int disponibilite;
    struct Books *next;
}Books;


/*-----------------function proto--------------------*/
void LibraryMenu(char []);
void affiche(Books* );
Books* UploadFileToList();
Books* AjoutBooks(Books* , Books* );
void UploadListToFile(Books* );
void SwapNodes(Books* , Books*);
void sortCategorie(Books*);
void sorttitle(Books*);
/*******************functions*******************/
void affiche(Books* p)
{
    Books *Liste = p;
    while(p!=NULL)
    {
        printf("\n<< la Books de matricule %d >> : %s || %s || %s || %s || %.2f || %s || %d\n",
                            Liste->Id, Liste->titre, Liste->Auteur,
                            Liste->description, Liste->nom_utilisateur,
                            Liste->prix_Books, Liste->category,
                            Liste->disponibilite);
        Liste = Liste->next;
    }
}

void LibraryMenu(char username[])
{
    Books *Liste = UploadFileToList();
    int choice;
    printf("\npress any key\n");
    system("pause");
    while(1)
    {
        system("pause");
        system("cls");
        printf("\n\tWelcome to the library!\n");
        printf("\t\tMenu:\n");
        printf("1. Search for a Books.\n2. Add a new Books.\n3. Remove an existing Books.\n4. Display all Bookss in the library.\n");
        printf("5. Modify. \n 6. Trie.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                int I;
                Books *tmp1 = Liste;
                char title_tmp[100], writer_tmp[30];
                system("cls");
                printf("\nWelcome to Car Search App\n");
                printf("\nMenu:\n");
                printf("1. Search by title.\n");
                printf("2. Search by writer.\n");
                printf("------------------------------------------");
                printf("\n\t\tEnter your choice: ");
                scanf("%d", &I);
                switch (I)
                {
                    case 1:{
                        printf("enter title you are looking for: (no space use \"-\")");
                        scanf("%s", title_tmp);
                        while (tmp1 != NULL)
                        {
                            if(!strcmp(title_tmp,tmp1->titre))
                            {
                                printf("\n<< la Books de matricule %d >> : %s %s %s %s %.2f %s %d\n",
                            tmp1->Id, tmp1->titre, tmp1->Auteur,
                            tmp1->description, tmp1->nom_utilisateur,
                            tmp1->prix_Books, tmp1->category,
                            tmp1->disponibilite);
                            }
                            tmp1 = tmp1->next;
                        }
                        system("pause");
                        break;
                    }
                    case 2:{
                        printf("enter writer you are looking for: (no space use \"-\")");
                        scanf("%s", writer_tmp);
                        while (tmp1 != NULL)
                        {
                            if(!strcmp(writer_tmp,tmp1->Auteur))
                            {
                                printf("\n<< la Books de matricule %d >> : %s %s %s %s %.2f %s %d\n",
                            tmp1->Id, tmp1->titre, tmp1->Auteur,
                            tmp1->description, tmp1->nom_utilisateur,
                            tmp1->prix_Books, tmp1->category,
                            tmp1->disponibilite);
                            }
                            tmp1 = tmp1->next;
                        }
                        system("pause");
                        break;
                    }
                    
                }
                break;
            }
            case 2:{
                Books *Add_book;
                Add_book = (Books*)malloc(sizeof(Books));
                system("cls");
                printf("\n");
                printf("\nEntrez l'ID livre : ");
                scanf("%d", &Add_book->Id);
                printf("Entrez le titre : ");
                scanf("%s", Add_book->titre);
                printf("Entrez l'auteur : ");
                scanf("%s", Add_book->Auteur);
                printf("Entrez la description : ");
                scanf("%s", Add_book->description);
                printf("Entrez le nom de utilisateur : ");
                scanf("%s", Add_book->nom_utilisateur);
                printf("Entrez le prix : ");
                scanf("%f", &Add_book->prix_Books);
                printf("Entrez la category : ");
                scanf("%s", Add_book->category);
                printf("dispo ou non(1,0) : ");
                scanf("%d", &Add_book->disponibilite);
                Liste = AjoutBooks(Liste,Add_book);
                UploadListToFile(Liste);
                break;
            }
            case 3:{
                Books *sup1 = Liste, *sup2;
                int choice_delete;
                system("cls");
                printf ("***--------------------------------------***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf ("***---    BIENVENUE DANS mon projet   ---***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf ("***------Veuillez supprimer via ---------***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf ("***   1. par ID                          ***\n") ;
                printf ("***   0. RETURN                          ***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf ("***--------------------------------------***\n") ;
                printf("votre choix: \t\t");
                scanf("%d", &choice_delete);
                switch (choice_delete)
                {
                case 1:{
                    int ID_delete;
                    printf("\nEnter the ID to delete:\n");
                    scanf("%d", &ID_delete);
                    Books *sup1 = Liste, *sup2 = NULL;
                    while (sup1 != NULL){
                        if (sup1->Id == ID_delete) {
                        if (sup2 != NULL) {
                            sup2->next = sup1->next;}
                        else {
                            Liste = sup1->next;
                        }
                        printf("\nDeletion successful!!!\n");
                        free(sup1);
                        break;
                    }
                    sup2 = sup1;
                    sup1 = sup1->next;
                }
                }
                break;
                }
                UploadListToFile(Liste);
                break;
            }
            case 4:{
                affiche(Liste);
                printf("press to back.");
                system("pause");
                break;
            }
            case 5:{
                int id;
                printf("\nentrer le ID de la Books vous voulez modifiez: \n");
                scanf("%d",&id);
                if(1)
                {
                    Books* tmp = Liste;
                    while(tmp != NULL)
                    {
                        if(tmp->Id == id)
                        {
                            printf("entrer les nouvelles donnees de la Books de Id : %d\n", tmp->Id);                            
                            printf("Entrez le titre : ");
                            scanf("%s", tmp->titre);
                            printf("Entrez l'auteur : ");
                            scanf("%s", tmp->Auteur);
                            printf("Entrez la description : ");
                            scanf("%s", tmp->description);
                            printf("Entrez le nom de utilisateur : ");
                            scanf("%s", tmp->nom_utilisateur);
                            printf("Entrez le prix : ");
                            scanf("%f", &tmp->prix_Books);
                            printf("Entrez la category : ");
                            scanf("%s", tmp->category);
                            printf("dispo ou non(1,0) : ");
                            scanf("%d", &tmp->disponibilite);
                            break;
                        }
                        tmp = tmp->next;
                    }
                    printf("\nUploaded Successfully.\n");
                    UploadListToFile(Liste);
                }
                break;
            }
            case 6:{
                int c;
                printf("\nsort by:\n");
                printf("1- category.\n");
                printf("2- title. \n");
                printf("your choice: ");
                scanf("%d", &c);
                switch (c)
                {
                    case 1:{
                        sortCategorie(Liste);
                        affiche(Liste);
                        UploadListToFile(Liste);
                        break;
                    }
                    
                
                    case 2:{
                        sorttitle(Liste);
                        affiche(Liste);
                        UploadListToFile(Liste);
                        break;
                    }
                }
                break;
            }
        }
    }
    system("pause");
}
Books* UploadFileToList() {
    Books* Liste = NULL;
    Books* p = NULL;
    FILE* file = fopen("CSV1.txt", "r");
    if (!file) {
        printf("Error opening the file.");
        return NULL;
    }

    while (1) {
        p = (Books*)malloc(sizeof(Books));
        if (!p) {
            printf("Memory allocation failed.");
            fclose(file);
            free(Liste);
            return NULL;
        }
        int result = fscanf(file, "%d %s %s %s %s %f %s %d\n",
                            &p->Id, p->titre, p->Auteur,
                            p->description, p->nom_utilisateur,
                            &p->prix_Books, p->category,
                            &p->disponibilite);
        if (result != 8) {
            free(p);
            break;
        }
        p->next = Liste;
        Liste = p;
    }
    fclose(file);
    return Liste;
}
Books* AjoutBooks(Books* Liste, Books* livre) {
    (Liste) = UploadFileToList();
    livre->next = (Liste);
    (Liste) = livre;
    return (Liste);
}

void SwapNodes(Books* a, Books* b) {
    int temp_id = a->Id;
    a->Id = b->Id;
    b->Id = temp_id;
    char temp_titre[100];
    strcpy(temp_titre, a->titre);
    strcpy(a->titre, b->titre);
    strcpy(b->titre, temp_titre);
    char temp_auteur[100];
    strcpy(temp_auteur, a->Auteur);
    strcpy(a->Auteur, b->Auteur);
    strcpy(b->Auteur, temp_auteur);
    char temp_description[100];
    strcpy(temp_description, a->description);
    strcpy(a->description, b->description);
    strcpy(b->description, temp_description);
    char temp_nom[100];
    strcpy(temp_nom, a->nom_utilisateur);
    strcpy(a->nom_utilisateur, b->nom_utilisateur);
    strcpy(b->nom_utilisateur, temp_nom);
    float temp_float = a->prix_Books;
    a->prix_Books = b->prix_Books;
    b->prix_Books = temp_float;
    char temp_cat[15];
    strcpy(temp_cat, a->category);
    strcpy(a->category, b->category);
    strcpy(b->category, temp_cat);
    int temp_dispo = a->disponibilite;
    a->disponibilite= b->disponibilite;
    b->disponibilite = temp_dispo;
}

void UploadListToFile(Books* Liste) {
    FILE* file = fopen("CSV1.txt", "w");
    Books* current = (Liste);
    if (file == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    while (current != NULL) {
        fprintf(file, "%d %s %s %s %s %f %s %d\n",
                            current->Id, current->titre, current->Auteur,
                            current->description, current->nom_utilisateur,
                            current->prix_Books, current->category,
                            current->disponibilite);
        current = current->next;
    }
    printf("\nUpload successfully");
    fclose(file);
}
void main()
{
    char username[10];
    char user_file[10];
    printf("entrer le nom de utilisateur: ");
    scanf("%s", username);
    FILE *check = fopen("users.txt","rt");
    if(check == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    int found=0;
    while (fscanf(check, "%s", user_file) != EOF)
    {
        if(!strcmp(username,user_file)){
            found=1;
            break;
        }
    }
    if(found)
    {
        printf("%s logged succefully!!\n", username);
        LibraryMenu(username);
    }
    else
        printf("not found");
}

void sortCategorie(Books* Liste) {
    int swapped;
    Books* ptr1;
    Books* lptr = NULL;

    // Checking for empty list
    if (Liste == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = Liste;

        while (ptr1->next != lptr) {
            // Compare brands of adjacent nodes and swap if necessary
            if (strcmp(ptr1->category, ptr1->next->category) > 0) {
                SwapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void sorttitle(Books* Liste) {
    int swapped;
    Books* ptr1;
    Books* lptr = NULL;

    // Checking for empty list
    if (Liste == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = Liste;

        while (ptr1->next != lptr) {
            // Compare brands of adjacent nodes and swap if necessary
            if (strcmp(ptr1->titre, ptr1->next->titre) > 0) {
                SwapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

