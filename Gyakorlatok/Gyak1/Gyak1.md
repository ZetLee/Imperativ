# 1. gyakorlat

## Bevezetés


### Kötelező feladatok


#### Standard I/O

1. Írj programot, amely kiírja a képernyőre, hogy *Hello World!* (Ezt variáljuk: mutassuk meg, mi a warning, mi az error, töröljünk ki annyi szóközt, amennyit lehet, nézzük meg, mi a különbség a szóközzel és a tabulátorral való behúzás között, stb.)


### Gyakorló feladatok


#### Standard I/O

1. Írj programot, amely kiírja a nevedet.
2. Írj programot, mely kiírja két szám összegét.
3. Írj programot, melyben elosztasz két számot. Írd ki az eredményt. Mi történik, ha az osztó 0? Mi történik, ha `int` vagy `float` típusú változókat használunk?
> - Használd a `%f` formázó karaktert. Figyelj oda, hogy kiíráskor két tizedesig
írja csak ki az eredményt.
> - Használd a `%d` formázó karaktert. Nézd meg, hogy mi történik.
> - A program fordításánál használd a **-W, -Wall, -Wextra** és **-pedantic** kapcsolókat. Vajon fordítási hibát okoz, ha hibás formázó karaktert használsz?
4. Írj programot, melyben kiszámolod egy négyszög, illetve egy kör kerületét és területét. A négyszög két oldalát, illetve a kör sugarát kérd be a standard inputról.
> - Használd a `scanf(“%d”, &a)` függvényt. Használd az `&` operátort, amely a
változó címét adja vissza. A pi értékét vedd *3.1415*-nek.
5. Írj programot, ami a neveden köszönt. A nevedet tárold változóban.
> - Használd a `char[]` típust, és a `%s` formázó karaktert. Figyelj oda, tömböknél
fontos a szintaxis: `char name[10]`.


### Haladó feladatok


#### Standard I/O

1. Írj programot, mely a napok számát átszámolja évekre, hetekre és napokra. Pl. 375 nap = 1 év 1 hét 3 nap. Mindig csak a nagyobb egység maradékával dolgozz.
2. Készíts egy Fahrenheit-Celsius átalakító programot ( *C = (F-32)/1.8* ). Írd ki a [-20; 200] intervallum Fahrenheit értékeit 10-es léptékkel, és a hozzájuk tartozó Celsius-fokot.