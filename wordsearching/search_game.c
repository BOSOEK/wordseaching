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
char lie_ch[49][10] = { "" };  //瓊擊 л熱 綠轎溘擊 嬪п憮
char meaning[49][70] = { "" };
int num;   //瓊擊 л熱 偃熱
int num_count = 0; // 瓊擊 л熱 醞縑憮 賃偃蒂 瓊懊朝雖 �挫�
int arr[13] = { 0, };  //瓊擊 л熱 廓��
int location[SIZE][SIZE] = { 0, }; // 謝ル 嬪纂(啜纂雖 彊啪 撲薑)
int pagenumber = 0;  //number曖 撮廓營 檣筍蝶 廓�ㄧ� 雖薑
int Length; //僥濠翮 望檜 
int direction;  //寞щ
int hag_location = 0; // 籀擠 衛濛 陛煎 嬪纂
int yul_location = 0; // 籀擠 衛濛 撮煎 嬪纂
int hag = 1, yul = 1;
int timer;
int dap[49] = { 947294, 1556, 456, 587, 4669, 1445, 456, 4587, 5498, 6512, 2147,2147,2147, 2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147, 1546, 8522 };       // 薑港檣雖 嬴棋雖 憲嬴頂朝 滲熱
char answer[10] = { "\0" };  // 薑港 鉻嬴頂朝 僥濠翮
int first = 0;
int beforhag, beforyul, afterhag, afteryul;
int hy;


