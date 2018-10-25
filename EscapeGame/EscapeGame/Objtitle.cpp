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
	Font::StrDraw(L"館から脱出しながらイチャコラするゲームやん？", 40, 250, 32, c);

	Font::StrDraw(L"ゲーム始まるやん？: PushEnterKeyしたら", 100, 400, 32, c);
}