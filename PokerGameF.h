int end_turn(int pnum, int pot[1], int hand[2][4][13], int deck[4][13], int table[4][13], int bet[2], int win, int mon[2]);
int high_card(int pnum, int hand[2][4][13], int hdrk[2]);
int rank_hands(int pnum, int hand[2][4][13], int table[4][13]);
int start_turn(int hand[2][4][13], int deck[4][13], int mon[2], int bet[2], int bl[2], int pnum, char plyturn[2][20], int pot[1], int tmp[2], int round_counter[1]);
void flop (int deck[4][13], int table[4][13], int bet[2], int mx, int my);
void turn(int deck[4][13], int table[4][13], int bet[2], int mx, int my);
void river (int deck[4][13],int table[4][13], int bet[2], int mx, int my);
int round(int bet[2], int bl[2], int mon[2], int pot[1], int pnum, char plyturn[2][20], int hand[2][4][13], int table[4][13], int cd, int check[1], int tmp[2], int fold[1], int round_counter[1], int sl[1]);
int high_card2(int pnum, int hand[2][4][13], int hdrk[2], int hicard[2]);

int graphics(int mx, int my);
int main_graphics(int mx, int my, int i, int clicksum, int click[4], char plynms[2][11], int bl[2], char blc[2][10], int mon[2], char monc[10]);
int round_graphics(int mx, int my, int pnum, char plyturn[2][20], int x, int mon[2], int bet[2], int pot[1]);
int bet_graphics(int mx, int my, int bl[2], int bet[2], int pnum, int mon[2], int hand[2][4][13], int table[4][13], int cd, int end[1], int check[1], int fold[1], int round_counter[1], int pot[1], int sl[1]);
void switch_graphics(int MX, int MY, int pnum, char plyturn[2][20]);
void win_graphics(int MX, int MY, char plynms[2][11], int win, int mon[2]);