void gets() {
	hy = 0;
	FILE* fp;
	fp = fopen("ch.txt", "r");    //欽橫 だ橾擊 檗晦賅萄煎 翮晦
	char arr[3000];
	char hu[5000];
	fgets(arr, 2000, fp);    //arr僥縑 欽橫 だ橾曖 旋濠菟 渠殮
	int check = 0, tn = 0, td = 0;
	for (int i = 0; arr[i] != NULL; i++) {     //arr陛 部陳陽 梱雖 奩犒
		if (arr[i] == '/') {     //虜擒 /蒂 虜釭賊
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
	// 詭景 摹鷗璽
	int iu;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                                                  <<詭景蒂 摹鷗п 輿撮蹂>>\n");
	printf("                                                                                       1. 欽橫 晦睡ж晦\n");
	printf("                                                                                         2. 奢睡ж晦\n");
	printf("                                                                                         3. 啪歜謙猿\n");
	printf("                                                                                            >> ");
	scanf_s("%d", &iu);
	system("cls");
	return iu;
	// 殮溘嫡擎 詭景 廓�ㄧ� 奩��
}

int Num()
{
	int n;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										瓊擊 欽橫曖 熱蒂 雖薑п 輿撮蹂(1 ~ %d)\n", hy);
	printf("										        	>> ");
	scanf_s("%d", &n);
	system("cls");
	return n;
}

void list()
{
	int kigram[49] = { 0, };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");     //跡煙 轎溘
	printf("										==== 跡煙醞 瓊擊 л熱 雖薑 ====\n");
	printf("		 (1) : %10s  (2) : %10s  (3) : %10s  (4) : %10s  (5) : %10s  (6) : %10s  (7) : %10s  (8) : %10s\n", ch[0], ch[1], ch[2], ch[3], ch[4], ch[5], ch[6], ch[7]);
	printf("		 (9) : %10s (10) : %10s (11) : %10s (12) : %10s (13) : %10s (14) : %10s (15) : %10s (16) : %10s\n", ch[8], ch[9], ch[10], ch[11], ch[12], ch[13], ch[14], ch[15]);
	printf("		(17) : %10s (18) : %10s (19) : %10s (20) : %10s (21) : %10s (22) : %10s (23) : %10s (24) : %10s\n", ch[16], ch[17], ch[18], ch[19], ch[20], ch[21], ch[22], ch[23]);
	printf("		(25) : %10s (26) : %10s (27) : %10s (28) : %10s (29) : %10s (30) : %10s (31) : %10s (32) : %10s\n", ch[24], ch[25], ch[26], ch[27], ch[28], ch[29], ch[30], ch[31]);
	printf("		(33) : %10s (34) : %10s (35) : %10s (36) : %10s (37) : %10s (38) : %10s (39) : %10s (40) : %10s\n", ch[32], ch[33], ch[34], ch[35], ch[36], ch[37], ch[38], ch[39]);
	printf("		(41) : %10s (42) : %10s (43) : %10s (44) : %10s (45) : %10s (46) : %10s (47) : %10s (48) : %10s\n", ch[40], ch[41], ch[42], ch[43], ch[44], ch[45], ch[46], ch[47]);


	int count;
	for (count = 0; count < num; count++) {  //瓊擊 л熱 偃熱虜躑 奩犒
		scanf_s("%d", &arr[count]);    //殮溘嫡嬴憮 arr縑 離滔渠煎 盪濰
		kigram[arr[count] - 1] = 1;
	}
	system("cls");

	for (int i = 0; i < 49; i++) {        // 欽橫諦 嗆醞縑憮
		if (kigram[i] == 0) {             // 摹鷗и 欽橫陛 嬴棲賊
			for (int j = 0; j < 10; j++) {   //欽橫蒂 奢寥戲煎 
				if (j == 0)
					lie_ch[i][j] = '\0';
				else
					lie_ch[i][j] = ' ';
			}
			for (int j = 0; j < 70; j++) {    //嗆擊 奢寥戲煎
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
				map[i][j] = '#';    //裘曖 陛濰濠葬朝 #戲煎 撲薑
			}
			else
				map[i][j] = rand() % 26 + 97;    //斜諼朝 楠渾 艙橫旋濠煎 撲薑
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {    //location曖 陛濰濠葬蒂 1煎撲薑
				location[i][j] = 1;
			}
			else
				location[i][j] = 0;     //斜諼朝 0戲煎 撲薑
		}
	}




	for (int p = 0; p < num; p++) {
		Find(ch[arr[p] - 1]);     //嬪纂 匐隸 欽啗
		Create(ch[arr[p] - 1]);    //裘 薯濛 欽啗
	}


}
/* 寞щ(direction)
  0 1 2
  3 n 4
  5 6 7
*/
void Find(char Writing[]) // �挫恉炴� 欽啗
{
	int Verification;  //匐隸ж朝 滲熱
	Length = strlen(Writing);
	while (1) {
		Verification = 0;
		hag_location = rand() % 21 + 1;
		yul_location = rand() % 21 + 1;
		direction = rand() % 8;  //寞щ縑 評塭 
		switch (direction)   //裘曖 部縑 湊剪釭 棻艇 旋濠嬪纂諦 啜纂賊 營撲薑
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
			break;   //�挫庰� 衛濛嬪纂諦 寞щ檜 �捏葭�
	}
}

void output() {
	system("cls");   //�飛� 雖遺
	for (int i = 1; i < SIZE - 1;) {
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬                                            旨收收收 <陴擎 衛除>收收收旬\n");
		printf("早                                                                                                                  早");
		printf(" 摹鷗и 欽橫 : %20s         早", answer);
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
		printf("早\n");
		printf("早    ");
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
		printf("早                                            曲收收收收收收收收收收收收收收收收收收旭\n");
		printf("早                                                                                                                  早 旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收 <陴擎 旋濠>收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早    ");
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
		printf("早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[0], lie_ch[1], lie_ch[2], lie_ch[3], lie_ch[4], lie_ch[5], lie_ch[6]);
		printf("早                                                                                                                  早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[7], lie_ch[8], lie_ch[9], lie_ch[10], lie_ch[11], lie_ch[12], lie_ch[13]);
		printf("早    ");
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
		printf("早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[14], lie_ch[15], lie_ch[16], lie_ch[17], lie_ch[18], lie_ch[19], lie_ch[20]);
		printf("早                                                                                                                  早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[21], lie_ch[22], lie_ch[23], lie_ch[24], lie_ch[25], lie_ch[26], lie_ch[27]);
		printf("早    ");
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
		printf("早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[28], lie_ch[29], lie_ch[30], lie_ch[31], lie_ch[32], lie_ch[33], lie_ch[34]);
		printf("早                                                                                                                  早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[35], lie_ch[36], lie_ch[37], lie_ch[38], lie_ch[39], lie_ch[40], lie_ch[41]);
		printf("早    ");
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
		printf("早 早%10s%10s%10s%10s%10s%10s%10s早\n", lie_ch[42], lie_ch[43], lie_ch[44], lie_ch[45], lie_ch[46], lie_ch[47], lie_ch[48]);
		printf("早                                                                                                                  早 曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[34], meaning[34]);
		}
		else if (dap[0] == 1) {
			printf("早    %s %s\n", lie_ch[0], meaning[0]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[35] == 1) {
			printf("早    %s %s\n", lie_ch[35], meaning[35]);
		}
		else if (dap[1] == 1) {
			printf("早    %s %s\n", lie_ch[1], meaning[1]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[36], meaning[36]);
		}
		else if (dap[2] == 1) {
			printf("早    %s %s\n", lie_ch[2], meaning[2]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[37] == 1) {
			printf("早    %s %s\n", lie_ch[37], meaning[37]);
		}
		else if (dap[3] == 1) {
			printf("早    %s %s\n", lie_ch[3], meaning[3]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[38], meaning[38]);
		}
		else if (dap[4] == 1) {
			printf("早    %s %s\n", lie_ch[4], meaning[4]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[39] == 1) {
			printf("早    %s %s\n", lie_ch[39], meaning[39]);
		}
		else if (dap[5] == 1) {
			printf("早    %s %s\n", lie_ch[5], meaning[5]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[40], meaning[40]);
		}
		else if (dap[6] == 1) {
			printf("早    %s %s\n", lie_ch[6], meaning[6]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[41] == 1) {
			printf("早    %s %s\n", lie_ch[41], meaning[41]);
		}
		else if (dap[7] == 1) {
			printf("早    %s %s\n", lie_ch[7], meaning[7]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[42], meaning[42]);
		}
		else if (dap[8] == 1) {
			printf("早    %s %s\n", lie_ch[8], meaning[8]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[43] == 1) {
			printf("早    %s %s\n", lie_ch[43], meaning[43]);
		}
		else if (dap[9] == 1) {
			printf("早    %s %s\n", lie_ch[9], meaning[9]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[44], meaning[44]);
		}
		else if (dap[10] == 1) {
			printf("早    %s %s\n", lie_ch[10], meaning[10]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[45] == 1) {
			printf("早    %s %s\n", lie_ch[45], meaning[45]);
		}
		else if (dap[11] == 1) {
			printf("早    %s %s\n", lie_ch[11], meaning[11]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[46], meaning[46]);
		}
		else if (dap[12] == 1) {
			printf("早    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  ");
		if (dap[47] == 1) {
			printf("早    %s %s\n", lie_ch[47], meaning[47]);
		}
		else if (dap[13] == 1) {
			printf("早    %s %s\n", lie_ch[13], meaning[13]);
		}
		else
			printf("早\n");
		printf("早    ");
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
			printf("早    %s %s\n", lie_ch[48], meaning[48]);
		}
		else if (dap[14] == 1) {
			printf("早    %s %s\n", lie_ch[14], meaning[14]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[15] == 1) {
			printf("    %s %s\n", lie_ch[15], meaning[15]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[16], meaning[16]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[12] == 1) {
			printf("    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[17], meaning[17]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[18] == 1) {
			printf("    %s %s\n", lie_ch[18], meaning[18]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[19], meaning[19]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[20] == 1) {
			printf("    %s %s\n", lie_ch[20], meaning[20]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[21], meaning[21]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[22] == 1) {
			printf("    %s %s\n", lie_ch[22], meaning[22]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[23], meaning[23]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[24] == 1) {
			printf("    %s %s\n", lie_ch[24], meaning[24]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[25], meaning[25]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[26] == 1) {
			printf("    %s %s\n", lie_ch[26], meaning[26]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[27], meaning[27]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[28] == 1) {
			printf("    %s %s\n", lie_ch[28], meaning[28]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[29], meaning[29]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[30] == 1) {
			printf("    %s %s\n", lie_ch[30], meaning[30]);
		}
		else
			printf("\n");
		printf("早    ");
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
			printf("早    %s %s\n", ch[31], meaning[31]);
		}
		else
			printf("早\n");
		printf("早                                                                                                                  早");
		if (dap[32] == 1) {
			printf("    %s %s\n", lie_ch[32], meaning[32]);
		}
		else
			printf("\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		if (dap[33] == 1) {
			printf("    %s %s\n", lie_ch[33], meaning[33]);
		}
		else
			printf("\n");
	}
}

void input() {     //欽橫蒂 盪濰ж朝 л熱
	char arr[20] = { "" };
	char arr2[70] = { "" };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										   欽橫(10欽橫頂, 艙橫煎) :  ");
	scanf_s("%s", arr, 20);     //盪濰й 欽橫蒂 殮溘
	printf("											嗆 :  ");
	scanf_s("%s", arr2, 70);     //盪濰й 欽橫 嗆 殮溘
	FILE* fp;
	fp = fopen("ch.txt", "a");     //欽橫 だ橾擊(ch.txt) 熱薑戲煎 翱棻(a)
	fputs(arr, fp);      //欽橫 盪濰
	fputs("/", fp);      // 欽橫 菴縑 掘滌濠(/) 盪濰
	fclose(fp);         //欽橫 だ橾 殘晦
	fp = fopen("meaning.txt", "a");     //嗆 だ橾擊(meaning.txt) 熱薑戲煎 翱棻(a)
	fputs(arr2, fp);    //嗆 盪濰
	fputs("/", fp);     //嗆 菴縑 掘滌濠(/) 盪濰
	fclose(fp);      //嗆 だ橾 殘晦
}

void Create(char Writting[])
{
	//匐隸欽啗縑憮 匐隸脹 旋濠諦 嬪纂蒂 渠殮л
	switch (direction)   //寞щ縑 蜃醮憮 8陛雖 寞щ戲煎 渠殮擊 и棻
	{
	case 0:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location - kbs] = Writting[kbs];    //裘縑 艙橫蒂 厥堅
			location[hag_location - kbs][yul_location - kbs] = 1;    //п渡 嬪纂 裘擊 1煎 撲薑
		}
		break;
	case 1:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location] = Writting[kbs];   //裘曖 艙橫蒂 厥堅 
			location[hag_location - kbs][yul_location] = 1;   //п渡嬪纂 裘擊 1煎 撲薑 (壽曖 匙紫 偽擎 寞衝)
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
	for (int i = 0; i < SIZE; i++) {     //匐隸ж晦 嬪и 0戲煎虜 檜瑞橫霞 匐隸裘曖 裔 陛濰濠葬蒂 1煎 撲薑
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {
				compare_map[i][j] = 1;
			}
			else
				compare_map[i][j] = 0;   //斜諼朝 0戲煎 撲薑
		}
	}
}

void Play() {   //啪歜 Ы溯檜
	timer = 100;
	int count = 0;    // 僥濠翮曖 牖憮 雖薑
	char c;   // 寞щ酈釭 c,d殮溘擊 嬪и 滲熱
	while (timer > 0 && num > num_count) { // 顫檜貊陛 0檜 腎剪釭 旋濠蒂 棻 瓊擊 陽梱雖 奩犒
		if (_kbhit()) {   //虜擒 殮溘擊 嫡戲賊
			c = _getch();

			if (c == -32) {
				c = _getch();
				switch (c) {
				case RIGHT:   //螃艇薹 寞щ酈橾 唳辦
					if (yul != 22)    //裘曖 陛濰濠葬陛 嬴棲賊
						yul++;   //ч擊 螃艇薹戲煎
					break;
				case LEFT:    //豭薹 寞щ酈橾 唳辦
					if (yul != 1)    // 裘曖 陛濰濠葬陛 嬴棲賊
						yul--;    //ч擊 豭薹戲煎
					break;
				case UP:   //嬪薹 寞щ酈橾 唳辦
					if (hag != 1)    //裘曖 陛濰濠葬 嬴棲賊
						hag--;     //翮擊 嬪煎
					break;
				case DOWN:    //嬴楚薹 寞щ酈橾 唳辦
					if (hag != 22)    //裘曖 陛濰濠葬陛 嬴棲賊
						hag++;     //翮擊 嬴楚煎
					break;
				}
			}

			else if (c == 'c') {   //c(摹鷗)蒂 殮溘嫡戲賊
				if (first == 0) {
					first++;
					beforhag = hag, beforyul = yul;
					compare_map[hag][yul] = 1;      //陛瞼 裘曖 п渡 蘊擊 1煎
					answer[count] = map[hag][yul];   //港曖 count縑 裘曖 艙橫旋濠蒂 渠殮
					count++;  //count朝 隸陛
					for (int i = 0; i < 49; i++) {     //盪濰腎橫 氈朝 港菟縑 渠殮п憮
						int kl;
						kl = strcmp(answer, ch[i]);
						if (kl == 0) {    //港檜 蜃朝啪 氈棻賊
							first = 0;
							num_count++;     //瓊擊 陽葆棻 瓊擎 л熱 Ы楝蝶
							timer += 10;    //顫檜該 10隸陛
							dap[i] = 1;    //港曖 п渡 艙橫蒂 1煎 撲薑
							count = 0;     //蘋遴お朝 棻衛 0
							for (int nm = 0; nm < 10; nm++) {
								answer[nm] = '\0';    //answer蒂 奢寥戲煎 棻衛 撲薑
							}
							break;
						}
					}
				}
				else {
					afterhag = hag, afteryul = yul;
					if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
						compare_map[hag][yul] = 1;      //陛瞼 裘曖 п渡 蘊擊 1煎
						answer[count] = map[hag][yul];   //港曖 count縑 裘曖 艙橫旋濠蒂 渠殮
						beforhag = afterhag, beforyul = afteryul;
						count++;  //count朝 隸陛
						for (int i = 0; i < 49; i++) {     //盪濰腎橫 氈朝 港菟縑 渠殮п憮
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //港檜 蜃朝啪 氈棻賊
								first = 0;
								num_count++;     //瓊擊 陽葆棻 瓊擎 л熱 Ы楝蝶
								timer += 10;    //顫檜該 10隸陛
								dap[i] = 1;    //港曖 п渡 艙橫蒂 1煎 撲薑
								count = 0;     //蘋遴お朝 棻衛 0
								for (int nm = 0; nm < 10; nm++) {
									answer[nm] = '\0';    //answer蒂 奢寥戲煎 棻衛 撲薑
								}
								break;
							}
						}
					}
				}
			}

			else if (c == 'd') {    //d陛 殮溘腎賊
				first = 0;
				compare_map[hag][yul] = 0;     //雖旎 嬪纂蒂 0戲煎 撲薑ж堅
				--count;     //蘋遴お蒂 葆檜傘蝶п憮 檜瞪 濠葬煎 檜翕
				answer[count] = ' ';       //港縑 殮溘腑湍 勘 鼠��
			}
			output();
		}    //殮溘 嫡戲賊 夥莎 高戲煎 轎溘

		else {
			output();
		}    //嬴棲賊 斜傖 轎溘

		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {     //1蟾 蘋遴お蒂 嬪и л熱
			if (_kbhit()) {     //1蟾 蘋遴お醞 殮溘嫡戲賊
				c = _getch();

				if (c == -32) {
					c = _getch();
					switch (c) {
					case RIGHT:    //螃艇薹 寞щ酈橾 唳辦
						if (yul != 22)    //裘曖 部檜 嬴棲賊
							yul++;    //ч擊 螃艇薹戲煎 檜翕
						break;
					case LEFT:     //豭薹 寞щ酈橾 唳辦
						if (yul != 1)    //裘曖 部檜 嬴棲賊
							yul--;     //ч擊 豭薹戲煎 檜翕
						break;
					case UP:     //嬪薹 寞щ酈橾 唳辦
						if (hag != 1)    //裘曖 部檜 嬴棲賊
							hag--;     //翮擊 嬪煎 檜翕
						break;
					case DOWN:     //嬴楚薹 寞щ酈橾 唳辦
						if (hag != 22)     //裘曖 部檜 嬴棲賊
							hag++;     //翮擊 嬴概薹戲煎 檜翕
						break;
					}
				}

				else if (c == 'c') {   //c(摹鷗)蒂 殮溘嫡戲賊
					if (first == 0) {
						first++;
						beforhag = hag, beforyul = yul;
						compare_map[hag][yul] = 1;      //陛瞼 裘曖 п渡 蘊擊 1煎
						answer[count] = map[hag][yul];   //港曖 count縑 裘曖 艙橫旋濠蒂 渠殮
						count++;  //count朝 隸陛
						for (int i = 0; i < 49; i++) {     //盪濰腎橫 氈朝 港菟縑 渠殮п憮
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //港檜 蜃朝啪 氈棻賊
								first = 0;
								num_count++;     //瓊擊 陽葆棻 瓊擎 л熱 Ы楝蝶
								timer += 10;    //顫檜該 10隸陛
								dap[i] = 1;    //港曖 п渡 艙橫蒂 1煎 撲薑
								count = 0;     //蘋遴お朝 棻衛 0
								for (int nm = 0; nm < 8; nm++) {
									answer[nm] = '\0';    //answer蒂 奢寥戲煎 棻衛 撲薑
								}
								break;
							}
						}
					}
					else {
						afterhag = hag, afteryul = yul;
						if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
							compare_map[hag][yul] = 1;      //陛瞼 裘曖 п渡 蘊擊 1煎
							answer[count] = map[hag][yul];   //港曖 count縑 裘曖 艙橫旋濠蒂 渠殮
							beforhag = afterhag, beforyul = afteryul;
							count++;  //count朝 隸陛
							for (int i = 0; i < 49; i++) {     //盪濰腎橫 氈朝 港菟縑 渠殮п憮
								int kl;
								kl = strcmp(answer, ch[i]);
								if (kl == 0) {    //港檜 蜃朝啪 氈棻賊
									first = 0;
									num_count++;     //瓊擊 陽葆棻 瓊擎 л熱 Ы楝蝶
									timer += 10;    //顫檜該 10隸陛
									dap[i] = 1;    //港曖 п渡 艙橫蒂 1煎 撲薑
									count = 0;     //蘋遴お朝 棻衛 0
									for (int nm = 0; nm < 8; nm++) {
										answer[nm] = '\0';    //answer蒂 奢寥戲煎 棻衛 撲薑
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
			}    //殮溘 嫡戲賊 夥莎 高戲煎 轎溘

		}
		timer--;   //1蟾陛 雖釭賊 蘋遴お 馬模
	}
	Ending_screan();    //衛除檜 部釭剪釭 棻 蜃蹺賊 縛註 觼楚覃 轎溘
}



int main()
{
	int end = 0;
	for (int kod = 0; kod < 2; kod++) {
		// 衛濛�飛� 2蟾翕寰 �飛橉� 酈辦塭朝 旋 轎溘
		printf("�飛橉� 觼啪 虜菟橫 輿撮蹂.");
		Sleep(1000);
		system("cls");
	}
	while (1) {    //晦獄 詭景 璽 啗樓 奩犒脾
		system("cls");
		int iu = menu();   //詭景 л熱煎 檜翕, 殮溘嫡擎 詭景 廓�ㄧ� ju縑 盪濰
		switch (iu) {      //殮溘嫡擎 詭景 廓�ˋ� 評塭 �飛� 褒ч
		case 1:   //欽橫 晦睡 摹鷗衛 inputл熱煎 檜翕, switch僥 釭馬
			input();
			break;
		case 2:    //奢睡 ж晦 摹鷗衛
			gets();    //getsл熱煎 檜翕
			num = Num();   //Numл熱縑憮 熱 殮溘 嫡擠
			list();   //listл熱煎 檜翕
			Map_create();   // Map_createл熱煎 檜翕
			Compare_map_create();  //Compare_map_createл熱煎 檜翕
			Play();  //playл熱煎 檜翕
			break;
		case 3:     //謙猿 摹鷗衛 
			end = 1;   //縛萄縑 1 渠殮
		}
		if (end == 1)   // 虜擒 縛萄陛 1檜賊
			break;    //while僥 驍轎, 欽橫 瓊晦 謙猿
	}
	system("cls");
	return 0;
}