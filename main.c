#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include "PokerGameF.h"

int main() { //1542 lines of code

    initwindow(800, 650, "Poker Game");
    system("COLOR 2F");

    //declaring all the necessary arrays, strings, and variables
    int pot[1]={0}, mon[2], bet[2], pnum=0, win=3, hicard[2], hicard2[2], hdrk[2], bl[2]={0}, fold[1]={2}, round_counter[1], sl[1]={0};
    //pnum(player number), win(the winner), hdrk (handrank), bl (blinds),
    int deck[4][13] = {0}, hand[2][4][13] = {0}, table[4][13] = {0};
    char plynms[2][11], plyturn[2][20], blc[2][10], monc[10]; //player names, blinds (character)
    int MX, MY, click[4]={0}, clicksum, i=35, o, cl=0, check[1]={0}, tmp[2], temp, u;

    graphics(MX, MY);

    printf("\t\t\tWelcome to 1v1 Texas Hold'em\n\t\t      Know your limits, play within'em\n\n"); //prompting user in the console
    printf("  If a question does not allow you to enter anything into the console, simply\n  re-click the allocated space\n\n"); //further instructions

    // The initializing graphics (includes title, short sloganand necessary inputs for users)
    settextstyle(1, HORIZ_DIR, 0);
    outtextxy(60, 30, "Welcome to 1v1 Texas Hold'em");
    settextstyle(1, HORIZ_DIR, 2.5);
    outtextxy(165, 300, "Know your limits, play within 'em");

        settextstyle(0, HORIZ_DIR, 0);
    outtextxy(60, 80,"Enter Player 1 name:");
        setfillstyle(SOLID_FILL, BLACK);
        bar(260, 83, 370, 95);

        settextstyle(0, HORIZ_DIR, 0);
    outtextxy(385+i, 80,"Enter Player 2 name:");
        setfillstyle(SOLID_FILL, BLACK);
        bar(586+i, 83, 697+i, 95);
    setfillstyle(XHATCH_FILL, BLACK);
        settextstyle(0, HORIZ_DIR, 0);
    outtextxy(60, 120,"Enter Big Blind:$");
        setfillstyle(SOLID_FILL, BLACK);
        bar(235, 123, 370, 135);

        settextstyle(0, HORIZ_DIR, 0);
    outtextxy(385+i, 120,"Enter Small Blind:$");
        setfillstyle(SOLID_FILL, BLACK);
        bar(580+i, 123, 697+i, 135);

        settextstyle(0, HORIZ_DIR, 0);
    outtextxy(60, 160,"Enter Starting Cash:$");
        setfillstyle(SOLID_FILL, BLACK);
        bar(275, 163, 370, 175);

    //intializing graphics (player names etc)

while(1){

clicksum=main_graphics(MX, MY, i, clicksum, click, plynms, bl, blc, mon, monc); // recieves users input throughthe graphics and console

    if(clicksum>=4){
    if(!cl){
    setfillstyle(SOLID_FILL, BLACK);
    bar(325, 330, 475, 380);
    settextstyle(1, HORIZ_DIR, 0);

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(330, 340, "NEXT");
    cl=1;
    }

    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 325) && (MX < 475) && (MY > 330) && (MY < 380)){ // next button allowing players to begin the game
                break;
            }
        }
    }
}
    i=0;
    strcpy(plyturn[0],plynms[0]);
    strcat(plyturn[0],"'s Turn"); // adding "'s turn" to the end of the players' names for ease of use
    strcpy(plyturn[1],plynms[1]);
    strcat(plyturn[1],"'s Turn");
    tmp[0]=mon[0];
    tmp[1]=mon[1];

    pot[0]=end_turn(pnum, pot, hand, deck, table, bet, win, mon);//setting deck and hands before start of game

