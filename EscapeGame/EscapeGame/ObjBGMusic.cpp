//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBGMusic.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBGMusic::Init()
{
	for (int i = 0; i < 10; i++)
	{
		PlayingSound[i] = false;
	}
	NowBGM = 0;

	Audio::Start(NowBGM);
}

//�A�N�V����
void CObjBGMusic::Action()
{
	for (int i = 0; i < 10; i++)
	{
		if (PlayingSound[i] == true && NowBGM != i && NowBGM != 99)
		{
			PlayingSound[NowBGM] = false;
			Audio::Stop(NowBGM);
			NowBGM = i;
			Audio::Start(i);
		}
		else if(NowBGM == 99)
		{
			for (int j = 0; j < 10; j++)
				PlayingSound[j] = false;
		}
	}
}

//�h���[
void CObjBGMusic::Draw()
{

}

//BGM�ύX�p�֐�
void CObjBGMusic::ChangeBGM(int bgmnum)
{
	if (bgmnum != 99)
	{
		PlayingSound[bgmnum] = true;
		if (NowBGM == 99)
			NowBGM = 0;
	}
	else
	{
		Audio::Stop(NowBGM);
		NowBGM = 99;
	}
}