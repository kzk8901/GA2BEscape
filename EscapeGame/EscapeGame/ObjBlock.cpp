//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"
#include "ObjBlock.h"
#include "ObjBackGround.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
bool room_c[3] = { false,false,false };
bool text_loop = true;
int text_m = -1;
bool event_skip = false;
//�}�b�v���--------------------------------------------
//1 = ��, 2 = ��l�������ʒu, 3 = ���t����(����̃J�M�����Ă���ΊJ��)
//4 = �������Ă܂�, 5 = �i���o�[���b�N�h�A , 6 = �U�A�C�e��
int block_data_map[4][15][20] =
{
	//�X�^�[�g�}�b�v1F mapnum==0
	{
		// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{  1, 1, 1, 1, 1, 1, 1, 1, 1,99, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{  1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, },// 1
		{  1,30,31,31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,31,31,30, 1, },// 2
		{  1, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{  1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 1, },// 4
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, },// 7
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{  1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, },//12
		{  1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 9, 0, 0, 0, 1, 1, 1, 1, 1, 1, },//13
		{  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//�t���}�b�v1Fmapnum==1
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1,39,39,39,39,39,39,39,47, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{ 1,35,38,35,35,35,35,35, 0, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1,35,35,35,35,35,35,35, 0, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,50,50,50,50, 0, 1, },// 9
		{ 1, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0,50,50,50,50,50, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,50,50,50,50, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,51,50,50,50, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1,98, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//�i���}�b�v1Fmapnum==2
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0, 0, 0, 0,33,41, 0, 0,43,31, 0, 0,42,33, 0, 0, 0, 0, 1, },// 1
		{ 1, 0, 0, 0, 0,33,33, 0, 0, 0, 0, 0, 0,33,33, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0,45,33,33, 0, 0, 0, 0, 0, 0,33,33,46, 0, 0, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{96, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 1, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//�����}�b�v1Fmapnum==3
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0,44,34, 0, 0, 0, 0, 0, 0,35,35, 0,37,37, 0,35,35, 0, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,94, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},
};
//�}�b�v���-------------------------------------------------
//�C�j�V�����C�Y
void CObjBlock::Init()
{

	mapnum = 0;

	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data_map, sizeof(int)*(4 * 15 * 20));

	SetHero();
	SetKirara();
	SetKanata();
	SetTowa();

	eventclockflag = false;
	eventclocktime = 0;
	blockx = 0;
	blocky = 0;
	blockm_x = 0.0f;
	blockm_y = 0.0f;
	moveshelf = 0.0f;
	blockdeleteYN = false;
	animationtime = 0;
	event_num = 1;
	lockpasu = 0;
	for (int i=0; i < 3; i++)
		event_clock[i] = false;

	((UserData*)Save::GetData())->number[0] = 402;
	((UserData*)Save::GetData())->number[1] = 402;
	((UserData*)Save::GetData())->number[2] = 112;

	//�����蔻��̂���u���b�N�̓i���o�[�������ɓ����
	int blocknumber[99] =
	{
		1, 3, 5, 7, 8, 9,10,30,31,32,
		33,34,35,36,37,38,39,40,41,42,
		43,44,50,51,52,
	};

	for (int i = 0; i < 99; i++)
	{
		notonblock[i] = blocknumber[i];
	}
}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�w�i��ݒ�
	CObjBackGround* bgro = (CObjBackGround*)Objs::GetObj(OBJ_BGROUND);
	//�����̈ʒu��ݒ�
	CObjKirara* kirara = (CObjKirara*)Objs::GetObj(OBJ_KIRARA);
	//�i���̈ʒu��ݒ�
	CObjTowa* towa = (CObjTowa*)Objs::GetObj(OBJ_TOWA);
	//�t���̈ʒu��ݒ�
	CObjKanata* kanata = (CObjKanata*)Objs::GetObj(OBJ_KANATA);

	//��b�C�x���g������-------------------------------------------------
	if (Input::GetVKey('O') == true)
	{
		event_num = 1;
		event_skip = true;
	}
	//�f�o�b�N�p------------------------------------------------
	if (Input::GetVKey('P') == true)
	{
		event_num = 9;
	}
	if (Input::GetVKey('L') == true)
	{
		event_num = 19;
	}
	if (Input::GetVKey('K') == true)
	{
		event_num = 13;
	}
	if (Input::GetVKey('J') == true)
	{
		event_num = 24;
	}
	//----------------------------------------------------------


	//�I�[�v�j���O�J�n---------------------------------
	//�C�x���g�i���o�[(1�`9)
	if (event_num==1)
	{
		hero->SetHeroEventFlag(true,1);
	}
	if (event_num==2)
	{
		towa->SetTowaEventFlag(true, 1);
	}
	if (event_num==3)
	{
		hero->SetHeroEventFlag(true, 2);
	}
	if (event_num == 4)
	{
		kanata->SetKanataEventFlag(true, 1);
	}
	if (event_num == 5)
	{
		kirara->SetKiraraEventFlag(true, 1);
	}
	if (event_num == 6)
	{
		hero->SetVec(3);
		kanata->SetVec(3);
		event_num=7;
	}
	if (event_num == 7)
	{
		kanata->SetKanataEventFlag(true, 2);
	}
	if (event_num == 8)
	{
		towa->SetTowaEventFlag(true, 2);
	}
	if (event_num == 9)
	{
		towa->SetTowaEventFlag(true, 3);
		kanata->SetKanataEventFlag(true, 3);
		kirara->SetKiraraEventFlag(true, 2);
		event_num = 98;
		hero_move = true;
	}
	//�I�[�v�j���O�I��---------------------------------

	//�t���}�b�v1F�C�x�J�n-----------------------------
	//�C�x���g�i���o�[(10�`15)
	//�����ɓ������Ƃ�
	if (event_clock[0] == false)
	{
		if (event_num == 10)
			hero->SetHeroEventFlag(true, 3);
		if (event_num == 11)
		{
			kanata->SetVec(1);
			event_num = 12;
		}
		if (event_num == 12)
		{
			kanata->SetVec(4);
			event_num = 99;
			event_clock[0] = true;
		}	
	}
	//��������肵����
	if (event_num == 13)
		hero->SetHeroEventFlag(true, 4);
	if (event_num == 14)
	{
		kanata->SetVec(1);
		event_num = 15;
	}
	if (event_num == 15)
	{
		kanata->SetVec(4);
		event_num = 99;
	}
	//�t���}�b�v1F�C�x�I��-----------------------------

	//�i���}�b�v1F�C�x�J�n-----------------------------
	//�C�x���g�i���o�[(16�`21)
	//�����ɓ������Ƃ�
	if (event_clock[1] == false)
	{
		if (event_num == 16)
			hero->SetHeroEventFlag(true, 5);
		if (event_num == 17)
		{
			towa->SetVec(2);
			event_num = 18;
		}
		if (event_num == 18)
		{
			towa->SetVec(4);
			event_num = 99;
			event_clock[1] = true;
		}
	}
	//��������肵����
	if (event_num == 19)
		hero->SetHeroEventFlag(true, 6);
	if (event_num == 20)
	{
		kanata->SetVec(3);
		event_num = 21;
	}
	if (event_num == 21)
	{
		kanata->SetVec(4);
		event_num = 99;
	}

	//�i���}�b�v1F�C�x�I��-----------------------------

	//�����}�b�v1F�C�x�J�n-----------------------------
	//�C�x���g�i���o�[(22�`2)
	//�����ɓ������Ƃ�
	if (event_clock[1] == false)
	{
		if (event_num == 22)
			hero->SetHeroEventFlag(true, 7);
		if (event_num == 23)
		{
			event_num = 99;
			event_clock[1] = true;
		}
	}
	//��������肵����
	if (event_num == 24)
	{
		hero->SetVec(1);
		event_num = 25;
	}
	if (event_num == 25)
	{
		kirara->SetKiraraEventFlag(true,3);
	}
	if (event_num == 26)
	{
		kirara->SetVec(4);
		event_num = 99;
	}

	//�����}�b�v1F�C�x�I��-----------------------------

	//�ړ��}�X��z�u����---------------------------------
	if (event_num == 98)
	{
		m_map[mapnum][kirara_y][kirara_x] = 95;
		m_map[mapnum][towa_y][towa_x] = 97;
		m_map[mapnum][kanata_y][kanata_x] = 99;
		event_num = 99;
	}

	//��l�����T�����J�n����---------------------------
	//�C�x���g�i���o�[(99)
	if (event_num == 99)
	{
		hero->SetActionflag(false);
		event_num = 0;
	}

	//��b�C�x���g������-------------------------------------------------

	//�X�^�[�gF1�ֈړ�---------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 98 && hero->GetMoveFlag() == false||
		m_map[mapnum][hero_y][hero_x] == 96 && hero->GetMoveFlag() == false||
		m_map[mapnum][hero_y][hero_x] == 94 && hero->GetMoveFlag() == false)
	{
		text_loop = true;
		text_m = -2;
		//��l���̈ʒu�ۑ�
		//�t��
		if (m_map[mapnum][hero_y][hero_x] == 98)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 2;
			kanata->SetKanataIn(false);
		}
		//�i��
		else if (m_map[mapnum][hero_y][hero_x] == 96)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 2;
			towa->SetTowaIn(false);
		}
		//�����
		else if (m_map[mapnum][hero_y][hero_x] == 94)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 2;
			kirara->SetKiraraIn(false);
		}
		//���ɍs���i���o�[��n��
		Mapchange(0);
		//����mapnum������
		mapnum = 0;
		//��l���̈ʒu�X�V
		SetHero();
	}

	//�t���}�b�v1F�ֈړ�-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 99 && hero->GetMoveFlag() == false)
	{
		word=0;
		text_loop = true;
		if (room_c[0] == false)
		{
			text_m = 1;
			room_c[0] = true;
		}
		else if(room_c[0] == true)
		{
			text_m = -4;
		}
		//��l���̈ʒu�ۑ�
		m_map[mapnum][hero_y + 1][hero_x] = 2;
		//���ɍs���i���o�[��n��
		Mapchange(1);
		//����mapnum������
		mapnum = 1;
		//�t���\��
		kanata->SetKanataIn(true);
		//��l���̈ʒu�X�V
		SetHero();
		//�t���̈ʒu�X�V
		SetKanata();
		//���߂ĕ����ɓ�������C�x���g���N����
		event_num = 10;
	}

	//�i���}�b�v1F�ֈړ�-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 97 && hero->GetMoveFlag() == false)
	{
		word = 0;
		text_loop = true;
		if (room_c[1] == false)
		{
			text_m = 2;
			room_c[1] = true;
		}
		else if (room_c[1] == true)
		{
			text_m = -5;
		}
		
		//��l���̈ʒu�ۑ�
		m_map[mapnum][hero_y][hero_x - 1] = 2;
		//���ɍs���i���o�[��n��
		Mapchange(2);
		//����mapnum������
		mapnum = 2;
		//�i���\��
		towa->SetTowaIn(true);
		//��l���̈ʒu�X�V
		SetHero();
		//�i���̈ʒu�X�V
		SetTowa();
		//���߂ĕ����ɓ�������C�x���g���N����
		event_num = 16;
	}

	//�����}�b�v1F�ֈړ�-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 95 && hero->GetMoveFlag() == false)
	{
		word = 0;
		text_loop = true;
		if (room_c[2] == false)
		{
			text_m = 0;
			room_c[2] = true;
		}
		else if (room_c[2] == true)
		{
			text_m = -3;
		}
		//��l���̈ʒu�ۑ�
		m_map[mapnum][hero_y][hero_x + 1] = 2;
		//���ɍs���i���o�[��n��
		Mapchange(3);
		//����mapnum������
		mapnum = 3;
		//�����\��
		kirara->SetKiraraIn(true);
		//��l���̈ʒu�X�V
		SetHero();
		//�����̈ʒu�X�V
		SetKirara();
		//���߂ĕ����ɓ�������C�x���g���N����
		event_num = 22;
	}

	//----------------------------------------------

	//�ǊJ����p�C�x���g�t���O
	if (eventclockflag == true)
	{
		hero->SetHeroEventFlag(true, 0);
		eventclocktime++;
		//------------------------------
		if (blockmovevec == 1)
			blockm_x += 0.5;
		if (blockmovevec == 2)
			blockm_x -= 0.5;
		if (blockmovevec == 3)
			blockm_y -= 0.5;
		if (blockmovevec == 4)
			blockm_y += 0.5;
		//------------------------------
		if (eventclocktime > 64)
		{
			hero->SetHeroEventFlag(false, 0);
			eventclocktime = 0;
			eventclockflag = 0;
			//�u���b�N�������Ȃ��ۂ̓���
			if (blockdeleteYN == true)
			{
				if (blockmovevec == 1)
					m_map[mapnum][blocky][blockx + 1] = 1;
				if (blockmovevec == 2)
					m_map[mapnum][blocky][blockx - 1] = 1;
				if (blockmovevec == 3)
					m_map[mapnum][blocky - 1][blockx] = 1;
				if (blockmovevec == 4)
					m_map[mapnum][blocky + 1][blockx] = 1;
			}
			//�㏈���i���������j-----------
			if (blockmovevec == 1 || blockmovevec == 2)
				blockm_x = 0.0;
			if (blockmovevec == 3 || blockmovevec == 4)
				blockm_y = 0.0;
			//------------------------------
			m_map[mapnum][blocky][blockx] = 0;
		}
	}

	//�I�������p�C�x���g�t���O---------------------------
	if (moveshelf > 0.0f)
	{
		bool finishflag = false;
		hero->SetHeroEventFlag(true, 0);
		eventclocktime++;
		moveshelf += 0.5;
		if (eventclocktime > 64)
		{
			hero->SetHeroEventFlag(false, 0);
			eventclocktime = 0;
			for (int i = 0; finishflag == false; i++)
			{
				if (m_map[mapnum][blocky][blockx + i] != 39)
				{
					m_map[mapnum][blocky][blockx + i] = 36;
					for (int j = 1; finishflag == false; j++)
					{
						if (m_map[mapnum][blocky][blockx + i - j] == 39)
						{
							m_map[mapnum][blocky][blockx + i - j] = 36;
						}
						else if (m_map[mapnum][blocky][blockx  + i - j] != 39)
						{
							m_map[mapnum][blocky][blockx + i - j + 1] = 0;
							finishflag = true;
						}
					}
				}
			}
			//�㏈��
			moveshelf = 0.0f;
			blockx = 0;
			blocky = 0;
		}
	}

	//�A�j���[�V�����������p
	animationtime++;
	if (animationtime >= 61)
	{
		animationtime = 0;
	}

	//�󋵂ɍ��킹�ď��
	//�w�i�؂�ւ�
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bgro->SetMapChip(mapnum, i, j, m_map[mapnum][i][j]);
		}
	}
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu

	//�e�L�X�g�E�B���h�E2�i�c�����j
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 230.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);



	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�
	/*
	src.m_top = 0.0f;
	src.m_left = 320.5f;
	src.m_right =src.m_left+64.0f;
	src.m_bottom = 64.0f;
	*/

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<20;j++)
		{
			//���t�����\��
			if (m_map[mapnum][i][j] == 3)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//���\��
			if (m_map[mapnum][i][j] == 4)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//�i���o�[���b�N�h�A
			if (m_map[mapnum][i][j] == 5)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//�U���\��
			if (m_map[mapnum][i][j] == 6)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//�U�u���b�N�\��
			if (m_map[mapnum][i][j] == 7)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + blockm_y;
				dst.m_left = j*32.0f + blockm_x;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//----------------------------------------

			//�Ƌ�}�b�v����Q��--------------------
			//�A���\��
			if (m_map[mapnum][i][j] == 30)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 16.0f;
				src.m_bottom = src.m_top + 32.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f-32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�`��
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			//�I�\��
			if (m_map[mapnum][i][j] == 31 || m_map[mapnum][i][j] == 34 || m_map[mapnum][i][j] == 43 || m_map[mapnum][i][j] == 44)
			{
				int skipcount = 0;
				int vase = 0;

				//�ԕr�̕\��������
				if (m_map[mapnum][i][j] == 34)
				{
					vase = 1;
				}

				if (m_map[mapnum][i][j + 1] == 31 || m_map[mapnum][i][j + 1] == 34 || m_map[mapnum][i][j + 1] == 43 || m_map[mapnum][i][j + 1] == 44)
				{
					skipcount++;
					//�ԕr�̕\��������
					if (m_map[mapnum][i][j + 1] == 34)
					{
						vase = 2;
					}
				}

				//�I�\��
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f * (skipcount + 1);
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);

				if (vase >= 1)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;
					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = (j + vase - 1) * 32.0f + 8.0f;
					dst.m_right = dst.m_left + 32.0f - 8.0f;
					dst.m_bottom = dst.m_top + 32.0f - 8.0f;

					//�`��
					Draw::Draw(15, &src, &dst, c, 0.0f);
				}

				j += skipcount;
			}
			//��(��)�\��
			if (m_map[mapnum][i][j] == 32)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 128.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			//�x�b�h�\��
			if (m_map[mapnum][i][j] == 33 ||
				m_map[mapnum][i][j] == 41 ||
				m_map[mapnum][i][j] == 42)
			{
				int skipcountx = 0;
				int county = 0;
				bool skip = false;

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 64.0f;

				if (m_map[mapnum][i + 1][j] == 33 || m_map[mapnum][i + 1][j] == 41 || m_map[mapnum][i + 1][j] == 42)
				{
					skip = true;
				}
				for (int s = 1; m_map[mapnum][i][j + s] == 33 || m_map[mapnum][i][j + s] == 41 || m_map[mapnum][i][j + s] == 42; s++)
				{
					skipcountx++;
				}
				while (m_map[mapnum][i - 1 - county][j] == 33 || m_map[mapnum][i - 1 - county][j] == 41 || m_map[mapnum][i - 1 - county][j] == 42)
				{
					county++;
				}

				if (skip == false)
				{
					//�\���ʒu�̐ݒ�
					dst.m_top = (i - county)*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
					dst.m_bottom = dst.m_top + 32.0f * (county + 1);

					//�`��
					Draw::Draw(14, &src, &dst, c, 0.0f);
				}

				j += skipcountx;
			}
			//�{�I�\��
			if ((m_map[mapnum][i][j] == 35  
				|| m_map[mapnum][i][j] == 36 
				|| m_map[mapnum][i][j] == 37
				|| m_map[mapnum][i][j] == 38) 
				&& hero_y < i)
			{
				if (m_map[mapnum][i + 1][j] == 35 || m_map[mapnum][i + 1][j] == 36 || m_map[mapnum][i + 1][j] == 37 || m_map[mapnum][i + 1][j] == 38)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;

					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//�`��
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else if (m_map[mapnum][i - 1][j] == 35 || m_map[mapnum][i - 1][j] == 36 || m_map[mapnum][i - 1][j] == 37 || m_map[mapnum][i - 1][j] == 38)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 64.0f;

					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//�`��
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else
				{
					int skipcountx = 0;
					int overcount = 0;

					for (int s = 1; m_map[mapnum][i][j + s] == 35 || m_map[mapnum][i][j + s] == 36 || m_map[mapnum][i][j + s] == 37 || m_map[mapnum][i][j + s] == 38; s++)
					{
						skipcountx++;
						if (skipcountx == 5)
						{
							skipcountx = 1;
							overcount += 1;
						}
					}

					for (int x = 0; x <= skipcountx;)
					{
						if (overcount > 0)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 64.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 128.0f;
							dst.m_bottom = dst.m_top + 64.0f;

							x += 4;
							overcount -= 1;
						}
						else
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 16.0f * (skipcountx + 1);
							src.m_bottom = src.m_top + 64.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
							dst.m_bottom = dst.m_top + 64.0f;

							x += skipcountx;
							if (skipcountx == 0)
								x++;
						}
					}

					//�`��
					Draw::Draw(16, &src, &dst, c, 0.0f);

					j += skipcountx;
				}
			}
			//�����{�I�\��
			if (m_map[mapnum][i][j] == 39 && hero_y < i)
			{
				int skipcountx = 0;
				int overcount = 0;
				for (int s = 1; m_map[mapnum][i][j + s] == 39; s++)
				{
					skipcountx++;
					if (skipcountx == 5)
					{
						skipcountx = 1;
						overcount += 1;
					}
				}
				for (int x = 0; x <= skipcountx;)
				{
					if (overcount > 0)
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;

						//�\���ʒu�̐ݒ�
						dst.m_top = i*32.0f - 16.0f;
						dst.m_left = j*32.0f + moveshelf;
						dst.m_right = dst.m_left + 128.0f;
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += 4;
						overcount -= 1;
					}
					else
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 16.0f * (skipcountx + 1);
						src.m_bottom = src.m_top + 64.0f;

						//�\���ʒu�̐ݒ�
						dst.m_top = i *32.0f - 16.0f;
						dst.m_left = j*32.0f + moveshelf;
						dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += skipcountx;
					}
				}

				//�`��
				Draw::Draw(16, &src, &dst, c, 0.0f);

				j += skipcountx;
			}
			//����������\��
			if (m_map[mapnum][i][j] == 40)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 128.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(20, &src, &dst, c, 0.0f);
			}
			//���(51�̈ʒu�ɋ��ɂ�u��)
			if (m_map[mapnum][i][j] == 50 || m_map[mapnum][i][j] == 51 || m_map[mapnum][i][j] == 52)
			{
				int skipcountx = 0;
				int county = 0;
				bool skip = false;

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 256.0f;
				src.m_bottom = src.m_top + 256.0f;

				if (m_map[mapnum][i + 1][j] == 50 || m_map[mapnum][i + 1][j] == 51 || m_map[mapnum][i + 1][j] == 52)
				{
					skip = true;
				}
				for (int s = 1; m_map[mapnum][i][j + s] == 50 || m_map[mapnum][i][j + s] == 51 || m_map[mapnum][i][j + s] == 52; s++)
				{
					skipcountx++;
				}
				while (m_map[mapnum][i - 1 - county][j] == 50 || m_map[mapnum][i - 1 - county][j] == 51 || m_map[mapnum][i - 1 - county][j] == 52)
				{
					county++;
				}

				if (skip == false)
				{
					//�\���ʒu�̐ݒ�
					dst.m_top = (i - county)*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
					dst.m_bottom = dst.m_top + 32.0f * (county + 1);

					//�`��
					Draw::Draw(22, &src, &dst, c, 0.0f);
				}

				j += skipcountx;

				for (int w = j - skipcountx; w <= j; w++)
				{
					for (int z = i - county; z <= i; z++)
					{
						if (m_map[mapnum][z][w] == 51)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 92.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = z * 32.0f - 16.0f;
							dst.m_left = w * 32.0f;
							dst.m_right = dst.m_left + 32.0f;
							dst.m_bottom = dst.m_top + 32.0f;

							//�`��
							Draw::Draw(23, &src, &dst, c, 0.0f);
						}
						if (m_map[mapnum][z][w] == 52)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 64.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 92.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = z*32.0f - 16.0f;
							dst.m_left = w*32.0f;
							dst.m_right = dst.m_left + 32.0f;
							dst.m_bottom = dst.m_top + 32.0f;

							//�`��
							Draw::Draw(23, &src, &dst, c, 0.0f);
						}
					}
				}
			}
		}
	}

	//�i���o�[���b�N���̉摜�\��
	if (lockpasu > 0)
	{
		if (lockpasu == 1)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 256.0f;
			src.m_bottom = src.m_top + 256.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 80.0f;
			dst.m_left = 150.0f;
			dst.m_right = dst.m_left + 320.0f;
			dst.m_bottom = dst.m_top + 320.0f;

			//�`��
			Draw::Draw(24, &src, &dst, c, 0.0f);
		}
		if (lockpasu == 2)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 256.0f;
			src.m_bottom = src.m_top + 256.0f;

			//�\���ʒu�̐ݒ�
			dst.m_top = 80.0f;
			dst.m_left = 150.0f;
			dst.m_right = dst.m_left + 320.0f;
			dst.m_bottom = dst.m_top + 320.0f;

			//�`��
			Draw::Draw(25, &src, &dst, c, 0.0f);
		}
	}
}
//���������Ƀu���b�N�����邩�ǂ����̔���
//Characternum 1=��l�� 2=����� 3=�t�� 4=�i��
bool CObjBlock::ThereIsBlock(int vec ,int Characternum)
{
	//��l��
	if (Characternum == 1)
	{
		//�E�������̓���
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y][hero_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				hero_x = hero_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//���������̓���
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y][hero_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				hero_x = hero_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�㓮�����̓���
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y - 1][hero_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				hero_y = hero_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�������Ƃ��̓���
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y + 1][hero_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				hero_y = hero_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	//�����
	else if (Characternum == 2)
	{
		//�E�������̓���
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y][kirara_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y][kirara_x + 1] = 8;
				kirara_x = kirara_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//���������̓���
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y][kirara_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y][kirara_x - 1] = 8;
				kirara_x = kirara_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�㓮�����̓���
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y - 1][kirara_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y - 1][kirara_x] = 8;
				kirara_y = kirara_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�������Ƃ��̓���
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y + 1][kirara_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y + 1][kirara_x] = 8;
				kirara_y = kirara_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//�i��
	else if (Characternum == 3)
	{
		//�E�������̓���
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y][towa_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y][towa_x + 1] = 9;
				towa_x = towa_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//���������̓���
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y][towa_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y][towa_x - 1] = 9;
				towa_x = towa_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�㓮�����̓���
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y - 1][towa_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y - 1][towa_x] = 9;
				towa_y = towa_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�������Ƃ��̓���
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y + 1][towa_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y + 1][towa_x] = 9;
				towa_y = towa_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//�t��
	else if (Characternum == 4)
	{
		//�E�������̓���
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y][kanata_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y][kanata_x + 1] = 10;
				kanata_x = kanata_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//���������̓���
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y][kanata_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y][kanata_x - 1] = 10;
				kanata_x = kanata_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�㓮�����̓���
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y - 1][kanata_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y - 1][kanata_x] = 10;
				kanata_y = kanata_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//�������Ƃ��̓���
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y + 1][kanata_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y + 1][kanata_x] = 10;
				kanata_y = kanata_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}
