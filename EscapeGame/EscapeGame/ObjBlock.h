#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	bool ThereIsBlock(int vec);
	void HeroAction(int vec);
	void UnlockDoor(int vec, int num);
private:
	int m_map[15][20];//�}�b�v���
	int hero_x; //��l���ʒu�iX�j
	int hero_y; //��l���ʒu�iY�j

};