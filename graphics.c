#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include "PokerGameF.h"


int graphics(int mx, int my){

    setbkcolor(2);

    setfillstyle(XHATCH_FILL, BLACK);
    bar(0, 0, 800, 650);

    setfillstyle(SOLID_FILL, GREEN);
    bar(50, 25, 750, 600);

    settextstyle(1, HORIZ_DIR, 0);
    setcolor(RED);

return 0;

}

int round_graphics(int mx, int my, int pnum, char plysturn[2][20], int x, int mon[2], int bet[2], int pot[1]){

int i=240, j=240, w=160, onum;
    //Each card is 80 pixels in length and 130 pixels in width. The red XHatch is 8 pixels from each side
    setbkcolor(WHITE);

//Player 1
    setfillstyle(SOLID_FILL, WHITE);
    bar(i, 390, i+80, 520);
    setfillstyle(XHATCH_FILL, RED);
    bar(i+8, 398, i+72, 512);

    setfillstyle(SOLID_FILL, WHITE);
    bar(i+100, 390, i+180, 520);
    setfillstyle(XHATCH_FILL, RED);
    bar(i+108, 398, i+172, 512);

if(x==1)
delay(1000);

//Player 2
    setfillstyle(SOLID_FILL, WHITE);
    bar(i, 70, i+80, 200);
    setfillstyle(XHATCH_FILL, RED);
    bar(i+8, 78, i+72, 192);

    setfillstyle(SOLID_FILL, WHITE);
    bar(i+100, 70, i+180, 200);
    setfillstyle(XHATCH_FILL, RED);
    bar(i+108, 78, i+172, 192);

if(x==1)
delay(1000);

//Table

    setfillstyle(SOLID_FILL, WHITE);
    bar(j-160, 70+w, j+80-160, 200+w);
    setfillstyle(XHATCH_FILL, RED);
    bar(j+8-160, 78+w, j+72-160, 192+w);

    setfillstyle(SOLID_FILL, WHITE);
    bar(j-20, 70+w, j+80-20, 200+w);
    setfillstyle(XHATCH_FILL, RED);
    bar(j+8-20, 78+w, j+72-20, 192+w);

    setfillstyle(SOLID_FILL, WHITE);
    bar(j+120, 70+w, j+200, 200+w);
    setfillstyle(XHATCH_FILL, RED);
    bar(j+128, 78+w, j+192, 192+w);

if(x==1)
delay(1000);

    setfillstyle(SOLID_FILL, WHITE);
    bar(j+120+140, 70+w, j+200+140, 200+w);
    setfillstyle(XHATCH_FILL, RED);
    bar(j+128+140, 78+w, j+192+140, 192+w);

if(x==1)
delay(1000);

    setfillstyle(SOLID_FILL, WHITE);
    bar(j+120+280, 70+w, j+200+280, 200+w);
    setfillstyle(XHATCH_FILL, RED);
    bar(j+128+280, 78+w, j+192+280, 192+w);

if(x==1)
delay(1000);

if(x>1){
//Buttons
    setfillstyle(SOLID_FILL, BLACK);
    bar(70, 535, 200, 585);
    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(1, HORIZ_DIR, 0);
    outtextxy(85, 546, "Fold");

    setfillstyle(SOLID_FILL, BLACK);
    bar(70+165, 535, 220+185, 585);
    settextstyle(1, HORIZ_DIR, 0);
    outtextxy(247+5, 546, "Check"); //(mx > 70+165) && (mx < 220+185) && (my > 535) && (my < 585)

    setfillstyle(SOLID_FILL, BLACK);
    bar(70+370, 535, 220+350, 585);
    settextstyle(1, HORIZ_DIR, 0);
    outtextxy(460, 546, "Call");

    setfillstyle(SOLID_FILL, BLACK);
    bar(70+535, 535, 220+500, 585);
    settextstyle(1, HORIZ_DIR, 0);
    outtextxy(625, 546, "Bet");

//Betting
    setfillstyle(SOLID_FILL, RED);
        bar(450, 390, 715, 520);

    setfillstyle(SOLID_FILL, GREEN);
    setcolor(RED);
    setbkcolor(GREEN);
        bar(658, 468, 703, 512);
    settextstyle(10, HORIZ_DIR, 5);
        outtextxy(668, 470, "+");

        setfillstyle(SOLID_FILL, WHITE);
        setbkcolor(BLUE);
        setcolor(BLUE);
        circle(485,428, 30);
        floodfill(480, 428, BLUE);
            settextstyle(1, HORIZ_DIR, 1);
                    setbkcolor(WHITE);
                    setcolor(BLACK);
            outtextxy(477, 420, "5");


        setbkcolor(WHITE);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, RED);
        circle(550,428, 30);
        floodfill(550, 428, WHITE);
            settextstyle(1, HORIZ_DIR, 1);
                    setbkcolor(RED);
                    setcolor(BLACK);
            outtextxy(535, 420, "20");

        setbkcolor(WHITE);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, GREEN);
        circle(615,428, 30);
        floodfill(615, 428, WHITE);
            settextstyle(1, HORIZ_DIR, 1);
                    setbkcolor(GREEN);
                    setcolor(BLACK);
            outtextxy(600, 420, "50");

        setbkcolor(WHITE);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BLUE);
        circle(680,428, 30);
        floodfill(680, 428, WHITE);
            settextstyle(1, HORIZ_DIR, 1);
                    setbkcolor(BLUE);
                    setcolor(BLACK);
            outtextxy(657, 420, "100");
}

    setcolor(RED);
    setbkcolor(2);

