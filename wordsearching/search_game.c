#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define SIZE 24
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void Find(char Writing[]);
void Create(char Writting[]);

char map[SIZE][SIZE];
int compare_map[SIZE][SIZE] = { 0, };
char ch[49][10] = { "" };
char lie_ch[49][10] = { "" };  //찾을 함수 비출력을 위해서
char meaning[49][70] = { "" };
int num;   //찾을 함수 개수
int num_count = 0; // 찾을 함수 중에서 몇개를 찾았는지 확인
int arr[13] = { 0, };  //찾을 함수 번호
int location[SIZE][SIZE] = { 0, }; // 좌표 위치(겹치지 않게 설정)
int pagenumber = 0;  //number의 세번재 인뎃스 번호를 지정
int Length; //문자열 길이 
int direction;  //방향
int hag_location = 0; // 처음 시작 가로 위치
int yul_location = 0; // 처음 시작 세로 위치
int hag = 1, yul = 1;
int timer;
int dap[49] = { 947294, 1556, 456, 587, 4669, 1445, 456, 4587, 5498, 6512, 2147,2147,2147, 2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147, 1546, 8522 };       // 정답인지 아닌지 알아내는 변수
char answer[10] = { "\0" };  // 정답 뽑아내는 문자열
int first = 0;
int beforhag, beforyul, afterhag, afteryul;
int hy;


void gets() {
	hy = 0;
	FILE* fp;
	fp = fopen("ch.txt", "r");    //단어 파일을 읽기모드로 열기
	char arr[3000];
	char hu[5000];
	fgets(arr, 2000, fp);    //arr문에 단어 파일의 글자들 대입
	int check = 0, tn = 0, td = 0;
	for (int i = 0; arr[i] != NULL; i++) {     //arr가 끝날때 까지 반복
		if (arr[i] == '/') {     //만약 /를 만나면
			tn = 0;
			hy++;
			for (; check < i; check++) {   //
				ch[td][tn] = arr[check];
				lie_ch[td][tn] = arr[check];
				tn++;
			}
			ch[td][tn] = '\0';
			lie_ch[td][tn] = '\0';
			td++;
			check++;

		}
	}
	fclose(fp);



	fp = fopen("meaning.txt", "r");

	fgets(hu, 4000, fp);
	check = 0, tn = 0, td = 0;
	for (int i = 0; hu[i] != NULL; i++) {
		if (hu[i] == '/') {
			tn = 0;
			for (; check < i; check++) {
				meaning[td][tn] = hu[check];
				tn++;
			}
			meaning[td][tn] = '\0';
			td++;
			check++;
		}
	}
	fclose(fp);

}

void Ending_screan() {
	system("cls");
	printf("the end");
	Sleep(3000);
	system("cls");
}

int menu() {
	// 메뉴 선택창
	int iu;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                                                  <<메뉴를 선택해 주세요>>\n");
	printf("                                                                                       1. 단어 기부하기\n");
	printf("                                                                                         2. 공부하기\n");
	printf("                                                                                         3. 게임종료\n");
	printf("                                                                                            >> ");
	scanf_s("%d", &iu);
	system("cls");
	return iu;
	// 입력받은 메뉴 번호를 반환
}

int Num()
{
	int n;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										찾을 단어의 수를 지정해 주세요(1 ~ %d)\n", hy);
	printf("										        	>> ");
	scanf_s("%d", &n);
	system("cls");
	return n;
}

