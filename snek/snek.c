#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<time.h>
#include<winuser.h>

COORD c = {0, 0};

const int higt = 11;
const int wid = 31;

void printftile(const char* tile, int x, int y){
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(tile);
}

void sleepx(float seconds){
	DWORD miliSeconds=seconds*1000;
	Sleep(miliSeconds);
}

void init(){
	system("CLS");
	int i;
	int j;
	for(i = 0; i < wid; ++i){
		for(j = 0; j < higt; ++j){
			printftile(".", i, j);
		}
	}
}

int arraycp(int a[], int b[], int size){
    int i;
	for(i=0;i<size;i++){
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

int arrinarray(int ine[], int arr[][2]){
    int i;
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        if(arraycp(arr[i], ine, 2)){
            return 1;
		}
    }
    return 0;
}

int sdir = 0;

int hx = 16;
int hy = 6;

int sgmnts[341][2] = {{13, 6}, {14, 6}, {15, 6}};

int howlong = 3;

int appl[] = {20, 6};

/*

sdir

0 = stop

1 = up
-1 = down

2 = right
-2 = left

*/

int main(){
	
	system("taskkill /f /im cmd.exe");
	
	srand(time(NULL));
	
	while(1){
		
		printf("\033[0;33m");
		
		init();
		
		if(GetAsyncKeyState(VK_UP)){
			if(sdir != -1){
				sdir = 1;
			}
		}
		if(GetAsyncKeyState(VK_DOWN)){
			if(sdir != 1){
				sdir = -1;
			}
		}
		if(GetAsyncKeyState(VK_RIGHT)){
			if(sdir != -2){
				sdir = 2;
			}
		}
		if(GetAsyncKeyState(VK_LEFT)){
			if(sdir != 2 || sdir != 0){
				sdir = -2;
			}
		}
		
		int phpos[] = {hx, hy};
		
		int longlen = sizeof(sgmnts) / sizeof(*sgmnts);
		
		if(((hx > (wid - 1)) || (hx < 0)) || ((hy > (higt - 1)) || (hy < 0))){
			system("start rs.cmd");
			exit(0);
		}
		
		if(arraycp(appl, phpos, 2)){
			
			int insrt[] = {0, 0};
			
			sgmnts[howlong + 1][2] = 16, 6;
			
			howlong += 1;
			
			while((arrinarray(appl, sgmnts)) || arraycp(appl, phpos, 2)){
				rand();
   				appl[0] = (rand() % wid);
   				appl[1] = (rand() % higt);
			}
		}
		
		for(int i = 0; i < howlong; i++){
			if(arraycp(phpos, sgmnts[i], 2)){
				system("start rs.cmd");
				exit(0);
			}
		}
		
		if(sdir != 0){
		
		for(int i = (howlong - 1); i > 0; i--){
			for (int j = 0; j < 2; j++) {     
        		sgmnts[i][j] = sgmnts[i - 1][j];
    		}
    	}
    	
    	if(howlong > 0){
    		for (int j = 0; j < 2; j++){     
        		sgmnts[0][j] = phpos[j];
    		}
		}
		
		}
		
		if(sdir == 1){
			hy -= 1;
		}
		if(sdir == -1){
			hy += 1;
		}
		if(sdir == 2){
			hx += 1;
		}
		if(sdir == -2){
			hx -= 1;
		}
		
		printf("\033[0;32m");
		
		printftile("#", hx, hy);
		
		for(int i = 0; i < howlong; i++){
			printftile("#", sgmnts[i][0], sgmnts[i][1]);
		}
		
		printf("\033[0;31m");
		
		printftile("@", appl[0], appl[1]);
		
		sleepx(0.00000001);
	}
}