while(mon[0]!=0 && mon[1]!=0){
    fold[0]=2;
    pot[0]=0;
    start_turn(hand, deck, mon, bet, bl, pnum, plyturn, pot, tmp, round_counter); // the start of the round, deals the players cards and assigns the blinds

    if(bl[0]>bl[1]) // determines which player goes first in the rounds this set (set of rounds includes the flop, turn, and river)
        pnum=1;
    else
        pnum=0;

    round(bet, bl, mon, pot, pnum, plyturn, hand, table, 0, check, tmp, fold, round_counter, sl); // first round, allows players to bet dependant on their own hands only

if(fold[0]==2){ //these if statements end the round if a player folded
    flop(deck, table, bet, MX, MY); // deals and reveals three new cards

    round( bet, bl, mon, pot, pnum, plyturn, hand, table, 1, check, tmp, fold, round_counter, sl); //second round, players now bet dependant on the three cards revealed in the flop
if(fold[0]==2){
    turn(deck, table, bet, MX, MY); // deals and reveals one new card

    round( bet, bl, mon, pot, pnum, plyturn, hand, table, 2, check, tmp, fold, round_counter, sl); //third round, players bet on the fourth revealed card
if(fold[0]==2){
    river( deck, table, bet, MX, MY); // deals and reveals one new card

    round( bet, bl, mon, pot, pnum, plyturn, hand, table, 3, check, tmp, fold, round_counter, sl); //fourth round, players bet on the fifth and final card
if(fold[0]==2){

    for(pnum=0;pnum<2;pnum++){ // resets player handrank and highcard
        hdrk[pnum]=0;
        hicard[pnum]=0;
    }



    for(pnum=0; pnum<2;pnum++){ // assigns players their current hand rank and highcard
        hdrk[pnum]=rank_hands(pnum, hand, table);
        hicard[pnum]=high_card(pnum, hand, hdrk);
        hicard2[pnum]=high_card2( pnum, hand, hdrk, hicard);
    }


    if(hdrk[0]>hdrk[1]) //winner is determined based on hand rank and highcard
        win=0;
    else if(hdrk[0]<hdrk[1])
        win=1;
    else {//if(hdrk[0]==hdrk[1]){
            if(hicard[0]>hicard[1])
                win=0;
            else if(hicard[0]<hicard[1])
                win=1;
            else{
                if(hicard2[0]>hicard2[1])
                win=0;
                else if(hicard2[0]<hicard2[1])
                win=1;
                else
                    win=2;
            }
    }
}
}
}
}
if(fold[0]==0) //if a player folded winner is also determined
    win=1;
if(fold[0]==1)
    win=0;

    printf("\nThe table was\n");
    for(o=0;o<4;o++){
        for(i=0;i<13;i++){
        if(table[o][i]){
                u=i;
                switch(i){
                case 0: i='2';
                    break;
                case 1: i='3';
                    break;
                case 2: i='4';
                    break;
                case 3: i='5';
                    break;
                case 4: i='6';
                    break;
                case 5: i='7';
                    break;
                case 6: i='8';
                    break;
                case 7: i='9';
                    break;
                case 8: i='1';
                    break;
                case 9: i='J';
                    break;
                case 10: i='Q';
                    break;
                case 11: i='K';
                    break;
                case 12: i='A';
                    break;
                default:
                    break;
            }
            if(i=='1')
                printf("%c%c0\n", o+3, i);
            else
                printf("%c%c\n", o+3, i);
            i=u;
        }
    }
}
    putchar('\n');

    temp=pnum;
    for(pnum=0;pnum<2;pnum++){
        printf("\n\nPlayer %shad the cards:\n", plynms[pnum]);
        for(i=0;i<13;i++){
            for(o=0;o<4;o++){
                if((hand[pnum][o][i]==1)&&(table[o][i]==0)){
                    u=i;
                    switch(i){
                    case 0: i='2';
                        break;
                    case 1: i='3';
                        break;
                    case 2: i='4';
                        break;
                    case 3: i='5';
                        break;
                    case 4: i='6';
                        break;
                    case 5: i='7';
                        break;
                    case 6: i='8';
                        break;
                    case 7: i='9';
                        break;
                    case 8: i='10';
                        break;
                    case 9: i='J';
                        break;
                    case 10: i='Q';
                        break;
                    case 11: i='K';
                        break;
                    case 12: i='A';
                        break;
                    default:
                        break;
                    }
                    printf("%c%c\n", o+3, i);
                    i=u;
                }
            }
        }
        printf("Their hand was ");
        switch (hdrk[pnum]){
        case 1: printf("a Pair");
            break;
        case 2: printf("Two pairs");
            break;
        case 3: printf("a Three of a Kind");
            break;
        case 4: printf("a Straight");
            break;
        case 5: printf("a Flush");
            break;
        case 6: printf("a Full House");
            break;
        case 7: printf("a Four of a Kind");
            break;
        case 8: printf("a Straight Flush");
            break;
        case 9: printf("a Royal Flush");
            break;
        default: printf("a High Card");
            break;
        }
        putchar('\n');
    }
    pnum=temp;

    pnum=end_turn(pnum, pot, hand, deck, table, bet, win, mon); // resets table and deck and etc. also gives/splits pot as necessary between the players

    win_graphics( MX, MY, plynms, win, mon); // displays which player won
}

/////////////////////////////////////////////////////////////////////

    closegraph();
    return pnum;

}
