#pragma once
//�������, ���������� �� ������������ ������
void movement(int& x, int& y, char button, int& mx, int& my, int r);
//�������������� ������������
void r_movement(int& x, int& y, char button, int& mx, int& my, int r);
//�������, ������� ������� ������ � 81 ������
void center();
//������ �� ���������� "x" � ������ �������
void x_step(int x);
//��� ����� �������, ����� �� ������ ������ ���� ������ ������ ����
void darkness(int x, int y, char(&map)[31][31]);
//�������, ������������� ������ � ��������� ����������� �� ���� ������ ������ "cs" ����������
void conveir(int& x, int& y, int cd, bool& death, int& mx, int& my, int cs);
//�������� ��������� ��������. ������ ����������� ����� ���
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
//�������, ������� ������� ����
void clear(char(&side)[31][22]);
//������ ������� ����� �� ����
void arrow_up(char(&side)[31][22], int y_arrow);
//������ ������� ���� �� ����
void arrow_down(char(&side)[31][22], int y_arrow);
//��������, ����� ����������/����������� ����������� ����������
void r_animate(char(&ls)[31][22], char(&rs)[31][22]);
//�������� � ���������� 
void conveir_1_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_2_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_3_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
void conveir_4_an(char(&ls)[31][22], char(&rs)[31][22], int& cd);
//������ �� 59 ��������
void center2();
//�������, ���������� �� ���������, ��������
void mechanics(int& cd, int& r, int& cl, int cs, int& ls, int& dk, int& lc);
