#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <MMSystem.h>

using namespace std;
char score_str[0];
int delayWave=0,score;
class mc
{
public:
    int xo=50,yo=getmaxy()/2,ismoving=0;
    void print()
    {
        //road
        line(0,getmaxy()/2+200,1920,getmaxy()/2+200); //y=0
        line(0,getmaxy()/2,1920,getmaxy()/2); //y=1
        line(0,getmaxy()/2-200,1920,getmaxy()/2-200); //y=2
        if (GetAsyncKeyState(VK_SPACE))
        {
            //head
            circle(xo+15,yo-60,10);
            //body
            line(xo+15,yo-17,xo+15,yo-50);
            //legs
            line(xo,yo,xo+15,yo-17);
            line(xo+15,yo-17,xo+28,yo);
            //hand
            line(xo+15,yo-45,xo+27,yo-23);
            //sword
            line(xo+20,yo-30,xo+105,yo+55);
            line(xo+45,yo-30,xo+20,yo-5);
            line(xo+20,yo-5,xo+75,yo+50);
            line(xo+75,yo+50,xo+105,yo+55);
            line(xo+45,yo-30,xo+100,yo+25);
            line(xo+100,yo+25,xo+105,yo+55);

        }
        else
        {
            //head
			circle(xo+15,yo-60,10);
			//body
			line(xo+15,yo-17,xo+15,yo-50);
			//legs
			line(xo,yo,xo+15,yo-17);
			line(xo+15,yo-17,xo+28,yo);
			//hand
			line(xo+15,yo-45,xo+30,yo-30);
			//sword
			line(xo+20,yo-23,xo+110,yo-113);
			line(xo+27,yo-48,xo+45,yo-30);
			line(xo+45,yo-30,xo+105,yo-90);
			line(xo+105,yo-90,xo+110,yo-113);
			line(xo+27,yo-48,xo+87,yo-108);
			line(xo+87,yo-108,xo+110,yo-113);
        }
    }
    void gerak()
    {
        if(GetAsyncKeyState(VK_UP))
        {
            if(ismoving==0)
            {
                yo=yo-200;
                ismoving=1;
                if (yo<=getmaxy()/2-200) yo=getmaxy()/2-200;
            }
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            if(ismoving==0)
            {
                yo=yo+200;
                ismoving=1;
                if (yo>=getmaxy()/2+200) yo=getmaxy()/2+200;
            }
        }
        else ismoving=0;
    }
};

class Wave
{
private:
    int speed=5;
public:
    int xw,yw,cekWave,warna,isattacking=0;
    Wave()
    {
        xw=0;
        yw=0;
        cekWave=0;
        warna=rand()%10;
    }
    int updateWave(int x,int y)
    {
        if((xw==0)&&(yw==0)&&(cekWave==1))
        {
            xw=x;
            yw=y;
        }
        if(xw>getmaxx())
        {
            xw=0;
            yw=0;
            cekWave=0;
        }
        if(cekWave==1)
        {
            xw=xw+speed;
            arc(xw+50,yw-50,-90,-270,30);
            arc(xw+50,yw-50,-90,-270,50);
        }
    }
    int controlWave(int x,int y)
    {
        if(delayWave==0)
        {
            if (GetAsyncKeyState(VK_SPACE))
            {
                cekWave=1;
                if(xw==0&&yw==0)
                {
                    delayWave=7;
                }
            }
        }
        updateWave(x,y);
    }
};

