#pragma once
/*
���ݽṹͷ�ļ�
��������Ҫ�õ������ݽṹ
*/
#include "utils.h"

/*
�����հ������ݽṹ
*/
struct DATA_PROPERTY
{
	//�����
	int index;
	//������
	int type;

	int len;
	//���ݰ�
	std::shared_ptr<unsigned char> _ptr;
};

/*
AMF0��������
*/
typedef enum
{
	AMF0_NUMBER = 0,
	AMF0_BOOLEAN,
	AMF0_STRING,
	AMF0_OBJECT,
	AMF0_MOVIECLIP,      /* reserved, not used */
	AMF0_NULL,
	AMF0_UNDEFINED,
	AMF0_REFERENCE,
	AMF0_ECMA_ARRAY,
	Amf0_object_END,
	AMF0_STRICT_ARRAY,
	AMF0_DATE,
	AMF0_LONG_STRING,
	AMF0_UNSUPPORTED,
	AMF0_RECORDSET,       /* reserved, not used */
	AMF0_XML_DOC,
	AMF0_TYPED_OBJECT,
	AMF0_AVMPLUS,        /* switch to AMF3 */
	AMF0_INVALID = 0xff
} AMF0DataType;

/*
AMF3��������
*/
typedef enum
{
	AMF3_UNDEFINED = 0,
	AMF3_NULL,
	AMF3_FALSE,
	AMF3_TRUE,
	AMF3_INTEGER,
	AMF3_DOUBLE,
	AMF3_STRING,
	AMF3_XMLDOCUMENT,
	AMF3_DATE,
	AMF3_ARRAY,
	AMF3_OBJECT,
	AMF3_XML,
	AMF3_BYTEARRAY,
} AMF3DataType;

/*
AMF0/AMF3
*/
typedef enum
{
	TYPE_BASE = 0,
	TYPE_AMF0,
	TYPE_AMF3
}AMF_TYPE;

//����
struct POINT_PROPERTY
{
	float nfX;
	float nfY;
	float nfZ;
};



struct UI_PROPERTY
{
	//��ǰ���
	DWORD ndMoney;
	//ʣ�༼�ܵ�
	DWORD ndRestSkillPnt;
	//������
	DWORD ndKillMiniorNum;
	//������
	DWORD ndDeadNum;
	//ɱ����
	DWORD ndKillNum;
	//�����ָ�
	float  nfLifeRecovery;
	//�ͷ���Դ�ָ�
	float nfResourceRecovery;
	//���״�͸
	float nfArmorPenetration;
	//������͸
	float nfSpellPenetration;
	//����͵ȡ
	float nfLifeSteal;
	//������Ѫ
	float nfSpellVampire;
	//��������
	float AttackDistance;
	//����
	float nfToughness;
	//������
	float nfAggressivity;
	//����ǿ��
	float nfSpellPower;
	//����
	float nfArmor;
	//ħ��
	float nfMagicResistance;
	//�����ٶ�
	float nfAttackSpeed;
	//��ȴ����
	float nfCoolingReduction;
	//��������
	float nfCriticalStrikeChance;
	//�ƶ��ٶ�
	float nfMovingSpeed;
};


/*
�����������
*/
struct ROLE_PROPERTY
{
	//UI��ʾ����Ϣ
	UI_PROPERTY ui;
	//�������
	char* szpName;
	//�������
	POINT_PROPERTY pnt;
	//��ǰѪ��
	float nfCurHp;
	//���Ѫ��
	float nfMaxHp;
	//��ǰ����
	float nfCurMp;
	//�������
	float nfMaxMp;
	//��ҵȼ�
	DWORD ndLevel;
	//��ɱ��
	DWORD ndMutilKillNum;
	//345��ɱ
	DWORD ndKeepKillNum;
};

/*
��������
*/
struct MONSTER_PROPERTY
{
	//����
	char* szpName;
	//����
	POINT_PROPERTY pnt;
	//��ǰHP
	float nfCurHp;
	//���HP
	float nfMaxHp;
	//��������
	int type;
	//��Ӫ
	int camp;
};


/*
���ܶ���
*/
struct SKILL_PROPERTY
{
	//��������
	char* szpName;
	//��ȴʱ��
	//?????
	//����ID
	DWORD ndId1;
	DWORD ndId2;

};