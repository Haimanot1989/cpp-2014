cpp_tic-tac-toe
===============

oppgave 2 Tre og Fire på rad i casino-rammeverket


    Oppgave tekst
    Denne oppgaven passer for de som i prinsippet likte å jobbe med casino-rammeverket fra oblig 1, men som så hvordan det kunne vært gjort bedre. Velger du denne oppgaven skal du ta utgangpsunkt i det rammeverket, og følgende krav gjelder:

    Du skal implementere 3-på-rad, og fire-på-rad, menneske mot maskin. Du velger selv om begge spillene skal være en og samme strategi, der tre eller fire er gyldige verdier til konstruktor, eller om det er to separate klasser.

    Du oppfordres til å løse eventuelle problemer med casino-rammeverket, som feks. å legge til destruktorer der det er naturlig, strømlinjeforme kontrollflyt (feks. tilrettelegge for at all kommunikasjon med bruker går via gambler), omstrukturere mer i retning MVC lagdeling etc.

    Du kan endre alle klassene, og også legge til så mange klasser du vil, men ett krav er absolutt: Det må fremdeles være slik at en gambler kan ha et vilkårlig antall strategier, til minst to ulike spill, og at dette kan endres "runtime". Pr. i dag er det lagt opp til at dette ligger i en vector i gambler, og det må da gjøres en "downcast". Hvis du synes downcast er et problem, bør du vurdere oppgave 3.

    Når spillet starter skal brukeren få en meny over de spillene som er tilgjengelige, og velge et, eller avslutte. Når spillet er ferdig skal man tilbake til menyen.

    Ekstra (frivillig) utfordring: lag programmet ditt slik at du kan sette maskinen til å spille mot seg selv - eller til å spille mot en annens strategi, og la det være mulig å vise spillet i sakte film i terminalen, slik at man som bruker kan følge med. Sett gjerne ditt program til å spille mot en medstudent sitt - da må dere bli enige om en api. OBS: Dersom du gjør dette, si fra!
