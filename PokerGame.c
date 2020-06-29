#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include "PokerGameF.h"

int round(int bet[2], int bl[2], int mon[2], int pot[1], int pnum, char plyturn[2][20], int hand[2][4][13], int table[4][13], int cd, int check[1], int tmp[2], int fold[1], int round_counter[1], int sl[1]){

    int MX, MY, end[1]={0};

    do{ //This while loop continues until one of the requirements for the betting to end occurs

            cleardevice();
            switch_graphics( MX, MY, pnum, plyturn);//loading screen between players to insure player 1 can't see player 2's cards
            round_graphics(MX, MY, pnum, plyturn, 2, mon, bet, pot); // creates the graphics of the cards on the table and chips
            outtextxy(250, 25, plyturn[pnum]);// displays the player's name


            pot[0]+=bet_graphics(MX, MY, bl, bet, pnum, mon, hand, table, cd, end, check, fold, round_counter, pot, sl); //player can now decide how much they wish to bet or how they wish to act this round


        if(pnum) //swaps player for next round
            pnum=0;
        else
            pnum=1;

        if(end[0]){ //if the requirements to continue have been meet the loop breaks
            check[0]=0;
            end[0]=0;
            break;
        }

    }while(1);

    sl[0]=0;

    mon[0]-=bet[0]; //deduct the mmoney bet from player's cash
    mon[1]-=bet[1];

    bet[0]=0; //reset their betting values
    bet[1]=0;

    round_counter[0]++;

    return pot[0];
}

int end_turn(int pnum, int pot[1], int hand[2][4][13], int deck[4][13], int table[4][13], int bet[2], int win, int mon[2]){ // give pot to winner, reset pot, hand & deck

    int MX=0, MY=0;

    cleardevice();
    graphics(MX, MY);

    if(win==1){ //depending on which player won the pot is given or split.
        mon[1]+=pot[0];
    }
    else if (win==0){
        mon[0]+=pot[0];
    }
    else if(win==2){
        mon[0]+=pot[0]/2;
        mon[1]+=pot[0]/2;
    }

    int i, o;
    if(pnum==1){ //swaps what player goes first
        pnum=0;
    }
    else{
        pnum=1;
    }
    for(i=0; i<4;i++){ //resets the deck, table and hands
        for(o=0; o<13; o++){
            deck[i][o]=1;
            hand[1][i][o]=0;
            hand[0][i][o]=0;
            table[i][o]=0;
        }
    }

   for(i=0;i<2;i++) //resets the bets (only essential for the first use of endturn
        bet[i]=0;


    return pnum;
}

int high_card(int pnum, int hand[2][4][13], int hdrk[2]){
    int i=0, o=0, c=0, t=0, u=0, q=0, p=0, temp=0;

    switch (hdrk[pnum]){
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
        for(i=0;i<13;i++){
            c=0;
            for(o=0;o<4;o++){
                if(hand[pnum][o][i]==1){
                    c++;
                }
            }
            if(c==2 && t<1){
                temp=i;
            }
            if(c==3 && t<2){
                temp=i;
                t=1;
            }
            if(c==4 && t<3){
                temp=i;
                t=2;
            }
        }
        break;

    case 4:
    case 8:
        for(o=-1;o<13;o++){ // Checks for straight
        q=p;
        for(i=0;i<4;i++){
            if(o==-1){
                if(hand[pnum][i][12]==1){
                    p++;
                    break;
                }
            }

            else if (hand[pnum][i][o]==1){
                p++;
                break;
            }
        }
        if(p==5){
            temp=o;
        }
        if(q==p)
            p=0;
    }

    break;

    case 5:
        for(i=0;i<4;i++){ // Checks for flush
        c=0;
        for(o=0;o<13;o++){
            if (hand[pnum][i][o]==1){
                c++;
                u=o;
            }
        }
        if (c>=5){
            temp=u;
        }
    }
    break;

    default: temp=12;
    break;
    }

    return temp; //returns value of highest card
}

int high_card2(int pnum, int hand[2][4][13], int hdrk[2], int hicard[2]){
    int rank, i, o;
    switch (hdrk[0]){
case 1:
case 2:
case 3:
case 7:
    for(i=0;i<13;i++){
        for(o=0;o<4;o++){
        if (hand[pnum][o][i])
            if(hicard[pnum]!=i)
             rank=i;
        }
    }
    break;
default:
    rank=0;
    break;
    }
    return rank;
}

int rank_hands(int pnum, int hand[2][4][13], int table[4][13]){
    int i, o, c=0, f=0, t=0, p=0, q=0, s=0, rank=0;

    for(i=0;i<13;i++){ // adds the table to the players hand
        for(o=0;o<4;o++){
            if(table[o][i]){
                hand[pnum][o][i]=1;
            }
        }
    }

    for(i=0;i<13;i++){ // Checks for one pair
        c=0;
        for(o=0;o<4;o++){
            if(hand[pnum][o][i]==1)
            c++;
        }
        if(c==2){
            rank=1;
            if(f==0)
            f++;
        }
    }

    for(i=0;i<13;i++){ // Checks for two pairs
        c=0;
        for(o=0;o<4;o++){
            if(hand[pnum][o][i]==1){
            c++;
            }
        }
        if(c==2)
            t++;
        if(t==2)
            rank=2;
    }

    for(i=0;i<13;i++){ //  Checks for three of a kind
        c=0;
        for(o=0;o<4;o++){
            if((hand[pnum][o][i]==1))
                c++;
        }
        if(c==3){
            rank=3;
            f++;
        }
    }

    for(o=-1;o<13;o++){ // Checks for straight
        q=p;
        for(i=0;i<4;i++){
            if(o==-1){
                if(hand[pnum][i][12]==1){
                    p++;
                    break;
                }
            }

            else if (hand[pnum][i][o]==1){
                p++;
                break;
            }
        }
        if(p==5){
            rank=4;
            s=1;
        }
        if(q==p)
            p=0;
    }


    for(i=0;i<4;i++){ // Checks for flush
        c=0;
        for(o=0;o<13;o++){
            if (hand[pnum][i][o]==1)
                c++;
        }
        if (c>=5){
            rank=5;
            s++;
        }
    }

    if(f==2){ // Checks for full house
        rank=6;
    }

    for(i=0;i<13;i++){ // Checks for four of a kind
        if(hand[pnum][0][i]&&hand[pnum][1][i]&&hand[pnum][2][i]&&hand[pnum][3][i])
            rank=7;
    }

    if(s==2) // Checks for straight flush
        rank=8;

    for(i=0;i<4;i++){ // Checks for royal flush
        if((hand[pnum][i][12]==1)&&(hand[pnum][i][11]==1)&&(hand[pnum][i][10]==1)&&(hand[pnum][i][9]==1)&&(hand[pnum][i][8]==1))
            rank=9;
    }

    return rank;
}

