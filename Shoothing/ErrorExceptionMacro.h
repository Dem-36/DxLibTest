#ifndef _ERROREXCEPTIONMACRO_H_
#define _ERROREXCEPTIONMACRO_H_

#include"ErrorException.h"
#include"ResourceException.h"

#define DX_EXCEPT throw ErrorException(__LINE__,__FILE__)
#define DX_CHECK_EXCEPT(hr) if(FAILED(hr)) throw ErrorException(__LINE__,__FILE__)

#define DX_RESOURCE_EXCEPT(resourceName) throw ResourceException(__LINE__,__FILE__,resourceName)

#endif