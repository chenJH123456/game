#include "head.h"
void init();// ��ʼ����Ϸ��Դ
void init1();//�ؿ���ʼ����
void Select();//ѡ���ɫ
void start();//���ǰ����
void game();// ��Ϸ����
void end();//����
void move(long time);// �ƶ�����
void Draw();// ���ƺ���
void reset();// ���û���
void put();// ���ƻ���
void load();// ������Դ
void drawWall();// ����ǽ
void drawScore(int x, int y, int sc, int dif, int se);// ���Ʒ���
void drawAlpha(IMAGE* dstimg, int x, int y, IMAGE* srcimg);// ����͸���Ȼ�ͼ
bool Die();// �ж�è����
bool GetControl();//�رմ���

int main()
{
	init();// ��Ϸ����ҳ��
	while (true)
	{
		Select();//ѡ���ɫ
		start();//���ǰ����
		game();// ��Ϸ����
		end();//����
		init1();//���ο�ʼ
	}
	return 0;
}

void init()//���п�ʼ����+��ʼ����ֵ
{
	load();// ����ͼ����Դ
	initgraph(1000, 600);// �����С

	srand((unsigned int)time(NULL));// ���������
	Ccolor = 1;//èɫ
	clock_t time = clock();// ��Ϸ��ʼʱ��
	int i = 0;
	while (true)// ��������
	{
		drawAlpha(&bk, 0, 0, &B[i]);//��ͼ
		i++;
		if (i == 4)i = 0;
		drawAlpha(&bk, 60, 50, &TITLE);//����Ϸ��
		drawAlpha(&bk, 480, 240, &CAT[Ccolor]);//��è
		drawAlpha(&bk, 400, 300, &PLAY[0]);//����
		drawAlpha(&bk, 400, 420, &PLAY[1]);//������
		put();//��ͼ
		if (MouseHit()) {  // �ж��Ƿ���������¼�
			MOUSEMSG msg = GetMouseMsg();  // ��ȡ����¼�
			if (msg.uMsg == WM_LBUTTONDOWN) {  // �ж��Ƿ�������������¼�
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 400 && mouseX <= 600 && mouseY >= 300 && mouseY <= 400) {//��ģʽ
					setcolor(GREEN);  // ������ɫΪ��ɫ
					setfillcolor(GREEN);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(30, 400, "����ѡ���ģʽ��");
					pattern = 1;
					Sleep(1000);
					break;  
				}
				else if (mouseX >= 400 && mouseX <= 600 && mouseY >= 420 && mouseY <= 520) {//����ģʽ
					setcolor(RED);  // ������ɫΪ��ɫ
					setfillcolor(RED);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(620, 400, "����ѡ������ģʽ��");
					pattern = 2;
					Sleep(1000);
					break;
				}
			}
		}
//		Sleep(50);//�����ٶȣ����ᵼ�½��濨��
	}
}

void init1()//���ο�ʼ����
{
	Ccolor = 1;//èɫ
	clock_t time = clock();// ��Ϸ��ʼʱ��
	while (true)// ��������
	{
		drawAlpha(&bk, 0, 0, &BK[3]);//��ͼ
		drawAlpha(&bk, 400, 300, &PLAY[0]);//����
		drawAlpha(&bk, 400, 420, &PLAY[1]);//������
		put();//��ͼ
		if (MouseHit()) {  // �ж��Ƿ���������¼�
			MOUSEMSG msg = GetMouseMsg();  // ��ȡ����¼�
			if (msg.uMsg == WM_LBUTTONDOWN) {  // �ж��Ƿ�������������¼�
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 400 && mouseX <= 600 && mouseY >= 300 && mouseY <= 400) {//��ģʽ
					setcolor(GREEN);  // ������ɫΪ��ɫ
					setfillcolor(GREEN);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(30, 400, "����ѡ���ģʽ��");
					pattern = 1;
					Sleep(1000);
					break;
				}
				else if (mouseX >= 400 && mouseX <= 600 && mouseY >= 420 && mouseY <= 520) {//����ģʽ
					setcolor(RED);  // ������ɫΪ��ɫ
					setfillcolor(RED);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(620, 400, "����ѡ������ģʽ��");
					pattern = 2;
					Sleep(1000);
					break;
				}
			}
		}
		//		Sleep(50);//�����ٶȣ����ᵼ�½��濨��
	}
}

