#pragma once
/*
�����Ϊ���еĶ�����Ļ���
*/
#include "utils.h"

class base
{
public:
	 base();
	 virtual~base();
	 void setError(std::string _str);
	 std::string error();
	 virtual bool init() = 0;
private:
	std::string m_errorString;
};

