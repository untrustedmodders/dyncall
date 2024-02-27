#include <plugify/cpp_plugin.h>
#include <plugin_export.h>
#include <dyncall/dyncall.h>

class DynCallPlugin : public plugify::IPluginEntry {
	void OnPluginStart() override {}

	void OnPluginEnd() override {}
} g_dynCallPlugin;

EXPOSE_PLUGIN(PLUGIN_API, &g_dynCallPlugin)

// TODO: Validate ptr and make sure that allocated vm a

extern "C"
PLUGIN_API DCCallVM* NewVM(size_t size) { return dcNewCallVM(size); }
extern "C"
PLUGIN_API void Free(DCCallVM* vm) { dcFree(vm); }
extern "C"
PLUGIN_API void Reset(DCCallVM* vm) { dcReset(vm); }
extern "C"
PLUGIN_API void Mode(DCCallVM* vm, int mode) { dcMode(vm, mode); }

extern "C"
PLUGIN_API void ArgBool(DCCallVM* vm, bool value) { dcArgBool(vm, value); }
extern "C"
PLUGIN_API void ArgChar(DCCallVM* vm, char value) { dcArgChar(vm, value); }
extern "C"
PLUGIN_API void ArgInt8(DCCallVM* vm, int8_t value) { dcArgChar(vm, value); }
extern "C"
PLUGIN_API void ArgUInt8(DCCallVM* vm, uint8_t value) { dcArgChar(vm, static_cast<int8_t>(value)); }
extern "C"
PLUGIN_API void ArgInt16(DCCallVM* vm, int16_t value) { dcArgShort(vm, value); }
extern "C"
PLUGIN_API void ArgUInt16(DCCallVM* vm, uint16_t value) { dcArgShort(vm, static_cast<int16_t>(value)); }
extern "C"
PLUGIN_API void ArgInt32(DCCallVM* vm, int32_t value) { dcArgInt(vm, value); }
extern "C"
PLUGIN_API void ArgUInt32(DCCallVM* vm, uint32_t value) { dcArgInt(vm, static_cast<int32_t>(value)); }
extern "C"
PLUGIN_API void ArgInt64(DCCallVM* vm, int64_t value) { dcArgLongLong(vm, value); }
extern "C"
PLUGIN_API void ArgUInt64(DCCallVM* vm, uint64_t value) { dcArgLongLong(vm, static_cast<int64_t>(value)); }
extern "C"
PLUGIN_API void ArgFloat(DCCallVM* vm, float value) { dcArgFloat(vm, value); }
extern "C"
PLUGIN_API void ArgDouble(DCCallVM* vm, double value) { dcArgDouble(vm, value); }
extern "C"
PLUGIN_API void ArgPointer(DCCallVM* vm, void* value) { dcArgPointer(vm, value); }
extern "C"
PLUGIN_API void ArgStruct(DCCallVM* vm, DCstruct* s, void* value) { dcArgStruct(vm, s, value); }

extern "C"
PLUGIN_API void CallVoid(DCCallVM* vm, void* funcptr) { dcCallVoid(vm, funcptr); }
extern "C"
PLUGIN_API bool CallBool(DCCallVM* vm, void* funcptr) { return dcCallBool(vm, funcptr); }
extern "C"
PLUGIN_API char CallChar(DCCallVM* vm, void* funcptr) { return dcCallChar(vm, funcptr); }
extern "C"
PLUGIN_API int8_t CallInt8(DCCallVM* vm, void* funcptr) { return dcCallChar(vm, funcptr); }
extern "C"
PLUGIN_API uint8_t CallUInt8(DCCallVM* vm, void* funcptr) { return static_cast<uint8_t>(dcCallChar(vm, funcptr)); }
extern "C"
PLUGIN_API int16_t CallInt16(DCCallVM* vm, void* funcptr) { return dcCallShort(vm, funcptr); }
extern "C"
PLUGIN_API uint16_t CallUInt16(DCCallVM* vm, void* funcptr) { return static_cast<uint16_t>(dcCallShort(vm, funcptr)); }
extern "C"
PLUGIN_API int32_t CallInt32(DCCallVM* vm, void* funcptr) { return dcCallInt(vm, funcptr); }
extern "C"
PLUGIN_API uint32_t CallUInt32(DCCallVM* vm, void* funcptr) { return static_cast<uint32_t>(dcCallInt(vm, funcptr)); }
extern "C"
PLUGIN_API int64_t CallInt64(DCCallVM* vm, void* funcptr) { return dcCallLongLong(vm, funcptr); }
extern "C"
PLUGIN_API uint64_t CallUInt64(DCCallVM* vm, void* funcptr) { return static_cast<uint64_t>(dcCallLongLong(vm, funcptr)); }
extern "C"
PLUGIN_API float CallFloat(DCCallVM* vm, void* funcptr) { return dcCallFloat(vm, funcptr); }
extern "C"
PLUGIN_API double CallDouble(DCCallVM* vm, void* funcptr) { return dcCallDouble(vm, funcptr); }
extern "C"
PLUGIN_API void* CallPointer(DCCallVM* vm, void* funcptr) { return dcCallPointer(vm, funcptr); }
extern "C"
PLUGIN_API void CallStruct(DCCallVM* vm, void* funcptr, DCstruct* s, void* returnValue) { dcCallStruct(vm, funcptr, s, returnValue); } 

extern "C"
PLUGIN_API int GetError(DCCallVM* vm) { return dcGetError(vm); }

extern "C"
PLUGIN_API DCstruct* NewStruct(size_t fieldCount, int alignment) { return dcNewStruct(fieldCount, alignment); }
extern "C"
PLUGIN_API void StructField(DCstruct* s, int type, int alignment, size_t arrayLength) { dcStructField(s, type, alignment, arrayLength); } 
extern "C"
PLUGIN_API void SubStruct(DCstruct* s, size_t fieldCount, int alignment, size_t arrayLength) { dcSubStruct(s, fieldCount, alignment, arrayLength); } 
extern "C"
PLUGIN_API void CloseStruct(DCstruct* s) { dcCloseStruct(s); } 	  	
extern "C"
PLUGIN_API size_t StructSize(DCstruct* s) { return dcStructSize(s); } 	
extern "C"
PLUGIN_API size_t StructAlignment(DCstruct* s) { return dcStructAlignment(s); }  	
extern "C"
PLUGIN_API void FreeStruct(DCstruct* s) { dcFreeStruct(s); } 	

extern "C"
PLUGIN_API DCstruct* DefineStruct(const std::string& signature) { return dcDefineStruct(signature.c_str()); }
extern "C"
PLUGIN_API int GetModeFromCCSigChar(char sigChar) { return dcGetModeFromCCSigChar(sigChar); }