class Monster1
{
public:
    int xm1=getmaxx()-rand()%400,ym1=rand()%3,v;
    void printm1()
    {
        if(ym1==0)ym1=getmaxy()/2+200;
        else if(ym1==1)ym1=getmaxy()/2;
        else if(ym1==2)ym1=getmaxy()/2-200;
        setcolor(4);
        //monster 1
        line(xm1-60,ym1-10,xm1-40,ym1-10);
        line(xm1-40,ym1-10,xm1-40,ym1-30);
        line(xm1-40,ym1-30,xm1-30,ym1-30);
        line(xm1-30,ym1-30,xm1-30,ym1-10);
        line(xm1-30,ym1-10,xm1-20,ym1-10);
        line(xm1-20,ym1-10,xm1-20,ym1-30);
        line(xm1-20,ym1-30,xm1-10,ym1-30);
        line(xm1-10,ym1-30,xm1-10,ym1-10);
        line(xm1-10,ym1-10,xm1,ym1-10);
        line(xm1,ym1-10,xm1,ym1-30);
        line(xm1,ym1-30,xm1+10,ym1-30);
        line(xm1+10,ym1-30,xm1+10,ym1-10);
        line(xm1+10,ym1-10,xm1+30,ym1-10);
        line(xm1+30,ym1-10,xm1+30,ym1-20);
        line(xm1+30,ym1-20,xm1+20,ym1-20);
        line(xm1+20,ym1-20,xm1+20,ym1-40);
        line(xm1+20,ym1-40,xm1+10,ym1-40);
        line(xm1+10,ym1-40,xm1+10,ym1-50);
        line(xm1+10,ym1-50,xm1+20,ym1-50);
        line(xm1+20,ym1-50,xm1+20,ym1-80);
        line(xm1+20,ym1-80,xm1,ym1-80);
        line(xm1,ym1-80,xm1,ym1-100);
        line(xm1,ym1-100,xm1-30,ym1-100);
        line(xm1-30,ym1-100,xm1-30,ym1-80);
        line(xm1-30,ym1-80,xm1-50,ym1-80);
        line(xm1-50,ym1-80,xm1-50,ym1-50);
        line(xm1-50,ym1-50,xm1-40,ym1-50);
        line(xm1-40,ym1-50,xm1-40,ym1-40);
        line(xm1-40,ym1-40,xm1-50,ym1-40);
        line(xm1-50,ym1-40,xm1-50,ym1-20);
        line(xm1-50,ym1-20,xm1-60,ym1-20);
        line(xm1-60,ym1-20,xm1-60,ym1-10);
        //eyes
        rectangle(xm1-40,ym1-70,xm1-30,ym1-60);
        rectangle(xm1-20,ym1-90,xm1-10,ym1-80);
        rectangle(xm1,ym1-70,xm1+10,ym1-60);
        setcolor(7);
    }
    void gerakm1()
    {
        v=5+rand()%5;
        xm1=xm1-v;
        if(xm1<-70)
        {
            xm1=getmaxx()-rand()%400;
        }
    }
    int hitbox(int xw, int yw)
    {
        if (xw>xm1-150&&xw<xm1+50&&yw>ym1-10&&yw<ym1+10)
        {
            xm1=getmaxx()-rand()%400;
            ym1=rand()%3;
            if(ym1==0)ym1=getmaxy()/2+200;
            else if(ym1==1)ym1=getmaxy()/2;
            else if(ym1==2)ym1=getmaxy()/2-200;
            return true;
        }
        return false;
    }
};

