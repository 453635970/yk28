#ifndef TDX_REGISTER_H_
#define TDX_REGISTER_H_
#pragma pack(push, 1)

// 函数(数据个数,输出,输入a,输入b,输入c)
typedef void (*pPluginFUNC)(int, float*, float*, float*, float*);

typedef struct tagPluginTCalcFuncInfo {
  unsigned short nFuncMark;  // 函数编号
  pPluginFUNC pCallFunc;     // 函数地址
} PluginTCalcFuncInfo;

typedef BOOL (*pRegisterPluginFUNC)(PluginTCalcFuncInfo**);
#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus
__declspec(dllexport) BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun);
#ifdef __cplusplus
}
#endif  //__cplusplus
#endif  /* TDX_REGISTER_H_ */
