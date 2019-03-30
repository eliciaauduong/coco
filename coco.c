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
#define N_CARDS_RECEIVED      3

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
// int read_nums(int nums[len]);

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
    int placement = N_CARDS_INITIAL_HAND - 1;
    while (numberDiscarded < N_CARDS_DISCARDED) {
        printf("%d ", myCards[placement]);
        placement = placement - 1;
        numberDiscarded++;
    }

}


void choose_card_to_play(void) {

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    int counterN = 0;
    int numbers[N_CARDS_DISCARDED] = {0};
    while (counterN < N_CARDS_DISCARDED) {
        scanf("%d", &numbers[counterN]);
        counterN++;
    }
    int numberInHand = numbers[0];
    int numberCardsPlayed = numbers[1];
    int tablePosition = numbers[2];
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    int counterH = 0;
    int cardsInHand[MAX_SIZE];
    while (counterH < numberInHand) {
        scanf("%d", &cardsInHand[counterH]);
        // printf("%d\n", cardsInHand[counterH]);
        counterH++;
    }

    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    int counterP = 0;
    int previouslyPlayed[MAX_SIZE];
    while (counterP < numberCardsPlayed) {
        scanf("%d", &previouslyPlayed[counterP]);
        counterP++;
    }
    
    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
    
    int counterS = 0;
    int round = N_CARDS_INITIAL_HAND - numberInHand;
    int numberPlayed = round * N_PLAYERS;
    int gameHistory[MAX_SIZE];
    while (counterS < numberPlayed) {
        scanf("%d", &gameHistory[counterS]);
        counterS++;
    }
    
    // scan in discarded cards from the beginning
    int counterD = 0;
    int discardedCards[MAX_SIZE];
    while (counterD < N_CARDS_DISCARDED) {
        scanf("%d", &discardedCards[counterD]);
        counterD++;
    }
    // scan in received cards from the beginning
    int counterR = 0;
    int receivedCards[MAX_SIZE];
    while (counterR < N_CARDS_RECEIVED) {
        scanf("%d", &receivedCards[counterR]);
        counterR++;
    }
    
    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    
    
    
}

// ADD YOUR FUNCTIONS HERE
