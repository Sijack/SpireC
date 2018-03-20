gcc -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\main.o" "..\\src\\main.c" 
gcc -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\utils.o" "..\\src\\utils.c" 
gcc -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\factorizations.o" "..\\src\\factorizations.c" 
gcc -o SpireC.exe "src\\utils.o" "src\\factorizations.o" "src\\main.o" 