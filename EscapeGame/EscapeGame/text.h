#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern bool text_move;
extern int word;
extern int anime_move;
extern bool hero_move;
extern bool text_hide;
extern bool skip_anime;//�A�j���[�V�������e�L�X�g��i�߂Ȃ�����t���O
extern int item_word;//���𒲂ׂ����̕���
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
	bool anime_flag;
	int time;//�e�L�X�g�\���㕔�Ǘ�����
	int time_x;//�e�L�X�g�\�������Ǘ�����
	int g;//�e�L�X�g���Q�s��1�s���̊m�F�p
	int d;//���ꂪ�b���Ă��邩�m�F�p
	bool f;//�A�j���[�V�������e�L�X�g��i�߂Ȃ�����t���O
};