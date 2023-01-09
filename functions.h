#ifndef PROJECT_NUMBER_3_FUNCTIONS_H
#define PROJECT_NUMBER_3_FUNCTIONS_H

#define FOREGROUND_WHITE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define color_switch_red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
#define color_switch_green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
#define color_switch_blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
#define color_switch_white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_WHITE);
#define color_switch_pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_BLUE) | FOREGROUND_INTENSITY );
#define clear system("cls");

void wait();
void to_lower(char *string);

#endif //PROJECT_NUMBER_3_FUNCTIONS_H
