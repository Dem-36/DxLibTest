#ifndef _IOBSERVABLE_H_
#define _IOBSERVABLE_H_

#include<functional>

/// <summary>
/// インターフェース
/// 登録した関数の実行処理
/// </summary>
template<typename T>
class IObservable {
public:
	//仮想デストラクタ
	virtual ~IObservable(){}

	//処理の登録(純粋仮想関数)
	//std::function<戻り値の型(引数の型)> object = 関数or ラムダ式 or 関数オブイェクト orクラスのメンバ関数
	virtual void Subscribe(std::function<void(T)> func) = 0;
};

#endif