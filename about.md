
# Game of Nim

Nim [Wikiedia] https://en.wikipedia.org/wiki/Nim is a **mathematical game of strategy** in which two players take turns removing objects (Matchsticks in our case)
from distinct heaps. On each turn, a player must remove at least one object, and may remove any number of objects
provided they all come from the same heap. The goal of the game is to avoid being the player who must remove the
last object.

Nim is typically played as a misère game, in which the player to take the last object loses. Nim can also be
played as a normal play game, where the player taking the last object wins. This is called normal play because
the last move is a winning move in most games; Nim is usually played so that the last move loses.

The normal game is between two players and played with three heaps of any number of objects. The two players
alternate taking any number of objects from any single one of the heaps. The goal is to be the last to take an
object. **In misère play, the goal is instead to ensure that the opponent is forced to take the last remaining object.**

## Single Heap Nim

In our Case we have just a single Heap :

  1. We start with any number of objects (Matchsticks) but minimum 10 is a fair play number.
  2. We can chose who plays first : either You or Computer.
  3. In one move anyone can pick 1 or 2 or 3 or 4 machsticks. So Minimum 1 & Maximum 4.
  4. The one forced to pick last matchstick loses the game.
