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
char lie_ch[49][10] = { "" };  //ã�� �Լ� ������� ���ؼ�
char meaning[49][70] = { "" };
int num;   //ã�� �Լ� ����
int num_count = 0; // ã�� �Լ� �߿��� ��� ã�Ҵ��� Ȯ��
int arr[13] = { 0, };  //ã�� �Լ� ��ȣ
int location[SIZE][SIZE] = { 0, }; // ��ǥ ��ġ(��ġ�� �ʰ� ����)
int pagenumber = 0;  //number�� ������ �ε��� ��ȣ�� ����
int Length; //���ڿ� ���� 
int direction;  //����
int hag_location = 0; // ó�� ���� ���� ��ġ
int yul_location = 0; // ó�� ���� ���� ��ġ
int hag = 1, yul = 1;
int timer;
int dap[49] = { 947294, 1556, 456, 587, 4669, 1445, 456, 4587, 5498, 6512, 2147,2147,2147, 2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147,2147, 1546, 8522 };       // �������� �ƴ��� �˾Ƴ��� ����
char answer[10] = { "\0" };  // ���� �̾Ƴ��� ���ڿ�
int first = 0;
int beforhag, beforyul, afterhag, afteryul;
int hy;


void gets() {
	hy = 0;
	FILE* fp;
	fp = fopen("ch.txt", "r");    //�ܾ� ������ �б���� ����
	char arr[3000];
	char hu[5000];
	fgets(arr, 2000, fp);    //arr���� �ܾ� ������ ���ڵ� ����
	int check = 0, tn = 0, td = 0;
	for (int i = 0; arr[i] != NULL; i++) {     //arr�� ������ ���� �ݺ�
		if (arr[i] == '/') {     //���� /�� ������
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
	// �޴� ����â
	int iu;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                                                  <<�޴��� ������ �ּ���>>\n");
	printf("                                                                                       1. �ܾ� ����ϱ�\n");
	printf("                                                                                         2. �����ϱ�\n");
	printf("                                                                                         3. ��������\n");
	printf("                                                                                            >> ");
	scanf_s("%d", &iu);
	system("cls");
	return iu;
	// �Է¹��� �޴� ��ȣ�� ��ȯ
}

int Num()
{
	int n;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										ã�� �ܾ��� ���� ������ �ּ���(1 ~ %d)\n", hy);
	printf("										        	>> ");
	scanf_s("%d", &n);
	system("cls");
	return n;
}

void list()
{
	int kigram[49] = { 0, };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");     //��� ���
	printf("										==== ����� ã�� �Լ� ���� ====\n");
	printf("		 (1) : %10s  (2) : %10s  (3) : %10s  (4) : %10s  (5) : %10s  (6) : %10s  (7) : %10s  (8) : %10s\n", ch[0], ch[1], ch[2], ch[3], ch[4], ch[5], ch[6], ch[7]);
	printf("		 (9) : %10s (10) : %10s (11) : %10s (12) : %10s (13) : %10s (14) : %10s (15) : %10s (16) : %10s\n", ch[8], ch[9], ch[10], ch[11], ch[12], ch[13], ch[14], ch[15]);
	printf("		(17) : %10s (18) : %10s (19) : %10s (20) : %10s (21) : %10s (22) : %10s (23) : %10s (24) : %10s\n", ch[16], ch[17], ch[18], ch[19], ch[20], ch[21], ch[22], ch[23]);
	printf("		(25) : %10s (26) : %10s (27) : %10s (28) : %10s (29) : %10s (30) : %10s (31) : %10s (32) : %10s\n", ch[24], ch[25], ch[26], ch[27], ch[28], ch[29], ch[30], ch[31]);
	printf("		(33) : %10s (34) : %10s (35) : %10s (36) : %10s (37) : %10s (38) : %10s (39) : %10s (40) : %10s\n", ch[32], ch[33], ch[34], ch[35], ch[36], ch[37], ch[38], ch[39]);
	printf("		(41) : %10s (42) : %10s (43) : %10s (44) : %10s (45) : %10s (46) : %10s (47) : %10s (48) : %10s\n", ch[40], ch[41], ch[42], ch[43], ch[44], ch[45], ch[46], ch[47]);


	int count;
	for (count = 0; count < num; count++) {  //ã�� �Լ� ������ŭ �ݺ�
		scanf_s("%d", &arr[count]);    //�Է¹޾Ƽ� arr�� ���ʴ�� ����
		kigram[arr[count] - 1] = 1;
	}
	system("cls");

	for (int i = 0; i < 49; i++) {        // �ܾ�� ���߿���
		if (kigram[i] == 0) {             // ������ �ܾ �ƴϸ�
			for (int j = 0; j < 10; j++) {   //�ܾ �������� 
				if (j == 0)
					lie_ch[i][j] = '\0';
				else
					lie_ch[i][j] = ' ';
			}
			for (int j = 0; j < 70; j++) {    //���� ��������
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
				map[i][j] = '#';    //���� �����ڸ��� #���� ����
			}
			else
				map[i][j] = rand() % 26 + 97;    //�׿ܴ� ���� ������ڷ� ����
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {    //location�� �����ڸ��� 1�μ���
				location[i][j] = 1;
			}
			else
				location[i][j] = 0;     //�׿ܴ� 0���� ����
		}
	}




	for (int p = 0; p < num; p++) {
		Find(ch[arr[p] - 1]);     //��ġ ���� �ܰ�
		Create(ch[arr[p] - 1]);    //�� ���� �ܰ�
	}


}
/* ����(direction)
  0 1 2
  3 n 4
  5 6 7
*/
void Find(char Writing[]) // Ȯ���ϴ� �ܰ�
{
	int Verification;  //�����ϴ� ����
	Length = strlen(Writing);
	while (1) {
		Verification = 0;
		hag_location = rand() % 21 + 1;
		yul_location = rand() % 21 + 1;
		direction = rand() % 8;  //���⿡ ���� 
		switch (direction)   //���� ���� ��ų� �ٸ� ������ġ�� ��ġ�� �缳��
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
			break;   //Ȯ�ε� ������ġ�� ������ Ȯ����
	}
}

void output() {
	system("cls");   //ȭ�� ����
	for (int i = 1; i < SIZE - 1;) {
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������                                            �������� <���� �ð�>��������\n");
		printf("��                                                                                                                  ��");
		printf(" ������ �ܾ� : %20s         ��", answer);
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
		printf("��\n");
		printf("��    ");
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
		printf("��                                            ����������������������������������������\n");
		printf("��                                                                                                                  �� �������������������������������������������������������������� <���� ����>����������������������������������������������������������\n");
		printf("��    ");
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
		printf("�� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[0], lie_ch[1], lie_ch[2], lie_ch[3], lie_ch[4], lie_ch[5], lie_ch[6]);
		printf("��                                                                                                                  �� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[7], lie_ch[8], lie_ch[9], lie_ch[10], lie_ch[11], lie_ch[12], lie_ch[13]);
		printf("��    ");
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
		printf("�� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[14], lie_ch[15], lie_ch[16], lie_ch[17], lie_ch[18], lie_ch[19], lie_ch[20]);
		printf("��                                                                                                                  �� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[21], lie_ch[22], lie_ch[23], lie_ch[24], lie_ch[25], lie_ch[26], lie_ch[27]);
		printf("��    ");
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
		printf("�� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[28], lie_ch[29], lie_ch[30], lie_ch[31], lie_ch[32], lie_ch[33], lie_ch[34]);
		printf("��                                                                                                                  �� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[35], lie_ch[36], lie_ch[37], lie_ch[38], lie_ch[39], lie_ch[40], lie_ch[41]);
		printf("��    ");
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
		printf("�� ��%10s%10s%10s%10s%10s%10s%10s��\n", lie_ch[42], lie_ch[43], lie_ch[44], lie_ch[45], lie_ch[46], lie_ch[47], lie_ch[48]);
		printf("��                                                                                                                  �� ������������������������������������������������������������������������������������������������������������������������������������������������");

		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[34], meaning[34]);
		}
		else if (dap[0] == 1) {
			printf("��    %s %s\n", lie_ch[0], meaning[0]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[35] == 1) {
			printf("��    %s %s\n", lie_ch[35], meaning[35]);
		}
		else if (dap[1] == 1) {
			printf("��    %s %s\n", lie_ch[1], meaning[1]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[36], meaning[36]);
		}
		else if (dap[2] == 1) {
			printf("��    %s %s\n", lie_ch[2], meaning[2]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[37] == 1) {
			printf("��    %s %s\n", lie_ch[37], meaning[37]);
		}
		else if (dap[3] == 1) {
			printf("��    %s %s\n", lie_ch[3], meaning[3]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[38], meaning[38]);
		}
		else if (dap[4] == 1) {
			printf("��    %s %s\n", lie_ch[4], meaning[4]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[39] == 1) {
			printf("��    %s %s\n", lie_ch[39], meaning[39]);
		}
		else if (dap[5] == 1) {
			printf("��    %s %s\n", lie_ch[5], meaning[5]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[40], meaning[40]);
		}
		else if (dap[6] == 1) {
			printf("��    %s %s\n", lie_ch[6], meaning[6]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[41] == 1) {
			printf("��    %s %s\n", lie_ch[41], meaning[41]);
		}
		else if (dap[7] == 1) {
			printf("��    %s %s\n", lie_ch[7], meaning[7]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[42], meaning[42]);
		}
		else if (dap[8] == 1) {
			printf("��    %s %s\n", lie_ch[8], meaning[8]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[43] == 1) {
			printf("��    %s %s\n", lie_ch[43], meaning[43]);
		}
		else if (dap[9] == 1) {
			printf("��    %s %s\n", lie_ch[9], meaning[9]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[44], meaning[44]);
		}
		else if (dap[10] == 1) {
			printf("��    %s %s\n", lie_ch[10], meaning[10]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[45] == 1) {
			printf("��    %s %s\n", lie_ch[45], meaning[45]);
		}
		else if (dap[11] == 1) {
			printf("��    %s %s\n", lie_ch[11], meaning[11]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[46], meaning[46]);
		}
		else if (dap[12] == 1) {
			printf("��    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ");
		if (dap[47] == 1) {
			printf("��    %s %s\n", lie_ch[47], meaning[47]);
		}
		else if (dap[13] == 1) {
			printf("��    %s %s\n", lie_ch[13], meaning[13]);
		}
		else
			printf("��\n");
		printf("��    ");
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
			printf("��    %s %s\n", lie_ch[48], meaning[48]);
		}
		else if (dap[14] == 1) {
			printf("��    %s %s\n", lie_ch[14], meaning[14]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[15] == 1) {
			printf("    %s %s\n", lie_ch[15], meaning[15]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[16], meaning[16]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[12] == 1) {
			printf("    %s %s\n", lie_ch[12], meaning[12]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[17], meaning[17]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[18] == 1) {
			printf("    %s %s\n", lie_ch[18], meaning[18]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[19], meaning[19]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[20] == 1) {
			printf("    %s %s\n", lie_ch[20], meaning[20]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[21], meaning[21]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[22] == 1) {
			printf("    %s %s\n", lie_ch[22], meaning[22]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[23], meaning[23]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[24] == 1) {
			printf("    %s %s\n", lie_ch[24], meaning[24]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[25], meaning[25]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[26] == 1) {
			printf("    %s %s\n", lie_ch[26], meaning[26]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[27], meaning[27]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[28] == 1) {
			printf("    %s %s\n", lie_ch[28], meaning[28]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[29], meaning[29]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[30] == 1) {
			printf("    %s %s\n", lie_ch[30], meaning[30]);
		}
		else
			printf("\n");
		printf("��    ");
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
			printf("��    %s %s\n", ch[31], meaning[31]);
		}
		else
			printf("��\n");
		printf("��                                                                                                                  ��");
		if (dap[32] == 1) {
			printf("    %s %s\n", lie_ch[32], meaning[32]);
		}
		else
			printf("\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		if (dap[33] == 1) {
			printf("    %s %s\n", lie_ch[33], meaning[33]);
		}
		else
			printf("\n");
	}
}

void input() {     //�ܾ �����ϴ� �Լ�
	char arr[20] = { "" };
	char arr2[70] = { "" };
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("										   �ܾ�(10�ܾ, �����) :  ");
	scanf_s("%s", arr, 20);     //������ �ܾ �Է�
	printf("											�� :  ");
	scanf_s("%s", arr2, 70);     //������ �ܾ� �� �Է�
	FILE* fp;
	fp = fopen("ch.txt", "a");     //�ܾ� ������(ch.txt) �������� ����(a)
	fputs(arr, fp);      //�ܾ� ����
	fputs("/", fp);      // �ܾ� �ڿ� ������(/) ����
	fclose(fp);         //�ܾ� ���� �ݱ�
	fp = fopen("meaning.txt", "a");     //�� ������(meaning.txt) �������� ����(a)
	fputs(arr2, fp);    //�� ����
	fputs("/", fp);     //�� �ڿ� ������(/) ����
	fclose(fp);      //�� ���� �ݱ�
}

void Create(char Writting[])
{
	//�����ܰ迡�� ������ ���ڿ� ��ġ�� ������
	switch (direction)   //���⿡ ���缭 8���� �������� ������ �Ѵ�
	{
	case 0:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location - kbs] = Writting[kbs];    //�ʿ� ��� �ְ�
			location[hag_location - kbs][yul_location - kbs] = 1;    //�ش� ��ġ ���� 1�� ����
		}
		break;
	case 1:
		for (int kbs = 0; kbs < Length; kbs++) {
			map[hag_location - kbs][yul_location] = Writting[kbs];   //���� ��� �ְ� 
			location[hag_location - kbs][yul_location] = 1;   //�ش���ġ ���� 1�� ���� (���� �͵� ���� ���)
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
	for (int i = 0; i < SIZE; i++) {     //�����ϱ� ���� 0���θ� �̷���� �������� �� �����ڸ��� 1�� ����
		for (int j = 0; j < SIZE; j++) {
			if (i == 0 || i == 23 || j == 0 || j == 23) {
				compare_map[i][j] = 1;
			}
			else
				compare_map[i][j] = 0;   //�׿ܴ� 0���� ����
		}
	}
}

void Play() {   //���� �÷���
	timer = 100;
	int count = 0;    // ���ڿ��� ���� ����
	char c;   // ����Ű�� c,d�Է��� ���� ����
	while (timer > 0 && num > num_count) { // Ÿ�̸簡 0�� �ǰų� ���ڸ� �� ã�� ������ �ݺ�
		if (_kbhit()) {   //���� �Է��� ������
			c = _getch();

			if (c == -32) {
				c = _getch();
				switch (c) {
				case RIGHT:   //������ ����Ű�� ���
					if (yul != 22)    //���� �����ڸ��� �ƴϸ�
						yul++;   //���� ����������
					break;
				case LEFT:    //���� ����Ű�� ���
					if (yul != 1)    // ���� �����ڸ��� �ƴϸ�
						yul--;    //���� ��������
					break;
				case UP:   //���� ����Ű�� ���
					if (hag != 1)    //���� �����ڸ� �ƴϸ�
						hag--;     //���� ����
					break;
				case DOWN:    //�Ʒ��� ����Ű�� ���
					if (hag != 22)    //���� �����ڸ��� �ƴϸ�
						hag++;     //���� �Ʒ���
					break;
				}
			}

			else if (c == 'c') {   //c(����)�� �Է¹�����
				if (first == 0) {
					first++;
					beforhag = hag, beforyul = yul;
					compare_map[hag][yul] = 1;      //��¥ ���� �ش� ĭ�� 1��
					answer[count] = map[hag][yul];   //���� count�� ���� ������ڸ� ����
					count++;  //count�� ����
					for (int i = 0; i < 49; i++) {     //����Ǿ� �ִ� ��鿡 �����ؼ�
						int kl;
						kl = strcmp(answer, ch[i]);
						if (kl == 0) {    //���� �´°� �ִٸ�
							first = 0;
							num_count++;     //ã�� ������ ã�� �Լ� �÷���
							timer += 10;    //Ÿ�̸� 10����
							dap[i] = 1;    //���� �ش� ��� 1�� ����
							count = 0;     //ī��Ʈ�� �ٽ� 0
							for (int nm = 0; nm < 10; nm++) {
								answer[nm] = '\0';    //answer�� �������� �ٽ� ����
							}
							break;
						}
					}
				}
				else {
					afterhag = hag, afteryul = yul;
					if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
						compare_map[hag][yul] = 1;      //��¥ ���� �ش� ĭ�� 1��
						answer[count] = map[hag][yul];   //���� count�� ���� ������ڸ� ����
						beforhag = afterhag, beforyul = afteryul;
						count++;  //count�� ����
						for (int i = 0; i < 49; i++) {     //����Ǿ� �ִ� ��鿡 �����ؼ�
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //���� �´°� �ִٸ�
								first = 0;
								num_count++;     //ã�� ������ ã�� �Լ� �÷���
								timer += 10;    //Ÿ�̸� 10����
								dap[i] = 1;    //���� �ش� ��� 1�� ����
								count = 0;     //ī��Ʈ�� �ٽ� 0
								for (int nm = 0; nm < 10; nm++) {
									answer[nm] = '\0';    //answer�� �������� �ٽ� ����
								}
								break;
							}
						}
					}
				}
			}

			else if (c == 'd') {    //d�� �ԷµǸ�
				first = 0;
				compare_map[hag][yul] = 0;     //���� ��ġ�� 0���� �����ϰ�
				--count;     //ī��Ʈ�� ���̳ʽ��ؼ� ���� �ڸ��� �̵�
				answer[count] = ' ';       //�信 �Էµƴ� �� ��ȿ
			}
			output();
		}    //�Է� ������ �ٲ� ������ ���

		else {
			output();
		}    //�ƴϸ� �׳� ���

		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {     //1�� ī��Ʈ�� ���� �Լ�
			if (_kbhit()) {     //1�� ī��Ʈ�� �Է¹�����
				c = _getch();

				if (c == -32) {
					c = _getch();
					switch (c) {
					case RIGHT:    //������ ����Ű�� ���
						if (yul != 22)    //���� ���� �ƴϸ�
							yul++;    //���� ���������� �̵�
						break;
					case LEFT:     //���� ����Ű�� ���
						if (yul != 1)    //���� ���� �ƴϸ�
							yul--;     //���� �������� �̵�
						break;
					case UP:     //���� ����Ű�� ���
						if (hag != 1)    //���� ���� �ƴϸ�
							hag--;     //���� ���� �̵�
						break;
					case DOWN:     //�Ʒ��� ����Ű�� ���
						if (hag != 22)     //���� ���� �ƴϸ�
							hag++;     //���� �Ʒ������� �̵�
						break;
					}
				}

				else if (c == 'c') {   //c(����)�� �Է¹�����
					if (first == 0) {
						first++;
						beforhag = hag, beforyul = yul;
						compare_map[hag][yul] = 1;      //��¥ ���� �ش� ĭ�� 1��
						answer[count] = map[hag][yul];   //���� count�� ���� ������ڸ� ����
						count++;  //count�� ����
						for (int i = 0; i < 49; i++) {     //����Ǿ� �ִ� ��鿡 �����ؼ�
							int kl;
							kl = strcmp(answer, ch[i]);
							if (kl == 0) {    //���� �´°� �ִٸ�
								first = 0;
								num_count++;     //ã�� ������ ã�� �Լ� �÷���
								timer += 10;    //Ÿ�̸� 10����
								dap[i] = 1;    //���� �ش� ��� 1�� ����
								count = 0;     //ī��Ʈ�� �ٽ� 0
								for (int nm = 0; nm < 8; nm++) {
									answer[nm] = '\0';    //answer�� �������� �ٽ� ����
								}
								break;
							}
						}
					}
					else {
						afterhag = hag, afteryul = yul;
						if (map[beforhag - 1][beforyul] == map[afterhag][afteryul] || map[beforhag + 1][beforyul] == map[afterhag][afteryul] || map[beforhag][beforyul - 1] == map[afterhag][afteryul] || map[beforhag][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul - 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag - 1][beforyul + 1] == map[afterhag][afteryul] || map[beforhag + 1][beforyul - 1] == map[afterhag][afteryul]) {
							compare_map[hag][yul] = 1;      //��¥ ���� �ش� ĭ�� 1��
							answer[count] = map[hag][yul];   //���� count�� ���� ������ڸ� ����
							beforhag = afterhag, beforyul = afteryul;
							count++;  //count�� ����
							for (int i = 0; i < 49; i++) {     //����Ǿ� �ִ� ��鿡 �����ؼ�
								int kl;
								kl = strcmp(answer, ch[i]);
								if (kl == 0) {    //���� �´°� �ִٸ�
									first = 0;
									num_count++;     //ã�� ������ ã�� �Լ� �÷���
									timer += 10;    //Ÿ�̸� 10����
									dap[i] = 1;    //���� �ش� ��� 1�� ����
									count = 0;     //ī��Ʈ�� �ٽ� 0
									for (int nm = 0; nm < 8; nm++) {
										answer[nm] = '\0';    //answer�� �������� �ٽ� ����
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
			}    //�Է� ������ �ٲ� ������ ���

		}
		timer--;   //1�ʰ� ������ ī��Ʈ ����
	}
	Ending_screan();    //�ð��� �����ų� �� ���߸� ���� ũ���� ���
}



int main()
{
	int end = 0;
	for (int kod = 0; kod < 2; kod++) {
		// ����ȭ�� 2�ʵ��� ȭ���� Ű���� �� ���
		printf("ȭ���� ũ�� ����� �ּ���.");
		Sleep(1000);
		system("cls");
	}
	while (1) {    //�⺻ �޴� â ��� �ݺ���
		system("cls");
		int iu = menu();   //�޴� �Լ��� �̵�, �Է¹��� �޴� ��ȣ�� ju�� ����
		switch (iu) {      //�Է¹��� �޴� ��ȣ�� ���� ȭ�� ����
		case 1:   //�ܾ� ��� ���ý� input�Լ��� �̵�, switch�� ����
			input();
			break;
		case 2:    //���� �ϱ� ���ý�
			gets();    //gets�Լ��� �̵�
			num = Num();   //Num�Լ����� �� �Է� ����
			list();   //list�Լ��� �̵�
			Map_create();   // Map_create�Լ��� �̵�
			Compare_map_create();  //Compare_map_create�Լ��� �̵�
			Play();  //play�Լ��� �̵�
			break;
		case 3:     //���� ���ý� 
			end = 1;   //���忡 1 ����
		}
		if (end == 1)   // ���� ���尡 1�̸�
			break;    //while�� Ż��, �ܾ� ã�� ����
	}
	system("cls");
	return 0;
}