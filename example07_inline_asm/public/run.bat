nasm -f win32 MessageBox32.asm -o MessageBox32.obj
golink /entry:Start kernel32.dll user32.dll MessageBox32.obj
gcc  -shared -o MessageBox32.dll MessageBox32.o -Wl,--out-implib,lib-MessageBox32.obj




