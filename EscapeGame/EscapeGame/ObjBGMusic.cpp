//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjBGMusic.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBGMusic::Init()
{
	for (int i = 0; i < 10; i++)
	{
		PlayingSound[i] = false;
	}
	NowBGM = 0;

	Audio::Start(NowBGM);
}

//アクション
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

//ドロー
void CObjBGMusic::Draw()
{

}

//BGM変更用関数
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