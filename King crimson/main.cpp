#include "TXLib.h"

struct Button
{
    int x;
    int y;
    const char* text;
    string category;
};

void drawButton(Button btn)
{
    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);
    Win32::RoundRect (txDC(), btn.x+5, btn.y+5, btn.x+155, btn.y+45, 30, 30);
    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    Win32::RoundRect (txDC(), btn.x, btn.y, btn.x+150, btn.y+40, 30, 30);
    txSetColor (TX_BLACK);
    txSelectFont("Times New Roman", 32);
    txDrawText(btn.x, btn.y, btn.x+150, btn.y+40, btn.text);
}

bool Click(Button btn)
{
    return( txMouseButtons() == 1 &&
            txMouseX() >= btn.x &&
            txMouseX() <= btn.x+150 &&
            txMouseY() >= btn.y &&
            txMouseY() <= btn.y+40);
}


struct Pictures
{
    int x;
    int y;
    HDC image;
    int w;
    int h;
    int w_scr;
    int h_scr;
    bool visible;
    string category;
};

void drawPicture(Pictures pct)
{
    if(pct.visible)
    {
        Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.w_scr, pct.h_scr, pct.image, 0, 0, pct.w, pct.h, TX_WHITE);
    }
};


int main()
{
    txCreateWindow (1200, 800);
    txDisableAutoPause();
    txTextCursor (false);

    int COUNT_BTN = 5;
    int COUNT_PICTURES = 16;
    int vybor = -1;
    bool mouse_free = false;
    char str[100];

    //?????? ??????
    Button btn[COUNT_BTN];
    btn[0] = {100, 30, "???? ????", "????"};
    btn[1] = {260, 30, "??????", "??????"};
    btn[2] = {420, 30, "?????", "?????"};
    btn[3] = {580, 30, "????", "????"};
    btn[4] = {740, 30, "????", "????"};


    //?????? ????????-????
    Pictures menuPicture[COUNT_PICTURES];
    menuPicture[0] = {50, 100, txLoadImage ("Pictures/????/????1.bmp"), 450, 450, 65, 65, false, "????"};
    menuPicture[1] = {50, 200, txLoadImage ("Pictures/????/????2.bmp"), 450, 450, 65, 65, false, "????"};
    menuPicture[2] = {50, 300, txLoadImage ("Pictures/????/????3.bmp"), 450, 450, 65, 65, false, "????"};
    menuPicture[3] = {50, 100, txLoadImage ("Pictures/??????/??????1.bmp"), 350, 350, 65, 65, false, "??????"};
    menuPicture[4] = {50, 200, txLoadImage ("Pictures/??????/??????2.bmp"), 350, 350, 65, 65, false, "??????"};
    menuPicture[5] = {50, 300, txLoadImage ("Pictures/??????/??????3.bmp"), 350, 350, 65, 65, false, "??????"};
    menuPicture[6] = {50, 100, txLoadImage ("Pictures/?????/?????1.bmp"), 200, 65, 200, 65, false, "?????"};
    menuPicture[7] = {50, 200, txLoadImage ("Pictures/?????/?????2.bmp"), 200, 65, 200, 65, false, "?????"};
    menuPicture[8] = {50, 300, txLoadImage ("Pictures/?????/?????3.bmp"), 200, 65, 200, 65, false, "?????"};
    menuPicture[9] = {50, 100, txLoadImage ("Pictures/????/???1.bmp"), 50, 65, 50, 65, false, "????"};
    menuPicture[10] = {50, 200, txLoadImage ("Pictures/????/???2.bmp"), 50, 65, 50, 65, false, "????"};
    menuPicture[11] = {50, 300, txLoadImage ("Pictures/????/???3.bmp"), 50, 65, 50, 65, false, "????"};
    menuPicture[12] = {50, 100, txLoadImage ("Pictures/????/????1.bmp"), 100, 40, 100, 40, false, "????"};
    menuPicture[13] = {50, 200, txLoadImage ("Pictures/????/????2.bmp"), 100, 40, 100, 40, false, "????"};
    menuPicture[14] = {50, 300, txLoadImage ("Pictures/????/????3.bmp"), 100, 40, 100, 40, false, "????"};
    menuPicture[15] = {50, 400, txLoadImage ("Pictures/????/????4.bmp"), 100, 40, 100, 40, false, "????"};

    //?????? ???????? ? ??????
    Pictures centralPicture[COUNT_PICTURES];
    centralPicture[0] = {450, 200, menuPicture[0].image, menuPicture[0].w, menuPicture[0].h, menuPicture[0].w, menuPicture[0].h, menuPicture[0].visible, menuPicture[0].category};
    centralPicture[1] = {450, 200, menuPicture[1].image, menuPicture[1].w, menuPicture[1].h, menuPicture[1].w, menuPicture[1].h, menuPicture[1].visible, menuPicture[1].category};
    centralPicture[2] = {450, 200, menuPicture[2].image, menuPicture[2].w, menuPicture[2].h, menuPicture[2].w, menuPicture[2].h, menuPicture[2].visible, menuPicture[2].category};
    centralPicture[3] = {490, 150, menuPicture[3].image, menuPicture[3].w, menuPicture[3].h, menuPicture[3].w, menuPicture[3].h, menuPicture[3].visible, menuPicture[3].category};
    centralPicture[4] = {490, 150, menuPicture[4].image, menuPicture[4].w, menuPicture[4].h, menuPicture[4].w, menuPicture[4].h, menuPicture[4].visible, menuPicture[4].category};
    centralPicture[5] = {490, 150, menuPicture[5].image, menuPicture[5].w, menuPicture[5].h, menuPicture[5].w, menuPicture[5].h, menuPicture[5].visible, menuPicture[5].category};
    centralPicture[6] = {570, 400, menuPicture[6].image, menuPicture[6].w, menuPicture[6].h, menuPicture[6].w, menuPicture[6].h, menuPicture[6].visible, menuPicture[6].category};
    centralPicture[7] = {570, 400, menuPicture[7].image, menuPicture[7].w, menuPicture[7].h, menuPicture[7].w, menuPicture[7].h, menuPicture[7].visible, menuPicture[7].category};
    centralPicture[8] = {570, 400, menuPicture[8].image, menuPicture[8].w, menuPicture[8].h, menuPicture[8].w, menuPicture[8].h, menuPicture[8].visible, menuPicture[8].category};
    centralPicture[9] = {640, 460, menuPicture[9].image, menuPicture[9].w, menuPicture[9].h, menuPicture[9].w, menuPicture[9].h, menuPicture[9].visible, menuPicture[9].category};
    centralPicture[10] = {640, 460, menuPicture[10].image, menuPicture[10].w, menuPicture[10].h, menuPicture[10].w, menuPicture[10].h, menuPicture[10].visible, menuPicture[10].category};
    centralPicture[11] = {640, 460, menuPicture[11].image, menuPicture[11].w, menuPicture[11].h, menuPicture[11].w, menuPicture[11].h, menuPicture[11].visible, menuPicture[11].category};
    centralPicture[12] = {620, 550, menuPicture[12].image, menuPicture[12].w, menuPicture[12].h, menuPicture[12].w, menuPicture[12].h, menuPicture[12].visible, menuPicture[12].category};
    centralPicture[13] = {620, 550, menuPicture[13].image, menuPicture[13].w, menuPicture[13].h, menuPicture[13].w, menuPicture[13].h, menuPicture[13].visible, menuPicture[13].category};
    centralPicture[14] = {620, 550, menuPicture[14].image, menuPicture[14].w, menuPicture[14].h, menuPicture[14].w, menuPicture[14].h, menuPicture[14].visible, menuPicture[14].category};
    centralPicture[15] = {620, 550, menuPicture[15].image, menuPicture[15].w, menuPicture[15].h, menuPicture[15].w, menuPicture[15].h, menuPicture[15].visible, menuPicture[15].category};



    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetColor (TX_WHITE);
        txSetFillColor (TX_YELLOW);
        txClear();

        //????????? ??????
        for(int nk=0; nk<COUNT_BTN; nk++)
        {
            drawButton(btn[nk]);
        }

        //????????? ????-????????
        for(int npic=0; npic < COUNT_PICTURES; npic++)
        {
            drawPicture(menuPicture[npic]);
        }

        //????????? ???????? ? ??????
        for(int npic=0; npic < COUNT_PICTURES; npic++)
        {
            drawPicture(centralPicture[npic]);
        }

        //????????? ???????? ? ?????? ?? ????????? ????-????????
        for(int npic=0; npic < COUNT_PICTURES; npic++)
        {
            if(txMouseButtons() == 1 &&
                menuPicture[npic].visible &&
                txMouseX() >= menuPicture[npic].x &&
                txMouseX() <= menuPicture[npic].x + menuPicture[npic].w_scr &&
                txMouseY() >= menuPicture[npic].y &&
                txMouseY() <= menuPicture[npic].y + menuPicture[npic].h_scr)
                {
                    for(int npic1=0; npic1 < COUNT_PICTURES; npic1++)
                    {
                        if(centralPicture[npic1].category == centralPicture[npic].category)
                        {
                            centralPicture[npic1].visible = false;
                        }
                    }
                    centralPicture[npic].visible = !centralPicture[npic].visible;
                    txSleep(100);
                }
         }

        //????????? ????-???????? ?? ????????? ??????
        for(int nk=0; nk<COUNT_BTN; nk++)
        {
            if(Click(btn[nk]))
            {
                for(int npic=0; npic < COUNT_PICTURES; npic++)
                {
                    menuPicture[npic].visible = false;
                    if(menuPicture[npic].category == btn[nk].category)
                    {
                        menuPicture[npic].visible = true;
                    }
                }
            }
        }


        //????? ??????????? ????????
        for(int npic=0; npic < COUNT_PICTURES; npic++)
        {
            if(txMouseButtons() == 1 &&
                centralPicture[npic].visible &&
                txMouseX() >= centralPicture[npic].x &&
                txMouseX() <= centralPicture[npic].x + centralPicture[npic].w &&
                txMouseY() >= centralPicture[npic].y &&
                txMouseY() <= centralPicture[npic].y + centralPicture[npic].h)
                {
                    vybor=npic;
                    mouse_free = false;
                }
        }

        sprintf(str, "????? = %d", vybor);
        txTextOut(0,0, str);

        //???????????? ???????? ??????????? ???????? ?????????
        if(vybor>=0)
        {
            if(GetAsyncKeyState(VK_RIGHT)) centralPicture[vybor].x += 3;
            if(GetAsyncKeyState(VK_LEFT))  centralPicture[vybor].x -= 3;
            if(GetAsyncKeyState(VK_UP))    centralPicture[vybor].y -= 3;
            if(GetAsyncKeyState(VK_DOWN))  centralPicture[vybor].y += 3;

            if(GetAsyncKeyState(VK_OEM_PLUS))
            {
                centralPicture[vybor].w_scr = centralPicture[vybor].w_scr * 1.02;
                centralPicture[vybor].h_scr = centralPicture[vybor].h_scr * 1.02;;
            }

            if(GetAsyncKeyState(VK_OEM_MINUS))
            {
                centralPicture[vybor].w_scr = centralPicture[vybor].w_scr * 0.98;
                centralPicture[vybor].h_scr = centralPicture[vybor].h_scr * 0.988;
            }
        }


        //???????????? ???????? ??????????? ???????? ??????
        if(vybor>=0)
        {
            if(txMouseButtons() == 1 && !mouse_free)
            {
                centralPicture[vybor].x = txMouseX() - centralPicture[vybor].w/2;
                centralPicture[vybor].y = txMouseY() - centralPicture[vybor].h/2;
            }
            else
            {
                if(txMouseButtons() != 1)
                {
                    mouse_free = true;
                }
            }
        }


        txSleep(50);
        txEnd();

    }

    for(int npic=0; npic < COUNT_PICTURES; npic++)
    {
        txDeleteDC(menuPicture[npic].image);
    }


    for(int npic=0; npic < COUNT_PICTURES; npic++)
    {
        txDeleteDC(centralPicture[npic].image);
    }



return 0;
}

