#pragma once
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<easyx.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

IMAGE BK[5];// ��ʼ����ͼ
IMAGE SE[4];// ѡ�񱳾�ͼ
IMAGE bk;//����
IMAGE CAT[9];//è
IMAGE P[8];//�ϰ���
IMAGE N[10];// ����
IMAGE LAND;// ������Դ
IMAGE PLAY[2];// ��ʼ����ť
IMAGE B[4];//��������
IMAGE E[6];//���㱳��
// ����
IMAGE READY;//Ԥ��
IMAGE TITLE;//����
IMAGE KEY[2];//ѡè��ť
IMAGE ENTRY[3];// ������
IMAGE TIP;//��ʾ
IMAGE OVER;// ��������ͼ

int background;//rand������
int Ccolor;//randè��ɫ��
long startTime = 0;// ��Ϸ��ʼʱ��
int score;// ��ǰ�÷�
int pattern;//������ģʽ
int character;//��ɫ

double g = 6;// �������ٶ�(��ͨè)
double vx = 8;// ǽ�ƶ��ٶ�
double vy = 8;// è�������ٶ�(��ͨè)
// è�ĵ�ǰλ��
double y = 960;
const double x = 39.5;

double X[4];// ǽ��������
int Y[4];// ǽ��������
int c[4] = { 0,1,2 };//��Ļ��4���ϰ���ɫ

// ����λ��
const double landY = 500;
double landX = 0;
const int diff = 333;// ���м��

void load()// ͼƬ
{
	loadimage(&bk, _T("res\\bg_0.png"), 1000, 600);//����

	loadimage(&B[0], _T("res\\B_1.png"));//��������
	loadimage(&B[1], _T("res\\B_2.png"));
	loadimage(&B[2], _T("res\\B_3.png"));
	loadimage(&B[3], _T("res\\B_4.png"));

	loadimage(&BK[0], _T("res\\bg_0.png"));//��Ϸ����
	loadimage(&BK[1], _T("res\\bg_1.png"));
	loadimage(&BK[2], _T("res\\bg_2.png"));
	loadimage(&BK[3], _T("res\\bg_3.png"));
	loadimage(&BK[4], _T("res\\bg_4.png"));//���ѶȲʵ�

	loadimage(&SE[0], _T("res\\se1.png"));//ѡ�񱳾�
	loadimage(&SE[1], _T("res\\se2.png"));
	loadimage(&SE[2], _T("res\\se3.png"));
	loadimage(&SE[3], _T("res\\se4.png"));

	loadimage(&ENTRY[0], _T("res\\entry1.png"),150,212);//è������
	loadimage(&ENTRY[1], _T("res\\entry2.png"),150,212);
	loadimage(&ENTRY[2], _T("res\\entry3.png"), 150, 212);

	loadimage(&OVER, _T("res\\bg_0.png"));

	loadimage(&E[0], _T("res\\E_1.png"));//���㱳��
	loadimage(&E[1], _T("res\\E_2.png"));
	loadimage(&E[2], _T("res\\E_3.png"));
	loadimage(&E[3], _T("res\\E_4.png"));
	loadimage(&E[4], _T("res\\E_5.png"));
	loadimage(&E[5], _T("res\\E_6.png"));

	loadimage(&CAT[0], _T("res\\cat_1.png"), 48, 48);//��
	loadimage(&CAT[1], _T("res\\cat_2.png"), 48, 48);//��
	loadimage(&CAT[2], _T("res\\cat_3.png"), 48, 48);//��
	loadimage(&CAT[3], _T("res\\cat_4.png"), 48, 48);//��

	loadimage(&CAT[4], _T("res\\cat1.png"), 48, 48);//��
	loadimage(&CAT[5], _T("res\\cat2.png"), 48, 48);//��
	loadimage(&CAT[6], _T("res\\cat3.png"), 48, 48);//��
	loadimage(&CAT[7], _T("res\\cat4.png"), 48, 48);//��
	loadimage(&CAT[8], _T("res\\cat999.png"), 48, 48);//����

	loadimage(&P[0], _T("res\\p1.png"), 16, 600);//��
	loadimage(&P[1], _T("res\\p2.png"), 16, 600);//��
	loadimage(&P[2], _T("res\\p3.png"), 16, 600);//��
	loadimage(&P[3], _T("res\\p4.png"), 16, 600);//��
	loadimage(&P[4], _T("res\\p5.png"), 16, 600);//��
	loadimage(&P[5], _T("res\\p6.png"), 16, 600);//��
	loadimage(&P[6], _T("res\\p7.png"), 16, 600);//��
	loadimage(&P[7], _T("res\\p8.png"), 16, 600);//��

	loadimage(&N[0], _T("res\\n0.png"));//����
	loadimage(&N[1], _T("res\\n1.png"));
	loadimage(&N[2], _T("res\\n2.png"));
	loadimage(&N[3], _T("res\\n3.png"));
	loadimage(&N[4], _T("res\\n4.png"));
	loadimage(&N[5], _T("res\\n5.png"));
	loadimage(&N[6], _T("res\\n6.png"));
	loadimage(&N[7], _T("res\\n7.png"));
	loadimage(&N[8], _T("res\\n8.png"));
	loadimage(&N[9], _T("res\\n9.png"));

	loadimage(&LAND, _T("res\\land.png"));//½��
	loadimage(&PLAY[0], _T("res\\play_key1.png"));//��ģʽ
	loadimage(&PLAY[1], _T("res\\play_key2.png"));//����ģʽ
	loadimage(&READY, _T("res\\ready.png"), 332, 89);//ready
	loadimage(&TITLE, _T("res\\title.png"));//����
	loadimage(&TIP, _T("res\\tip.png"), 334, 260);//��ʾ
	loadimage(&KEY[0], _T("res\\sele_key1.png"), 150, 75);//ѡè��ť
	loadimage(&KEY[1], _T("res\\sele_key2.png"), 150, 75);
}

bool GetControl()
{
	bool res = false;
	if (_kbhit())
	{
		char ch = _getch();
		if (ch == ' ')res = true;
	}
	MOUSEMSG msg;
	while (MouseHit())
	{
		msg = GetMouseMsg();
		if (msg.mkLButton)res = true;
	}
	return res;
}

void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg)// ����͸���Ȼ�ͼ
{
	if (dstimg == NULL)return;
	// ������ʼ��
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = dstimg->getwidth();
	int dst_height = dstimg->getheight();

	//// ʵ��͸����ͼ  ���Ż�
	for (int iy = 0; iy < src_height; iy++)
	{
		for (int ix = 0; ix < src_width; ix++)
		{
			int srcX = ix + iy * src_width;
			int sa = ((src[srcX] & 0xff000000) >> 24);
			int sr = ((src[srcX] & 0xff0000) >> 16);
			int sg = ((src[srcX] & 0xff00) >> 8);
			int sb = src[srcX] & 0xff;
			if (x + ix >= 0 && x + ix < dst_width
				&& y + iy >= 0 && y + iy < dst_height)
			{
				int dstX = (x + ix) + (y + iy) * dst_width;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				dst[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16) | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8) | (sb * sa / 255 + db * (255 - sa) / 255);//������ɫ
			}
		}
	}
}
