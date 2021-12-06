#include <stdio.h>
#include <stdlib.h>

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

void codificaLegitimatii(int nrStudenti, Student studenti[], int legitimatiiCodificate[], int r, int key) {
    for (int i = 0 ; i < nrStudenti ; i++) {
        legitimatiiCodificate[i] = codificaLegitimatie(studenti[i].nrLegitimatie, r, key);
    }
}

void decToBin(int x, FILE *fout) {
    if(x) {
        decToBin(x / 2, fout);
        fprintf(fout, "%d", x % 2);
    }
}

int binToDec(int x) {
    int legitimatieDecimala = 0, e = 1;
    while(x) {
        legitimatieDecimala += ((x % 10) * e);
        e *= 2;
        x /= 10;
    }

    return legitimatieDecimala;
}

void scrieLegitimatiiBinare(int nrStudenti, int legitimatiiCodificate[], FILE *fout) {
    for (int i = 0 ; i < nrStudenti ; i++) {
        decToBin(legitimatiiCodificate[i], fout);
        fprintf(fout, "\n");
    }
}

int citireDecodificata(int nrLinie, FILE *fin, int r, int key) {
    char buffer[32];

    for (int i = 0 ; i < nrLinie - 1 ; i++) {
        fgets(buffer, 32, fin);
    }

    fscanf(fin, "%s", buffer); // aici se afla legitimatia de la nrLinie

    int nrLegitimatie = atoi(buffer); // itoa, atol, ltoa
    nrLegitimatie = binToDec(nrLegitimatie);
    nrLegitimatie = decodificaLegitimatie(nrLegitimatie, r, key);
    return nrLegitimatie;
}

int main() {
    int nrStudenti = 4;
    int r = 3;
    int key = 5;
    Student studenti[10];
    int legitimatiiCodificate[10];

    FILE *fin = fopen("studenti.txt", "r");
    FILE *fout = fopen("legitimatii.txt", "w");

    citireStudenti(nrStudenti, studenti, fin);
    codificaLegitimatii(nrStudenti, studenti, legitimatiiCodificate, r, key);
    scrieLegitimatiiBinare(nrStudenti, legitimatiiCodificate, fout);

    fclose(fin);
    fclose(fout);
    FILE *finBin = fopen("legitimatii.txt", "r");

    int x = citireDecodificata(2, finBin, r, key);
    printf("%d", x);

    fclose(finBin);


    return 0;
}