if(x>1){
    if(pnum)
        onum=0;
    else
        onum=1;

    char obal[40]="Their Current Cash:$", ob[10], obet[40]="Their Current Bet:$", obe[10], tpot[40]="The Pot:$", tpo[10];
    char pbal[25]="Your Current Cash:", ps[2]="$", pb[10], pbet[40]="Your Current Bet:", pbe[10];


    sprintf(ob,"%d",mon[onum]-bet[onum]);
    strcat(obal, ob);

    sprintf(obe,"%d",bet[onum]);
    strcat(obet, obe);

    sprintf(tpo,"%d",pot[0]);
    strcat(tpot, tpo);

    sprintf(pb,"%d",mon[pnum]-bet[pnum]);

    sprintf(pbe,"%d",bet[pnum]);

    setfillstyle(SOLID_FILL, GREEN);
    bar(429, 69, 749, 170);

    settextstyle(0, HORIZ_DIR, 0);
    outtextxy(430, 70, obal);
    outtextxy(430, 110, obet);
    outtextxy(430, 150, tpot);

    outtextxy(55, 390, pbal);
    outtextxy(65, 420, pb);
    outtextxy(55, 420, ps);
    outtextxy(55, 460, pbet);
    outtextxy(65, 490, pbe);
    outtextxy(55, 490, ps);
}

settextstyle(1, HORIZ_DIR, 0);

return 0;

}

int info(char betc[2][10], int pnum, int temp[2]){

char ety[10]="         ";

setfillstyle(SOLID_FILL, RED);
bar(450, 460, 650, 520);
strcpy(betc[pnum], ety);
sprintf(betc[pnum],"$%d",temp[pnum]);
setbkcolor(RED);
setcolor(BLACK);
settextstyle(1, HORIZ_DIR, 0);
outtextxy(460, 480,betc[pnum]);

setbkcolor(GREEN);
setcolor(RED);

return 0;
}

void cards(char ch[4][2], char cv[13][3]){

//Rank
    ch[0][0]='H';
    ch[0][1]='\0';

    ch[1][0]='D';
    ch[1][1]='\0';

    ch[2][0]='C';
    ch[2][1]='\0';

    ch[3][0]='S';
    ch[3][1]='\0';

//Number
    cv[0][0]='2';
    cv[0][1]='\0';

    cv[1][0]='3';
    cv[1][1]='\0';

    cv[2][0]='4';
    cv[2][1]='\0';

    cv[3][0]='5';
    cv[3][1]='\0';

    cv[4][0]='6';
    cv[4][1]='\0';

    cv[5][0]='7';
    cv[5][1]='\0';

    cv[6][0]='8';
    cv[6][1]='\0';

    cv[7][0]='9';
    cv[7][1]='\0';

    cv[8][0]='1';
    cv[8][1]='0';
    cv[8][2]='\0';

    cv[9][0]='J';
    cv[9][1]='\0';

    cv[10][0]='Q';
    cv[10][1]='\0';

    cv[11][0]='K';
    cv[11][1]='\0';

    cv[12][0]='A';
    cv[12][1]='\0';

}

