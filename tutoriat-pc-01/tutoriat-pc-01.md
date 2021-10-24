
# Tutoriat PC 2021-2022

> Tutoriatul #01

## Curpins
* [Introducere](#introducere)
* [GCC și VSC](#gcc-și-vsc)
* [GitHub](#github)
* [Comenzi de bază în terminal](#comenzi-de-bază-în-terminal)
* [Comenzi de bază git](#comenzi-de-bază-git)
* [Primul program C](#primul-program-c)
* [Probleme propuse](#probleme-propuse)

## Introducere
*Bine ai venit la tutoriatul de Programarea Calculatoarelor!*

Pentru această disciplină îți recomand utilizarea sistemului de operare Linux. Este super util să lucrăm cu programele C direct din terminalul sistemului Linux. În acest fel, te vei 
Dacă folosiți un sistem de operare Linux, este foarte ok. Dacă folosiți Windows sau OS X, se poate configura o mașină virtuală care să ruleze Linux. Configurarea unei astfel de mașini este ușoară. Avem nevoie doar de un software care poate realiza mașini virtuale (ex. Oracle VirtualBox) și de fișierul .iso al unei versiuni Linux (ex. Ubuntu). Pentru versiunea de Ubuntu, recomand folosirea celei mai noi versiuni **LTS**.

*Linkuri utile:*
 - [Descarcă VirtualBox de aici](https://www.virtualbox.org/wiki/Downloads) 
 - [Descarcă Ubuntu 20.04 LTS](https://ubuntu.com/download/desktop)

Dacă totuși nu dorești să lucrezi cu Linux, recomand un IDE de la JetBrains pentru C/C++. Acesta este [CLion](https://www.jetbrains.com/clion/download/?source=google&medium=cpc&campaign=11964013813&gclid=Cj0KCQjwiNSLBhCPARIsAKNS4_c23wCEt3CXrmWDisLsUrtY4SBUm3jP6SDEdLGXAlqd-L9EbHrza7saAqtMEALw_wcB#section=windows) și **necesită licență**. Cu adresa instituțională (@s.unibuc.ro) ai posibilitatea să îți activezi o licență anuală ca să beneficiezi de toate softurile celor de la JetBrains.
## GCC și VSC
De regulă, nu trebuie instalat nimic pentru a compila programe C/C++. Pentru a verifica acest lucru, deschidem terminalul și rulăm următoarea comandă:

    gcc --version
Dacă îți va afișa ceva de genul acesta - **gcc (Ubuntu 9,3,0-17ubuntu1~20.04) 9.3.0** - totul este în regulă. Dacă nu, atunci trebuie să instalăm gcc, folosind următoarea comandă:

    sudo apt install gcc
Acum nu ne rămâne decât să folosim un editor de text pentru a scrie programele C. Dacă vrei să rămâi în zona Linux, folosește **vim**  sau **nano**. Eu recomand Visual Studio Code, care poate fi instalat folosind următoarea comandă în terminal:

    sudo snap install --classic code

EXTRA: Cum modifici mărimea fontului în zona de terminal a VSC?
Accesezi zona Command Palette (Ctrl+Shift+P) și tastezi *Open Settings (JSON)*. Va trebui să scrii o linie de cod JSON, înlocuind font-size cu valoarea dorită de tine. Nu uita să pui o virgulă pe ultima linie care era înainte de linia scrisă de tine (dacă este cazul).

    "terminal.integrated.fontSize": font-size
## Git
Este foarte important să învățăm să folosim sisteme version control, precum Git. Dacă te-ai decis să folosești Linux pentru această materie, instalarea lui este relativ ușoară. Însă mai întâi, vom verifica dacă este instalat. Te-ai prins: comanda se aseamană cu cea de la gcc!

    git --version
   Dacă nu este instalat (ceea ce este foarte probabil) scrie următoarele linii de cod în terminal:

    sudo apt update
    sudo apt install git
    sudo apt --version
  Gata! Am terminat de instalat git pe Linux. Dacă folosești Windows, poți descărca git de [aici](https://git-scm.com/downloads).
  
## GitHub
Ca să faci ceva cu git-ul instalat anterior, ai nevoie de o platformă care să îți găzduiască proiectele. Una dintre ele, și cea mai cunoscută cred, este GitHub. Te rog să îți faci cont și `[GitHub](https://github.com/)`.  Vom învăța să folosim GitHub și Git în curând!

După ce ți-ai făcut cont pe GitHub, este foarte recomandat să îți configurezi git-ul folosind datele introduse în contul de GitHub. Folosește următoarele comenzi pentru a configura git:

    git config --global user.name "Numele tău aici :)"
    git config --global user.email "Adresa ta de email aici :)"

Pentru a lista configurației git, poți folosi următoarele variante de comenzi:

    git config --list
	    SAU
	nano ~/.gitconfig
## Comenzi de bază în terminal
Aici este o listă cu comenzile de bază de care poți avea nevoie să te descurci în terminal:
 - pwd - afișează calea curentă în care te afli;
 - cd - **change directory**;
 - ls - listează conținutul folderului în care te afli;
 - cat - **concatenate**;
 - cp - **copy**;
 - mv - **move**;
 - mkdir - **make directory**;
 - rmdir -**remove directory**;
 - rm - **remove**
 - touch - creează un nou fișier;
 - man - **manual**.

Nu te speria. Vom învăța împreună cum să folosim aceste comenzi ;)
## Comenzi de bază git

 - git init - inițializează un nou repository;
 - git clone - clonează un repo (ex: de pe GitHub);
 - git status - verifică statusul curent al repo-ului;
 - git pull - trimite modificările în repo-ul local;
 - git push - trimite modificările în repo-ul remote;
 - git add - adaugă fișiere (noi/modificate) pentru a fi incorporate întru-un commit;
 - git commit - realizează un set de modificări care să fie trimise mai departe (cu git push).

Din nou: Nu te speria. Vom învăța împreună cum să folosim aceste comenzi ;)

## Primul program C

    #include <stdio.h>
    
    int main() {
	    printf("Hello, World!");
	    return 0;
    }
   Acesta este un program basic în C. Îl vom salva sub numele de **test.c**. Cum compilăm acest program din terminal? Tastăm comanda următoare:

    gcc test.c

   Nu se va afișa nimic. Ce am greșit? Nimic. Acum doar am făcut operația de build pentru programul nostru. Pentru a rula efectiv programul, la o simplă comandă **ls** vom observa că a apărut un nou fișier cu numele *a.out*. Acel fișier trebuie accesat de către noi pentru a rula programul C. Cum îl accesăm? Folosind următoarea comandă:

    ./a.out
   Dacă totul a decurs conform planului, ar trebui să vezi mesajul celebru. Totuși, putem specifica noi numele acestui fișier .out, în cazul în care dorim să facem acest lucru. Uite cum:   

    gcc test.c -o test
    ./test
Atât de simplu!

## Probleme propuse
Nu cred că are sens să scriu teoria chibritului în acest fișier. Teoria esențială o găsiți în materialele de curs. Voi sublinia aici doar anumite lucruri foarte importante de reținut, atunci când va fi cazul.

 1. Se dă ecuația de gradul al II-lea: ax^2 + bx + c = 0. Să se calculeze rădăcinile ecuației folosind ori de câte ori se poate operatorii de atribuire combinați.
 2. Se citesc trei numere întregi de la tastatură. Să se afișeze maximul dintre cele 3 numere
folosind operatorul decizional.
3. Se citește un număr întreg n de la tastatură. Să se calculeze n * 8, n / 4 si n * 10 folosind
operatorii logici de deplasare la nivel de bit.
4. Se citește un număr întreg de la tastatură. Să se determine dacă acesta este par sau impar folosind doar operatorii logici la nivel de biți.