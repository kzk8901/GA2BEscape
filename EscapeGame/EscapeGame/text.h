#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern bool text_move;
extern int word;
//�I�u�W�F�N�g:�^�C�g��
class CObjText :public CObj
{
public:
	CObjText() {};
	~CObjText() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//�L�[�t���O
	bool skip_flag;//�X�L�b�v�t���O
	int time;
	int x, y;
};