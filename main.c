/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :Che Joseph Fuh
Student ID#:146644224
Email      :jfche@myseneca.ca
Section    :ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define maxPath 70
#define minPath 10
#define maxLive 10
#define minLive 1
#define five 5

#include <stdio.h>
struct PlayerInfo
{
    int numLives;
    char playerSymbol;
    int numTreasures;
    int pstPosition[maxPath];
};
struct GameInfo
{
    int moves;
    int pathLength;
    int bombs[maxPath];
    int treasures[maxPath];
    int history[maxPath];
};



int main(void)
{
    int flag = 0,g,p,c,v,b,o,i,k,a,s,d,counter1 = 0,counter2 = 0, position = 0, maj = 1,min = 1,nextMv = 0, pastMove = 0;
    char hyphen[maxPath] ={' '}, bar = '|';
    
    struct PlayerInfo player;
    struct GameInfo playInfo;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    
    printf("\nPLAYER Configuration\n");
    printf("--------------------\n");
            
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerSymbol);
    
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numLives);
        if (player.numLives < minLive || player.numLives > maxLive) {
            printf("     Must be between %d and %d!\n", minLive, maxLive);
        }
        else
        {
            printf("Player configuration set-up is complete\n");
        }
    } while (player.numLives < minLive || player.numLives > maxLive);
    
    printf("\nGAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ",five, minPath, maxPath);
        scanf("%d", &playInfo.pathLength);
        if (playInfo.pathLength % five == 0 ) {
            flag = 1;
        } else {
            printf("     Must be a multiple of %d and between %d-%d!!!\n",five, minPath, maxPath);
        }
    } while (flag == 0);
    flag = 0;
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&playInfo.moves);
        if (playInfo.moves >= player.numLives && playInfo.moves <= (int)(playInfo.pathLength * 0.75) ) {
                    flag = 1;
        } 
        else {
            printf("    Value must be between %d and %d\n", player.numLives,(int)(playInfo.pathLength * 0.75));
        }
    } while (flag == 0);
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n", five);
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", playInfo.pathLength);
    for (k = 0; k < (playInfo.pathLength / five); k++) {
        printf("   Positions [%2d-%2d]: ", position + 1, position + five);
        for (i = 0; i < five; i++)
        {
            scanf("%d", &playInfo.bombs[counter1++]);
        }
        position += five;
    }
    printf("BOMB placement set\n");
    
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n", five);
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", playInfo.pathLength);
    position = 0;
    for (k = 0; k < (playInfo.pathLength / five); k++) {
        printf("   Positions [%2d-%2d]: ", position + 1, position + five);
        for (i = 0; i < five; i++)
        {
            scanf("%d", &playInfo.treasures[counter2++]);
        }
        position += five;
    }
    printf("TREASURE placement set\n");
    
    printf("\nGAME configuration set-up is complete...\n");
    
    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    
    printf("Player:\n");
    printf("   Symbol     : %c\n",player.playerSymbol);
    printf("   Lives      : %d\n", player.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d", playInfo.pathLength);
    printf("\n   Bombs      : ");
    for (i = 0; i < playInfo.pathLength; i++) {
        printf("%d", playInfo.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < playInfo.pathLength; i++) {
        printf("%d", playInfo.treasures[i]);
    }
    printf("\n");
    
    
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    
    for(o = 0; o < playInfo.pathLength; o++){
        hyphen[o] = '-';
    }
    
    printf("\n  ");
    for(c = 0; c < playInfo.pathLength;  c++){
        printf("%c", hyphen[c]);
    }
    printf("\n  ");
    for (v = 0; v < playInfo.pathLength; v++){
        if ((v + 1) % 10 == 0){
            printf("%d", maj);
            maj++;
            
        }
        else{
            printf("%c", bar);
        }
    }
    printf("\n  ");
   for (b = 1; b <= playInfo.pathLength; b++) {
        if (b % 10 == 0){
            min = 0;
            printf("%d",min);
        }
        else if (b % 10 != 0){
            printf("%d",min);
        }
       min++;
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numLives, player.numTreasures, playInfo.moves);
    printf("+---------------------------------------------------+\n");

    do {
    
    do {
        flag = 0;
        printf("Next Move [1-%d]: ", playInfo.pathLength);
        scanf("%d",&nextMv);
        if (nextMv < 1 || nextMv > playInfo.pathLength) {
            printf("  Out of Range!!!\n");
        }
        else{
            flag = 1;
        }
    } while (flag == 0);
        printf("\n===============> ");
        pastMove = 0;
        for (p = 0; p < playInfo.pathLength; p++) {
            if (playInfo.history[p] == nextMv){
                pastMove = 1;
            }
        }
        flag = 0;
        while (flag == 0) {
            if (pastMove == 1 && playInfo.history[p] == nextMv) {
                printf("Dope! You've been here before!");
                flag = 1;
            }
           else if (playInfo.bombs[nextMv - 1] == 1 && playInfo.treasures[nextMv - 1] == 1)
            {
                printf("[&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.numTreasures += 1;
                flag = 1;
                player.numLives--;
                playInfo.moves--;
                if(player.numLives == 0){
                    printf("\nNo more LIVES remaining!\n");
                }
            }
            else if (playInfo.bombs[nextMv -1] == 1 && playInfo.treasures[nextMv - 1] == 0 )
            {
                printf("[!] !!! BOOOOOM !!! [!]\n");
                player.numLives--;
                playInfo.moves--;
                flag = 1;
                if(player.numLives == 0){
                    printf("\nNo more LIVES remaining!\n");
                }
            }
            else if(playInfo.bombs[nextMv -1] == 0 && playInfo.treasures[nextMv - 1] == 1 )
            {
                printf("[$] $$$ Found Treasure! $$$ [$]\n");
                player.numTreasures += 1;
                playInfo.moves--;
                flag = 1;
            }
           else if (playInfo.bombs[nextMv -1] == 0 && playInfo.treasures[nextMv - 1] == 0 )
           {
               printf("[.] ...Nothing found here... [.]\n");
               playInfo.moves--;
               flag = 1;
           }
        }
        
        
        printf("\n  ");
        for(g = 0; g <= nextMv + 1; g++){
            if (nextMv > 1 ) {
                printf(" ");
            }
            
            if (nextMv == 1 && nextMv - 1 == g) {
                playInfo.history[g] = nextMv;
                printf("%c", player.playerSymbol);
            }
            else if (nextMv > 1 && nextMv - 2 == g){
                playInfo.history[g] = nextMv;
                printf("%c", player.playerSymbol);
            }
        }
            
        printf("\n");
    printf("  ");
    for (a = 0; a < playInfo.pathLength;  a++) {
        
        if (nextMv - 1 == a && playInfo.bombs[nextMv - 1] == 1 && playInfo.treasures[nextMv - 1] == 1){
            playInfo.history[a] = nextMv - 1;
            hyphen[nextMv - 1] = '&';
            printf("%c", hyphen[nextMv - 1]);
            
        }
        else if (nextMv - 1 == a && playInfo.bombs[nextMv - 1] == 1){
            
            hyphen[nextMv - 1] = '!';
            printf("%c", hyphen[nextMv - 1]);
        }
        else if (nextMv - 1 == a && playInfo.treasures[nextMv - 1] == 1){
            
            hyphen[nextMv - 1] = '$';
            printf("%c", hyphen[nextMv - 1]);
        }
        else if (nextMv - 1 == a && playInfo.bombs[nextMv - 1] == 0 && playInfo.treasures[nextMv - 1] == 0 ){
                
                hyphen[nextMv - 1] = '.';
                printf("%c", hyphen[nextMv - 1]);
                
        }
             else{
            printf("%c", hyphen[a]);
        }
        
    }
    printf("\n  ");
        maj = 1;
    for (s = 0; s < playInfo.pathLength; s++){
        if ((s + 1) % 10 == 0){
            printf("%d", maj);
            maj++;
        }
        else{
            printf("%c", bar);
        }
    }
    printf("\n  ");
   for (d = 1; d <= playInfo.pathLength; d++) {
        if (d % 10 == 0){
            min = 0;
            printf("%d",min);
        }
        else if (d % 10 != 0){
            printf("%d",min);
        }
        min++;
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numLives, player.numTreasures, playInfo.moves);
    printf("+---------------------------------------------------+\n");
        
        
        //printf("===============> ");
    } while (player.numLives > 0);
    
    printf("\n##################\n");
    printf("#   Game over!   #");
    printf("\n##################\n");
    
    printf("\nYould play again and try to beat your score!\n");
    
    return 0;
}

 
