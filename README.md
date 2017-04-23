# PIC 10C - Homework 1
## Git Practice
This project practices several features.
* Branching
* Pull Requests
* Merging Branches
* Adding a readme file
* Adding a license file
* Adding .gitignore & .gitattributes files

## Spanish Playing Cards
This project is a console application that attempts to recreate the popular blackjack variant known as [Siete y Medio]( https://en.wikipedia.org/wiki/Sette_e_mezzo ).

### The Deck
#### Suits
* Oros (Diamonds)
* Copas (Hearts)
* Espadas (Spades)
* Bastos (Clubs)
#### Card Values
AS = 1 , DOS = 2, TRES = 3, CUATRO = 4, CINCO = 5, SEIS = 6, SIETE = 7, SOTA = 1/2, CABALLO = 1/2, REY = 1/2

### The Game
The game is typically played with two or more players. In this application, there are only two: the *user* and the *dealer*. The *user* starts with a total of $100 and places a bet against the *dealer*. After this initial setup, the game and rules are essentially the same as Blackjack, but instead of aiming for a score of 21, the value to reach is 7.5 without going over.

### Logging
The application produces a text file 'gamelog.txt' that records the last played game session. A portion of a typical gamelog is provided below.

```
-----------------------------------
Game number: 1	Money Left: $100
Bet: 98

Your cards: 
	As de copas
	  { Ace of hearts } 
	Seis de bastos
	  { Six of clubs } 
Your total: 7

Dealer's cards: 
	Dos de oros
	  { Two of diamonds } 
	Tres de copas
	  { Three of hearts } 
	Tres de oros
	  { Three of diamonds } 
Dealer's total: 8

-----------------------------------
-----------------------------------
Game number: 2	Money Left: $198
Bet: 98

Your cards: 
	Rey de copas
	  { King of hearts } 
	Sota de bastos
	  { Jack of clubs } 
	As de bastos
	  { Ace of clubs } 
	Dos de bastos
	  { Two of clubs } 
	Cinco de copas
	  { Five of hearts } 
Your total: 9

Dealer's cards: 
	Rey de copas
	  { King of hearts } 
	Cuatro de bastos
	  { Four of clubs } 
	Sota de bastos
	  { Jack of clubs } 
	Dos de bastos
	  { Two of clubs } 
Dealer's total: 7

-----------------------------------
-----------------------------------
Game number: 3	Money Left: $100
Bet: 50

Your cards: 
	Seis de bastos
	  { Six of clubs } 
Your total: 6

Dealer's cards: 
	Siete de espadas
	  { Seven of spades } 
Dealer's total: 7

-----------------------------------
-----------------------------------
```
