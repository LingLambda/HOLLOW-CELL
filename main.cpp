#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include <stdlib.h>
#include<mmsystem.h>//���������ļ���
#include<time.h>//��ʱ����Ҫ��ͷ�ļ�
#pragma comment(lib,"Winmm.lib")
bool Timer(clock_t ms, int id);
int music_kg = 1;
IMAGE diban[2];
IMAGE BJ1;
IMAGE menu_image_bj;
IMAGE menu_image[2];
IMAGE start_image[2];
IMAGE help_image[2];
IMAGE out_image[2];
IMAGE YX_image[2];
IMAGE YXK_image[2];
IMAGE YXG_image[2];
IMAGE caid;
IMAGE caid2;
IMAGE gb_menu[2];
IMAGE back_menu[2];
IMAGE yes_menu[2];
IMAGE no_menu[2];
IMAGE BULL_image[2];
IMAGE zzbj1;
IMAGE zzbj2;
//��
IMAGE jump1_image[3];
IMAGE move1_image[7];
IMAGE jump2_image[3];
IMAGE move2_image[7];
IMAGE stand1_image[4];
IMAGE stand2_image[4];
//��
IMAGE jump1_image2[3];
IMAGE move1_image2[7];
IMAGE jump2_image2[3];
IMAGE move2_image2[7];
IMAGE stand1_image2[4];
IMAGE stand2_image2[4];
//����
IMAGE attack1_image[4];
IMAGE attack2_image[4];
IMAGE attack1_image2[4];
IMAGE attack2_image2[4];
//�ӵ�
IMAGE bull[3];
IMAGE bull2[3];//��
IMAGE bull3[3];//�ұ�
IMAGE bull4[3];
//����
IMAGE dr_death1;//1��2��
IMAGE dr_death2;
IMAGE dr2_death1;//1��2��
IMAGE dr2_death2;
//��stand
IMAGE dr_stand1[4];//��ͨ
IMAGE dr_stand2[4];
IMAGE dr_2stand1[4];//�ܻ�
IMAGE dr_2stand2[4];
//��stand
IMAGE dr2_stand1[4];//��ͨ
IMAGE dr2_stand2[4];
IMAGE dr2_2stand1[4];//�ܻ�
IMAGE dr2_2stand2[4];
//����
IMAGE gg_image;
IMAGE ts1_image;
IMAGE win_image;
IMAGE yes2_image[2];
enum mymenu
{
	start,
	gg,
	ts1,
	win,
	opxx,
	achieve,
	ewnr,
	out,
	home
};
enum mymenu mystate = home;
enum my
{
	bull_num = 5,
	dr1_num = 8
};
struct sbwz
{
	int x=531;
	int y[5]={398,438,480,530,570};
	int n=0;
}ZZSB;
struct zj_init//С��ʿ
{
	int x;
	int y;
	int init_y;
	int x_self;//��¼��������λ��(��ͼƬ)
	int y_self;
	//���豾����ֵ
	int high = 95;
	int wight = 55;
	IMAGE* ztai1;//����ͼ
	IMAGE* ztai2;//����ͼ
	int donzuo;
	int live;
	int js;//��ɱ����
	int mianxiang = 0;//0��1��
	int move_pd = 0;//0ԭ�أ�1�ң�-1��
	int move_cd = 0;//�ж��ƶ�����
	int jump_pd = 0;//0ԭ�أ�1�£�-1��
	int jump_pd2 = 0;//0Ϊ��ʼ������Ϊ������2����Ծ
	int gj_pd = 0;//0,��Ϊ0ʱ�޷��ƶ���Ծ
	int gj_pd2 = 0;//0,����0ʱ�����޷����
}xqs;
struct dr_init//����
{
	int x;
	int y;
	int init_y;
	IMAGE* ztai1;
	IMAGE* ztai2;
	int donzuo;
	int live;
	int mianxiang = 0;
	bool app = false;//trueʱ����ͼƬ�����򲻾��л���
	int shouji=0;//�ж��Ƿ��ܻ�,0����,�������ܻ�
	int xz ;//λ������ֵy
	//���豾����ֵ
	int x_self;
	int y_self;
	int high = 90;
	int wight = 80;
}dr_fly[dr1_num];
void init_image()//ͼƬ����
{
	for (int i = 0; i < 2; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./res/diban%d.png", i);
		loadimage(diban + i, lujin1,250,250);
		sprintf(lujin1, "./res/menu%d.png", i);
		loadimage(menu_image + i, lujin1, 70, 70);
		sprintf(lujin1, "./res/playgame%d.png", i);
		loadimage(start_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./res/help%d.png", i);
		loadimage(help_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./res/exit%d.png", i);
		loadimage(out_image + i, lujin1, 180, 80);
		sprintf(lujin1, "./test/xuanze%d.png", i);
		loadimage(gb_menu + i, lujin1, 222, 57);
		sprintf(lujin1, "./test/yinxiao%d.png", i);
		loadimage(YX_image + i, lujin1, 90, 40);
		sprintf(lujin1, "./test/kai%d.png", i);
		loadimage(YXK_image + i, lujin1, 50, 40);
		sprintf(lujin1, "./test/guan%d.png", i);
		loadimage(YXG_image + i, lujin1, 50, 40);
		sprintf(lujin1, "./test/huidaocaidan%d.png", i);
		loadimage(back_menu + i, lujin1, 180, 40);
		sprintf(lujin1, "./test/bull%d.png", i);
		loadimage(BULL_image + i, lujin1, 65, 20);
		sprintf(lujin1, "./test/shi%d.png", i);
		loadimage(yes_menu + i, lujin1, 45, 40);
		sprintf(lujin1, "./jm/yes%d.png", i);
		loadimage(yes2_image + i, lujin1, 225, 95);
		sprintf(lujin1, "./test/fou%d.png", i);
		loadimage(no_menu + i, lujin1, 45, 40);
	}
	loadimage(&menu_image_bj, "./res/menuunit3.png", 1280, 720);
	loadimage(&BJ1, "./res/BJ1.png", 1280, 720);
	loadimage(&caid, "./test/caidan1.png", 1280, 720);
	loadimage(&caid2, "./test/beijing.png", 1280, 720);
	loadimage(&zzbj1, "./test/zhandoubeijing.png", 1280, 720);
	loadimage(&zzbj2, "./test/114514.png", 300, 50);
	loadimage(&ts1_image, "./jm/ts1.png", 1280, 750);
	loadimage(&gg_image, "./jm/gg.png", 1280, 750);
	loadimage(&win_image, "./jm/win.png", 1280, 750);
	//С��ʿ����ͼƬ
	for (int i = 0; i < 3; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./jump/jump_%d_0.png", i+1);
		loadimage(jump1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump/jump_%d_1.png", i+1);
		loadimage(jump2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump2/jump_%d_0.png", i + 1);
		loadimage(jump1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./jump2/jump_%d_1.png", i + 1);
		loadimage(jump2_image2 + i, lujin1, 90, 125);
	}
	for (int i = 0; i < 4; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./zl44/zl%d.png", i + 1);
		loadimage(stand2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl44/zl%d%d.png", i + 1,i+1);
		loadimage(stand1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl22/zl%d.png", i + 1);
		loadimage(stand2_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./zl22/zl%d%d.png", i + 1, i + 1);
		loadimage(stand1_image2 + i, lujin1, 90, 125);
		//�����������⴦��
		sprintf(lujin1, "./attack/%d 0 1.png", i + 1);
		loadimage(attack1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 0 2.png", i + 1);
		loadimage(attack1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 1 1.png", i + 1);
		loadimage(attack2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./attack/%d 1 2.png", i + 1);
		loadimage(attack2_image2 + i, lujin1, 90, 125);
	}
	for (int i = 0; i < 7; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./move/move_%d_0.png", i + 1);
		loadimage(move1_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./move/move_%d_1.png", i + 1);
		loadimage(move2_image + i, lujin1, 90, 125);
		sprintf(lujin1, "./move2/move_%d_0.png", i + 1);
		loadimage(move1_image2 + i, lujin1, 90, 125);
		sprintf(lujin1, "./move2/move_%d_1.png", i + 1);
		loadimage(move2_image2 + i, lujin1, 90, 125);
	}
	//�ӵ�
	for (int i = 0; i < 3; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./bull/%d0.png", i + 1);
		loadimage(bull + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull/%d1.png", i + 1);
		loadimage(bull2 + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull2/%d0.png", i + 1);
		loadimage(bull3 + i, lujin1, 175, 30);
		sprintf(lujin1, "./bull2/%d1.png", i + 1);
		loadimage(bull4 + i, lujin1, 175, 30);
	}
	//���ˣ�����1)
	char lujin1[50] = { 0 };
	sprintf(lujin1, "./dr_death/1 0 1.png");
	loadimage(&dr_death1, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 1 1.png");
	loadimage(&dr_death2, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 0 2.png");
	loadimage(&dr2_death1, lujin1, 120, 120);
	sprintf(lujin1, "./dr_death/1 1 2.png");
	loadimage(&dr2_death2, lujin1, 120, 120);
	for (int i = 0; i < 4; i++)
	{
		char lujin1[50] = { 0 };
		sprintf(lujin1, "./dr_stand/%d 0 1.png", i + 1);
		loadimage(dr_stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 1.png", i + 1);
		loadimage(dr_stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 1.png", i + 1);
		loadimage(dr_2stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 1 1.png", i + 1);
		loadimage(dr_2stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 2.png", i + 1);
		loadimage(dr2_stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 2.png", i + 1);
		loadimage(dr2_stand2 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 0 2.png", i + 1);
		loadimage(dr2_2stand1 + i, lujin1, 120, 120);
		sprintf(lujin1, "./dr_stand/%d 1 2 1.png", i + 1);
		loadimage(dr2_2stand2 + i, lujin1, 120, 120);
	}
}
struct bull_sx
{
	int x;
	int y;
	bool live = false;
	int mianxiang = 0;//0��1��
	int donzuo = 0;//�ӵ���������
	int init_x = 0;//����λ��
	int time = 0;//����ʱ��
	int high = 30;
	int wight = 170;
}bull_xqs[bull_num];
void createbull()
{
	for (int i = 0; i < bull_num; i++)
	{
		if (!bull_xqs[i].live)
		{
			bull_xqs[i].mianxiang = xqs.mianxiang;
			if (bull_xqs[i].mianxiang == 0)
			{
				bull_xqs[i].x = xqs.x - 155;
				bull_xqs[i].y = xqs.y + 30;
			}
			else
			{
				bull_xqs[i].x = xqs.x + 60;
				bull_xqs[i].y = xqs.y + 30;
			}
			bull_xqs[i].init_x = bull_xqs[i].x;
			bull_xqs[i].live = true;
			bull_xqs[i].time = 0;
			break;
		}
	}
}
void bullmove()//�ӵ��ƶ�
{
	for (int i = 0; i < bull_num; i++)
	{
		if (bull_xqs[i].live&& bull_xqs[i].time==0)
		{
			//û�����ƶ�
			if (bull_xqs[i].mianxiang == 0)
			{
				bull_xqs[i].x -= 30;
				if (bull_xqs[i].x < bull_xqs[i].init_x - 190 && bull_xqs[i].donzuo == 0)
				{
					bull_xqs[i].donzuo = 1;
				}
			}
			else
			{
				bull_xqs[i].x += 30;
				if (bull_xqs[i].x > bull_xqs[i].init_x + 190 && bull_xqs[i].donzuo == 0)
				{
					bull_xqs[i].donzuo = 1;
				}
			}
			if (bull_xqs[i].x < 0 - 175 || bull_xqs[i].x>getwidth() + 175)
			{
				bull_xqs[i].live = false;//��������
			}
		}
	}
}
int fhesc;
void init_all()//�󲿷ֳ�ʼ��
{
	//mystate = start;
	ZZSB.n = 0;
	fhesc = 0;
}
void init_dr_fly()//����1��ʼ��
{
	for (int i = 0; i < dr1_num; i++)
	{
		dr_fly[i].x = -120;
		dr_fly[i].y = -120;
		dr_fly[i].ztai1 = dr_stand1;
		dr_fly[i].ztai2 = dr_stand2;
		dr_fly[i].donzuo = 0;
		dr_fly[i].live = 2;
		dr_fly[i].mianxiang = 0;
		dr_fly[i].x_self = dr_fly[i].x + 30;
		dr_fly[i].y_self = dr_fly[i].y + 30;
		dr_fly[i].app = false;
		dr_fly[i].shouji = 0;
		dr_fly[i].init_y = getheight() - 45 - 125;
		dr_fly[i].xz = 5;
	}
}
void init_role()//С��ʿ��ʼ��
{
	fhesc = 0;
	mciSendString("play BGM_1 repeat", NULL, 0, NULL);     //ѭ����������
	mciSendString("stop BGM1", NULL, 0, NULL);
	if (music_kg == 0)
	{
		mciSendString("stop BGM_1", NULL, 0, NULL);
	}
	//���˳�ʼ��
	init_dr_fly();
	//С��ʿ�ĳ�ʼ��
	xqs.init_y = getheight() - 45 - 125;
	xqs.y = xqs.init_y;
	xqs.x = getwidth()/2-45;
	xqs.x_self = xqs.x + 30;
	xqs.y_self = xqs.y + 30;
	xqs.donzuo = 0;
	xqs.live = 1;
	xqs.js = 0;
	xqs.ztai1 = stand1_image2;
	xqs.ztai2 = stand2_image2;
	xqs.mianxiang = 1;
	int mianxiang = 0;//0��1��
	int move_pd = 0;//0ԭ�أ�1�ң�-1��
	int move_cd = 0;//�ж��ƶ�����
	int jump_pd = 0;//0ԭ�أ�1�£�-1��
	int gj_pd = 0;//0,��Ϊ0ʱ�޷��ƶ���Ծ
	int gj_pd2 = 0;//0,����0ʱ�����޷����
	int jump_pd2 = 0;//0Ϊ��ʼ������Ϊ������2����Ծ
}
void dr_fly_cj()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == false)
		{
			srand((unsigned)time(NULL));
			int n_dr1 = rand() % 2;//[0,1]
			dr_fly[i].donzuo = 0;
			dr_fly[i].live = 2;
			dr_fly[i].mianxiang = n_dr1;
			dr_fly[i].shouji = 0;
			int dr_y_1 = (rand() % (getheight() - 160 - 260 + 1)) + 260;//[a,b]
			dr_fly[i].y = dr_y_1;//���ø߶�,�����߷ɳ�
			if (dr_fly[i].mianxiang == 0)
			{
				dr_fly[i].x = -120;
				dr_fly[i].ztai1 = dr2_stand1;
				dr_fly[i].ztai2 = dr2_stand2;
			}
			else
			{
				dr_fly[i].x = getwidth() + 120;
				dr_fly[i].ztai1 = dr_stand1;
				dr_fly[i].ztai2 = dr_stand2;
			}
			dr_fly[i].x_self = dr_fly[i].x + 20;
			dr_fly[i].y_self = dr_fly[i].y + 20;
			dr_fly[i].app = true;
			break;
		}
	}
}
void dr_fly_donzuo()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == true)//�жϴ��
		{
			if (dr_fly[i].donzuo != -1)//�ж���������
			{
				if (Timer(120, 200 + i))
				{
					dr_fly[i].donzuo += 1;
					dr_fly[i].y += dr_fly[i].xz;//��������y�ᶶ��
					if (dr_fly[i].xz > 0)
					{
						dr_fly[i].xz = -5;
					}
					else
					{
						dr_fly[i].xz = 5;
					}
				}
				if (dr_fly[i].donzuo >= 4)
				{
					dr_fly[i].donzuo = 0;
				}
				//�����ƶ�
				if (dr_fly[i].mianxiang == 0)
				{
					dr_fly[i].x += 5;
				}
				else
				{
					dr_fly[i].x -= 5;
				}
				//λ������
				if (dr_fly[i].x < -120 || dr_fly[i].x > getwidth() + 120)
				{
					dr_fly[i].app = false;
				}
			}
			else
			{
				dr_fly[i].y += 35;
				//λ������,�������
				if (dr_fly[i].y_self> getheight()-dr_fly[i].high)
				{
					dr_fly[i].app = false;
					dr_fly[i].donzuo = 0;
					xqs.js += 1;//���ӻ�ɱ��
					//����
					if (xqs.js >= 10)
					{
						mystate = win;
					}
				}
			}
		}
	}
}
void dr1_fly_attack()
{
	for (int i = 0; i < dr1_num; i++)
	{
		if (dr_fly[i].app == false)
		{
			continue;//�����������λֱ������
		}
		//�ж�С��ʿ
		if ((xqs.y_self >= dr_fly[i].y_self && xqs.y_self <= dr_fly[i].y_self + dr_fly[i].high)
			|| (dr_fly[i].y_self >= xqs.y_self && dr_fly[i].y_self <= xqs.y_self + xqs.high))
		{
			if ((xqs.x_self >= dr_fly[i].x_self && xqs.x_self <= dr_fly[i].x_self + dr_fly[i].wight)
				|| (dr_fly[i].x_self >= xqs.x_self && dr_fly[i].x_self <= xqs.x_self + xqs.wight))
			{
				if (xqs.live > 0)
				{
					xqs.live -= 1;
					//������Ч
					if (music_kg == 1)
					{
						mciSendString("close attack_self", NULL, 0, NULL);
						mciSendString("open ./sound/attack_self.mp3 alias attack_self", NULL, 0, NULL);
						mciSendString("play attack_self", NULL, 0, NULL);
					}
					//�����ж�
					mystate = gg;
				}
			}
		}
		//�ж��ӵ�
		for (int j = 0; j < bull_num; j++)
		{
			if (bull_xqs[j].live == false)
			{
				continue;//�����������λֱ������
			}
			if ((bull_xqs[j].y >= dr_fly[i].y_self && bull_xqs[j].y <= dr_fly[i].y_self + dr_fly[i].high)
				||(dr_fly[i].y_self >= bull_xqs[j].y && dr_fly[i].y_self <= bull_xqs[j].y + bull_xqs[j].high))//�ж��ӵ��Ƿ�������y
			{
				if ((bull_xqs[j].x <= dr_fly[i].x_self + dr_fly[i].wight && bull_xqs[j].x >= dr_fly[i].x)//�ж��ӵ��Ƿ�������x
					|| (dr_fly[i].x_self <= bull_xqs[j].x + bull_xqs[j].wight && dr_fly[i].x_self >= bull_xqs[j].x))
				{
					if (bull_xqs[j].donzuo != 2)//�������������������Ĺ���
					{
						bull_xqs[j].donzuo = 2;
						dr_fly[i].live -= 1;
						bull_xqs[i].time = 10;
						if (dr_fly[i].live != 0)
						{
							dr_fly[i].shouji = 2;//�ܻ��ж�������
							if (dr_fly[i].mianxiang == 0)
							{
								dr_fly[i].ztai1 = dr2_2stand1;
								dr_fly[i].ztai2 = dr2_2stand2;
							}
							else
							{
								dr_fly[i].ztai1 = dr_2stand1;
								dr_fly[i].ztai2 = dr_2stand2;
							}
							//�ܻ���λ��
							int pd_1 = bull_xqs[j].x - dr_fly[i].x_self;
							//�ӵ�λ������
							bull_xqs[j].x = dr_fly[i].x;
							if (pd_1 > 0)//������䵽�ұ�
							{
								dr_fly[i].x -= 50;
							}
							else
							{
								dr_fly[i].x += 50;
							}
						}
						else//�������䶯��
						{
							dr_fly[i].donzuo = -1;
							if (dr_fly[i].mianxiang == 0)
							{
								dr_fly[i].ztai1 = &dr_death1;
								dr_fly[i].ztai2 = &dr_death2;
							}
							else
							{
								dr_fly[i].ztai1 = &dr2_death1;
								dr_fly[i].ztai2 = &dr2_death2;
							}
						}
						//������Ч
						if (music_kg == 1)
						{
							mciSendString("close attack_em", NULL, 0, NULL);
							mciSendString("open ./sound/attack_em.mp3 alias attack_em", NULL, 0, NULL);
							mciSendString("play attack_em", NULL, 0, NULL);
						}
					}
				}
			}
		}
	}
}
void draw_image()//ͼƬ����
{
	//������ͼ�δ��ڣ�    system("cls")���������̨
	cleardevice();
	//�ָ���
	if (mystate==start)
	{
		putimage(0, 0, &BJ1);
		for (int i = 0; i < getwidth();)
		{
			putimage(i, getheight() - 250, diban + 1, NOTSRCERASE);
			putimage(i, getheight() - 250, diban + 0, SRCERASE);
			i += 250;
		}
	}
	/*if (mystate == home)
	{
		putimage(0, 0, &menu_image_bj);
		putimage(540, 280, start_image + 1, NOTSRCERASE);
		putimage(540, 280, start_image + 0, SRCERASE);
		putimage(540, 380, help_image + 1, NOTSRCERASE);
		putimage(540, 380, help_image + 0, SRCERASE);
		putimage(540, 480, out_image + 1, NOTSRCERASE);
		putimage(540, 480, out_image + 0, SRCERASE);
	}*/
	if (mystate == home)
	{
		putimage(0, 0, &caid);
		putimage(ZZSB.x, ZZSB.y[ZZSB.n], gb_menu + 1, NOTSRCERASE);
		putimage(ZZSB.x, ZZSB.y[ZZSB.n], gb_menu + 0, SRCERASE);
	}
	if (mystate == opxx)
	{
		putimage(0, 0, &caid2);
		putimage(520, 320, YX_image + 1, NOTSRCERASE);
		putimage(520, 320, YX_image + 0, SRCERASE);
		putimage(510, 460, back_menu + 1, NOTSRCERASE);
		putimage(510, 460, back_menu + 0, SRCERASE);
		if (music_kg == 1)
		{
			putimage(620, 320, YXK_image + 1, NOTSRCERASE);
			putimage(620, 320, YXK_image + 0, SRCERASE);
		}
		else
		{
			putimage(620, 320, YXG_image + 1, NOTSRCERASE);
			putimage(620, 320, YXG_image + 0, SRCERASE);
		}
	}
	if (mystate == ts1)
	{
		putimage(0, 0, &ts1_image);
		putimage(510, 600, yes2_image + 1, NOTSRCERASE);
		putimage(510, 600, yes2_image + 0, SRCERASE);
	}
	if (mystate == gg)
	{
		putimage(0, 0, &gg_image);
	}
	if (mystate == win)
	{
		putimage(0, 0, &win_image);
	}
	if (mystate == start)
	{
		putimage(0, 0, &zzbj1);
		//С��ʿ��������
		if (xqs.x < 0)
		{
			xqs.x = 0;
		}
		if (xqs.x > getwidth() - 90)
		{
			xqs.x = getwidth() - 90;
		}
		if (xqs.y > xqs.init_y)
		{
			xqs.y = xqs.init_y;
			xqs.jump_pd = 0;
			xqs.gj_pd2 = 0;
			xqs.jump_pd2 = 0;
			if (xqs.mianxiang == 0)
			{
				xqs.ztai1 = stand1_image;
				xqs.ztai2 = stand2_image;
				xqs.move_pd = 0;
			}
			else
			{
				xqs.ztai1 = stand1_image2;
				xqs.ztai2 = stand2_image2;
				xqs.move_pd = 0;
			}
		}
		//С��ʿ��Ծ���ƶ�
		if (xqs.gj_pd != 0)
		{
			xqs.gj_pd -= 2;
			if (Timer(120, 56))
			{
				xqs.donzuo += 1;
				if (xqs.donzuo == 1)
				{
					//������Ч
					if (music_kg == 1)
					{
						mciSendString("close attack", NULL, 0, NULL);
						mciSendString("open ./sound/attack.mp3 alias attack", NULL, 0, NULL);
						mciSendString("play attack", NULL, 0, NULL);
					}
				}
				if (xqs.donzuo == 2)
				{
					createbull();
				}
				if (xqs.donzuo >= 4)
				{
					xqs.donzuo = 0;
					xqs.gj_pd = 0;
					if (xqs.mianxiang == 0)
					{
						if (xqs.jump_pd != 0)
						{
							xqs.ztai1 = jump1_image;
							xqs.ztai2 = jump2_image;
							xqs.jump_pd = 1;
							xqs.donzuo = 2;
						}
						else
						{
							xqs.ztai1 = stand1_image;
							xqs.ztai2 = stand2_image;
						}
						xqs.move_pd = 0;
					}
					else
					{
						if (xqs.jump_pd != 0)
						{
							xqs.ztai1 = jump1_image2;
							xqs.ztai2 = jump2_image2;
							xqs.jump_pd = 1;
							xqs.donzuo = 2;
						}
						else
						{
							xqs.ztai1 = stand1_image2;
							xqs.ztai2 = stand2_image2;
						}
						xqs.move_pd = 0;
					}
				}
			}
		}
		else
		{
			if (xqs.jump_pd == 0)
			{
				if (Timer(120, 56))
				{
					if (xqs.y == xqs.init_y)
					{
						xqs.donzuo += 1;
					}
					if (xqs.donzuo >= 4 && xqs.move_pd == 0)
					{
						xqs.donzuo = 0;
					}
				}
			}
			if (xqs.jump_pd != 0)
			{
				if (xqs.donzuo != 2)
				{
					xqs.y += 26 * xqs.jump_pd;
				}
				else
				{
					xqs.y += 20 * xqs.jump_pd;
				}
				if (xqs.donzuo == 0)
				{
					if (Timer(30, 11))
					{
						xqs.donzuo = 1;
					}
				}
				if (xqs.y < getheight() - 125 - 45 - 150-xqs.jump_pd2)
				{
					xqs.donzuo = 2;
					xqs.jump_pd = 1;
				}
				xqs.x += 21 * xqs.move_pd;
			}
			else if (xqs.move_cd > 0)
			{
				if (xqs.donzuo >= 7)
				{
					xqs.donzuo = 0;
				}
				xqs.x += 20 * xqs.move_pd;
				xqs.move_cd -= 15;
			}
			else if (xqs.move_cd <= 0 && xqs.jump_pd == 0 && xqs.move_pd != 0)
			{
				xqs.donzuo = 0;
				if (xqs.mianxiang == 0)
				{
					xqs.ztai1 = stand1_image;
					xqs.ztai2 = stand2_image;
					xqs.move_pd = 0;
				}
				else
				{
					xqs.ztai1 = stand1_image2;
					xqs.ztai2 = stand2_image2;
					xqs.move_pd = 0;
				}
				xqs.move_pd = 0;
				xqs.move_cd = 0;
			}
		}
		//С��ʿ�ı�����������
		xqs.x_self = xqs.x + 30;
		xqs.y_self = xqs.y + 30;
		//С��ʿ����
		if (xqs.live > 0)
		{
			putimage(xqs.x, xqs.y, xqs.ztai1 + xqs.donzuo, NOTSRCERASE);
			putimage(xqs.x, xqs.y, xqs.ztai2 + xqs.donzuo, SRCERASE);
		}
		//ˢ�µ���
		if (Timer(3000, 233))
		{
			dr_fly_cj();
		}
		//���˻���
		for (int i = 0; i < dr1_num; i++)
		{
			if (dr_fly[i].app == false)
			{
				continue;
			}
			if (dr_fly[i].shouji == 0)
			{
				if (dr_fly[i].donzuo != -1)
				{
					if (dr_fly[i].mianxiang == 0)
					{
						dr_fly[i].ztai1 = dr2_stand1;
						dr_fly[i].ztai2 = dr2_stand2;
					}
					else
					{
						dr_fly[i].ztai1 = dr_stand1;
						dr_fly[i].ztai2 = dr_stand2;
					}
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1 + dr_fly[i].donzuo, NOTSRCERASE);
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2 + dr_fly[i].donzuo, SRCERASE);
				}
				else
				{
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1+0, NOTSRCERASE);
					putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2+0, SRCERASE);
				}
			}
			else
			{
				putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai1 + dr_fly[i].donzuo, NOTSRCERASE);
				putimage(dr_fly[i].x, dr_fly[i].y, dr_fly[i].ztai2 + dr_fly[i].donzuo, SRCERASE);
				if (Timer(200, 100 + i)&& dr_fly[i].shouji != 0)//��λ�ܻ�����
				{
					dr_fly[i].shouji -= 1;
				}
			}
			dr_fly[i].x_self = dr_fly[i].x + 20;
			dr_fly[i].y_self = dr_fly[i].y + 20;
		}
		dr_fly_donzuo();
		dr1_fly_attack();
		//�ӵ�����
		for (int i = 0; i < bull_num; i++)
		{
			if (bull_xqs[i].live)
			{
				int nx = bull_xqs[i].donzuo;
				if (bull_xqs[i].mianxiang == 0)
				{
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull + nx, NOTSRCERASE);
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull2 + nx, SRCINVERT);
				}
				else
				{
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull3 + nx, NOTSRCERASE);
					putimage(bull_xqs[i].x, bull_xqs[i].y, bull4 + nx, SRCINVERT);
				}
				if (bull_xqs[i].time > 0&&nx==2)
				{
					if (Timer(100, 40+i))
					{
						bull_xqs[i].time = 0;
					}
				}
				else if ((bull_xqs[i].time == 0 && nx == 2))
				{
					bull_xqs[i].live = false;
					bull_xqs[i].donzuo = 0;
				}
			}
		}
		//���ػ���
		if (fhesc == 1)
		{
			putimage(510, 460, &zzbj2);
			putimage(510, 460, back_menu + 1, NOTSRCERASE);
			putimage(510, 460, back_menu + 0, SRCERASE);
			putimage(690, 460, yes_menu + 1, NOTSRCERASE);
			putimage(690, 460, yes_menu + 0, SRCERASE);
			putimage(735, 460, no_menu + 1, NOTSRCERASE);
			putimage(735, 460, no_menu + 0, SRCERASE);
		}
		//������
		settextcolor(RGB(255, 255, 255));
		settextstyle(50, 25, "����");
		char fs_1[10];
		sprintf(fs_1, "�÷�:%d", xqs.js);
		outtextxy(0, 0, fs_1);
	}
}
//����Ƿ���ĳ����������
bool isInRect(ExMessage* msg, int x, int y, int w, int h)
{
	if (msg->x > x && msg->x <x + w && msg->y >y && msg->y < y + h)
	{
		return true;
	}
	return false;
}
void StartUpScence(ExMessage* msg)//��&ȡ��ַҲ����
{
	//����������л���������
	if (msg->message == WM_LBUTTONDOWN)//WM_LBUTTONDOWN�������
	{
		if (mystate == home)//�ж��Ƿ������˵�
		{
			if (isInRect(msg, 600, 420, 100, 40))//��ʼ��Ϸ
			{
				mystate = ts1;
				init_role();
			}
			else if (isInRect(msg, 600, 460, 100, 40))//ѡ��
			{
				mystate = opxx;
			}
			else if (isInRect(msg, 600, 500, 100, 40))//�ɾ�
			{
				//mystate = out;
			}
			else if (isInRect(msg, 600, 540, 100, 40))//��������
			{
				//mystate = out;
			}
			else if (isInRect(msg, 600, 580, 100, 40))//�˳���Ϸ
			{
				mystate = out;
			}
		}
		else if (mystate == opxx)
		{
			if (isInRect(msg, 520, 320, 150, 40))//������Ч
			{
				if (music_kg == 1)
				{
					music_kg = 0;
					mciSendString("stop BGM1", NULL, 0, NULL);
				}
				else
				{
					music_kg = 1;
					mciSendString("play BGM1 repeat", NULL, 0, NULL);
				}
			}
			if (isInRect(msg, 510, 460, 150, 40))//�ص��˵�
			{
				mystate = home;
			}
		}
	}
	//��ʾ��gg��win
	if (msg->message == WM_LBUTTONDOWN)
	{
		if (mystate == ts1)
		{
			if (isInRect(msg, 510, 600, 225, 95))//��ʼ��Ϸ
			{
				mystate = start;
				init_role();
			}
		}
		if (mystate == gg || mystate == win)
		{
			mystate = home;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);     //ѭ����������
			mciSendString("stop BGM_1", NULL, 0, NULL);
			if (music_kg == 0)
			{
				mciSendString("stop BGM1", NULL, 0, NULL);
			}
		}
	}
	//С��ʿ�ص��˵�
	if (msg->message == WM_LBUTTONDOWN && fhesc == 1)
	{
		if (isInRect(msg, 690, 460, 50, 40))//���ز˵�
		{
			fhesc = 0;
			mystate = home;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);     //ѭ����������
			mciSendString("stop BGM_1", NULL, 0, NULL);
			if (music_kg == 0)
			{
				mciSendString("stop BGM1", NULL, 0, NULL);
			}
		}
		else if (isInRect(msg, 735, 460, 50, 40))//ȡ��
		{
			fhesc = 0;
		}
	}
}
void gb_sb(ExMessage* msg)
{
	if (isInRect(msg, 600, 420, 100, 40))
	{
		ZZSB.n = 0;
	}
	else if (isInRect(msg, 600, 460, 100, 40))
	{
		ZZSB.n = 1;
	}
	else if (isInRect(msg, 600, 500, 100, 40))
	{
		ZZSB.n = 2;
	}
	else if (isInRect(msg, 600, 540, 100, 40))
	{
		ZZSB.n = 3;
	}
	else if (isInRect(msg, 600, 580, 100, 40))
	{
		ZZSB.n = 4;
	}
}
void gb_key()
{
	//GetAsyncKeyState��ȡ�첽����״̬,��������----VK�������ֵvirtual key
	static DWORD t1 = 0, t2 = 0;//��������һ���������
	if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && t2 - t1 > 120)//����
	{
		if (ZZSB.n > 0)
		{
			ZZSB.n -= 1;
		}
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) && t2 - t1 > 120)//����
	{
		if (ZZSB.n < 4)
		{
			ZZSB.n += 1;
		}
		t1 = t2;
	}
	//�س�����
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 0) && t2 - t1 > 120)
	{
		mystate = ts1;
		init_role();
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 1) && t2 - t1 > 120)
	{
		mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 2) && t2 - t1 > 120)
	{
		//mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 3) && t2 - t1 > 120)
	{
		//mystate = opxx;
		t1 = t2;
	}
	if ((GetAsyncKeyState(VK_RETURN) && ZZSB.n == 4) && t2 - t1 > 120)
	{
		mystate = out;
		t1 = t2;
	}
	t2 = GetTickCount();
}
void key_xx()
{
	//GetAsyncKeyState��ȡ�첽����״̬,��������----VK�������ֵvirtual key
	static DWORD t1 = 0, t2 = 0;//��������һ���������
	if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('D')|| GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('A')) && t2 - t1 > 200)//�л�
	{
		if (music_kg == 1)
		{
			music_kg = 0;
			mciSendString("stop BGM1", NULL, 0, NULL);
		}
		else
		{
			music_kg = 1;
			mciSendString("play BGM1 repeat", NULL, 0, NULL);
		}
		t1 = t2;
	}
	t2 = GetTickCount();
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		mystate = home;
	}
}
void xqs_key()
{
	static DWORD t1 = 0, t2 = 0;//��������һ���������
	static DWORD t3 = 0, t4 = 0;
	//ESC
	if (GetAsyncKeyState(VK_ESCAPE) && t2 - t1 > 300)
	{
		t1 = t2;
		if (fhesc == 0)
		{
			fhesc = 1;//����1��������ѡ��
		}
		else
		{
			fhesc = 0;
		}
	}
	//�ƶ���Ծ
	if (xqs.gj_pd == 0&&xqs.live>0)
	{
		//���ƶ�
		if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) && t2 - t1 > 30)
		{

			if (xqs.y == xqs.init_y)//z�ж��Ƿ���Ծ
			{
				xqs.ztai1 = move1_image;
				xqs.ztai2 = move2_image;
				xqs.mianxiang = 0;
			}
			else if (xqs.ztai1 != move1_image)//�ж��Ƿ�����
			{
				xqs.donzuo = 0;
			}
			xqs.move_pd = -1;
			xqs.move_cd = 20;
			t1 = t2;
		}
		//JUMP��
		if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('K')) && t4 - t3 > 100)
		{
			if (xqs.mianxiang == 0)//������
			{
				if (xqs.ztai1 != jump1_image)
				{
					xqs.donzuo = 0;
				}
				xqs.ztai1 = jump1_image;
				xqs.ztai2 = jump2_image;
				t3 = t4;
				if (xqs.jump_pd == 0)
				{
					xqs.jump_pd = -1;
				}
			}
			else//������
			{
				if (xqs.ztai1 != jump1_image2)
				{
					xqs.donzuo = 0;
				}
				xqs.ztai1 = jump1_image2;
				xqs.ztai2 = jump2_image2;
				t3 = t4;
				if (xqs.jump_pd == 0)
				{
					xqs.jump_pd = -1;
				}
			}
			if (xqs.jump_pd == 1&&xqs.jump_pd2==1)
			{
				xqs.jump_pd2 = 100;
				xqs.jump_pd = -1;
				xqs.donzuo = 0;
			}
			else if (xqs.jump_pd2 == 0)
			{
				xqs.jump_pd2 = 1;
			}
		}
		//���ƶ�
		if ((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) && t2 - t1 > 30)
		{

			if (xqs.y == xqs.init_y)//z�ж��Ƿ���Ծ
			{
				xqs.ztai1 = move1_image2;
				xqs.ztai2 = move2_image2;
				xqs.mianxiang = 1;
			}
			else if (xqs.ztai1 != move1_image2)//�ж��Ƿ�����
			{
				xqs.donzuo = 0;
			}
			xqs.move_pd = 1;
			xqs.move_cd = 20;
			t1 = t2;
		}
	}
	//�����ӵ�
	if (GetAsyncKeyState('J') && xqs.gj_pd==0&&xqs.gj_pd2==0 && xqs.live > 0)
	{
		xqs.gj_pd = 50;
		xqs.donzuo = 0;
		if (xqs.y != xqs.init_y)
		{
			xqs.gj_pd2 = 1;
		}
		if (xqs.mianxiang == 0)
		{
			xqs.ztai1 = attack1_image;
			xqs.ztai2 = attack2_image;
		}
		else
		{
			xqs.ztai1 = attack1_image2;
			xqs.ztai2 = attack2_image2;
		}
	}
	t2 = GetTickCount();
	t4 = GetTickCount();
}
//��ȡ����
void music_dq()
{
	mciSendString("open ./sound/1.mp3 alias BGM1", NULL, 0, NULL);
	mciSendString("open ./sound/BGM1.mp3 alias BGM_1", NULL, 0, NULL);
	mciSendString("open ./sound/attack.mp3 alias attack", NULL, 0, NULL);
	mciSendString("open ./sound/attack_em.mp3 alias attack_em", NULL, 0, NULL);
	mciSendString("open ./sound/attack_self.mp3 alias attack_self", NULL, 0, NULL);
}
//��ʱ��
bool Timer(clock_t ms, int id)
{
	static clock_t start[10] = { 0 };
	clock_t end = clock();
	if (end - start[id] >= ms)
	{
		start[id] = end;
		return true;
	}
	return false;
}
int main()
{
	music_dq();
	//openָ�����Ҫ���ŵ����֣�alias�����ƶ���ǰ���ļ�·���ı������Ժ���Ҫ��������ļ�ֱ��ʹ����������Ϳ�����.
	//��������ļ������ǵ�debug�ļ�����ͬһĿ¼�£��Ϳ���������������д·����ֱ����������
	//��������ļ��������������͵�д���·����
	//��: D���µ�demoĿ¼��һ����1.MP3���ļ�
	//mciSendString("open D:\\demo\\1.mp3 alias bkmusic", NULL, 0, NULL);
	//mciSendString("stop bkmusic", NULL, 0, NULL);		//ֹͣ��������
	//mciSendString("close bkmusic", NULL, 0, NULL);		//�ر�����
	//mciSendString("play BGM1 repeat", NULL, 0, NULL);     //ѭ����������
	//��������
	initgraph(1280, 720);
	//��ʼ��
	init_all();
	init_image();
	//���ͼ��
	//draw_image();
	//˫�����ͼ
	mciSendString("play BGM1 repeat", NULL, 0, NULL);     //ѭ����������
	BeginBatchDraw();
	while (1)
	{
		ExMessage msg;
		//���ϻ�ȡ�����Ϣ���������Ϣ�ͷ���true�����򷵻�false
		while (peekmessage(&msg, EM_MOUSE))
		{
			StartUpScence(&msg);
		}
		FlushBatchDraw();//ˢ��
		if (mystate == out)//��⵽�˳�������ѭ��
		{
			break;
		}
		if (mystate == home)//���������ƶ��Լ����̿���
		{
			gb_sb(&msg);
			gb_key();
		}
		if (mystate == start)//С��ʿ
		{
			xqs_key();
			if (Timer(30,33))
			{
				bullmove();
			}
		}
		if (mystate == opxx)
		{
			key_xx();
		}
		if (Timer(50, 1))
		{
			draw_image();
		}
	}
	EndBatchDraw();
	return 0;
}