int start_turn(int hand[2][4][13], int deck[4][13], int mon[2], int bet[2], int bl[2], int pnum, char plyturn[2][20], int pot[1], int tmp[2], int round_counter[1]){ //pot=start_turn()
    int c, r, temp, i, MX=0, MY=0;
    srand(time(NULL));

    round_counter[0]=0;// resets round counter

    //start turn graphics function
    cleardevice();
    graphics(MX, MY);

    bet[0]=bl[1]; // each players bet equals their blind
    bet[1]=bl[0];

    temp=bl[0]; //swaps blinds
    bl[0]=bl[1];
    bl[1]=temp;

    round_graphics(MX, MY, pnum, plyturn, 1, mon, bet, pot); // first round graphics

    for(pnum=0;pnum<2;pnum++){ //deals card to each player
        for(i=0;i<2;i++){ // deals two cards
            do{ // continues untill a card has been add
                temp=1;
                r=rand()%4;
                c=rand()%13;
                if(deck[r][c]==1){
                    hand[pnum][r][c]=1;
                    deck[r][c]=0;
                    temp=0;
                }
            }while(temp);
        }

    }
    return bl[1]+bl[0];
}

void flop(int deck[4][13], int table[4][13], int bet[2], int MX, int MY){
    srand(time(NULL));
    int i, r, c, temp;

    graphics(MX, MY);

    setfillstyle(SOLID_FILL, BLACK);
    bar(240, 335, 555, 425);
    settextstyle(1, HORIZ_DIR, 7); // builds black box background of the next button

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(255, 350, "NEXT"); //prints "NEXT"

    settextstyle(1, HORIZ_DIR, 5);
    setcolor(RED);
    setbkcolor(GREEN);
    outtextxy(265, 230, "The Flop");//prints "The Flop"

    while(1){ //next button and loading sceen to signal the Flop has occured
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 240) && (MX < 555) && (MY > 335) && (MY < 425)){
                break;
            }
        }
    }

        for(i=0;i<3;i++){ // deals three cards onto the table
            do{ // insure it is three new cards
                temp=1;
                r=rand()%4;
                c=rand()%13;
                if(deck[r][c]==1){
                    table[r][c]=1;
                    deck[r][c]=0;
                    temp=0;
                }
            }while(temp);
        }
}
void turn(int deck[4][13], int table[4][13], int bet[2], int MX, int MY){
    srand(time(NULL));
    int i, r, c, temp;

    graphics(MX, MY);

    setfillstyle(SOLID_FILL, BLACK);
    bar(240, 335, 555, 425);
    settextstyle(1, HORIZ_DIR, 7); // builds black box background of the next button

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(255, 350, "NEXT"); //prints "NEXT"

    settextstyle(1, HORIZ_DIR, 5);
    setcolor(RED);
    setbkcolor(GREEN);
    outtextxy(265, 230, "The Turn");//prints "The Turn"

    while(1){ //next button and loading sceen to signal the turn has occured
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 240) && (MX < 555) && (MY > 335) && (MY < 425)){
                break;
            }
        }
    }

    for(i=3;i<4;i++){  // deals a cards onto the table
            do{ // insures it's a new card
                temp=1;
                r=rand()%4;
                c=rand()%13;
                if(deck[r][c]==1){
                    table[r][c]=1;
                    deck[r][c]=0;
                    temp=0;
                }
            }while(temp);
        }
}
void river(int deck[4][13], int table[4][13], int bet[2], int MX, int MY){
    srand(time(NULL));
    int i, r, c, temp;

    graphics(MX, MY);

        setfillstyle(SOLID_FILL, BLACK);
    bar(240, 335, 555, 425);
    settextstyle(1, HORIZ_DIR, 7); // builds black box background of the next button

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(255, 350, "NEXT"); //prints "NEXT"

    settextstyle(1, HORIZ_DIR, 5);
    setcolor(RED);
    setbkcolor(GREEN);
    outtextxy(265, 230, "The River"); //prints " The River"

    while(1){ //next button and loading sceen to signal the river has occured
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 240) && (MX < 555) && (MY > 335) && (MY < 425)){
                break;
            }
        }
    }

    for(i=4;i<5;i++){ // deals a cards onto the table
            do{ // insures it's a new card
                temp=1;
                r=rand()%4;
                c=rand()%13;
                if(deck[r][c]==1){
                    table[r][c]=1;
                    deck[r][c]=0;
                    temp=0;
                }
            }while(temp);
        }
}
