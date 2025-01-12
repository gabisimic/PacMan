# Pac-Man

Ovo je **jednostavna Pac-Man igra** implementirana u C++ programskom jeziku. 

Igra se sastoji od igrača koji kontrolira **Pac-Man** lika i pomiče ga po 2D mreži kako bi skupljao **točke** dok izbjegava **neprijatelje** (duhove). Igrač pobjeđuje kada skupi sve točke na mreži, ali ako Pac-Man bude uhvaćen od strane duha, igra završava.

## Kako igrati

1. **Pokretanje igre**:
   - Igra počinje generiranjem 2D mape sa zidovima i praznim prostorima. Pac-Man i neprijatelji (duhovi) su nasumično postavljeni na mapu.

2. **Kontrole**:
   - **W** ili **w**: Pomakni Pac-Man prema gore.
   - **S** ili **s**: Pomakni Pac-Man prema dolje.
   - **A** ili **a**: Pomakni Pac-Man prema lijevo.
   - **D** ili **d**: Pomakni Pac-Man prema desno.

3. **Cilj**:
   - Cilj je sakupiti sve točke dok izbjegavate duhove. Ako Pac-Man bude uhvaćen od strane duha, igra završava. Ako se sve točke sakupi, igra završava pobjedom.

4. **Kraj igre**:
   - Igra završava kada:
     - Pac-Man bude uhvaćen od strane duha (Game Over).
     - Skupljene su sve točke (Pobjeda).

## Karakteristike

- **Pac-Man**: Glavni lik kojeg igrač kontrolira kako bi skupljao točke i izbjegavao duhove.
- **Duhovi**: Neprijatelji koji se nasumično kreću po mapi i pokušavaju uloviti Pac-Man-a.
- **Točke**: Točke su raspoređene po mapi, a igrač ih mora skupiti kako bi pobijedio.
- **Zidovi**: Mapa je okružena zidovima koje igrač i duhovi ne mogu proći.
- 
## Potencijalna poboljšanja

1. **Inteligentnije kretanje duhova**:
   - Trenutno se duhovi kreću nasumično, što može biti previše lako za igrača. Poboljšanje bi bilo implementirati logiku koja omogućuje duhovima da aktivno love Pac-Man-a, čineći igru izazovnijom.

2. **Dodavanje različitih vrsta duhova**:
   - U originalnoj Pac-Man igri, svaki duh ima jedinstvenu strategiju kretanja. Implementacija različitih vrsta duhova s različitim ponašanjima može značajno unaprijediti igru.

3. **Više razina**:
   - Trenutno postoji samo jedna razina. Dodavanje više razina s različitim mapama, većim brojem duhova i težim uvjetima moglo bi igru učiniti interesantnijom.

4. **Grafičko sučelje**:
   - Trenutno se koristi tekstualno sučelje. Implementacija grafičkog sučelja, s boljim prikazom likova i animacijama, značajno bi poboljšala vizualni dojam igre.

5. **Pauza i postavke igre**:
   - Dodavanje opcije za pauzu i mogućnosti za podešavanje postavki igre (npr. brzina duha, broj duhova) bi omogućilo veću fleksibilnost igračima.

## Greške s kojima smo se susreli

1. **Problem sa unosom na Linux/MacOS**:
   - Funkcija `_getch()` iz `conio.h` ne radi na Linux i MacOS platformama. To zahtijeva promjenu unosa u nešto što je kompatibilno s tim sustavima (npr. `cin`). Ali u svrhu jednostavnosti projekta, nastavljeno je korištenje funkcije _getch().

2. **Rupe u logici generiranja mape**:
   - Iako mapu generiramo nasumično, može doći do situacija gdje zidovi budu postavljeni na pozicije koje ometaju igru (npr. točkice okruzene zidovima). Jednostavno rješenje bilo je samo smanjiti vjerojatnost generiranja zida `rand() % 7 == 0`, što nije baš efikasno, samo smanjuje vjerojatnost pogreške, ali ju ne eliminira. Bilo bi optimalnije da se implementira napredniji algoritam za generiranje zidova, koji prati udaljenosti između zidova i je li ijedna točkica nepristupačna igraču.

## Kako instalirati

1. Preuzmite i instalirajte C++ kompajler (ako ga već nemate).
   
2. Preuzmite izvorni kod i spremite ga u `.cpp` datoteku.
   
3. Pokrenite izvođenje koda.