//��l���A�N�V����
void CObjBlock::HeroAction(int vec)
{
	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�A�C�e���Q��
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//������
	if (m_map[mapnum][hero_y][hero_x] == 4)
	{
		m_map[mapnum][hero_y][hero_x] = 0;
		itm->GetItem(1);
		//((UserData*)Save::GetData())->item1 = true;
	}

	//�E
	if (vec == 1)
	{
		if (m_map[mapnum][hero_y][hero_x + 1] == 3)
		{
			;
		}
		//������
		if (m_map[mapnum][hero_y][hero_x + 1] == 4)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(1);
		}
		//�U������
		if (m_map[mapnum][hero_y][hero_x + 1] == 6)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(2);
		}
		//�U�ǔ���
		if (m_map[mapnum][hero_y][hero_x + 1] == 7)
		{
			blockmovevec = 4;
			blockx = hero_x + 1; blocky = hero_y;
			blockdeleteYN = false;
			eventclockflag = true;
		}
		//���̏�̃�������锻��
		if (m_map[mapnum][hero_y][hero_x + 1] == 40)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 32;
			itm->GetItem(5);
		}
		//�x�b�h�̏�̃���2����锻��
		if (m_map[mapnum][hero_y][hero_x + 1] == 41)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 33;
			itm->GetItem(6);
		}
		//�x�b�h�̏�̃���3����锻��
		if (m_map[mapnum][hero_y][hero_x + 1] == 42)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 33;
			itm->GetItem(7);
		}
		//�O�~�̉��̃���4����锻��
		if (m_map[mapnum][hero_y][hero_x + 1] == 46)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(8);
		}
	}
	//��
	if (vec == 2)
	{
		if (m_map[mapnum][hero_y][hero_x - 1] == 3)
		{
			;
		}
		//������
		if (m_map[mapnum][hero_y][hero_x - 1] == 4)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(1);
		}
		//�U������
		if (m_map[mapnum][hero_y][hero_x - 1] == 6)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(2);
		}
		//���̏�̃���1����锻��
		if (m_map[mapnum][hero_y][hero_x - 1] == 40)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 32;
			itm->GetItem(5);
		}
		//�x�b�h�̏�̃���2����锻��
		if (m_map[mapnum][hero_y][hero_x - 1] == 41)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 33;
			itm->GetItem(6);
		}
		//�x�b�h�̏�̃���3����锻��
		if (m_map[mapnum][hero_y][hero_x - 1] == 42)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 33;
			itm->GetItem(7);
		}
		//�O�~�̉��̃���4����锻��
		if (m_map[mapnum][hero_y][hero_x - 1] == 46)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(8);
		}
	}
	//��
	if (vec == 3)
	{
		//���t���h�A����
		if (m_map[mapnum][hero_y - 1][hero_x] == 3 && itm->CheckItem(1))
		{
			itm->DeleteItem(1,false);
			itm->DeleteItem(2, true);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (m_map[mapnum][i][j] == 6)
					{
						m_map[mapnum][i][j] = 0;
					}
				}
			}
			m_map[mapnum][hero_y - 1][hero_x] = 99;
		}
		//������
		if (m_map[mapnum][hero_y - 1][hero_x] == 4)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(1);
		}
		//�i���o�[���b�N�h�A����
		if (m_map[mapnum][hero_y - 1][hero_x] == 5)
		{
			//�����Ă�ԓ����Ȃ��悤�ɂ���
			hero->SetActionflag(true);
			//�i���o�[���b�N�̌����ƃ��b�N�i���o�[
			hero->SetLockpiece(1,4);
			//�i���o�[���b�N�����Ă�t���O�𗧂Ă�
			hero->SetNumlock(true);
		}
		//�U������
		if (m_map[mapnum][hero_y - 1][hero_x] == 6)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(2);
		}
		//�I����
		if (m_map[mapnum][hero_y - 1][hero_x] == 37)
		{
			bool gby = false;
			itm->GetItem(3);
			for (int k = 0; gby == false; k++)
			{
				gby = true;
				if (m_map[mapnum][hero_y - 1][hero_x - k] == 37)
				{
					m_map[mapnum][hero_y - 1][hero_x - k] = 36;
					gby = false;
				}
				if (m_map[mapnum][hero_y - 1][hero_x + k] == 37)
				{
					m_map[mapnum][hero_y - 1][hero_x + k] = 36;
					gby = false;
				}
			}
		}
		//���ɔ���
		if (m_map[mapnum][hero_y - 1][hero_x] == 51 && itm->CheckItem(4))
		{
			m_map[mapnum][hero_y - 1][hero_x] = 52;
			itm->DeleteItem(4, false);
			//itm->GetItem(8);
		}
		//�I����
		if (m_map[mapnum][hero_y - 1][hero_x] == 38)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 36;
			itm->GetItem(4);
		}
		//�����I����
		if (m_map[mapnum][hero_y - 1][hero_x] == 39 && itm->CheckItem(3))
		{
			blockx = hero_x; blocky = hero_y - 1;
			itm->DeleteItem(3, false);
			moveshelf = 1.0f;
		}
		//���̏�̃���1����锻��
		if (m_map[mapnum][hero_y - 1][hero_x] == 40)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 32;
			itm->GetItem(5);
		}
		//�x�b�h�̏�̃���2����锻��
		if (m_map[mapnum][hero_y - 1][hero_x] == 41)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 33;
			itm->GetItem(6);
		}
		//�x�b�h�̏�̃���3����锻��
		if (m_map[mapnum][hero_y - 1][hero_x] == 42)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 33;
			itm->GetItem(7);
		}
		//�O�~�̉��̃���4����锻��
		if (m_map[mapnum][hero_y - 1][hero_x] == 46)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(8);
		}
		//�I�̃i���o�[���b�N����
		if (m_map[mapnum][hero_y - 1][hero_x] == 43)
		{
			//�����Ă�ԓ����Ȃ��悤�ɂ���
			hero->SetActionflag(true);
			//�i���o�[���b�N�̌���
			hero->SetLockpiece(2,4);
			//�i���o�[���b�N�����Ă�t���O�𗧂Ă�
			hero->SetNumlock(true);
			//�q���g�p�̉摜��\������
			lockpasu = 2;
		}
		//�I�̃i���o�[���b�N����
		if (m_map[mapnum][hero_y - 1][hero_x] == 44)
		{
			//�����Ă�ԓ����Ȃ��悤�ɂ���
			hero->SetActionflag(true);
			//�i���o�[���b�N�̌���
			hero->SetLockpiece(3, 3);
			//�i���o�[���b�N�����Ă�t���O�𗧂Ă�
			hero->SetNumlock(true);
			//�q���g�p�̉摜��\������
			lockpasu = 1;
		}
	}
	//��
	if (vec == 4)
	{
		if (m_map[mapnum][hero_y + 1][hero_x] == 3 && itm->CheckItem(1))
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
		}
		//������
		if (m_map[mapnum][hero_y + 1][hero_x] == 4)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(1);
		}
		//�U������
		if (m_map[mapnum][hero_y + 1][hero_x] == 6)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(2);
		}
		//���̏�̃�������锻��
		if (m_map[mapnum][hero_y + 1][hero_x] == 40)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 32;
			itm->GetItem(5);
		}
		//�x�b�h�̏�̃���2����锻��
		if (m_map[mapnum][hero_y + 1][hero_x] == 41)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 33;
			itm->GetItem(6);
		}
		//�x�b�h�̏�̃���3����锻��
		if (m_map[mapnum][hero_y + 1][hero_x] == 42)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 33;
			itm->GetItem(7);
		}
		//�O�~�̉��̃���4����锻��
		if (m_map[mapnum][hero_y + 1][hero_x] == 46)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(8);
		}
	}
}
//�}�b�v�؂�ւ��p�֐�
void CObjBlock::Mapchange(int mapn)
{
	//��l���̈ʒu��ݒ�
	CObjBackGround* bgro = (CObjBackGround*)Objs::GetObj(OBJ_BGROUND);
	//�}�b�v�ۑ�-------------------------------------------
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			block_data_map[mapnum][i][j] = m_map[mapnum][i][j];
		}
	}

	//���[�f�B���O-----------------------------------------
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			m_map[mapn][i][j] = block_data_map[mapn][i][j];
		}
	}

	//�w�i�؂�ւ�
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bgro->SetMapChip(mapnum, i, j, m_map[mapnum][i][j]);
		}
	}
}

