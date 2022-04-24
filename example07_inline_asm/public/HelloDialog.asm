;------------------------------------------------------------------
;
;      HelloDialog - copyright Jeremy Gordon 2004
;
;      SIMPLE Dialog program
;      This displays some messages in a modal dialog box 
;      and then a MessageBox
;      The modal dialog box is made using a template in data
;      instead of the usual resource file.  For this reason
;      it uses DialogBoxIndirectParamA instead of DialogBoxParam
;      which would be used to make a modal dialog box using a
;      resource file.
;
;      No include files are used since all constants are inserted by hand
;
;      Assemble using GoAsm HelloDialog 
;      This produces a PE COFF file.
;      Then link using:-
;      GoLink HelloDialog.obj kernel32.dll user32.dll
;      (add /debug coff if you want to watch the program in the debugger)
;      This produces HelloDialog.exe
;
;------------------------------------------------------------------
;
;*******************************************************************
;
DATA SECTION
;
ALIGN 4         ;just to emphasise this must be dword aligned
;*********************** here is the dialog template for the dialog
DIALOG_TEMPLATE DD 10000000h |0C00000h  |800h     |40h|  \
                   80h          |80000h    +20000h
            ;style WS_VISIBLE+WS_CAPTION+DS_CENTER+DS_SETFONT
            ;      DS_MODALFRAME+WS_SYSMENU+WS_MINIMIZEBOX
             DD 0                 ;extended style
             DW 5                 ;no. items in dialog box
             DW 0                 ;top left x position
             DW 0                 ;top left y position
             DW 160               ;box width
             DW 104               ;box height
             DW 0                 ;menu array (no menu)
             DW 0                 ;class array (use default)
             DUS 'HelloDialog demonstration',0   
            ;title (DUS causes assembler to convert string
            ;to Unicode as required by Windows)
             DW 10                ;font point size
             DUS 'Microsoft Sans Serif',0
            ;you can change the font using eg. Arial or Times New Roman
