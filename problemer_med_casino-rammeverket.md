#Hovedproblemene med casino-rammeverket
----------------------------------
1. Minnelekkasjer er umuligå unngå, uten å endre .h-filene

	a. gambler har en vektor av strategi-pekere, men ingen destructor. 
		- Løsning: Lag destruktor, ~gambler(){ … *for/while-løkke* … }
		
		- Må vi iterere gjennom hele vectoren? 
		
		- Ja. Vectoren har ikke ansvaret; den har bare fått noen pekere, den vet ikke til hvor.
	
2. hvordan sletter man alle action-pekerne? Hvem har ansvaret? Noen muligheter:
	
	- Man kan ha kun ett action-objekt, som stadig endres, i bljackjackStrategy. (Hvem bør slette da…?)
		
	- Man kan ha en vector av action-objekter i blackjackStrategy, som stadig vokser
		
	- I blackjack, siden det er så få mulige actions, kan man lage ett av hver på forhånd
		
	- Det viktige er: Klassen bør selv ta ansvar for alt dynamisk minne den allokerer
		
	
2. Vi må bruke downcast. Vi kan gjøre dette med static_cast<blackjackGame>, men det løser ingen ting. Vi kan bruke dynamic_cast<blackjackGame> men det medfører runtime type-checking. Downcast er 100% tillatt i språket, men mange er litt skeptiske til det. Det er en stående utfordring å finne et design som har de samme fordelene som dette rammeverket, men som ikke bruker downcast. Hvis ikke det finnes, vil det være en legitimering av downcast, i dette tilfellet.
 

##Diverse andre problemer

2. Man kan ikke sette gameType. Dette må fikses hvis den skal kunne brukes til noe; den skal være protected.

3. placeBet grensesnitt? Hva med de andres bets? Bør være med i gameState, eller annen løsning.

4. Hvis en gambler gir fra seg penger via placeBet - hvordan vet man at han faktisk har tatt pengene ut av sin kontantbeholdning og ikke bare returnert en sum? Et ganske omfattende pengesystem måtte vært på plass hvis dette rammeverket skulle vært brukt.


4. Hvis noen kaller placeBet, bør de ikke da få vite hvilket spill det gjelder?
	
	- Sende med referanse til game? 
	
	- Sende med en gameType? 	

5. Lagdeling - hva hvis vi nå ønsker å legge på GUI? Hvor mye jobb er det?

	1. Sjakk, Roulette, n-på-rad: her kan alle se alt
	
	2. Poker, Blackjack: her er det *meget* forskjellig hva alle (og dealer) ser
	
	3. Mulig løsning: lag en generell ui-klasse, og en subklasse "myGameUI" for hvert spill. I den generelle klassen, lag feks. "msgToUser(string msg)"
	4. Mer om dette når vi kommer til Qt!

6. Join Game - dette ligger nå som en medlemsfunksjon i gambler. Det må tenkes gjennom hvordan dette skal skje. Skal det finnes en felles registerklasse over gamblere, og en over alle games? Skal gamblere oppsøke spill eller skal "casinoet", eller de enkelte spillene kunne "plukke" gamblere? Dette er et åpent spørsmål.

7. …Det er sikkert flere ting! Men rammeverket har også noen store fordeler, se nederst.
	

##Annen konstruktiv kritikk / Spørsmål:
- Const burde vært brukt mye mer i .h-filene, for å signalisere intensjon. Som feks. const t_rank. Enig! Men det er en del vi ikke hadde lært om const på det tidspunktet det kom ut. Sjekk forelesningsnotater fra f13!

- Hvorfor er blackjackGame::start() virtuell? Den skal vel ikke arves?

	- Generelt bruker jeg virtual også i subklassene, for å *vise* at den er virtuell.
	
	- Det kan godt hende man vil lage subklasser av blackjackGame - det kan feks. være blackjackGame_http, eller blackjackGame_terminal? Poenget er at det ikke er min jobb å fortelle andre utviklere at denne metoden *ikke* bør overrides, med mindre det er en viktig grunn til det.
	
	- OG: selv om man ikke kaller en polymorfisk funksjon virtual i sbuklassen, kan den allikevel overrides i en evt. subklasse. Siden man ikke kan hindre dette er det etter min mening ryddig å oppgi at den er virtual - den er jo det uansett.

- Er det ikke mer naturlig at gambler-klassen holder kortene sine selv, enn at de ligger i "gameState"?  Kanskje, men da må vi ha en egen subtype av gambler for hvert spill - og da mister vi fordel nr. 1 med dette rammeverket (se under). Man kan også argumentere slik: er det ikke naturlig at en gambler kan spille forskjellige spill? Og at han kan veksle mellom ulike strategier i ulike spill? I så fall er det *ikke* naturlig at gabmleren har kort (fordi han skal være en generell spiller, også for sjakk og poker), med mindre man lager en generell beholder "hands" av "ting" han kan holde i hendene. Man kan også spørre seg om det er naturlig at ikke kortene ligger på bordet…
	
	
##Fordeler med casino-rammeverket
1. En gambler kan tilegne seg, og miste strategier til mange ulike spill, mens programmet kjører (runtime). 
2. Støtte for svært mange runde-baserte (turn-based) spill, som poker, sjakk, roulette, blackjack, kinasjakk, ludo, risk etc.
3. Det er støtte for både menneskelige og kunstige spillere, som kan spille om hverandre
4. Med bare kunstige spillere kan rammeverket fint brukes som et simuleringsrammeverk for å teste effekten av ulike strategier, over mange millioner spill.
5. En menneskelig spiller kan assisteres av mange ulike AI-strategier *mens* den spiller, som er det Gary Kasparov [i denne interessante artikkelen](http://www.nybooks.com/articles/archives/2010/feb/11/the-chess-master-and-the-computer/), mener vil gi de aller beste resultatene i sjakk. Dette ville konkret løses enkelt, ved at man i en strategi som henter resultatet fra et GUI (á la den fra oblig1), først henter resultater fra flere andre strategier (altså actions), som så blir presentert til brukeren sammen med gameState. Brukeren gjør da en action, basert på gameState, men kan også velge å ta hensyn til hva de andre strategiene ville valgt - de fungerer da som "AI-advisors".
