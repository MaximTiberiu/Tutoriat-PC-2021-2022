
# Tutoriat PC 2021-2022

> Tutoriatul #02

## Curpins
* [Operatori pe biți](#operatori-pe-biți)
* [Interschimbarea a două valori](#interschimbarea-a-două-valori)
* [Deplasarea circulară](#deplasarea-circulară)
* [Testarea valorii unui bit](#testarea-valorii-unui-bit)
* [Setarea și resetarea valorii unui bit](#setarea-și-resetarea-valorii-unui-bit)
* [Comutarea valorii unui bit](#comutarea-valorii-unui-bit)
* [Probleme propuse](#probleme-propuse)

## Operatori pe biți

Există șase operatori care se folosesc în lucrul cu biții:

- & (și logic);
- | (sau logic);
- ^ (sau exclusiv/xor logic);
- << (shiftare la stânga);
-  \>> (shiftare la dreapta);
- ~ (nu logic).

#### ȘI Logic - & 

| & | 0 | 1 |
|--|--|--|
| 0 | 0 | 0 |
| 1 | 0  | 1 |

#### SAU Logic - |

| \| | 0 | 1 |
|--|--|--|
| 0 | 0 | 1 |
| 1 | 1  | 1 |

#### XOR Logic - ^

| ^ | 0 | 1 |
|--|--|--|
| 0 | 0 | 1 |
| 1 | 1  | 0 |

#### NU Logic - ~

|  | 0 | 1 |
|--|--|--|
| ~ | 1 | 0 |

Operatorii de shiftare la stânga sau la dreapta au următoarea specificație: deplasează la stânga, respectiv la dreapta, un număr de biți dat.

De exemplu: vom lua numărul 7 și îl vom shifta la stânga și la dreapta cu 2 biți.

#### La stânga:
| 7 | 0 | 0 | 1 | 1 | 1 |
|--|--|--|--|--|--|
| 7<<2 | 1 | 1 | 1 | 0 | 0 |

#### La dreapta:
| 7 | 0 | 0 | 1 | 1 | 1 |
|--|--|--|--|--|--|
| 7>>2 | 0 | 0 | 0 | 0 | 1 |

## Interschimbarea a două valori
Se face cu ajutorul operatorului **^**:

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

## Deplasarea circulară
Operațiile realizate cu ajutorul << și />> au un cost - pierderea de biți.

Să luăm numărul 93<sub>(10)</sub> echivalent cu 01011101<sub>(2)</sub> drept exemplu. Dorim să îl deplasăm la stânga, respectiv la dreapta cu 3 poziții.

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | **0** | **1** | **0** | 1 | 1 | *1* | *0* | *1* |
| x<<3 | 1 | 1 | 1 | 0 | 1 | **0** | **0** | **0** |
| x>>3 | *0* | *0* | *0* | 0 | 1 | 0 | 1 | 1 |

La ce neferim prin deplasare circulară? Dorim să eliminăm acest cost al pierderii de biți. Să obținem ceva de genul:
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | **0** | **1** | **0** | 1 | 1 | *1* | *0* | *1* |
| x RotL 3 | 1 | 1 | 1 | 0 | 1 | **0** | **1** | **0** |
| x RotR 3 | *1* | *0* | *1* | 0 | 1 | 0 | 1 | 1 |

Să definim problema noastră. Variabila x stochează date de tipul TDI. Dorim să realizăm o deplasare circulară a valorii stocate în variabila x, cu p poziții. Algoritmul de rezolvare este format din trei operații:

- x << p;
- x >> (8 * sizeof(TDI) - p);
- aplicarea operatorului sau pentru cele două valori de mai sus. 

Exemplu pentru x = 93 (unsigned char) și p = 3
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 1 |
| x<<p | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 0 |
| x>>(8*sizeof(u_char)-p) | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| (x<<p)\|(x>>(8*sizeof(u_char)-p)) | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 0 |

Analog se realizează și deplasarea circulară către dreapta.
Cum putem rezuma tot ce am descris anterior în cod C?

    // deplasare circulară la stânga
    x = (x << p) | (x >> (8 * sizeof(TDI) - p))
    // deplasare circulară la dreapta
    x = (x >> p) | (x << (8 * sizeof(TDI) - p))
  
## Testarea valorii unui bit
Pentru a testa valoarea unui bit aflat la o anumită poziție în reprezentarea binară a numărului, trebuie să aplicăm operația ȘI logică pe număr și un bit de 1 aflat pe poziția respectivă.

Exemplu: x = 93, b = 3;
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | 0 | 1 | 0 | 1 |**1** | 1 | 0 | 1 |
| 1 << b | 0 | 0 | 0 | 0 | **1** | 0 | 0 | 0 |
| x & (1 << b) | 0 | 0 | 0 | 0 | **1** | 0 | 0 | 0 |

Dacă numărul rezultat este diferit de 0, însemnă că bitul aflat la poziția b este 1. Altfel, este 0. Deci în cod C, vom scrie:

    valoare_bit = (x & (1 << b)) != 0;
## Setarea și resetarea valorii unui bit

Pentru a seta/reseta valoarea unui bit aflat la o anumită poziție în reprezentarea binară a numărului, respectăm *cu aproximație* aceeași procedură precum cea de la testarea unui bit.

Pentru setare - valoare 1 pe acel bit - avem nevoie de SAU logic cu valoarea 1 la poziția dorită.

Exemplu: x = 93, b = 1;
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | 0 | 1 | 0 | 1 |1 | 1 | **0** | 1 |
| 1 << b | 0 | 0 | 0 | 0 | 0 | 0 | **1** | 0 |
| x \| (1 << b) | 0 | 1 | 0 | 1 | 1 | 1 | **1** | 0 |

Pentru resetare - valoare 0 pe acel bit - avem nevoie de ȘI logic cu valoarea 0 la poziția dorită.

Exemplu: x = 93, b = 4;
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | 0 | 1 | 0 | **1** |1 | 1 | 0 | 1 |
| ~(1 << b) | 1 | 1 | 1 | **0** | 1 | 1 | 1 | 1 |
| x & (~(1 << b)) | 0 | 1 | 0 | **0** | 1 | 1 | 0 | 1 |

Deci în cod C, vom scrie:

    // setare bit
    x = x | (1 << b);
    // resetare bit
    x = x & (~(1 << b));

## Comutarea valorii unui bit

Procedăm analog și pentru a comuta valoarea unui bit. Singura diferență o va consta operatorul. Cel care se potrivește pentru această operație este XOR. 

Exemplu: x = 93, b = 7;
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|--|--|--|--|--|--|--|--|--|
| x | **0** | 1 | 0 | 1 |1 | 1 | 0 | 1 |
| 1 << b | **1** | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| x ^ (1 << b) | **1** | 1 | 0 | 1 | 1 | 1 | 0 | 0 |

## Probleme propuse

1. Pentru valori întregi citite de la tastatură să se tiparească valoarea corespunzătoare în binar.
2. Se citesc 2 numere întregi, x și n, unde n este între 0 si 15. Să se afișeze: bitul n din x, numărul x în care se seteaza bitul n, numărul x în care se șterge bitul n, numărul x în care se complementează bitul n.
3. Se citesc întregii x, y, n, p. Să se copieze în x, începând din poziția p, ultimii n biți din y și să se afișeze noua valoare a lui x.
4. Scrieți un program care primește ca input de la tastatură scrierea unui număr în baza 2 și calculează direct scrierea acestuia în baza 16 (nu mai trece prin baza intermediară 10). Realizați acest lucru inversând cele două baze (input – scrierea în baza 16, output – scrierea în baza 2).
5. Se citesc numere naturale până la întâlnirea numărului 0. Să se afișeze toate perechile de numere consecutive citite cu proprietatea că al doilea număr reprezintă restul împărțirii primului număr la suma cifrelor sale.
6. Se citește de la tastatură un număr natural p. Să se determine toate perechile distincte de numere întregi (i,j,k) cu proprietatea că ele pot reprezenta laturile unui triunghi de perimetru p. Folosiți maxim două instrucțiuni for.