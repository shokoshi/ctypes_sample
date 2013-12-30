#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define POINT_NUM 100

typedef struct {
    float x;
    float y;
    float z;
} FPOINT_3D;

typedef struct {
    int x;
    int y;
} IPOINT_2D;

static IPOINT_2D points[POINT_NUM];

/*
 * 呼ばれたことをコンソールに出力する
 */
void
print_with_no_arg()
{
    fprintf(stderr, "[native] print_with_no_arg called\n");
}

/*
 * 引数にとった値をコンソールに出力する
 * @param arg int型の数値
 */
void
print_with_int_arg(int arg)
{
    fprintf(stderr, "[native] print_with_int_arg called, arg:%d\n", arg);
}

/*
 * 引数にとった値をコンソールに出力する
 * @param arg float型の数値
 */
void
print_with_float_arg(float arg)
{
    fprintf(stderr, "[native] print_with_float_arg called, arg:%f\n", arg);
}

/*
 * 引数にとった値に1を足して返す
 * @param num int型の数値
 * @return numに1を足した値
 */
int
add_one(int num)
{
    fprintf(stderr, "[native] add_one called\n");
    return num + 1;
}

void
add_one_to_ptr(int *num_ptr)
{
    fprintf(stderr, "[native] add_one_to_ptr called\n");
    *num_ptr += 1;
}

/*
 * 引数の配列の各要素に1を足す
 * @param arr 各要素に1を足されるint型の配列
 * @param len 配列arrの長さ
 */
void
add_one_in_array(int *arr, int len)
{
    fprintf(stderr, "[native] add_one_to_array called\n");
    int i;
    for (i = 0; i < len; i++){
        arr[i] += 1;
    }
}

/*
 * 引数にとったFPOINT_3D構造体の各メンバをコンソールに出力する
 * @param point FPOINT_3D構造体
 */
void
print_fpoint3d(FPOINT_3D point)
{
    fprintf(stderr, "[native] print_fpoint3d x:%.3f, y:%.3f, z:%.3f\n", point.x, point.y, point.z);
}

/*
 * 引数にとったFPOINT_3D構造体の各メンバに1を足す
 * @param point_ptr FPOINT_3D構造体のポインタ
 */
void
add_one_in_fpoint3d(FPOINT_3D *point_ptr)
{
    fprintf(stderr, "[native] add_one_in_fpoint3d\n");
    point_ptr->x += 1.0;
    point_ptr->y += 1.0;
    point_ptr->z += 1.0;
}

/*
 * IPOINT_2D構造体の配列pointsの各要素の各メンバに0から9の値を設定する
 */
void
set_random_to_array()
{
    int i;

    fprintf(stderr, "[native] set_random_to_array called\n");
    
    srand(time(NULL));

    for (i = 0; i< POINT_NUM; i++){
        points[i].x = rand() % 10;
        points[i].y = rand() % 10;
    }
}

/*
 * IPOINT_2D構造体の配列pointsを引数のポインタにコピーする
 * @param IPOINT_2D構造体のポインタ
 */
void
cpy_array(IPOINT_2D *point_ptr)
{

    fprintf(stderr, "[native] cpy_array called\n");

    memcpy(point_ptr, points, sizeof(IPOINT_2D)*POINT_NUM);
}
