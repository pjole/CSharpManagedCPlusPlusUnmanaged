// C++ CSharp.h

#pragma once

using namespace System;

#ifdef _WIN32
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
namespace CPlus {

#pragma pack(push)
#pragma pack(1)
#else
#include "type_defs.h"
#endif // _WIN32

/////// TYPEDEFS BEGIN ///////

#ifdef _WIN32
typedef signed char     Int8;
typedef unsigned char   UInt8;
typedef signed short    Int16;
typedef unsigned short  UInt16;
typedef signed long     Int32;
typedef unsigned long   UInt32;
#endif // _WIN32


#ifdef _WIN32
public ref class ConfigStruct
{
public:
	IntPtr StructPointer;
	Int32 StructSize;
};
#endif // _WIN32




// nova definicija headera modula od xx/02/2013, za generiranje konfiguracije
typedef struct
{
	UInt16 id;
	UInt32 index;
}
newModuleHeader;


#ifdef _WIN32
public ref class W_newModuleHeader : ConfigStruct
{
public:
	W_newModuleHeader();
	W_newModuleHeader(IntPtr ModuleHeader);
	newModuleHeader* _nMH;
	virtual property UInt16 id { UInt16 get(); void set(UInt16 id); };
	virtual property UInt32 index { UInt32 get(); void set(UInt32 index); };
};

#endif // _WIN32


/////// CONSTANTS BEGIN ///////


#ifdef _WIN32
#pragma pack(pop)
} // namespace Cplus

#endif // _WIN32
