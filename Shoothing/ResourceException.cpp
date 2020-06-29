#include "ResourceException.h"
#include<sstream>

ResourceException::ResourceException(int line, const char* file, const std::string resourceName)
	:ErrorException(line,file),resourceName(resourceName)
{
}

const char* ResourceException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< "[Description] " << GetErrorString() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ResourceException::GetType() const noexcept
{
	return "Resource Exception";
}

std::string ResourceException::GetErrorString() const noexcept
{
	std::ostringstream oss;
	oss << "指定したリソースが存在しません。" << std::endl
		<< "[ResourceName] " << resourceName << std::endl;
	return oss.str();
}
