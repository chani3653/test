#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
void rotate90(void); ///
HINSTANCE g_hInst; ///

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("Test 2005-2-1") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;
	 g_hInst=hInstance; ///

     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName,                  // window class name
                          TEXT ("Test 2002-2-1"), // window caption
                          WS_OVERLAPPEDWINDOW,        // window style
                          CW_USEDEFAULT,              // initial x position
                          CW_USEDEFAULT,              // initial y position
                          CW_USEDEFAULT,              // initial x size
                          CW_USEDEFAULT,              // initial y size
                          NULL,                       // parent window handle
                          NULL,                       // window menu handle
                          hInstance,                  // program instance handle
                          NULL) ;                     // creation parameters
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

FILE * fpin;
int image[256][256];

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     HDC         hdc ;
     PAINTSTRUCT ps ;
     static RECT rt;  //
	 static HWND hCombo; ////
	 static char Items[][15]={"90도","180도","270도"}; ////
	 int index; ////
	 int i,j, temp;

	      
     switch (message)
     {
     case WM_CREATE:
		 CreateWindow("button","90도 회전",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20,20,100,25,hwnd,(HMENU)0,g_hInst,NULL); ///
         //// 		
		 hCombo=CreateWindow("combobox",NULL,WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
			20,50,100,200,hwnd,(HMENU)1,g_hInst,NULL);
		 for (i=0;i<3;i++)
			SendMessage(hCombo,CB_ADDSTRING,0,(LPARAM)Items[i]);
		 SendMessage(hCombo,CB_SETCURSEL,(WPARAM)0,0);		
		 ////
		 if((fpin=fopen("data.txt", "r"))==NULL)
		 {
			MessageBox(hwnd, "Read File open failed", "Fiel Open Error", MB_OK);
		 }

		 for(i=0; i<256; i++)
			 for(j=0; j<256; j++)
			 {
				 fscanf(fpin, "%d", &image[i][j]);
			 }

		 fclose(fpin);
		 return 0 ;
	 
	 case WM_SIZE:	  //
	  	 rt.right=LOWORD(lParam); // 
	 	 rt.bottom=HIWORD(lParam); //
		 return 0 ; //		  

 	 case WM_COMMAND: ///
		switch(LOWORD(wParam))///
		{
		case 0:///
			rotate90();///
			InvalidateRect(hwnd, NULL, FALSE);///
			break;
		//}
		////
		case 1:
			switch (HIWORD(wParam)) {
			case CBN_SELCHANGE:
				index=SendMessage(hCombo, CB_GETCURSEL,0,0);
				for(i=0; i<index+1; i++)
					rotate90();
				InvalidateRect(hwnd, NULL, FALSE);
				break;
			}
		}
		////
		return 0;///
     
	 case WM_PAINT:
          hdc = BeginPaint (hwnd, &ps) ;
		  SetViewportOrgEx(hdc, (rt.right/2)-128, (rt.bottom/2)-128, NULL);  //
		  
		  for(i=0; i<256; i++)
			  for(j=0; j<256; j++)
			  {
				    temp=image[i][j];
					SetPixel(hdc,j,i,RGB(temp,temp,temp));
			  }

		  EndPaint (hwnd, &ps) ;
          return 0 ;
          
     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}

///
void rotate90(void)
{
	int i,j;
	int temp[256][256];
	for(i=0; i<256; i++)
		for(j=0; j<256; j++)
		{
			temp[i][j]=image[i][j];
		}

	for(i=0; i<256; i++)
		for(j=0; j<256; j++)
		{
			image[i][256-j-1]=temp[j][i];
		}

}