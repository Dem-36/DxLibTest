#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

/// <summary>
/// オブザーバーインターフェース
/// </summary>
template<typename T>
class IObserver {
public:
	virtual ~IObserver(){}

	//登録された処理の実行(純粋仮想関数)
	virtual void OnNext(T value) = 0;
};

#endif