# Sor adatszerkezet
 
Ebben a feladatban egy *Sor* (*Queue*) adatszerkezetet kell implementálni. A felhasználó stringeket szúrhat a sor végére, és a legkorábban beszúrt elemet éri el belőle. A következő műveleteket kell biztosítani:
 
- `insert()`: Beszúr egy stringet a sor végére. **(8 pont)**
- `first()`: Visszaadja a sor első elemét. **(3 pont)**
- `pop()`: Törli a sor első elemét. **(8 pont)**
- `isEmpty()`: Igazzal tér vissza, ha a sor üres. **(3 pont)**
- `clear()`: Törli a sor összes elemét. **(6 pont)**
 
Példa:
```
insert “apple”
insert “peach”
insert “grapes”
print first (prints “apple”)
pop first (removes “apple”)
print first (prints “peach”)
insert “plum”
pop first (removes “peach”)
print first (prints “grapes”)
pop first (removes “grapes”)
print first (prints “plum”)
```
 
A sort implementáljuk egy struktúrával, ami stringek tömbjét, és a beszúrt elemek számát kezeli. A tömb legfeljebb 100 elem tárolására legyen alkalmas. **(4 pont)** Ezt a számot egy preprocessor makróval reprezentáljuk. Maguk a stringek a heap memóriában lesznek eltárolva. **(3 pont)**
 
Tipp: A `pop()` műveletet meg lehet úgy valósítani, hogy a beszúrt elemeket eggyel balrább csúsztatja. Ily módon a sor első eleme mindig a tömb elején foglal helyet. Egy alternatív megvalósítás az is lehet, hogy a struktúrában eltároljuk a sor első és utolsó elemének a pozícióját. Azonban ennél az implementációnál oda kell figyelni a tömb túlcsordulására: ha az utolsó tömbindex foglalt, akkor a kökvetkező elemet a tömb elejére kell beszúrni, ha vannak még ott üres helyek.
 
Figyelj arra, hogy a programban ne legyen memóriaszivárgás: a `clear()` függvénynek az összes stringet deallokálnia kell, amik a heap memóriában kaptak helyet. **(5 pont)**
 
Bontsd a programot több fordítási egységre: a sor típus és műveleteinek megvalósítását egy külön `.c` fájlba helyezzük, amit egy header fájllal kapcsolunk a fő programhoz. **(4 pont)**
 
Olvasd be egy fájl tartalmát, és a benne található szavakat szúrd be egy sor adatszerkezetbe. Ezután írd és töröld ki a sor elemeit, amíg az ki nem ürül. **(6 pont)**