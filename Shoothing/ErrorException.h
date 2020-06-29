#ifndef _ERROREXCEPTION_H_
#define _ERROREXCEPTION_H_

#include<exception>
#include<string>

//��O�X���[�p�N���X
class ErrorException:public std::exception
{
public:
	//�R���X�g���N�^
	ErrorException(int line, const char* file)noexcept;
	//�G���[���̎擾
	const char* what()const noexcept override;
	//�G���[�^�C�v�̎擾
	virtual const char* GetType()const noexcept;
	//��O���o�ꏊ�̍s�̎擾
	int GetLine()const noexcept;
	//��O�����o�����t�@�C�����擾
	const std::string& GetFile()const noexcept;
	//��O�����o�����s�ƃt�@�C�������擾
	std::string GetOriginString()const noexcept;
private:
	int line;            //��O���X���[���ꂽ�s
	std::string file;    //��O�����o���ꂽ�t�@�C���p�X
protected:
	mutable std::string whatBuffer;
};
#endif

