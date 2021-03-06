#include "ErrorException.h"
#include<sstream>

ErrorException::ErrorException(int line, const char* file) noexcept
	:line(line),file(file)
{
	
}

const char* ErrorException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ErrorException::GetType() const noexcept
{
	return "DxLib Exception";
}

int ErrorException::GetLine() const noexcept
{
	return line;
}

const std::string& ErrorException::GetFile() const noexcept
{
	return file;
}

std::string ErrorException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
