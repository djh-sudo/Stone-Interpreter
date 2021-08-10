#pragma once

#include <string>
#include <memory>
/*	Token [Base]
	-> IdToken
	-> NumberToken
	-> StrToken
*/
class Token {
public:
	// ��������ָ��
	typedef std::shared_ptr<Token>ptr;
	typedef std::shared_ptr<const Token>cptr;
	// ���������
	static const Token::cptr END_OF_FILE;// Դ�ļ��������
	static const std::string END_OF_LINE;// һ�еĽ�β

public :
	// Ĭ�Ϲ��캯�� ��������ʽת��
	explicit Token() = default;
	explicit Token(int line);
	virtual ~Token() = default;

private:
	// �к�
	int lineNumber;
public:
	int getLineNumber() const;			//��ȡ�к�
	virtual bool isIdentifier()const;	//�ж��Ƿ�Ϊ��ʶ��
	virtual bool isNumber()const;		//�ж��Ƿ�Ϊ����
	virtual bool isString()const;		//�ж��Ƿ�Ϊ�ַ���
	virtual int getNumber()const;		//��ȡ����
	virtual std::string getText()const;	//���ַ�����ʽ��ȡToken
};
