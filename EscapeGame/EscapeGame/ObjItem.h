#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjItem : public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	bool CheckItem(int item);
	void DeleteItem(int item, bool all);
	void GetItem(int item);
	void SetShowItem(int item) { ShowItem = item; show = true; }
	void SetShow(bool which) { show = which; }
private:
	int ShowItem;
	bool show;
};