GoAsm Helloworld2
GoLink HelloWorld2.obj user32.dll kernel32.dll gdi32.dll
@REM nasm -f win32 Helloworld2.asm -o Helloworld2.obj
@REM golink /entry:Start kernel32.dll user32.dll Helloworld2.obj





