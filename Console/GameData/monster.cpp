#include "monster.h"
#include "baseaddr.h"
#include "StringCovert.h"

monster g_monster;

monster::monster()
{
}


monster::~monster()
{
}

bool monster::init()
{

	m_monster.clear();
	try
	{
		DWORD  startAddr = *(DWORD*)(Base_MonsterAddr);
		DWORD endAddr = *(DWORD*)(Base_MonsterAddr + 0x4);
		for (int i = startAddr; i < endAddr; i+= 0x4)
		{
			DWORD ndObj = *(DWORD*)(i);
			if (ndObj == 0)
			{
				continue;
			}
			MONSTER_PROPERTY temp;
			if (*(DWORD*)(ndObj + 0x30) < 0xf)
			{
				temp.szpName = (char*)(ndObj + 0x20);
			}
			else
			{
				temp.szpName = (char*)(*(DWORD*)(ndObj + 0x20));
			}
			temp.camp = *(DWORD*)(ndObj + 0x14);
			temp.type = *(DWORD*)(ndObj + 0x18);
			temp.pnt.nfX = *(float*)(ndObj + 0x50);
			temp.pnt.nfZ = *(float*)(ndObj + 0x54);
			temp.pnt.nfY = *(float*)(ndObj + 0x58);
			temp.nfCurHp = *(float*)(ndObj + 0x2fc);
			temp.nfMaxHp = *(float*)(ndObj + 0x30c);
			m_monster.push_back(temp);
			tools::getInstance()->message("���ֳ��ȣ�%d", *(DWORD*)(ndObj + 0x30));
			tools::getInstance()->message("��ַ�� %x , ���֣�%s, ��Ӫ��%d  ,�������ͣ�%d,����(%f, %f , %f) ��ǰѪ����%f", i, Utf8ToAnsi(temp.szpName).c_str(), temp.camp ,temp.type,temp.pnt.nfX , temp.pnt.nfY , temp.pnt.nfZ, temp.nfCurHp);
		}
		tools::getInstance()->message("һ��%d���������\n", m_monster.size());
	}
	catch (...)
	{
		setError("��ʼ����������ʧ�ܣ�\n");
		return false;
	}
	return true;
}
