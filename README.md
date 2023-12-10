# CardGame

### I - To launch the game:   
Simply **compile** the program, commenting the first line with `#define TESTING` and adding `//` before it.   
### II - Next, you'll be asked to enter a game mode:
-  AI  = 🥷🏼vs🤖
- JvJ = 🥷🏼vs🥷🏼
  
In AI mode, you'll play against a `BOT` 🤖 which has already `trained against other BOTS` 🤖🤖🤖 to find the strongest deck from a set number. 
  
### III - You can choose between:   
- ⭐Easy AI, with `100` decks   
- ⭐⭐Medium AI, with `5000` decks  
- ⭐⭐⭐Hard AI, with `7000` decks  

The program will ask you to allocate a number of `prestige points` to each player.   
Both players have the `same number` of prestige points.  
### IV - Once you've entered the names of the two players (🥷🏼🥷🏼) in JvJ mode  
### IV - Once you've entered the names of the player (🥷🏼) in AI mode (🤖)  
  
The game will ask you to choose how to `organize` your deck  
Proposing several `pre-programmed orders`.  
  
### V - You can choose between:    
**1.** ❓❓`Random` mode _(where all cards are randomly arranged)_  
**2.** ❓Handmade mode (which lets you choose the `position` of each card `manually` _(based on the card's index)_) 
  
**3.** ⭐⭐Sort cards from **smallest** to **largest** `Attack` damage   
**4.** ⭐Sort cards from **largest** to **smallest** `Attack` damage   
  
**5.** ⭐⭐Sort cards from **smallest** to largest `Magic` damage  
**6.** ⭐Sort cards from **largest** to **smallest** `Magic` damage  
  
**7.** ⭐⭐Sort cards from **smallest** to **largest** `Defence`     
**8.** ⭐Sort cards from **largest** to **smallest** `Defence`    
  
**9.** ⭐⭐⭐ Sort by `descending` order of _(1)_ `attack`, then _(2)_ `magic`, then _(3)_ `defense`  


### VI - Once the players have their decks  
#### The program runs and plays both players' cards until:   
1. `One` of them has `no more prestige points`  
2. `Both` players have `no more cards`
3. Whoever falls to 0 first loses _(if `both` players `fall below 0` at the `same time`, the player with the `fewest prestige points loses`)_ 

**( (_To run the tests, simply `uncomment` the first `#define TESTING` line_) )**