void list()
{
	int kigram[49] = { 0, };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");     //목록 출력
	printf("										==== 목록중 찾을 함수 지정 ====\n");
	printf("		 (1) : %10s  (2) : %10s  (3) : %10s  (4) : %10s  (5) : %10s  (6) : %10s  (7) : %10s  (8) : %10s\n", ch[0], ch[1], ch[2], ch[3], ch[4], ch[5], ch[6], ch[7]);
	printf("		 (9) : %10s (10) : %10s (11) : %10s (12) : %10s (13) : %10s (14) : %10s (15) : %10s (16) : %10s\n", ch[8], ch[9], ch[10], ch[11], ch[12], ch[13], ch[14], ch[15]);
	printf("		(17) : %10s (18) : %10s (19) : %10s (20) : %10s (21) : %10s (22) : %10s (23) : %10s (24) : %10s\n", ch[16], ch[17], ch[18], ch[19], ch[20], ch[21], ch[22], ch[23]);
	printf("		(25) : %10s (26) : %10s (27) : %10s (28) : %10s (29) : %10s (30) : %10s (31) : %10s (32) : %10s\n", ch[24], ch[25], ch[26], ch[27], ch[28], ch[29], ch[30], ch[31]);
	printf("		(33) : %10s (34) : %10s (35) : %10s (36) : %10s (37) : %10s (38) : %10s (39) : %10s (40) : %10s\n", ch[32], ch[33], ch[34], ch[35], ch[36], ch[37], ch[38], ch[39]);
	printf("		(41) : %10s (42) : %10s (43) : %10s (44) : %10s (45) : %10s (46) : %10s (47) : %10s (48) : %10s\n", ch[40], ch[41], ch[42], ch[43], ch[44], ch[45], ch[46], ch[47]);


	int count;
	for (count = 0; count < num; count++) {  //찾을 함수 개수만큼 반복
		scanf_s("%d", &arr[count]);    //입력받아서 arr에 차례대로 저장
		kigram[arr[count] - 1] = 1;
	}
	system("cls");

	for (int i = 0; i < 49; i++) {        // 단어와 뜻중에서
		if (kigram[i] == 0) {             // 선택한 단어가 아니면
			for (int j = 0; j < 10; j++) {   //단어를 공백으로 
				if (j == 0)
					lie_ch[i][j] = '\0';
				else
					lie_ch[i][j] = ' ';
			}
			for (int j = 0; j < 70; j++) {    //뜻을 공백으로
				if (j == 69)
					meaning[i][j] = '\0';
				else
					meaning[i][j] = ' ';
			}
		}
	}
}

void Map_create()
{
	srand((unsigned)time(0));
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {
				map[i][j] = '#';    //맵의 가장자리는 #으로 설정
			}
			else
				map[i][j] = rand() % 26 + 97;    //그외는 랜덤 영어글자로 설정
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {    //location의 가장자리를 1로설정
				location[i][j] = 1;
			}
			else
				location[i][j] = 0;     //그외는 0으로 설정
		}
	}




	for (int p = 0; p < num; p++) {
		Find(ch[arr[p] - 1]);     //위치 검증 단계
		Create(ch[arr[p] - 1]);    //맵 제작 단계
	}


}
/* 방향(direction)
  0 1 2
  3 n 4
  5 6 7
*/
void Find(char Writing[]) // 확인하는 단계
{
	int Verification;  //검증하는 변수
	Length = strlen(Writing);
	while (1) {
		Verification = 0;
		hag_location = rand() % 21 + 1;
		yul_location = rand() % 21 + 1;
		direction = rand() % 8;  //방향에 따라 
		switch (direction)   //맵의 끝에 닿거나 다른 글자위치와 겹치면 재설정
		{
		case 0:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location - kbs][yul_location - kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		case 1:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location - kbs][yul_location] == 1) {
					Verification = 1;
				}
			}
			break;
		case 2:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location - kbs][yul_location + kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		case 3:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location][yul_location - kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		case 4:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location][yul_location + kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		case 5:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location + kbs][yul_location - kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		case 6:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location + kbs][yul_location] == 1) {
					Verification = 1;
				}
			}
			break;
		case 7:
			for (int kbs = 0; kbs < Length; kbs++) {
				if (location[hag_location + kbs][yul_location + kbs] == 1) {
					Verification = 1;
				}
			}
			break;
		}
		if (Verification == 0)
			break;   //확인된 시작위치와 방향이 확보됨
	}
}

