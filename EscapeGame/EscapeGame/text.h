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
extern int kirara_word;
extern int kanata_word;
extern int towa_word;
extern bool kirara_flag;
extern bool kanata_flag;
extern bool towa_flag;
extern bool gate_flag;
extern int kirara_num;
extern int kanata_num;
extern int towa_num;
extern bool kirara_anger;//������b�ύX�t���O
extern bool kanata_anger;//�t����b�ύX�t���O
extern bool towa_anger;//�i����b�ύX�t���O
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
	int end_time;//�G���f�B���O�X�N���[��
	int g;//�e�L�X�g���Q�s��1�s���̊m�F�p
	int d;//���ꂪ�b���Ă��邩�m�F�p
	int kirara_count;//�����̂���ׂ肩������
	int kanata_count;//�t���̂���ׂ肩������
	int towa_count;//�i���̂���ׂ肩������
	bool f;//�A�j���[�V�������e�L�X�g��i�߂Ȃ�����t���O
	bool ending;
};