//��l���̈ʒu���Z�b�g����
void CObjBlock::SetHero()
{

	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 2)
			{
				hero_x = j; hero_y = i;
				hero->SetPX(32.0f*j);
				hero->SetPY(32.0f*i);
				m_map[mapnum][i][j] = 0;
			}
		}
	}
}

//�i���̈ʒu���Z�b�g����
void CObjBlock::SetTowa()
{

	//�i���̈ʒu��ݒ�
	CObjTowa* towa = (CObjTowa*)Objs::GetObj(OBJ_TOWA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 9)
			{
				towa_x = j; towa_y = i;
				towa->SetPX(32.0f*j);
				towa->SetPY(32.0f*i);
			}
		}
	}
}

//�t���̈ʒu���Z�b�g����
void CObjBlock::SetKanata()
{

	//�t���̈ʒu��ݒ�
	CObjTowa* kanata = (CObjTowa*)Objs::GetObj(OBJ_KANATA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] ==10)
			{
				kanata_x = j; kanata_y = i;
				kanata->SetPX(32.0f*j);
				kanata->SetPY(32.0f*i);
			}
		}
	}
}


//�����̈ʒu���Z�b�g����
void CObjBlock::SetKirara()
{

	//�����̈ʒu��ݒ�
	CObjKirara* kirara = (CObjKirara*)Objs::GetObj(OBJ_KIRARA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 8)
			{
				kirara_x = j; kirara_y = i;
				kirara->SetPX(32.0f*j);
				kirara->SetPY(32.0f*i);
			}
		}
	}
}