void Select()//ѡ���ɫ
{
	Ccolor = 1;//èɫ
	clock_t time = clock();// ��Ϸ��ʼʱ��
	int i = 0;
	while (true)// ��������
	{
		drawAlpha(&bk, 0, 0, &SE[i]);//��ͼ
		i = rand() % 4;
		drawAlpha(&bk, 171, 180, &CAT[1]);//��è1
		drawAlpha(&bk, 466, 180, &CAT[5]);//��è2
		drawAlpha(&bk, 746, 180, &CAT[8]);//��è3
		drawAlpha(&bk, 120, 228, &ENTRY[0]);//������1
		drawAlpha(&bk, 410, 228, &ENTRY[1]);//������2
		drawAlpha(&bk, 695, 228, &ENTRY[2]);//������3

		drawAlpha(&bk, 120, 440, &KEY[0]);//����ť1
		drawAlpha(&bk, 415, 440, &KEY[0]);//����ť2
		drawAlpha(&bk, 700, 440, &KEY[1]);//����ť3

		put();//��ͼ
		if (MouseHit()) {  // �ж��Ƿ���������¼�
			MOUSEMSG msg = GetMouseMsg();  // ��ȡ����¼�
			if (msg.uMsg == WM_LBUTTONDOWN) {  // �ж��Ƿ�������������¼�
				int mouseX = msg.x;
				int mouseY = msg.y;
				if (mouseX >= 120 && mouseX <= 270 && mouseY >= 440 && mouseY <= 515) {//��ͨè
					setcolor(GREEN);  // ������ɫΪ��ɫ
					setfillcolor(GREEN);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(50, 400, "����ѡ����ͨè��");
					g = 6;
					vx = 6;
					if (c[0] >= 4)c[0] -= 4;
					if (c[1] >= 4)c[1] -= 4;
					if (c[2] >= 4)c[2] -= 4;
					if (c[3] >= 4)c[3] -= 4;
					character = 1;
					Sleep(1000);
					break;
				}
				else if (mouseX >= 415 && mouseX <= 565 && mouseY >= 440 && mouseY <= 515) {//��è
					setcolor(RED);  // ������ɫΪ��ɫ
					setfillcolor(RED);  // ���������ɫΪ��ɫ
					settextstyle(40, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(360, 400, "����ѡ���è��");
					g = 7;
					character = 2;
					vx = 10;
					if (c[0] < 4)c[0] += 4;
					if (c[1] < 4)c[1] += 4;
					if (c[2] < 4)c[2] += 4;
					if (c[3] < 4)c[3] += 4;
					Sleep(1000);
					if (pattern == 2) {
						drawAlpha(&bk, 0, 0, &BK[4]);//��ͼ
						put();//��ͼ
						Sleep(1500);
					}
					break;
				}
				else if (mouseX >= 700 && mouseX <= 850 && mouseY >= 440 && mouseY <= 515) {//����è
					setcolor(RED);  // ������ɫΪ��ɫ
					setfillcolor(RED);  // ���������ɫΪ��ɫ
					settextstyle(50, 0, _T("����"));  // �����ı���ʽ
					setbkmode(TRANSPARENT);  // ���ñ���͸��
					outtextxy(420, 380, "����è����100�ֺ����~");
					Sleep(1500);
				}
			}
		}
		//		Sleep(50);//�����ٶȣ����ᵼ�½��濨��
	}
}

void start()//�ڶ��ε��ǰ
{
	//4��ǽ
	X[0] = 900 + 30;//ǰ
	X[1] = 900 + 30 + 323;//��ǰ
	X[2] = 900 + 30 + 323 + 323;//�к�
	X[3] = 900 + 30 + 323 + 323 + 323;//��

	landX = 0;//���ǰ������ͼ������
	score = 0;//���ǰ����
	y = 250;//��Ϸ��ʼèλ��
	vy = 0;//�����ٶ�
	if (character == 2)Ccolor = 5;
	clock_t time = clock();//��Ϸ��ʼʱ��
	clock_t t = clock();// ��������
	background = rand() % 4;//����
	while (true)
	{
		drawAlpha(&bk, 0, 0, &BK[background]);
		drawAlpha(&bk, 347, 120, &READY);
		drawAlpha(&bk, 0, 0, &TIP);
		drawAlpha(&bk, (int)x, (int)y, &CAT[Ccolor]);
		drawAlpha(&bk, (int)landX, (int)landY, &LAND);
		drawScore(500, 60, score, 13, 26);
		landX -= (clock() - t) * vx / 100;

		t = clock();
		put();
		if (landX < -800)landX = 0;//ˢ�µ�����ͼ
		if (GetControl())break;
		Sleep(10);
	}
}

void game()// ��Ϸ����
{
	//����
	startTime = clock();
	long time = clock();
	while (!Die())
	{
		// �ƶ�
		move(clock() - time);
		time = clock();
		if (GetControl()) {//���
			if (character == 1)vy = -20;// �����ٶ�
			else vy = -10;
			if (character == 1) {//��ɫ1��ɫ����0-3
				if (pattern == 1) {//��
					if (Ccolor < 2)Ccolor++;//������ɫ
					else Ccolor = 0;
				}
				else {//����
					if (Ccolor < 3)Ccolor++;//������ɫ
					else Ccolor = 0;
				}
			}
			else {//��ɫ2��ɫ����4-7
				if (pattern == 1) {//��
					if (Ccolor < 6)Ccolor++;//������ɫ
					else Ccolor = 4;
				}
				else {//����
					if (Ccolor < 7)Ccolor++;//������ɫ
					else Ccolor = 4;
				}
			}
			}
		Draw();// ����
		Sleep(10);
	}
	startTime = clock();
	while (clock() - startTime < 1000);
	vy = -30;
	time = clock();
	drawAlpha(&OVER, 0, 0, &bk);// ���ݽ��㱳��
}

void end()// ��������
{
	startTime = clock();
	if (score > 0)
	{
		if (score > 1) {
			int i = 2;
			while (true)//��߷ֶ���
			{
				drawAlpha(&bk, 0, 0, &E[i]);
				i++;
				if (i == 6)i = 2;
				put();//��ͼ
				if (GetControl())break;
				Sleep(50);
			}
		}
		else drawAlpha(&bk, 0, 0, &E[1]);
	}
	else {
		drawAlpha(&bk, 0, 0, &E[0]);
	}
	drawScore(500, 150, score, 16, 16);// ��ӡ��ǰ��
	while (MouseHit()) GetMouseMsg();
	while (_kbhit())_getch();//�رռ�
	put();
	while (true)
	{
		if (GetControl())break;
		Sleep(10);
	}
}

void move(long time)// è, ����, ǽ�ƶ�
{
	y += time * vy / 100;//è�ƶ��ٶ�
	vy += g * time / 100;
	if (y < 0 - 10)y = -10;//��ֹè�ɳ��ϱ߽�

	landX -= time * vx / 50;//½���ƶ��ٶ�
	if (landX < -888)landX = 0;//ˢ��½����ͼ
	
	X[0] -= time * vx / 50;//ǽ�ƶ��ٶ�
	X[1] -= time * vx / 50;
	X[2] -= time * vx / 50;
	X[3] -= time * vx / 50;
	Y[0] = 0;
	Y[1] = 0;
	Y[2] = 0;
	Y[3] = 0;
	if (pattern == 1) {//��
		if (X[0] < -50)//ǰǽ��ʧλ��
		{
			X[0] = X[1] + 1000;//ǰǽ��һ�γ���λ��
			c[0] = rand() % 3;
			if (character == 2)c[0] += 4;
		}
		if (X[1] < -50)//��ǰǽ��ʧλ��
		{
			X[1] = X[2] + 1000;//��ǰǽ��һ�γ���λ��
			c[1] = rand() % 3;
			if (character == 2)c[1] += 4;
		}
		if (X[2] < -50)//�к�ǽ��ʧλ��
		{
			X[2] = X[3] + 1000;//�к�ǽ��һ�γ���λ��
			c[2] = rand() % 3;
			if (character == 2)c[2] += 4;
		}
		if (X[3] < -50)//��ǽ��ʧλ��
		{
			X[3] = X[0] + 1000;//��ǽ��һ�γ���λ��
			c[3] = rand() % 3;
			if (character == 2)c[3] += 4;
		}
	}
	else {//����
		if (X[0] < -50)//ǰǽ��ʧλ��
		{
			X[0] = X[1] + 1000;//ǰǽ��һ�γ���λ��
			c[0] = rand() % 4;
			if (character == 2)c[0] += 4;
		}
		if (X[1] < -50)//��ǰǽ��ʧλ��
		{
			X[1] = X[2] + 1000;//��ǰǽ��һ�γ���λ��
			c[1] = rand() % 4;
			if (character == 2)c[1] += 4;
		}
		if (X[2] < -50)//�к�ǽ��ʧλ��
		{
			X[2] = X[3] + 1000;//�к�ǽ��һ�γ���λ��
			c[2] = rand() % 4;
			if (character == 2)c[2] += 4;
		}
		if (X[3] < -50)//��ǽ��ʧλ��
		{
			X[3] = X[0] + 1000;//��ǽ��һ�γ���λ��
			c[3] = rand() % 4;
			if (character == 2)c[3] += 4;
		}
	}

	if (character == 1)if ((int)(clock() - startTime) > 7250)score = (int)(clock() - startTime - 7250) / 2775 + 1;//��һǽλ��(��ʼ�Ʒֵ�)
	if (character == 2)if ((int)(clock() - startTime) > 4300)score = (int)(clock() - startTime - 4300) / 1660 + 1;//��һǽλ��(��ʼ�Ʒֵ�)
//	score = (int)(clock() - startTime);
}

bool Die()// �ж�����
{
	if (y > 450)return true;
	if (x + 40 > X[0] && x - 20 < X[0])if (Ccolor != c[0])return true;
	if (x + 40 > X[1] && x - 20 < X[1])if (Ccolor != c[1])return true;
	if (x + 40 > X[2] && x - 20 < X[2])if (Ccolor != c[2])return true;
	if (x + 40 > X[3] && x - 20 < X[3])if (Ccolor != c[3])return true;
	return false;
}

void reset()
{
	drawAlpha(&bk, 0, 0, &BK[background]);
}

void put()
{
	putimage(0, 0, &bk);
}

void Draw()
{
	drawAlpha(&bk, 0, 0, &BK[background]);//��ʼ����ͼ
	drawWall();//��ǽ
	drawAlpha(&bk, (int)landX, (int)landY, &LAND);//������
	drawAlpha(&bk, (int)x, (int)y, &CAT[Ccolor]);//��è
	drawScore(500, 60, score, 13, 26);// ������
	put();// ����������������
}

void drawWall()
{
	// ǰ
	drawAlpha(&bk, (int)X[0], Y[0], &P[c[0]]);
	// ǰ��
	drawAlpha(&bk, (int)X[1], Y[1], &P[c[1]]);
	// ����
	drawAlpha(&bk, (int)X[2], Y[2], &P[c[2]]);
	//��
	drawAlpha(&bk, (int)X[3], Y[3], &P[c[3]]);
}

void drawScore(int x, int y, int sc, int dif, int se)
{
	// ������������ʾ
	int t = sc;
	int num[8];//8λ��λ���ϵ�����
	int length = 0;
	do
	{
		num[length] = t % 10;
		length++;
		t /= 10;
	} while (t != 0);
	int s = x - dif * length;// �������ʼ����
	for (int i = length - 1; i >= 0; i--)
	{
		drawAlpha(&bk, s, y, &N[num[i]]);
		s += se;
	}
}

