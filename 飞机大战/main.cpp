//�ɻ���ս
//EasyX
#include <iostream>
#include <graphics.h>//easyx
using namespace std;

constexpr auto swidth = 600;
constexpr auto sheight = 1100;


bool PointInRect(int x, int y, RECT& r) 
{
	return (r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}


//һ����ʼ����
void Welcome()
{
	LPCTSTR title = _T("�ɻ���ս");
	LPCTSTR tplay = _T("��ʼ��Ϸ");
	LPCTSTR texit = _T("�˳���Ϸ");


	RECT tplayr, texitr;//λ�ýṹ��
	BeginBatchDraw();//��ֹƵ��
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(60, 0, _T("����"));
	settextcolor(BLACK);//20-23�и�������Ĵ�С����ʽ
	outtextxy(swidth / 2-textwidth(title) / 2, sheight / 10, title);//������ʾ����
	
	settextstyle(40, 0, _T("����"));//����λ�����С����Ҫ�� ����27-30�д���ǰ��
	tplayr.left = swidth / 2 - textwidth(tplay) / 2;
	tplayr.right = tplayr.left + textwidth(tplay);
	tplayr.top = sheight / 5*2.5;
	tplayr.bottom = tplayr.top + textheight(tplay);
	outtextxy(tplayr.left, tplayr.top, tplay);//��ʼ��Ϸ  ������λ��
	
	texitr.left = swidth / 2 - textwidth(texit) / 2;
	texitr.right = texitr.left + textwidth(texit);
	texitr.top = sheight / 5*3;
	texitr.bottom = texitr.top + textheight(texit);
	outtextxy(texitr.left, texitr.top, texit);//�˳���Ϸ  ������λ��

	EndBatchDraw();//��ֹƵ��

	while (true) {


		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton) {
			if (PointInRect(mess.x, mess.y, tplayr)) {
				return;
			}
		}
		else if (PointInRect(mess.x, mess.y, texitr)) {
			exit(0);
		}
	}






	
}


int main()
{
	//easyx��ʼ��
	initgraph(swidth, sheight, EW_NOMINIMIZE|EW_SHOWCONSOLE);
	bool is_live = true;
	while (is_live) {

		Welcome();
		//Play
	}

	return 0;
}