// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by Elicia Au Duong (z5260173)
// on 30.03.2019
// 

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// IF YOU NEED MORE #defines ADD THEM HERE
#define MAX_SIZE           1000
#define SCANNED_CARDS         3
#define THE_DOUGLAS          42

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int primeCheck(int num);
int numGoodCards(int largest, int numPossible, int allPossible[numPossible]);
int bestPlay(int largest, int numPossible, int allPossible[numPossible]);

// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("COSMIC ROGERS");

}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int numberOfCards = 0;
    int myCards[N_CARDS_INITIAL_HAND];
    while (numberOfCards < N_CARDS_INITIAL_HAND) {
        scanf("%d", &myCards[numberOfCards]);
        numberOfCards++;
    }
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    int numberDiscarded = 0;
    int counterI = 0;
    int douglasCheck = 0;
    int placement = N_CARDS_INITIAL_HAND - 1;
    
    // if douglas is in initial hand, discard 42
    while (counterI < N_CARDS_INITIAL_HAND && douglasCheck == 0) {
        if (myCards[counterI] == THE_DOUGLAS) {
            printf("%d ", THE_DOUGLAS);
            douglasCheck = 1;
            numberDiscarded = 1;
        }
        counterI++;
    }
    
    // discard the 3 highest cards if the douglas is not in the hand
    // discard the 2 highest cards if the douglas is in the hand
    while (numberDiscarded < N_CARDS_DISCARDED) {
        // if 42 is in 3 the highest cards shift to get the next highest card
        if (myCards[placement] == 42) {
            placement = placement - 1;
        } else {
            printf("%d ", myCards[placement]);
            placement = placement - 1;
            numberDiscarded++;
        }
    }

    printf("\n");
}