;*********************************** make a box for the following group
ALIGN 4         ;must be dword aligned
DD 50000000h          +7h
;(WS_CHILD+WS_VISIBLE)+BS_GROUPBOX
DD 0           ;extended style
DW 6           ;control top left x position
DW 6           ;control top left y position
DW 148         ;control width
DW 90          ;control height
DW 0           ;control identifier
DW -1          ;look at next for class
DW 80h         ;button control
DUS 'Various strings drawn inside dialog',0
DW 0           ;elements to send to DlgProc (none)
;*********************************** next control
ALIGN 4         ;must be dword aligned
DD 50000000h          
;(WS_CHILD+WS_VISIBLE)
DD 0           ;extended style
DW 10          ;control top left x position
DW 23          ;control top left y position
DW 140         ;control width
DW 10          ;control height
DW 1h          ;control identifier
DW -1          ;look at next for class
DW 82h         ;static control
DUS 'String already in the dialog template',0  
DW 0           ;elements to send to DlgProc (none)
;*********************************** next control
ALIGN 4        ;must be dword aligned
CONTROL_2:     ;label to alter control dynamically
DD 50000000h   ;+0
;(WS_CHILD+WS_VISIBLE)
DD 0           ;+4 extended style
DW 10          ;+8 control top left x position
DW 43          ;+A control top left y position
DW 140         ;+C control width
DW 10          ;+E control height
DW 2h          ;+10 control identifier
DW -1          ;+12 look at next for class
DW 82h         ;+14 static control
DW 30 DUP 0    ;+16 space for Unicode null terminated string to be added
DW 0           ;elements to send to DlgProc (none)
;*********************************** next control
ALIGN 4         ;must be dword aligned
DD 50000000h
;(WS_CHILD+WS_VISIBLE)
DD 0           ;extended style
DW 10          ;control top left x position
DW 63          ;control top left y position
DW 140         ;control width
DW 10          ;control height
DW 3h          ;control identifier
DW -1          ;look at next for class
DW 82h         ;static control
DW 0           ;this string will added by INITIALISE_DIALOG
DW 0           ;elements to send to DlgProc (none)
;*********************************** next control
ALIGN 4         ;must be dword aligned
DD 50000000h
;(WS_CHILD+WS_VISIBLE)
DD 0           ;extended style
DW 10D         ;control top left x position
DW 83          ;control top left y position
DW 140         ;control width
DW 10          ;control height
DW 4h          ;control identifier
DW -1          ;look at next for class
DW 82h         ;static control
DW 0           ;this string will added by INITIALISE_DIALOG
DW 0           ;elements to send to DlgProc (none)
;
ALIGN 4
GOODBYE_MESSAGE DB "Goodbye from the HelloDialog program.  We'll see you again.",0
DYNO_STRING     DB 'String inserted dynamically 1',0     ;30 chars including null
;
;*******************************************************************
;*  CODE
;*******************************************************************
CODE SECTION
;
;***************************************************** PROGRAM START
START:
PUSH 0
CALL GetModuleHandleA   ;get handle to this process in eax
;****************************** now create the dialog box
CALL INSERT_DYNAMICSTRING
PUSH 0                  ;initialisation value (not used)
PUSH ADDR DlgProc       ;pointer to dialog procedure
PUSH 0                  ;this dialog has desktop as parent
PUSH ADDR DIALOG_TEMPLATE      ;template in the file itself
PUSH EAX                ;handle to this process from GetModuleHandleA
CALL DialogBoxIndirectParamA   ;this does not return until dialog closed
PUSH 0                  ;exit code zero
CALL ExitProcess        ;never returns from here
;
;******************************************************* DIALOG PROCEDURE
;This uses FRAME..ENDF to establish a local data and to get the parameters
;
DlgProc FRAME hDlg,uMsg,wParam,lParam  
USES EBX,EDI,ESI        ;save ebx,edi,esi as required by Windows (safety only)
MOV EAX,[uMsg]          ;get message
CMP EAX,110h            ;see if WM_INITDIALOG message
JNZ >                   ;no, jump to next colon
CALL INITIALISE_DIALOG
MOV EAX,1
JMP >.return            ;return eax=non-zero as required by Windows
:
CMP EAX,111h            ;see if WM_COMMAND message
JNZ >.false             ;no
CMP W[wParam],2h        ;see if sysmenu was clicked
JNZ >.false             ;no
;*********************** yes, so say goodbye in a MessageBox
PUSH 40h                		;information and ok button
PUSH 'GoodbyeDialog'    ;title
PUSH ADDR GOODBYE_MESSAGE     	;main body text
PUSH [hDlg]             		;owner (this dialog)
CALL MessageBoxA
;****************************** 
PUSH 1,[hDlg]
CALL EndDialog          ;end the dialog
.false
XOR EAX,EAX             ;return zero as required
.return
RET
ENDF
;
;note this must be done before DialogBoxIndirectParamA is called
;it cannot be done on the WM_INITDIALOG message
INSERT_DYNAMICSTRING:
;*************** add DYNO_STRING to the second static control
MOV EDI,ADDR CONTROL_2     ;get address of static control in edi
ADD EDI,16h             ;get edi to the address of the control's string
MOV ESI,ADDR DYNO_STRING   ;give address of source to edi
XOR EAX,EAX             ;zero eax register
;*************** load the string converting to Unicode at the same time
L0:
LODSB                   ;load al at [esi] and advance esi
STOSW                   ;store ax at [edi] and advance edi
OR AL,AL                ;see if AL=0
JNZ L0                  ;no, continue
RET
;
;On WM_INITDIALOG you can do a lot of work adding things to the dialog
;for example:-
INITIALISE_DIALOG:
USEDATA DlgProc         ;use the local data held in the DlgProc frame 
PUSH 'String inserted dynamically 2'
PUSH 3h                 ;control with identifier of 3
PUSH [hDlg]             ;use the dialog handle held in local data
CALL SetDlgItemTextA
;************************** now do control number 4 a different way
PUSH 4h                 ;control with identifier of 3
PUSH [hDlg]             ;use the dialog handle held in local data
CALL GetDlgItem         ;get the handle to the control in eax
PUSH 'String inserted dynamically 3'
PUSH 0                  ;wParam not used
PUSH 0Ch                ;constant value for the message WM_SETTEXT
PUSH EAX                ;handle to the control from GetDlgItem 
CALL SendMessageA       ;send the WM_SETTEXT message with the string
RET