
#include "miniRT.h"
#define COLOR 255.0f /* colorの範囲 */

/**
 * @brief colorを色を追加する
 *
 * @param color
 * @param adding_num
 */
void	color_add(t_color color, float adding_num)
{
	color.red += adding_num;
	color.green += adding_num;
	color.blue += adding_num;
}

/**
 * @brief colorを実数で表された色に変換する
 *
 * @param color
 * @return float
 */
float	color_to_fcolor(float color)
{
	return (color / COLOR);
}

/**
 * @brief 実数で表された色をcolor(0~255)に変換する
 *
 * @param fcolor
 * @return float
 */
float	color_to_color(float fcolor)
{
	float	color;

	color = fcolor * COLOR;
	return (constrain(color, 0.0f, COLOR));
}
