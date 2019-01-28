//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	//エンターキーをおしてシーン:ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"放課後の災難", 150, 200, 80, c);

	Font::StrDraw(L"GameStart: PushEnterKey", 210, 400, 32, c);
}