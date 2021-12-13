#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    float debit; // 32 de biti
    unsigned char biti[4];
} octet;

typedef struct {
    char nume[40]; // 1 byte
    octet debit_cont; // 4 bytes
    unsigned int codificat; // 4 bytes
    unsigned int stare_indatorare : 1; // 4 bytes
} Client;

void citire(int nrClienti, Client client[]) {
    for(int i = 0 ; i < nrClienti ; i++) {
        printf("Numele clientului %d: ", i + 1);
        scanf("%s", client[i].nume);

        printf("Debit clientului %d: ", i + 1);
        scanf("%f", &client[i].debit_cont.debit);

        unsigned int validareCitire = 0;
        unsigned int stareIndatorare;
        printf("Starea de indatorare a clientului %d: ", i + 1);
        scanf("%u", &stareIndatorare);
        if (stareIndatorare <= 1) {
            validareCitire = 1;
        } else {
            printf("Stare indatorare (0-neindatorat / 1-inbdatorat) gresita!\n Tastati din nou: ");
            while (!validareCitire) {
                scanf("%u", &stareIndatorare);
                if (stareIndatorare <= 1) {
                    validareCitire = 1;
                } else {
                    printf("Stare indatorare (0-neindatorat / 1-inbdatorat) gresita!\n Tastati din nou: ");
                }
            }
        }
        client[i].stare_indatorare = stareIndatorare;
    }
}

unsigned int codificare(unsigned char octet) {
    unsigned int cnt = 0;
    while(octet) {
        if((octet & 1) == 0) cnt++;
        octet >>= 1; // octet = octet >> 1;
    }
    return cnt;
}

void codifica(int nrClienti, Client client[]) {
//    for(int i = 0 ; i < 4 ; i++)
//        printf("bitul %d este: %03x\n", i, client[0].debit_cont.biti[i]);

    for(int i = 0 ; i < nrClienti ; i++) {
        client[i].codificat = codificare(client[i].debit_cont.biti[0]) + codificare(client[i].debit_cont.biti[3]);
    }
}

// Ordine afisare: 1. clienti indatorati, debit > 1000; 2. clienti indatorati, debit <= 1000; 3. clienti neindatorati
int cmp(const void* clientA, const void* clientB) {
    Client* client1 = (Client*)clientA;
    Client* client2 = (Client*)clientB;

    /*
     * cmp(a, b) < 0 => ordinea dorita - nu facem schimbari
     * cmp(a, b) = 0 => elementele sunt egale - nu facem schimbari
     * cmp(a, b) > 0 => ordinea nu este cea dorita - facem schimbare
     */

    if(client1->stare_indatorare == 0 && client2->stare_indatorare == 0) return 0;
    if(client1->stare_indatorare == 1 && client2->stare_indatorare == 0) return -1;
    if(client1->stare_indatorare == 0 && client2->stare_indatorare == 1) return 1;

    if(client1->stare_indatorare == 1 && client2->stare_indatorare == 1)
    {
        if(client1->debit_cont.debit > 1000 && client2->debit_cont.debit <= 1000) return -1;
        if(client1->debit_cont.debit > 1000 && client2->debit_cont.debit > 1000) return 0;
        if(client1->debit_cont.debit <= 1000 && client2->debit_cont.debit <= 1000) return 0;
        return 1; // if(client1->debit_cont.debit <= 1000 && client2->debit_cont.debit > 1000)
    }
}

void afisare(int nrClienti, Client client[]) {
    for(int i = 0 ; i < nrClienti ; i++)
        printf("%s %.2f %u\n", client[i].nume, client[i].debit_cont.debit, client[i].stare_indatorare);
}

void sortare(int nrClienti, Client client[]) {
    // qsort(obj, nrElem, sizeof(Elem), cmp)
    qsort(client, nrClienti, sizeof(Client), cmp);
    afisare(nrClienti, client);
}

void citireClienti(FILE* fin) {
    char nume[40];
    char debit[6];
    char stareIndatorare;

    while(fscanf(fin,"%s %s %c", nume, debit, &stareIndatorare) == 3) {
        int validareCitireDate = 1;

        if(strcmp(nume, "-") == 0)
        {
            validareCitireDate = 0;
            printf("Lipseste numele! ");
        }
        if(strcmp(debit, "-") == 0) {
            validareCitireDate = 0;
            printf("Lipseste debitul! ");
        }
        if(stareIndatorare == '-') {
            validareCitireDate = 0;
            printf("Nu stim daca este dator!");
        }

        if(validareCitireDate) {
            if(stareIndatorare == '1'){
                int deb = atoi(debit);
                if(deb > 200)
                    printf("%s\n", nume);
            }
        }
        else printf("\n");
    }

}

int main() {
    int nrClienti;
    scanf("%d", &nrClienti);
    Client client[nrClienti];

    citire(nrClienti, client);
    codifica(nrClienti, client);
    sortare(nrClienti, client);

    printf("\n\n\n\n");

    FILE* fin = fopen("clienti.txt", "r");
    if (fin != NULL) {
        citireClienti(fin);
        fclose(fin);
    } else {
        printf("Eroare la deschiderea fisierului!\n");
    }
    return 0;
}