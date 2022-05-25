
#include <stdlib.h> 
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include<vfw.h>
#include "mmsystem.h"
#include <thread>
#include "Header.h"
#pragma comment (lib, "Winmm.lib")
int main() {
	int x = 15, y = 15, n = 961, life = 3, mx = 0, level_complete = 0, my = 0, revers = 0, conveir_direction = 0, couldown_lasers = 750, lifes = 3, conveir_speed = 1500, laser_sleep = 500, dk = 0;//объявляем переменные
	bool death = 0, god_mode=0, level_started=0;
	std::string level;
	char tutorial;
	double clock = 0;
	char button, map[31][31] = {//наше поле
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|' },
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	};
	char left_side[31][22] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
	char right_side[31][22] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '  },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' ,' ',' ' },
	};
	std::cout << "Hello user! Welcome to my game! Play in this game in fullscreen only! Type GOD for unlimmited lifes!Type I for info. Or just select the level:";
	while (level_started == 0) {
		std::cin >> level;
		if (level == "GOD") {
			god_mode = 1;
			system("cls");
			std::cout << "GOD MODE ON. Lets select the level:";
			level = "GOD";
		}
		else if (level == "1") {
			level_started = 1;
			system("cls");
			std::cout << "Level will be started in 3 seconds." << std::endl << "Good luck!";
			Sleep(3000);
		}
		else if (level == "I") {
			for (int i = 0; i < 7; i++) {
				system("cls");
				if (i == 0) {
					std::cout << "Wow! I thinking you just go to play, but i see you want know more" << std::endl;
				}
				if (i == 1) {
					std::cout << "Your target - avoid the $ with WASD keys" << std::endl;
				}
				if (i == 2) {
					std::cout << "But this not all! We had some challenges..." << std::endl;
				}
				if (i == 3) {
					std::cout << "First challenge - inverted moving. If in this mode you pressed W, you go down, if S - up" << std::endl;
				}
				if (i == 4) {
					std::cout << "Second challenge - darkness. You can see tile only around you, but lasers still can kill you" << std::endl;
				}
				if (i == 5) {
					std::cout << "Third challenge - conveir. My english bad, so you need to saw this with your eyes" << std::endl;
				}
				if (i == 6) {
					std::cout << "Now, you can select the level" << std::endl;
				}
				if (i != 6) {
					std::cout << "Press any key" << std::endl;
					tutorial = _getch();
				}
			}
		}
		else if(level!="1"||level!="GOD") {
			system("cls");
			std::cout << "Please, type correct value!" << std::endl;
		}
	}
	char szTexturePath[MAX_PATH] = { 0 };//создаем массив типа char длинной в 256 символов
	GetModuleFileNameA(NULL, szTexturePath, sizeof(szTexturePath));//получаем путь к исполняемому файлу
	std::string::size_type pos = std::string(szTexturePath).find_last_of("\\/");//находим исполняемый файл
	szTexturePath[pos] = 0;//удаеляем /game.exe
	strcat_s(szTexturePath, "\\1111.wav");//вставляем название песни
	PlaySoundA(szTexturePath, NULL, SND_NODEFAULT | SND_ASYNC);//проигрываем
	for (int g = 0; level_complete != 1; g++) {
		//запускаем все потоки
		if (g == 0) {
			std::thread kd_x3_y3(killing_dot_x3_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x3_y3.detach();
			std::thread kd_x2_y2(killing_dot_x2_y2_t, std::ref(map), couldown_lasers,laser_sleep);
			kd_x2_y2.detach();
			std::thread kd_x4_y2(killing_dot_x4_y2_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x4_y2.detach();
			std::thread kd_x4_y4(killing_dot_x4_y4_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x4_y4.detach();
			std::thread kd_x1_y3(killing_dot_x1_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x1_y3.detach();
			std::thread kd_x2_y3(killing_dot_x2_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x2_y3.detach();
			std::thread lb_x1(laser_beam_x1_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_x1.detach();
			std::thread lb_x5(laser_beam_x5_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_x5.detach();
			std::thread lb_y5(laser_beam_y5_t, std::ref(map),couldown_lasers, laser_sleep);
			lb_y5.detach();
			std::thread lb_y2(laser_beam_y2_t, std::ref(map),couldown_lasers, laser_sleep);
			lb_y2.detach();
			std::thread lb_y1(laser_beam_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_y1.detach();
			std::thread kd_x2_y5(killing_dot_x2_y5_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x2_y5.detach();
			std::thread lb_y3(laser_beam_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_y3.detach();
			std::thread kd_x2_y1(killing_dot_x2_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x2_y1.detach();
			std::thread lb_y4(laser_beam_y4_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_y4.detach();
			std::thread lb_x3(laser_beam_x3_t, std::ref(map),couldown_lasers, laser_sleep);
			lb_x3.detach();
			std::thread mec(mechanics, std::ref(conveir_direction),std::ref(revers), std::ref(couldown_lasers), std::ref(conveir_speed), std::ref(laser_sleep),std::ref(dk),std::ref(level_complete));
			mec.detach();
			std::thread lb_x4(laser_beam_x4_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_x4.detach();
			std::thread lb_x2(laser_beam_x2_t, std::ref(map),couldown_lasers,laser_sleep);
			lb_x2.detach();
			std::thread kd_x1_y1(killing_dot_x1_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x1_y1.detach();
			std::thread kd_x5_y5(killing_dot_x5_y5_t, std::ref(map), couldown_lasers,laser_sleep);
			kd_x5_y5.detach();
			std::thread kd_x4_y5(killing_dot_x4_y5_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x4_y5.detach();
			std::thread kd_x3_y1(killing_dot_x3_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x3_y1.detach();
			std::thread kd_x3_y5(killing_dot_x3_y5_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x3_y5.detach();
			std::thread kd_x4_y1(killing_dot_x4_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x4_y1.detach();
			std::thread kd_x1_y5(killing_dot_x1_y5_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x1_y5.detach();
			std::thread kd_x1_y4(killing_dot_x1_y4_t, std::ref(map),couldown_lasers, laser_sleep);
			kd_x1_y4.detach();
			std::thread kd_x1_y2(killing_dot_x1_y2_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x1_y2.detach();
			std::thread kd_x4_y3(killing_dot_x4_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x4_y3.detach();
			std::thread kd_x2_y4(killing_dot_x2_y4_t, std::ref(map),couldown_lasers, laser_sleep);
			kd_x2_y4.detach();
			std::thread kd_x3_y4(killing_dot_x3_y4_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x3_y4.detach();
			std::thread kd_x3_y2(killing_dot_x3_y2_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x3_y2.detach();
			std::thread r_anim(r_animate, std::ref(left_side), std::ref(right_side));
			r_anim.detach();
			std::thread kd_x5_y4(killing_dot_x5_y4_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x5_y4.detach();
			std::thread kd_x5_y2(killing_dot_x5_y2_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x5_y2.detach();
			std::thread kd_x5_y1(killing_dot_x5_y1_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x5_y1.detach();
			std::thread kd_x5_y3(killing_dot_x5_y3_t, std::ref(map),couldown_lasers,laser_sleep);
			kd_x5_y3.detach();
			std::thread cnv(conveir, std::ref(x), std::ref(y), std::ref(conveir_direction), std::ref(death), std::ref(mx), std::ref(my), std::ref(conveir_speed));
			cnv.detach();
			std::thread cnv_anim_3(conveir_3_an, std::ref(left_side), std::ref(right_side), std::ref(conveir_direction));
			cnv_anim_3.detach();
			std::thread cnv_anim_1(conveir_1_an, std::ref(left_side), std::ref(right_side), std::ref(conveir_direction));
			cnv_anim_1.detach();
			std::thread cnv_anim_4(conveir_4_an, std::ref(left_side), std::ref(right_side), std::ref(conveir_direction));
			cnv_anim_4.detach();
		}
		map[y + my][x + mx] = ' ';
		
		if (dk == 0) {
			if (_kbhit() == 1) {//проверка на нажатие клавишы 
				button = _getch();
				if (revers == 0) {
					movement(x, y, button, mx, my, revers);
					map[y + my][x + mx] = ' ';
					mx = 0; my = 0;
					//удаление игрока с его предыдущей позиции
				}
				if (revers == 1) {
					r_movement(x, y, button, mx, my, revers);
					map[y + my][x + mx] = ' ';
					mx = 0; my = 0;
				}
			}
			map[y][x] = life;
			for (int i = 0, i2 = 0; i < n; i++) {
				if (i % 31 == 0) {
					center2();
					for (int x = 0; x < 22; x++)std::cout << left_side[i2][x];
				}

				std::cout << map[i / 31][i % 31];

				if ((i + 1) % 31 == 0) {
					for (int x = 0; x < 22; x++) {
						std::cout << right_side[i2][x];
					}
					std::cout << std::endl;
					i2++;
				}
				if (i == n - 1)system("cls");
			}
		}

		if (dk == 1) {
			for (int i = 0; i < n; i++) {
				if (_kbhit() == 1) {
					button = _getch();
					if (revers == 0) {
						movement(x, y, button, mx, my, revers);
						map[y + my][x + mx] = ' ';
					}
					if (revers == 1) {
						r_movement(x, y, button, mx, my, revers);
						map[y + my][x + mx] = ' ';
					}
				}
				map[y][x] = life;
				darkness(x, y, map); g++;
				if (map[y][x + 1] == '$' && map[y][x - 1] == '$')death = 1;
				if (map[y + 1][x] == '$' && map[y - 1][x] == '$')death = 1;
				if (death == 1) {
					break;
				}
			}
			
		}
		if (map[y][x + 1] == '$' && map[y][x - 1] == '$')death = 1;
		if (map[y + 1][x] == '$' && map[y - 1][x] == '$')death = 1;
		if (death == 1 && god_mode == 0) {
			break;
		}
		
	}//запускаем все потоки
	if (death == 1 && god_mode == 0) {
		center();
		std::cout << "GAME OVER";
	}
	if (level_complete == 1 && god_mode == 0){
		center();
		std::cout << "YOU ARE GOD OF THIS GAME";
	}
	if (level_complete == 1 && god_mode == 1) {
		center();
		std::cout << "NOW TRY WITHOUT GOD MODE!";
	}
	for (int i = 0; i < 31; i++)std::cout << std::endl;
}
void movement(int& x, int& y, char button, int& mx, int& my, int r) {
	if (button == 'w' && y != 3 || button == 'W' && y != 3) {
		y -= 6;
		my = 6;
		mx = 0;
	}
	if (button == 's' && y != 27 || button == 'S' && y != 27) {
		y += 6;
		my = -6;
		mx = 0;
	}
	if (button == 'a' && x != 3 || button == 'A' && x != 3) {
		x -= 6;
		mx = 6;
		my = 0;
	}
	if (button == 'd' && x != 27 || button == 'D' && x != 27) {
		x += 6;
		mx = -6;
		my = 0;
	}
}
void r_movement(int& x, int& y, char button, int& mx, int& my, int r) {
	if (button == 'w' && y != 27 || button == 'W' && y != 27) {
		y += 6;
		my = -6;
		mx = 0;
	}
	if (button == 's' && y != 3 || button == 'S' && y != 3) {
		y -= 6;
		my = 6;
		mx = 0;
	}
	if (button == 'a' && x != 27 || button == 'A' && x != 27) {
		x += 6;
		mx = -6;
		my = 0;
	}
	if (button == 'd' && x != 3 || button == 'D' && x != 3) {
		x -= 6;
		mx = 6;
		my = 0;
	}
}
void center() {
	for (int j = 0; j < 81; j++) {
		std::cout << " ";
	}
}
void x_step(int x) {
	for (int j = 0; j < x - 3; j++) {
		std::cout << " ";
	}
}
void darkness(int x, int y, char(&map)[31][31]) {
	for (int i = 0; i < y - 3; i++) {//отступ по координате "y"
		std::cout << std::endl;
	}
	center();
	x_step(x);
	std::cout << map[y - 3][x - 3] << map[y - 3][x - 2] << map[y - 3][x - 1] << map[y - 3][x] << map[y - 3][x + 1] << map[y - 3][x + 2] << map[y - 3][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y - 2][x - 3] << map[y - 2][x - 2] << map[y - 2][x - 1] << map[y - 2][x] << map[y - 2][x + 1] << map[y - 2][x + 2] << map[y - 2][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y - 1][x - 3] << map[y - 1][x - 2] << map[y - 1][x - 1] << map[y - 1][x] << map[y - 1][x + 1] << map[y - 1][x + 2] << map[y - 1][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y][x - 3] << map[y][x - 2] << map[y][x - 1] << map[y][x] << map[y][x + 1] << map[y][x + 2] << map[y][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y + 1][x - 3] << map[y + 1][x - 2] << map[y + 1][x - 1] << map[y + 1][x] << map[y + 1][x + 1] << map[y + 1][x + 2] << map[y + 1][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y + 2][x - 3] << map[y + 2][x - 2] << map[y + 2][x - 1] << map[y + 2][x] << map[y + 2][x + 1] << map[y + 2][x + 2] << map[y + 2][x + 3] << std::endl;
	center();
	x_step(x);
	std::cout << map[y + 3][x - 3] << map[y + 3][x - 2] << map[y + 3][x - 1] << map[y + 3][x] << map[y + 3][x + 1] << map[y + 3][x + 2] << map[y + 3][x + 3] << std::endl;
	system("cls");
}
void conveir(int& x, int& y, int cd, bool& death, int& mx, int& my, int cs) {
	int i = 1;
	while (i != 23) {
		if (i == 1) {
			Sleep(36050);
			cd = 3;
		}
		if (i == 5) {
			cd = 0;
		}
		if (i == 6) {
			Sleep(13000);
			cd = 1;
			cs = 750;
		}
		if (i == 9) {
			cd = 0;
			Sleep(1850);
		}
		if (i == 10) {
			cs = 150;
			cd = 4;
		}
		if (i == 16) {
			cd = 0;
			Sleep(4550);
		}
		if (i == 17) {
			cd = 3;
		}
		if (i == 23) {
			cd = 0;
			Sleep(30000);
		}
		if (cd == 0);
		else if (cd == 1) {
			if (y == 3)death = true;
			if (y != 3) {
				y -= 6;
				my = 6;
				mx = 0;
				Sleep(cs);
			}
			if (y == 3) {
				Sleep(cs);
			}
		}
		else if (cd == 2) {
			if (y == 27)death = true;
			if (y != 27) {
				y += 6;
				my = -6;
				mx = 0;
				Sleep(cs);
			}
			if (y == 27) {
				Sleep(cs);
			}
		}
		else if (cd == 3) {
			if (x == 27)death = true;
			if (x != 27) {
				x += 6;
				my = 0;
				mx = -6;
				Sleep(cs);
			}
			if (x == 27) {
				Sleep(cs);
			}
		}
		else if (cd == 4) {
			if (x == 3)death = true;
			if (x != 3) {
				x -= 6;
				my = 0;
				mx = 6;
				Sleep(cs);
			}
			if (x == 3) {
				Sleep(cs);
			}
		}
		i++;
	}
}
void laser_beam_y1_t(char(&map)[31][31], int couldown_lasers,int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(3720);
		if (i == 2)Sleep(7030);
		if (i == 3)Sleep(850);
		if (i == 4)Sleep(2300);
		if (i == 5)Sleep(1200);
		if (i == 6)Sleep(750);
		if (i == 7)Sleep(2200);
		if (i == 8)Sleep(2100);
		if (i == 9)Sleep(3450);
		if (i == 10) {
			Sleep(4800);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 11)Sleep(2100);
		if (i == 12)Sleep(4700);
		if (i == 13)Sleep(250);
		if (i == 14)Sleep(1450);
		if (i == 15)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[i][1] = '|'; map[i][5] = '|';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][2] = '|'; map[i][4] = '|';
			map[i][1] = ' '; map[i][5] = ' ';
			if (i - (5 + j) == 0) {
				map[i][1] = '-'; map[i][5] = '-';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[i][2] = '$'; map[i][4] = '$'; map[i][3] = '$';
		}
		Sleep(ls);
		if (i == 14)Sleep(2000);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][2] = ' '; map[i][4] = ' '; map[i][3] = ' ';
			map[0][2] = '-'; map[0][4] = '-'; map[0][3] = '-';
			if (i - (5 + j) == 0) {
				map[i][2] = '-'; map[i][4] = '-'; map[i][3] = '-';
				j += 6;
			}
		}
	}
}
void laser_beam_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(2525);
		if (i == 2)Sleep(650);
		if (i == 3)Sleep(2825);
		if (i == 5)Sleep(4100);
		if (i == 6)Sleep(600);
		if (i == 7)Sleep(400);
		if (i == 8)Sleep(6950);
		if (i == 10)Sleep(4050);
		if (i == 11) {
			Sleep(2100);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 12)Sleep(500);
		if (i == 13)Sleep(2100);
		if (i == 14)Sleep(4950);
		if (i == 15)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[i][7] = '|'; map[i][11] = '|';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][8] = '|'; map[i][10] = '|';
			map[i][7] = ' '; map[i][11] = ' ';
			if (i - (5 + j) == 0) {
				map[i][7] = '-'; map[i][11] = '-';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[i][8] = '$'; map[i][9] = '$'; map[i][10] = '$';
		}
		Sleep(ls);
		if (i == 3)Sleep(1000);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][8] = ' '; map[i][9] = ' '; map[i][10] = ' ';
			if (i - (5 + j) == 0) {
				map[i][8] = '-'; map[i][9] = '-'; map[i][10] = '-';
				j += 6;
			}
		}
	}
}
void laser_beam_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(4000);
		if (i == 2)Sleep(3700);
		if (i == 3)Sleep(3500);
		if (i == 4)Sleep(200);
		if (i == 5)Sleep(1300);
		if (i == 7)Sleep(850);
		if (i == 8)Sleep(1800);
		if (i == 9)Sleep(2650);
		if (i == 10)Sleep(700);
		if (i == 11) {
			Sleep(5000);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 12)Sleep(1700);
		if (i == 14)Sleep(4850);
		if (i == 15)Sleep(4700);
		if (i == 16)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[i][13] = '|'; map[i][17] = '|';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][14] = '|'; map[i][16] = '|';
			map[i][13] = ' '; map[i][17] = ' ';
			if (i - (5 + j) == 0) {
				map[i][13] = '-'; map[i][17] = '-';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[i][14] = '$'; map[i][15] = '$'; map[i][16] = '$';
		}
		Sleep(ls);
		if (i == 4)Sleep(1250);
		if (i == 10)Sleep(350);
		if (i == 12)Sleep(1000);
		if (i == 15)Sleep(800);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][14] = ' '; map[i][15] = ' '; map[i][16] = ' ';
			if (i - (5 + j) == 0) {
				map[i][14] = '-'; map[i][15] = '-'; map[i][16] = '-';
				j += 6;
			}
		}
	}
}
void laser_beam_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(5500);
		if (i == 2)Sleep(1900);
		if (i == 3)Sleep(2000);
		if (i == 4)Sleep(3550);
		if (i == 5)Sleep(700);
		if (i == 6)Sleep(300);
		if (i == 7)Sleep(7100);
		if (i == 8)Sleep(2600);
		if (i == 9)Sleep(650);
		if (i == 10) {
			Sleep(2600);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 11)Sleep(650);
		if (i == 12)Sleep(2300);
		if (i == 13)Sleep(4600);
		if (i == 14)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[i][19] = '|'; map[i][23] = '|';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][20] = '|'; map[i][22] = '|';
			map[i][19] = ' '; map[i][23] = ' ';
			if (i - (5 + j) == 0) {
				map[i][19] = '-'; map[i][23] = '-';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[i][20] = '$'; map[i][21] = '$'; map[i][22] = '$';
		}
		Sleep(ls);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][20] = ' '; map[i][21] = ' '; map[i][22] = ' ';
			if (i - (5 + j) == 0) {
				map[i][20] = '-'; map[i][21] = '-'; map[i][22] = '-';
				j += 6;
			}
		}
	}
}
void laser_beam_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(2325);
		if (i == 3)Sleep(2775);
		if (i == 4)Sleep(1650);
		if (i == 5)Sleep(950);
		if (i == 6)Sleep(2200);
		if (i == 7)Sleep(1200);
		if (i == 8)Sleep(1000);
		if (i == 9)Sleep(1950);
		if (i == 10)Sleep(5000);
		if (i == 11)Sleep(550);
		if (i == 12) {
			Sleep(4800);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 13)Sleep(2150);
		if (i == 14)Sleep(4650);
		if (i == 15)Sleep(150);
		if (i == 16)Sleep(1550);
		if (i == 17)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[i][25] = '|'; map[i][29] = '|';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][26] = '|'; map[i][28] = '|';
			map[i][25] = ' '; map[i][29] = ' ';
			if (i - (5 + j) == 0) {
				map[i][25] = '-'; map[i][29] = '-';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[i][26] = '$'; map[i][27] = '$'; map[i][28] = '$';
		}
		Sleep(ls);
		if (i == 16)Sleep(2000);
		for (int i = 1, j = 1; i < 30; i++) {
			map[i][26] = ' '; map[i][27] = ' '; map[i][28] = ' ';
			if (i - (5 + j) == 0) {
				map[i][26] = '-'; map[i][27] = '-'; map[i][28] = '-';
				j += 6;
			}
		}
	}
}
void laser_beam_x1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int g = 1; g < 1000; g++) {
		if (g == 1)Sleep(2000);
		if (g == 2)Sleep(8750);
		if (g == 3)Sleep(6050);
		if (g == 4)Sleep(700);
		if (g == 5)Sleep(350);
		if (g == 6)Sleep(3400);
		if (g == 7)Sleep(2300);
		if (g == 8)Sleep(2600);
		if (g == 9) {
			Sleep(4250);
			couldown_lasers = 400;
			ls = 250;
		}
		if (g == 10)Sleep(1900);
		if (g == 11)Sleep(2650);
		if (g == 12)Sleep(2500);
		if (g == 13)Sleep(1950);
		if (g == 14)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[1][i] = '-'; map[5][i] = '-';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[2][i] = '-'; map[4][i] = '-';
			map[1][i] = ' '; map[5][i] = ' ';
			if (i - (5 + j) == 0) {
				map[1][i] = '|'; map[5][i] = '|';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[2][i] = '$'; map[3][i] = '$'; map[4][i] = '$';
		}
		Sleep(ls);
		if (g == 13)Sleep(1500);
		for (int i = 1, j = 1; i < 30; i++) {
			map[2][i] = ' '; map[3][i] = ' '; map[4][i] = ' ';
			if (i - (5 + j) == 0) {
				map[2][i] = '|'; map[3][i] = '|'; map[4][i] = '|';
				j += 6;
			}
		}
	}
}
void laser_beam_x2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(6700);
		if (i == 2)Sleep(8400);
		if (i == 3)Sleep(8750);
		if (i == 4)Sleep(100);
		if (i == 5)Sleep(1800);
		if (i == 6)Sleep(4150);
		if (i == 7) {
			Sleep(1400);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 8)Sleep(950);
		if (i == 9)Sleep(900);
		if (i == 10)Sleep(2750);
		if (i == 11)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[7][i] = '-'; map[11][i] = '-';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[8][i] = '-'; map[10][i] = '-';
			map[7][i] = ' '; map[11][i] = ' ';
			if (i - (5 + j) == 0) {
				map[7][i] = '|'; map[11][i] = '|';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[8][i] = '$'; map[9][i] = '$'; map[10][i] = '$';
		}
		Sleep(ls);
		if (i == 1)Sleep(1800);
		for (int i = 1, j = 1; i < 30; i++) {
			map[8][i] = ' '; map[9][i] = ' '; map[10][i] = ' ';
			if (i - (5 + j) == 0) {
				map[8][i] = '|'; map[9][i] = '|'; map[10][i] = '|';
				j += 6;
			}
		}
	}
}
void laser_beam_x3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(6500);
		if (i == 2)Sleep(5050);
		if (i == 5)Sleep(3050);
		if (i == 6)Sleep(1150);
		if (i == 7)Sleep(300);
		if (i == 8)Sleep(650);
		if (i == 9)Sleep(2900);
		if (i == 10) {
			Sleep(6500);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 11)Sleep(6500);
		if (i == 12)Sleep(750);
		if (i == 13)Sleep(800);
		if (i == 14)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[13][i] = '-'; map[17][i] = '-';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[14][i] = '-'; map[16][i] = '-';
			map[13][i] = ' '; map[17][i] = ' ';
			if (i - (5 + j) == 0) {
				map[13][i] = '|'; map[17][i] = '|';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[14][i] = '$'; map[15][i] = '$'; map[16][i] = '$';
		}
		Sleep(ls);
		if (i == 4)Sleep(1250);
		for (int i = 1, j = 1; i < 30; i++) {
			map[14][i] = ' '; map[15][i] = ' '; map[16][i] = ' ';
			if (i - (5 + j) == 0) {
				map[14][i] = '|'; map[15][i] = '|'; map[16][i] = '|';
				j += 6;
			}
		}
	}
}
void laser_beam_x4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(6700);
		if (i == 2)Sleep(8700);
		if (i == 3)Sleep(7900);
		if (i == 4)Sleep(1050);
		if (i == 5)Sleep(6700);
		if (i == 6) {
			Sleep(2650);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(550);
		if (i == 8)Sleep(900);
		if (i == 9)Sleep(4400);
		if (i == 10)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[19][i] = '-'; map[23][i] = '-';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[20][i] = '-'; map[22][i] = '-';
			map[19][i] = ' '; map[23][i] = ' ';
			if (i - (5 + j) == 0) {
				map[19][i] = '|'; map[23][i] = '|';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[20][i] = '$'; map[21][i] = '$'; map[22][i] = '$';
		}
		Sleep(ls);
		if (i == 1)Sleep(1800);
		for (int i = 1, j = 1; i < 30; i++) {
			map[20][i] = ' '; map[21][i] = ' '; map[22][i] = ' ';
			if (i - (5 + j) == 0) {
				map[20][i] = '|'; map[21][i] = '|'; map[22][i] = '|';
				j += 6;
			}
		}
	}
}
void laser_beam_x5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int g = 1; g < 1000; g++) {
		if (g == 1)Sleep(2150);
		if (g == 2)Sleep(8600);
		if (g == 3)Sleep(6050);
		if (g == 4)Sleep(700);
		if (g == 5)Sleep(600);
		if (g == 6)Sleep(600);
		if (g == 7)Sleep(5450);
		if (g == 8)Sleep(2000);
		if (g == 9) {
			Sleep(4250);
			couldown_lasers = 400;
			ls = 250;
		}
		if (g == 10)Sleep(1900);
		if (g == 11)Sleep(3900);
		if (g == 12)Sleep(1250);
		if (g == 13)Sleep(2250);
		if (g == 14)Sleep(20000000);
		for (int i = 1; i < 30; i++) {
			map[25][i] = '-'; map[29][i] = '-';
		}
		Sleep(couldown_lasers);
		for (int i = 1, j = 1; i < 30; i++) {
			map[26][i] = '-'; map[28][i] = '-';
			map[25][i] = ' '; map[29][i] = ' ';
			if (i - (5 + j) == 0) {
				map[25][i] = '|'; map[29][i] = '|';
				j += 6;
			}
		}
		Sleep(couldown_lasers);
		for (int i = 1; i < 30; i++) {
			map[26][i] = '$'; map[27][i] = '$'; map[28][i] = '$';
		}
		Sleep(ls);
		if (g == 13)Sleep(1500);
		for (int i = 1, j = 1; i < 30; i++) {
			map[26][i] = ' '; map[27][i] = ' '; map[28][i] = ' ';
			if (i - (5 + j) == 0) {
				map[26][i] = '|'; map[27][i] = '|'; map[28][i] = '|';
				j += 6;
			}
		}
	}
}
void killing_dot_x1_y1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(7100);
		if (i == 2)Sleep(1250);
		if (i == 3) {
			Sleep(5550);
			ls = 250;
		}
		if (i == 4) {
			Sleep(6000);
			ls = 500;
		}
		if (i == 5)Sleep(11750);
		
		if (i == 6) {
			Sleep(4500);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(1550);
		if (i == 8)Sleep(2200);
		if (i == 9)Sleep(20000000);
		map[1][3] = '|'; map[2][3] = '0'; map[4][3] = '0'; map[5][3] = '|'; map[3][2] = '0'; map[3][4] = '0';
		map[2][2] = '0'; map[2][4] = '0'; map[4][2] = '0'; map[4][4] = '0'; map[3][1] = '-'; map[3][5] = '-';
		Sleep(couldown_lasers);
		map[1][3] = '|'; map[2][3] = '0'; map[4][3] = '0'; map[5][3] = '|'; map[3][2] = '0'; map[3][4] = '0';
		map[2][2] = '0'; map[2][4] = '0'; map[4][2] = '0'; map[4][4] = '0'; map[3][1] = '-'; map[3][5] = '-';
		Sleep(couldown_lasers);
		map[1][3] = ' '; map[5][3] = ' '; map[3][1] = ' '; map[3][5] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 2] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 2] = ' ';
		}
	}
}
void killing_dot_x2_y1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(5250);
		if (i == 2)Sleep(150);
		if (i == 3)Sleep(6100);
		if (i == 4)Sleep(800);
		if (i == 5)Sleep(17950);
		if (i == 6) {
			Sleep(8150);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(2200);
		if (i == 8)Sleep(1550);
		if (i == 9)Sleep(7500);
		if (i == 10)Sleep(20000000);
		map[1][9] = '|'; map[2][9] = '0'; map[4][9] = '0'; map[5][9] = '|'; map[3][8] = '0'; map[3][10] = '0';
		map[2][8] = '0'; map[2][10] = '0'; map[4][8] = '0'; map[4][10] = '0'; map[3][7] = '-'; map[3][11] = '-';
		Sleep(couldown_lasers);
		map[1][9] = '|'; map[2][9] = '0'; map[4][9] = '0'; map[5][9] = '|'; map[3][8] = '0'; map[3][10] = '0';
		map[2][8] = '0'; map[2][10] = '0'; map[4][8] = '0'; map[4][10] = '0'; map[3][7] = '-'; map[3][11] = '-';
		Sleep(couldown_lasers);
		map[1][9] = ' '; map[5][9] = ' '; map[3][7] = ' '; map[3][11] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 8] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 8] = ' ';
		}
	}
}
void killing_dot_x3_y1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(7600);
		if (i == 2)Sleep(15350);
		if (i == 3)Sleep(950);
		if (i == 4) {
			Sleep(21750);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(20000000);
		map[1][15] = '|'; map[2][15] = '0'; map[4][15] = '0'; map[5][15] = '|'; map[3][14] = '0'; map[3][16] = '0';
		map[2][14] = '0'; map[2][16] = '0'; map[4][14] = '0'; map[4][16] = '0'; map[3][13] = '-'; map[3][17] = '-';
		Sleep(couldown_lasers);
		map[1][15] = '|'; map[2][15] = '0'; map[4][15] = '0'; map[5][15] = '|'; map[3][14] = '0'; map[3][16] = '0';
		map[2][14] = '0'; map[2][16] = '0'; map[4][14] = '0'; map[4][16] = '0'; map[3][13] = '-'; map[3][17] = '-';
		Sleep(couldown_lasers);
		map[1][15] = ' '; map[5][15] = ' '; map[3][13] = ' '; map[3][17] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 14] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 14] = ' ';
		}
	}
}
void killing_dot_x4_y1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(8000);
		if (i == 2)Sleep(6100);
		if (i == 3)Sleep(500);
		if (i == 4)Sleep(4350);
		if (i == 5) {
			Sleep(21600);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 6)Sleep(2450);
		if (i == 7)Sleep(20000000);
		map[1][21] = '|'; map[2][21] = '0'; map[4][21] = '0'; map[5][21] = '|'; map[3][20] = '0'; map[3][22] = '0';
		map[2][20] = '0'; map[2][22] = '0'; map[4][20] = '0'; map[4][22] = '0'; map[3][19] = '-'; map[3][23] = '-';
		Sleep(couldown_lasers);
		map[1][21] = '|'; map[2][21] = '0'; map[4][21] = '0'; map[5][21] = '|'; map[3][20] = '0'; map[3][22] = '0';
		map[2][20] = '0'; map[2][22] = '0'; map[4][20] = '0'; map[4][22] = '0'; map[3][19] = '-'; map[3][23] = '-';
		Sleep(couldown_lasers);
		map[1][21] = ' '; map[5][21] = ' '; map[3][19] = ' '; map[3][23] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 20] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 20] = ' ';
		}
	}
}
void killing_dot_x5_y1_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1) {
			Sleep(17900);
			ls = 250;
		}
		if (i == 2) {
			Sleep(7750);
			ls = 500;
		}
		if (i == 3) {
			Sleep(16500);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(1600);
		if (i == 5)Sleep(2250);
		if (i == 6)Sleep(9800);
		if (i == 7)Sleep(20000000);
		map[1][27] = '|'; map[2][27] = '0'; map[4][27] = '0'; map[5][27] = '|'; map[3][26] = '0'; map[3][28] = '0';
		map[2][26] = '0'; map[2][28] = '0'; map[4][26] = '0'; map[4][28] = '0'; map[3][25] = '-'; map[3][29] = '-';
		Sleep(couldown_lasers);
		map[1][27] = '|'; map[2][27] = '0'; map[4][27] = '0'; map[5][27] = '|'; map[3][26] = '0'; map[3][28] = '0';
		map[2][26] = '0'; map[2][28] = '0'; map[4][26] = '0'; map[4][28] = '0'; map[3][25] = '-'; map[3][29] = '-';
		Sleep(couldown_lasers);
		map[1][27] = ' '; map[5][27] = ' '; map[3][25] = ' '; map[3][29] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 26] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 2][i % 3 + 26] = ' ';
		}
	}
}
void killing_dot_x1_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(11100);
		if (i == 2)Sleep(4700);
		if (i == 3)Sleep(19100);
		if (i == 4) {
			Sleep(7900);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(2000);
		if (i == 6)Sleep(9900);
		if (i == 7)Sleep(20000000);
		map[7][3] = '|'; map[8][3] = '0'; map[10][3] = '0'; map[11][3] = '|'; map[9][2] = '0'; map[9][4] = '0';
		map[8][2] = '0'; map[8][4] = '0'; map[10][2] = '0'; map[10][4] = '0'; map[9][1] = '-'; map[9][5] = '-';
		Sleep(couldown_lasers);
		map[7][3] = '|'; map[8][3] = '0'; map[10][3] = '0'; map[11][3] = '|'; map[9][2] = '0'; map[9][4] = '0';
		map[8][2] = '0'; map[8][4] = '0'; map[10][2] = '0'; map[10][4] = '0'; map[9][1] = '-'; map[9][5] = '-';
		Sleep(couldown_lasers);
		map[7][3] = ' '; map[11][3] = ' '; map[9][1] = ' '; map[9][5] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 2] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 2] = ' ';
		}
	}
}
void killing_dot_x2_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1150);
		if (i == 2)Sleep(9400);
		if (i == 3)Sleep(3050);
		if (i == 4)Sleep(7800);
		if (i == 5)Sleep(8850);
		if (i == 6) {
			Sleep(5800);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(1750);
		if (i == 8)Sleep(1950);
		if (i == 9)Sleep(8200);
		if (i == 10)Sleep(450);
		if (i == 11)Sleep(20000000);
		map[7][9] = '|'; map[8][9] = '0'; map[10][9] = '0'; map[11][9] = '|'; map[9][8] = '0'; map[9][10] = '0';
		map[8][8] = '0'; map[8][10] = '0'; map[10][8] = '0'; map[10][10] = '0'; map[9][7] = '-'; map[9][11] = '-';
		Sleep(couldown_lasers);
		map[7][9] = '|'; map[8][9] = '0'; map[10][9] = '0'; map[11][9] = '|'; map[9][8] = '0'; map[9][10] = '0';
		map[8][8] = '0'; map[8][10] = '0'; map[10][8] = '0'; map[10][10] = '0'; map[9][7] = '-'; map[9][11] = '-';
		Sleep(couldown_lasers);
		map[7][9] = ' '; map[11][9] = ' '; map[9][7] = ' '; map[9][11] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 8] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 8] = ' ';
		}
	}
}
void killing_dot_x3_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(12550);
		if (i == 2)Sleep(10400);
		if (i == 3) {
			Sleep(25000);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(7700);
		if (i == 5)Sleep(20000000);
		map[7][15] = '|'; map[8][15] = '0'; map[10][15] = '0'; map[11][15] = '|'; map[9][14] = '0'; map[9][16] = '0';
		map[8][14] = '0'; map[8][16] = '0'; map[10][14] = '0'; map[10][16] = '0'; map[9][13] = '-'; map[9][17] = '-';
		Sleep(couldown_lasers);
		map[7][15] = '|'; map[8][15] = '0'; map[10][15] = '0'; map[11][15] = '|'; map[9][14] = '0'; map[9][16] = '0';
		map[8][14] = '0'; map[8][16] = '0'; map[10][14] = '0'; map[10][16] = '0'; map[9][13] = '-'; map[9][17] = '-';
		Sleep(couldown_lasers);
		map[7][15] = ' '; map[11][15] = ' '; map[9][13] = ' '; map[9][17] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 14] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 14] = ' ';
		}
	}
}
void killing_dot_x4_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1300);
		if (i == 2)Sleep(1950);
		if (i == 3)Sleep(5300);
		if (i == 4)Sleep(450);
		if (i == 5)Sleep(600);
		if (i == 6)Sleep(5750);
		if (i == 7)Sleep(400);
		if (i == 8) {
			Sleep(16300);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 9)Sleep(1750);
		if (i == 10)Sleep(2050);
		if (i == 11)Sleep(1400);
		if (i == 12)Sleep(4950);
		if (i == 13)Sleep(20000000);
		map[7][21] = '|'; map[8][21] = '0'; map[10][21] = '0'; map[11][21] = '|'; map[9][20] = '0'; map[9][22] = '0';
		map[8][20] = '0'; map[8][22] = '0'; map[10][20] = '0'; map[10][22] = '0'; map[9][19] = '-'; map[9][23] = '-';
		Sleep(couldown_lasers);
		map[7][21] = '|'; map[8][21] = '0'; map[10][21] = '0'; map[11][21] = '|'; map[9][20] = '0'; map[9][22] = '0';
		map[8][20] = '0'; map[8][22] = '0'; map[10][20] = '0'; map[10][22] = '0'; map[9][19] = '-'; map[9][23] = '-';
		Sleep(couldown_lasers);
		map[7][21] = ' '; map[11][21] = ' '; map[9][19] = ' '; map[9][23] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 20] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 20] = ' ';
		}
	}
}
void killing_dot_x5_y2_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if(i == 1)Sleep(17800);
		if (i == 2)Sleep(5500);
		if (i == 3) {
			Sleep(21550);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(12800);
		if (i == 5)Sleep(20000000);
		map[7][27] = '|'; map[8][27] = '0'; map[10][27] = '0'; map[11][27] = '|'; map[9][26] = '0'; map[9][28] = '0';
		map[8][26] = '0'; map[8][28] = '0'; map[10][26] = '0'; map[10][28] = '0'; map[9][25] = '-'; map[9][29] = '-';
		Sleep(couldown_lasers);
		map[7][27] = '|'; map[8][27] = '0'; map[10][27] = '0'; map[11][27] = '|'; map[9][26] = '0'; map[9][28] = '0';
		map[8][26] = '0'; map[8][28] = '0'; map[10][26] = '0'; map[10][28] = '0'; map[9][25] = '-'; map[9][29] = '-';
		Sleep(couldown_lasers);
		map[7][27] = ' '; map[11][27] = ' '; map[9][25] = ' '; map[9][29] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 26] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 8][i % 3 + 26] = ' ';
		}
	}
}
void killing_dot_x1_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1550);
		if (i == 2)Sleep(8650);
		if (i == 3)Sleep(24700);
		if (i == 4) {
			Sleep(8050);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(2050);
		if (i == 6)Sleep(20000000);
		map[13][3] = '|'; map[14][3] = '0'; map[16][3] = '0'; map[17][3] = '|'; map[15][2] = '0'; map[15][4] = '0';
		map[14][2] = '0'; map[14][4] = '0'; map[16][2] = '0'; map[16][4] = '0'; map[15][1] = '-'; map[15][5] = '-';
		Sleep(couldown_lasers);
		map[13][3] = '|'; map[14][3] = '0'; map[16][3] = '0'; map[17][3] = '|'; map[15][2] = '0'; map[15][4] = '0';
		map[14][2] = '0'; map[14][4] = '0'; map[16][2] = '0'; map[16][4] = '0'; map[15][1] = '-'; map[15][5] = '-';
		Sleep(couldown_lasers);
		map[13][3] = ' '; map[17][3] = ' '; map[15][1] = ' '; map[15][5] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 2] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 2] = ' ';
		}
	}
}
void killing_dot_x2_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1900);
		if (i == 2)Sleep(1050);
		if (i == 3)Sleep(6000);
		if (i == 4) {
			Sleep(34050);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(1700);
		if (i == 6)Sleep(8300);
		if (i == 7)Sleep(20000000);
		map[13][9] = '|'; map[14][9] = '0'; map[16][9] = '0'; map[17][9] = '|'; map[15][8] = '0'; map[15][10] = '0';
		map[14][8] = '0'; map[14][10] = '0'; map[16][8] = '0'; map[16][10] = '0'; map[15][7] = '-'; map[15][11] = '-';
		Sleep(couldown_lasers);
		map[13][9] = '|'; map[14][9] = '0'; map[16][9] = '0'; map[17][9] = '|'; map[15][8] = '0'; map[15][10] = '0';
		map[14][8] = '0'; map[14][10] = '0'; map[16][8] = '0'; map[16][10] = '0'; map[15][7] = '-'; map[15][11] = '-';
		Sleep(couldown_lasers);
		map[13][9] = ' '; map[17][9] = ' '; map[15][7] = ' '; map[15][11] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 8] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 8] = ' ';
		}
	}
}
void killing_dot_x3_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1050);
		if (i == 2)Sleep(8900);
		if (i == 3) {
			Sleep(32250);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(4500);
		if (i == 5)Sleep(1550);
		if (i == 6)Sleep(4600);
		if (i == 7)Sleep(20000000);
		map[13][15] = '|'; map[14][15] = '0'; map[16][15] = '0'; map[17][15] = '|'; map[15][14] = '0'; map[15][16] = '0';
		map[14][14] = '0'; map[14][16] = '0'; map[16][14] = '0'; map[16][16] = '0'; map[15][13] = '-'; map[15][17] = '-';
		Sleep(couldown_lasers);
		map[13][15] = '|'; map[14][15] = '0'; map[16][15] = '0'; map[17][15] = '|'; map[15][14] = '0'; map[15][16] = '0';
		map[14][14] = '0'; map[14][16] = '0'; map[16][14] = '0'; map[16][16] = '0'; map[15][13] = '-'; map[15][17] = '-';
		Sleep(couldown_lasers);
		map[13][15] = ' '; map[17][15] = ' '; map[15][13] = ' '; map[15][17] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 14] = '$';
		}
		Sleep(ls);
		if (i == 6)Sleep(1400);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 14] = ' ';
		}
	}
}
void killing_dot_x4_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(12200);
		if (i == 2)Sleep(700);
		if (i == 3)Sleep(8450);
		if (i == 4) {
			Sleep(21800);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(1450);
		if (i == 6)Sleep(7600);
		if (i == 7)Sleep(1250);
		if (i == 8)Sleep(20000000);
		map[13][21] = '|'; map[14][21] = '0'; map[16][21] = '0'; map[17][21] = '|'; map[15][20] = '0'; map[15][22] = '0';
		map[14][20] = '0'; map[14][22] = '0'; map[16][20] = '0'; map[16][22] = '0'; map[15][19] = '-'; map[15][23] = '-';
		Sleep(couldown_lasers);
		map[13][21] = '|'; map[14][21] = '0'; map[16][21] = '0'; map[17][21] = '|'; map[15][20] = '0'; map[15][22] = '0';
		map[14][20] = '0'; map[14][22] = '0'; map[16][20] = '0'; map[16][22] = '0'; map[15][19] = '-'; map[15][23] = '-';
		Sleep(couldown_lasers);
		map[13][21] = ' '; map[17][21] = ' '; map[15][19] = ' '; map[15][23] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 20] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 20] = ' ';
		}
	}
}
void killing_dot_x5_y3_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(24550);
		if (i == 2)Sleep(1200);
		if (i == 3) {
			Sleep(19400);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(1550);
		if (i == 5)Sleep(1675);
		if (i == 6)Sleep(20000000);
		map[13][27] = '|'; map[14][27] = '0'; map[16][27] = '0'; map[17][27] = '|'; map[15][26] = '0'; map[15][28] = '0';
		map[14][26] = '0'; map[14][28] = '0'; map[16][26] = '0'; map[16][28] = '0'; map[15][25] = '-'; map[15][29] = '-';
		Sleep(couldown_lasers);
		map[13][27] = '|'; map[14][27] = '0'; map[16][27] = '0'; map[17][27] = '|'; map[15][26] = '0'; map[15][28] = '0';
		map[14][26] = '0'; map[14][28] = '0'; map[16][26] = '0'; map[16][28] = '0'; map[15][25] = '-'; map[15][29] = '-';
		Sleep(couldown_lasers);
		map[13][27] = ' '; map[17][27] = ' '; map[15][25] = ' '; map[15][29] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 26] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 14][i % 3 + 26] = ' ';
		}
	}
}
void killing_dot_x1_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(10900);
		if (i == 2)Sleep(4900);
		if (i == 3)Sleep(18600);
		if (i == 4) {
			Sleep(8450);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(1950);
		if (i == 6)Sleep(9800);
		if (i == 7)Sleep(20000000);
		map[19][3] = '|'; map[20][3] = '0'; map[22][3] = '0'; map[23][3] = '|'; map[21][2] = '0'; map[21][4] = '0';
		map[20][2] = '0'; map[20][4] = '0'; map[22][2] = '0'; map[22][4] = '0'; map[21][1] = '-'; map[21][5] = '-';
		Sleep(couldown_lasers);
		map[19][3] = '|'; map[20][3] = '0'; map[22][3] = '0'; map[23][3] = '|'; map[21][2] = '0'; map[21][4] = '0';
		map[20][2] = '0'; map[20][4] = '0'; map[22][2] = '0'; map[22][4] = '0'; map[21][1] = '-'; map[21][5] = '-';
		Sleep(couldown_lasers);
		map[19][3] = ' '; map[23][3] = ' '; map[21][1] = ' '; map[21][5] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 2] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 2] = ' ';
		}
	}
}
void killing_dot_x2_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(12350);
		if (i == 2)Sleep(3250);
		if (i == 3)Sleep(5750);
		if (i == 4)Sleep(400);
		if (i == 5)Sleep(9150);
		if (i == 6) {
			Sleep(5150);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(1700);
		if (i == 8)Sleep(2100);
		if (i == 9)Sleep(1325);
		if (i == 10)Sleep(6125);
		if (i == 11)Sleep(20000000);
		map[19][9] = '|'; map[20][9] = '0'; map[22][9] = '0'; map[23][9] = '|'; map[21][8] = '0'; map[21][10] = '0';
		map[20][8] = '0'; map[20][10] = '0'; map[22][8] = '0'; map[22][10] = '0'; map[21][7] = '-'; map[21][11] = '-';
		Sleep(couldown_lasers);
		map[19][9] = '|'; map[20][9] = '0'; map[22][9] = '0'; map[23][9] = '|'; map[21][8] = '0'; map[21][10] = '0';
		map[20][8] = '0'; map[20][10] = '0'; map[22][8] = '0'; map[22][10] = '0'; map[21][7] = '-'; map[21][11] = '-';
		Sleep(couldown_lasers);
		map[19][9] = ' '; map[23][9] = ' '; map[21][7] = ' '; map[21][11] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 8] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 8] = ' ';
		}
	}
}
void killing_dot_x3_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(12350);
		if (i == 2)Sleep(950);
		if (i == 3)Sleep(10100);
		if (i == 4) {
			Sleep(22250);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(8800);
		if (i == 6)Sleep(20000000);
		map[19][15] = '|'; map[20][15] = '0'; map[22][15] = '0'; map[23][15] = '|'; map[21][14] = '0'; map[21][16] = '0';
		map[20][14] = '0'; map[20][16] = '0'; map[22][14] = '0'; map[22][16] = '0'; map[21][13] = '-'; map[21][17] = '-';
		Sleep(couldown_lasers);
		map[19][15] = '|'; map[20][15] = '0'; map[22][15] = '0'; map[23][15] = '|'; map[21][14] = '0'; map[21][16] = '0';
		map[20][14] = '0'; map[20][16] = '0'; map[22][14] = '0'; map[22][16] = '0'; map[21][13] = '-'; map[21][17] = '-';
		Sleep(couldown_lasers);
		map[19][15] = ' '; map[23][15] = ' '; map[21][13] = ' '; map[21][17] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 14] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 14] = ' ';
		}
	}
}
void killing_dot_x4_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(1450);
		if (i == 2)Sleep(1250);
		if (i == 3)Sleep(5650);
		if (i == 4)Sleep(750);
		if (i == 5)Sleep(500);
		if (i == 6)Sleep(4950);
		if (i == 7) {
			Sleep(19500);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 8)Sleep(1750);
		if (i == 9)Sleep(4575);
		if (i == 10)Sleep(4775);
		if (i == 11)Sleep(20000000);
		map[19][21] = '|'; map[20][21] = '0'; map[22][21] = '0'; map[23][21] = '|'; map[21][20] = '0'; map[21][22] = '0';
		map[20][20] = '0'; map[20][22] = '0'; map[22][20] = '0'; map[22][22] = '0'; map[21][19] = '-'; map[21][23] = '-';
		Sleep(couldown_lasers);
		map[19][21] = '|'; map[20][21] = '0'; map[22][21] = '0'; map[23][21] = '|'; map[21][20] = '0'; map[21][22] = '0';
		map[20][20] = '0'; map[20][22] = '0'; map[22][20] = '0'; map[22][22] = '0'; map[21][19] = '-'; map[21][23] = '-';
		Sleep(couldown_lasers);
		map[19][21] = ' '; map[23][21] = ' '; map[21][19] = ' '; map[21][23] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 20] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 20] = ' ';
		}
	}
}
void killing_dot_x5_y4_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 100; i++) {
		if (i == 1)Sleep(15300);
		if (i == 2)Sleep(600);
		if (i == 3)Sleep(4650);
		if (i == 4) {
			Sleep(22300);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(12800);
		if (i == 6)Sleep(20000000);
		map[19][27] = '|'; map[20][27] = '0'; map[22][27] = '0'; map[23][27] = '|'; map[21][26] = '0'; map[21][28] = '0';
		map[20][26] = '0'; map[20][28] = '0'; map[22][26] = '0'; map[22][28] = '0'; map[21][25] = '-'; map[21][29] = '-';
		Sleep(couldown_lasers);
		map[19][27] = '|'; map[20][27] = '0'; map[22][27] = '0'; map[23][27] = '|'; map[21][26] = '0'; map[21][28] = '0';
		map[20][26] = '0'; map[20][28] = '0'; map[22][26] = '0'; map[22][28] = '0'; map[21][25] = '-'; map[21][29] = '-';
		Sleep(couldown_lasers);
		map[19][27] = ' '; map[23][27] = ' '; map[21][25] = ' '; map[21][29] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 26] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 20][i % 3 + 26] = ' ';
		}
	}
}
void killing_dot_x1_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(10700);
		if (i == 2)Sleep(2000);
		if (i == 3) {
			Sleep(1200);
			ls = 250;
		}
		if (i == 4) {
			Sleep(8250);
			ls = 500;
		}
		if (i == 5)Sleep(8800);
		if (i == 6) {
			Sleep(5200);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 7)Sleep(1450);
		if (i == 8)Sleep(2500);
		if (i == 9)Sleep(1550);
		if (i == 10)Sleep(20000000);
		map[25][3] = '|'; map[26][3] = '0'; map[28][3] = '0'; map[29][3] = '|'; map[27][2] = '0'; map[27][4] = '0';
		map[26][2] = '0'; map[26][4] = '0'; map[28][2] = '0'; map[28][4] = '0'; map[27][1] = '-'; map[27][5] = '-';
		Sleep(couldown_lasers);
		map[25][3] = '|'; map[26][3] = '0'; map[28][3] = '0'; map[29][3] = '|'; map[27][2] = '0'; map[27][4] = '0';
		map[26][2] = '0'; map[26][4] = '0'; map[28][2] = '0'; map[28][4] = '0'; map[27][1] = '-'; map[27][5] = '-';
		Sleep(couldown_lasers);
		map[25][3] = ' '; map[29][3] = ' '; map[27][1] = ' '; map[27][5] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 2] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 2] = ' ';
		}
	}
}
void killing_dot_x2_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(3870);
		if (i == 2)Sleep(2130);
		if (i == 3)Sleep(5800);
		if (i == 4)Sleep(600);
		if (i == 5)Sleep(4550);
		if (i == 6)Sleep(11450);
		if (i == 7) {
			Sleep(8100);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 8)Sleep(13350);
		if (i == 9)Sleep(20000000);
		map[25][9] = '|'; map[26][9] = '0'; map[28][9] = '0'; map[29][9] = '|'; map[27][8] = '0'; map[27][10] = '0';
		map[26][8] = '0'; map[26][10] = '0'; map[28][8] = '0'; map[28][10] = '0'; map[27][7] = '-'; map[27][11] = '-';
		Sleep(couldown_lasers);
		map[25][9] = '|'; map[26][9] = '0'; map[28][9] = '0'; map[29][9] = '|'; map[27][8] = '0'; map[27][10] = '0';
		map[26][8] = '0'; map[26][10] = '0'; map[28][8] = '0'; map[28][10] = '0'; map[27][7] = '-'; map[27][11] = '-';
		Sleep(couldown_lasers);
		map[25][9] = ' '; map[29][9] = ' '; map[27][7] = ' '; map[27][11] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 8] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 8] = ' ';
		}
	}
}
void killing_dot_x3_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(7800);
		if (i == 2)Sleep(5300);
		if (i == 3) {
			Sleep(34950);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 4)Sleep(20000000);
		map[25][15] = '|'; map[26][15] = '0'; map[28][15] = '0'; map[29][15] = '|'; map[27][14] = '0'; map[27][16] = '0';
		map[26][14] = '0'; map[26][16] = '0'; map[28][14] = '0'; map[28][16] = '0'; map[27][13] = '-'; map[27][17] = '-';
		Sleep(couldown_lasers);
		map[25][15] = '|'; map[26][15] = '0'; map[28][15] = '0'; map[29][15] = '|'; map[27][14] = '0'; map[27][16] = '0';
		map[26][14] = '0'; map[26][16] = '0'; map[28][14] = '0'; map[28][16] = '0'; map[27][13] = '-'; map[27][17] = '-';
		Sleep(couldown_lasers);
		map[25][15] = ' '; map[29][15] = ' '; map[27][13] = ' '; map[27][17] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 14] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 14] = ' ';
		}
	}
}
void killing_dot_x4_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(7400);
		if (i == 2)Sleep(6500);
		if (i == 3)Sleep(500);
		if (i == 4) {
			Sleep(28150);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(2450);
		if (i == 6)Sleep(1325);
		if (i == 7)Sleep(7425);
		if (i == 8)Sleep(20000000);
		map[25][21] = '|'; map[26][21] = '0'; map[28][21] = '0'; map[29][21] = '|'; map[27][20] = '0'; map[27][22] = '0';
		map[26][20] = '0'; map[26][22] = '0'; map[28][20] = '0'; map[28][22] = '0'; map[27][19] = '-'; map[27][23] = '-';
		Sleep(couldown_lasers);
		map[25][21] = '|'; map[26][21] = '0'; map[28][21] = '0'; map[29][21] = '|'; map[27][20] = '0'; map[27][22] = '0';
		map[26][20] = '0'; map[26][22] = '0'; map[28][20] = '0'; map[28][22] = '0'; map[27][19] = '-'; map[27][23] = '-';
		Sleep(couldown_lasers);
		map[25][21] = ' '; map[29][21] = ' '; map[27][19] = ' '; map[27][23] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 20] = '$';
		}

		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 20] = ' ';
		}
	}
}
void killing_dot_x5_y5_t(char(&map)[31][31], int couldown_lasers, int ls) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(7100);
		if (i == 2) {
			Sleep(8800);
			ls = 250;
		}
		if (i == 3) {
			Sleep(8250);
			ls = 500;
		}
		if (i == 4) {
			Sleep(16000);
			couldown_lasers = 400;
			ls = 250;
		}
		if (i == 5)Sleep(1600);
		if (i == 6)Sleep(4950);
		if (i == 7)Sleep(20000000);
		map[25][27] = '|'; map[26][27] = '0'; map[28][27] = '0'; map[29][27] = '|'; map[27][26] = '0'; map[27][28] = '0';
		map[26][26] = '0'; map[26][28] = '0'; map[28][26] = '0'; map[28][28] = '0'; map[27][25] = '-'; map[27][29] = '-';
		Sleep(couldown_lasers);
		map[25][27] = '|'; map[26][27] = '0'; map[28][27] = '0'; map[29][27] = '|'; map[27][26] = '0'; map[27][28] = '0';
		map[26][26] = '0'; map[26][28] = '0'; map[28][26] = '0'; map[28][28] = '0'; map[27][25] = '-'; map[27][29] = '-';
		Sleep(couldown_lasers);
		map[25][27] = ' '; map[29][27] = ' '; map[27][25] = ' '; map[27][29] = ' ';
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 26] = '$';
		}
		Sleep(ls);
		for (int i = 0; i < 9; i++) {
			map[i / 3 + 26][i % 3 + 26] = ' ';
		}
	}
}
void clear(char(&side)[31][22]) {
	for (int x = 0, y = 0; y < 31; x++) {
		side[y][x] = ' ';
		if (x == 21) {
			y++;
			x = -1;
		}
	}
}
void arrow_up(char(&side)[31][22], int y_arrow) {
	side[y_arrow][9] = '/'; side[y_arrow + 1][8] = '/'; side[y_arrow + 2][7] = '/'; side[y_arrow + 3][6] = '/';	side[y_arrow + 4][5] = '/'; side[y_arrow + 5][4] = '/'; side[y_arrow + 6][3] = '/'; side[y_arrow + 7][2] = '/'; side[y_arrow + 8][1] = '/'; side[y_arrow + 9][0] = '/';
	side[y_arrow][10] = 92; side[y_arrow + 1][11] = 92; side[y_arrow + 2][12] = 92; side[y_arrow + 3][13] = 92; side[y_arrow + 4][14] = 92; side[y_arrow + 5][15] = 92; side[y_arrow + 6][16] = 92; side[y_arrow + 7][17] = 92; side[y_arrow + 8][18] = 92; side[y_arrow + 9][19] = 92;
	for (int i = 1; i < 19; i++)side[y_arrow + 9][i] = '0';
	for (int i = y_arrow + 10; i < y_arrow + 19; i++) {
		side[i][5] = '|'; side[i][14] = '|';
	}
	for (int i = 6; i < 14; i++)side[y_arrow + 18][i] = '0';
}
void arrow_down(char(&side)[31][22], int y_arrow) {
	for (int i = 8; i < 16; i++)side[y_arrow - 18][i] = '0';
	for (int i = y_arrow - 18; i < y_arrow - 9; i++) {
		side[i][7] = '|'; side[i][16] = '|';
	}
	side[y_arrow][11] = 92; side[y_arrow - 1][10] = 92; side[y_arrow - 2][9] = 92; side[y_arrow - 3][8] = 92; side[y_arrow - 4][7] = 92; side[y_arrow - 5][6] = 92; side[y_arrow - 6][5] = 92; side[y_arrow - 7][4] = 92; side[y_arrow - 8][3] = 92; side[y_arrow - 9][2] = 92;
	side[y_arrow][12] = '/'; side[y_arrow - 1][13] = '/'; side[y_arrow - 2][14] = '/'; side[y_arrow - 3][15] = '/'; side[y_arrow - 4][16] = '/'; side[y_arrow - 5][17] = '/'; side[y_arrow - 6][18] = '/'; side[y_arrow - 7][19] = '/'; side[y_arrow - 8][20] = '/'; side[y_arrow - 9][21] = '/';
	for (int i = 3; i < 21; i++)side[y_arrow - 9][i] = '0';
}
void r_animate(char(&ls)[31][22], char(&rs)[31][22]) {
	for (int i = 1; i < 1000; i++) {
		if (i == 1)Sleep(15500);
		if (i == 2)Sleep(2000);
		if (i == 3)Sleep(29550);
		if (i == 4)Sleep(3100);
		if (i == 5)Sleep(2000000000);
		int y1 = 12, y2 = 18;
		arrow_up(ls, y1);
		arrow_down(rs, y2);
		Sleep(200);
		clear(ls);
		clear(rs);
		y1 -= 6; y2 += 6;
		arrow_up(ls, y1);
		arrow_down(rs, y2);
		Sleep(200);
		clear(ls);
		clear(rs);
		y1 -= 6; y2 += 6;
		arrow_up(ls, y1);
		arrow_down(rs, y2);
		Sleep(200);
		clear(ls);
		clear(rs);
	}
}
void conveir_1_an(char(&ls)[31][22], char(&rs)[31][22], int& cd) {
	int y1 = 12, y2 = 0, i = 0;
	while (1 != 0) {
		if (cd == 1) {
			arrow_up(ls, y1);
			arrow_up(rs, y2);
			i++;
			if (i % 2 == 0) {
				y1 = 12;
				y2 = 0;
			}
			if (i % 2 == 1) {
				y2 = 12;
				y1 = 0;
			}
			Sleep(750);
			clear(ls);
			clear(rs);
		}
	}
}
void conveir_2_an(char(&ls)[31][22], char(&rs)[31][22], int& cd) {
	int y1 = 30, y2 = 18, i = 0;
	while (1 != 0) {
		if (cd == 2) {
			arrow_down(ls, y1);
			arrow_down(rs, y2);
			i++;
			if (i % 2 == 0) {
				y1 = 30;
				y2 = 18;
			}
			if (i % 2 == 1) {
				y2 = 30;
				y1 = 18;
			}
			Sleep(750);
			clear(ls);
			clear(rs);
		}
	}
}
void conveir_3_an(char(&ls)[31][22], char(&rs)[31][22], int& cd) {
	while (1 != 0) {
		if (cd == 3) {
			for (int i = 0; i < 31; i++) {
				ls[i][0] = '>'; ls[i][6] = '>'; ls[i][12] = '>'; ls[i][18] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][0] = '>'; rs[i][6] = '>'; rs[i][12] = '>'; rs[i][18] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][1] = '>'; ls[i][7] = '>'; ls[i][13] = '>'; ls[i][19] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][1] = '>'; rs[i][7] = '>'; rs[i][13] = '>'; rs[i][19] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][2] = '>'; ls[i][8] = '>'; ls[i][14] = '>'; ls[i][20] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][2] = '>'; rs[i][8] = '>'; rs[i][14] = '>'; rs[i][20] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][3] = '>'; ls[i][9] = '>'; ls[i][15] = '>'; ls[i][21] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][3] = '>'; rs[i][9] = '>'; rs[i][15] = '>'; rs[i][21] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][4] = '>'; ls[i][10] = '>'; ls[i][16] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][4] = '>'; rs[i][10] = '>'; rs[i][16] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][5] = '>'; ls[i][11] = '>'; ls[i][17] = '>';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][5] = '>'; rs[i][11] = '>'; rs[i][17] = '>';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
		}
	}
}
void conveir_4_an(char(&ls)[31][22], char(&rs)[31][22], int& cd) {
	while (1 != 0) {
		if (cd == 4) {
			for (int i = 0; i < 31; i++) {
				ls[i][5] = '<'; ls[i][11] = '<'; ls[i][17] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][5] = '<'; rs[i][11] = '<'; rs[i][17] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][4] = '<'; ls[i][10] = '<'; ls[i][16] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][4] = '<'; rs[i][10] = '<'; rs[i][16] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][3] = '<'; ls[i][9] = '<'; ls[i][15] = '<'; ls[i][21] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][3] = '<'; rs[i][9] = '<'; rs[i][15] = '<'; rs[i][21] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][2] = '<'; ls[i][8] = '<'; ls[i][14] = '<'; ls[i][20] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][2] = '<'; rs[i][8] = '<'; rs[i][14] = '<'; rs[i][20] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][1] = '<'; ls[i][7] = '<'; ls[i][13] = '<'; ls[i][19] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][1] = '<'; rs[i][7] = '<'; rs[i][13] = '<'; rs[i][19] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);
			for (int i = 0; i < 31; i++) {
				ls[i][0] = '<'; ls[i][6] = '<'; ls[i][12] = '<'; ls[i][18] = '<';
			}
			for (int i = 0; i < 31; i++) {
				rs[i][0] = '<'; rs[i][6] = '<'; rs[i][12] = '<'; rs[i][18] = '<';
			}
			Sleep(100);
			clear(rs);
			clear(ls);



		}
	}
}
void center2() {
	for (int j = 0; j < 59; j++) {
		std::cout << " ";
	}
}
void mechanics(int& cd, int& r, int& cl, int cs, int& ls, int& dk, int& lc) {
	Sleep(15500);
	r = 1;
	Sleep(2600);
	r = 0;
	Sleep(5900);
	dk = 1;
	Sleep(10950);
	dk = 0;
	cd = 3;
	Sleep(5450);
	cd = 0;
	Sleep(7850);
	r = 1;
	Sleep(3700);
	r = 0;
	Sleep(1450);
	cd = 1;
	Sleep(2650);
	cd = 0;
	Sleep(2750);
	cd = 4;
	Sleep(900);
	cd = 0;
	Sleep(4750);
	cd = 3;
	Sleep(900);
	cd = 0;
	Sleep(2150);
	lc = 1;
}
/*

         /\
        /  \
       /    \
      /      \
     /        \
    /          \
   /            \
  /              \
 /                \                                         > > > > > > >
/000000000000000000\                                       > > > > > > >
     |        |                                           
     |        |
     |        |
     |        |
     |        |
     |        |
     |        |
     |00000000|



	 |00000000|
	 |        |
	 |        |
	 |        |
	 |        |
	 |        |
	 |        |
	 |        |
\000000000000000000/
 \\\\\\\\\/////////
  \\\\\\\\////////
   \\\\\\\///////
    \\\\\\//////
	 \\\\\/////
	  \\\\////
	   \\\///
	    \\//
		 \/






                    -----------
          |        |    |||    |
         000       |           |55+6=61!!!!
        -0 0-  |           |
         000       |           |
          |        |           |
                    -----------
*/ 