int phd(int a){

    if(a==2||a==3){
    setcolor(BLACK);
        if(a==2)
            return 250;
        if(a==3)
            return 255;
    }
    else{
    setcolor(RED);
    return 250;
    }

}

int tb(int a){

    if(a==2||a==3){
    setcolor(BLACK);
        if(a==2)
            return 90;
        if(a==3)
            return 95;
    }
    else{
    setcolor(RED);
    return 90;
    }

}

int bet_graphics(int mx, int my, int bl[2], int bet[2], int pnum, int mon[2], int hand[2][4][13], int table[4][13], int cd, int end[1], int check[1], int fold[1], int round_counter[1], int pot[1], int sl[1]){

    int cl=0, mode=0, onum, temp[2]={0}, i=240, j=240, w=160, r, c, card=0, x;
    char betc[2][10], ch[4][2], cv[13][3];

    cards(ch, cv);

    if(pnum)
        onum=0;
    else
        onum=1;


    setcolor(RED);
    setbkcolor(WHITE);


//Player cards
    for(r=0;r<4;r++){
        for(c=0;c<13;c++){
            if(hand[pnum][r][c]==1)
                card++;

            if(card==1){
                setfillstyle(SOLID_FILL, WHITE);
                bar(i, 390, i+80, 520);
                x=phd(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x, 437, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(i+5, 395, cv[c]);
                card++;
            }
            if(card==3){
                setfillstyle(SOLID_FILL, WHITE);
                bar(i+100, 390, i+180, 520);
                x=phd(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x+100, 437, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(i+105, 395, cv[c]);
                card++;
            }
        }
    }

card=0;

//Table cards
if(cd>0){

    setfillstyle(SOLID_FILL, WHITE);
    bar(j-160, 70+w, j+80-160, 200+w);
    bar(j-20, 70+w, j+80-20, 200+w);
    bar(j+120, 70+w, j+200, 200+w);

if(cd>1)
    bar(j+120+140, 70+w, j+200+140, 200+w);

if(cd>2)
    bar(j+120+280, 70+w, j+200+280, 200+w);

    for(r=0;r<4;r++){
        for(c=0;c<13;c++){
            if(table[r][c]==1)
                card++;

            if(card==1){
                x=tb(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x, 277, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(j-155, 75+w, cv[c]);
                card++;
         }
            if(card==3){
                x=tb(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x+140, 277, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(j-15, 75+w, cv[c]);
                card++;
            }
            if(card==5){
                x=tb(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x+280, 277, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(j+125, 75+w, cv[c]);
                card++;
            }

            if(cd>1){
                if(card==7){
                x=tb(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x+420, 277, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(j+265, 75+w, cv[c]);
                card++;
                }
            }
            if(cd>2){
                if(card==9){
                x=tb(r);

                settextstyle(1, HORIZ_DIR, 6);
                outtextxy(x+560, 277, ch[r]);
                settextstyle(1, HORIZ_DIR, 3);
                outtextxy(j+405, 75+w, cv[c]);
                card++;
                }
            }
        }
    }
}

    info(betc, pnum, temp);

while(1){

getmouseclick(WM_LBUTTONDOWN, mx, my);

    if(GetAsyncKeyState(VK_LBUTTON)){
//+/- Button
            if((mx > 658) && (mx < 703) && (my > 468) && (my < 512)){
                ++cl;

                if(cl%2!=0){
                    settextstyle(10, HORIZ_DIR, 5);
                    outtextxy(668,470, "-");
                    mode=1;
                }
                if(cl%2==0){
                    settextstyle(10, HORIZ_DIR, 5);
                    outtextxy(668,470, "+");
                    mode=0;
                }
            }
//Betting Buttons
            if((mx > 465) && (mx < 505) && (my > 408) && (my < 448)){
                if(mode==0&& temp[pnum]+5<=mon[pnum]){//&& temp[pnum]+5<=mon[pnum]
                    temp[pnum]+=5;
                }
                if(mode==1&&(temp[pnum]-5)>=bet[onum]){
                    temp[pnum]-=5;
                }
            info(betc, pnum, temp);
            }
            if((mx > 530) && (mx < 570) && (my > 408) && (my < 448)){
                if(mode==0&& temp[pnum]+20<=mon[pnum]){
                    temp[pnum]+=20;
                }
                if(mode==1&&(temp[pnum]-20)>=bet[onum]){
                    temp[pnum]-=20;
                }
            info(betc, pnum, temp);
            }
            if((mx > 595) && (mx < 635) && (my > 408) && (my < 448)){
                if(mode==0&& temp[pnum]+50<=mon[pnum]){
                    temp[pnum]+=50;
                }
                if(mode==1&&(temp[pnum]-50)>=bet[onum]){
                    temp[pnum]-=50;
                }
            info(betc, pnum, temp);
            }
            if((mx > 660) && (mx < 700) && (my > 408) && (my < 448)){
                if(mode==0&& temp[pnum]+100<=mon[pnum]){
                    temp[pnum]+=100;
                }
                if(mode==1&&(temp[pnum]-100)>=bet[onum]){
                    temp[pnum]-=100;
                }
            info(betc, pnum, temp);
            }
            if((mx > 450) && (mx < 650) && (my > 460) && (my < 520)){//All-in button
                if(temp[pnum]!=mon[pnum]-bet[pnum]){
                    temp[pnum]=mon[pnum]-bet[pnum];
                    setbkcolor(RED);
                    setcolor(BLACK);
                    settextstyle(1, HORIZ_DIR, 0);
                    outtextxy(460, 480, "ALL IN");
                    setbkcolor(GREEN);
                    setcolor(RED);
                }
                else{
                    temp[pnum]=0;
                    info(betc, pnum, temp);
                }
            }
//Bet Button
    if((bet[pnum]+temp[pnum]>=bet[onum])&&temp[pnum]!=0){
            if((mx > 70+535) && (mx < 220+500) && (my > 535) && (my < 585)){
                sl++;
                bet[pnum]+=temp[pnum];
                check[0]=0;
                break;
            }
    }
//Call Button
            if(check[0]==0&&bet[pnum]<bet[onum]){
                if((mx > 70+370) && (mx < 220+350) && (my > 535) && (my < 585)){
                check[0]++;
                bet[pnum]=bet[onum];


                if(bet[onum]>=mon[pnum])
                bet[pnum]=mon[pnum];
                break;

                }
            }
//Check Button
            if(bet[pnum]==bet[onum]||(bet[pnum]==mon[pnum]&&bet[onum]==mon[onum])){
                if((mx > 70+165) && (mx < 220+185) && (my > 535) && (my < 585)){
                check[0]++;
                    if(check[0]==2){
                    end[0]=1;
                    if(round_counter[0]==0&&sl[0]==0){
                        return bet[pnum];
                        }
                    }
                    return 0;
                }
            }
//Fold Button
            if((mx > 70) && (mx < 200) && (my > 535) && (my < 585)){
                fold[0]=pnum;
                end[0]=1;
                return 0;
            }
    }
}

return bet[pnum];
}

int main_graphics(int mx, int my, int i, int clicksum, int click[4], char plynms[2][11], int bl[2], char blc[2][10], int mon[2], char monc[10]){

getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((mx > 260) && (mx < 375) && (my > 83) && (my < 95)){
                printf("Enter Player 1 name: ");
                if(click[0]!=1)
                click[0]=1;
                        fgets(plynms[0], 12, stdin);
                        printf("\n");
                        setfillstyle(SOLID_FILL, GREEN);
                        bar(260, 83, 370, 95);
                        setcolor(RED);
                        setbkcolor(GREEN);
                        settextstyle(0, HORIZ_DIR, 0);
                        outtextxy( 260, 80, plynms[0]);
            }

            if ((mx > 586+i) && (mx < 697+i) && (my > 83) && (my < 95)){
                printf("Enter Player 2 name: ");
                if(click[1]!=1)
                click[1]=1;
                        fgets(plynms[1], 12, stdin);
                        printf("\n");
                        setfillstyle(SOLID_FILL, GREEN);
                        bar(586+i, 83, 697+i, 95);
                        setcolor(RED);
                        setbkcolor(GREEN);
                        settextstyle(0, HORIZ_DIR, 0);
                        outtextxy(586+i, 80, plynms[1]);
            }

            if((mx > 230)&&(mx < 370)&&(my > 123)&&(my < 135)){
               printf("Enter Big Blind Amount: $");
               if(click[2]!=1)
               click[2]=1;
                    scanf("%d",&bl[0]);
                    sprintf(blc[0],"%d",bl[0]);
                    bl[1]=bl[0]/2+bl[1]%2;
                    sprintf(blc[1],"%d",bl[1]);
                    printf("\n");

               setfillstyle(SOLID_FILL, GREEN);
               bar(230, 123, 370, 135);
               setcolor(RED);
               setbkcolor(GREEN);
               settextstyle(0, HORIZ_DIR, 0);
               outtextxy(230, 120, blc[0]);

               setfillstyle(SOLID_FILL, GREEN);
               bar(576+i, 123, 697+i, 135);
               outtextxy(576+i, 120, blc[1]);
            }

            if((mx > 576+i)&&(mx < 697+i)&&(my > 123)&&(my < 135)){
               printf("Enter Small Blind Amount: $");
               if(click[2]!=1)
               click[2]=1;
                    scanf("%d",&bl[1]);
                    sprintf(blc[1],"%d",bl[1]);
                    bl[0]=bl[1]*2;
                    sprintf(blc[0],"%d",bl[0]);
                    printf("\n");

               setfillstyle(SOLID_FILL, GREEN);
               bar(230, 123, 370, 135);
               settextstyle(0, HORIZ_DIR, 0);
               setcolor(RED);
               setbkcolor(GREEN);
               outtextxy(230, 120, blc[0]);

               setfillstyle(SOLID_FILL, GREEN);
               setcolor(RED);
               setbkcolor(GREEN);
               bar(576+i, 123, 697+i, 135);
               outtextxy(576+i, 120, blc[1]);

            }

            if((mx > 275)&&(mx < 370)&&(my > 163)&&(my < 175)&&bl[0]!=0){
                printf("Enter Starting Cash: $");
                if(click[3]!=1)
                click[3]=1;
                    scanf("%d",&mon[0]);

                if(mon[0]>=(bl[0]*50)){
                    mon[1]=mon[0];
                    sprintf(monc,"%d",mon[0]);
                    printf("\n");

                setfillstyle(SOLID_FILL, GREEN);
                bar(275, 163, 370, 175);
                setcolor(RED);
                setbkcolor(GREEN);
                settextstyle(0, HORIZ_DIR, 0);
                outtextxy(275, 160, monc);
            }
            else{
        click[3]=0;
        printf("Re-enter a Starting Cash (Must be at least 50 Times bigger than the Big Blind)\n\n");
            }
        }

            clicksum=click[0]+click[1]+click[2]+click[3];

                return clicksum;
        }
}

void switch_graphics(int MX, int MY, int pnum, char plyturn[2][20]){
setbkcolor(2);

graphics(MX, MY);

setfillstyle(SOLID_FILL, BLACK);
    bar(240, 335, 555, 425);
    settextstyle(1, HORIZ_DIR, 0);

    settextstyle(1, HORIZ_DIR, 5);
    outtextxy(230, 230, plyturn[pnum]);

    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(1, HORIZ_DIR, 7);
    outtextxy(255, 350, "NEXT");

while(1){
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 240) && (MX < 555) && (MY > 335) && (MY < 425)){
                break;
            }
        }
    }

graphics(MX, MY);

}

void win_graphics(int MX, int MY, char plynms[2][11], int win, int mon[2]){

    char wn[40]="Player ";

if(win<2){
    cleardevice();
    graphics(MX, MY);
    strcat(wn, plynms[win]);
    strcat(wn, " Won!");
    outtextxy(220, 230, wn);
}

if(win==2){
        outtextxy(300, 230, "It's a tie");
}

if(mon[0]&&mon[1]){
    setfillstyle(SOLID_FILL, BLACK);
    bar(230, 335, 565, 425);
    settextstyle(1, HORIZ_DIR, 6);

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(240, 350, "Continue");

while(1){
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 230) && (MX < 565) && (MY > 335) && (MY < 425)){
                break;
                }
            }
        }
    }
else{

setfillstyle(SOLID_FILL, BLACK);
    bar(240, 335, 555, 425);
    settextstyle(1, HORIZ_DIR, 0);

    settextstyle(1, HORIZ_DIR, 4);
    outtextxy(220, 230, wn);

    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(1, HORIZ_DIR, 7);
    outtextxy(285, 350, "END");

    while(1){
    getmouseclick(WM_LBUTTONDOWN, MX, MY);

        if(GetAsyncKeyState(VK_LBUTTON)){

            if ((MX > 230) && (MX < 565) && (MY > 335) && (MY < 425)){
                break;
                }
            }
        }
    }
}
