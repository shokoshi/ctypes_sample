#coding: utf-8

from ctypes import *
from pylab import *

LIB_NAME = "libctypessample.so"

class FPoint_3D(Structure):
    _fields_ = [
            ("x", c_float),
            ("y", c_float),
            ("z", c_float)]

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

class IPoint_2D(Structure):
    _fields_ = [
            ("x", c_int),
            ("y", c_int)]

    def __init__(self, x, y):
        self.x = x
        self.y = y


# nativeライブラリをロードする
libc = cdll.LoadLibrary(LIB_NAME)


# 引数も戻り値も持たない
print "\n***libc.print_with_no_arg***"
libc.print_with_no_arg()


# int型を引数にとり、表示する
print "\n***libc.print_with_int_arg***"
libc.print_with_int_arg(c_int(100))


# float型を引数にとり、表示する
print "\n***print_with_float_arg***"
libc.print_with_float_arg(c_float(12.34))


# 引数のint型の数値に1を足して返す
print "\n***libc.add_one***"
added = libc.add_one(c_int(100))
print "orig:%d, added:%d" % (100, added)

# 引数のint型の数値に1を足して返す(参照渡し)
print "\n***libc.add_one_to_ptr***"
num_c = c_int(100)
libc.add_one_to_ptr(byref(num_c))
print "orig:%d, added:%d" % (100, num_c.value)

# 引数のint型の配列の要素に1を足す
print "\n***libc.add_one_in_array***"
IntArray10 = c_int * 10
i_arr = [i for i in xrange(10)]
i_arr_c = IntArray10(*i_arr)
print "before:", [i_arr_c[i] for i in xrange(10)]
libc.add_one_in_array(i_arr_c, 10)
print "after:", [i_arr_c[i] for i in xrange(10)]


# FPoint_3D型を引数にとり、表示する
print "\n***libc.print_fpoint3d***"
point_3d = FPoint_3D(1.1, 2.2, 3.3)
libc.print_fpoint3d(point_3d)


# FPoint_3D型の各メンバに1を足す
print "\n***libc.add_one_in_fpoint3d***"
print "before: x:%.3f, y:%.3f, z:%.3f" % (point_3d.x, point_3d.y, point_3d.z)
libc.add_one_in_fpoint3d(byref(point_3d))
print "after: x:%.3f, y:%.3f, z:%.3f" % (point_3d.x, point_3d.y, point_3d.z)


# native内部のIPoint_2Dの配列にランダムな値を設定する
print "\n***libc.set_random_to_array***"
libc.set_random_to_array()


# native内部のIPoint_2Dの配列をpython側にコピーし、描画する
print "\n***libc.cpy_array***"
IPoint_2DArray100 = IPoint_2D*100
point_2d_arr = IPoint_2DArray100(*(IPoint_2D(0,0) for i in xrange(100)))
libc.cpy_array(point_2d_arr)
print "draw graph"
x_list = [point_2d_arr[i].x for i in xrange(100)]
y_list = [point_2d_arr[i].y for i in xrange(100)]
xlim(-5, 15)
ylim(-5, 15)
plot(x_list, y_list, "o")
show()