void output() {
	system("cls");   //화면 지움
	for (int i = 1; i < SIZE - 1;) {
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                                            ┏━━━ <남은 시간>━━━┓\n");
		printf("┃                                                                                                                  ┃");
		printf(" 선택한 단어 : %20s         ┃", answer);
		if (timer <= 5) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("     %2d : %4d    ", 0, timer);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (timer <= 10) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("     %2d : %4d    ", 0, timer);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (timer <= 20) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			printf("     %2d : %4d    ", 0, timer);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else {
			printf("     %2d : %4d    ", 0, timer);
		}
		printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		printf("┃                                            ┗━━━━━━━━━━━━━━━━━━┛\n");
		printf("┃                                                                                                                  ┃ ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ <남은 글자>━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		printf("┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[0], lie_ch[1], lie_ch[2], lie_ch[3], lie_ch[4], lie_ch[5], lie_ch[6]);
		printf("┃                                                                                                                  ┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[7], lie_ch[8], lie_ch[9], lie_ch[10], lie_ch[11], lie_ch[12], lie_ch[13]);
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		printf("┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[14], lie_ch[15], lie_ch[16], lie_ch[17], lie_ch[18], lie_ch[19], lie_ch[20]);
		printf("┃                                                                                                                  ┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[21], lie_ch[22], lie_ch[23], lie_ch[24], lie_ch[25], lie_ch[26], lie_ch[27]);
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		printf("┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[28], lie_ch[29], lie_ch[30], lie_ch[31], lie_ch[32], lie_ch[33], lie_ch[34]);
		printf("┃                                                                                                                  ┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[35], lie_ch[36], lie_ch[37], lie_ch[38], lie_ch[39], lie_ch[40], lie_ch[41]);
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		printf("┃ ┃%10s%10s%10s%10s%10s%10s%10s┃\n", lie_ch[42], lie_ch[43], lie_ch[44], lie_ch[45], lie_ch[46], lie_ch[47], lie_ch[48]);
		printf("┃                                                                                                                  ┃ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[34] == 1) {
			printf("┃    %s %s\n", lie_ch[34], meaning[34]);
		}
		else if (dap[0] == 1) {
			printf("┃    %s %s\n", lie_ch[0], meaning[0]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[35] == 1) {
			printf("┃    %s %s\n", lie_ch[35], meaning[35]);
		}
		else if (dap[1] == 1) {
			printf("┃    %s %s\n", lie_ch[1], meaning[1]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[36] == 1) {
			printf("┃    %s %s\n", lie_ch[36], meaning[36]);
		}
		else if (dap[2] == 1) {
			printf("┃    %s %s\n", lie_ch[2], meaning[2]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[37] == 1) {
			printf("┃    %s %s\n", lie_ch[37], meaning[37]);
		}
		else if (dap[3] == 1) {
			printf("┃    %s %s\n", lie_ch[3], meaning[3]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[38] == 1) {
			printf("┃    %s %s\n", lie_ch[38], meaning[38]);
		}
		else if (dap[4] == 1) {
			printf("┃    %s %s\n", lie_ch[4], meaning[4]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[39] == 1) {
			printf("┃    %s %s\n", lie_ch[39], meaning[39]);
		}
		else if (dap[5] == 1) {
			printf("┃    %s %s\n", lie_ch[5], meaning[5]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[40] == 1) {
			printf("┃    %s %s\n", lie_ch[40], meaning[40]);
		}
		else if (dap[6] == 1) {
			printf("┃    %s %s\n", lie_ch[6], meaning[6]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[41] == 1) {
			printf("┃    %s %s\n", lie_ch[41], meaning[41]);
		}
		else if (dap[7] == 1) {
			printf("┃    %s %s\n", lie_ch[7], meaning[7]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[42] == 1) {
			printf("┃    %s %s\n", lie_ch[42], meaning[42]);
		}
		else if (dap[8] == 1) {
			printf("┃    %s %s\n", lie_ch[8], meaning[8]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[43] == 1) {
			printf("┃    %s %s\n", lie_ch[43], meaning[43]);
		}
		else if (dap[9] == 1) {
			printf("┃    %s %s\n", lie_ch[9], meaning[9]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[44] == 1) {
			printf("┃    %s %s\n", lie_ch[44], meaning[44]);
		}
		else if (dap[10] == 1) {
			printf("┃    %s %s\n", lie_ch[10], meaning[10]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[45] == 1) {
			printf("┃    %s %s\n", lie_ch[45], meaning[45]);
		}
		else if (dap[11] == 1) {
			printf("┃    %s %s\n", lie_ch[11], meaning[11]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[46] == 1) {
			printf("┃    %s %s\n", lie_ch[46], meaning[46]);
		}
		else if (dap[12] == 1) {
			printf("┃    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ");
		if (dap[47] == 1) {
			printf("┃    %s %s\n", lie_ch[47], meaning[47]);
		}
		else if (dap[13] == 1) {
			printf("┃    %s %s\n", lie_ch[13], meaning[13]);
		}
		else
			printf("┃\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[48] == 1) {
			printf("┃    %s %s\n", lie_ch[48], meaning[48]);
		}
		else if (dap[14] == 1) {
			printf("┃    %s %s\n", lie_ch[14], meaning[14]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[15] == 1) {
			printf("    %s %s\n", lie_ch[15], meaning[15]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[16] == 1) {
			printf("┃    %s %s\n", ch[16], meaning[16]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[12] == 1) {
			printf("    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[17] == 1) {
			printf("┃    %s %s\n", ch[17], meaning[17]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[18] == 1) {
			printf("    %s %s\n", lie_ch[18], meaning[18]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[19] == 1) {
			printf("┃    %s %s\n", ch[19], meaning[19]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[20] == 1) {
			printf("    %s %s\n", lie_ch[20], meaning[20]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[21] == 1) {
			printf("┃    %s %s\n", ch[21], meaning[21]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[22] == 1) {
			printf("    %s %s\n", lie_ch[22], meaning[22]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[23] == 1) {
			printf("┃    %s %s\n", ch[23], meaning[23]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[24] == 1) {
			printf("    %s %s\n", lie_ch[24], meaning[24]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[25] == 1) {
			printf("┃    %s %s\n", ch[25], meaning[25]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[26] == 1) {
			printf("    %s %s\n", lie_ch[26], meaning[26]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[27] == 1) {
			printf("┃    %s %s\n", ch[27], meaning[27]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[28] == 1) {
			printf("    %s %s\n", lie_ch[28], meaning[28]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[29] == 1) {
			printf("┃    %s %s\n", ch[29], meaning[29]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[30] == 1) {
			printf("    %s %s\n", lie_ch[30], meaning[30]);
		}
		else
			printf("\n");
		printf("┃    ");
		for (int j = 1; j < SIZE - 1; j++) {
			if (hag == i && yul == j) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (compare_map[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%c    ", map[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
				printf("%c    ", map[i][j]);
		}
		i++;
		if (dap[31] == 1) {
			printf("┃    %s %s\n", ch[31], meaning[31]);
		}
		else
			printf("┃\n");
		printf("┃                                                                                                                  ┃");
		if (dap[32] == 1) {
			printf("    %s %s\n", lie_ch[32], meaning[32]);
		}
		else
			printf("\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		if (dap[33] == 1) {
			printf("    %s %s\n", lie_ch[33], meaning[33]);
		}
		else
			printf("\n");
	}
}

void input() {     //단어를 저장하는 함수
	char arr[20] = { "" };
	char arr2[70] = { "" };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										   단어(10단어내, 영어로) :  ");
	scanf_s("%s", arr, 20);     //저장할 단어를 입력
	printf("											뜻 :  ");
	scanf_s("%s", arr2, 70);     //저장할 단어 뜻 입력
	FILE* fp;
	fp = fopen("ch.txt", "a");     //단어 파일을(ch.txt) 수정으로 연다(a)
	fputs(arr, fp);      //단어 저장
	fputs("/", fp);      // 단어 뒤에 구별자(/) 저장
	fclose(fp);         //단어 파일 닫기
	fp = fopen("meaning.txt", "a");     //뜻 파일을(meaning.txt) 수정으로 연다(a)
	fputs(arr2, fp);    //뜻 저장
	fputs("/", fp);     //뜻 뒤에 구별자(/) 저장
	fclose(fp);      //뜻 파일 닫기
}

void Create(char Writting[])
{
	//검증단계에서 검증된 글자와 위치를 대입함
	switch (direction)   //방향에 맞춰서 8가지 방향으로 대입을 한다
	{
	case 0:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location - kbs] = Writting[kbs];    //맵에 영어를 넣고
			location[hag_location - kbs][yul_location - kbs] = 1;    //해당 위치 맵을 1로 설정
		}
		break;
	case 1:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location] = Writting[kbs];   //맵의 영어를 넣고 
			location[hag_location - kbs][yul_location] = 1;   //해당위치 맵을 1로 설정 (밑의 것도 같은 방식)
		}
		break;
	case 2:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location + kbs] = Writting[kbs];
			location[hag_location - kbs][yul_location + kbs] = 1;
		}
		break;
	case 3:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location][yul_location - kbs] = Writting[kbs];
			location[hag_location][yul_location - kbs] = 1;
		}
		break;
	case 4:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location][yul_location + kbs] = Writting[kbs];
			location[hag_location][yul_location + kbs] = 1;
		}
		break;
	case 5:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location + kbs][yul_location - kbs] = Writting[kbs];
			location[hag_location + kbs][yul_location - kbs] = 1;
		}
		break;
	case 6:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location + kbs][yul_location - kbs] = Writting[kbs];
			location[hag_location + kbs][yul_location - kbs] = 1;
		}
		break;
	case 7:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location + kbs][yul_location + kbs] = Writting[kbs];
			location[hag_location + kbs][yul_location + kbs] = 1;
		}
		break;
	}

}

void Compare_map_create()
{
	for (int i = 0; i < SIZE; i++) {     //검증하기 위한 0으로만 이루어진 검증맵의 맨 가장자리를 1로 설정
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {
				compare_map[i][j] = 1;
			}
			else
				compare_map[i][j] = 0;   //그외는 0으로 설정
		}
	}
}

void Play() {   //게임 플레이
	timer = 100;
	int count = 0;    // 문자열의 순서 지정
	char c;   // 방향키나 c,d입력을 위한 변수
	while (timer > 0 && num > num_count) { // 타이며가 0이 되거나 글자를 다 찾을 때까지 반복
		if (_kbhit()) {   //만약 입력을 받으면
			c = _getch();

			if (c == -32) {
				c = _getch();
				switch (c) {
				case RIGHT:   //오른쪽 방향키일 경우
					if (yul != 22)    //맵의 가장자리가 아니면
						yul++;   //행을 오른쪽으로
					break;
				case LEFT:    //왼쪽 방향키일 경우
					if (yul != 1)    // 맵의 가장자리가 아니면
						yul--;    //행을 왼쪽으로
					break;
				case UP:   //위쪽 방향키일 경우
					if (hag != 1)    //맵의 가장자리 아니면
						hag--;     //열을 위로
					break;
				case DOWN:    //아래쪽 방향키일 경우
					if (hag != 22)    //맵의 가장자리가 아니면
						hag++;     //열을 아래로
					break;
				}
			}

			else if (c == 'c') {   //c(선택)를 입력받으면
				if (first == 0) {
					first++;
					beforhag = hag, beforyul = yul;
					compare_map[hag][yul] = 1;      //가짜 맵의 해당 칸을 1로
					answer[count] = map[hag][yul];   //답의 count에 맵의 영어글자를 대입
					count++;  //count는 증가
					for (int i = 0; i < 49; i++) {     //저장되어 있는 답들에 대입해서
						int kl;
						kl = strcmp(answer, ch[i]);
						if (kl == 0) {    //답이 맞는게 있다면
							first = 0;
							num_count++;     //찾을 때마다 찾은 함수 플러스
							timer += 10;    //타이머 10증가
							dap[i] = 1;    //답의 해당 영어를 1로 설정
							count = 0;     //카운트는 다시 0
							for (int nm = 0; nm < 10; nm++) {
								answer[nm] = '\0';    //answer를 공백으로 다시 설정
							}
							break;
						}
					}
				}
				else {
					afterhag = hag, afteryul = yul;
					if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
						compare_map[hag][yul] = 1;      //가짜 맵의 해당 칸을 1로
						answer[count] = map[hag][yul];   //답의 count에 맵의 영어글자를 대입
						beforhag = afterhag, beforyul = afteryul;
						count++;  //count는 증가
						for (int i = 0; i < 49; i++) {     //저장되어 있는 답들에 대입해서
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //답이 맞는게 있다면
								first = 0;
								num_count++;     //찾을 때마다 찾은 함수 플러스
								timer += 10;    //타이머 10증가
								dap[i] = 1;    //답의 해당 영어를 1로 설정
								count = 0;     //카운트는 다시 0
								for (int nm = 0; nm < 10; nm++) {
									answer[nm] = '\0';    //answer를 공백으로 다시 설정
								}
								break;
							}
						}
					}
				}
			}

			else if (c == 'd') {    //d가 입력되면
				first = 0;
				compare_map[hag][yul] = 0;     //지금 위치를 0으로 설정하고
				--count;     //카운트를 마이너스해서 이전 자리로 이동
				answer[count] = ' ';       //답에 입력됐던 걸 무효
			}
			output();
		}    //입력 받으면 바뀐 값으로 출력

		else {
			output();
		}    //아니면 그냥 출력

		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {     //1초 카운트를 위한 함수
			if (_kbhit()) {     //1초 카운트중 입력받으면
				c = _getch();

				if (c == -32) {
					c = _getch();
					switch (c) {
					case RIGHT:    //오른쪽 방향키일 경우
						if (yul != 22)    //맵의 끝이 아니면
							yul++;    //행을 오른쪽으로 이동
						break;
					case LEFT:     //왼쪽 방향키일 경우
						if (yul != 1)    //맵의 끝이 아니면
							yul--;     //행을 왼쪽으로 이동
						break;
					case UP:     //위쪽 방향키일 경우
						if (hag != 1)    //맵의 끝이 아니면
							hag--;     //열을 위로 이동
						break;
					case DOWN:     //아래쪽 방향키일 경우
						if (hag != 22)     //맵의 끝이 아니면
							hag++;     //열을 아랫쪽으로 이동
						break;
					}
				}

				else if (c == 'c') {   //c(선택)를 입력받으면
					if (first == 0) {
						first++;
						beforhag = hag, beforyul = yul;
						compare_map[hag][yul] = 1;      //가짜 맵의 해당 칸을 1로
						answer[count] = map[hag][yul];   //답의 count에 맵의 영어글자를 대입
						count++;  //count는 증가
						for (int i = 0; i < 49; i++) {     //저장되어 있는 답들에 대입해서
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //답이 맞는게 있다면
								first = 0;
								num_count++;     //찾을 때마다 찾은 함수 플러스
								timer += 10;    //타이머 10증가
								dap[i] = 1;    //답의 해당 영어를 1로 설정
								count = 0;     //카운트는 다시 0
								for (int nm = 0; nm < 8; nm++) {
									answer[nm] = '\0';    //answer를 공백으로 다시 설정
								}
								break;
							}
						}
					}
					else {
						afterhag = hag, afteryul = yul;
						if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
							compare_map[hag][yul] = 1;      //가짜 맵의 해당 칸을 1로
							answer[count] = map[hag][yul];   //답의 count에 맵의 영어글자를 대입
							beforhag = afterhag, beforyul = afteryul;
							count++;  //count는 증가
							for (int i = 0; i < 49; i++) {     //저장되어 있는 답들에 대입해서
								int kl;
								kl = strcmp(answer, ch[i]);
								if (kl == 0) {    //답이 맞는게 있다면
									first = 0;
									num_count++;     //찾을 때마다 찾은 함수 플러스
									timer += 10;    //타이머 10증가
									dap[i] = 1;    //답의 해당 영어를 1로 설정
									count = 0;     //카운트는 다시 0
									for (int nm = 0; nm < 8; nm++) {
										answer[nm] = '\0';    //answer를 공백으로 다시 설정
									}
									break;
								}
							}
						}
					}
				}

				else if (c == 'd') {
					first = 0;
					compare_map[hag][yul] = 0;
					--count;
					answer[count] = ' ';
				}
				output();
			}    //입력 받으면 바뀐 값으로 출력

		}
		timer--;   //1초가 지나면 카운트 감소
	}
	Ending_screan();    //시간이 끝나거나 다 맞추면 엔딩 크래딧 출력
}



int main()
{
	int end = 0;
	for (int kod = 0; kod < 2; kod++) {
		// 시작화면 2초동안 화면을 키우라는 글 출력
		printf("화면을 크게 만들어 주세요.");
		Sleep(1000);
		system("cls");
	}
	while (1) {    //기본 메뉴 창 계속 반복됨
		system("cls");
		int iu = menu();   //메뉴 함수로 이동, 입력받은 메뉴 번호를 ju에 저장
		switch (iu) {      //입력받은 메뉴 번호에 따라 화면 실행
		case 1:   //단어 기부 선택시 input함수로 이동, switch문 나감
			input();
			break;
		case 2:    //공부 하기 선택시
			gets();    //gets함수로 이동
			num = Num();   //Num함수에서 수 입력 받음
			list();   //list함수로 이동
			Map_create();   // Map_create함수로 이동
			Compare_map_create();  //Compare_map_create함수로 이동
			Play();  //play함수로 이동
			break;
		case 3:     //종료 선택시 
			end = 1;   //엔드에 1 대입
		}
		if (end == 1)   // 만약 엔드가 1이면
			break;    //while문 탈출, 단어 찾기 종료
	}
	system("cls");
	return 0;
}