//�i���o�[���b�N�h�A�J���邽�߂̊֐�
void CObjBlock::UnlockDoor(int vec, int num, int locknum)
{
	//�A�C�e���Q��
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	if (((UserData*)Save::GetData())->number[0] == num && locknum == 1)
	{
		m_map[mapnum][hero_y - 1][hero_x] = 0;
	}
	if (((UserData*)Save::GetData())->number[1] == num && locknum == 2)
	{
		itm->GetItem(3);
		m_map[mapnum][hero_y - 1][hero_x] = 31;
	}
	if (((UserData*)Save::GetData())->number[2] == num && locknum == 3)
	{
		//itm->GetItem(3);
		m_map[mapnum][hero_y - 1][hero_x] = 31;
	}

	//�摜������
	lockpasu = 0;
}
int CObjBlock::CheckBlockNumber(int vec, int x, int y)
{
	//����̒l��Ԃ�
	if (vec == 1)
	{
		return m_map[mapnum][y - 1][x - 1];
	}
	//��̒l��Ԃ�
	if (vec == 2)
	{
		return m_map[mapnum][y - 1][x];
	}
	//�E��̒l��Ԃ�
	if (vec == 3)
	{
		return m_map[mapnum][y - 1][x + 1];
	}
	//�E�̒l��Ԃ�
	if (vec == 4)
	{
		return m_map[mapnum][y][x + 1];
	}
	//�E���̒l��Ԃ�
	if (vec == 5)
	{
		return m_map[mapnum][y + 1][x + 1];
	}
	//���̒l��Ԃ�
	if (vec == 6)
	{
		return m_map[mapnum][y + 1][x];
	}
	//�����̒l��Ԃ�
	if (vec == 7)
	{
		return m_map[mapnum][y + 1][x - 1];
	}
	//���̒l��Ԃ�
	if (vec == 8)
	{
		return m_map[mapnum][y][x - 1];
	}
}