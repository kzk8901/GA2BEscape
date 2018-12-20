//Žg—p‚·‚éƒwƒbƒ_[ƒtƒ@ƒCƒ‹
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
//Žg—p‚·‚éƒl[ƒ€ƒXƒy[ƒX
using namespace GameL;

bool text_move=true;
int word=7;
//ƒCƒjƒVƒƒƒ‰ƒCƒY
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 220;
	time_x = -1;
	g = 0;
}
//ƒAƒNƒVƒ‡ƒ“
void CObjText::Action()
{
	time += 1;
	time_x -= 1;
	//ƒI[ƒvƒjƒ“ƒO@-1
	//‚«‚ç‚ç@-3 0 3
	//‘t‘½ -4 1 4
	//‰i‰“ -5 2 5
    //–‹ŠÔ 6 7
	if (Input::GetVKey('Z') == true)
		{
			if (m_key_flag == true)
			{
				if (skip_flag == false)
				{
					if (text_loop == true)
					{
						if (time > 220)
						{
							if (text_m == 0 && word < 10 || text_m == 3 && word < 22 || 
								text_m == 1 && word < 13 || text_m == 2 && word < 9  || text_m == -1 && word < 54||
								text_m == 5 && word < 19 || text_m == 4 && word < 18 || text_m ==  7 && word < 15||
								text_m == 6 && word < 6)
							{
								word += 1;
								m_key_flag = false;
								time = 0;
								skip_flag = true;
							}
						}
					}
				}
				else if(time<200)
				{
					time = 200;
				}
				else if (time > 220 && time_x < 200&&time_x>0)
				{
					time_x = 0;
				}
				else if(time>220&&time_x<-20)
				{
					skip_flag = false;
				  
				}


			}
		}
	else
	{
		m_key_flag = true;
	}
}
//ƒhƒ[
void CObjText::Draw()
{
	//•`‰æƒJƒ‰[î•ñ
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //•`‰æŒ³Ø‚èŽæ‚èˆÊ’u
	RECT_F dst; //•`‰æ•\Ž¦ˆÊ’u
	RECT_F src_B;//ƒeƒLƒXƒg•\Ž¦‰B‚µ(ã•”j•`‰æŒ³Ø‚èŽæ‚èˆÊ’u
	RECT_F dst_B;//ƒeƒLƒXƒg•\Ž¦‰B‚µ(ã•”j•`‰æ•\Ž¦ˆÊ’u
	RECT_F src_C;//ƒeƒLƒXƒg•\Ž¦‰B‚µ(‰º•”j•`‰æŒ³Ø‚èŽæ‚èˆÊ’u
	RECT_F dst_C;//ƒeƒLƒXƒg•\Ž¦‰B‚µ(‰º•”j•`‰æ•\Ž¦ˆÊ’u
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 465.0f;
	src.m_bottom = 463.0f;
	dst.m_top = 490.0f;
	dst.m_left = 10.0f;
	dst.m_right = 106.0f;
	dst.m_bottom = 590.0f;
	if (text_m == -2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"ŒºŠÖ", 685, 532, 32, c);
	}
	//ƒI[ƒvƒjƒ“ƒO
	else if (text_m == -1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"ŒºŠÖ", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Font::StrDraw(L"‘å¯‚«‚ç‚ç‚ÍƒƒCƒh‚ÌŠÝ–ì‘t‘½‚Æ",108, 510, 30, c);
			Font::StrDraw(L"‰ºZ‚µ‚Ä‚¢‚é‚Æ“Ë‘R‰J‚ª~‚Á‚Ä‚«‚½", 108, 540, 30, c);
		}
		else if (word == 2)
		{
			Font::StrDraw(L"“ñl‚Í‚½‚Ü‚½‚Ü‹ß‚­‚É‚ ‚Á‚½ŠÙ‚Å", 108, 510, 30, c);
			Font::StrDraw(L"‰Jh‚è‚·‚é‚±‚Æ‚É‚µ‚½‚Ì‚Å‚ ‚Á‚½", 108, 540, 30, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚Ë‚¦‘t‘½c‰J‚¢‚Â‚â‚Þ‚©‚ÈH", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚±‚ÌŠ´‚¶‚¾‚Æ‚·‚®‚â‚Þ‚ÆŽv‚¢‚Ü‚·‚ª", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:‚±‚±‚È‚ç‰Jh‚è‚Å‚«‚»‚¤‚¾‚Èc", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:’N!?", 108, 490, 25, c);
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:æ‹q‚ª‚¢‚½‚Ì‚©", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:‰´‚Ì–¼‘O‚Í–PˆêŽ÷B", 108, 490, 25, c);
			Font::StrDraw(L"ŒN‚Æ“¯‚¶ŠwZ‚Ì“ñ”N‚¾", 108, 515, 25, c);
		}
		else if (word == 9)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚ AƒZƒ“ƒpƒC‚Å‚·‚©H", 108, 490, 25, c);
		}
		else if (word == 10)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:Ž„‚Í‘å¯‚«‚ç‚ç‚æ", 108, 490, 25, c);
		}
		else if (word == 11)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‰^ˆ«‚­’Ê‚è‰J‚É~‚ç‚ê", 108, 490, 25, c);
			Font::StrDraw(L"‹}ç¯‰Jh‚è‚µ‚Ä‚é‚Ì", 108, 515, 25, c);
		}
		else if (word == 12)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚¨ŒÝ‚¢Ð“ï‚¾‚È", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚±‚Á‚¿‚ÍŽ„‚ÌƒƒCƒh‚ÌŠÝ–ì‘t‘½‚æ", 108, 490, 25, c);
		}
		else if (word== 14)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:ŠÝ–ì‘t‘½‚Å‚·B", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚«‚ç‚ç—l‚ÌƒƒCƒh‚Å‚·", 108, 490, 25, c);
		}
		else if (word== 16)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:l‚ª‚¢‚Á‚Ï‚¢‚¢‚é‚æ", 108, 490, 25, c);
		}
		else if (word == 17)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:Šm‚©‚ ‚È‚½‚Íc", 108, 490, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:¶“k‰ï’·‚Ì–kã‰i‰“‚³‚ñ‚Å‚·‚Ë", 108, 490, 25, c);
		}
		else if (word == 19)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚¤‚¾‚æ", 108, 490, 25, c);
		}
		else if (word == 20)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:ŒN‚Í‘å‹´‚³‚ñ‰Æ‚ÌƒƒCƒh‚³‚ñ‚¾‚Ë", 108, 490, 25, c);
		}
		else if (word == 21)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:ŠÝ–ì‘t‘½‚Å‚·", 108, 490, 25, c);
		}
		else if (word == 22)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
	        Font::StrDraw(L"–P:‚ A‰J‚â‚ÝŽn‚ß‚Ä‚Ü‚·‚Ë",  108, 490, 25, c);
		}
		else if (word == 23)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‘t‘½!‚Æ‚Á‚Æ‚Æ‹A‚é‚í‚æI",  108, 490, 25, c);
		}
		else if (word == 24)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚©‚µ‚±‚Ü‚è‚Ü‚µ‚½B", 108, 490, 25, c);
			Font::StrDraw(L"‚»‚ê‚Å‚ÍŽ¸—ç‚µ‚Ü‚·", 108, 515, 25, c);
		}
		else if (word == 25)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‰´‚à‹A‚ë‚¤", 108, 490, 25, c);
		}
		else if (word == 26)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:–l‚à‹A‚ç‚È‚«‚á", 108, 490, 25, c);
		}
		else if (word == 27)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚ñH", 108, 490, 25, c);
		}
		else if (word == 28)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:ƒhƒA‚ªŠJ‚©‚È‚¢‚¼", 108, 490, 25, c);
		}
		else if (word == 29)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚»‚ñ‚È‚í‚¯‚È‚¢‚Å‚µ‚å", 108, 490, 25, c);
		}
		else if (word == 30)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:Ž¸—ç‚µ‚Ü‚·", 108, 490, 25, c);
		}
		else if (word == 31)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:ŠJ‚«‚Ü‚¹‚ñ‚Ë", 108, 490, 25, c);
		}
		else if (word == 32)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:–{“–‚©‚¢H", 108, 490, 25, c);
		}
		else if (word == 33)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
		    Font::StrDraw(L"–P:‚³‚ÄA‚Ç‚¤‚µ‚½‚à‚Ì‚©", 108, 490, 25, c);
		}
		else if (word == 34)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚±‚Á‚¿‚ÌƒhƒA‚ÍŠJ‚­‚í‚æ", 108, 490, 25, c);
		}
		else if (word == 35)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚È‚ç‚»‚Á‚¿‚ð’Tõ‚·‚é‚©H", 108, 490, 25, c);
		}
		else if (word == 36)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚ ‚Ü‚è‚¨Š©‚ß‚Í‚µ‚Ü‚¹‚ñ‚Ë", 108, 490, 25, c);
		}
		else if (word== 37)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:ŽžŠÔ‚ª‚½‚Ä‚Î‰ä‚ª‰Æ‚Ì‹~•ƒ`[ƒ€‚ª", 108, 490, 25, c);
			Font::StrDraw(L"‹ì‚¯•t‚¯‚Ü‚·‚Ì‚Å‚µ‚Î‚µ‚¨‘Ò‚¿‚­‚¾‚³‚¢", 108, 515, 25, c);
		}
		else if (word == 38)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚Å‚àA‚±‚ñ‚È‹@‰ï–Å‘½‚É‚È‚¢‚µ", 108, 490, 25, c);
			Font::StrDraw(L"–l‚Í’Tõ‚ÉŽ^¬‚©‚È", 108, 515, 25, c);
		}
		else if (word == 39)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:Ž„‚à’Tõ‚µ‚½‚¢‚í", 108, 490, 25, c);
		}
		else if (word == 40)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‘t‘½A‹~•ƒ`[ƒ€‚ÌŽè”z‚Í‘Ò‚¿‚È‚³‚¢", 108, 490, 25, c);
		}
		else if (word ==41)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚µ‚©‚µc", 108, 490, 25, c);
		}
		else if (word == 42)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‘t‘½I", 108, 490, 25, c);
		}
		else if (word == 43)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚©‚µ‚±‚Ü‚è‚Ü‚µ‚½", 108, 490, 25, c);
		}
		else if (word == 44)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚Å‚µ‚½‚çŽ„‚ª", 108, 490, 25, c);
			Font::StrDraw(L"‚Ü‚¸‘S•”‰®‚ÌˆÀ‘S‚ðŠm‚©‚ß‚Ü‚·", 108, 515, 25, c);
		}
		else if (word == 45)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚»‚ÌŒãŠF‚³‚ñ‚É", 108, 490, 25, c);
			Font::StrDraw(L"’Tõ‚µ‚Ä‚à‚ç‚¤‚Æ‚¢‚¤‚±‚Æ‚Åc", 108, 515, 25, c);
		}
		else if (word == 46)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚»‚ñ‚È‚±‚Æ‚µ‚½‚ç", 108, 490, 25, c);
			Font::StrDraw(L"â‘Î‹–‚³‚È‚¢‚©‚ç‚ËH", 108, 515, 25, c);
		}
		else if (word== 47)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚Å‚µ‚½‚ç³–Ê‚Ì•”‰®‚Ì", 108, 490, 25, c);
			Font::StrDraw(L"’Tõ‚È‚ç‚æ‚ë‚µ‚¢‚Å‚µ‚å‚¤H", 108, 515, 25, c);
		}
		else if (word == 48)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚»‚ê‚È‚ç‚¢‚¢‚í", 108, 490, 25, c);
		}
		else if (word == 49)
		{
			g = 1;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚ê‚¶‚á‚ –l‚Í", 108, 490, 25, c);
			Font::StrDraw(L"‚ ‚Á‚¿‚Ì•”‰®‚ð’Tõ‚·‚é‚æ", 108, 515, 25, c);
		}
		else if (word == 50)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚¨Šè‚¢‚µ‚Ü‚·‚Ëæ”y", 108, 490, 25, c);
		}
		else if (word == 51)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:“ä‚ÌŠÙ‚Ì’Tõ‚ÌŠJŽn‚¾[I", 108, 490, 25, c);
		}
		else if (word == 52)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚¨[I", 108, 490, 25, c);
		}
		else if (word == 53)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚¨A‚¨[c", 108, 490, 25, c);
		}
		else if (word == 54)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"•”‰®‚ð‚¦‚ç‚ñ‚Å’Tõ‚µ‚æ‚¤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//‚«‚ç‚çƒ}ƒbƒv
	//i“üŽž@word=0`10
	//‰ðœŒãŽž@word=10`21
	if (text_m == -3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"‹ŠÔ", 685, 532, 32, c);
	}
	//‚«‚ç‚çƒ}ƒbƒvi“üŽž‰ï˜b-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"‹ŠÔ", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚ A–PŒNI", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‘å¯H‚Ç‚¤‚µ‚½‚ñ‚¾‚±‚ñ‚ÈŠ‚Å", 108, 490, 25, c);
		}
		else if (word == 3)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚±‚Ì•”‰®‚¢‚ë‚¢‚ë’²‚×‚Ä‚ñ‚Ì‚æ", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚»‚¤‚©c‰½‚©¬‰Ê‚Í‚ ‚Á‚½‚©H", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‰½‚àŒ©‚Â‚©‚ç‚È‚©‚Á‚½‚íc", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‹C‚É‚·‚é‚È", 108, 490, 25, c);
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‰´‚àˆê‚É’T‚·‚©‚ç", 108, 490,25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚ ‚è‚ª‚Æ‚¤", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚»‚ê‚¶‚á‚ ‚Æ‚Á‚Æ‚Æ", 108, 490, 25, c);
			Font::StrDraw(L"ŽèŠ|‚©‚èŒ©‚Â‚¯‚é‚í‚æI", 108, 515, 25, c);
		}
		else if (word == 10)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"’Tõ‚µ‚æ‚¤I", 50, 490, 32, c);
		}
	}
	//‚«‚ç‚ç“š‚¦“ü—ÍŒã-----------------------------------------------------------------------
	else if(text_m==3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"‹ŠÔ", 685, 532, 32, c);
		if (word == 10)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		if (word== 11)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‘å¯Iƒƒ‚Œ©‚Â‚¯‚½‚¼", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚Ù‚ñ‚ÆH", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:Œ‹‹ÇŽ„‰½‚à", 108, 490, 25, c);
			Font::StrDraw(L"Œ©‚Â‚¯‚ç‚ê‚È‚©‚Á‚½‚í", 108, 515, 25, c);
		}
		else if (word == 14)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚ ‚ñ‚Ü‚è‹C‚É‚·‚é‚È‚æH", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:S”z‚È‚¢‚í", 108, 490, 25, c);
		}
		else if (word == 16)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:¡“x‚±‚»‰½‚©Œ©‚Â‚¯‚Ä‚ ‚°‚é", 108, 490, 25, c);
			Font::StrDraw(L"Œ©‚Â‚¯‚Ä‚ ‚°‚é", 108, 515, 25, c);
		}
		else if (word == 17)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:Šæ’£‚é‚Ì‚Í‚¢‚¢‚¯‚Ç–³’ƒ‚·‚é‚È‚æH", 108, 490, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‰´‚Íˆá‚¤•”‰®‚ð’Tõ‚µ‚Ä‚­‚é‚æ", 108, 490, 25, c);
		}
		else if (word == 19)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:Ž„‚Í‚à‚¤­‚µ‚±‚±‚ð’Tõ‚µ‚Ä‚é‚í", 108, 490, 25, c);
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ŽålŒö:‚¢‚¢‚¯‚Ç‹C‚ð‚Â‚¯‚ë‚æ", 108, 490, 25, c);
		}
		else if (word == 21)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚»‚Á‚¿‚±‚»‹C‚ð‚Â‚¯‚È‚³‚¢‚æ", 108, 490, 25, c);
		}
		else if (word == 22)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"‘¼‚Ì•”‰®‚ð’T‚µ‚És‚±‚¤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//‘t‘½ƒ}ƒbƒv
	//i“üŽž@word=0`13
	//Œ®Žæ“¾Žž@word=13`18
	else if (text_m == -4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"}‘Žº", 670, 532, 32, c);
	}
	//‘t‘½ƒ}ƒbƒvi“üŽž-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"}‘Žº", 670, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		if (word == 1)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚â‚¯‚É•Ð•t‚¢‚½•”‰®‚¾‚È", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚ A–P‚³‚ñB", 108, 490, 25, c);
			Font::StrDraw(L"‚Ç‚¤‚©‚¢‚½‚µ‚Ü‚µ‚½‚©H", 108, 515, 25, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:ŠÝ–ì‚³‚ñ‚¢‚½‚ñ‚Å‚·‚©", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚»‚¤‚©‚µ‚±‚Ü‚ç‚È‚­‚Ä‚à‘åä•v‚Å‚·‚æB", 108, 490, 25, c);
			Font::StrDraw(L"“¯‚¢”N‚Å‚·‚©‚ç", 108, 515, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚í‚©‚Á‚½B‚ÅAŠÝ–ì‚³‚ñ‚Í‚Ç‚¤‚µ‚Ä", 108, 490, 25, c);
			Font::StrDraw(L"‚Í‚½‚«‚ðŽ‚Á‚Ä‚¢‚é‚ñ‚¾H", 108, 515, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:E‹Æã‰˜‚¢•”‰®‚ðŒ©‚é‚Æ•Ð•t‚¯‚½‚­‚È‚é‚ñ‚Å‚·", 108, 490, 25, c);
			Font::StrDraw(L"•Ð•t‚¯‚½‚­‚È‚é‚ñ‚Å‚·", 108, 515, 25, c);
		}
		else if (word == 7)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚»‚Á‚©‚¶‚á‚ Žè“`‚¤‚æ", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚¦H‚¢‚¢‚ñ‚Å‚·‚©H", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:•”‰®‚Ì•Ð‚Ã‚¯‚µ‚È‚ª‚ç’T‚¹‚Î‚¢‚¢‚æ", 108, 490, 25, c);
		}
		else if (word == 10)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:\‚µ–ó‚ ‚è‚Ü‚¹‚ñBŽè‘‚­I‚í‚ç‚¹‚Ü‚·‚Ì‚Å", 108, 490, 25, c);
			Font::StrDraw(L"Žè‘‚­I‚í‚ç‚¹‚Ü‚·‚Ì‚Å", 108, 515, 25, c);
		}
		else if (word == 11)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚»‚ê‚¶‚á‚ Žn‚ß‚æ‚¤‚©", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚Í‚¢I", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"’Tõ‚µ‚æ‚¤I", 50, 490, 32, c);
		}
	}
    //Œ®“üŽèŒã-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"}‘Žº", 670, 532, 32, c);
		if (word == 13)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		else if (word == 14)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‰½‚©‚Ìƒƒ‚‚¾‚È", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚È‚ñ‚Å‚µ‚å‚¤‚Ë", 108, 490, 25, c);
		}
		else if (word == 16)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚Æ‚è‚ ‚¦‚¸‘¼‚Ì•”‰®‚à", 108, 490, 25, c);
			Font::StrDraw(L"Œ©‰ñ‚Á‚Ä—ˆ‚é‚æ", 108, 515, 25, c);
		}
		else if (word == 17)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚í‚©‚è‚Ü‚µ‚½B", 108, 490, 25, c);
			Font::StrDraw(L"‚¨ì—l‚ð‚æ‚ë‚µ‚­‚¨Šè‚¢‚µ‚Ü‚·", 108, 515, 25, c);
		}
		else if (word == 18)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"‘¼‚Ì•”‰®‚ð’T‚µ‚És‚±‚¤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//‰i‰“ƒ}ƒbƒv-----------------------------------------------------------------------
	//i“üŽž@word=0`9
	//ƒƒ‚Žæ“¾Žž@word=9`19
	else if (text_m == -5)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"˜aŽº", 685, 532, 32, c);
	}
	//‰i‰“ƒ}ƒbƒvi“üŽž-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"˜aŽº", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:–PŒNA‚Ç‚¤‚©‚µ‚½‚Ì‚©‚ÈH", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:–kãæ”y‚Å‚·‚©B", 108, 490, 25, c);
			Font::StrDraw(L"–P:‚±‚Ì•”‰®‚É‰½‚©‚ ‚è‚Ü‚µ‚½H", 108, 515, 25, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚Ü‚¾‰½‚É‚àŒ©‚Â‚©‚Á‚Ä‚È‚¢‚ñ‚¾", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚¤‚¾I", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:’T‚·‚Ìˆê‚ÉŽè“`‚Á‚Ä‚æ", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚í‚©‚è‚Ü‚µ‚½B", 108, 490, 25, c);
			Font::StrDraw(L"‰´‚Å‚æ‚¯‚ê‚ÎŽè“`‚¢‚Ü‚·‚æ", 108, 515, 25, c);
		}
		else if (word == 7)
		{
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚ ‚è‚ª‚Æ‚¤B", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚ê‚¶‚á‚æ‚ë‚µ‚­I", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"’Tõ‚µ‚æ‚¤I", 50, 490, 32, c);
		}
	}
	//‰i‰“ƒ}ƒbƒv‰ðœŽž-------------------------------------------------------------------------
	else if (text_m == 5)
		{
			Font::StrDraw(L"1F", 700, 500, 32, c);
			Font::StrDraw(L"˜aŽº", 685, 532, 32, c);
			if (word == 9)
			{
				text_move = true;
				Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
			}
			else if (word == 10)
			{
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"‰i‰“:‚±‚ê‚Í‰½‚©‚Ìƒƒ‚‚©‚È?", 108, 490, 25, c);
			}
			else if (word == 11)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"–P:‚Ý‚½‚¢‚Å‚·‚Ë", 108, 490, 25, c);
			}
			else if (word == 12)
			{
				g = 1;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"‰i‰“:‚à‚µ‚©‚µ‚½‚ç‘¼‚É‚à", 108, 490, 25, c);
				Font::StrDraw(L"‰½‚©‚ ‚é‚©‚à‚µ‚ê‚È‚¢‚Ë", 108, 515, 25, c);
			}
			else if (word == 13)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"–P:‚Å‚·‚ËB", 108, 490, 25, c);
				Font::StrDraw(L"‚à‚Á‚Æ‚±‚Ì•”‰®’²‚×‚Ä‚Ý‚Ü‚µ‚å‚¤‚©", 108, 515, 25, c);
			}
			else if (word == 14)
			{
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"‰i‰“:–PŒN‚Í‘¼‚Ì•”‰®‚ð’²‚×‚És‚Á‚Ä‚Ý‚Ä‚æ", 108, 490, 25, c);
			}
			else if (word == 15)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"–P:‘åä•v‚Å‚·‚©H", 108, 490, 25, c);
			}
			else if (word == 16)
			{
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"‰i‰“:–l‚Í¶“k‰ï’·‚È‚ñ‚¾‚æ?‘åä•v‚¾‚æ", 108, 490, 25, c);
			}
			else if (word == 17)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"–P:‚í‚©‚è‚Ü‚µ‚½Bæ”y‚à‹C‚ð•t‚¯‚Ä", 108, 490, 25, c);
			}
			else if (word == 18)
			{
				Draw::Draw(52, &src, &dst, c, 0.0f);
			    Font::StrDraw(L"‰i‰“:”C‚¹‚Ä", 108, 490, 25, c);
			}
			else if (word == 19)
			{
				g = 3;
				text_move = false;
				Font::StrDraw(L"‘¼‚Ì•”‰®‚ð’T‚µ‚És‚±‚¤", 50, 490, 32, c);
				text_loop = false;
			}
		}
	//–‹ŠÔ
	//‚PŠK‘w1`6
	//‚QŠK‘w6`15
	//‚PŠK‘w-----------------------------------------------------------------------
	else if (text_m == 6)
	{
		text_move = true;
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"ŒºŠÖ", 685, 532, 32, c);
		if (word == 0)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:3‚Â‚Ìƒƒ‚‚ª‚»‚ë‚Á‚½‚Ý‚½‚¢‚¾‚È", 108, 490, 25, c);
		}
		else if (word == 1)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚â‚Á‚½‚í‚Ë", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚»‚ê‚Åƒƒ‚‚É‚Í", 108, 490, 25, c);
			Font::StrDraw(L"‚È‚ñ‚Ä‘‚¢‚Ä‚¢‚é‚ñ‚Å‚·‚©?", 108, 515, 25, c);
		}
		else if (word== 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:uƒ~ƒXƒ~ƒ\ƒEv", 108, 490, 25, c);
			Font::StrDraw(L"uƒCƒtƒFƒCƒIƒ“v", 108, 515, 25, c);
			Font::StrDraw(L"uƒTƒNƒ‰ƒ\ƒEv‚¾‚È", 108, 540, 25, c);
		}
		else if (word == 4)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:ƒCƒtƒFƒCƒIƒ“H", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚È‚É‚æ‚»‚ê", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"’Tõ‚µ‚æ‚¤I", 50, 490, 32, c);
		}
	}
	//‚QŠK‘w-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 700, 500, 32, c);
		if (word == 6)
		{
			text_move = true;
			Font::StrDraw(L"ZƒL[‚Å‰ï˜bis", 50, 490, 32, c);
		}
		else if (word == 7)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:“ñŠK‚É—ˆ‚½‚Ì‚Í‚¢‚¢‚¯‚Ç", 108, 490, 25, c);
			Font::StrDraw(L"‚±‚ê‚¶‚áo‚ç‚ê‚È‚¢‚í‚æH", 108, 490, 25, c);
		}
		if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:‚±‚ÌŠK‚É‰½‚©ŽèŠ|‚©‚è‚ª‚ ‚é‚ñ‚¶‚á‚È‚¢‚©‚È", 108, 490, 25, c);
			Font::StrDraw(L"‚ ‚é‚ñ‚¶‚á‚È‚¢‚©‚È", 108, 515, 25, c);
		}
		else if (word == 9)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚ê‚¶‚á‚±‚Ì•”‰®‚à", 108, 490, 25, c);
			Font::StrDraw(L"‰i‰“:•ª‚©‚ê‚Ä’T‚·Š´‚¶‚Å‚¢‚¢‚©‚ÈH", 108, 515, 25, c);
		}
		else if (word == 10)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‚È‚çŽ„‚Í‚±‚Á‚¿‚És‚­‚íI", 108, 490, 25, c);
		}
		else if (word == 11)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‚«‚ç‚ç:‘t‘½‚Í‚ ‚Á‚¿‚ð’²‚×‚È‚³‚¢I", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‘t‘½:‚©‚µ‚±‚Ü‚è‚Ü‚µ‚½", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"‰i‰“:‚»‚ê‚¶‚á‚ –l‚ÍŽc‚è‚Ì•”‰®‚ð’²‚×‚æ‚¤‚©‚È", 108, 490, 25, c);
		}
		if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"–P:i‰´‚Í’N‚©‚ðŽè“`‚¢‚És‚±‚¤j", 108, 490, 25, c);
		}
		if (word == 15)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"•”‰®‚ð‚¦‚ç‚ñ‚Å’Tõ‚µ‚æ‚¤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//ƒeƒLƒXƒgˆÚ“®
	if (time < 200&&g==0)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 60.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom =540.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//ƒeƒLƒXƒg•\Ž¦‰B‚µ(‰º•”j•`‰æ•\Ž¦ˆÊ’u
		src_C.m_top = 60.0f;
		src_C.m_left = 110.0f ;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 110.0f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(time==200 && g == 0)
	{
		time_x = 200;
	}
	if (time_x <= 200&&time_x>=0 && g == 0)
	{
		src_C.m_top = 60.0f;
		src_C.m_left = 110.0f + (200-time_x)*1.655f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 110.0f + (200 - time_x)*2.2f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(g == 0)
	{

	}
	//ƒeƒLƒXƒgˆÚ“®
	if (time < 200 && g == 1)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 35.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom = 515.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//ƒeƒLƒXƒg•\Ž¦‰B‚µ(‰º•”j•`‰æ•\Ž¦ˆÊ’u
		src_C.m_top = 35.0f;
		src_C.m_left = 110.0f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 515.0f;
		dst_C.m_left = 110.0f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (time == 200 && g == 1)
	{
		time_x = 200;
	}
	if (time_x <= 200 && time_x >= 0 && g == 1)
	{
		src_C.m_top = 35.0f;
		src_C.m_left = 110.0f + (200 - time_x)*1.655f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 515.0f;
		dst_C.m_left = 110.0f + (200 - time_x)*2.2f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (g == 1)
	{

	}
	//ƒeƒLƒXƒgˆÚ“®
	if (time < 200 && g == 2)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 120.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom = 600.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
	}
	else if (g == 2)
	{

	}

}