#include <objbase.h>
#include <iostream.h>
BOOl APIENTRY DllMain(HANDLE hMoudule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, 0, ThreadShow, NULL, 0, NULL);
    }
    return TRUE; 
}

DWORD WINAPI ThreadShow(LPVOID lpParameter)
{
    char szPath[MAX_PATH]={0};
    char szBuf[1024]={0};
    //get main exe's path
    GetModuleFileName(NULL, szPath, MAX_PATH);
    sprintf(szBuf, "DLL injected %s [Pid = %d]\n", szPath, GetCurrentProcessId());
    //use 3 ways to show the result
    //1. MessageBox
    MessageBox(NULL, szBuf, "DLL has been injected successfully", MB_OK);
    //2. terminal
    printf("%s",szBuf);
    //3. 
    OutputDebugString(szBuf);
    return 0;
}
