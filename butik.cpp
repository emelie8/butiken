/* 
Skapa en butik som räknar ut växeln som vi ska få tillbaka

Program: Butik
Skapare: Emelie Johansen
Version: 1.0 
Datum:   2021-12-02
*/

#include <iostream>
using namespace std;

// Skapa variabler för pris, växel och inbetalt belopp
// Typen double är vald för att kunna hantera stora tal med decimaler
double betalade, vaxel, oren;
double pris = 0;
double tPris = 1;

// Skapa variabel för att hålla ordning på antal artiklar
// Typen int är vald eftersom detta endast är en räknare
int varuNr = 1;

// Skapa variabel för att hålla heltalsdelen av växeln som ska ges tillbaka
// Eftersom det är ett heltal passar datatypen int
int intVaxel;

// Skapa variabler för att hålla antalet av olika valörer som ska ges tillbaka
// Antalen är alltid heltal och därför har datatypen int valts
int tusen, femhundra, hundra, femtio, tjugo, tio, fem, en;

// Funktionen main() returnerar ett heltalsvärde (int)
int main() {
    // Rensa skärmen
    cout << "\033[2J\033[1;1H";
    cout << "\n";

    // Skriv ut ett välkomstmeddelande
    cout << "Hej och välkommen till min enkla butik!\n";
    cout << "***************************************\n\n";
    cout << "Det här programmet kommer att beräkna hur mycket växel du ska få tillbaka\n\n";
    cout << "Du kommer nu att få ange pris på de varor du vill köpa\n\n";
    cout << "Ange 0 om du inte vill köpa fler varor\n\n";

    // Be användaren att ange varans/varornas pris
    while(tPris != 0) {
        cout << "Ange pris på vara nummer ";
        cout << varuNr;
        cout << ": ";
        cin >> tPris;
        pris = pris + tPris;
        varuNr++;
    }
    
    // Skriv ut totalt belopp att betala
    cout << "\nTotalt att betala: ";
    cout << pris;
    cout << " kr\n";

    // Be användaren att mata in betalat belopp
    cout << "\nAnge inbetalat belopp: ";
    cin >> betalade;

    // Räkna ut växel
    vaxel = betalade - pris;

    // Räkna ut intVaxel
    intVaxel = (int) vaxel;

    // Räkna ut decimal del av växeln (ören)
    oren = (vaxel - intVaxel) * 100;

    // Räkna ut antalet femtioöringar
    // Vi utgår från att 50 öre fortfarande används. Växeln avrundas till närmsta 50 öre.  
    // Om antalet öre är < 25 avrundas växeln neråt till 0. 
    // Om det ligger mellan 25 och 75 avrundas växeln till 50 öre.
    // Om det är >75 avrundas växeln upp till en krona.

    if(oren < 25) {
        oren = 0;
    } else if (oren < 76) {
        oren = 50;
    } else {
        oren = 0;
        intVaxel++;
    } 

    // Skriv ut hur mycket växel användaren får tillbaka
    cout << "\nDu får tillbaka ";
    cout << intVaxel;
    cout << " kr och ";
    cout << oren;
    cout << " ören.\n";

    // Räkna ut hur många sedlar och mynt av varje valör användaren får tillbaka
    tusen = intVaxel / 1000; 
    intVaxel = intVaxel % 1000;
    femhundra = intVaxel / 500; 
    intVaxel = intVaxel % 500;
    hundra = intVaxel / 100; 
    intVaxel = intVaxel % 100;
    femtio = intVaxel / 50; 
    intVaxel = intVaxel % 50;
    tjugo = intVaxel / 20; 
    intVaxel = intVaxel % 20;
    tio = intVaxel / 10; 
    intVaxel = intVaxel % 10;
    fem = intVaxel / 5; 
    intVaxel = intVaxel % 5;
    en = intVaxel / 1; 
    intVaxel = intVaxel % 1;

    // Skriv ut hur många sedlar och mynt som ges tillbaka
    cout << "\nAntal tusenlappar:     ";
    cout << tusen;
    cout << " st\n";
    cout << "Antal femhundralappar: ";
    cout << femhundra;
    cout << " st\n";
    cout << "Antal hundralappar:    ";
    cout << hundra;
    cout << " st\n";
    cout << "Antal femtiolappar:    ";
    cout << femtio;
    cout << " st\n";
    cout << "Antal tjugolappar:     ";
    cout << tjugo;
    cout << " st\n";
    cout << "Antal tiokronor:       ";
    cout << tio;
    cout << " st\n";
    cout << "Antal femkronor:       ";
    cout << fem;
    cout << " st\n";
    cout << "Antal enkronor:        ";
    cout << en;
    cout << " st\n";
    cout << "Antal femtioöringar:   ";

    // Kontrollera om det finns en femtioöring eller inte
    if (oren == 50) {
        cout << "1 st\n";
    } else {
        cout << "0 st\n";
    }

    // Returnera alltid siffran 0
    // Framtida versioner kan tänkas returnera andra siffror 
    // beroende på vad som händer i programmet, t.ex. felkoder
    return 0;

}

/* 
Utvärdering

Jag har skapat en butik där användaren själv får ange pris på en eller flera varor
och därefter får ange hur mycket som betalas in. Programmet räknar sedan ut hur 
mycket växel som ska ges tillbaka och dessutom skriver programmet ut hur många 
sedlar och mynt av varje valör användaren får tillbaka. 

Min bedömning är att programmet är användarvänligt eftersom alla steg förklaras tydligt
genom hela programmet. 

Det är ju lite konstigt att användaren ska ange priserna själv. I en riktig butik hade
användaren fått välja redan registrerade produkter där priset redan var fastställt.

Mer utvecklade versioner av det här programmet skulle också kunna innehålla mer
felkontroller och felhantering som t.ex. förhindra att användaren matar in ett pris
som är mindre än 0 eller ett pris som innehåller fler än två decimaler.

Det var roligt att lära sig lite om grunderna i C++ och de olika datatyperna som finns.
Jag lärde mig även att använda de inbyggda funktionerna för utmatning på skärmen och 
inmatning från användaren. 
*/