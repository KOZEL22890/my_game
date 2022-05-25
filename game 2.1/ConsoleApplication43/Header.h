#pragma once
//функция, отвечающая за передвижение игрока
void movement(int& x, int& y, char button, int& mx, int& my, int r);
//инвертированое передвижение
void r_movement(int& x, int& y, char button, int& mx, int& my, int r);
//функция, которая создает отступ в 81 пробел
void center();
//отступ по координате "x" в режиме темноты
void x_step(int x);
//сам режим темнота, когда ты видишь только одну клетку вокруг себя
void darkness(int x, int y, char(&map)[31][31]);
//конвейр, передвигающий игрока в выбранном направлении на одну клетку каждые "cs" милисекунд
void conveir(int& x, int& y, int cd, bool& death, int& mx, int& my, int cs);
//анимации убивающих объектов. Ничего интересного здесь нет
void laser_beam_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_x1_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_x2_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_x3_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_x4_t(char(&map)[31][31], int couldown_lasers, int ls);
void laser_beam_x5_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x1_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x2_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x3_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x4_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x5_y1_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x1_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x2_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x3_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x4_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x5_y2_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x1_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x2_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x3_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x4_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x5_y3_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x1_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x2_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x3_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x4_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x5_y4_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x1_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x2_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x3_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x4_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
void killing_dot_x5_y5_t(char(&map)[31][31], int couldown_lasers, int ls);
//функция, которая очищает поле
void clear(char(&side)[31][22]);
//рисует стрелку вверх на поле
void arrow_up(char(&side)[31][22], int y_arrow);
//рисует стрелку вниз на поле
void arrow_down(char(&side)[31][22], int y_arrow);
//анимация, когда включается/выключается реверсивное управление
void r_animate(char(&ls)[31][22], char(&rs)[31][22]);
//анимации к конвейерам 
void conveir_1_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_2_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_3_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_4_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
//отступ на 59 пробелов
void center2();
//функция, отвечающая за механники, анимации
void mechanics(int& cd, int& r, int& cl, int cs, int& ls, int& dk, int& lc);
