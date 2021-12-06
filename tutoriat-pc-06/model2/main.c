#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nrLegitimatie;
    char nume[30];
} Student;

void citireStudenti(int nrStudenti, Student studenti[], FILE *fin) {
    for (int i = 0 ; i < nrStudenti ; i++) {
        fscanf(fin, "%d %s", &studenti[i].nrLegitimatie, studenti[i].nume);
    }
}

int codificaLegitimatie(int nrLegitimatie, int r, int key) {
    int legitimatieCodificata = (nrLegitimatie << r) | (nrLegitimatie >> (8 * sizeof(int) - r)); // rotatie cu r biti la stanga
    legitimatieCodificata = legitimatieCodificata ^ key;

    return legitimatieCodificata;
}

int decodificaLegitimatie(int nrLegitimatie, int r, int key) {
    int legitimatieDecodificata = nrLegitimatie ^ key;
    legitimatieDecodificata = (legitimatieDecodificata >> r) | (legitimatieDecodificata << (8 * sizeof(int) - r)); // rotatie cu r biti la dreapta

    return legitimatieDecodificata;
}

void codificaDateStudenti(int nrStudenti, Student studenti[], Student studentiCodificati[], int r, int key) {
    for (int i = 0 ; i < nrStudenti ; i++) {
        // codifcare numarLegitimatie
        studentiCodificati[i].nrLegitimatie = codificaLegitimatie(studenti[i].nrLegitimatie, r, key);

        // codifcare nume
        strcpy(studentiCodificati[i].nume,  "\0");
        int len = strlen(studenti[i].nume); // char nume[30] = "abcd\0"
        for (int j = len - 1 ; j >= 0 ; j--) {
            studentiCodificati[i].nume[len - j - 1] = studenti[i].nume[j];
        }
        studentiCodificati[i].nume[len] = '\0';
    }
}


void scrieStudenti(int nrStudenti, Student studentiCodificati[], FILE *fout) {
    for (int i = 0 ; i < nrStudenti ; i++) {
        fprintf(fout, "%d %s\n", studentiCodificati[i].nrLegitimatie, studentiCodificati[i].nume);
    }
}

void citireFisierCodificat(int nrStudenti, FILE *fin, int r, int key) {
    int numarLegitimatie;
    char nume[31];
    char vocale[] = "aeiouAEIOU";

    for (int i = 0 ; i < nrStudenti ; i++) {
        fscanf(fin, "%d %s", &numarLegitimatie, nume);

        char ch = nume[strlen(nume) - 1]; // ultima litera din nume
        if (strchr(vocale, ch) != NULL) {
            int legitimatieDecodifcata = decodificaLegitimatie(numarLegitimatie, r, key);

            if (legitimatieDecodifcata % 3 == 0) {
                printf("%d ", legitimatieDecodifcata);

                int len = strlen(nume);
                char numeDecodificat[31];
                for (int j = len - 1 ; j >= 0 ; j--) {
                    numeDecodificat[len - j - 1] = nume[j];
                }
                numeDecodificat[len] = '\0';
                printf("%s\n", numeDecodificat);
            }
        }
    }
}

int main() {
    int nrStudenti = 4;
    int r = 3;
    int key = 5;
    Student studenti[10];
    Student studentiCodificati[10];

    FILE *fin = fopen("studenti.txt", "r");
    FILE *fout = fopen("stud_codif.txt", "w");

    citireStudenti(nrStudenti, studenti, fin);
    codificaDateStudenti(nrStudenti, studenti, studentiCodificati, r, key);
    scrieStudenti(nrStudenti, studentiCodificati, fout);

    fclose(fin);
    fclose(fout);

    FILE *fin_stud = fopen("stud_codif.txt", "r");
    citireFisierCodificat(nrStudenti, fin_stud, r, key);
    fclose(fin_stud);


    return 0;
}