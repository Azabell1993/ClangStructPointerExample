gcc -c -DBUILD_MY_DLL Calculator.c
gcc  -shared -o Calculator.dll Calculator.o -Wl,--out-implib,lib-Calculator.a
gcc main.c -W -Wformat -Wextra -Werror -o main.exe
emcc Calculator.c -s WASM=1 -o Calculator.html --shell-file html_template/shell_minimal.html -s NO_EXIT_RUNTIME=1
