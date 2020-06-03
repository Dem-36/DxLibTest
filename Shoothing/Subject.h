#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include"IObserver.h"
#include"IObservable.h"
#include<list>

template<typename T>
class Subject :public IObservable<T>, public IObserver<T> {
public:
	//ƒCƒxƒ“ƒg‚Ì’Ê’mæ‚ğ“o˜^
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(func);
	}

	//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”‚ğÀs‚·‚é
	void OnNext(T value) {
		for (std::function<void(T)> s: _list) {
			//“o˜^‚³‚ê‚Ä‚¢‚éŠÖ”‚ğŒÄ‚Ño‚·
			s(value);
		}
	}

	/// <summary>
	/// ‘ÎÛ‚ÌƒNƒŠƒA
	/// </summary>
	void Dispose() {
		_list.clear();
	}

private:
	std::list<std::function<void(T)>> _list;
};

#endif