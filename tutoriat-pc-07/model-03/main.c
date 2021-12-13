#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[30];
    unsigned int IBAN : 17;
    unsigned int stare_civila : 1;
    unsigned int bit_paritate : 1;
} Client;

void citire(int nrClienti, Client clienti[]) {
    for (int i = 0 ; i < nrClienti ; i++) {
        printf("Numele clientului %d: ", i + 1);
        scanf("%s", clienti[i].nume);

        unsigned int iban, stareCivila;
        unsigned int validareCitire = 0;
        printf("IBAN-ul clientului %d: ", i + 1);
        scanf("%u", &iban);

        if (iban < 100000) {
            validareCitire = 1;
        } else {
            printf("IBAN-ul este o valoare numerica de maxim 5 cifre!\n Tastati din nou: ");
            while(validareCitire == 0) {
                scanf("%u", &iban);
                if (iban < 100000) {
                    validareCitire = 1;
                } else {
                    printf("IBAN-ul este o valoare numerica de maxim 5 cifre!\n Tastati din nou: ");
                }
            }
        }
        clienti[i].IBAN = iban;

        validareCitire = 0;
        printf("Starea civila (0-necasatorit / 1-casatorit) a clientului %d: ", i + 1);
        scanf("%u", &stareCivila);
        if (stareCivila <= 1) {
            validareCitire = 1;
        } else {
            printf("Starea civila (0-necasatorit / 1-casatorit) gresita!\n Tastati din nou: ");
            while (!validareCitire) {
                scanf("%u", &stareCivila);
                if (stareCivila <= 1) {
                    validareCitire = 1;
                } else {
                    printf("Starea civila (0-necasatorit / 1-casatorit) gresita!\n Tastati din nou: ");
                }
            }
        }
        clienti[i].stare_civila = stareCivila;
    }
}

void afisare(int nrClienti, Client clienti[]) {
    for (int i = 0 ; i < nrClienti ; i++) {
        printf("%s %u %u %u\n", clienti[i].nume, clienti[i].IBAN, clienti[i].stare_civila, clienti[i].bit_paritate);
    }
}

unsigned int bitParitate(unsigned int iban) {
    unsigned int cnt = 0;
    while (iban) {
        if (iban & 1) {
            cnt++;
        }
        iban >>= 1; // iban = iban >> 1
    }
    if (cnt % 2 == 0) {
        return 0;
    }
    return 1;
}

void completareDate(int nrClienti, Client clienti[]) {
    for (int i = 0 ; i < nrClienti ; i++) {
        clienti[i].bit_paritate = bitParitate(clienti[i].IBAN);
    }
}

int cmpStareCivila(const void* clientA, const void* clientB) {
    Client *client1 = (Client*)clientA;
    Client *client2 = (Client*)clientB;
    return (client1->stare_civila - client2->stare_civila);
    /*
     * if (c1->stare_civila == 0 && c2->stare_civila == 1) return -1;
     * if (c1->stare_civila == 1 && c2->stare_civila == 0) return 1;
     * return 0; //if (c1->stare_civila == c2->stare_civila )
     */
}

void sortareStareCivila(int nrClienti, Client clienti[]) {
    qsort(clienti, nrClienti, sizeof(Client), cmpStareCivila);
    afisare(nrClienti, clienti);
}

unsigned int verificareNume(char nume[]) {
    int len = strlen(nume);
    char vocale[] = "aeiouAEIOU\0";

    int nrVocale = 0, nrConsoane = 0;
    for (int i = 0 ; i < len ; i++) {
        if (strchr("aeiouAEIOU", nume[i])) { // strchr(vocale, nume[i])
            nrVocale++;
        } else {
            nrConsoane++;
        }
    }
    if (nrConsoane > nrVocale) return 1;
    return 0;
}

void citireClienti(FILE *fin) {
    char nume[30];
    unsigned int IBAN;
    unsigned int stare_civila;

    while(fscanf(fin, "%s %u %u", nume, &IBAN, &stare_civila) == 3) {
        if (stare_civila == 0 && verificareNume(nume)) {
            printf("%s %u %u\n", nume, IBAN, bitParitate(IBAN));
        }
    }
}

int main() {
    int nrClienti;
    scanf("%d", &nrClienti);
    Client clienti[nrClienti];
    citire(nrClienti, clienti);
    completareDate(nrClienti, clienti);
    sortareStareCivila(nrClienti, clienti);
    afisare(nrClienti, clienti);
    FILE *fin = fopen("C:\\Users\\maxim\\Desktop\\Tutoriat-PC-2021-2022\\tutoriat-pc-07\\model-03\\cmake-build-debug\\clienti.txt", "r");
    citireClienti(fin);
    fclose(fin);
    return 0;
}
