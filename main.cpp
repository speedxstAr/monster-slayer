#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <MMSystem.h>

using namespace std;
char score_str[0],hp_str[100];
int delayWave=0,score=0,darah=100,xo=50;

class mc
{
public:
    int yo=getmaxy()/2,ismoving=0,isattacking=0;
    void print()
    {
        //road
        line(0,getmaxy()/2+200,1920,getmaxy()/2+200); //y=0
        line(0,getmaxy()/2,1920,getmaxy()/2); //y=1
        line(0,getmaxy()/2-200,1920,getmaxy()/2-200); //y=2
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (isattacking==0)
            {
                isattacking=1;
            }
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
            isattacking=0;
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
    int xw,yw,cekWave,isattacking=0;
    Wave()
    {
        xw=0;
        yw=0;
        cekWave=0;
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
        if(GetAsyncKeyState(VK_SPACE))
        {
            if (isattacking==0)
            {
                if(delayWave==0)
                {
                    cekWave=1;
                    if(xw==0&&yw==0)
                    {
                        delayWave=10;
                    }
                }
                isattacking=1;
            }
        }
        else isattacking=0;
        updateWave(x,y);
    }
};

class Monster1 //score=2
{
public:
    int xm1=getmaxx()-rand()%300,ym1=rand()%3,v;
    void printm1()
    {
        if(ym1==0)ym1=getmaxy()/2+200;
        else if(ym1==1)ym1=getmaxy()/2;
        else if(ym1==2)ym1=getmaxy()/2-200;
        setcolor(4); //red
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
        if(xm1<=xo)
        {
            darah=darah-2;
            xm1=getmaxx()-rand()%300;
            ym1=rand()%3;
            if(ym1==0)ym1=getmaxy()/2+200;
            else if(ym1==1)ym1=getmaxy()/2;
            else if(ym1==2)ym1=getmaxy()/2-200;
        }
    }
    int hitbox(int xw, int yw)
    {
        if (xw>xm1-150&&xw<xm1+50&&yw>ym1-10&&yw<ym1+10)
        {
            xm1=getmaxx()-rand()%300;
            ym1=rand()%3;
            if(ym1==0)ym1=getmaxy()/2+200;
            else if(ym1==1)ym1=getmaxy()/2;
            else if(ym1==2)ym1=getmaxy()/2-200;
            score=score+2;
            return true;
        }
        return false;
    }
};

class Monster2 //score=1
{
public:
    int xm2=getmaxx()-rand()%300,ym2=rand()%3,v;
    void printm2()
    {
        if(ym2==0)ym2=getmaxy()/2+200;
        else if(ym2==1)ym2=getmaxy()/2;
        else if(ym2==2)ym2=getmaxy()/2-200;
        setcolor(2); //green
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
        if(xm2<=xo)
        {
            darah=darah-2;
            xm2=getmaxx()-rand()%300;
            ym2=rand()%3;
            if(ym2==0)ym2=getmaxy()/2+200;
            else if(ym2==1)ym2=getmaxy()/2;
            else if(ym2==2)ym2=getmaxy()/2-200;
        }
    }
    int hitbox(int xw,int yw)
    {
        if(xw>xm2-165&&xw<xm2+50&&yw>ym2-10&&yw<ym2+10)
        {
            xm2=getmaxx()-rand()%300;
            ym2=rand()%3;
            if(ym2==0)ym2=getmaxy()/2+200;
            else if(ym2==1)ym2=getmaxy()/2;
            else if(ym2==2)ym2=getmaxy()/2-200;
            score=score+1;
            return true;
        }
        return false;
    }
};

class UserInterface
{
    public:
    void menu()
    {
        settextstyle(4,HORIZ_DIR,40);
        settextjustify(1,1);
        outtextxy(getmaxx()/2,getmaxy()/2-25,"Welcome to");
        settextstyle(6,HORIZ_DIR,40);
        setcolor(4);
        outtextxy(getmaxx()/2,getmaxy()/2+30,"Berzerk");
        //setcolor(4);
        line(getmaxx()/2,100,getmaxx()/2,900);
        //kanan->kiri
        line(getmaxx()/2,900,getmaxx()/2+250,650);
        line(getmaxx()/2+250,650,getmaxx()/2-220,300);
        line(getmaxx()/2-220,300,getmaxx()/2-100,170);
        //kiri->kanan
        line(getmaxx()/2,900,getmaxx()/2-250,650);
        line(getmaxx()/2-250,650,getmaxx()/2+220,300);
        line(getmaxx()/2+220,300,getmaxx()/2+100,170);
        setcolor(7);
    }
    void scoreboard()
    {
        settextstyle(3,HORIZ_DIR,6);
        settextjustify(1,1);
        //score
        outtextxy(getmaxx()-1250,getmaxy()-700,"Score:");
        sprintf(score_str,"%d",score);
        outtextxy(getmaxx()-1120,getmaxy()-700,score_str);
        //hp
        outtextxy(getmaxx()-1250,getmaxy()-50,"Health:");
        setcolor(4);
        sprintf(hp_str,"%d",darah);
        outtextxy(getmaxx()-1120,getmaxy()-50,hp_str);
        setcolor(7);
    }
    void Deathscreen()
    {
        settextjustify(1,1);
        setcolor(4);
        outtextxy(getmaxx()/2,getmaxy()/2-25,"YOU DIED");
        setcolor(7);
        outtextxy(getmaxx()/2,getmaxy()/2+25,"Better luck next time");
    }
};

int main()
{
    int page=0,blink=0;
    DWORD maxX = GetSystemMetrics(SM_CXSCREEN);
    DWORD maxY = GetSystemMetrics(SM_CYSCREEN);
    initwindow(maxX,maxY);
    mc Guts;
    Wave wave[1000];
    Monster1 A[4];
    Monster2 B[9];
    UserInterface UI;
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        blink+=1;
        cleardevice();
        UI.menu();
        if (blink<20){}
        else if (blink<70)
        {
            settextjustify(1,1);
            settextstyle(3,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2+100,"Press Any Key to Start");
        }
        else blink=0;
        if(kbhit())
        {
            break;
        }
        delay(2);
        page=1-page;
    }

    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        Guts.gerak();
        Guts.print();
        UI.scoreboard();
        for(int i=0;i<1000;i++)
        {
            wave[i].controlWave(xo,Guts.yo);
        }
        if(delayWave!=0)
        {
            delayWave=delayWave-1;
        }
        if(score<100)
        {
            for(int j=0;j<4;j++)
			{
				A[j].gerakm1();
				A[j].printm1();
				for(int i=0;i<1000;i++)
				{
					if (wave[i].cekWave==1)
					{
						if (A[j].hitbox(wave[i].xw,wave[i].yw))
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
				for(int i=0;i<1000;i++)
				{
					if (wave[i].cekWave==1)
					{
						if (B[k].hitbox(wave[i].xw,wave[i].yw))
						{
							wave[i].cekWave = 0;
							wave[i].xw=0;
							wave[i].yw=0;
						}
					}
				}
			}
			if(darah<=0) break;
        }
        else if(score>100)
        {

        }
        delay(1);
        page=1-page;
    }

    while(1)
    {
        cleardevice();
        UI.Deathscreen();
    }
}