class Monster2
{
public:
    int xm2=getmaxx()-rand()%400,ym2=rand()%3,v,xskor2,yskor2;
    void printm2()
    {
        if(ym2==0)ym2=getmaxy()/2+200;
        else if(ym2==1)ym2=getmaxy()/2;
        else if(ym2==2)ym2=getmaxy()/2-200;
        setcolor(2);
        //monster 2
        line(xm2-50,ym2-10,xm2-40,ym2-10);
        line(xm2-40,ym2-10,xm2-40,ym2-20);
        line(xm2-40,ym2-20,xm2-30,ym2-20);
        line(xm2-30,ym2-20,xm2-30,ym2-10);
        line(xm2-30,ym2-10,xm2-20,ym2-10);
        line(xm2-20,ym2-10,xm2-20,ym2-20);
        line(xm2-20,ym2-20,xm2-10,ym2-20);
        line(xm2-10,ym2-20,xm2-10,ym2-10);
        line(xm2-10,ym2-10,xm2,ym2-10);
        line(xm2,ym2-10,xm2,ym2-20);
        line(xm2,ym2-20,xm2+10,ym2-20);
        line(xm2+10,ym2-20,xm2+10,ym2-10);
        line(xm2+10,ym2-10,xm2+20,ym2-10);
        line(xm2+20,ym2-10,xm2+20,ym2-50);
        line(xm2+20,ym2-50,xm2+30,ym2-50);
        line(xm2+30,ym2-50,xm2+30,ym2-70);
        line(xm2+30,ym2-70,xm2+20,ym2-70);
        line(xm2+20,ym2-70,xm2+20,ym2-60);
        line(xm2+20,ym2-60,xm2+10,ym2-60);
        line(xm2+10,ym2-60,xm2+10,ym2-70);
        line(xm2+10,ym2-70,xm2,ym2-70);
        line(xm2,ym2-70,xm2,ym2-80);
        line(xm2,ym2-80,xm2-30,ym2-80);
        line(xm2-30,ym2-80,xm2-30,ym2-70);
        line(xm2-30,ym2-70,xm2-40,ym2-70);
        line(xm2-40,ym2-70,xm2-40,ym2-60);
        line(xm2-40,ym2-60,xm2-50,ym2-60);
        line(xm2-50,ym2-60,xm2-50,ym2-70);
        line(xm2-50,ym2-70,xm2-60,ym2-70);
        line(xm2-60,ym2-70,xm2-60,ym2-50);
        line(xm2-60,ym2-50,xm2-50,ym2-50);
        line(xm2-50,ym2-50,xm2-50,ym2-10);
        //setfillstyle(SOLID_FILL,GREEN);
        //floodfill();
        //eyes
        rectangle(xm2-40,ym2-60,xm2-20,ym2-30);
        rectangle(xm2-10,ym2-60,xm2+10,ym2-30);
        rectangle(xm2-40,ym2-50,xm2-30,ym2-40);
        rectangle(xm2-10,ym2-50,xm2,ym2-40);
        setcolor(7);
    }
    void gerakm2()
    {
        v=1+rand()%5;
        xm2=xm2-v;
        if(xm2<-70)
        {
            xm2=getmaxx()-rand()%400;
        }
    }
    int hitbox(int xw, int yw)
    {
        if (xw>xm2-165&&xw<xm2+50&&yw>ym2-10&&yw<ym2+10)
        {
            xm2=getmaxx()-rand()%400;
            ym2=rand()%3;
            if(ym2==0)ym2=getmaxy()/2+200;
            else if(ym2==1)ym2=getmaxy()/2;
            else if(ym2==2)ym2=getmaxy()/2-200;
            return true;
        }
        return false;
    }
};

class UI
{
    public:
    void scoreboard()
    {
        settextstyle(3,HORIZ_DIR,40);
        settextjustify(3,1);
        sprintf(score_str,"%d",score);
        outtextxy(100,50,score_str);
    }
};

int main()
{
    int page=0;
    DWORD maxX = GetSystemMetrics(SM_CXSCREEN);
    DWORD maxY = GetSystemMetrics(SM_CYSCREEN);

    initwindow(maxX,maxY);
    mc Guts;
    Wave wave[100];
    Monster1 A[10];
    Monster2 B[10];
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        Guts.gerak();
        Guts.print();
        UI userinterface;
        userinterface.scoreboard();
        for(int i=0;i<100;i++)
        {
            wave[i].controlWave(Guts.xo,Guts.yo);
        }
        if(delayWave!=0)
        {
            delayWave=delayWave-1;
        }
        for(int j=0;j<4;j++)
        {
            A[j].gerakm1();
            A[j].printm1();
            for(int i=0;i<15;i++)
            {
                if (wave[i].cekWave == 1)
                {
                    if (A[j].hitbox(wave[i].xw, wave[i].yw))
                    {
                        wave[i].cekWave = 0;
                        wave[i].xw=0;
                        wave[i].yw=0;
                    }
                }
            }
        }
        for(int k=0;k<9;k++)
        {
            B[k].gerakm2();
            B[k].printm2();
            for(int i=0;i<15;i++)
            {
                if (wave[i].cekWave == 1)
                {
                    if (B[k].hitbox(wave[i].xw, wave[i].yw))
                    {

                        wave[i].cekWave = 0;
                        wave[i].xw=0;
                        wave[i].yw=0;
                    }
                }
            }
        }
        delay(1);
        page=1-page;
    }

}
