#ifndef _RESOURCEEXCEPT_H_
#define _RESOURCEEXCEPT_H_

#include"ErrorException.h"

class ResourceException:public ErrorException
{
public:
	ResourceException(int line, const char* file, const std::string resourceName);
	const char* what()const noexcept override;
	virtual const char* GetType()const noexcept;
	std::string GetErrorString()const noexcept;
private:
	std::string resourceName;
};
#endif
