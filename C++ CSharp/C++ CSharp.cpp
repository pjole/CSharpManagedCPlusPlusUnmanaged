#include "stdafx.h"
#include "C++ CSharp.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace CPlus {


#pragma region newModuleHeader


		W_newModuleHeader::W_newModuleHeader()
		{
			_nMH = new newModuleHeader();
			StructPointer = (IntPtr)_nMH;
			StructSize = sizeof(newModuleHeader);
		}

		W_newModuleHeader::W_newModuleHeader(IntPtr ModuleHeader)
		{
			_nMH = (newModuleHeader*)ModuleHeader.ToPointer();
			StructPointer = ModuleHeader;
			StructSize = sizeof(newModuleHeader);
		}

		UInt16 W_newModuleHeader::id::get() { return _nMH->id; }
		void W_newModuleHeader::id::set(UInt16 id) { _nMH->id = id; }

		UInt32 W_newModuleHeader::index::get() { return _nMH->index; }
		void W_newModuleHeader::index::set(UInt32 index) { _nMH->index = index; }


#pragma endregion


	}