void choose_card_to_play(void) {

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    
    // counter of cards to scan in
    int counterN = 0;
    int numbers[SCANNED_CARDS] = {0};
    while (counterN < SCANNED_CARDS) {
        scanf("%d", &numbers[counterN]);
        counterN++;
    }
    // number of cards in your hand
    int numberInHand = numbers[0];
    // number of cards played this round
    int numberCardsPlayed = numbers[1];
    // table position
    int tablePosition = numbers[2];
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    // counter of cards in your hand
    int counterH = 0;
    int cardsInHand[MAX_SIZE];
    while (counterH < numberInHand) {
        scanf("%d", &cardsInHand[counterH]);
        counterH++;
    }

    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    // counter of previously played cards
    int counterP = 0;
    int previouslyPlayed[MAX_SIZE];
    while (counterP < numberCardsPlayed) {
        scanf("%d", &previouslyPlayed[counterP]);
        counterP++;
    }
    
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    // counter of how many cards have been played in the whole game
    int counterS = 0;
    // calculate round number (determined by number of cards in hand)
    int round = N_CARDS_INITIAL_HAND - numberInHand - 1;
    // total number of cards played in the whole game
    int numberPlayed = round * N_PLAYERS;
    int gameHistory[MAX_SIZE];
    while (counterS < numberPlayed) {
        scanf("%d", &gameHistory[counterS]);
        counterS++;
    }
    
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
    // total number of prime numbers in hand
    int totalPrimes = 0;
    int primes[MAX_SIZE];
    
    // total number of non-prime numbers in hand
    int totalNonPrimes = 0;
    int nonPrimes[MAX_SIZE];
    
    // counter of cards in hand
    int counterC = 0;

    // check for and count all primes and non-primes in hand
    while (counterC < numberInHand) {
        // primeCheck() - check if card is a prime number or not
        // if card is a prime number, add to array of prime numbers
        if ((primeCheck(cardsInHand[counterC]) == 1)) {
            primes[totalPrimes] = cardsInHand[counterC];
            totalPrimes++;
        // if card is not a prime number, add to array of non-prime numbers
        } else {
            nonPrimes[totalNonPrimes] = cardsInHand[counterC];
            totalNonPrimes++;
        }
        counterC++;
    }
    
    // boolean if a prime card has been previously played; starts as FALSE
    int primeBefore = 0;
    // counter of cards played before
    int counterB = 0;
    
    // check if a prime number has previously been played
    while (counterB < numberPlayed) {
        // if a prime number exists in game history, primeBefore is TRUE
        if ((primeCheck(gameHistory[counterB])) == 1) {
            primeBefore = 1;
        }
        counterB++;
    }
    
    // boolean if first card this round is prime; starts as FALSE
    int firstPrime = 0;
    // first card is the first in the previouslyPlayed array
    int firstCard = previouslyPlayed[0];
    
    // if not the first player then check if first card is prime
    if (numberCardsPlayed != 0 && (primeCheck(firstCard)) == 1) {
        firstPrime = 1;
    } 
    
    // copy of the first card to be divided by factors    
    int numberDivided = firstCard;
    // initialise array for the factors of the first card (when not prime)
    int firstFactors[MAX_SIZE];
    // count of the number of factors in the first card
    int numFirstFactors = 0;
    
    // if not the first player and first card is not prime
    if (numberCardsPlayed != 0 && firstPrime == 0) {
        // find factors of first card and add to array of factors
        // find the prime factorisation of the first card
        while (numberDivided != 1 && numFirstFactors < MAX_SIZE) {
            // find all factors of 2 in the first card
            while (numberDivided % 2 == 0) {
                firstFactors[numFirstFactors] = 2;
                numberDivided = numberDivided/2;
                numFirstFactors++;
            } 
            // intitialise factor to 3
            int factor = 3;
            // find all factors until the factor is equal to the first card 
            while (factor <= firstCard) {
                // find all odd factors of the first card
                if (numberDivided % factor == 0) {
                    while (numberDivided % factor == 0) {
                        firstFactors[numFirstFactors] = factor;
                        numberDivided = numberDivided/factor;
                        numFirstFactors++;
                    }
                    factor = factor + 2;
                // if not a factor of first card, increment by 2
                } else {
                    factor = factor + 2;
                }
            }
        }
    }
    
    // initialise array for when a factor of a card is in the first card factors
    int match[MAX_SIZE] = {0}; 
    // initialise array of all cocomposite numbers to the first card
    int allCocomposites[MAX_SIZE] = {0};
    // total number of cocomposite numbers
    int numCocomposites = 0;
    
    // counter of all composite numbers
    int counterJ = 0;
    // count of the number of factors in each card
    int numberOfFactors = 0;

    // if the first card is not prime and player is not first
    if (firstPrime == 0 && numberCardsPlayed != 0) {
        // find the prime factorisation of 
        while (counterJ < totalNonPrimes) {
        
            // initialise array for the factors of each card
            int compositeFactors[MAX_SIZE];
            // copy of the each card to be divided by factors
            int composite = nonPrimes[counterJ];
            // reset number of factors to 0 for each card
            numberOfFactors = 0;
            
            // find factors of each card and add to array of factors
            // find the prime factorisation of each card
            while (composite != 1 && counter < MAX_SIZE) {
                while (composite % 2 == 0) {
                    compositeFactors[numberOfFactors] = 2;
                    composite = composite/2;
                    numberOfFactors++;
                } 
            
                int factor = 3;
                while (factor <= composite) {
                    if (composite % factor == 0) {
                        while (composite % factor == 0) {
                            compositeFactors[numberOfFactors] = factor;
                            composite = composite/factor;
                            numberOfFactors++;
                        }
                        factor = factor + 2;
                    } else {
                        factor = factor + 2;
                    }
                }
            }
            
            // counter of the number of factors in the first card
            int counterK = 0;
            // counter of the number of factors in each card
            int counterL = 0;
            // reset counter to 0 for each card        
            counterK = 0; 
            while (counterK < numFirstFactors) {
                // reset counter to 0 for each of the factors in the first card
                counterL = 0;
                while (counterL < numberOfFactors) {
                    // if a factor in the first card is also in each card
                    // add the card to the match array
                    if (firstFactors[counterK] == compositeFactors[counterL]) {
                        match[counterJ] = nonPrimes[counterJ];
                    }
                    counterL++;
                }
                counterK++;
            }
            counterJ++;
        }
    }
    // counter of number of cocomposite cards
    int counterA = 0;
    while (counterA < MAX_SIZE) {
        // for each card in match array, add it to cocomposite array if not 0
        if (match[counterA] != 0) {
            allCocomposites[numCocomposites] = match[counterA];
            numCocomposites++;
        }
        counterA++;
    }
    
    // find the biggest card that has been played in this round
    // counter of cards previously played
    int counterZ = 0;
    // intitialise biggest card played this round
    int bigPlay = 0;
    while (counterZ < numberCardsPlayed) {
        // if previous card played is bigger than bigPlay, assign it as bigPlay
        if (previouslyPlayed[counterZ] > bigPlay) {
            bigPlay = previouslyPlayed[counterZ];
        }
        counterZ++;
    }
    
    // find if there is the douglas in the hand
    // counter of cards in the hand
    int counterF = 0;
    // boolean if the douglas is in hand; starts as FALSE
    int douglasHand = 0;
    while (counterF < numberInHand) {
        // if a card in the hand is 42, douglasHand is TRUE
        if (cardsInHand[counterF] == 42) {
            douglasHand = 1;
        }
        counterF++;
    }
    
    // check if the douglas is cocomposite
    // counter of cocomposite cards
    int counterE = 0;
    // boolean if the douglas is cocomposite; starts as FALSE
    int douglasCocomposite = 0;
    while (counterE < numCocomposites) {
        // if 42 is a cocomposite card, douglasCocomposite is TRUE
        if (allCocomposites[counterE] == 42) {
            douglasCocomposite = 1;
        }
        counterE++;
    }
    
    // valid moves
    // check if playing first card in round
    if (numberCardsPlayed == 0) {
        // check if prime card has been played before
        if (primeBefore == 1) {
            //play any card
            if (totalNonPrimes != 0) {
                printf("%d\n", nonPrimes[0]);
            } else {
                printf("%d\n", primes[0]);
            }
        } else {
            if (totalNonPrimes !=0) {
                //play a non-prime
                printf("%d\n", nonPrimes[0]);
            } else {
                //play any card
                if (totalNonPrimes != 0) {
                    printf("%d\n", nonPrimes[0]);
                } else {
                    printf("%d\n", primes[0]);
                }
            }
        }
    } else {
        // check if first card this round is prime
        if (firstPrime == 1) {
            // check if there is a prime card in hand
            if (totalPrimes != 0) {
                //play a prime 
                if (numGoodCards(bigPlay, totalPrimes, primes) != 0) {
                    printf("%d\n", bestPlay(bigPlay, totalPrimes, primes));
                } else {
                    printf("%d\n", primes[0]);
                }
            } else {
                //play any card
                if (totalNonPrimes != 0) {
                    if (numGoodCards(bigPlay, totalNonPrimes, nonPrimes) != 0) {
                        printf("%d\n", bestPlay(bigPlay, totalNonPrimes, nonPrimes));
                    } else {
                        printf("%d\n", nonPrimes[0]);
                    }
                } else {
                    if (numGoodCards(bigPlay, totalPrimes, primes) != 0) {
                        printf("%d\n", bestPlay(bigPlay, totalPrimes, primes));
                    } else {
                        printf("%d\n", primes[0]);
                    }
                }
            }
        } else {
            // check if co-composite card in hand
            if (numCocomposites != 0) {
                // play co-composite card
                if (numGoodCards(bigPlay, numCocomposites, allCocomposites) != 0) {
                    printf("%d\n", bestPlay(bigPlay, numCocomposites, allCocomposites));
                } else {
                    printf("%d\n", allCocomposites[0]);
                }
            } else {
                // play any card
                if (douglasHand == 1 && douglasCocomposite == 0) {
                    printf("%d\n", THE_DOUGLAS); 
                } else if (totalPrimes != 0) {
                    printf("%d\n", primes[totalPrimes-1]); 
                } else {
                    printf("%d\n", nonPrimes[totalNonPrimes-1]);
                }
            }
        }
    }  
}

// ADD YOUR FUNCTIONS HERE

int primeCheck(int num) {

    int prime = 0;
    int divider = 2;
    
    while (divider < num) {
        if (num % divider == 0) {
            prime = 0;
            break;
        } else {
            prime = 1;
        }
        if (divider % 2 == 0) {
            divider++;
        } else {
            divider = divider + 2;
        }
    }

    return prime;
}

int numGoodCards(int largest, int numPossible, int allPossible[numPossible]) {
    int i = 0;
    
    int numGoodCards = 0;
    while (i < numPossible && allPossible[i] < largest) {
        i++;
        numGoodCards++;
    }
    
    return numGoodCards;
}


int bestPlay(int largest, int numPossible, int allPossible[numPossible]) {
    int j = 0;
    
    int goodCards[MAX_SIZE] = {0};
    int numGoodCards = 0;
    while (j < numPossible && allPossible[j] < largest) {
        goodCards[numGoodCards] = allPossible[j];
        j++;
        numGoodCards++;
    }
    
    int bestCard = goodCards[numGoodCards-1];
    
    return bestCard;
}