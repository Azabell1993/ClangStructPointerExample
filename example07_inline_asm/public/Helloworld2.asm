;------------------------------------------------------------------
;
;      HelloWorld2 - copyright Jeremy Gordon 2002
;
;      SIMPLE "HELLO WORLD" WINDOWS GDI PROGRAM - for GoAsm
;
;      Assemble using GoAsm HelloWorld2 (produces PE COFF file)
;      Then link using:-
;      GoLink HelloWorld2.obj user32.dll kernel32.dll gdi32.dll
;      (add -debug coff if you want to watch the program in the debugger)
;
;------------------------------------------------------------------
;
DATA SECTION
;
hInst DD 0            ;to keep the handle to the process itself
hDC   DD 0            ;to keep the handle of the device context
PAINTSTRUCT DD 16 DUP 0  ;structure to hold stuff from Windows on WM_PAINT
MSG DD 7 DUP 0        ;structure to hold messages from Windows as follows:-
;hwnd, +4=message, +8=wParam, +C=lParam, +10h=time, +14h/18=pt
WNDCLASS DD 10D DUP 0 ;structure to send to RegisterClass holding data:-
                      ;+0 window class style (CS_)
                      ;+4 pointer to Window Procedure
                      ;+8 no. of extra bytes to allocate after structure
                      ;+C no. of extra bytes to allocate after window instance
                      ;+10 handle to instance of this window class
                      ;+14 handle to the class icon
                      ;+18 handle to the class cursor
                      ;+1C identifies the class background brush
                      ;+20 pointer to resource name for class menu
                      ;+24 pointer to string for window class name
;******************** Window message table 
;          (in a real program this would deal with many more messages)
MESSAGES DD (ENDOF_MESSAGES-$-4)/8      ;=number to be done
         DD  1h,CREATE,2h,DESTROY,0Fh,PAINT
ENDOF_MESSAGES:           ;label used to work out how many messages
;******************************************
;
WINDOW_CLASSNAME DB 'WC',0            ;string to hold name of window class
;
;------------------------------------------------------------------
;
CODE SECTION
;
INITIALISE_WNDCLASS:    ;get ready to register the window class
MOV EBX,ADDR WNDCLASS
MOV EAX,9
L1:
MOV D[EBX+EAX*4],0      ;fill it with zeroes
DEC EAX
JNS L1
;***** add things to window class for all windows in the program ..
MOV EAX,[hInst]         ;get handle to the process
MOV [EBX+10h],EAX       ;make it the window class
PUSH 32512              ;IDC_ARROW common cursor
PUSH 0
CALL LoadCursorA        ;get in eax, handle to arrow cursor
MOV [EBX+18h],EAX       ;and give to WNDCLASS
MOV D[EBX+1Ch],6D       ;set background brush to COLOR_WINDOW+1
RET
;
;*******************
CREATE:                 ;one of the few messages dealt with by this prog
XOR EAX,EAX             ;return zero to make window
RET
;
DESTROY:                ;one of the few messages dealt with by this prog
PUSH 0
CALL PostQuitMessage    ;exit via the message loop
STC                     ;go to DefWindowProc too
RET
;
;This paints an ellipse in the rectangle provided by Windows on the
;message WM_PAINT. This rectangle is the area which needs updating, eg
;on resizing or if the window is uncovered by another.
PAINT:
MOV EBX,ADDR PAINTSTRUCT
PUSH EBX,[EBP+8h]           ;EBP+8h=hwnd
CALL BeginPaint             ;get device context to use, initialise paint
MOV [hDC],EAX
PUSH [EBX+14h],[EBX+10h]    ;rectangle bottom, right
PUSH [EBX+0Ch],[EBX+8h]     ;rectangle top, left
PUSH [hDC]
CALL Ellipse                ;draw ellipse in update rectangle
PUSH EBX,[EBP+8h]           ;EBP+8h=hwnd
CALL EndPaint
XOR EAX,EAX
RET
;
;********** this is a general window procedure which in an ordinary
;********** program deals with all messages sent to the window
GENERAL_WNDPROC:        ;eax can be used to convey information to the call
PUSH EBP                ;use ebp to avoid using eax which may hold information
MOV EBP,[ESP+10h]       ;uMsg
MOV ECX,[EDX]           ;get number of messages to do
ADD EDX,4               ;jump over size dword
L2:
DEC ECX
JS >L3
CMP [EDX+ECX*8],EBP     ;see if its the correct message
JNZ L2                  ;no
MOV EBP,ESP
PUSH ESP,EBX,EDI,ESI    ;save registers as required by Windows
ADD EBP,4               ;allow for the extra call to here
;now [EBP+8]=hwnd, [EBP+0Ch]=uMsg, [EBP+10h]=wParam, [EBP+14h]=lParam,
CALL [EDX+ECX*8+4]      ;call the correct procedure for the message
POP ESI,EDI,EBX,ESP
JNC >L4                 ;nc=return value in eax - don't call DefWindowProc
L3:
PUSH [ESP+18h],[ESP+18h],[ESP+18h],[ESP+18h]     ;allowing for change of ESP
CALL DefWindowProcA
L4:
POP EBP
RET
;
;******************* This is the actual window procedure
WndProcTable:
MOV EDX,ADDR MESSAGES   ;give edx the list of messages to deal with
CALL GENERAL_WNDPROC    ;call the generic message handler
RET 10h                 ;restore the stack as required by caller
;
;*******************************************************************
START:
PUSH 0
CALL GetModuleHandleA   ;get handle to the process
MOV [hInst],EAX         ;record it in data label hInst
CALL INITIALISE_WNDCLASS    ;get ready to register window class
;********** now add things specific to the window to be made
MOV D[EBX],1h+2h+40h    ;CS_VREDRAW+CS_HREDRAW+CS_CLASSDC (window class style)
MOV D[EBX+4],ADDR WndProcTable          ;window procedure
MOV D[EBX+24h],ADDR WINDOW_CLASSNAME    ;window class name
PUSH EBX                ;address of structure with window class data
CALL RegisterClassA     ;register the window class
PUSH 0,[hInst],0,0      ;owner=desktop
PUSH 200D               ;height
PUSH 320D               ;width
PUSH 50D,50D            ;position y then x
PUSH 90000000h +0C00000h+40000h +80000h +20000h     +10000h      ;window style
;(POPUP+VISIBLE)+CAPTION+SIZEBOX+SYSMENU+MINIMIZEBOX+MAXIMIZEBOX
PUSH 'Hello World window made by GoAsm'       ;window title
PUSH ADDR WINDOW_CLASSNAME     ;window class name
PUSH 0                  ;extended window style
CALL CreateWindowExA    ;make window, returning handle in EAX
;************************ now enter the main message loop
L1:
PUSH 0,0,0
PUSH ADDR MSG
CALL GetMessageA        ;wait for message from Windows
OR EAX,EAX              ;see if it is WM_QUIT
JZ >L2                  ;yes
PUSH ADDR MSG
CALL TranslateMessage   ;no so convert message to character if necessary
PUSH ADDR MSG
CALL DispatchMessageA   ;and send the message to the window procedure
JMP L1                  ;after message dealt with, loop back for next one
L2:
PUSH [hInst],ADDR WINDOW_CLASSNAME   ;message was WM_QUIT
CALL UnregisterClassA   ;ensure class is removed
PUSH [MSG+8h]           ;exit code (send contents of wParam)
CALL ExitProcess        ;return to Windows in the manner it prefers