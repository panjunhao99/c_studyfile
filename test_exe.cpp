#include <iostream>  
#include <windows.h>

using namespace std;




int main()
{

  {
    SHELLEXECUTEINFO shExecInfo = {0};
    shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    shExecInfo.fMask  = SEE_MASK_NOCLOSEPROCESS;
    shExecInfo.hwnd   = NULL;
    shExecInfo.lpVerb = TEXT("open");
    shExecInfo.lpFile = TEXT("D:/Achollege/code/yolov5-6.2/detect_bag2/detect_R.exe");       
    shExecInfo.lpParameters = TEXT("--source=D:/Achollege/code/0630_model_R/yolov5-6.0/test_img --weight=D:/Achollege/code/0630_model_R/yolov5-6.0/best.pt --project=D:/Achollege/code/0630_model_R/yolov5-6.0/output");   
    shExecInfo.lpDirectory  = TEXT("D:/Achollege/code/yolov5-6.2/detect_bag2");      
    shExecInfo.hInstApp     = NULL;
    ShellExecuteEx(&shExecInfo);

    WaitForSingleObject(shExecInfo.hProcess,INFINITE); 
  }

  return 0;
}