# Varianta 1 - propunere

Fiind student la FMI, ai nevoie de un cont pe MoodleUB pentru a accesa materialele de la cursuri. Din cauza pandemiei, secretariatul nu mai poate trimite lista fizică cu credențialele șefului de grupă. Din acest motiv, secretariatul te roagă să implementezi o soluție prin care datele să ajungă în siguranță la studenți.

1. Construiește o structură care să stocheze prenumele, numele, grupa, username și parola.
2. Datele vor fi citite dintr-un fișier construit de către secretariat. Trebuie să implementezi o funcție.
3. Calculează numărul de studenți din fiecare grupă, și memorează aceste date în stucutura ta.
4. Acum că datele sunt introduse în sistem, trebuie codificate. Codificarea se face în următorul mod:
    - USERNAME:
        - trebuie inversate caracterele
        - codificare cu XOR pentru fiecare caracter folosind caracterele din câmpul nume 
            - ex: userCodificat[i] = userInversat[i] ^ nume[i % ((sizeof(nume) / sizeof(char))]
    - PAROLA:
        - pentru grupele pare
            - rotire cu r biți la stânga
        - pentru grupele impare
            - rotire cu r biți la dreapta
        - la final, XOR cu numărul grupei
5. Ca un student să își afle credențialele, secretariatul te mai roagă să dezvolți o funcție care primește grupa, și numărul studentului din grupa respectivă.
6. Și încă ceva... Seful de grupă are acces la toate username-urile conturilor. Avem nevoie de o funcție care primește numărul unei grupe și afișează numele, prenumele și username-ul studenților din grupa respectivă.

**OBSERVAȚII**
- parola este un număr întreg pozitiv, de 6 cifre.
- folosiți fișierul v1_date.in de pe GitHub pentru teste
