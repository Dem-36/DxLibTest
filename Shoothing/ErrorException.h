#ifndef _ERROREXCEPTION_H_
#define _ERROREXCEPTION_H_

#include<exception>
#include<string>

//例外スロー用クラス
class ErrorException:public std::exception
{
public:
	//コンストラクタ
	ErrorException(int line, const char* file)noexcept;
	//エラー文の取得
	const char* what()const noexcept override;
	//エラータイプの取得
	virtual const char* GetType()const noexcept;
	//例外検出場所の行の取得
	int GetLine()const noexcept;
	//例外を検出したファイル名取得
	const std::string& GetFile()const noexcept;
	//例外を検出した行とファイル名を取得
	std::string GetOriginString()const noexcept;
private:
	int line;            //例外がスローされた行
	std::string file;    //例外が検出されたファイルパス
protected:
	mutable std::string whatBuffer;
};
#endif

